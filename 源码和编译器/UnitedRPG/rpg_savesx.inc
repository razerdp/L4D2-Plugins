#include "UnitedRPG/common/Serialization.inc"
/************************************************************************
*	存档保存读取功能
************************************************************************/
new Handle:ServerTimeLog = INVALID_HANDLE;

stock LoadRPGData()
{
	/* 服务器时间日志 */
	ServerTimeLog = CreateKeyValues("Server Time Log");
	BuildPath(Path_SM, ServerTimePath, 255, "data/ServerTimeLog.txt");
	if (FileExists(ServerTimePath))
		FileToKeyValues(ServerTimeLog, ServerTimePath);
	else
		KeyValuesToFile(ServerTimeLog, ServerTimePath);
}




/* 读取存档Function */
bool:ClientSaveToFileLoad(Client)
{
	if(!ID[Client])
	{
		LogMessage("[@ClientSaveToFileLoad]玩家[%N]未登录，无法读取档案.", Client);
		return false;
	}

	decl String:Info[512], String:Skill[512], String:Sing[128], String:Roobot[64], String:Master[512], String:Master2[64], String:BagData[255], String:ItemXH[255], String:ItemZB[1024];

	// 查询并载入用户基本信息
	new Handle:query = db_query("select * from ssdf where user_id = %d", ID[Client]);
	if(query != INVALID_HANDLE && SQL_GetRowCount(query) > 0 && SQL_FetchRow(query)) {

		VIP[Client]						= SQL_FetchInt(query, 3);
		VIPTL[Client]					= SQL_FetchInt(query, 4);
		VIPYEAR[Client]					= SQL_FetchInt(query, 5);
		NewLifeCount[Client]			= SQL_FetchInt(query, 6);
		Lv[Client]						= SQL_FetchInt(query, 7);
		JD[Client]						= SQL_FetchInt(query, 8);
		Cash[Client]					= SQL_FetchInt(query, 9);
		XB[Client]						= SQL_FetchInt(query, 10);
		StatusPoint[Client]				= SQL_FetchInt(query, 11);
		SkillPoint[Client]				= SQL_FetchInt(query, 12);
		KTCount[Client]					= SQL_FetchInt(query, 13);
		Str[Client]						= SQL_FetchInt(query, 14);
		Agi[Client]						= SQL_FetchInt(query, 15);
		Health[Client]					= SQL_FetchInt(query, 16);
		Endurance[Client]				= SQL_FetchInt(query, 17);
		Intelligence[Client]			= SQL_FetchInt(query, 18);
		EXP[Client]						= SQL_FetchInt(query, 19);

		SQL_FetchString(query, 20, Info, sizeof(Info));
		SQL_FetchString(query, 21, Skill, sizeof(Skill));
		SQL_FetchString(query, 22, Sing, sizeof(Sing));
		SQL_FetchString(query, 23, Roobot, sizeof(Roobot));
		SQL_FetchString(query, 24, Master, sizeof(Master));
		SQL_FetchString(query, 25, Master2, sizeof(Master2));
		SQL_FetchString(query, 26, BagData, sizeof(BagData));
		SQL_FetchString(query, 27, ItemXH, sizeof(ItemXH));
		SQL_FetchString(query, 28, ItemZB, sizeof(ItemZB));

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
	} else {
		decl String:error[255];
		SQL_GetError(db, error, sizeof(error));
		LogToFileEx(db_log, "[notice]用户[%N]档案载入失败![error: %s]", Client, error);
	}
	CloseHandle(query);
	return false;
}

/* 存档Function */
public ClientSaveToFileSave(Client)
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

	db_fastBigQuery("call ssdf_update(%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')",
		ID[Client],
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
		ItemZB);

	// 保存存档日期
	db_fastQuery("update member set timeline = sysdate(), is_admin = %d where id = %d", (IsAdmin[Client] ? 1 : 0), ID[Client]);
}

/* 手动存档 */
public Action:Command_RPGSave(Client, args)
{
	PlayerManualSave(Client);
	return Plugin_Handled;
}


