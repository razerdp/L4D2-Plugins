/*******************************************************************************************
*								拜师收徒_开始
*******************************************************************************************/
/**********************
*	 基础参数
**********************/
/**********************
*	 师徒主菜单
**********************/

public Action:Menu_SHITU(Client,args)
{
	if (!IsPasswordConfirm[Client])
	{
		CPrintToChat(Client, "\x03[系统] \x04你没登录或注册,请输入密码登录!");
		CPrintToChat(Client, "\x03[系统] \x04输入密码方法: \x01/pw + 空格 +密码!");
		return Plugin_Handled;
	}
	if (IsPasswordConfirm[Client])
	{
		MenuFunc_Master(Client);
	}
	return Plugin_Handled;
}
public Action:MenuFunc_Master(Client)
{
	decl String:line[256];
	new Handle:menu = CreatePanel();
	Format(line, sizeof(line), "======拜师|收徒|称号=====");			
	SetPanelTitle(menu, line);
	DrawPanelText(menu, "初级玩家可以拜高级玩家为师父");	
	DrawPanelText(menu, "高级玩家可以收低级玩家为徒弟");
	DrawPanelText(menu, "作为师父将负担提携新人的责任");
	DrawPanelText(menu, "作为徒弟努力升级将来回报师父");
	DrawPanelText(menu, "====================");
	DrawPanelText(menu, " \n");
	Format(line, sizeof(line), "我要收徒弟");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "我要找师父");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "查看我的师徒");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "查看我的称号");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "拜师收徒帮助");
	DrawPanelItem(menu, line);
	DrawPanelItem(menu, "返回");

	SendPanelToClient(menu, Client, MenuHandler_Master, MENU_TIME_FOREVER);

	CloseHandle(menu);

	return Plugin_Handled;
}

public MenuHandler_Master(Handle:menu, MenuAction:action, Client, itemNum)
{
	if (action == MenuAction_Select) {
		switch (itemNum)
		{
			case 1:
			{
				MenuFunc_XZTDPlayer(Client);
			}	
			case 2:
			{
				MenuFunc_ZXDSFPlayer(Client);
			}	
			case 3:
			{
				MenuFunc_shitu(Client);
			}	
			case 4:
			{
				MenuFunc_Title(Client);
			}	
			case 5:
			{
				MenuFunc_MasterHelp(Client);
			}		
			case 6:
			{
				MenuFunc_RPG(Client);
			}				
		}
	}
}

/**********************
*	 寻找师父菜单
**********************/
public MenuFunc_ZXDSFPlayer(Client)
{
	decl String:line[256], String:name[64], has;
	new Handle:menu = CreateMenu(MenuHandler_ZXDSFPlayer);
	SetMenuTitle(menu, "寻找师父: 达到1转以上符合担任师父的玩家");
	has = 0;
	for (new i = 1; i <= MaxClients; i++)
	{
		if (IsValidPlayer(i, false) && i != Client)
		{
			if (NewLifeCount[i] > 0)//达到1转以上符合担任师父条件的玩家
			{
				has++;
				Format(line, sizeof(line), "%N(%d转 %d级)", i, NewLifeCount[i], Lv[i]);
				GetClientName(i, name, sizeof(name));			
				if (NewLifeCount[i] > 0)
					AddMenuItem(menu, name, line);
			}
		}
	}
	if (has <= 0)
		AddMenuItem(menu, "item1", "没有符合担任你师父的玩家!", ITEMDRAW_DISABLED)
		
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
}

