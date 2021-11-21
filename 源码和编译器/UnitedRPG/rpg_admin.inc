RegisterCmds()
{
    /* RPG主选单 */
	RegConsoleCmd("sm_rpgmenu",	Menu_RPG);
	RegConsoleCmd("sm_rpg",		Menu_RPG);
	RegConsoleCmd("say",		Command_Say);
	RegConsoleCmd("say_team",	Command_SayTeam);
	RegConsoleCmd("sm_joingame", Johnson_joingame);		//新增 加入游戏指令 !joingame


	/* 分配属性 */
	RegConsoleCmd("sm_str",	AddStrength);
	RegConsoleCmd("sm_agi",	AddAgile);
	RegConsoleCmd("sm_hea",	AddHealth);
	RegConsoleCmd("sm_end",	AddEndurance);
	RegConsoleCmd("sm_int",	AddIntelligence);
	RegConsoleCmd("sm_cts",	AddCrits);
	RegConsoleCmd("sm_ctn",	AddCritMin);
	RegConsoleCmd("sm_ctx",	AddCritMax);
	/* 技能 */
	RegConsoleCmd("sm_useskill",	Menu_UseSkill);
	RegConsoleCmd("sm_sply",		UseAreaBlastingex);
	RegConsoleCmd("sm_hl",			UseHealing);
	RegConsoleCmd("sm_gwq",     	UseEarthQuakeA);
	RegConsoleCmd("sm_dizhen",   	UseEarthQuake);
	RegConsoleCmd("sm_am",			UseAmmoMaking);
	RegConsoleCmd("sm_sc",			UseSatelliteCannon);
	RegConsoleCmd("sm_baolei",		UseSatelliteCannonmiss);
	RegConsoleCmd("sm_sp",			UseSprint);
	RegConsoleCmd("sm_ia",			UseInfiniteAmmo);
	RegConsoleCmd("sm_bs",			UseBioShield);
	RegConsoleCmd("sm_baofa",		UseBioShieldmiss);
	RegConsoleCmd("sm_kbz",			UseBioShieldkb);
	RegConsoleCmd("sm_dr",			UseDamageReflect);
	RegConsoleCmd("sm_ms",			UseMeleeSpeed);
	RegConsoleCmd("sm_ts",			UseTeleportToSelect);
	RegConsoleCmd("sm_at",			UseHolyBolt);
	RegConsoleCmd("sm_dyzh",		UseDyzh);
	RegConsoleCmd("sm_tt",			UseTeleportTeam);
	RegConsoleCmd("sm_ztcs",		UseTeleportTeamzt);
	RegConsoleCmd("sm_fb",			UseFireBall);
	RegConsoleCmd("sm_ib",			UseIceBall);
	RegConsoleCmd("sm_cl",			UseChainLightning);
	RegConsoleCmd("sm_dbfgle",		UseChainmissLightning);
	RegConsoleCmd("sm_hb",			UseHealingBall);
	RegConsoleCmd("sm_dbfgl",		UseHealingBallmiss);
	RegConsoleCmd("sm_psd",			UseBrokenAmmo);
	RegConsoleCmd("sm_sdd",			UsePoisonAmmo);
	RegConsoleCmd("sm_xxd",			UseSuckBloodAmmo);
	RegConsoleCmd("sm_qybp",		UseAreaBlasting);
	RegConsoleCmd("sm_lsjgp",		UseLaserGun);
	RegConsoleCmd("sm_zd",			UseZdgc);
	RegConsoleCmd("sm_cdz",			UseCqdz);
	RegConsoleCmd("sm_ht",			UseSWHT);
	RegConsoleCmd("sm_ny",			UseWXNY);
	RegConsoleCmd("sm_dz",		    UseLDZ);
	RegConsoleCmd("sm_yl",			UseYLTJ);
	RegConsoleCmd("sm_gs",	        UseGZS);
	RegConsoleCmd("sm_nq",			UseFBZN);
	RegConsoleCmd("sm_xbfb",		UseXBFB);
	RegConsoleCmd("sm_hm",			UseHMZS);
	RegConsoleCmd("sm_sap",			UseSPZS);
	RegConsoleCmd("sm_sx",			UseSXZG);
	RegConsoleCmd("sm_ds",			UseDSZG);
	RegConsoleCmd("sm_phf",			UsePHFR);
	RegConsoleCmd("sm_pha",			UsePHAB);
	RegConsoleCmd("sm_phz",			UsePHZG);
	RegConsoleCmd("sm_phs",			UsePHSC);
	RegConsoleCmd("sm_qy",			UsePHFRA);
	RegConsoleCmd("sm_fc",			UsePHABA);
	RegConsoleCmd("sm_bp",			UsePHZGA);
	RegConsoleCmd("sm_sd",			UsePHSD);
	RegConsoleCmd("sm_xj",			UseXJ);
	RegConsoleCmd("sm_lllz",		UseLLLZ);
	RegConsoleCmd("sm_llle",		UseLLLE);
	RegConsoleCmd("sm_llls",		UseLLLS);
	RegConsoleCmd("sm_bbbs",		UseBBBS);
	RegConsoleCmd("sm_hyjw",		UseHYJW);
	RegConsoleCmd("sm_hyjw",		UseNQBF);
	RegConsoleCmd("sm_xzkb",		UseXZKB);
	RegConsoleCmd("sm_jbsy",		UseJBSY);
	
	
	/* 购物商店 */
	RegConsoleCmd("normalitem",		Menu_NormalItemShop);
	RegConsoleCmd("selectedgun",	Menu_SelectedGunShop);
	RegConsoleCmd("selectedmelee",	Menu_MeleeShop);
	RegConsoleCmd("robotshop",		Menu_RobotShop);
	RegConsoleCmd("viewskill",		Menu_ViewSkill);
	/*  密码 */
	RegConsoleCmd("sm_rpgpw",		EnterPassword,"sm_rpgpw 密码");
	RegConsoleCmd("sm_pw",		EnterPassword,"sm_pw 密码");
	RegConsoleCmd("sm_rpgresetpw",	ResetPassword,"sm_rpgresetpw 原来密码 新的密码");
	RegConsoleCmd("sm_rpgpwinfo",	Passwordinfo);
	/*  队友资讯 */
	RegConsoleCmd("sm_wanjia", Command_playerlistpanel);

    /* Admins */
	RegAdminCmd("sm_xb",	Command_GiveExp, ADMFLAG_KICK, "sm_givebj 玩家名字 数量");
	RegAdminCmd("sm_givelv",	Command_GiveLevel, ADMFLAG_KICK, "sm_givelv 玩家名字 数量");
	RegAdminCmd("sm_jb",	Command_GiveCash, ADMFLAG_KICK, "sm_givecash 玩家名字 数量");
	RegAdminCmd("sm_fullmp",	Command_FullMP, ADMFLAG_KICK, "sm_fullmp");
	RegAdminCmd("sm_givenl",	Command_GiveKT, ADMFLAG_KICK, "sm_givenl 玩家名字 数量");
	RegAdminCmd("sm_rptest",	Command_RpTest, ADMFLAG_KICK, "sm_rptest 编号");
	RegAdminCmd("sm_vip",	Command_SetVIP, ADMFLAG_KICK, "sm_vip 玩家名字 VIP类型(0 = 普通会员 1 = 白银会员 2 = 黄金会员 3 = 水晶会员 4 = 至尊会员 5 = 创世会员 6 = 末日会员 )");
	RegAdminCmd("sm_rpgkv",	Command_RPGKV, ADMFLAG_KICK, "sm_rpgkv name key vaule");
	RegAdminCmd("sm_rpgdel",	Command_RPGDEL, ADMFLAG_KICK, "sm_rpgdel name");
	RegAdminCmd("sm_rpggm",	Command_RPGGM, ADMFLAG_KICK, "sm_rpggm");
	RegAdminCmd("sm_rpgsn",	Command_RPGName, ADMFLAG_KICK, "sm_rpgsn");
	RegAdminCmd("sm_rpgreset",	Command_RPGReset, ADMFLAG_KICK, "sm_rpgreset");
	RegConsoleCmd("callvote",	Callvote_Handler);
	/* bot 增加 */
	RegAdminCmd("sm_addbot",	Command_AddBot, ADMFLAG_KICK, "sm_addbot");
	/* 时间流速 */
	RegAdminCmd("sm_settime",	Command_SetTime, ADMFLAG_KICK, "sm_settime");
	
	/* 特殊道具背包 */
	RegConsoleCmd("sm_tsdj", Command_MyTSDJ);
	/* VIP */
	RegConsoleCmd("sm_vipfree",	Command_VIP);
	RegConsoleCmd("sm_vipvote",	Command_VIPVote);
	
	/* 我的背包 */
	RegConsoleCmd("sm_mybag",	Command_MyBag);
	
	/* 我的道具 */
	RegConsoleCmd("sm_myitem",	Command_MyItem);
	RegConsoleCmd("sm_zb",	Command_SetItem);
	
	/* 手动存档 */
	RegConsoleCmd("sm_isave",	Command_RPGSave);
	
	/* 全部踢出更新 */
	RegServerCmd("sm_serverupdata", Command_ServerUpdata);
	
	/* 每日签到 */
	RegConsoleCmd("sm_qiandao",	Command_QianDao);
	
	/* 激活码 */
	RegConsoleCmd("sm_cdkey", Command_CDKey);
}