// 用户登陆检测及注册
bool:RegLogin(Client, String:password[] = "")
{

		decl userId, userStatus, String:InfoPassword[PasswordLength], String:username[64];

		// 如果是手动输入，则以手动输入为准，否则读取默认保存处密码
		if(StrEqual(password, "", true))
			GetClientInfo(Client, "rpgpw", InfoPassword, PasswordLength);
		else
			strcopy(InfoPassword, PasswordLength, password);

		// 获取玩家用户名
		SafeGetClientName(Client, username, sizeof(username));

		/* 读取玩家密码 */
		new Handle:query = db_query("select * from member where username = '%s'", username);
		if (query != INVALID_HANDLE && SQL_GetRowCount(query) && SQL_FetchRow(query))
		{
			userId = SQL_FetchInt(query, 0);
			userStatus = SQL_FetchInt(query, 5);
			SQL_FetchString(query, 2, Password[Client], PasswordLength);
			CloseHandle(query);

			// 通服封号
			if(userStatus == 1) return (BanUser(Client));

			// 检测密码是否匹配成功
			if(StrEqual(Password[Client], InfoPassword, true))
			{
				// 本服内有信息则直接载入，无信息则创建并载入
				query = db_query("select user_id, status from ssdf where user_id = %d", userId);
				if(query != INVALID_HANDLE && SQL_GetRowCount(query) && SQL_FetchRow(query))
				{
					// 本服封号
					if(SQL_FetchInt(query, 1) == 1)
					{
						CloseHandle(query);
						return (BanUser(Client));
					}

					ID[Client] = userId;
					IsPasswordConfirm[Client] = ClientSaveToFileLoad(Client);
				} else RegInSerer(Client, userId, username);

				CloseHandle(query);
				return true;
			}
			return false;
		}

		// 新注册用户
		if( !StrEqual(InfoPassword, "", true) && !StrEqual(username, "", true))
		{
			return CreateNewMember(Client, username, InfoPassword);
		}

		return false;
}

// 创建用户
bool:CreateNewMember(Client, String:username[], String:password[])
{
	if(!IsClientInGame(Client) || StrEqual(password, "", true) || StrEqual(username, "", true) )
		return false;

	db_fastQuery("INSERT INTO member (username, password) VALUES('%s', '%s');", username, password);
	new Handle:query = db_query("select * from member where username = '%s'", username);

	if (query != INVALID_HANDLE && SQL_GetRowCount(query) && SQL_FetchRow(query))
	{
		new userId = SQL_FetchInt(query, 0);
		CloseHandle(query);
		strcopy(Password[Client], sizeof(Password[]), password);
		RegInSerer(Client, userId, username);
		return true;
	}

	return false;
}

// 注册信息及背包
RegInSerer(Client, userId, String:username[])
{
	decl giveSP, giveKSP,giveCASH;
	giveSP = 0;
	giveKSP = 0;
	giveCASH = GetConVarInt(cv_firtsreg);

	db_fastQuery("INSERT INTO ssdf (`user_id`, `nickname`, `SP`, `KSP`, `CASH`) VALUES(%d, '%s', %d, %d, %d);", userId, username, giveSP, giveKSP, giveCASH);
	// 确认登陆
	ID[Client] = userId;
	IsPasswordConfirm[Client] = ClientSaveToFileLoad(Client);

	// 注册信息
	if(IsClientInGame(Client))
	{
		// CPrintToChat(Client, "\x05[系统]:\x03在本服注册密码后,首次会送妳{red}%d金钱\x03,希望妳能在游戏中茁壮成长!", FIRTS_CASH);
		CPrintToChat(Client, MSG_ENTERPASSWORD_ACTIVATED, Password[Client]);
		CPrintToChat(Client, MSG_PASSWORD_EXPLAIN);
	}
}


// 封号用户
bool:BanUser(Client)
{
	KickClient(Client, "您的帐号已被冻结，更多详情请联系管理员！%s", MSG_QQ_GROUPS);
	return false;
}