public MenuHandler_ZXDSFPlayer(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param == MenuCancel_ExitBack)
			MenuFunc_Master(Client);
	}
	if(action == MenuAction_Select)
	{
		decl String:name[64], target;
		GetMenuItem(menu, param, name, sizeof(name));
		target = GetClientForName(name);
		if (IsValidPlayer(target, false))
		{
			if(shifuNem[Client] < 1 && tudiNem[target] < 1 && NewLifeCount[Client] < 1)//你的师父<=1，且对方徒弟<=1
			{
				/*  自己保存师父名字 */
				decl String:user_name[MAX_NAME_LENGTH]="";
				GetClientName(target, user_name, sizeof(user_name));//获取对方ID转换为名字给予自己保存
				shifu[Client] = user_name;
				shifuNem[Client] +=1;//自己师父数量+=1
				CPrintToChatAll("{olive}[拜师]\x3玩家\x4%N{olive}拜\x4%N{olive}为师,各位恭喜他吧!", Client,target);
					
				/*  对方保存徒弟名字 */
				decl String:user_name1[MAX_NAME_LENGTH]="";
				GetClientName(Client, user_name1, sizeof(user_name1));//获取自己ID转换为名字给予对方保存
				tudi[target] = user_name1;
				tudiNem[target] +=1;//对方徒弟数量+=1
				
				decl String:text[3][128];
				Format(text[0], sizeof(text[]), "玩家：%N",Client);
				Format(text[1], sizeof(text[]), "已拜你为师!");
				Format(text[2], sizeof(text[]), "师父请受徒儿一拜");
				MenuFunc_VoteChose2(target, "拜师提醒:", text, 3);
			}
			else
			{
				if(shifuNem[Client] > 0)
				{
					CPrintToChat(Client,"{olive}[师徒]\x3你已经有师父了!");
				}	
				if(tudiNem[target] > 0)
				{
					CPrintToChat(Client,"{olive}[师徒]\x3玩家\x4%N\x3已经有徒弟了!", target);
				}
				if(NewLifeCount[Client] > 0)
				{
					CPrintToChat(Client,"{olive}[师徒]\x3你现在的级别已经不需要师父了!");
				}
			}		
		}	
	}
}

/**********************
*	寻找徒弟菜单
**********************/
public MenuFunc_XZTDPlayer(Client)
{
	decl String:line[256], String:name[64], has;
	new Handle:menu = CreateMenu(MenuHandler_XZTDPlayer);
	SetMenuTitle(menu, "寻找徒弟: 低于3转以下符合条件的玩家");
	has = 0;
	for (new i = 3; i <= MaxClients; i++)
	{
		if (IsValidPlayer(i, false) && i != Client)
		{
			if (Lv[i] < 300 && NewLifeCount[i] == 0)//低于300级以下符合条件的玩家
			{
				has++;
				Format(line, sizeof(line), "%N(%d转 %d级)", i, NewLifeCount[i], Lv[i]);
				GetClientName(i, name, sizeof(name));			
				if (Lv[i] < 100 && NewLifeCount[i] == 0)
					AddMenuItem(menu, name, line);
			}
		}
	}
	if (has <= 0)
		AddMenuItem(menu, "item1", "没有符合当你徒弟的玩家!", ITEMDRAW_DISABLED)
		
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
}

