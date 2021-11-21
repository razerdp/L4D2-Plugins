/************************************************************************
*	Vip功能
************************************************************************/

//投票变量
new vote_type;
new String:vote_mapname[64];
new String:vote_mapinfo[32];
new vip_chose[MAXPLAYERS+1];
new vote_timeout;
new vote_target;

//回蓝使用变量
new bool:UseHFMP[MAXPLAYERS+3];


/* VIP主面板 */
public Action:MenuFunc_VIP(Client)
{
	new Handle:menu = CreatePanel();
	decl String:line[256];
	VipIsOver(Client);
	new viplimit = CheckVipTimeLimit(Client);
	if (VIP[Client] <= 0)
		Format(line, sizeof(line), "你的身份: 普通VIP");
	else if (VIP[Client] == 1)
		Format(line, sizeof(line), "你的身份: 白银VIP1 剩余:%d天", viplimit);
	else if (VIP[Client] == 2)
		Format(line, sizeof(line), "你的身份: 黄金VIP2 剩余:%d天", viplimit);
	else if (VIP[Client] == 3)
		Format(line, sizeof(line), "你的身份: 水晶VIP3 剩余:%d天", viplimit);
	else if (VIP[Client] == 4)
		Format(line, sizeof(line), "你的身份: 至尊VIP4 剩余:%d天", viplimit);
	else if (VIP[Client] == 5)
		Format(line, sizeof(line), "你的身份: 创世VIP5 剩余:%d天", viplimit);
	else if (VIP[Client] == 6)
		Format(line, sizeof(line), "你的身份: 末日VIP6 剩余:%d天", viplimit);	
	SetPanelTitle(menu, line);

	DrawPanelItem(menu, "会员功能介绍");
	DrawPanelItem(menu, "购买会员方法");
	DrawPanelItem(menu, "会员免费补给(O键)");
	DrawPanelItem(menu, "会员投票菜单(P键)");
	DrawPanelItem(menu, "会员传送补给");	
	DrawPanelItem(menu, "会员专属商店");	
	
	DrawPanelItem(menu, "返回");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIP, MENU_TIME_FOREVER);
	CloseHandle(menu);
	return Plugin_Handled;
}
public MenuHandler_VIP(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1: MenuFunc_VIPInfo(Client); //VIP功能介绍
			case 2: MenuFunc_VIPBuy(Client); //VIP购买方法
			case 3: MenuFunc_VIPFunction(Client); //使用VIP功能
			case 4: MenuFunc_VIPVote(Client); //VIP投票菜单
			case 5: MenuFunc_Teleport(Client);//VIP传送补给			
			case 6: {PrintToChat(Client,"会员专属商店暂不开放");}
		}
	}
}
//VIP功能介绍
public Action:MenuFunc_VIPInfo(Client)
{
	new Handle:menu = CreatePanel();
	decl String:line[256];
	if (VIP[Client] <= 0)
		Format(line, sizeof(line), "你的身份: 普通VIP");
	else if (VIP[Client] == 1)
		Format(line, sizeof(line), "你的身份: 白银VIP1");
	else if (VIP[Client] == 2)
		Format(line, sizeof(line), "你的身份: 黄金VIP2");
	else if (VIP[Client] == 3)
		Format(line, sizeof(line), "你的身份: 水晶VIP3");
	else if (VIP[Client] == 4)
		Format(line, sizeof(line), "你的身份: 至尊VIP4");
	else if (VIP[Client] == 5)		
		Format(line, sizeof(line), "你的身份: 创世VIP5");
	else if (VIP[Client] == 6)
		Format(line, sizeof(line), "你的身份: 末日VIP6");
	SetPanelTitle(menu, line);

	DrawPanelItem(menu, "白金VIP1");
	DrawPanelItem(menu, "黄金VIP2");
	DrawPanelItem(menu, "水晶VIP3");
	DrawPanelItem(menu, "至尊VIP4");
	DrawPanelItem(menu, "创世VIP5");
	DrawPanelItem(menu, "末日VIP6");
	
	DrawPanelItem(menu, "返回");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPInfo, MENU_TIME_FOREVER);
	CloseHandle(menu);
	return Plugin_Handled;
}
public MenuHandler_VIPInfo(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1: MenuFunc_VIPAInfo(Client); //白金VIP1介绍
			case 2: MenuFunc_VIPBInfo(Client); //黄金VIP2介绍
			case 3: MenuFunc_VIPCInfo(Client); //水晶VIP3介绍
			case 4: MenuFunc_VIPDInfo(Client); //至尊VIP4介绍
			case 5: MenuFunc_VIPDInfo(Client); //创世VIP5介绍			
			case 6: MenuFunc_VIPDInfo(Client); //末日VIP6介绍
			case 7: MenuFunc_VIP(Client); //返回VIP主面板
		}
	}
}
		
//白银会员介绍
public Action:MenuFunc_VIPAInfo(Client)
{
	new Handle:menu = CreatePanel();
	decl String:line[256];
	
	Format(line, sizeof(line), "治疗术提升为高级治疗术,拥有50％的经验加成 \n倒地死亡经验减少50％ \n商店有9打折优惠 \n免费补给4个 装备:白银勋章 \n拥有投票踢人和个性绿色字体颜色白色光晕轮廓.");
	DrawPanelText(menu, line);
	
	DrawPanelItem(menu, "返回");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPAInfo, MENU_TIME_FOREVER);
	CloseHandle(menu);
	return Plugin_Handled;
}
public MenuHandler_VIPAInfo(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1: MenuFunc_VIPInfo(Client); //返回VIP主面板
		}
	}
}

//黄金会员介绍
public Action:MenuFunc_VIPBInfo(Client)
{
	new Handle:menu = CreatePanel();
	decl String:line[256];
	
	Format(line, sizeof(line), "治疗术提升为高级治疗术,拥有80％的经验加成 \n倒地死亡经验减少60％ \n商店有8打折优惠 \n免费补给8个 装备:黄金勋章 \n拥有投票踢人,换图和橄榄色个性字体颜色黄色光晕轮廓.");
	DrawPanelText(menu, line);
	
	DrawPanelItem(menu, "返回");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPBInfo, MENU_TIME_FOREVER);
	CloseHandle(menu);
	return Plugin_Handled;
}
public MenuHandler_VIPBInfo(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1: MenuFunc_VIPInfo(Client); //返回VIP主面板
		}
	}
}

//水晶会员介绍
public Action:MenuFunc_VIPCInfo(Client)
{
	new Handle:menu = CreatePanel();
	decl String:line[256];
	
	Format(line, sizeof(line), "治疗术提升为高级治疗术,拥有100％的经验加成 \n倒地死亡经验减少80％ \n商店有7打折优惠 \n免费补给12个 装备:水晶勋章(-30%火伤) \n拥有投票踢人,换图和个性蓝色字体颜色绿色光晕轮廓.");
	DrawPanelText(menu, line);
	
	DrawPanelItem(menu, "返回");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPBInfo, MENU_TIME_FOREVER);
	CloseHandle(menu);
	return Plugin_Handled;
}
public MenuHandler_VIPCInfo(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1: MenuFunc_VIPInfo(Client); //返回VIP主面板
		}
	}
}

//至尊会员介绍
public Action:MenuFunc_VIPDInfo(Client)
{
	new Handle:menu = CreatePanel();
	decl String:line[256];
	
	Format(line, sizeof(line), "治疗术提升为高级治疗术,拥有150％的经验加成 \n倒地死亡经验减少90％ \n商店有6打折优惠 \n免费补给16个 装备:至尊勋章(-40%火伤) \n拥有投票踢人,换图和个性字体颜色紫色光晕轮廓.");
	DrawPanelText(menu, line);
	
	DrawPanelItem(menu, "返回");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPBInfo, MENU_TIME_FOREVER);
	CloseHandle(menu);
	return Plugin_Handled;
}
public MenuHandler_VIPDInfo(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1: MenuFunc_VIPInfo(Client); //返回VIP主面板
		}
	}
}