/* Admin选单 */
new Handle:hTopMenu = INVALID_HANDLE;
new TopMenuObject:Admin_GiveExp;
new TopMenuObject:Admin_GiveLv;
new TopMenuObject:Admin_ResetStatus;
new TopMenuObject:Admin_GiveCash;
new TopMenuObject:Admin_GiveKT;
new TopMenuObject:Admin_SetVIP;
new TopMenuObject:Admin_GiveXZ;
new TopMenuObject:Admin_GiveBH;
new TopMenuObject:Admin_GiveST;

new TopMenuObject:Admin_SpawnCDKey;

new AdminGiveAmount[MAXPLAYERS+1];
new g_id[MAXPLAYERS+1];

/* 其他 */
new Handle:ShowMode				=	INVALID_HANDLE;
new Handle:GiveAnnonce			=	INVALID_HANDLE;


/************************************************************************
*	管理员菜单Start
************************************************************************/
public OnLibraryRemoved(const String:name[])
{
	if (StrEqual(name, "adminmenu"))
	{
		hTopMenu = INVALID_HANDLE;
	}
}
public OnAdminMenuReady(Handle:topmenu)
{
	if (topmenu == hTopMenu) 
		return;
		
	hTopMenu = topmenu;
	AddToTopMenu(hTopMenu, "United RPG 菜单", TopMenuObject_Category, Menu_CategoryHandler, INVALID_TOPMENUOBJECT);
	
	new TopMenuObject:AdminTopmenu = FindTopMenuCategory(hTopMenu, "United RPG 菜单");
	
	if (AdminTopmenu != INVALID_TOPMENUOBJECT)
	{
		Admin_GiveExp = AddToTopMenu(hTopMenu, "rpg_givebj", TopMenuObject_Item, Menu_TopItemHandler, AdminTopmenu, "rpg_givebj", ADMFLAG_KICK);
		Admin_GiveLv = AddToTopMenu(hTopMenu, "rpg_givelv", TopMenuObject_Item, Menu_TopItemHandler, AdminTopmenu, "rpg_givelv", ADMFLAG_KICK);
		Admin_GiveCash = AddToTopMenu(hTopMenu, "rpg_givecash", TopMenuObject_Item, Menu_TopItemHandler, AdminTopmenu, "rpg_givecash", ADMFLAG_KICK);
		Admin_ResetStatus = AddToTopMenu(hTopMenu, "rpg_xidian", TopMenuObject_Item, Menu_TopItemHandler, AdminTopmenu, "rpg_xidian", ADMFLAG_KICK);
		Admin_GiveKT = AddToTopMenu(hTopMenu, "rpg_givekt", TopMenuObject_Item, Menu_TopItemHandler, AdminTopmenu, "rpg_givekt", ADMFLAG_KICK);
		Admin_SetVIP = AddToTopMenu(hTopMenu, "rpg_setvip", TopMenuObject_Item, Menu_TopItemHandler, AdminTopmenu, "rpg_setvip", ADMFLAG_KICK);
		Admin_GiveXZ = AddToTopMenu(hTopMenu, "rpg_givexz", TopMenuObject_Item, Menu_TopItemHandler, AdminTopmenu, "rpg_givexz", ADMFLAG_KICK);
		Admin_GiveBH = AddToTopMenu(hTopMenu, "rpg_givehz", TopMenuObject_Item, Menu_TopItemHandler, AdminTopmenu, "rpg_givehz", ADMFLAG_KICK);
		Admin_GiveST = AddToTopMenu(hTopMenu, "rpg_givest", TopMenuObject_Item, Menu_TopItemHandler, AdminTopmenu, "rpg_givest", ADMFLAG_KICK);		
		
		Admin_SpawnCDKey = AddToTopMenu(hTopMenu, "rpg_spawncdkey", TopMenuObject_Item, Menu_TopItemHandler, AdminTopmenu, "rpg_spawncdkey", ADMFLAG_KICK);		
		
	}
}
public Menu_CategoryHandler(Handle:topmenu, TopMenuAction:action, TopMenuObject:object_id, Client, String:buffer[], maxlength)
{
	if (action == TopMenuAction_DisplayTitle)
	{
		Format(buffer, maxlength, "United RPG 管理员菜单");
	}
	else if (action == TopMenuAction_DisplayOption)
	{
		Format(buffer, maxlength, "United RPG 管理员菜单");
	}
}

