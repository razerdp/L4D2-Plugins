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
 
new Handle:SQLite_Timeout = INVALID_HANDLE;

//SQLite Execute Command for default
Handle:SQLite_Query(Handle:DataBase, const String:sSql[], any:...)
{
	if(SQLite_Timeout!=INVALID_HANDLE)
	{
		KillTimer(SQLite_Timeout);
		SQLite_Timeout = INVALID_HANDLE;
	}

	ResetPack(DataBase,false);
	new Handle:SQLite_db = ReadPackCell(DataBase);
	new String:driver[64];
	ReadPackString(DataBase,driver,sizeof(driver));
	
	new String:sql[512];
	new String:error[512];
	new Handle:query = INVALID_HANDLE;
	
	VFormat(sql, sizeof(sql), sSql, 3);

	if(SQLite_db == INVALID_HANDLE) 
	{
		if(SQLite_DebugMod)LogToFileEx(SQLite_logpath, "[logic  ] The SQL was disconnected when execute \034[command]%s\034, will be reconncet\n(执行数据库指令 \34%s\34 时发现数据库未连接,将重新连接...)", sql,sql);
		
		ResetPack(DataBase,true);
		new Handle:Tmp_data = SQLite_Connect(driver);
			
		ResetPack(Tmp_data);
		new Handle:db_tmp = ReadPackCell(Tmp_data);
			
		WritePackCell(DataBase,db_tmp);
		WritePackString(DataBase,driver);
		CloseHandle(Tmp_data);
		return SQLite_Query(DataBase,sql);
	}
	else
	{
		query = SQL_Query(SQLite_db, sql);
		if(SQLite_DebugMod) 
		{
			LogToFileEx(SQLite_logpath, "[command] %s", sql);
			if( query == INVALID_HANDLE ) 
			{
				SQL_GetError(SQLite_db, error, sizeof(error));
				LogToFileEx(SQLite_logpath, "[error] %s (sql:%s)", error, sql);
			}
		}
		SQLite_Timeout = CreateTimer(10.0, sqldb_closeConnect, DataBase, TIMER_REPEAT);
	}
	
	return query;
}

//SQLite Execute Command for Long String
Handle:SQLite_BigQuery(Handle:DataBase, const String:sSql[], any:...)
{
	if(SQLite_Timeout!=INVALID_HANDLE)
	{
		KillTimer(SQLite_Timeout);
		SQLite_Timeout = INVALID_HANDLE;
	}

	ResetPack(DataBase,false);
	new Handle:SQLite_db = ReadPackCell(DataBase);
	new String:driver[64];
	ReadPackString(DataBase,driver,sizeof(driver));
	
	new String:sql[2048];
	new String:error[2048];
	new Handle:query = INVALID_HANDLE;
	
	VFormat(sql, sizeof(sql), sSql, 3);

	if(SQLite_db == INVALID_HANDLE) 
	{
		if(SQLite_DebugMod)LogToFileEx(SQLite_logpath, "[logic  ] The SQL was disconnected when execute \034[command]%s\034, will be reconncet\n(执行数据库指令 \34%s\34 时发现数据库未连接,将重新连接...)", sql,sql);
		
		ResetPack(DataBase,true);
		new Handle:Tmp_data = SQLite_Connect(driver);
			
		ResetPack(Tmp_data);
		new Handle:db_tmp = ReadPackCell(Tmp_data);
			
		WritePackCell(DataBase,db_tmp);
		WritePackString(DataBase,driver);
		CloseHandle(Tmp_data);
		return SQLite_BigQuery(DataBase,sql);
	}
	else
	{
		query = SQL_Query(SQLite_db, sql);
		if(SQLite_DebugMod) 
		{
			LogToFileEx(SQLite_logpath, "[command] %s", sql);
			if( query == INVALID_HANDLE ) 
			{
				SQL_GetError(SQLite_db, error, sizeof(error));
				LogToFileEx(SQLite_logpath, "[error] %s (sql:%s)", error, sql);
			}
		}
		SQLite_Timeout = CreateTimer(10.0, sqldb_closeConnect, DataBase, TIMER_REPEAT);
	}
	
	return query;
}

bool:SQLite_FieldNotInTable(Handle:DataBase, const String:Table[], const String:Field[])
{
	if(DataBase != INVALID_HANDLE)
	{
		ResetPack(DataBase,false);
		new String:command[512];
		FormatEx(command,sizeof(command),"SELECT %s FROM %s", Field, Table);
		new Handle:SQLite_db = ReadPackCell(DataBase);
		if(SQLite_db!=INVALID_HANDLE)
		{
			new Handle:query = SQL_Query(SQLite_db, command);
			if(query==INVALID_HANDLE)
			{
				if(SQLite_DebugMod) LogToFileEx(SQLite_logpath, "[logic  ] Field:%s not in Table:%s", Field, Table);
				return true;
			}
		}
	}
	return false;
}

SQLite_AddField(Handle:DataBase, const String:Table[], const String:Field[])
{
	if(DataBase != INVALID_HANDLE)
	{
		ResetPack(DataBase,false);
		new String:command[512];
		FormatEx(command,sizeof(command),"SELECT %s FROM %s", Field, Table);
		new Handle:SQLite_db = ReadPackCell(DataBase);
		if(SQLite_db!=INVALID_HANDLE)
		{
			new Handle:query = SQL_Query(SQLite_db, command);
			if(query==INVALID_HANDLE)
			{
				FormatEx(command,sizeof(command),"ALTER %s ADD %s", Table, Field);
				SQL_Query(SQLite_db, command);
				if(SQLite_DebugMod) LogToFileEx(SQLite_logpath, "[success] Add Field:%s success from Table:%s", Field, Table);
			}
		}
	}
}

public Action:sqldb_closeConnect(Handle:Timer, Handle:sql_data)
{
	KillTimer(Timer);
	SQLite_Timeout = INVALID_HANDLE;
	
	ResetPack(sql_data,false);
	new String:driver[64];
	new Handle:SQLite_db = ReadPackCell(sql_data);
	ReadPackString(sql_data, driver, sizeof(driver));
	
	CloseHandle(SQLite_db);
	SQLite_db = INVALID_HANDLE;
	
	ResetPack(sql_data,true);
	WritePackCell(sql_data,SQLite_db);
	WritePackString(sql_data,driver);
	
	if(SQLite_DebugMod) LogToFileEx(SQLite_logpath, "[success] 数据库闲时10秒断开.");
}