//创世会员介绍
public Action:MenuFunc_VIPEInfo(Client)
{
	new Handle:menu = CreatePanel();
	decl String:line[256];
	
	Format(line, sizeof(line), "治疗术提升为高级治疗术,拥有180％的经验加成 \n倒地死亡经验减少95％ \n商店有5打折优惠 \n免费补给18个 论坛版主专用 \n拥有投票踢人,换图和个性字体颜色紫色光晕轮廓.");
	DrawPanelText(menu, line);
	
	DrawPanelItem(menu, "返回");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPBInfo, MENU_TIME_FOREVER);
	CloseHandle(menu);
	return Plugin_Handled;
}
public MenuHandler_VIPEInfo(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1: MenuFunc_VIPInfo(Client); //返回VIP主面板
		}
	}
}

//末日会员介绍
public Action:MenuFunc_VIPFInfo(Client)
{
	new Handle:menu = CreatePanel();
	decl String:line[256];
	
	Format(line, sizeof(line), "治疗术提升为高级治疗术,拥有200％的经验加成 \n倒地死亡经验减少100％ \n商店有4打折优惠 \n免费补给20个 管理员尊用 \n拥有投票踢人,换图和个性字体颜色紫色光晕轮廓.");
	DrawPanelText(menu, line);
	
	DrawPanelItem(menu, "返回");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPBInfo, MENU_TIME_FOREVER);
	CloseHandle(menu);
	return Plugin_Handled;
}
public MenuHandler_VIPFInfo(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1: MenuFunc_VIPInfo(Client); //返回VIP主面板
		}
	}
}

//VIP购买方法
public Action:MenuFunc_VIPBuy(Client)
{
	new Handle:menu = CreatePanel();
	decl String:line[256];
	if (VIP[Client] <= 0)
		Format(line, sizeof(line), "你的身份: 普通VIP");
	else if (VIP[Client] == 1)
		Format(line, sizeof(line), "你的身份: 白银VIP1");
	else if (VIP[Client] == 2)
		Format(line, sizeof(line), "你的身份: 黄金VIP2");
	else if (VIP[Client] == 3)
		Format(line, sizeof(line), "你的身份: 水晶VIP3");
	else if (VIP[Client] == 4)
		Format(line, sizeof(line), "你的身份: 至尊VIP4");	
	else if (VIP[Client] == 5)
		Format(line, sizeof(line), "你的身份: 创世VIP5");
	else if (VIP[Client] == 6)
		Format(line, sizeof(line), "你的身份: 末日VIP6");	
	SetPanelTitle(menu, line);

	//Format(line, sizeof(line), "需要会员请前往商店购买");
	//DrawPanelText(menu, line);
	
	DrawPanelItem(menu, "返回");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPBuy, MENU_TIME_FOREVER);
	CloseHandle(menu);
	return Plugin_Handled;
}
public MenuHandler_VIPBuy(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1: MenuFunc_VIP(Client); //返回VIP主面板
		}
	}
}

//使用VIP功能
public Action:Command_VIP(Client,args)
{
	MenuFunc_VIPFunction(Client);
	return Plugin_Handled;
}

public Action:Command_VIPVote(Client,args)
{
	MenuFunc_VIPVote(Client);
	return Plugin_Handled;
}