public Menu_TopItemHandler(Handle:topmenu, TopMenuAction:action, TopMenuObject:object_id, Client, String:buffer[], maxlength)
{
	if (action == TopMenuAction_DisplayOption)
	{
		if (object_id == Admin_GiveLv)
			Format(buffer, maxlength, "给予玩家等级");
		else if (object_id == Admin_GiveExp)
			Format(buffer, maxlength, "给予玩家玄币");
		else if (object_id == Admin_GiveCash)
			Format(buffer, maxlength, "给予玩家金钱");
		else if (object_id == Admin_ResetStatus)
			Format(buffer, maxlength, "给玩家洗点(不扣等级)");
		else if (object_id == Admin_GiveKT)
			Format(buffer, maxlength, "给予玩家转生");
		else if (object_id == Admin_SetVIP)
			Format(buffer, maxlength, "设置玩家为VIP");
		else if (object_id == Admin_GiveXZ)
			Format(buffer, maxlength, "给予玩家烈焰勋章");
		else if (object_id == Admin_GiveBH)
			Format(buffer, maxlength, "给予玩家炎神宝盒");
		else if (object_id == Admin_GiveST)
			Format(buffer, maxlength, "给予玩家强化石");
		else if (object_id == Admin_SpawnCDKey)
			Format(buffer, maxlength, "CDKey系统");			
	}
	else if (action == TopMenuAction_SelectOption)
	{
		if (object_id == Admin_GiveLv)
			g_id[Client] = 1, AdminGive(Client);
		else if (object_id == Admin_GiveExp)
			g_id[Client] = 2, AdminGive(Client);
		else if (object_id == Admin_GiveCash)
			g_id[Client] = 3, AdminGive(Client);
		else if (object_id == Admin_ResetStatus)
			g_id[Client] = 4, AdminGive_Handler(Client);
		else if (object_id == Admin_GiveKT)
			g_id[Client] = 5, AdminGive(Client);
		else if (object_id == Admin_SetVIP)
			Menu_SetVIPMenu_Select(Client);
		else if (object_id == Admin_GiveXZ)
			g_id[Client] = 7, AdminGive(Client);	
		else if (object_id == Admin_GiveBH)
			g_id[Client] = 8, AdminGive(Client);
		else if (object_id == Admin_GiveST)
			g_id[Client] = 9, AdminGive(Client);	
		else if (object_id == Admin_SpawnCDKey)
		{
			Menu_CDKeyMenu_Select(Client,hTopMenu);
		}
	}
}

