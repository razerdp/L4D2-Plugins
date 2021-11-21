/*****************************************************************************/

/*Author	= MicroLeo , Idea by UnitedRPG_V3.65 */

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

#include "UnitedRPG/ArchiveSystems/SQLiteInclude.inc"

new Handle:h_ArchiveSys = INVALID_HANDLE;
new Handle:h_SQLiteDatabase = INVALID_HANDLE;

SQLiteArchiveSys_OnPluginStart()
{
	Debug_RegConVar();
	h_ArchiveSys = CreateConVar("l4d_SQLiteArchiveSysEnabled", "1", "是否开启SQLite存档模式", FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY, true, 0.0, true, 1.0);
	
	//使用系统默认配置好的数据库, 避免手动配置数据库
	h_SQLiteDatabase = SQLite_Connect(SQLiteDriver);//尝试连接到数据库
	SQLite_CreateTable(h_SQLiteDatabase, AccountTable, AccountField, sizeof(AccountField), false);//尝试创建数据库表格“Account”
	SQLite_CreateTable(h_SQLiteDatabase, GameDataTable, GameDataField, sizeof(GameDataField), false);//尝试创建数据库表格"Gamedata"
}

/* 读取存档Function */
bool:SQLiteArchiveSys_ClientSaveToFileLoad(Client)
{
	if(!ID[Client])
	{
		LogMessage("[@ClientSaveToFileLoad]玩家[%N]未登录，无法读取档案.", Client);
		return false;
	}

	decl String:Info[512], String:Skill[512], String:Sing[128], String:Roobot[64], String:Master[512], String:Master2[64], String:BagData[255], String:ItemXH[255], String:ItemZB[1024];

	// 查询并载入用户基本信息
	new Handle:query = SQLite_Query(h_SQLiteDatabase,"SELECT * FROM %s where UserID = %d", GameDataTable, ID[Client]);
	if(query != INVALID_HANDLE && SQL_GetRowCount(query) > 0 && SQL_FetchRow(query)) 
	{
		VIP[Client]						= SQL_FetchInt(query, 5);
		VIPTL[Client]					= SQL_FetchInt(query, 6);
		VIPYEAR[Client]					= SQL_FetchInt(query, 7);
		NewLifeCount[Client]			= SQL_FetchInt(query, 8);
		Lv[Client]						= SQL_FetchInt(query, 9);
		JD[Client]						= SQL_FetchInt(query, 10);
		Cash[Client]					= SQL_FetchInt(query, 11);
		XB[Client]						= SQL_FetchInt(query, 12);
		StatusPoint[Client]				= SQL_FetchInt(query, 13);
		SkillPoint[Client]				= SQL_FetchInt(query, 14);
		KTCount[Client]					= SQL_FetchInt(query, 15);
		Str[Client]						= SQL_FetchInt(query, 16);
		Agi[Client]						= SQL_FetchInt(query, 17);
		Health[Client]					= SQL_FetchInt(query, 18);
		Endurance[Client]				= SQL_FetchInt(query, 19);
		Intelligence[Client]			= SQL_FetchInt(query, 20);
		EXP[Client]						= SQL_FetchInt(query, 21);

		SQL_FetchString(query, 22, Info, sizeof(Info));
		SQL_FetchString(query, 23, Skill, sizeof(Skill));
		SQL_FetchString(query, 24, Sing, sizeof(Sing));
		SQL_FetchString(query, 25, Roobot, sizeof(Roobot));
		SQL_FetchString(query, 26, Master, sizeof(Master));
		SQL_FetchString(query, 27, Master2, sizeof(Master2));
		SQL_FetchString(query, 28, BagData, sizeof(BagData));
		SQL_FetchString(query, 29, ItemXH, sizeof(ItemXH));
		SQL_FetchString(query, 30, ItemZB, sizeof(ItemZB));

		UnSerializationInfo(Client, Info);
		UnSerializationSkill(Client, Skill);
		UnSerializationEveryDaySign(Client, Sing);
		UnSerializationMaster(Client, Master);
		UnSerializationMaster2(Client, Master2);

		Explode(Roobot, ",", RobotUpgradeLv[Client], sizeof(RobotUpgradeLv[]));
		GetPlayerBag(BagData, I_Bag[Client]);
		Explode(ItemXH, ",", PlayerItem[Client][ITEM_XH], ITEM_XH_MAX);
		Explode(ItemZB, ",", PlayerItem[Client][ITEM_ZB], ITEM_ZB_MAX);

		//装备到期检查
		PlayerZBIsOver(Client);
		return true;
	} 
	else 
	{
		decl String:error[255];
		SQL_GetError(db, error, sizeof(error));
		LogToFileEx(db_log, "[notice]用户[%N]档案载入失败![error: %s]", Client, error);
	}
	CloseHandle(query);
	return false;
}