public Action:MenuFunc_VIPFunction(Client)
{
	new Handle:menu = CreateMenu(MenuHandler_VIPFunction);
	decl String:line[256];
	VipIsOver(Client);
	new viplimit = CheckVipTimeLimit(Client);
	if (VIP[Client] <= 0)
		Format(line, sizeof(line), "你的身份: 普通VIP \n你不是高级会员,无法领取免费补给.");
	else if (VIP[Client] == 1)
		Format(line, sizeof(line), "你的身份: 白银VIP1 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);
	else if (VIP[Client] == 2)
		Format(line, sizeof(line), "你的身份: 黄金VIP2 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);
	else if (VIP[Client] == 3)
		Format(line, sizeof(line), "你的身份: 水晶VIP3 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);
	else if (VIP[Client] == 4)
		Format(line, sizeof(line), "你的身份: 至尊VIP4 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);
	else if (VIP[Client] == 5)
		Format(line, sizeof(line), "你的身份: 创世VIP5 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);
	else if (VIP[Client] == 6)
		Format(line, sizeof(line), "你的身份: 末日VIP6 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);		
	SetMenuTitle(menu, line);

	AddMenuItem(menu, "item0", "武器补给菜单");
	/*
	AddMenuItem(menu, "item1", "传送补给菜单");	
	*/
	Format(line, sizeof(line), "瞬间满血(剩余:%d)", vip_item[Client]);
	AddMenuItem(menu, "item1", line);	
	
	Format(line, sizeof(line), "瞬间满蓝(剩余:%d)", vip_item[Client]);
	if (!UseHFMP[Client])
		AddMenuItem(menu, "item2", line);
	else
		AddMenuItem(menu, "item2", line, ITEMDRAW_DISABLED);

	/*
	Format(line, sizeof(line), "获得医疗包(剩余:%d)", vip_item[Client]);
	AddMenuItem(menu, "item4", line);
	
	Format(line, sizeof(line), "获得电击器(剩余:%d)", vip_item[Client]);
	AddMenuItem(menu, "item5", line);
	*/
	
	Format(line, sizeof(line), "获得肾上腺素(剩余:%d)", vip_item[Client]);
	AddMenuItem(menu, "item3", line);
	
	Format(line, sizeof(line), "获得止痛药丸(剩余:%d)", vip_item[Client]);
	AddMenuItem(menu, "item4", line);
	
	Format(line, sizeof(line), "获得燃烧瓶(剩余:%d)", vip_item[Client]);
	AddMenuItem(menu, "item5", line);
	
	Format(line, sizeof(line), "获得胆汁瓶(剩余:%d)", vip_item[Client]);
	AddMenuItem(menu, "item6", line);
	
	Format(line, sizeof(line), "获得土制炸弹(剩余:%d)", vip_item[Client]);
	AddMenuItem(menu, "item7", line);
	
	Format(line, sizeof(line), "获得得氧气瓶(剩余:%d)", vip_item[Client]);
	AddMenuItem(menu, "item8", line);

	
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
	return Plugin_Handled;
}

public MenuHandler_VIPFunction(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param == MenuCancel_ExitBack)
			MenuFunc_VIP(Client);
	}
	if(action == MenuAction_Select)
	{
		if (!IsPlayerAlive(Client) || GetClientTeam(Client) != 2)
		{
			PrintToChat(Client, "补给获取失败,因为你死亡了或你不是幸存者!");
			return;
		}
		if (param != 0)
		{
			if (vip_item[Client] >= 1)
				vip_item[Client] -= 1;
			else
			{
				PrintHintText(Client, "你在本回合的免费补给已经领取完了,请到下回合在领取!");
				MenuFunc_VIPFunction(Client);
				return;
			}
		}
		switch(param)
		{
			case 0: MenuFunc_VIPFunction_Weapon(Client); //获得武器
			//case 1: MenuFunc_Teleport(Client); //玩家传送
			case 1: CheatCommand(Client, "give", "health"), CPrintToChatAll("\x03[Vip会员]%N{olive}使用\x03补给瞬间满血\x03直接回满了生命(倒地自起).", Client); //瞬间满血
			case 2: 
			{
				if (!UseHFMP[Client])//瞬间满蓝
				{
					UseHFMP[Client] = true;
					MP[Client] = MaxMP[Client];
					CPrintToChatAll("\x03[Vip会员]\x03%N{olive}使用补给\x03瞬间满蓝{olive}直接回满了MP值.", Client);
				}
			}
			case 3: CheatCommand(Client, "give", "adrenaline"), CPrintToChatAll("\x03[Vip会员]\x03}%N{olive}使用补给获得了\x03肾上腺素", Client); //获得肾上腺素
			/*
			case 5: CheatCommand(Client, "give", "defibrillator"), CPrintToChatAll("{olive}[Vip会员]{lightgreen}%N{olive}使用补给获得了{lightgreen}电击器", Client); //获得电击器
			case 6: CheatCommand(Client, "give", "adrenaline"), CPrintToChatAll("{olive}[Vip会员]{lightgreen}%N{olive}使用补给获得了{lightgreen}肾上腺素", Client); //获得肾上腺素
			*/
			case 4: CheatCommand(Client, "give", "pain_pills"), CPrintToChatAll("\x03[Vip会员]\x03%N{olive}使用补给获得了\x03止痛药丸", Client); //获得痛药丸
			case 5: CheatCommand(Client, "give", "molotov"), CPrintToChatAll("\x03[Vip会员]\x03%N{olive}使用补给获得了\x03燃烧瓶", Client); //获得燃烧瓶
			case 6: CheatCommand(Client, "give", "vomitjar"), CPrintToChatAll("\x03[Vip会员]\x03%N{olive}使用补给获得了\x03胆汁液", Client); //获得胆汁瓶
			case 7: CheatCommand(Client, "give", "pipe_bomb"), CPrintToChatAll("\x03[Vip会员\x03%N{olive}使用补给获得了\x03土制炸弹", Client); //获得土制炸弹
			case 8: CheatCommand(Client, "give", "oxygentank"), CPrintToChatAll("\x03[Vip会员\x03%N{olive}使用补给获得了\x03氧气瓶", Client); //获得氧气瓶
		}
		
		if (param != 0)
			MenuFunc_VIPFunction(Client);
	}

}

//使用VIP功能_获得武器
public Action:MenuFunc_VIPFunction_Weapon(Client)
{
	new Handle:menu = CreateMenu(MenuHandler_VIPFunction_Weapon);
	decl String:line[256];
	VipIsOver(Client);
	new viplimit = CheckVipTimeLimit(Client);
	if (VIP[Client] <= 0)
		Format(line, sizeof(line), "你的身份: 普通VIP \n你不是高级会员,无法领取免费补给.");
	else if (VIP[Client] == 1)
		Format(line, sizeof(line), "你的身份: 白银VIP1 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);
	else if (VIP[Client] == 2)
		Format(line, sizeof(line), "你的身份: 黄金VIP2 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);
	else if (VIP[Client] == 3)
		Format(line, sizeof(line), "你的身份: 水晶VIP3 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);
	else if (VIP[Client] == 4)
		Format(line, sizeof(line), "你的身份: 至尊VIP4 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);	
	else if (VIP[Client] == 5)
		Format(line, sizeof(line), "你的身份: 创世VIP5 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);	
	else if (VIP[Client] == 6)
		Format(line, sizeof(line), "你的身份: 末日VIP6 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);	
	SetMenuTitle(menu, line);

	
	Format(line, sizeof(line), "获得武士刀(剩余:%d)", vip_item[Client]);
	AddMenuItem(menu, "item0", line);
	
	Format(line, sizeof(line), "获得斩马刀(剩余:%d)", vip_item[Client]);
	AddMenuItem(menu, "item1", line);
	
	Format(line, sizeof(line), "获得燃烧弹(剩余:%d)", vip_item[Client]);
	AddMenuItem(menu, "item7", line);
	
	Format(line, sizeof(line), "获得高爆弹(剩余:%d)", vip_item[Client]);
	AddMenuItem(menu, "item8", line);
	
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	

	return Plugin_Handled;
}

public MenuHandler_VIPFunction_Weapon(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param == MenuCancel_ExitBack)
			MenuFunc_VIPFunction(Client);
	}
	if(action == MenuAction_Select)
	{
		if (!IsPlayerAlive(Client) || GetClientTeam(Client) != 2)
		{
			PrintToChat(Client, "补给获取失败,因为你死亡了或你不是幸存者!");
			return;
		}
		if (vip_item[Client] >= 1)
			vip_item[Client] -= 1;
		else
		{
			PrintHintText(Client, "温馨提示：你在本回合的免费补给已经领取完了,请到下回合在领取!")
			MenuFunc_VIPFunction_Weapon(Client);
			return;
		}
			
		switch(param)
		{
			case 0: CheatCommand(Client, "give", "katana"), CPrintToChatAll("\x03[Vip会员]\x03%N{olive}使用补给获得了\x03武士刀", Client); //获得武士刀
			case 1: CheatCommand(Client, "give", "machete"), CPrintToChatAll("\x03[Vip会员]\x03%N{olive}使用补给获得了\x03斩马刀", Client); //获得斩马刀
			case 2: CheatCommand(Client, "upgrade_add", "Incendiary_ammo"), CPrintToChatAll("\x03[Vip会员]\x03%N{olive}使用补给获得了\x03燃烧弹", Client); //获得燃烧弹
			case 3: CheatCommand(Client, "upgrade_add", "explosive_ammo"), CPrintToChatAll("\x03[Vip会员]\x03%N{olive}使用补给获得了\x03高爆弹", Client); //获得高爆弹
		}
	}
}

//使用VIP功能_玩家传送
public Action:MenuFunc_Teleport(Client)
{
	new Handle:menu = CreatePanel();
	decl String:line[256];
	VipIsOver(Client);
	new viplimit = CheckVipTimeLimit(Client);
	if (VIP[Client] <= 0)
		Format(line, sizeof(line), "你的身份: 普通VIP \n你不是高级会员,无法领取免费补给.");
	else if (VIP[Client] == 1)
		Format(line, sizeof(line), "你的身份: 白银VIP1 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);
	else if (VIP[Client] == 2)
		Format(line, sizeof(line), "你的身份: 黄金VIP2 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);
	else if (VIP[Client] == 3)
		Format(line, sizeof(line), "你的身份: 水晶VIP3 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);
	else if (VIP[Client] == 4)
		Format(line, sizeof(line), "你的身份: 创世VIP5 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);	
	else if (VIP[Client] == 4)
		Format(line, sizeof(line), "你的身份: 末日VIP6 剩余:%d天 \n本回合还可以免费领取补给(%d)个", viplimit, vip_item[Client]);	
	SetPanelTitle(menu, line);

	
	Format(line, sizeof(line), "传送到某玩家处(剩余:%d)", vip_item[Client]);
	DrawPanelItem(menu, line);
	
	Format(line, sizeof(line), "某玩家传送到本人处(剩余:%d)", vip_item[Client]);
	DrawPanelItem(menu, line);
	
	Format(line, sizeof(line), "传送到准心位置(剩余:%d)", vip_item[Client]);
	DrawPanelItem(menu, line);	
	
	DrawPanelItem(menu, "返回");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_Teleport, MENU_TIME_FOREVER);
	CloseHandle(menu);
	return Plugin_Handled;
}

public MenuHandler_Teleport(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		if (!IsPlayerAlive(Client) || GetClientTeam(Client) != 2)
		{
			PrintToChat(Client, "补给获取失败,因为你死亡了或你不是幸存者!");
			return;
		}
		if (vip_item[Client] <= 0)
		{
			PrintHintText(Client, "温馨提示：你在本回合的免费补给已经领取完了,请到下回合在领取!")
			MenuFunc_Teleport(Client)
			return;
		}
		
		if (param == 3)
		{
			if (vip_item[Client] >= 1)
				vip_item[Client] -= 1;
		}
		
		switch(param)
		{
			case 1: MenuFunc_TeleportChose(Client, 0); //传送到某玩家处
			case 2: MenuFunc_TeleportChose(Client, 1); //某玩家传送到本人处
			case 3: Vip_Teleport(Client, Client, 2); //传送到鼠标位置
			case 4: MenuFunc_VIP(Client); //返回
		}
		
	}
}

//使用VIP功能_玩家传送_传送类型
public Action:MenuFunc_TeleportChose(Client, type)
{
	new Handle:menu = CreateMenu(MenuHandler_TeleportChose);
	decl String:line[256], String:id[12];
	if (type == 0)
		Format(line, sizeof(line), "传送到某玩家处:");
	else if (type == 1)
		Format(line, sizeof(line), "某玩家传送到本人处:");

	SetMenuTitle(menu, line);

	for (new i = 1; i <= MaxClients; i++)
	{
		if (IsValidPlayer(i) && GetClientTeam(i) == 2)
		{
			if (IsPlayerAlive(i))
			{
				Format(line, sizeof(line), "生还: %N", i);
				Format(id, sizeof(id), "%d", i);
				AddMenuItem(menu, id, line);
			}			
			else
			{
				Format(line, sizeof(line), "死亡: %N", i);
				Format(id, sizeof(id), "%d", i);
				AddMenuItem(menu, id, line, ITEMDRAW_DISABLED);			
			}
		}
	}

	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
	return Plugin_Handled;
}

public MenuHandler_TeleportChose(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param == MenuCancel_ExitBack)
			MenuFunc_Teleport(Client);
	}
	else if (action == MenuAction_Select)
	{
		if (vip_item[Client] <= 0)
		{
			PrintHintText(Client, "你在本回合的免费补给已经领取完了,请到下回合在领取!")
			MenuFunc_Teleport(Client)
			return;
		}
		
		decl String:info[32], String:title[32];
		new userid, target, type;
		
		GetMenuTitle(menu, title, sizeof(title));
		GetMenuItem(menu, param, info, sizeof(info));
		if (StrEqual(title, "传送到某玩家处:", false))
			type = 0;
		else if (StrEqual(title, "某玩家传送到本人处:", false))
			type = 1;
		else 
			return;
		
		userid = StringToInt(info);
		target = userid;		
		if (IsValidPlayer(target) && IsValidEntity(target))
			Vip_Teleport(Client, target, type), vip_item[Client] -= 1;
		else
			PrintHintText(Client, "无效的目标!");
	}
}

//传送玩家子程序
public Vip_Teleport(Client, target, type)
{
	new Float:pos[3];
	new Float:t_pos[3];
	new Float:m_pos[3];
	if (IsValidPlayer(Client) && IsValidPlayer(target))
	{
		GetEntPropVector(Client, Prop_Send, "m_vecOrigin", pos);
		GetEntPropVector(target, Prop_Send, "m_vecOrigin", t_pos);
		if (type == 0)
		{
			TeleportEntity(Client, t_pos, NULL_VECTOR, NULL_VECTOR);
			MenuFunc_Teleport(Client);
			CPrintToChatAll("\x03[Vip会员]\x03%N{olive}使用传送补给,传送到了\x03%N{olive}的位置.", Client, target);
		}
		else if (type == 1)
		{
			TeleportEntity(target, pos, NULL_VECTOR, NULL_VECTOR)
			MenuFunc_Teleport(Client);
			CPrintToChatAll("\x03[Vip会员]\x03%N{olive}使用传送补给,将\x03%N{olive}传送到了自己的位置.", Client, target);
		}
		else if (type == 2)
		{
			GetTracePosition(Client, m_pos);
			TeleportEntity(Client, m_pos, NULL_VECTOR, NULL_VECTOR);
			MenuFunc_Teleport(Client);
			CPrintToChatAll("\x03[Vip会员]\x03%N{olive}使用传送补给,传送到了他准心的位置.", Client, target);
		}
			
	}
}

//重置VIP免费补给
public ReSetVipProps(Client)
{
	if (IsValidPlayer(Client) && !IsFakeClient(Client))
	{
		new vipA = GetConVarInt(cv_vippropsA);
		new vipB = GetConVarInt(cv_vippropsB);
		new vipC = GetConVarInt(cv_vippropsC);
		new vipD = GetConVarInt(cv_vippropsD);
		new vipE = GetConVarInt(cv_vippropsE);
		new vipF = GetConVarInt(cv_vippropsF);
		if (VIP[Client] <= 0)
			vip_item[Client] = 0;
		else if (VIP[Client] == 1 && VIPNameCheck(Client))
		{
			if (vipA > 0)
				vip_item[Client] = vipA, UseHFMP[Client] = false, GetClientName(Client, VipName[Client], sizeof(VipName));
				
		}
		else if (VIP[Client] == 2 && VIPNameCheck(Client))
		{
			if (vipB > 0)
				vip_item[Client] = vipB, UseHFMP[Client] = false, GetClientName(Client, VipName[Client], sizeof(VipName));
		}
		else if (VIP[Client] == 3 && VIPNameCheck(Client))
		{
			if (vipC > 0)
				vip_item[Client] = vipC, UseHFMP[Client] = false, GetClientName(Client, VipName[Client], sizeof(VipName));
		}
		else if (VIP[Client] == 4 && VIPNameCheck(Client))
		{
			if (vipD > 0)
				vip_item[Client] = vipD, UseHFMP[Client] = false, GetClientName(Client, VipName[Client], sizeof(VipName));
		}
		else if (VIP[Client] == 5 && VIPNameCheck(Client))
		{
			if (vipE > 0)
				vip_item[Client] = vipE, UseHFMP[Client] = false, GetClientName(Client, VipName[Client], sizeof(VipName));
		}
		else if (VIP[Client] == 6 && VIPNameCheck(Client))
		{
			if (vipF > 0)
				vip_item[Client] = vipF, UseHFMP[Client] = false, GetClientName(Client, VipName[Client], sizeof(VipName));
		}
	}
}

/* VIP加成功能(经验金钱加成 type = 1, 商店物品打折 type = 2) */
public VIPAdd(Client, data, type, bool:exp)
{
	if(!IsValidPlayer(Client) || data <= 0)
		return 0;
	
	new Value = 0;
	
	if (type == 1)
	{	
		if (VIP[Client] == 1)
			Value = RoundToNearest(data * 0.5);
		else if (VIP[Client] == 2)
			Value = RoundToNearest(data * 0.8);
		else if (VIP[Client] == 3)
			Value = RoundToNearest(data * 1.0);
		else if (VIP[Client] == 4)
			Value = RoundToNearest(data * 1.5);	
		else if (VIP[Client] == 5)
			Value = RoundToNearest(data * 1.8);	
		else if (VIP[Client] == 6)
			Value = RoundToNearest(data * 2.0);	
		else
			return 0;
			
		if (exp)
		{
			if(GetConVarInt(cv_vipexp) <= 0)
				return 0;
			CPrintToChat(Client, "\x03[VIP会员]\x05VIP会员经验获得总额\x03%d(原来:%d+加成:%d)", Value + data, data, Value);
		}
		else
		{
			if(GetConVarInt(cv_vipcash) <= 0)
				return 0;
			CPrintToChat(Client, "\x03[VIP会员]\x05VIP会员金钱获得总额\x03%d(原来:%d+加成:%d)", Value + data, data, Value);
		}
	}
	else if (type == 2)
	{
		if(GetConVarInt(cv_vipbuy) <= 0)
			return data;
			
		if (VIP[Client] == 1)
			Value = RoundToNearest(data * 0.9);
		else if (VIP[Client] == 2)
			Value = RoundToNearest(data * 0.8);
		else if (VIP[Client] == 3)
			Value = RoundToNearest(data * 0.7);
		else if (VIP[Client] == 4)
			Value = RoundToNearest(data * 0.6);
		else if (VIP[Client] == 5)
			Value = RoundToNearest(data * 0.5);
		else if (VIP[Client] == 6)
			Value = RoundToNearest(data * 0.4);			
		else
			return data;
		
		CPrintToChat(Client, "\x03[VIP会员]VIP会员商店优惠后价格\x05(原价:%d 打折后:%d)", data, Value);
	}
	
	return Value;
}

//会员名字检查,防止刷补给
public bool:VIPNameCheck(Client)
{
	if(!IsValidPlayer(Client) || IsFakeClient(Client))
		return false;
	new String:name[MAX_NAME_LENGTH];
	GetClientName(Client, name, sizeof(name));
	for(new i = 1; i <= MaxClients; i++)
	{	
		if (StrEqual(VipName[i], name))
			return false;		
	}
	return true;
}

//设置VIP光晕轮廓
public SetVipGrow(Client)
{
	if (VIP[Client] > 0)
	{
		if (VIP[Client] == 1)
			PerformGlow(Client, 3, 0, 255, 255, 255);
		else if (VIP[Client] == 2)
			PerformGlow(Client, 3, 0, 240, 255, 80);
		else if (VIP[Client] == 3)
			PerformGlow(Client, 3, 0, 85, 240, 130);
		else if (VIP[Client] == 4)
			PerformGlow(Client, 3, 0, 220, 20, 60);
		else if (VIP[Client] == 5)
			PerformGlow(Client, 3, 0, 75, 0, 130);
		else if (VIP[Client] == 6)
			PerformGlow(Client, 3, 0, 255, 0, 255);			
	}
}


//使用VIP功能_投票菜单
public Action:MenuFunc_VIPVote(Client)
{
	new Handle:menu = CreatePanel();
	decl String:line[256];
	VipIsOver(Client);
	new viplimit = CheckVipTimeLimit(Client);
	if (VIP[Client] == 0)
		Format(line, sizeof(line), "你的身份: 普通VIP");
	else if (VIP[Client] == 1)
		Format(line, sizeof(line), "你的身份: 白银VIP1 剩余:%d天", viplimit);
	else if (VIP[Client] == 2)
		Format(line, sizeof(line), "你的身份: 黄金VIP2 剩余:%d天", viplimit);
	else if (VIP[Client] == 3)
		Format(line, sizeof(line), "你的身份: 水晶VIP3 剩余:%d天", viplimit);
	else if (VIP[Client] == 4)
		Format(line, sizeof(line), "你的身份: 至尊VIP4 剩余:%d天", viplimit);	
	else if (VIP[Client] == 5)
		Format(line, sizeof(line), "你的身份: 创世VIP5 剩余:%d天", viplimit);	
	else if (VIP[Client] == 6)
		Format(line, sizeof(line), "你的身份: 末日VIP6 剩余:%d天", viplimit);	
	SetPanelTitle(menu, line);

	if (VIP[Client] == 1 || VIP[Client] == 2 || VIP[Client] == 3 || VIP[Client] == 4 || VIP[Client] == 5 || VIP[Client] == 6)
		DrawPanelItem(menu, "[可用]投票踢人");
	else
		DrawPanelItem(menu, "[不可用]投票踢人");
		
	if (VIP[Client] == 2 || VIP[Client] == 3 || VIP[Client] == 4 || VIP[Client] == 5 || VIP[Client] == 6)
		DrawPanelItem(menu, "[可用]投票换图");
	else
		DrawPanelItem(menu, "[不可用]投票换图");
		
	DrawPanelItem(menu, "返回");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPVote, MENU_TIME_FOREVER);
	CloseHandle(menu);
	return Plugin_Handled;
}

public MenuHandler_VIPVote(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{	
		if (vote_type != 0)
		{
			CPrintToChat(Client, "\x03现在有投票正在进行中,请稍后再试!");
			return;
		}
			
		switch(param)
		{
			case 1:
			{
				if (VIP[Client] == 1 || VIP[Client] == 2 || VIP[Client] == 3 || VIP[Client] == 4 || VIP[Client] == 5 || VIP[Client] == 6)
					MenuFunc_VIPKick(Client); //VIP投票踢人
				else
					CPrintToChat(Client, "\x03你的会员权限不足,\x05无法使用该功能!");
			}
			case 2:
			{
				if (VIP[Client] == 2 || VIP[Client] == 3 || VIP[Client] == 4 || VIP[Client] == 5 || VIP[Client] == 6)
					MenuFunc_VIPMap(Client); //VIP投票换图
				else
					CPrintToChat(Client, "\x03你的会员权限不足,\x05无法使用该功能!");
			}
			case 3: MenuFunc_VIP(Client); //返回VIP主面板
		}

	}
}


//使用VIP功能_投票菜单_投票换图
public Action:MenuFunc_VIPMap(Client)
{
	new Handle:menu = CreateMenu(MenuHandler_VIPMap);
	decl String:line[256];
	if (VIP[Client] == 0)
		Format(line, sizeof(line), "你的身份: 普通VIP");
	else if (VIP[Client] == 1)
		Format(line, sizeof(line), "你的身份: 白银VIP1");
	else if (VIP[Client] == 2)
		Format(line, sizeof(line), "你的身份: 黄金VIP2");
	else if (VIP[Client] == 3)
		Format(line, sizeof(line), "你的身份: 水晶VIP3");
	else if (VIP[Client] == 4)
		Format(line, sizeof(line), "你的身份: 至尊VIP4");
	else if (VIP[Client] == 5)
		Format(line, sizeof(line), "你的身份: 创世VIP5");
	else if (VIP[Client] == 6)
		Format(line, sizeof(line), "你的身份: 末日VIP6");		
	SetMenuTitle(menu, line);
	AddMenuItem(menu, "c1m1_hotel", "[第一关]死亡中心(Dead Center)(旅馆)");
	AddMenuItem(menu, "c1m2_streets", "[第一关]死亡中心(Dead Center)(街道)");
	AddMenuItem(menu, "c1m3_mall", "[第一关]死亡中心(Dead Center)(购物中心)");
	AddMenuItem(menu, "c1m4_atrium", "[第一关]死亡中心(Dead Center)(中庭)");
	AddMenuItem(menu, "c2m1_highway", "[第二关]黑色狂欢夜(Dark Carnivale)(公路)");
	AddMenuItem(menu, "c2m2_fairgrounds", "[第二关]黑色狂欢夜(Dark Carnivale)(游乐场)");
	AddMenuItem(menu, "c2m3_coaster", "[第二关]黑色狂欢夜(Dark Carnivale)(过山车)");
	AddMenuItem(menu, "c2m4_barns", "[第二关]黑色狂欢夜(Dark Carnivale)(谷仓)");
	AddMenuItem(menu, "c2m5_concert", "[第二关]黑色狂欢夜(Dark Carnivale)(音乐会)");
	AddMenuItem(menu, "c3m1_plankcountry", "[第三关]沼泽激战(Swamp Fevere)(村庄)");
	AddMenuItem(menu, "c3m2_swamp", "[第三关]沼泽激战(Swamp Fevere)(沼泽)");
	AddMenuItem(menu, "c3m3_shantytown", "[第三关]沼泽激战(Swamp Fevere)(贫民窟)");
	AddMenuItem(menu, "c3m4_plantation", "[第三关]沼泽激战(Swamp Fevere)(种植园)");
	AddMenuItem(menu, "c4m1_milltown_a", "[第四关]暴风骤雨(Hard Raine(密尔城))");
	AddMenuItem(menu, "c4m2_sugarmill_a", "[第四关]暴风骤雨(Hard Raine)(糖工厂)");
	AddMenuItem(menu, "c4m3_sugarmill_b", "[第四关]暴风骤雨(Hard Raine)(逃离工厂)");
	AddMenuItem(menu, "c4m4_milltown_b", "[第四关]暴风骤雨(Hard Raine)(重返城镇)");
	AddMenuItem(menu, "c4m5_milltown_escape", "[第四关]暴风骤雨(Hard Raine)(逃离城镇)");
	AddMenuItem(menu, "c5m1_waterfront", "[第五关]教区(The Parishe)(岸边)");
	AddMenuItem(menu, "c5m2_park", "[第五关]教区(The Parishe)(公园)");
	AddMenuItem(menu, "c5m3_cemetery", "[第五关]教区(The Parishe)(墓地)");
	AddMenuItem(menu, "c5m4_quarter", "[第五关]教区(The Parishe)(特区)");
	AddMenuItem(menu, "c5m5_bridge", "[第五关]教区(The Parishe)(桥)");
	AddMenuItem(menu, "c6m1_riverbank", "[第六关]消逝(The Passinge)(公园)");
	AddMenuItem(menu, "c6m2_bedlam", "[第六关]消逝(The Passinge)(下水道)");
	AddMenuItem(menu, "c6m3_port", "[第六关]消逝(The Passinge)(桥的另一端)");
	AddMenuItem(menu, "c7m1_docks", "[第七关]牺牲(The Sacrifice)(码头)");
	AddMenuItem(menu, "c7m2_barge", "[第七关]牺牲(The Sacrifice)(驳船)");
	AddMenuItem(menu, "c7m3_port", "[第七关]牺牲(The Sacrifice)(桥的一端)");
	AddMenuItem(menu, "c8m1_apartment", "[第八关]毫不留情(No Mercy)(公寓)");
	AddMenuItem(menu, "c8m2_subway", "[第八关]毫不留情(No Mercy)(地下铁)");
	AddMenuItem(menu, "c8m3_sewers", "[第八关]毫不留情(No Mercy)(下水道)");
	AddMenuItem(menu, "c8m4_interior", "[第八关]毫不留情(No Mercy)(医院)");
	AddMenuItem(menu, "c8m5_rooftop", "[第八关]毫不留情(No Mercy)(屋顶)");
	AddMenuItem(menu, "c9m1_alleys", "[第九关]坠机险途(Crash Course)");
	AddMenuItem(menu, "c9m2_lots", "[第九关]坠机险途(Crash Course)");
	AddMenuItem(menu, "c10m1_caves", "[第十关]死亡丧钟(Death Toll)(隧道)");
	AddMenuItem(menu, "c10m2_drainage", "[第十关]死亡丧钟(Death Toll)(下水道)");
	AddMenuItem(menu, "c10m3_ranchhouse", "[第十关]死亡丧钟(Death Toll)(教堂)");
	AddMenuItem(menu, "c10m4_mainstreet", "[第十关]死亡丧钟(Death Toll)(主要街道)");
	AddMenuItem(menu, "c10m5_houseboat", "[第十关]死亡丧钟(Death Toll)(船屋)");
	AddMenuItem(menu, "c11m1_greenhouse", "[第十一关]静寂时分(Blood Harvest)(温室)");
	AddMenuItem(menu, "c11m2_offices", "[第十一关]静寂时分(Blood Harvest)(办公区)");
	AddMenuItem(menu, "c11m3_garage", "[第十一关]静寂时分(Blood Harvest)(车库)");
	AddMenuItem(menu, "c11m4_terminal", "[第十一关]静寂时分(Blood Harvest)(机场)");
	AddMenuItem(menu, "c11m5_runway", "[第十一关]静寂时分(Blood Harvest)(跑道)");
	AddMenuItem(menu, "c12m1_hilltop", "[第十二关]血腥收获(Dead Air)(山顶)"); 
	AddMenuItem(menu, "c12m2_traintunnel", "[第十二关]血腥收获(Dead Air)(火车隧道)"); 
	AddMenuItem(menu, "c12m3_bridge", "[第十二关]血腥收获(Dead Air)(桥)"); 
	AddMenuItem(menu, "c12m4_barn", "[第十二关]血腥收获(Dead Air)(谷仓)"); 
	AddMenuItem(menu, "c12m5_cornfield", "[第十二关]血腥收获(Dead Air)(农舍)"); 
	AddMenuItem(menu, "c13m1_alpinecreek", "[第十三关]冷流(Cold Stream)");

	
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
	return Plugin_Handled;
}

public MenuHandler_VIPMap(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param == MenuCancel_ExitBack)
			MenuFunc_VIPVote(Client);
	}
	else if (action == MenuAction_Select)
	{
		decl String:info[32], String:mapname[64], String:C_Map[128], style;
		GetCurrentMap(C_Map, sizeof(C_Map));
		GetMenuItem(menu, param, info, sizeof(info), style, mapname, sizeof(mapname));
		if (StrEqual(C_Map, info, false))
		{
			PrintHintText(Client, "不可以更换与当前地图相同的地图!");
			Vip_VoteReSet();
			return;
		}
		strcopy(vote_mapname, sizeof(vote_mapname), mapname);
		strcopy(vote_mapinfo, sizeof(vote_mapinfo), info);
		vote_type = 2;
		CreateTimer(1.0, Timer_Voting, Client, TIMER_REPEAT);
	}
}

//使用VIP功能_投票菜单_投票踢人
public Action:MenuFunc_VIPKick(Client)
{
	new Handle:menu = CreateMenu(MenuHandler_VIPKick);
	decl String:line[256];
	if (VIP[Client] == 0)
		Format(line, sizeof(line), "你的身份: 普通VIP");
	else if (VIP[Client] == 1)
		Format(line, sizeof(line), "你的身份: 白银VIP1");
	else if (VIP[Client] == 2)
		Format(line, sizeof(line), "你的身份: 黄金VIP2");
	else if (VIP[Client] == 3)
		Format(line, sizeof(line), "你的身份: 水晶VIP3");
	else if (VIP[Client] == 4)
		Format(line, sizeof(line), "你的身份: 至尊VIP4");
	else if (VIP[Client] == 5)
		Format(line, sizeof(line), "你的身份: 创世VIP5");
	else if (VIP[Client] == 4)
		Format(line, sizeof(line), "你的身份: 末日VIP6");	
	SetMenuTitle(menu, line);

	AddTargetsToMenu2(menu, Client, COMMAND_FILTER);
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
	return Plugin_Handled;
}

public MenuHandler_VIPKick(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param == MenuCancel_ExitBack)
			MenuFunc_VIPVote(Client);
	}
	else if (action == MenuAction_Select)
	{
		decl String:info[32];
		new userid, target;

		vote_type = 1;
		GetMenuItem(menu, param, info, sizeof(info));
		userid = StringToInt(info);
		target = GetClientOfUserId(userid);
		if (VIP[target] >= 3)
		{
			PrintHintText(Client, "无法踢出VIP3以上玩家!");
			Vip_VoteReSet();
			return;
		}
		vote_target = target;
		CreateTimer(1.0, Timer_Voting, Client, TIMER_REPEAT);
	}
}

//使用VIP功能_投票菜单_投票选择
public Action:MenuFunc_VoteChose(Client)
{
	new Handle:menu = CreatePanel();
	decl String:line[256];
	if (vote_type == 1)
		Format(line, sizeof(line), "玩家 %N 建议投票踢出 %N, 你的选择是?", Client, vote_target);
	else if (vote_type == 2)
		Format(line, sizeof(line), "玩家 %N 建议地图更换为 %s, 你的选择是?", Client, vote_mapname);
	else
		return Plugin_Handled;
		
	SetPanelTitle(menu, line);

	DrawPanelItem(menu, "同意");
	DrawPanelItem(menu, "反对");
	for (new i = 1; i <= MaxClients; i++)
	{
		if (!IsValidPlayer(i) || IsFakeClient(i) || vip_chose[i] == 1 || vip_chose[i] == 2)
			continue;
			
		SendPanelToClient(menu, i, MenuHandler_VoteChose, MENU_TIME_FOREVER);
	}
	
	return Plugin_Handled;
}

public MenuHandler_VoteChose(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select)
	{
		if (vote_type > 0)
		{
			switch(param)
			{
				case 1: vip_chose[Client] = 1, CPrintToChatAll("\x03[投票]{red}%N{olive}选择了同意.", Client);
				case 2: vip_chose[Client] = 2, CPrintToChatAll("\x03[投票]{red}%N{olive}选择了反对.", Client);		
			}
		}
	}
}

//投票计时器
public Action:Timer_Voting(Handle:timer, any:Client)
{
	new yes;
	new no;
	new over;
	new all;

	if (vote_type == 1)
	{
		if (!IsValidPlayer(vote_target))
		{
			Vip_VoteReSet();
			CPrintToChatAll("\x03由于被投票踢出的玩家已经退出游戏,\x03投票中止!");
			return Plugin_Stop;
		}
	}
	
	for (new i = 1; i <= MaxClients; i++)
	{
		if (!IsValidPlayer(i) || IsFakeClient(i))
			continue;
			
		all++;
		
		if (vip_chose[i] == 1)
			yes++;
		else if (vip_chose[i] == 2)
			no++;
		else
			MenuFunc_VoteChose(Client);
	}
	
	over = all - yes - no;
	vote_timeout++;
	
	PrintHintTextToAll("当前投票的票数统计(剩余时间:%d): 未投票数: %d/%d \n同意: %d/%d \n反对:%d/%d", 20 - vote_timeout, over, all, yes, all, no, all);
	
	if (vote_timeout >= 20)
	{
		no += over;
		over = 0;
		if (yes > no)
		{
			if (vote_type == 1)
				PrintHintTextToAll("投票同意票数最高,踢出%N", vote_target), KickClient(vote_target, "你已被投票踢出!");
			else if (vote_type == 2)
			{
				PrintHintTextToAll("投票同意票数最高,更改地图为%s", vote_mapname);
				ForceChangeLevel(vote_mapinfo, "vote");
				SaveServerTimeLog(true);
			}
		}
		else if (no > yes)
		{
			if (vote_type == 1)
				PrintHintTextToAll("投票反对票数最高,未踢出%N", vote_target);
			else if (vote_type == 2)
				PrintHintTextToAll("投票反对票数最高,停止更改地图");		
		}
		else
		{
			if (vote_type == 1)
				PrintHintTextToAll("投票票数相同,未踢出%N", vote_target);
			else if (vote_type == 2)
				PrintHintTextToAll("投票票数相同,停止更改地图");			
		}	
		
		Vip_VoteReSet();
		return Plugin_Stop;
	}
	else if (yes + no >= all)
	{
		if (yes > no)
		{
			if (vote_type == 1)
				PrintHintTextToAll("投票同意票数最高,踢出%N", vote_target), KickClient(vote_target, "你已被投票踢出!");
			else if (vote_type == 2)
			{
				PrintHintTextToAll("投票同意票数最高,更改地图为%s", vote_mapname);
				ForceChangeLevel(vote_mapinfo, "vote");
				SaveServerTimeLog(true);
			}
		}
		else if (no > yes)
		{
			if (vote_type == 1)
				PrintHintTextToAll("投票反对票数最高,未踢出%N", vote_target);
			else if (vote_type == 2)
				PrintHintTextToAll("投票反对票数最高,停止更改地图");		
		}
		else
		{
			if (vote_type == 1)
				PrintHintTextToAll("投票票数相同,未踢出%N", vote_target);
			else if (vote_type == 2)
				PrintHintTextToAll("投票票数相同,停止更改地图");			
		}	
		
		Vip_VoteReSet();
		return Plugin_Stop;
	}
	
	return Plugin_Continue;
}

//投票数据重置
public Vip_VoteReSet()
{
	vote_type = 0;
	vote_target = 0;
	vote_timeout = 0;
	Format(vote_mapname, sizeof(vote_mapname), "");
	Format(vote_mapinfo, sizeof(vote_mapinfo), "");
	for (new i = 1; i <= MaxClients; i++)
	{
		vip_chose[i] = 0;
	}
}

/* VIP通道_初始人数设置 */
public SetPlayerLimit()
{
	if (cv_MaxPlayer != INVALID_HANDLE)
	{
		ServerPlayerLimit = GetConVarInt(cv_MaxPlayer);
		SetConVarInt(cv_MaxPlayer, ServerPlayerLimit + 1);
	}
}

/* VIP通道_还原人数设置 */
public ResetPlayerLimit()
{
	if (cv_MaxPlayer != INVALID_HANDLE)
		SetConVarInt(cv_MaxPlayer, ServerPlayerLimit);
}

/* VIP通道_会员进入 */
public VipPlayerConnect(Client)
{
	if (!IsFakeClient(Client))
	{
		if (GetAllConnectedCount() > ServerPlayerLimit)
		{
			if (VIP[Client] >= 1)
				KickNotVipPlayer();
			else
			{
				CPrintToChatAll("\x03[公告]由于\x03%N\x03占用了Vip会员通道,已经被服务器踢出!", Client);
				KickClient(Client, "此通道为VIP专用通道");
			}
		}
	}
}

/* VIP通道_踢出玩家 */
public KickNotVipPlayer()
{
	new Handle:hasmm = CreateArray(1, 0);
	new Handle:notmm = CreateArray(1, 0);
	for(new i = 1; i <= MaxClients; i++)
	{
		if (!IsValidPlayer(i) || IsFakeClient(i) || VIP[i] >= 1)
			continue;
			
		if (IsPasswordConfirm[i])
			PushArrayCell(hasmm, i);
		else
			PushArrayCell(notmm, i);
	}
	
	if (GetArraySize(notmm) > 1)
	{
		new target = GetArrayCell(notmm, GetRandomInt(0, GetArraySize(notmm) - 1));
		if (IsValidPlayer(target) && !IsFakeClient(target))
		{
			KickClient(target, "由于你占用了会员通道,已经被服务器踢出");
			CPrintToChatAll("\x03[公告]由于\x03%N\x03占用了Vip会员通道,已经被服务器踢出!", target);		
		}
	}
	else if (GetArraySize(hasmm) >= 1)
	{
		new target = GetArrayCell(hasmm, GetRandomInt(0, GetArraySize(hasmm) - 1));
		if (IsValidPlayer(target) && !IsFakeClient(target))
		{
			KickClient(target, "由于你占用了会员通道,已经被服务器踢出");
			CPrintToChatAll("\x03[公告]由于\x03%N\x03占用了Vip会员通道,已经被服务器踢出!", target);		
		}	
	}
	
}

/* VIP剩余时间检测 */
public CheckVipTimeLimit(Client)
{
	if (VIP[Client] >= 1)
	{
		new year = GetThisYear();
		new today = GetToday();
		new maxday = GetThisYearMaxDay();
		new last;
		if (VIPYEAR[Client] > 0 && VIPTL[Client] > 0)
		{
			if (year == VIPYEAR[Client])
			{
				last = VIPTL[Client] - today;
				if (last > 0)
					return last;
				else
					return 0;
			}
			else if (VIPYEAR[Client] > year)
			{
				new moreyear = VIPYEAR[Client] - year;
				new moreday = maxday - today;
				
				for (new i = 1; i <= moreyear; i++)
					moreday += GetThisYearMaxDay(year + i);
							
				last = moreday + VIPTL[Client];
				
				if (last > 0)
					return last;
				else
					return 0;
			}
			else
				return 0;
		}
	}
	
	return 0;
}

/* VIP到期 */
public VipIsOver(Client)
{
	if (VIP[Client] >= 1)
	{
		new last = CheckVipTimeLimit(Client);
		if (last <= 0)
		{
			if (I_BagSize[Client] > 5)
			{
				if (VIP[Client] == 1)
					I_BagSize[Client] -= 3;
				else if (VIP[Client] == 2)
					I_BagSize[Client] -= 5;
			}
			VIP[Client] = 0;
			VIPTL[Client] = 0;
			VIPYEAR[Client] = 0;
			SetZBItemTime(Client, 1, 0);
			SetZBItemTime(Client, 0, 0);
			
			//by MicroLeo
			if(GetConVarBool(h_ArchiveSys))
			{
				SQLiteArchiveSys_ClientSaveToFileSave(Client,false);
			}
			//end
			else
			{
				ClientSaveToFileSave(Client);
			}
			
			CPrintToChat(Client, "\x03[Vip会员]\x03你的Vip会员已经到期了");
		}
	}
}

//检查服务器当前已连接总人数
stock GetAllConnectedCount(bool:ingame = false, team = 0)
{
	new count = 0;
	for (new i = 1; i <= MaxClients; i++)
	{
		if (IsClientConnected(i) && !IsFakeClient(i))
		{
			if (!ingame)
			{
				if (team == 0)
					count++;
				else if (GetClientTeam(i) == team)
					count++;
			}
			else if (IsClientInGame(i))
			{
				if (team == 0)
					count++;
				else if (GetClientTeam(i) == team)
					count++;
			}
		}
	}
	
	return count;
}

public Action:Timer_CheckMaxPlayer(Handle:timer)
{
	new max = GetAllPlayerCount();
	if (max > ServerPlayerLimit)
		KickNotVipPlayer();		
}

/* 选择玩家菜单 */
public Menu_SetVIPMenu_Select(Client)
{
	viptarget = 0;
	viptype = 0;
	new Handle:menu = CreateMenu(Handler_SetVIPMenu_Select);	
	SetMenuTitle(menu, "设置玩家为VIP:");		
	SetMenuExitBackButton(menu, true);
	AddTargetsToMenu2(menu, Client, COMMAND_FILTER);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);
	
}

public Handler_SetVIPMenu_Select(Handle:menu, MenuAction:action, param1, param2)
{
	if (action == MenuAction_End)
	{
		CloseHandle(menu);
	}
	else if (action == MenuAction_Select)
	{
		decl String:info[32];
		new userid, target;
		GetMenuItem(menu, param2, info, sizeof(info));
		userid = StringToInt(info);
		target = GetClientOfUserId(userid);
		Menu_SetVIPMenu(param1, target)	;
	}
}

/* 选择会员类型菜单 */
public Menu_SetVIPMenu(Client, target)
{
	new Handle:menu = CreateMenu(Handler_SetVIPMenu);
	new String:targetinfo[16];
	SetMenuTitle(menu, "设置玩家为VIP:");
	IntToString(target, targetinfo, sizeof(targetinfo));
	AddMenuItem(menu, targetinfo, "普通VIP");
	AddMenuItem(menu, targetinfo, "白银VIP1");
	AddMenuItem(menu, targetinfo, "黄金VIP2");
	AddMenuItem(menu, targetinfo, "水晶VIP3");
	AddMenuItem(menu, targetinfo, "至尊VIP4");
	AddMenuItem(menu, targetinfo, "创世VIP5");
	AddMenuItem(menu, targetinfo, "末日VIP6");
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
}

public Handler_SetVIPMenu(Handle:menu, MenuAction:action, param1, param2)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Select)
	{
		if (param2 >=0 && param2 <= 6)
		{
			new String:info[16];
			GetMenuItem(menu, param2, info, sizeof(info));
			new target = StringToInt(info);
			viptarget = target;
			viptype = param2;
			Menu_SetVIPTimeMenu(param1);
		}	
	}
}