AdminGive(Client)
{
	new Handle:menu = CreateMenu(AdminGive_MenuHandler);
	SetMenuTitle(menu, "选择数量");

	if (g_id[Client] == 1)
	{
		AddMenuItem(menu, "5", "5");
		AddMenuItem(menu, "10", "10");
		AddMenuItem(menu, "20", "20");
		AddMenuItem(menu, "30", "30");
		AddMenuItem(menu, "40", "40");
		AddMenuItem(menu, "50", "50");
		AddMenuItem(menu, "100", "100");
	}
	else if (g_id[Client] == 2)
	{
		AddMenuItem(menu, "50", "50");
		AddMenuItem(menu, "100", "100");
		AddMenuItem(menu, "200", "200");
		AddMenuItem(menu, "500", "500");
		AddMenuItem(menu, "1000", "1000");
		AddMenuItem(menu, "5000", "5000");
		AddMenuItem(menu, "50000", "50000");
	}
	else if (g_id[Client] == 3)
	{
		AddMenuItem(menu, "10000", "10000");
		AddMenuItem(menu, "20000", "20000");
		AddMenuItem(menu, "100000", "100000");
		AddMenuItem(menu, "250000", "250000");
		AddMenuItem(menu, "500000", "500000");
		AddMenuItem(menu, "1000000", "1000000");
		AddMenuItem(menu, "2500000", "2500000");
	}
	else if (g_id[Client] == 4)
	{
		AddMenuItem(menu, "500", "500");
		AddMenuItem(menu, "1000", "1000");
		AddMenuItem(menu, "2000", "2000");
		AddMenuItem(menu, "3000", "3000");
		AddMenuItem(menu, "5000", "5000");
		AddMenuItem(menu, "10000", "10000");
		AddMenuItem(menu, "20000", "20000");
	}
	else if (g_id[Client] == 5)
	{
		AddMenuItem(menu, "1", "1");
		AddMenuItem(menu, "2", "2");
		AddMenuItem(menu, "3", "3");
		AddMenuItem(menu, "4", "4");
		AddMenuItem(menu, "5", "5");
		AddMenuItem(menu, "6", "6");
		AddMenuItem(menu, "7", "7");
	}
	else if (g_id[Client] == 6)
	{
		AddMenuItem(menu, "1", "1");
		AddMenuItem(menu, "2", "2");
		AddMenuItem(menu, "3", "3");
		AddMenuItem(menu, "4", "4");
		AddMenuItem(menu, "5", "5");
		AddMenuItem(menu, "6", "6");
		AddMenuItem(menu, "7", "7");
	}
	else if (g_id[Client] == 7)
	{
		AddMenuItem(menu, "100", "100");
		AddMenuItem(menu, "200", "200");
		AddMenuItem(menu, "1000", "1000");
		AddMenuItem(menu, "2500", "2500");
		AddMenuItem(menu, "5000", "5000");
		AddMenuItem(menu, "10000", "10000");
		AddMenuItem(menu, "25000", "25000");
	}
	else if (g_id[Client] == 8)
	{
		AddMenuItem(menu, "100", "100");
		AddMenuItem(menu, "200", "200");
		AddMenuItem(menu, "1000", "1000");
		AddMenuItem(menu, "2500", "2500");
		AddMenuItem(menu, "5000", "5000");
		AddMenuItem(menu, "10000", "10000");
		AddMenuItem(menu, "25000", "25000");
	}
	else if (g_id[Client] == 9)
	{
		AddMenuItem(menu, "100", "100");
		AddMenuItem(menu, "200", "200");
		AddMenuItem(menu, "1000", "1000");
		AddMenuItem(menu, "2500", "2500");
		AddMenuItem(menu, "5000", "5000");
		AddMenuItem(menu, "10000", "10000");
		AddMenuItem(menu, "25000", "25000");
	}	

	SetMenuExitBackButton(menu, true);

	DisplayMenu(menu, Client, MENU_TIME_FOREVER);
}
public AdminGive_MenuHandler(Handle:menu, MenuAction:action, param1, param2)
{
	if (action == MenuAction_End)
	{
		CloseHandle(menu);
	}
	else if (action == MenuAction_Cancel)
	{
		if (param2 == MenuCancel_ExitBack && hTopMenu != INVALID_HANDLE)
		{
			DisplayTopMenu(hTopMenu, param1, TopMenuPosition_LastCategory);
		}
	}
	else if (action == MenuAction_Select)
	{
		decl String:info[32];

		GetMenuItem(menu, param2, info, sizeof(info));
		AdminGiveAmount[param1] = StringToInt(info);
		AdminGive_Handler(param1);
	}
}
AdminGive_Handler(Client)
{
	new Handle:menu = CreateMenu(Admingive_MenuHandler2);
	
	if (g_id[Client] == 1)	SetMenuTitle(menu, "给予玩家等级");
	if (g_id[Client] == 2)	SetMenuTitle(menu, "给予玩家玄币");
	if (g_id[Client] == 3)	SetMenuTitle(menu, "给予玩家金钱");
	if (g_id[Client] == 4)	SetMenuTitle(menu, "选择洗点玩家");
	if (g_id[Client] == 5)	SetMenuTitle(menu, "给予玩家转生次数");
	if (g_id[Client] == 7)	SetMenuTitle(menu, "给予玩家烈焰勋章");	
	if (g_id[Client] == 8)	SetMenuTitle(menu, "给予玩家炎神宝盒");	
	if (g_id[Client] == 9)	SetMenuTitle(menu, "给予玩家强化石");	
		
	SetMenuExitBackButton(menu, true);
	AddTargetsToMenu2(menu, Client, COMMAND_FILTER);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);
}
public Admingive_MenuHandler2(Handle:menu, MenuAction:action, param1, param2)
{
	if (action == MenuAction_End)	CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param2 == MenuCancel_ExitBack && hTopMenu != INVALID_HANDLE)
			DisplayTopMenu(hTopMenu, param1, TopMenuPosition_LastCategory);
	}
	else if (action == MenuAction_Select)
	{
		decl String:info[32], String:targetName[MAX_NAME_LENGTH];
		new userid, target;

		GetMenuItem(menu, param2, info, sizeof(info));
		userid = StringToInt(info);

		if ((target = GetClientOfUserId(userid)) == 0)
			CPrintToChat(param1, "{green}[UnitedRPG] \x01%t", "Player no longer available");
		else if (!CanUserTarget(param1, target))
			CPrintToChat(param1, "{green}[UnitedRPG] \x01%t", "Unable to target");
		
		GetClientName(target, targetName, sizeof(targetName));
		if (g_id[param1] == 1)
		{
			Lv[target] += AdminGiveAmount[param1];
			StatusPoint[target] += AdminGiveAmount[param1]*GetConVarInt(LvUpSP);
			SkillPoint[target] += AdminGiveAmount[param1]*GetConVarInt(LvUpKSP);
			if (GiveAnnonce!=INVALID_HANDLE && GetConVarInt(GiveAnnonce))	CPrintToChatAllEx(param1, MSG_ADMIN_GIVE_LV, targetName, AdminGiveAmount[param1]);
		}
		else if (g_id[param1] == 2)
		{
			XB[target] += AdminGiveAmount[param1];
			if (GetConVarInt(GiveAnnonce))	CPrintToChatAllEx(param1, MSG_ADMIN_GIVE_EXP, targetName, AdminGiveAmount[param1]);
		}
		else if (g_id[param1] == 3)
		{
			Cash[target] += AdminGiveAmount[param1];
			if (GetConVarInt(GiveAnnonce))	CPrintToChatAllEx(param1, MSG_ADMIN_GIVE_CASH, targetName, AdminGiveAmount[param1]);
		}
		else if (g_id[param1] == 4)
		{
			ClinetResetStatus(target, Admin);
		}
		else if (g_id[param1] == 5)
		{
			NewLifeCount[target] += AdminGiveAmount[param1];
			if (GetConVarInt(GiveAnnonce))	CPrintToChatAllEx(param1, MSG_ADMIN_GIVE_KT, targetName, AdminGiveAmount[param1]);
		}
		else if (g_id[param1] == 7)
		{
			Lyxz[target] += AdminGiveAmount[param1];
			if (GetConVarInt(GiveAnnonce))	CPrintToChatAllEx(param1, MSG_ADMIN_GIVE_LYXZ, targetName, AdminGiveAmount[param1]);
		}
		else if (g_id[param1] == 8)
		{
			Eqbox[target] += AdminGiveAmount[param1];
			if (GetConVarInt(GiveAnnonce))	CPrintToChatAllEx(param1, MSG_ADMIN_GIVE_QJBHE, targetName, AdminGiveAmount[param1]);
		}	
		else if (g_id[param1] == 9)
		{
			Qhs[target] += AdminGiveAmount[param1];
			if (GetConVarInt(GiveAnnonce))	CPrintToChatAllEx(param1, MSG_ADMIN_GIVE_QHSD, targetName, AdminGiveAmount[param1]);
		}		
		AdminGive_Handler(param1);
	}
}