/* 存档Function */
public SQLiteArchiveSys_ClientSaveToFileSave(Client, bool:IsDisconnected)
{
	if (!ID[Client] || !IsPasswordConfirm[Client])
		return;

	decl String:Info[512], String:Skill[512], String:Sing[128], String:Roobot[64], String:Master[512], String:Master2[64], String:BagData[255], String:ItemXH[255], String:ItemZB[1024];

	// 用户信息
	SerializationInfo(Client, Info, sizeof(Info));

	// 技能
	SerializationSkill(Client, Skill, sizeof(Skill));

	// 每日签到
	SerializationEveryDaySign(Client, Sing, sizeof(Sing));

	// 拜师
	SerializationMaster(Client, Master, sizeof(Master));

	// 在线时间
	SerializationMaster2(Client, Master2, sizeof(Master2));

	// 机器人
	Implode(RobotUpgradeLv[Client], sizeof(RobotUpgradeLv[]), ",", Roobot, sizeof(Roobot));

	// 背包物品
	SetPlayerBag(I_Bag[Client], BagData, sizeof(BagData));

	// 消耗品
	Implode(PlayerItem[Client][ITEM_XH], ITEM_XH_MAX, ",", ItemXH, sizeof(ItemXH));

	// 装备类道具

	//装备到期检查
	PlayerZBIsOver(Client);

	for (new i; i < ITEM_ZB_MAX; i++)
	{
		if (i == 0 || i == 1 || i == 36)
			PlayerItem[Client][ITEM_ZB][i] = 0;
	}

	Implode(PlayerItem[Client][ITEM_ZB], ITEM_ZB_MAX, ",", ItemZB, sizeof(ItemZB));

	SQLite_Update(h_SQLiteDatabase, true, "UPDATE %s SET VIP=%d, VIPTL=%d, VIPYEAR=%d, NewLifeCount=%d, Lv=%d, JD=%d, Cash=%d, XB=%d, StatusPoint=%d, SkillPoint=%d, KTCount=%d, Str=%d, Agi=%d, Health=%d, Endurance=%d, Intelligence=%d, EXP=%d, Info='%s', Skill='%s', Sing='%s', Roobot='%s', Master='%s', Master2='%s', BagData='%s', ItemXH='%s', ItemZB='%s' WHERE UserID=%d",
		GameDataTable,
		VIP[Client],
		VIPTL[Client],
		VIPYEAR[Client],
		NewLifeCount[Client],
		Lv[Client],
		JD[Client],
		Cash[Client],
		XB[Client],
		StatusPoint[Client],
		SkillPoint[Client],
		KTCount[Client],
		Str[Client],
		Agi[Client],
		Health[Client],
		Endurance[Client],
		Intelligence[Client],
		EXP[Client],
		Info,
		Skill,
		Sing,
		Roobot,
		Master,
		Master2,
		BagData,
		ItemXH,
		ItemZB,
		ID[Client]);
		
	if(IsDisconnected)
	{
		SQLite_Update(h_SQLiteDatabase, false, "UPDATE %s SET UserID=%d WHERE UserID=%d", GameDataTable, 0, Client);//玩家离线后初始化UserID为0
	}
	
	// 保存存档日期
	new String:date[32];
	FormatTime(date,sizeof(date),"%Y%m%d", -1);
	SQLite_Update(h_SQLiteDatabase,false,"UPDATE %s SET LastLoginTime='%s',Admin=%d WHERE GameName='%N'",AccountTable,date,(IsAdmin[Client] ? 1 : 0),Client);
}