/* 选择会员类型菜单 */
public Menu_SetVIPTimeMenu(Client)
{
	new Handle:menu = CreateMenu(Handler_SetVIPTimeMenu);
	SetMenuTitle(menu, "设置期限:");

	AddMenuItem(menu, "0", "0");
	AddMenuItem(menu, "1", "1");
	AddMenuItem(menu, "5", "5");
	AddMenuItem(menu, "10", "10");
	AddMenuItem(menu, "15", "15");
	AddMenuItem(menu, "30", "30");
	AddMenuItem(menu, "90", "90");
	AddMenuItem(menu, "180", "180");
	AddMenuItem(menu, "360", "360");
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
}

public Handler_SetVIPTimeMenu(Handle:menu, MenuAction:action, Client, param2)
{
	if (action == MenuAction_End)
	{
		viptarget = 0;
		viptype = 0;
		CloseHandle(menu);
	}
	else if (action == MenuAction_Select)
	{
		new String:info[16];
		GetMenuItem(menu, param2, info, sizeof(info));
		new time = StringToInt(info);
		SetVip(Client, viptarget, viptype, time, false);		
	}
	else
	{
		viptarget = 0;
		viptype = 0;
	}
}

/* 设置VIP */
public SetVip(Client, Target, type, time, bool:isfirst)
{
	if (IsValidPlayer(Target) && !IsFakeClient(Target))
	{
		if (IsPasswordConfirm[Target])
		{
			if (type <= 0)
				CPrintToChatAll("\x03[VIP会员] \x03%N {red}已经被管理员设置为\x03普通VIP {green}期限: \x03%d {green}天 ", Target, time);
			else if (type == 1)
				CPrintToChatAll("\x03[VIP会员] \x03%N {red}已经被管理员设置为\x03白银VIP1 {green}期限: \x03%d {green}天 ", Target, time);
			else if (type == 2)
				CPrintToChatAll("\x03[VIP会员] \x03%N {red}已经被管理员设置为\x03黄金VIP2 {green}期限: \x03%d {green}天 .", Target, time);
			else if (type == 3)
				CPrintToChatAll("\x03[VIP会员] \x03%N {red}已经被管理员设置为\x03水晶VIP3 {green}期限: \x03%d {green}天 ", Target, time);
			else if (type == 4)
				CPrintToChatAll("\x03[VIP会员] \x03%N {red}已经被管理员设置为\x03至尊VIP4 {green}期限: \x03%d {green}天 ", Target, time);	
			else if (type == 5)
				CPrintToChatAll("\x03[VIP会员] \x03%N {red}已经被管理员设置为\x03创世VIP5 {green}期限: \x03%d {green}天 ", Target, time);	
			else if (type == 6)
				CPrintToChatAll("\x03[VIP会员] \x03%N {red}已经被管理员设置为\x03服主VIP6 {green}期限: \x03%d {green}天 ", Target, time);	
			
			if (isfirst)
				SetVipTimeLimit(Target, type, time, true);
			else
				SetVipTimeLimit(Target, type, time);
			ReSetVipProps(Target);
			SetVipGrow(Client);
		}
		else
			ReplyToCommand(Client, "\x03你选择的玩家还没有注册或登录RPG,无法给予VIP会员!");
	}
	else
		ReplyToCommand(Client, "\x03你选择的玩家是无效的!");
		
	viptarget = 0;
	viptype = 0;
}