/************************************************************************
*	管理员菜单END
************************************************************************/

/************************************************************************
*	Command和其他功能
************************************************************************/

public Action:Command_GiveST(Client, args)
{
	if (args < 1)
	{
		ReplyToCommand(Client, "[SM] 用法: sm_givest  <#userid|name> [数量]");
		return Plugin_Handled;
	}

	decl String:arg[MAX_NAME_LENGTH], String:arg2[64];
	GetCmdArg(1, arg, sizeof(arg));

	if (args > 1)
	{
		GetCmdArg(2, arg2, sizeof(arg2));
	}
	decl String:target_name[MAX_TARGET_LENGTH];
	decl target_list[MAXPLAYERS], target_count, bool:tn_is_ml;

	new targetClient;

	if ((target_count = ProcessTargetString(arg,Client,target_list,MAXPLAYERS,COMMAND_FILTER,target_name,sizeof(target_name),tn_is_ml)) > 0)
	{
		for (new i = 0; i < target_count; i++)
		{
			targetClient = target_list[i];
			Qhs[targetClient] += StringToInt(arg2);
		}
		if (GetConVarInt(GiveAnnonce))
		{
			if(StrEqual(arg, "@all", false)) arg = "所有玩家";
			if(StrEqual(arg, "@humans", false)) arg = "所有幸存者";
			if(StrEqual(arg, "@alive", false)) arg = "所有活着的玩家";
			if(StrEqual(arg, "@dead", false)) arg = "所有死亡的玩家";
			CPrintToChatAllEx(Client, MSG_ADMIN_GIVE_QHSD, arg, StringToInt(arg2));
		}
	}
	else
	{
		ReplyToTargetError(Client, target_count);
	}
	return Plugin_Handled;
}

