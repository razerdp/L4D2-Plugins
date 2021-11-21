/*****************************************************************************/

/*Author	= MicroLeo  */

/*****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */
 
//SQLite connect 
Handle:SQLite_Connect(const String:driver[])
{
	new Handle:data = INVALID_HANDLE;
	new Handle:SQLite_db = INVALID_HANDLE;
	if(SQLite_db==INVALID_HANDLE)
	{
		new String:error[255];
		if(!SQLite_DebugMod)
		{
			SQLite_DebugMod = DebugLogPath(SQLite_logpath,sizeof(SQLite_logpath));
		}
		
		if(SQL_CheckConfig(driver))
		{
			SQLite_db = SQL_Connect(driver,true,error,sizeof(error));
			if(SQLite_db!=INVALID_HANDLE)
			{
				SQL_FastQuery(SQLite_db , "SET NAMES 'utf8'");
				if(SQLite_DebugMod) LogToFileEx(SQLite_logpath,"[success] '%s' has connected('%s'數據庫連接成功)",driver,driver);
				
				data = CreateDataPack();
				WritePackCell(data,SQLite_db);
				WritePackString(data,driver);
			}
			else
			{
				if(SQLite_DebugMod) LogToFileEx(SQLite_logpath,"[error] Connect to '%s' failed('%s'數據庫連接失敗)",driver,driver);
			}
		}
	}
	
	return data;
}

//Create Table
SQLite_CreateTable(Handle:DataBase, const String:Table[], const String:Field[], FieldMaxlen, bool:BigQuery=false)
{
	if(DataBase != INVALID_HANDLE)
	{
		ResetPack(DataBase,false);
		new String:command[512],String:driver[64];
		FormatEx(command,sizeof(command),"SELECT * FROM %s",Table);
		new Handle:SQLite_db = ReadPackCell(DataBase);
		ReadPackString(DataBase, driver, sizeof(driver));
		
		if(SQLite_db!=INVALID_HANDLE)
		{
			new Handle:query = SQL_Query(SQLite_db, command);
			if(query==INVALID_HANDLE)
			{
				if(BigQuery)
				{
					SQLite_BigQuery(DataBase, "CREATE TABLE %s (%s)", Table, Field);
				}
				else
				{
					SQLite_Query(DataBase, "CREATE TABLE %s (%s)", Table, Field);
				}
				if(SQLite_DebugMod) LogToFileEx(SQLite_logpath, "[success] create '%s' table(成功創建數據庫表格\34%s\34)",Table,Table);
			}
			else
			{
				if(SQLite_DebugMod) LogToFileEx(SQLite_logpath, "[success] '%s' already exists(成功查找到數據庫表格\34%s\34)",Table,Table);
				
				CheckFieldStatus(DataBase, Table, Field, FieldMaxlen);
				
				if(SQLite_Timeout!=INVALID_HANDLE)
				{
					KillTimer(SQLite_Timeout);
					SQLite_Timeout = INVALID_HANDLE;
				}
				SQLite_Timeout = CreateTimer(10.0, sqldb_closeConnect, DataBase, TIMER_REPEAT);
			}
		}
		else
		{
			if(SQLite_DebugMod) LogToFileEx(SQLite_logpath, "[logic  ] '%s' maybe disconnected,reconncet(數據庫\34%s\34可能已經斷開連接,重新連接中)",driver,driver);
			
			if(BigQuery)
			{
				SQLite_BigQuery(DataBase, "CREATE TABLE %s (%s)", Table, Field);
			}
			else
			{
				SQLite_Query(DataBase, "CREATE TABLE %s (%s)", Table, Field);
			}
		}
	}
}

//SQLite Insert
SQLite_Insert(Handle:DataBase, bool:BigQuery=false, const String:Table[], const String:Field[], const String:Values[], any:...)
{
	if(DataBase != INVALID_HANDLE)
	{
		if(BigQuery)
		{
			new String:command[2048];
			new String:sql[2048];
			Format(command, sizeof(command), "INSERT INTO %s (%s) VALUES(%s)", Table, Field, Values);
			VFormat(sql, sizeof(sql), command, 6);
			SQLite_BigQuery(DataBase,sql);
		}
		else
		{
			new String:command[512];
			new String:sql[512];
			Format(command, sizeof(command), "INSERT INTO %s (%s) VALUES(%s)", Table, Field, Values);
			VFormat(sql, sizeof(sql), command, 6);
			SQLite_Query(DataBase,sql);
		}
	}
}

//SQLite Update
SQLite_Update(Handle:DataBase, bool:BigQuery=false, const String:command[], any:...)
{
	if(DataBase != INVALID_HANDLE)
	{
		if(BigQuery)
		{	
			new String:sql[2048];
			VFormat(sql,sizeof(sql),command,4);
			SQLite_BigQuery(DataBase,sql);
		}
		else
		{
			new String:sql[512];
			VFormat(sql,sizeof(sql),command,4);
			SQLite_Query(DataBase,sql);
		}
	}
}



CheckFieldStatus(Handle:DataBase, const String:Table[], const String:Field_Str[], maxlen)
{
	new const arrayLen = CountOfField_InStr(Field_Str,maxlen);
	if(SQLite_DebugMod) LogToFileEx(SQLite_logpath, "[logic  ] checking Field from Table...(檢查表中字段值是否完整)");
	new String:field[arrayLen][32];
	ExplodeString(Field_Str,",",field,arrayLen,32);
	for(new i=0;i<arrayLen;i++)
	{
		if(strlen(field[i]) && SQLite_FieldNotInTable(DataBase, Table, field[i]))
		{
			SQLite_AddField(DataBase, Table, field[i]);
		}
	}
}

CountOfField_InStr(const String:FieldText[],len)
{
	new count = 0;
	for(new i=0;i<len;i++)
	{
		if(FieldText[i]==',')
		{
			count++;
		}
	}
	return count;
}

bool:SQLite_IsFieldExists(Handle:DataBase, const String:Table[], const String:Field[])
{
	new Handle:query = SQLite_Query(DataBase,"SELECT * FROM %s WHERE CDKey = '%s'", Table, Field);
	if(query!=INVALID_HANDLE && SQL_GetRowCount(query)>0 && SQL_FetchRow(query))
	{
		CloseHandle(query);
		return true;
	}
	else
	{
		return false;
	}
}