public MenuHandler_XZTDPlayer(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param == MenuCancel_ExitBack)
			MenuFunc_Master(Client);
	}
	if(action == MenuAction_Select)
	{
		decl String:name[64], target;
		GetMenuItem(menu, param, name, sizeof(name));
		target = GetClientForName(name);
		if (IsValidPlayer(target, false))
		{
			if(NewLifeCount[Client] > 0)
			{
				if(tudiNem[Client] < 1 && shifuNem[target] < 1)//你的徒弟<=1，且对方师父<=1
				{
					/*  保存徒弟名字 */
					decl String:user_name1[MAX_NAME_LENGTH]="";
					GetClientName(target, user_name1, sizeof(user_name1));//获取对方ID转换为名字给予自己保存
					tudi[Client] = user_name1;
					tudiNem[Client] +=1;//徒弟数量+=1
					CPrintToChatAll("{olive}[收徒]\x3玩家\x4%N{olive}收\x4%N{olive}为徒,各位恭喜他吧!", Client,target);
				
					/*  保存师父名字 */
					decl String:user_name[MAX_NAME_LENGTH]="";
					GetClientName(Client, user_name, sizeof(user_name));//获取自己ID转换为名字给予对方保存
					shifu[target] = user_name;
					shifuNem[target] +=1;//师父数量+=1
				
					decl String:text[3][128];
					Format(text[0], sizeof(text[]), "玩家：%N",Client);
					Format(text[1], sizeof(text[]), "已收你为徒!");
					Format(text[2], sizeof(text[]), "小子快来见过师父");
					MenuFunc_VoteChose2(target, "收徒提醒:", text, 3);
				}
				else
				{
					if(tudiNem[Client] > 0)
					{
						CPrintToChat(Client,"{olive}[师徒]\x3你已经有徒弟了!");
					}	
					if(shifuNem[target] > 0)
					{
						CPrintToChat(Client,"{olive}[师徒]\x3玩家\x4%N\x3已经有师父了!", target);
					}
				}
			}
			else
			{
				CPrintToChat(Client,"{olive}[师徒]\x3收徒失败,你的等级低于1转!");
			}
		}	
	}
}

/* 万用菜单提示 */

public MenuFunc_VoteChose2(target, String:title[], String:text[][], LineNum)
{
	new Handle:menu = CreatePanel();
	SetPanelTitle(menu, title);
	DrawPanelText(menu, " \n");
	//DrawPanelText(menu, "════════════════");
	for (new i; i < LineNum; i++)
		DrawPanelText(menu, text[i]);	
	//DrawPanelText(menu, "════════════════");	
	DrawPanelText(menu, " \n");

	DrawPanelItem(menu, "知道了");
	
	SendPanelToClient(menu, target, MenuHandler_MenuMessage2, MENU_TIME_FOREVER);
	CloseHandle(menu);
}

public MenuHandler_MenuMessage2(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{

	}
}


/**********************
*	查看我的师徒菜单
**********************/
public Action:MenuFunc_shitu(Client)
{
	decl String:line[256];
	new Handle:menu = CreatePanel();
	Format(line, sizeof(line), "查看我的师徒");			
	SetPanelTitle(menu, line);
	DrawPanelText(menu, " \n");
	
	Format(line, sizeof(line), "观察师父");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "查询师父基础资料");
	DrawPanelText(menu, line);
	
	Format(line, sizeof(line), "观察徒弟");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "查询徒弟基础资料");
	DrawPanelText(menu, line);
	
	DrawPanelText(menu, " \n");
	DrawPanelItem(menu, "返回");


	SendPanelToClient(menu, Client, MenuHandler_shitu, MENU_TIME_FOREVER);

	CloseHandle(menu);

	return Plugin_Handled;
}

public MenuHandler_shitu(Handle:menu, MenuAction:action, Client, itemNum)
{
	if (action == MenuAction_Select) {
		switch (itemNum) {
			case 1: MenuFunc_shifu(Client);
			case 2: MenuFunc_tudi(Client);

		}
		if (itemNum != 1 && itemNum != 2)
			MenuFunc_Master(Client);
	}
}
/**********************
*	查看我的师父
**********************/
public Action:MenuFunc_shifu(Client)
{
	decl String:line[256];
	new Handle:menu = CreatePanel();
	Format(line, sizeof(line), "======查看我的师父=====");			
	SetPanelTitle(menu, line);
	
	DrawPanelText(menu, " \n");
	decl target;
	target = GetClientForName(shifu[Client]);//获取师父ID
	if(IsValidPlayer(target))
	{
		shifLv[Client] = Lv[target];
		shifNL[Client] = NewLifeCount[target];
		shifEXP[Client] = EXP[target];
	}
	if(shifuNem[Client] > 0)
	{
		Format(line, sizeof(line), "师父: %s" ,shifu[Client]);
		DrawPanelText(menu, line);
		DrawPanelText(menu, " \n");
		Format(line, sizeof(line), "等级: %d转 %d级" ,shifNL[Client], shifLv[Client]);
		DrawPanelText(menu, line);
		DrawPanelText(menu, " \n");
		Format(line, sizeof(line), "经验: %dExp" ,shifEXP[Client]);
		DrawPanelText(menu, line);
		DrawPanelText(menu, " \n");
		DrawPanelText(menu, "===================");
		DrawPanelText(menu, " \n");
		DrawPanelItem(menu, "申请出师(必须师徒同时在线)")
		DrawPanelItem(menu, "离开师门")
		DrawPanelItem(menu, "返回")
	}
	else
	{
		DrawPanelText(menu, " 你还没有师父");
		DrawPanelText(menu, " \n");
		DrawPanelText(menu, "1.离开");
	}

	SendPanelToClient(menu, Client, MenuHandler_shifu, MENU_TIME_FOREVER);

	CloseHandle(menu);

	return Plugin_Handled;
}