/* 设置VIP期限 */
stock SetVipTimeLimit(Target, type, time, bool:first = false)
{
	if (type > 0)
	{
		new today = GetToday();
		new maxday = GetThisYearMaxDay();
		new year = GetThisYear();
		VIP[Target] = type;
		if (today > 0 && year > 0 && maxday > 0)
		{
			if (today + time <= maxday)
			{
				VIPYEAR[Target] = year;
				VIPTL[Target] = today + time;
			}
			else
			{
				new moreday = time - maxday;
				new moreyear = year + 1;
				new nextyearmaxday = GetThisYearMaxDay(moreyear);
				
				while (moreday - nextyearmaxday > 0)
				{
					moreday = moreday - nextyearmaxday;
					moreyear += 1;
					nextyearmaxday = GetThisYearMaxDay(moreyear);
				}
				
				if (moreday > 0 && moreyear > 0)
				{
					VIPYEAR[Target] = moreyear;
					VIPTL[Target] = moreday;
					if (first)
						Cash[Target] += 50000;
				}
			}
			
			//by MicroLeo
			if(GetConVarBool(h_ArchiveSys))
			{
				SQLiteArchiveSys_ClientSaveToFileSave(Target,false);
			}
			//end
			else
			{
				ClientSaveToFileSave(Target);
			}
			
		}
	}
}