// 用户登陆检测及注册
bool:SQLiteArchiveSys_RegLogin(Client, String:password[] = "")
{

		new userId, userStatus, String:InfoPassword[PasswordLength], String:username[64];

		// 如果是手动输入，则以手动输入为准，否则读取默认保存处密码
		if(StrEqual(password, "", true))
		{
			GetClientInfo(Client, "rpgpw", InfoPassword, PasswordLength);
		}
		else
		{
			strcopy(InfoPassword, PasswordLength, password);
		}

		// 获取玩家用户名
		SafeGetClientName(Client, username, sizeof(username));

		/* 读取玩家密码 */
		new Handle:query = SQLite_Query(h_SQLiteDatabase,"SELECT * FROM %s WHERE GameName='%s'", AccountTable, username);
		if (query != INVALID_HANDLE && SQL_GetRowCount(query) && SQL_FetchRow(query))
		{
			userId = Client;
			userStatus = SQL_FetchInt(query, 7);
			SQL_FetchString(query, 1, Password[Client], PasswordLength);
			CloseHandle(query);

			// 通服封号
			if(userStatus == 1) return (SQLiteArchiveSys_BanUser(Client));

			// 检测密码是否匹配成功
			if(StrEqual(Password[Client], InfoPassword, true))
			{
				// 本服内有信息则直接载入，无信息则创建并载入
				query = SQLite_Query(h_SQLiteDatabase,"SELECT UserID FROM %s WHERE Account='%s'", GameDataTable, username);
				if(query != INVALID_HANDLE && SQL_GetRowCount(query) && SQL_FetchRow(query))
				{
					// 本服封号
					if(userStatus == 2)
					{
						CloseHandle(query);
						return (SQLiteArchiveSys_BanUser(Client));
					}

					ID[Client] = userId;
					
					new String:IPAddress[64];
					GetClientIP(Client,IPAddress,sizeof(IPAddress));
					SQLite_Update(h_SQLiteDatabase, false, "UPDATE %s SET LastLoginIP='%s' WHERE GameName='%s'",AccountTable, IPAddress, username);
					
					SQLite_Update(h_SQLiteDatabase, false, "UPDATE %s SET UserID=%d WHERE UserID=%d",GameDataTable, 0, userId);//初始化所有相同UserID为0，以免冲突
					
					SQLite_Update(h_SQLiteDatabase, false, "UPDATE %s SET UserID=%d WHERE Account='%s'",GameDataTable, userId, username);
					IsPasswordConfirm[Client] = SQLiteArchiveSys_ClientSaveToFileLoad(Client);
				} 
				else 
				{
					SQLiteArchiveSys_RegInSerer(Client, userId, username);
				}

				CloseHandle(query);
				return true;
			}
			return false;
		}

		// 新注册用户
		if( !StrEqual(InfoPassword, "", true) && !StrEqual(username, "", true))
		{
			return SQLiteArchiveSys_CreateNewMember(Client, username, InfoPassword);
		}

		return false;
}

// 创建用户
bool:SQLiteArchiveSys_CreateNewMember(Client, String:username[], String:password[])
{
	if(!IsClientInGame(Client) || StrEqual(password, "", true) || StrEqual(username, "", true) )return false;
	
	SQLite_Update(h_SQLiteDatabase, false, "UPDATE %s SET UserID=%d WHERE UserID=%d",GameDataTable, 0, Client);//初始化所有相同UserID为0，以免冲突
	
	new String:IPAddress[64];
	GetClientIP(Client,IPAddress,sizeof(IPAddress));
	SQLite_Insert(h_SQLiteDatabase, false, AccountTable, "PassWord, GameName, SteamID, AccountType, Status, LastLoginIP", "'%s','%s',%d,'%s',%d,'%s'", password, username, GetSteamAccountID(Client), "default", 0, IPAddress);
	
	SQLite_Insert(h_SQLiteDatabase, false, GameDataTable, "UserID, Account", "%d,'%s'", Client, username);
	
	new Handle:query = SQLite_Query(h_SQLiteDatabase,"SELECT UserID FROM %s WHERE Account = '%s'", GameDataTable, username);
	if (query != INVALID_HANDLE && SQL_GetRowCount(query) && SQL_FetchRow(query))
	{
		new userId = SQL_FetchInt(query, 0);
		CloseHandle(query);
		strcopy(Password[Client], sizeof(Password[]), password);
		SQLiteArchiveSys_RegInSerer(Client, userId, username);
		return true;
	}

	return false;
}

// 注册信息及背包
SQLiteArchiveSys_RegInSerer(Client, userId, String:username[])
{
	decl giveSP, giveKSP,giveCASH;
	giveSP = 0;
	giveKSP = 0;
	giveCASH = GetConVarInt(cv_firtsreg);
	username[0] = 0;
	
	SQLite_Update(h_SQLiteDatabase, false, "UPDATE %s SET SP=%d,KSP=%d,Cash=%d WHERE UserID=%d",GameDataTable,giveSP,giveKSP,giveCASH,userId);
	// 确认登陆
	ID[Client] = userId;
	IsPasswordConfirm[Client] = SQLiteArchiveSys_ClientSaveToFileLoad(Client);

	// 注册信息
	if(IsClientInGame(Client))
	{
		// CPrintToChat(Client, "\x05[系统]:\x03在本服注册密码后,首次会送妳{red}%d金钱\x03,希望妳能在游戏中茁壮成长!", FIRTS_CASH);
		CPrintToChat(Client, MSG_ENTERPASSWORD_ACTIVATED, Password[Client]);
		CPrintToChat(Client, MSG_PASSWORD_EXPLAIN);
	}
}

// 封号用户
bool:SQLiteArchiveSys_BanUser(Client)
{
	KickClient(Client, "您的帐号已被冻结，更多详情请联系管理员！%s", MSG_QQ_GROUPS);
	return false;
}