public MenuHandler_shifu(Handle:menu, MenuAction:action, Client, itemNum)
{
	if (action == MenuAction_Select) {
		switch (itemNum) {
			case 1: 
			{
				decl target;
				target = GetClientForName(shifu[Client]);//获取徒弟ID
				if (IsValidPlayer(target))
				{
					if(Lv[Client] == 150 && NewLifeCount[Client] == 0)
					{
						shifuNem[Client] = 0;
						Lv[Client] = 0;
						SetZBItemTime(Client, 99, 5, false);
						NewLifeCount[Client] += 1;
						ClinetResetStatus(Client, Admin);
						SetZBItemTime(target, 99, 5, false);
						tudiNem[target] = 0;
						Cbution[target] += 1;
						ticeship[target] += 1;
						CPrintToChatAll("{olive}[出师]\x3恭喜玩家\x4%N\x3在名师\x4%N\x3门下出师了!", Client, target);
						CPrintToChatAll("{olive}[出师]\x3徒弟\x4%N\x3奖励装备\x4 1 \x3件!", Client);
						CPrintToChatAll("{olive}[出师]\x3师父\x4%N\x3贡献值+ \x4%d点 \x3出师量+ \x4%d名!", target, Cbution[target], ticeship[target]);
					}
					else
					{
						CPrintToChat(Client,"{olive}[师徒]\x3出师失败,小子你太嫩了再去努力修炼吧!");
					}
				}
				else
				{
					CPrintToChat(Client,"{olive}[师徒]\x3出师失败,必须师父同时在线才可以出师!");
				}
			}
			case 2: 
			{
				if(shifuNem[Client] > 0)
				{
					decl target;
					target = GetClientForName(shifu[Client]);//获取师父ID
					if (IsValidPlayer(target))
					{
						shifuNem[Client] = 0;
						tudiNem[target] = 0;
						CPrintToChat(Client,"{olive}[师徒]\x3这个师父太不厚道了,不跟他混了闪人!");
						CPrintToChat(target,"{olive}[师徒]\x3你的徒弟离开师门了!");
					}
					else
					{
						shifuNem[Client] = 0;
						CPrintToChat(Client,"{olive}[师徒]\x3这个师父太不厚道了,不跟他混了闪人!");
					}
				}
			}
		}
		if (itemNum != 1 && itemNum != 2)
			MenuFunc_Master(Client);
	}
}

