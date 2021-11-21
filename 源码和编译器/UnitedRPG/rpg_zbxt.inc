 //装备/商城 
 public Action:MenuFunc_ZBGM(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "布甲/皮甲/重甲");
	SetPanelTitle(menu, line);
	Format(line, sizeof(line), "布甲法伤魔法");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "皮甲敏捷物伤");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "重甲防御物伤");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "狂战之魂套[40000]【永久】");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "万圣节纪念套[45000]【3天后下架】");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回RPG选单");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_ZBGM, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_ZBGM(Handle:menu, MenuAction:action, Client, param)
{
    if (action == MenuAction_Select)
    {
        switch (param)
        {
			case 1: MenuFunc_ZLZB(Client);
			case 2: MenuFunc_WLZB(Client);
			case 3: MenuFunc_FYZB(Client);
			case 4: MenuFunc_KZZHT(Client);
			case 5: MenuFunc_WSJTZ(Client);
			case 6: MenuFunc_RPG(Client);//
		}
	}
}
 
 //布甲法伤装备
public Action:MenuFunc_ZLZB(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "法伤/布甲/装备");
	SetPanelTitle(menu, line);
	Format(line, sizeof(line), "极品项链[31和7天][2000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "紫炎套装[31和7天][4000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "恶魔套装[31和7天][5000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "噩梦套装[31和7天][5000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "龙王头盔[31和7天][6000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "小野护肩[31和7天][9000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "樱花项链[31和7天][6000玄币]");
	DrawPanelItem(menu, line);
	
	DrawPanelItem(menu, "下一页");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_ZLZB, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_ZLZB(Handle:menu, MenuAction:action, Client, param)
{
    if (action == MenuAction_Select)
    {
        switch (param)
        {
			case 1: MenuFunc_JPMLXL(Client);
			case 2: MenuFunc_JPZYTZ(Client);
			case 3: MenuFunc_JPEMTZ(Client);
			case 4: MenuFunc_JPEQTZ(Client);
			case 5: MenuFunc_VIPJPAAA3(Client);
			case 6: MenuFunc_BL2(Client);
			case 7: MenuFunc_YYZ2(Client);
			case 8: MenuFunc_ZLZB1(Client);
		}
	}
}

 //布甲法伤装备
public Action:MenuFunc_ZLZB1(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "法伤/布甲/装备");
	SetPanelTitle(menu, line);
	Format(line, sizeof(line), "死神套装[31和7天][6000玄币]");
	DrawPanelItem(menu, line);
	
	Format(line, sizeof(line), "上一页");
	DrawPanelItem(menu, line);
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_ZLZB1, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_ZLZB1(Handle:menu, MenuAction:action, Client, param)
{
    if (action == MenuAction_Select)
    {
        switch (param)
        {
            case 1: MenuFunc_YYZ4(Client);
			case 8: MenuFunc_ZLZB(Client);
		}
	}
}

/*樱花项链 */
public Action:MenuFunc_YYZ2(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【樱花项链】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:法伤+30000!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[6000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[1500]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_YYZ2, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_YYZ2(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: YHXL(Client);
			case 2: YHGHJ(Client);
			case 3: MenuFunc_ZLZB(Client);
		}
	}
}

public YHXL(Client)//血盾
{
	if(XB[Client] >= 6000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 6000;
		SetZBItemTime(Client, 75, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【樱花项链】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}
public YHGHJ(Client)//血盾
{
	if(XB[Client] >= 1500 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 1500;
		SetZBItemTime(Client, 75, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【樱花项链】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}

/*死神套装 */
public Action:MenuFunc_YYZ4(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【死神套装】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:法伤+20000 速度+25% 治疗+6 防御+20% 生命+100 MP+2w 火焰伤害-50%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[6000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[1500]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_YYZ4, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_YYZ4(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: SSTZ(Client);
			case 2: SS456(Client);
			case 3: MenuFunc_ZLZB(Client);
		}
	}
}
public SSTZ(Client)//血盾
{
	if(XB[Client] >= 6000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 6000;
		SetZBItemTime(Client, 66, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【死神套装】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}

public SS456(Client)//血盾
{
	if(XB[Client] >= 1500 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 1500;
		SetZBItemTime(Client, 66, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【死神套装】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}

/*小野护肩 */
public Action:MenuFunc_BL2(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【小野护肩】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:法伤+50000!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[9000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7天购买[2250]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_BL2, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_BL2(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: BLSZ2(Client);
			case 2: BLZSE(Client);
			case 3: MenuFunc_ZLZB(Client);
		}
	}
}

public BLSZ2(Client)//血盾
{
	if(XB[Client] >= 9000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 9000;
		SetZBItemTime(Client, 106, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【小野护肩】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}
public BLZSE(Client)//血盾
{
	if(XB[Client] >= 2250 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 2250;
		SetZBItemTime(Client, 106, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【小野护肩】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}
/* 龙王头盔 */
public Action:MenuFunc_VIPJPAAA3(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【龙王头盔】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:法伤+20000!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[6000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[1500]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPJPAAA3, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_VIPJPAAA3(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPXLSASR(Client);
			case 2: VIPPOI(Client);
			case 3: MenuFunc_ZLZB(Client);
		}
	}
}

public VIPJPXLSASR(Client)//项链
{
	if(XB[Client] >= 6000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 6000;
		SetZBItemTime(Client, 55, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05购买31天的【龙王头盔】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}
public VIPPOI(Client)//项链
{
	if(XB[Client] >= 1500 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 1500;
		SetZBItemTime(Client, 55, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05购买31天的【龙王头盔】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}

/* 紫炎套装 */
public Action:MenuFunc_JPZYTZ(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【紫炎套装】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:法伤+2万 移+50% 重+20% 攻+1000% 射+25% 治+20 防+40% 生+200火+20%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[4000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[1000]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPZYTZ, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPZYTZ(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPXZSA(Client);
			case 2: VIPZXC(Client);
			case 3: MenuFunc_ZLZB(Client);
		}
	}
}

public VIPJPXZSA(Client)//鞋子
{
	if(XB[Client] >= 4000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 4000;
		SetZBItemTime(Client, 50, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【紫炎套装】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}

public VIPZXC(Client)//鞋子
{
	if(XB[Client] >= 1000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 1000;
		SetZBItemTime(Client, 50, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【紫炎套装】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}

/*恶魔套装 */
public Action:MenuFunc_JPEMTZ(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【恶魔套装】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:法伤+2万 移+55% 重+20% 攻+100% 射+30% 治+30 防+50% 生+200 蓝+2万 火+25%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[5000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[1250]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPEMTZ, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPEMTZ(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPFYSA(Client);
			case 2: VIPASD(Client);
			case 3: MenuFunc_ZLZB(Client);
		}
	}
}

public VIPJPFYSA(Client)//风衣
{
	if(XB[Client] >= 5000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 5000;
		SetZBItemTime(Client, 51, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【恶魔套装】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}
public VIPASD(Client)//风衣
{
	if(XB[Client] >= 1250 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 1250;
		SetZBItemTime(Client, 51, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【恶魔套装】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}

/* 噩梦套装 */
public Action:MenuFunc_JPEQTZ(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【噩梦套装】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:法伤+3万 移+90% 重+30% 攻+500% 射+50% 治+50 防+70% 生+800蓝+3万 火+30%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[5000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[1250]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPEQTZ, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPEQTZ(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPXLSA(Client);
			case 2: VIPQAZ(Client);
			case 3: MenuFunc_ZLZB(Client);
		}
	}
}

public VIPJPXLSA(Client)//项链
{
	if(XB[Client] >= 5000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 5000;
		SetZBItemTime(Client, 53, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【噩梦套装】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}

public VIPQAZ(Client)//项链
{
	if(XB[Client] >= 1250 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 1250;
		SetZBItemTime(Client, 53, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【噩梦套装】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}

/* 极品魔力项链 */
public Action:MenuFunc_JPMLXL(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【极品魔力项链购买】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:法伤+5000!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[2000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[500]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPMLXL, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPMLXL(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPXL(Client);
			case 2: VIP456(Client);
			case 3: MenuFunc_ZLZB(Client);
		}
	}
}

public VIPJPXL(Client)//项链
{
	if(XB[Client] >= 2000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 2000;
		SetZBItemTime(Client, 29, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【极品魔力项链】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}

public VIP456(Client)//项链
{
	if(XB[Client] >= 500 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 500;
		SetZBItemTime(Client, 29, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【极品魔力项链】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_ZLZB(Client)
}

//皮甲敏捷物伤
 public Action:MenuFunc_WLZB(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "敏捷/物理/装备");
	SetPanelTitle(menu, line);
	Format(line, sizeof(line), "极品鬼步靴子[31天][2000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "极品火焰风衣[31和7天][2000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "极品改良弹药[31和7天][2000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "极品改造枪膛[31和7天][2000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "神器の轻盈之躯 [31和7天][3000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "神器の狂暴之躯 [31天][3000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "神器の火凤凰之羽[31天][3000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "下一页");
	DrawPanelItem(menu, line);
	
	DrawPanelItem(menu, "返回RPG选单");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_WLZB, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_WLZB(Handle:menu, MenuAction:action, Client, param)
{
    if (action == MenuAction_Select)
    {
        switch (param)
        {
			case 1: MenuFunc_JPGBXZ(Client);
			case 2: MenuFunc_JPHYFY(Client);
			case 3: MenuFunc_JPGLDY(Client);
			case 4: MenuFunc_JPGZQT(Client);
			case 5: MenuFunc_JPQYZQ(Client);
			case 6: MenuFunc_JPKBZQ(Client);
			case 7: MenuFunc_JPHFHZY(Client);
			case 8: MenuFunc_WLZB1(Client);
            case 9: MenuFunc_RPG(Client);
		}
	}
}

//皮甲敏捷物伤
 public Action:MenuFunc_WLZB1(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "敏捷/物理/装备");
	SetPanelTitle(menu, line);
	Format(line, sizeof(line), "神器の钢铁之躯[31天][3000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "圣翼[31天][5000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "宇翔之翼[31天][1000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "光之翼[31天][2000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "极品治愈戒指[31][2000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "黑暗加农[31天][4000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "龙王套装[31天][8000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "下一页");
	DrawPanelItem(menu, line);
	
	DrawPanelItem(menu, "返回RPG选单");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_WLZB1, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_WLZB1(Handle:menu, MenuAction:action, Client, param)
{
    if (action == MenuAction_Select)
    {
        switch (param)
        {
            case 1: MenuFunc_JPGTZQ(Client);
            case 2: MenuFunc_JPSY(Client);
			case 3: MenuFunc_JPYXZY(Client);
			case 4: MenuFunc_JPGZY(Client);
			case 5: MenuFunc_JPZYJZ(Client);
			case 6: MenuFunc_JPHAJN(Client);
			case 7: MenuFunc_JPLWTZ(Client);
			case 8: MenuFunc_WLZB2(Client);
            case 9: MenuFunc_RPG(Client);
		}
	}
}

//皮甲敏捷物伤
 public Action:MenuFunc_WLZB2(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "敏捷/物理/装备");
	SetPanelTitle(menu, line);
	Format(line, sizeof(line), "无限之光[31天][3500玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "黑暗骑士[31天][4000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "亡灵手杖[31天][4000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "死神舞步[31天][4000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "亡灵护甲[31天][4000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "黑暗之泣[31天][4000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "亡者之力[31天][4000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "下一页");
	DrawPanelItem(menu, line);
	
	DrawPanelItem(menu, "返回RPG选单");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_WLZB2, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_WLZB2(Handle:menu, MenuAction:action, Client, param)
{
    if (action == MenuAction_Select)
    {
        switch (param)
        {
            case 1: MenuFunc_JPWXZG(Client);
			case 2: MenuFunc_VIPJPAAA1(Client);
			case 3: MenuFunc_VIPJPAAA2(Client);
			case 4: MenuFunc_VIPJPAAA4(Client);
			case 5: MenuFunc_VIPJPAAA5(Client);
			case 6: MenuFunc_VIPJPAAA6(Client);
			case 7: MenuFunc_VIPJPAAA7(Client);
			case 8: MenuFunc_WLZB3(Client);
            case 9: MenuFunc_RPG(Client);
		}
	}
}

//皮甲敏捷物伤
 public Action:MenuFunc_WLZB3(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "敏捷/物理/装备");
	SetPanelTitle(menu, line);
	Format(line, sizeof(line), "末世之矛[神][31天][7000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "末世之炎[神][31天][4000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "末世之翼[神][31天][4000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "末世之手[神][31天][7000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "小野鞋子[31天][6000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "小野武器[31天][10000玄币]");
	DrawPanelItem(menu, line);
	
	DrawPanelItem(menu, "返回RPG选单");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_WLZB3, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_WLZB3(Handle:menu, MenuAction:action, Client, param)
{
    if (action == MenuAction_Select)
    {
        switch (param)
        {
            case 1: MenuFunc_VIPBBB3(Client);
			case 2: MenuFunc_VIPBBB4(Client);
			case 3: MenuFunc_VIPBBB5(Client);
			case 4: MenuFunc_VIPBBB6(Client);
			case 5: MenuFunc_BL5(Client);
			case 6: MenuFunc_BL6(Client);
            case 7: MenuFunc_RPG(Client);
		}
	}
}

/*小野鞋子 */
public Action:MenuFunc_BL5(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【小野鞋子】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:速度+60% 跳跃+90%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_BL5, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_BL5(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: BLSZ5(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}

/*小野武器 */
public Action:MenuFunc_BL6(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【小野武器】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:伤害+4000%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_BL6, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_BL6(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: BLSZ6(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}
public BLSZ5(Client)//血盾
{
	if(XB[Client] >= 6000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 6000;
		SetZBItemTime(Client, 109, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【小野鞋子】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public BLSZ6(Client)//血盾
{
	if(XB[Client] >= 10000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 10000;
		SetZBItemTime(Client, 110, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【小野武器】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
/* 极品鬼步鞋子 */
public Action:MenuFunc_JPGBXZ(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【极品鞋子购买】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:速度+90%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPGBXZ, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPGBXZ(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPXZ(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}
/* 极品火焰风衣 */
public Action:MenuFunc_JPHYFY(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【极品火焰风衣购买】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:火炕+80%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[2000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[500]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPHYFY, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPHYFY(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPFY(Client);
			case 2: VIP951(Client);
			case 4: MenuFunc_WLZB(Client);
		}
	}
}
/* 极品改良弹药 */
public Action:MenuFunc_JPGLDY(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【极品改良弹药购买】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:伤害+400%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[2000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[500]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPGLDY, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPGLDY(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPDY(Client);
			case 2: VIPYGV(Client);
			case 3: MenuFunc_WLZB(Client);
		}
	}
}
/* 极品改造枪膛 */
public Action:MenuFunc_JPGZQT(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【极品改造枪膛购买】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:射速+400%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[2000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[500]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPGZQT, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPGZQT(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPQT(Client);
			case 2: QWER(Client);
			case 3: MenuFunc_WLZB(Client);
		}
	}
}
public VIPJPXZ(Client)//鞋子
{
	if(XB[Client] >= 2000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 2000;
		SetZBItemTime(Client, 9, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【极品鬼步靴子】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public VIPJPFY(Client)//风衣
{
	if(XB[Client] >= 2000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 2000;
		SetZBItemTime(Client, 21, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【极品火焰风衣】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public VIP951(Client)//风衣
{
	if(XB[Client] >= 500 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 500;
		SetZBItemTime(Client, 21, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【极品火焰风衣】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public VIPJPDY(Client)//弹药
{
	if(XB[Client] >= 2000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 2000;
		SetZBItemTime(Client, 25, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【极品改良弹药】,当前玄币%d!", XB[Client]);	 CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public VIPYGV(Client)//弹药
{
	if(XB[Client] >= 500 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 500;
		SetZBItemTime(Client, 25, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【极品改良弹药】,当前玄币%d!", XB[Client]);	 CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public VIPJPQT(Client)//枪膛
{
	if(XB[Client] >= 2000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 2000;
		SetZBItemTime(Client, 33, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【极品改造枪膛】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public QWER(Client)//枪膛
{
	if(XB[Client] >= 500 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 500;
		SetZBItemTime(Client, 33, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【极品改造枪膛】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
/* 神器の轻盈之躯 */
public Action:MenuFunc_JPQYZQ(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【神器の轻盈之躯】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:速+50% 跳+20%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[3000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[750]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPQYZQ, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPQYZQ(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPXZS(Client);
			case 2: LKJ4(Client);
			case 3: MenuFunc_WLZB(Client);
		}
	}
}
/* 神器の狂暴之躯 */
public Action:MenuFunc_JPKBZQ(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【神器の狂暴之躯】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:攻+500% 射+25%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPKBZQ, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPKBZQ(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPXDS(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}
/* 神器の火凤凰之羽 */
public Action:MenuFunc_JPHFHZY(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【神器の火凤凰之羽】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:跳跃+30%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPHFHZY, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPHFHZY(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPFYS(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}
/* 神器の钢铁之躯 */
public Action:MenuFunc_JPGTZQ(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【神器の钢铁之躯】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:治+6 防+10% 生+3000!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPGTZQ, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPGTZQ(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPDYS(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}
/* 圣翼 */
public Action:MenuFunc_JPSY(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【圣翼】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:跳跃+50%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPSY, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPSY(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPXLS(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}
/* 宇翔之翼 */
public Action:MenuFunc_JPYXZY(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【宇翔之翼】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:跳跃+20%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPYXZY, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPYXZY(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPQTS(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}
/* 光之翼 */
public Action:MenuFunc_JPGZY(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【光之翼】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:跳+30%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPGZY, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPGZY(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPHJS(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}
public VIPJPXZS(Client)//鞋子
{
	if(XB[Client] >= 3000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 3000;
		SetZBItemTime(Client, 34, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【神器の轻盈之躯】,当前玄币%d!", XB[Client]);	 CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public LKJ4(Client)//鞋子
{
	if(XB[Client] >= 750 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 750;
		SetZBItemTime(Client, 34, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【神器の轻盈之躯】,当前玄币%d!", XB[Client]);	 CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public VIPJPXDS(Client)//血盾
{
	if(XB[Client] >= 3000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 3000;
		SetZBItemTime(Client, 35, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【神器の狂暴之躯】,当前玄币%d!", XB[Client]);	 CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public VIPJPFYS(Client)//风衣
{
	if(XB[Client] >= 3000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 3000;
		SetZBItemTime(Client, 37, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【神器の火凤凰之羽】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public VIPJPDYS(Client)//弹药
{
	if(XB[Client] >= 3000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 3000;
		SetZBItemTime(Client, 17, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【神器の钢铁之躯】,当前水晶币%d!", XB[Client]);	  CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public VIPJPXLS(Client)//项链
{
	if(XB[Client] >= 5000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 5000;
		SetZBItemTime(Client, 16, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【圣翼】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}

public VIPJPQTS(Client)//枪膛
{
	if(XB[Client] >= 1000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 1000;
		SetZBItemTime(Client, 10, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【宇翔之翼】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}

public VIPJPHJS(Client)//护甲
{
	if(XB[Client] >= 2000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 2000;
		SetZBItemTime(Client, 11, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【光之翼】,当前玄币%d!", XB[Client]);	  CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
/* 极品治愈戒指 */
public Action:MenuFunc_JPZYJZ(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【极品治愈戒指】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:治疗+80!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPZYJZ, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPZYJZ(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPXDSA(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}
/* 黑暗加农 */
public Action:MenuFunc_JPHAJN(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【黑暗加农】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:攻击+1500% 射速+40%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPHAJN, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPHAJN(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPQTSA(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}

/* 龙王套装 */
public Action:MenuFunc_JPLWTZ(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【龙王套装】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:移+100% 重+35% 攻+1500% 射+50% 治+40 防+50%  生+800  火+35%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPLWTZ, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPLWTZ(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPHJSA(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}

/* 无限之光 */
public Action:MenuFunc_JPWXZG(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【无限之光】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:攻+1000% 射+20%  速+30%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPWXZG, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPWXZG(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: GMWXZGZB(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}
public VIPJPXDSA(Client)//血盾
{
	if(XB[Client] >= 2000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 2000;
		SetZBItemTime(Client, 5, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05永久的【极品治愈戒指】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public VIPJPQTSA(Client)//枪膛
{
	if(XB[Client] >= 4000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 4000;
		SetZBItemTime(Client, 79, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【黑暗加农】,当前玄币%d!", XB[Client]);	 CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}

public VIPJPHJSA(Client)//护甲
{
	if(XB[Client] >= 8000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 8000;
		SetZBItemTime(Client, 59, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【龙王套装】,当前玄币%d!", XB[Client]);	 CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}

public GMWXZGZB(Client)//护甲
{
	if(XB[Client] >= 3500 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 3500;
		SetZBItemTime(Client, 81, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【无限之光】,当前玄币%d!", XB[Client]);	 CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
/* 黑暗骑士 */
public Action:MenuFunc_VIPJPAAA1(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【黑暗骑士】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:移+50% 重+30% 攻+1500% 射+400% 治+20 防+20%  生+400  火+20%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPJPAAA1, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_VIPJPAAA1(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPXLSAS(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}

/* 亡灵手杖 */
public Action:MenuFunc_VIPJPAAA2(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【亡灵手杖】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:射速+10%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPJPAAA2, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_VIPJPAAA2(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPXLSASP(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}

/* 死神舞步 */
public Action:MenuFunc_VIPJPAAA4(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【死神舞步】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:速度+90%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPJPAAA4, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_VIPJPAAA4(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPXLSASD(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}

/* 亡灵护甲 */
public Action:MenuFunc_VIPJPAAA5(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【亡灵护甲】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:血量+600!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPJPAAA5, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_VIPJPAAA5(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPXLSASE(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}

/* 黑暗之泣 */
public Action:MenuFunc_VIPJPAAA6(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【黑暗之泣】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:移+50% 攻+1500%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPJPAAA6, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_VIPJPAAA6(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPXLSASQ(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}

/* 亡者之力 */
public Action:MenuFunc_VIPJPAAA7(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【亡者之力】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:重+20% 治+60!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPJPAAA7, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_VIPJPAAA7(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: GMWZZLZB(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}

public VIPJPXLSAS(Client)//项链
{
	if(XB[Client] >= 4000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 4000;
		SetZBItemTime(Client, 78, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【黑暗骑士】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}

public VIPJPXLSASP(Client)//项链
{
	if(XB[Client] >= 4000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 4000;
		SetZBItemTime(Client, 54, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【亡灵手杖】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}

public VIPJPXLSASD(Client)//项链
{
	if(XB[Client] >= 4000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 4000;
		SetZBItemTime(Client, 56, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【死神舞步】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public VIPJPXLSASE(Client)//项链
{
	if(XB[Client] >= 4000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 4000;
		SetZBItemTime(Client, 57, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【亡灵护甲】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public VIPJPXLSASQ(Client)//项链
{
	if(XB[Client] >= 4000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 4000;
		SetZBItemTime(Client, 77, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【黑暗之泣】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public GMWZZLZB(Client)//项链
{
	if(XB[Client] >= 4000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 4000;
		SetZBItemTime(Client, 90, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【亡者之力】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
/* 末世之矛 */
public Action:MenuFunc_VIPBBB3(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【末世之矛】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:伤3000% 射200%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPBBB3, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_VIPBBB3(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPCSZM(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}

/* 末世之炎 */
public Action:MenuFunc_VIPBBB4(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【末世之炎】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:防御+800%火炕+800%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPBBB4, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_VIPBBB4(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPCSZY(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}

/*末世之翼 */
public Action:MenuFunc_VIPBBB5(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【末世之翼】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:速度+90%跳跃+300%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPBBB5, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_VIPBBB5(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPCSZE(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}

/*末世之手 */
public Action:MenuFunc_VIPBBB6(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【末世之手】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:伤害+3000%速度+300%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPBBB6, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_VIPBBB6(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPCSZS(Client);
			case 2: MenuFunc_WLZB(Client);
		}
	}
}
public VIPCSZM(Client)//项链
{
	if(XB[Client] >= 7000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 7000;
		SetZBItemTime(Client, 101, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【末世之矛[神]】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}

public VIPCSZY(Client)//项链
{
	if(XB[Client] >= 4000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 4000;
		SetZBItemTime(Client, 102, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【末世之炎[神]】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public VIPCSZE(Client)//项链
{
	if(XB[Client] >= 4000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 4000;
		SetZBItemTime(Client, 103, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【末世之翼[神]】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}
public VIPCSZS(Client)//项链
{
	if(XB[Client] >= 7000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 7000;
		SetZBItemTime(Client, 104, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【末世之手[神]】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_WLZB(Client)
}



//重甲防御物伤
 public Action:MenuFunc_FYZB(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "防御/物伤/装备");
	SetPanelTitle(menu, line);
	Format(line, sizeof(line), "极品生命之盾[31和7天][2000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "极品金刚护甲[31和7天][2000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "末世之力[31和7天][8000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "末世之盾[31和7天][4000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "小野护甲[31和7天][8000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "小野头盔[31和7天][8000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "小野腰带[31和7天][8000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "下一页");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回RPG选单");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_FYZB, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_FYZB(Handle:menu, MenuAction:action, Client, param)
{
    if (action == MenuAction_Select)
    {
        switch (param)
        {
			case 1: MenuFunc_JPSMZD(Client);
			case 2: MenuFunc_JPJGHJ(Client);
			case 3: MenuFunc_VIPBBB1(Client);
			case 4: MenuFunc_VIPBBB2(Client);
			case 5: MenuFunc_BL1(Client);
			case 6: MenuFunc_BL3(Client);
			case 7: MenuFunc_BL4(Client);
			case 8: MenuFunc_FYZB1(Client);
			case 9: MenuFunc_RPG(Client);
		}
	}
}

//重甲防御物伤
 public Action:MenuFunc_FYZB1(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "防御/物伤/装备");
	SetPanelTitle(menu, line);
	Format(line, sizeof(line), "樱花枪膛[31和7天][5000玄币]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "死亡圣器[31和7天][5000玄币]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回RPG选单");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_FYZB1, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_FYZB1(Handle:menu, MenuAction:action, Client, param)
{
    if (action == MenuAction_Select)
    {
        switch (param)
        {
			case 1: MenuFunc_YYZ1(Client);
			case 2: MenuFunc_YYZ3(Client);
			case 3: MenuFunc_RPG(Client);
		}
	}
}

/*樱花枪膛 */
public Action:MenuFunc_YYZ1(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【樱花枪膛】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:劈砍+3000 回血+3000 伤害+1500%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[5000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[1250]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_YYZ1, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_YYZ1(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: YHQT(Client);
			case 2: YH111(Client);
			case 3: MenuFunc_FYZB(Client);
		}
	}
}



/*死亡圣器 */
public Action:MenuFunc_YYZ3(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【死亡圣器】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明://劈砍+3000 移动速度+80% 重力+40% 攻击力+1000% 射速+50% 生命恢复+3000 防御加成+55%  生命+800 减少火焰伤害+40%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[5000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[1250]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_YYZ3, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_YYZ3(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: SWSQ(Client);
			case 2: SW222(Client);
			case 3: MenuFunc_FYZB(Client);
		}
	}
}



public YHQT(Client)//鞋子
{
	if(XB[Client] >= 5000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 5000;
		SetZBItemTime(Client, 74, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【樱花枪膛】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
public YH111(Client)//鞋子
{
	if(XB[Client] >= 1250 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 1250;
		SetZBItemTime(Client, 74, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【樱花枪膛】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
public SWSQ(Client)//鞋子
{
	if(XB[Client] >= 5000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 5000;
		SetZBItemTime(Client, 67, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【死亡圣器】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
public SW222(Client)//鞋子
{
	if(XB[Client] >= 1250 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 1250;
		SetZBItemTime(Client, 67, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【死亡圣器】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
/* 极品生命之盾 */
public Action:MenuFunc_JPSMZD(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【极品生命之盾】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:劈砍+2000 回血+2000 血+1500!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[2000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[500]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPSMZD, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPSMZD(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPXD(Client);
			case 2: VIPAAA(Client);
			case 3: MenuFunc_FYZB(Client);
		}
	}
}
public VIPJPXD(Client)//血盾
{
	if(XB[Client] >= 2000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 2000;
		SetZBItemTime(Client, 15, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【【极品生命之盾】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
public VIPAAA(Client)//血盾
{
	if(XB[Client] >= 500 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 500;
		SetZBItemTime(Client, 15, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【【极品生命之盾】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
/* 极品金刚护甲 */
public Action:MenuFunc_JPJGHJ(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【极品金刚护甲购买】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:劈砍+2000 回血+2000 防御+80%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[2000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[500]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_JPJGHJ, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_JPJGHJ(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPJPHJ(Client);
			case 2: VIPZZZ(Client);
			case 3: MenuFunc_FYZB(Client);
		}
	}
}
public VIPJPHJ(Client)//护甲
{
	if(XB[Client] >= 2000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 2000;
		SetZBItemTime(Client, 41, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【极品金刚护甲】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
public VIPZZZ(Client)//护甲
{
	if(XB[Client] >= 500 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 500;
		SetZBItemTime(Client, 41, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【极品金刚护甲】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
/* 末世之力 */
public Action:MenuFunc_VIPBBB1(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【末世之力】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:劈砍+6000 移+50% 攻+3000% 射+300%  回血3000  生+20000%  火+80%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[8000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[1750]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPBBB1, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_VIPBBB1(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPCSZL(Client);
			case 2: VIP222(Client);
			case 3: MenuFunc_FYZB(Client);
		}
	}
}
/* 末世之盾 */
public Action:MenuFunc_VIPBBB2(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【末世之盾】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:劈砍+6000 防+80% 治+3000%  生10000%  火80%  跳200%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[4000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[1000]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_VIPBBB2, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_VIPBBB2(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: VIPCSZD(Client);
			case 2: VIP111(Client);
			case 3: MenuFunc_FYZB(Client);
		}
	}
}
public VIPCSZL(Client)//项链
{
	if(XB[Client] >= 8000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 8000;
		SetZBItemTime(Client, 99, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【末世之力[神]】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
public VIP222(Client)//项链
{
	if(XB[Client] >= 1750 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 1750;
		SetZBItemTime(Client, 99, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【末世之力[神]】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
public VIPCSZD(Client)//项链
{
	if(XB[Client] >= 4000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 4000;
		SetZBItemTime(Client, 100, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【末世之盾[神]】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
public VIP111(Client)//项链
{
	if(XB[Client] >= 1000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 1000;
		SetZBItemTime(Client, 100, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【末世之盾[神]】,当前玄币%d!", XB[Client]);   CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
/*小野护甲 */
public Action:MenuFunc_BL1(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【小野护甲】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:劈砍+15000 回血+5000 血+20000!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[8000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[2000]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_BL1, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_BL1(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: BLSZ1(Client);
			case 2: BL333(Client);
			case 3: MenuFunc_FYZB(Client);
		}
	}
}
/*小野头盔 */
public Action:MenuFunc_BL3(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【小野头盔】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:劈砍+15000 回血+2000 防御+80%!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "30天购买[8000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[2000]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_BL3, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_BL3(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: BLSZ3(Client);
			case 2: BL222(Client);
			case 3: MenuFunc_FYZB(Client);
		}
	}
}
/*小野腰带 */
public Action:MenuFunc_BL4(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【小野腰带】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:劈砍+15000 火炕+80% 回血+6000!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "31天购买[8000]");
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "7 天购买[2000]");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_BL4, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_BL4(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: BLSZ4(Client);
			case 2: BL111(Client);
			case 3: MenuFunc_FYZB(Client);
		}
	}
}
public BLSZ1(Client)//鞋子
{
	if(XB[Client] >= 8000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 8000;
		SetZBItemTime(Client, 105, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【小野护甲】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
public BL333(Client)//鞋子
{
	if(XB[Client] >= 2000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 2000;
		SetZBItemTime(Client, 105, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【小野护甲】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
public BLSZ3(Client)//鞋子
{
	if(XB[Client] >= 8000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 8000;
		SetZBItemTime(Client, 107, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【小野头盔】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
public BL222(Client)//鞋子
{
	if(XB[Client] >= 2000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 2000;
		SetZBItemTime(Client, 107, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【小野头盔】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
public BLSZ4(Client)//血盾
{
	if(XB[Client] >= 8000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 8000;
		SetZBItemTime(Client, 108, 31, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 31天的【小野腰带】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
public BL111(Client)//血盾
{
	if(XB[Client] >= 2000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 2000;
		SetZBItemTime(Client, 108, 7, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 7天的【小野腰带】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}
//永久装备
/*狂战之魂套 */
public Action:MenuFunc_KZZHT(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【狂战之魂套】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:劈砍伤害+15000 枪支伤害+3000 法伤技能+5万 生命+20000 防御+30 蓝+50000 回血3000 !");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "永久999天购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_KZZHT, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_KZZHT(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: YJTZ1(Client);
			case 2: MenuFunc_FYZB(Client);
		}
	}
}
public YJTZ1(Client)//鞋子
{
	if(XB[Client] >= 40000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 40000;
		SetZBItemTime(Client, 112, 999, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 999天的【狂战之魂套】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}

/*万圣节套装 */
public Action:MenuFunc_WSJTZ(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "【万圣节套装】\n拥有的玄币:%d个", XB[Client]);
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "说明:劈砍伤害+30000 枪支伤害+4000 法伤技能+5万 速度+50 蓝+50000 回血3000 !");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "永久99999天购买");
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "返回玄币商城");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_WSJTZ, MENU_TIME_FOREVER);
	return Plugin_Handled;
}
public MenuHandler_WSJTZ(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: YJTZ2(Client);
			case 2: MenuFunc_FYZB(Client);
		}
	}
}
public YJTZ2(Client)//鞋子
{
	if(XB[Client] >= 45000 && PlayerZBItemSize[Client] - GetHasZBItemCount(Client) > 0)
	{
		XB[Client] -= 45000;
		SetZBItemTime(Client, 113, 99999, false);
		CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 99999天的【万圣节套装】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04欢迎您下次光临0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄币或者没有足够的装备空间!");
	MenuFunc_FYZB(Client)
}