public Action:Command_GiveBH(Client, args)
{
	if (args < 1)
	{
		ReplyToCommand(Client, "[SM] 用法: sm_givehz  <#userid|name> [数量]");
		return Plugin_Handled;
	}

	decl String:arg[MAX_NAME_LENGTH], String:arg2[64];
	GetCmdArg(1, arg, sizeof(arg));

	if (args > 1)
	{
		GetCmdArg(2, arg2, sizeof(arg2));
	}
	decl String:target_name[MAX_TARGET_LENGTH];
	decl target_list[MAXPLAYERS], target_count, bool:tn_is_ml;

	new targetClient;

	if ((target_count = ProcessTargetString(arg,Client,target_list,MAXPLAYERS,COMMAND_FILTER,target_name,sizeof(target_name),tn_is_ml)) > 0)
	{
		for (new i = 0; i < target_count; i++)
		{
			targetClient = target_list[i];
			Eqbox[targetClient] += StringToInt(arg2);
		}
		if (GetConVarInt(GiveAnnonce))
		{
			if(StrEqual(arg, "@all", false)) arg = "所有玩家";
			if(StrEqual(arg, "@humans", false)) arg = "所有幸存者";
			if(StrEqual(arg, "@alive", false)) arg = "所有活着的玩家";
			if(StrEqual(arg, "@dead", false)) arg = "所有死亡的玩家";
			CPrintToChatAllEx(Client, MSG_ADMIN_GIVE_QJBHE, arg, StringToInt(arg2));
		}
	}
	else
	{
		ReplyToTargetError(Client, target_count);
	}
	return Plugin_Handled;
}