/**********************
*	查看我的徒弟
**********************/
public Action:MenuFunc_tudi(Client)
{
	decl String:line[256];
	new Handle:menu = CreatePanel();
	Format(line, sizeof(line), "=======查看我的徒弟=======");			
	SetPanelTitle(menu, line);
	
	DrawPanelText(menu, " \n");
	decl target;
	target = GetClientForName(tudi[Client]);//获取徒弟ID
	if(IsValidPlayer(target))
	{
		tudLv[Client] = Lv[target];
		tudNL[Client] = NewLifeCount[target];
		tudEXP[Client] = EXP[target];
	}
	if(tudiNem[Client] > 0)
	{
		Format(line, sizeof(line), "徒弟: %s" ,tudi[Client]);
		DrawPanelText(menu, line);
		DrawPanelText(menu, " \n");
		Format(line, sizeof(line), "等级: %d转 %d级" ,tudNL[Client], tudLv[Client]);
		DrawPanelText(menu, line);
		DrawPanelText(menu, " \n");
		Format(line, sizeof(line), "经验: %dExp" ,tudEXP[Client]);
		DrawPanelText(menu, line);
		DrawPanelText(menu, " \n");
		DrawPanelText(menu, "======================");
		DrawPanelText(menu, " \n");
		DrawPanelItem(menu, "提升徒弟修为(必须师徒同时在线)")
		DrawPanelItem(menu, "解除师徒关系")
		DrawPanelItem(menu, "返回")
	}

	SendPanelToClient(menu, Client, MenuHandler_tudi, MENU_TIME_FOREVER);

	CloseHandle(menu);

	return Plugin_Handled;
}

public MenuHandler_tudi(Handle:menu, MenuAction:action, Client, itemNum)
{
	if (action == MenuAction_Select) 
	{
		switch (itemNum) 
		{
			case 1: 
			{
				decl target;
				target = GetClientForName(tudi[Client]);//获取徒弟ID
				MenuFunc_tudi(Client);
				if (IsValidPlayer(target))
				{
					if(EXP[Client] >= 10000)
					{
						if(Lv[target] <= 150)
						{
							EXP[Client] -= 10000;
							EXP[target] += 4000;
							Cash[Client] += 300;
							CPrintToChat(Client,"{olive}[师徒]\x3传授予\x4徒弟{olive}10000EXP \x4奖励{olive}300$!");
							CPrintToChat(target,"{olive}[师徒]\x3师父\x4给予你{olive}4000EXP!");
						}
						else
							CPrintToChat(Client,"{olive}[师徒]\x3传授失败,徒弟已经可以独自闯荡了!");
					}
					else
						CPrintToChat(Client,"{olive}[师徒]\x3传授失败,你的经验不足了!");
				}
				else
					CPrintToChat(Client,"{olive}[师徒]\x3传授失败,你的徒弟不在线!");
			}
			case 2: 
			{
				if(tudiNem[Client] > 0)
				{
					decl target;
					target = GetClientForName(tudi[Client]);//获取徒弟ID
					if (IsValidPlayer(target))
					{
						tudiNem[Client] = 0;
						shifuNem[target] = 0;
						CPrintToChat(Client,"{olive}[师徒]\x3无法教养这个徒弟了,让它自生自灭吧!");
						CPrintToChat(target,"{olive}[师徒]\x3你的师父把你抛弃了!");
					}	
					else
					{
						tudiNem[Client] = 0;
						CPrintToChat(Client,"{olive}[师徒]\x3无法教养这个徒弟了,让它自生自灭吧!");
					}
				}
			}
		}
		if (itemNum != 1 && itemNum != 2 && itemNum != 3)
			MenuFunc_Master(Client);
	}
}

/**********************
*	 师徒帮助
**********************/
public Action:MenuFunc_MasterHelp(Client)
{
	decl String:line[256];
	new Handle:menu = CreatePanel();
	Format(line, sizeof(line), "拜师收徒帮助:");			
	SetPanelTitle(menu, line);
	DrawPanelText(menu, "低级玩家等级小于150级,可以拜1名玩家为师父.");	
	DrawPanelText(menu, "高级玩家等级大于1转,可以收1名玩家为徒弟.");
	DrawPanelText(menu, " \n");
	DrawPanelText(menu, "拜师收徒福利:");
	DrawPanelText(menu, "师父:师徒共同在线时,徒弟升级师父可获得一定量游戏币,");
	DrawPanelText(menu, "奖励与徒弟等级挂钩(大于1转后无奖励).");
	DrawPanelText(menu, "徒弟:师徒同时在线时,徒弟经验加成20%.");
	DrawPanelText(menu, "出师奖励:等级大于或等于150级可以选择出师");
	DrawPanelText(menu, "徒弟奖励装备1件,师父奖励贡献值(可换装备).");
	DrawPanelText(menu, " \n");
	DrawPanelItem(menu, "知道了");

	SendPanelToClient(menu, Client, MenuHandler_MasterHelp, MENU_TIME_FOREVER);

	CloseHandle(menu);

	return Plugin_Handled;
}