public Action:Command_GiveXZ(Client, args)
{
	if (args < 1)
	{
		ReplyToCommand(Client, "[SM] 用法: sm_givexz  <#userid|name> [数量]");
		return Plugin_Handled;
	}

	decl String:arg[MAX_NAME_LENGTH], String:arg2[64];
	GetCmdArg(1, arg, sizeof(arg));

	if (args > 1)
	{
		GetCmdArg(2, arg2, sizeof(arg2));
	}
	decl String:target_name[MAX_TARGET_LENGTH];
	decl target_list[MAXPLAYERS], target_count, bool:tn_is_ml;

	new targetClient;

	if ((target_count = ProcessTargetString(arg,Client,target_list,MAXPLAYERS,COMMAND_FILTER,target_name,sizeof(target_name),tn_is_ml)) > 0)
	{
		for (new i = 0; i < target_count; i++)
		{
			targetClient = target_list[i];
			Lyxz[targetClient] += StringToInt(arg2);
		}
		if (GetConVarInt(GiveAnnonce))
		{
			if(StrEqual(arg, "@all", false)) arg = "所有玩家";
			if(StrEqual(arg, "@humans", false)) arg = "所有幸存者";
			if(StrEqual(arg, "@alive", false)) arg = "所有活着的玩家";
			if(StrEqual(arg, "@dead", false)) arg = "所有死亡的玩家";
			CPrintToChatAllEx(Client, MSG_ADMIN_GIVE_LYXZ, arg, StringToInt(arg2));
		}
	}
	else
	{
		ReplyToTargetError(Client, target_count);
	}
	return Plugin_Handled;
}

public Action:Command_GiveExp(Client, args)
{
	if (args < 1)
	{
		ReplyToCommand(Client, "[SM] 用法: sm_givebj  <#userid|name> [数量]");
		return Plugin_Handled;
	}

	decl String:arg[MAX_NAME_LENGTH], String:arg2[64];
	GetCmdArg(1, arg, sizeof(arg));

	if (args > 1)
	{
		GetCmdArg(2, arg2, sizeof(arg2));
	}
	decl String:target_name[MAX_TARGET_LENGTH];
	decl target_list[MAXPLAYERS], target_count, bool:tn_is_ml;

	new targetClient;

	if ((target_count = ProcessTargetString(arg,Client,target_list,MAXPLAYERS,COMMAND_FILTER,target_name,sizeof(target_name),tn_is_ml)) > 0)
	{
		for (new i = 0; i < target_count; i++)
		{
			targetClient = target_list[i];
			XB[targetClient] += StringToInt(arg2);
		}
		if (GetConVarInt(GiveAnnonce))
		{
			if(StrEqual(arg, "@all", false)) arg = "所有玩家";
			if(StrEqual(arg, "@humans", false)) arg = "所有幸存者";
			if(StrEqual(arg, "@alive", false)) arg = "所有活着的玩家";
			if(StrEqual(arg, "@dead", false)) arg = "所有死亡的玩家";
			CPrintToChatAllEx(Client, MSG_ADMIN_GIVE_EXP, arg, StringToInt(arg2));
		}
	}
	else
	{
		ReplyToTargetError(Client, target_count);
	}
	return Plugin_Handled;
}
public Action:Command_GiveLevel(Client, args)
{
	if (args < 1)
	{
		ReplyToCommand(Client, "[SM] 用法: sm_givelv <#userid|name> [数量]");
		return Plugin_Handled;
	}

	decl String:arg[MAX_NAME_LENGTH], String:arg2[64];
	GetCmdArg(1, arg, sizeof(arg));

	if (args > 1)
	{
		GetCmdArg(2, arg2, sizeof(arg2));
	}
	decl String:target_name[MAX_TARGET_LENGTH];
	decl target_list[MAXPLAYERS], target_count, bool:tn_is_ml;

	new targetClient;

	if ((target_count = ProcessTargetString(arg,Client,target_list,MAXPLAYERS,COMMAND_FILTER,target_name,sizeof(target_name),tn_is_ml)) > 0)
	{
		for (new i = 0; i < target_count; i++)
		{
			targetClient = target_list[i];
			Lv[targetClient] += StringToInt(arg2);
			StatusPoint[targetClient] += GetConVarInt(LvUpSP)*StringToInt(arg2);
			SkillPoint[targetClient] += GetConVarInt(LvUpKSP)*StringToInt(arg2);
		}
		if (GetConVarInt(GiveAnnonce))
		{
			if(StrEqual(arg, "@all", false)) arg = "所有玩家";
			if(StrEqual(arg, "@humans", false)) arg = "所有幸存者";
			if(StrEqual(arg, "@alive", false)) arg = "所有活着的玩家";
			if(StrEqual(arg, "@dead", false)) arg = "所有死亡的玩家";
			CPrintToChatAllEx(Client, MSG_ADMIN_GIVE_LV, arg, StringToInt(arg2));
		}
	}
	else
	{
		ReplyToTargetError(Client, target_count);
	}
	return Plugin_Handled;
}