public MenuHandler_MasterHelp(Handle:menu, MenuAction:action, Client, itemNum)
{
	if (action == MenuAction_Select) {
		switch (itemNum)
		{
			case 1:
			{
				MenuFunc_Master(Client);
			}				
		}
	}
}


/**********************
*	 查看称号
**********************/
public Action:MenuFunc_Title(Client)
{
	decl String:line[256];
	new Handle:menu = CreatePanel();
	Format(line, sizeof(line), "====查看我的称号===");			
	SetPanelTitle(menu, line);
	DrawPanelText(menu, " \n");
	
	if(ticeship[Client] >= 1 && ticeship[Client] <= 3)
	{
		DrawPanelText(menu, "目前称号:1");
		Format(line, sizeof(line), "下一个称号还需%d人", 4 - ticeship[Client]);
		DrawPanelText(menu, line);
	}
	if(ticeship[Client] >= 4 && ticeship[Client] <= 6)
	{
		DrawPanelText(menu, "目前称号:2");
		Format(line, sizeof(line), "下一个称号还需%d人", 7 - ticeship[Client]);
		DrawPanelText(menu, line);
	}
	if(ticeship[Client] >= 7 && ticeship[Client] <= 9)
	{
		DrawPanelText(menu, "目前称号:3");
		Format(line, sizeof(line), "下一个称号还需%d人", 10 - ticeship[Client]);
		DrawPanelText(menu, line);
	}
	if(ticeship[Client] >= 10 && ticeship[Client] <= 12)
	{
		DrawPanelText(menu, "目前称号:4");
		Format(line, sizeof(line), "下一个称号还需%d人", 13 - ticeship[Client]);
		DrawPanelText(menu, line);
	}
	if(ticeship[Client] >= 13)
	{
		DrawPanelText(menu, "目前称号:5");
	}
	if(ticeship[Client] < 1)
	{
		DrawPanelText(menu, "目前称号:0");
	}
	DrawPanelText(menu, "===============");
	Format(line, sizeof(line), "已出师的徒弟有%d人", ticeship[Client]);
	DrawPanelText(menu, line);
	DrawPanelText(menu, "===============");
	DrawPanelText(menu, " \n");
	DrawPanelItem(menu, "返回");
	DrawPanelItem(menu, "离开");	
	SendPanelToClient(menu, Client, MenuHandler_Title, MENU_TIME_FOREVER);
}

public MenuHandler_Title(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) 
	{
		switch (param)
		{
			case 1:
			{
				MenuFunc_Master(Client);
			}	
		}	
	}	
}
/**********************
*	 徒弟经验加成
**********************/
public MasterAddEXP(Client, data, type, bool:exp)
{
	decl target;
	target = GetClientForName(shifu[Client]);//获取师父ID
	if(!IsValidPlayer(target) || data <= 0 && Lv[Client] <= 100 && NewLifeCount[Client] == 0)
		return 0;
	
	new Value = 0;
	
	if (type == 1)
	{	
		if (IsValidPlayer(target))
			Value = RoundToNearest(data * 0.20);
		else
			return 0;
			
		if (exp)
		{
			CPrintToChat(Client, "{green}[师徒]{lightgreen}师徒同时在线,经验获得总额{green}%d(默认:%d+加成:%d)", Value + data, data, Value);
		}
	}
	return Value;
}


/*******************************************************************************************
*								拜师收徒_结束
*******************************************************************************************/