public Action:Command_GiveCash(Client, args)
{
	if (args < 1)
	{
		ReplyToCommand(Client, "[SM] 用法: sm_giveexp  <#userid|name> [数量]");
		return Plugin_Handled;
	}

	decl String:arg[MAX_NAME_LENGTH], String:arg2[64];
	GetCmdArg(1, arg, sizeof(arg));

	if (args > 1)
	{
		GetCmdArg(2, arg2, sizeof(arg2));
	}
	decl String:target_name[MAX_TARGET_LENGTH];
	decl target_list[MAXPLAYERS], target_count, bool:tn_is_ml;

	new targetClient;
	if ((target_count = ProcessTargetString(arg,Client,target_list,MAXPLAYERS,COMMAND_FILTER,target_name,sizeof(target_name),tn_is_ml)) > 0)
	{
		for (new i = 0; i < target_count; i++)
		{
			targetClient = target_list[i];
			XC[targetClient] += StringToInt(arg2);
		}
		if (GetConVarInt(GiveAnnonce))
		{
			if(StrEqual(arg, "@all", false)) arg = "所有玩家";
			if(StrEqual(arg, "@humans", false)) arg = "所有幸存者";
			if(StrEqual(arg, "@alive", false)) arg = "所有活着的玩家";
			if(StrEqual(arg, "@dead", false)) arg = "所有死亡的玩家";
			CPrintToChatAllEx(Client, MSG_ADMIN_GIVE_CASH, arg, StringToInt(arg2));
		}
	}
	else
	{
		ReplyToTargetError(Client, target_count);
	}
	return Plugin_Handled;
}

public Action:Command_FullMP(Client, args)
{
	MP[Client] = MaxMP[Client];
	return Plugin_Handled;
}

public Action:Command_GiveKT(Client, args)
{
	if (args < 1)
	{
		ReplyToCommand(Client, "[SM] 用法: sm_givenl  <#userid|name> [数量]");
		return Plugin_Handled;
	}

	decl String:arg[MAX_NAME_LENGTH], String:arg2[64];
	GetCmdArg(1, arg, sizeof(arg));

	if (args > 1)
	{
		GetCmdArg(2, arg2, sizeof(arg2));
	}
	decl String:target_name[MAX_TARGET_LENGTH];
	decl target_list[MAXPLAYERS], target_count, bool:tn_is_ml;

	new targetClient;

	if ((target_count = ProcessTargetString(arg,Client,target_list,MAXPLAYERS,COMMAND_FILTER,target_name,sizeof(target_name),tn_is_ml)) > 0)
	{
		for (new i = 0; i < target_count; i++)
		{
			targetClient = target_list[i];
			NewLifeCount[targetClient] += StringToInt(arg2);
		}
		if (GetConVarInt(GiveAnnonce))
		{
			if(StrEqual(arg, "@all", false)) arg = "所有玩家";
			if(StrEqual(arg, "@humans", false)) arg = "所有幸存者";
			if(StrEqual(arg, "@alive", false)) arg = "所有活着的玩家";
			if(StrEqual(arg, "@dead", false)) arg = "所有死亡的玩家";
			CPrintToChatAllEx(Client, MSG_ADMIN_GIVE_KT, arg, StringToInt(arg2));
		}
	}
	else
	{
		ReplyToTargetError(Client, target_count);
	}
	return Plugin_Handled;
}

public Action:Command_RpTest(Client, args)
{
	if (args < 1)
	{
		ReplyToCommand(Client, "[SM] 用法: sm_rptest 编号(%d~%d)", diceNumMin, diceNumMax);
		return Plugin_Handled;
	}

	decl String:arg[4];
	GetCmdArg(1, arg, sizeof(arg));
	
	if(StringToInt(arg) > diceNumMax || StringToInt(arg) < diceNumMin)
	{
		ReplyToCommand(Client, "[SM] 用法: sm_rptest 编号(%d~%d)", diceNumMin, diceNumMax);
		return Plugin_Handled;
	}
	
	AdminDiceNum[Client] = StringToInt(arg);
	UseLotteryFunc(Client);
	return Plugin_Handled;
}