/************************************************************************
*	背包系统
************************************************************************/
/* 物品Size */
static Bag_Size[5] = { 10, 5, 3, 4, 2 }

/* 背包类别 */

#define BAG_GUN		0	//枪械
#define BAG_MELEE		1	//近战
#define BAG_BOMB		2	//手雷
#define BAG_MEDIC		3	//药物
#define BAG_OTHER		4	//小药物

/* 类别物品 */

//枪械物品
#define GUN_AK47		0	//AK47
#define GUN_M16		1	//M16
#define GUN_M60		2	//M60
#define GUN_MP5		3	//MP5
#define GUN_SPAS		4	//大散弹枪
#define GUN_CHROME	5	//二代单喷
#define GUN_HUNTING	6	//猎枪
#define GUN_SCOUT		7	//鸟狙
#define GUN_AWP		8	//AWP大狙
#define GUN_GL		9	//榴弹炮

//近战武器
#define MELEE_FX		0	//消防斧
#define MELEE_KT		1	//武士刀
#define MELEE_MT		2	//斩马刀
#define MELEE_FP		3	//平底锅
#define MELEE_CS		4	//电锯

//手雷
#define BOMB_MT		0	//燃烧瓶
#define BOMB_VJ		1	//胆汁液
#define BOMB_PB		2	//土制炸弹

//药物
#define MEDIC_FAK		0	//医疗包
#define MEDIC_DF		1	//电击器
#define MEDIC_UE		2	//高爆包
#define MEDIC_UI		3	//燃烧包

//其他
#define OTHER_AL		0	//肾上腺素
#define OTHER_PP		1	//止痛药

/* 类别物品name */
static String:Bag_GunName[10][64] = { "rifle_ak47", "rifle_m60", "rifle", "smg_mp5", "shotgun_spas", "shotgun_chrome", "hunting_rifle", "sniper_scout", "sniper_awp", "grenade_launcher" };
static String:Bag_MeleeName[5][64] = { "fireaxe", "katana", "machete", "frying_pan", "chainsaw" };
static String:Bag_BombName[3][64] = { "molotov", "vomitjar", "pipe_bomb" };
static String:Bag_MedicName[4][64] = { "first_aid_kit", "defibrillator", "upgradepack_explosive", "upgradepack_incendiary" };
static String:Bag_OtherName[2][64] = { "adrenaline", "pain_pills" };

/* 类别物品显示名称 */
static String:Bag_DisGunName[10][64] = { "AK47步枪", "M60机枪", "M16步枪", "MP5冲锋枪", "战斗散弹枪", "二代单发散弹枪", "猎枪", "轻型狙击枪", "AWP狙击枪", "榴弹发射器" };
static String:Bag_DisMeleeName[5][64] = { "消防斧", "武士刀", "斩马刀", "平底锅", "电锯" };
static String:Bag_DisBombName[3][64] = { "燃烧瓶", "胆汁液", "土制炸弹" };
static String:Bag_DisMedicName[4][64] = { "医疗包", "电击器", "高爆子弹包", "燃烧子弹包" };
static String:Bag_DisOtherName[2][64] = { "肾上腺素", "止痛药丸" };

/* 扩充背包价格 */
new buybagcost = 5000;
#define BAGCOST[%1]	(I_BagSize[%1] - 20) * 2500

/* 快捷指令 */
public Action:Command_MyBag(Client,args)
{
	if (!IsValidPlayer(Client) || IsFakeClient(Client))
		return Plugin_Handled;
		
	MenuFunc_IBag(Client);
	
	return Plugin_Handled;
}


/* 特殊道具背包快捷指令 */
public Action:Command_MyTSDJ(Client,args)
{
	if (!IsValidPlayer(Client) || IsFakeClient(Client))
		return Plugin_Handled;
		
	MenuFunc_TSDJBB(Client);
	
	return Plugin_Handled;
}


//背包主面板
public MenuFunc_IBag(Client)
{
	
	new Handle:menu = CreateMenu(MenuHandler_IBag);
	decl String:line[64];
	new bagnum = I_BagSize[Client] - GetClientBagSize(Client);
	new itemnum[5];
	
	for (new i; i < 5; i++)
		itemnum[i] = GetClientBagWeapon(Client, i);
		
	new n_BagCost;
	if (BAGCOST[Client] >= 1000)
		n_BagCost = buybagcost + BAGCOST[Client];
	else
		n_BagCost = buybagcost;
		
	SetMenuTitle(menu, "我的背包[L键]:");

	Format(line, sizeof(line), "取出物品(拥有数量:%d)", GetClientBagSize(Client));
	AddMenuItem(menu, "item0", line);
	
	Format(line, sizeof(line), "存入物品(剩余空间:%d)", bagnum);
	AddMenuItem(menu, "item1", line);	
	
	Format(line, sizeof(line), "扩充背包(当前空间:%d 价格:%d$/格)", I_BagSize[Client], n_BagCost);
	AddMenuItem(menu, "item2", line);	
	
	Format(line, sizeof(line), "我的特殊物品背包");
	AddMenuItem(menu, "item3", line);

	Format(line, sizeof(line), "地狱之门[拥有地狱之匙:%d把]", TZZS[Client]);
	AddMenuItem(menu, "item4", line);	
		
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
}

public MenuHandler_IBag(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param == MenuCancel_ExitBack)
			MenuFunc_RPG(Client);
	}
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 0: MenuFunc_GetBag(Client); //提取武器
			case 1: MenuFunc_SaveBag(Client); //保存物品
			case 2: BuyBag(Client), MenuFunc_IBag(Client); //扩充背包
			case 3: MenuFunc_WDTS(Client); //特殊背包	
			case 4: MenuFunc_TZZM(Client); //地狱之门				
		}
	}
}

public Action:MenuFunc_TZZM(Client)
{    
	new Handle:menu = CreatePanel();
	   
	decl String:line[1024];	   
	Format(line, sizeof(line), "========地狱之门========\n======拥有的地狱之匙:%d把======", TZZS[Client]);   
	SetPanelTitle(menu, line);   
    
	Format(line, sizeof(line), "开启地狱之门[需要1把地狱之匙]");    
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "======使用后过图地狱模式才会失效======");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买地狱之匙[玄币:200个]");    
	DrawPanelItem(menu, line);
	
	Format(line, sizeof(line), "购买坦克[金币:$200000]");    
	DrawPanelItem(menu, line);
	
	Format(line, sizeof(line), "透明模式[金币:$10000]");    
	DrawPanelItem(menu, line);
	
	Format(line, sizeof(line), "======可打坦克爆出======");
	DrawPanelText(menu, line);	
	
	DrawPanelItem(menu, "返回物品背包");    	
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);
	
	SendPanelToClient(menu, Client, MenuHandler_TZZM, MENU_TIME_FOREVER);   
	return Plugin_Handled;
}
public MenuHandler_TZZM(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: TZZMKQ(Client);
			case 2: GMTZZS(Client);
			case 3: TZZMKE(Client);
            case 4: TZZMKO(Client);				
			case 5: MenuFunc_IBag(Client);			
		}
	}
}

public TZZMKQ(Client)//全体无敌卷轴
{   
	if(TZZS[Client] >= 1)    
	{       
		TZZS[Client] -= 1;
		TZMS[Client] = 1;
		new Num = GetRandomInt(10, 15);
		for(new x=1; x<=Num; x++)
			CheatCommand(Client, "z_spawn", "tank auto");			
		CPrintToChatAll("\x03【地狱】恭喜玩家%N开启地狱模式", Client);	      
	} else CPrintToChat(Client, "\x03【提示】你没有足够的地狱之匙!");
	MenuFunc_TZZM(Client)
}

public TZZMKE(Client)//全体无敌卷轴
{   
	if(Cash[Client] >= 200000)    
	{       
		Cash[Client] -= 200000;
		TZME[Client] = 1;
		new Num = GetRandomInt(1, 2);
		for(new x=1; x<=Num; x++)
			CheatCommand(Client, "z_spawn", "tank auto");				
		CPrintToChatAll("\x03【地狱】恭喜玩家%N开启小型地狱坦克", Client);	      
	} else CPrintToChat(Client, "\x03【提示】你没有足够的金币!");
	MenuFunc_TZZM(Client)
}

public GMTZZS(Client)//全体无敌卷轴
{   
	if(XB[Client] >= 200)    
	{       
		XB[Client] -= 200;
		TZZS[Client] += 1;		
		CPrintToChat(Client, "{green}【提示】你成功购买1把地狱之匙!");	 	      
	} else CPrintToChat(Client, "\x03【提示】你没有足够的玄币!");
	MenuFunc_TZZM(Client)
}

public TZZMKO(Client)//全体无敌卷轴
{   
	if(Cash[Client] >= 10000)    
	{       
		Cash[Client] -= 10000;
		TZMO[Client] = 1;
		new Num = 1;
		for(new x=1; x<=Num; x++)
			PerformGlow(Client, 3, 0, 1);
		SetEntityRenderMode(Client, RenderMode:3);
		SetEntityRenderColor(Client, 0, 0, 0, 0);
		CPrintToChatAll("\x03【地狱】恭喜玩家%N开启透明模式", Client);	      
	} else CPrintToChat(Client, "\x03【提示】你没有足够的金币!");
	MenuFunc_TZZM(Client)
}

/* 我的特殊背包 */
public Action:MenuFunc_WDTS(Client)
{    
	new Handle:menu = CreatePanel();
	   
	decl String:line[1024];	   
	Format(line, sizeof(line), "========我的特殊背包========\n======拥有的玄币:%d个======", XB[Client]);   
	SetPanelTitle(menu, line);   
    
	Format(line, sizeof(line), "力量背包");    
	DrawPanelItem(menu, line);
	
	Format(line, sizeof(line), "宝石背包");    
	DrawPanelItem(menu, line);

	Format(line, sizeof(line), "神秘背包");    
	DrawPanelItem(menu, line);	

	Format(line, sizeof(line), "特殊道具背包");    
	DrawPanelItem(menu, line);	
	
	DrawPanelItem(menu, "返回物品背包");    	
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);
	
	SendPanelToClient(menu, Client, MenuHandler_WDTS, MENU_TIME_FOREVER);   
	return Plugin_Handled;
}
public MenuHandler_WDTS(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: MenuFunc_Equipmentsale(Client);
			case 2: MenuFunc_MFBSBAG(Client);
			case 3: MenuFunc_SMBAG(Client);
			case 4: MenuFunc_TSDJBB(Client); //特殊道具背包			
			case 5: MenuFunc_IBag(Client);			
		}
	}
}

/* 兑换BOSS之光 */
public Action:MenuFunc_DHBSZG(Client)
{
    new Handle:menu = CreatePanel();
	
    decl String:line[1024];	
    Format(line, sizeof(line), "【兑换BOSS之光】\n拥有的BOSS心愿:%d个", BSXY[Client]);
    SetPanelTitle(menu, line);
    Format(line, sizeof(line), "说明:用BOSS心愿兑换BOSS之光!");
    DrawPanelText(menu, line);

    Format(line, sizeof(line), "兑换BOSS之光5个【BOSS心愿:30】");
    DrawPanelItem(menu, line);
	
    Format(line, sizeof(line), "兑换BOSS之光10个【BOSS心愿:50】");
    DrawPanelItem(menu, line);
	
    Format(line, sizeof(line), "兑换BOSS之光15个【BOSS心愿:100】");
    DrawPanelItem(menu, line);
	
    DrawPanelItem(menu, "返回神秘背包");
    DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

    SendPanelToClient(menu, Client, MenuHandler_DHBSZG, MENU_TIME_FOREVER);
    return Plugin_Handled;
}
public MenuHandler_DHBSZG(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: DUIHUANBSA(Client);
			case 2: DUIHUANBSB(Client);
			case 3: DUIHUANBSC(Client);
			case 4: MenuFunc_SMBAG(Client);
		}
	}
}
public DUIHUANBSA(Client)
{   
	if(BSXY[Client] >= 30)    
	{       
		BSZG[Client] += 5;		
		BSXY[Client] -= 30;       
		CPrintToChat(Client, "\x05【提示】你成功兑换5个BOSS之光!");	    
	} else CPrintToChat(Client, "\x05【提示】你没有足够的BOSS心愿!");
}
public DUIHUANBSB(Client)
{    
	if(BSXY[Client] >= 50)    
	{       
		BSZG[Client] += 10;		
		BSXY[Client] -= 50;        
		CPrintToChat(Client, "\x05【提示】你成功兑换10个BOSS之光!");	    
	} else CPrintToChat(Client, "\x05【提示】你没有足够的BOSS心愿!");
}
public DUIHUANBSC(Client)
{    
	if(BSXY[Client] >= 100)    
	{        
		BSZG[Client] += 15;		
		BSXY[Client] -= 100;       
		CPrintToChat(Client, "{green}【提示】你成功兑换15个BOSS之光!");	   
	} else CPrintToChat(Client, "{green}【提示】你没有足够的BOSS心愿!");
}


/* 神秘背包*/
public Action:MenuFunc_SMBAG(Client)
{   
	new Handle:menu = CreatePanel();
		   
	decl String:line[1024];   
	Format(line, sizeof(line), "=============我的神秘背包=============");   
	SetPanelTitle(menu, line);   

	Format(line, sizeof(line), "═══开启BOSS之光[拥有:%d个]═══", BSZG[Client]);   
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "======BOSS对我们的祝福之光======");
	DrawPanelText(menu, line);	 	
	
	Format(line, sizeof(line), "═══兑换BOSS之光═══");   
	DrawPanelItem(menu, line);	
	
	DrawPanelItem(menu, "返回装备选单");   
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);
 
	SendPanelToClient(menu, Client, MenuHandler_SMBAG, MENU_TIME_FOREVER);  
	return Plugin_Handled;
}
public MenuHandler_SMBAG(Handle:menu, MenuAction:action, Client, param)
{
    if (action == MenuAction_Select) 
    {
        switch (param)
        {	        		
			case 1: KQBSZG(Client);
			case 2:
			    if (BSXY[Client] > 0)
			    {  
			        MenuFunc_DHBSZG(Client);
			    } else CPrintToChat(Client, "你没有BOSS心愿无法进入")				
			case 3: MenuFunc_IBag(Client);       
		}   
	}
}

public KQBSZG(Client)
{   
	if(BSZG[Client] >= 1)    
	{   
		BSZG[Client] -= 1;    
		new ESSASDS = GetRandomInt(0, 7);
		switch(ESSASDS)
		{
			case 0: 
			{
				Lyxz[Client] += 2;
				CPrintToChat(Client, "\x01[\x04给\x01]\x03：\x05获得烈焰勋章2个"); 				
			}
			case 1: 
			{
				Eqbox[Client] += 1;
				CPrintToChat(Client, "\x01[\x04光\x01]\x03：\x05获得炎神宝盒1个"); 				
			}
			case 2: 
			{
				LisA[Client] += 1;
				CPrintToChat(Client, "\x01[\x04光\x01]\x03：\x05获得天使之力1个");				
			}
			case 3: 
			{
				Cash[Client] += 80000;
				CPrintToChat(Client, "\x01[\x04光\x01]\x03：\x05获得金币80000个"); 				
			}
			case 4: 
			{
				SCL[Client] += 5;
				CPrintToChat(Client, "\x01[\x04光\x01]\x03：\x05获得套装碎片S5个"); 				
			}
			case 5: 
			{
				BSXY[Client] += 6;
				CPrintToChat(Client, "\x01[\x04光\x01]\x03：\x05获得BOSS心愿6个"); 				
			}
			case 6: 
			{
				MFBS3[Client] += 1;
				CPrintToChat(Client, "\x01[\x04光\x01]\x03：\x05获得高级经验宝石一块"); 				
			}			
        }			
		CPrintToChatAll("\x02[\x04光\x02],\x03玩家 \x04%N \x03开启了[BOSS之光]1个祝他好运", Client);	    
	} else CPrintToChat(Client, "\x03你的BOSS之光不足1个");
}


/* 装备合成 */
public Action:MenuFunc_ZBLYZQ(Client)
{    
	new Handle:menu = CreatePanel();
	   
	decl String:line[1024];	   
	Format(line, sizeof(line), "========装备合成=======\n 当前拥有: 套装碎片A:%d个 套装碎片B:%d个 \n套装碎片S:%d个 装备宝石:%d块 \n 生命碎片:%d块\n========================", ACL[Client], BCL[Client], SCL[Client], MFBS6[Client], MFBS7[Client]);   
	SetPanelTitle(menu, line);   
    
	Format(line, sizeof(line), "合成炎神枪膛");    
	DrawPanelItem(menu, line);

	Format(line, sizeof(line), "合成炎神之靴");    
	DrawPanelItem(menu, line);

	Format(line, sizeof(line), "合成炎神之盾");    
	DrawPanelItem(menu, line);

	Format(line, sizeof(line), "合成炎神护甲");    
	DrawPanelItem(menu, line);

	Format(line, sizeof(line), "合成炎神羽翼");    
	DrawPanelItem(menu, line);	
	
	Format(line, sizeof(line), "合成炎神魔戒");    
	DrawPanelItem(menu, line);		
	
	Format(line, sizeof(line), "下一页");    
	DrawPanelItem(menu, line);		
	   	
	DrawPanelItem(menu, "返回我的背包");    	
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);
	
	SendPanelToClient(menu, Client, MenuHandler_ZBLYZQ, MENU_TIME_FOREVER);   
	return Plugin_Handled;
}
public MenuHandler_ZBLYZQ(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: MenuFunc_QJQTLH(Client);
			case 2: MenuFunc_XWSDLH(Client);	
			case 3: MenuFunc_XWSMLH(Client);	
			case 4: MenuFunc_XWFYLH(Client);	
			case 5: MenuFunc_XWZLLH(Client);
			case 6: MenuFunc_QJMJLH(Client);	
			case 7: MenuFunc_ZBLYZQ2(Client);			
			case 8: MenuFunc_IBag(Client);
		}
	}
}

/* 装备合成 */
public Action:MenuFunc_ZBLYZQ2(Client)
{    
	new Handle:menu = CreatePanel();
	   
	decl String:line[1024];	   
	Format(line, sizeof(line), "========装备合成=======\n 当前拥有: 套装碎片A:%d个 套装碎片B:%d个 \n套装碎片S:%d个 装备宝石:%d块 \n 生命碎片:%d块\n========================", ACL[Client], BCL[Client], SCL[Client], MFBS6[Client], MFBS7[Client]);   
	SetPanelTitle(menu, line);   
    
	Format(line, sizeof(line), "合成炎神套装");    
	DrawPanelItem(menu, line);
	
	Format(line, sizeof(line), "上一页");    
	DrawPanelItem(menu, line);		
	   	
	DrawPanelItem(menu, "返回我的背包");    	
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);
	
	SendPanelToClient(menu, Client, MenuHandler_ZBLYZQ2, MENU_TIME_FOREVER);   
	return Plugin_Handled;
}
public MenuHandler_ZBLYZQ2(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: MenuFunc_QJTZLH(Client);
			case 2: MenuFunc_ZBLYZQ(Client);			
			case 3: MenuFunc_IBag(Client);
		}
	}
}


/*炎神套装 */
public Action:MenuFunc_QJTZLH(Client)
{
    new Handle:menu = CreatePanel();
	
    decl String:line[1024];	
    Format(line, sizeof(line), "炎神套装\n套装碎片A:%d个 套装碎片B:%d个 套装碎片S:%d个", ACL[Client], BCL[Client], SCL[Client]);
    SetPanelTitle(menu, line);
    Format(line, sizeof(line), "===================\n炎神枪膛[30日] 炎神之靴[30日] 炎神之盾[30日] \n 炎神护甲[30日] 炎神羽翼[30日] 炎神魔戒[30日] \n限期:永久 \n======================!");
    DrawPanelText(menu, line);

    Format(line, sizeof(line), "确认合成");
    DrawPanelItem(menu, line);
    DrawPanelItem(menu, "返回合成菜单");
    DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

    SendPanelToClient(menu, Client, MenuHandler_QJTZLH, MENU_TIME_FOREVER);
    return Plugin_Handled;
}
public MenuHandler_QJTZLH(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: QJTZLHD(Client);
			case 2: MenuFunc_ZBLYZQ2(Client);
		}
	}
}
public QJTZLHD(Client)
{
    if(PlayerItem[Client][ITEM_ZB][82] >= 30 && PlayerItem[Client][ITEM_ZB][83] >= 30 && PlayerItem[Client][ITEM_ZB][84] >= 30 && PlayerItem[Client][ITEM_ZB][85] >= 30 && PlayerItem[Client][ITEM_ZB][86] >= 30 && PlayerItem[Client][ITEM_ZB][87] >= 30)
    {
        PlayerItem[Client][ITEM_ZB][82] -= 30;		
        PlayerItem[Client][ITEM_ZB][83] -= 30;	
        PlayerItem[Client][ITEM_ZB][84] -= 30;	
        PlayerItem[Client][ITEM_ZB][85] -= 30;	
        PlayerItem[Client][ITEM_ZB][86] -= 30;	
        PlayerItem[Client][ITEM_ZB][87] -= 30;			
        SetZBItemTime(Client, 88, 999, false);			
        CPrintToChat(Client, "\x03【合成】你成功合成炎神套装永久");
        CPrintToChatAll("\x03【合成】恭喜玩家%N成功合成炎神套装永久", Client);
    } else CPrintToChat(Client, "\x03【提示】你没有足够的材料!");
}

/*炎神魔戒 */
public Action:MenuFunc_QJMJLH(Client)
{
    new Handle:menu = CreatePanel();
	
    decl String:line[1024];	
    Format(line, sizeof(line), "炎神魔戒\n套装碎片A:%d个 套装碎片B:%d个 套装碎片S:%d个", ACL[Client], BCL[Client], SCL[Client]);
    SetPanelTitle(menu, line);
    Format(line, sizeof(line), "===================\n需要 套装碎片S15个 套装碎片B12个 装备宝石3块 极品治愈戒指[30日] \n 生命碎片2个 限期:永久 \n======================!");
    DrawPanelText(menu, line);

    Format(line, sizeof(line), "确认合成");
    DrawPanelItem(menu, line);
    DrawPanelItem(menu, "返回合成菜单");
    DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

    SendPanelToClient(menu, Client, MenuHandler_QJMJLH, MENU_TIME_FOREVER);
    return Plugin_Handled;
}
public MenuHandler_QJMJLH(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: QJMJLHD(Client);
			case 2: MenuFunc_ZBLYZQ(Client);
		}
	}
}
public QJMJLHD(Client)
{
    if(PlayerItem[Client][ITEM_ZB][9] >= 30 && SCL[Client] >= 15 && BCL[Client] >= 12 && MFBS6[Client] >= 3 && MFBS7[Client] >=2)
    {
        PlayerItem[Client][ITEM_ZB][9] -= 30;
        SCL[Client] -= 15;
        BCL[Client] -= 12;
        MFBS6[Client] -= 3;
        MFBS7[Client] -= 2;		
        SetZBItemTime(Client, 87, 31, false);			
        CPrintToChat(Client, "\x03【合成】你成功合成炎神魔戒永久");
        CPrintToChatAll("\x03【合成】恭喜玩家%N成功合成炎神魔戒永久", Client);
    } else CPrintToChat(Client, "\x03【提示】你没有足够的材料!");
}

/*炎神羽翼 */
public Action:MenuFunc_XWZLLH(Client)
{
    new Handle:menu = CreatePanel();
	
    decl String:line[1024];	
    Format(line, sizeof(line), "炎神羽翼\n套装碎片A:%d个 套装碎片B:%d个 套装碎片S:%d个", ACL[Client], BCL[Client], SCL[Client]);
    SetPanelTitle(menu, line);
    Format(line, sizeof(line), "===================\n需要 套装碎片S15个 套装碎片B12个 装备宝石3块 光之翼[30日] \n 生命碎片2个 限期:永久 \n======================!");
    DrawPanelText(menu, line);

    Format(line, sizeof(line), "确认合成");
    DrawPanelItem(menu, line);
    DrawPanelItem(menu, "返回合成菜单");
    DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

    SendPanelToClient(menu, Client, MenuHandler_XWZLLH, MENU_TIME_FOREVER);
    return Plugin_Handled;
}
public MenuHandler_XWZLLH(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: XWZLLHD(Client);
			case 2: MenuFunc_ZBLYZQ(Client);
		}
	}
}
public XWZLLHD(Client)
{
    if(PlayerItem[Client][ITEM_ZB][11] >= 30 && SCL[Client] >= 15 && BCL[Client] >= 12 && MFBS6[Client] >= 3 && MFBS7[Client] >=2)
    {
        PlayerItem[Client][ITEM_ZB][11] -= 30;
        SCL[Client] -= 15;
        BCL[Client] -= 12;
        MFBS6[Client] -= 3;
        MFBS7[Client] -= 2;		
        SetZBItemTime(Client, 86, 999, false);			
        CPrintToChat(Client, "\x03【合成】你成功合成炎神羽翼永久");
        CPrintToChatAll("\x03【合成】恭喜玩家%N成功合成炎神羽翼永久", Client);
    } else CPrintToChat(Client, "\x03【提示】你没有足够的材料!");
}
/*炎神护甲 */
public Action:MenuFunc_XWFYLH(Client)
{
    new Handle:menu = CreatePanel();
	
    decl String:line[1024];	
    Format(line, sizeof(line), "炎神护甲\n套装碎片A:%d个 套装碎片B:%d个 套装碎片S:%d个", ACL[Client], BCL[Client], SCL[Client]);
    SetPanelTitle(menu, line);
    Format(line, sizeof(line), "===================\n需要 套装碎片S15个 套装碎片B12个 装备宝石3块 极品金刚护甲[30日] \n 生命碎片2个 限期:永久 \n======================!");
    DrawPanelText(menu, line);

    Format(line, sizeof(line), "确认合成");
    DrawPanelItem(menu, line);
    DrawPanelItem(menu, "返回合成菜单");
    DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

    SendPanelToClient(menu, Client, MenuHandler_XWFYLH, MENU_TIME_FOREVER);
    return Plugin_Handled;
}
public MenuHandler_XWFYLH(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: XWFYLHD(Client);
			case 2: MenuFunc_ZBLYZQ(Client);
		}
	}
}
public XWFYLHD(Client)
{
    if(PlayerItem[Client][ITEM_ZB][41] >= 30 && SCL[Client] >= 15 && BCL[Client] >= 12 && MFBS6[Client] >= 3 && MFBS7[Client] >=2)
    {
        PlayerItem[Client][ITEM_ZB][41] -= 30;
        SCL[Client] -= 15;
        BCL[Client] -= 12;
        MFBS6[Client] -= 3;
        MFBS7[Client] -= 2;		
        SetZBItemTime(Client, 85, 999, false);			
        CPrintToChat(Client, "\x03【合成】你成功合成炎神护甲永久");
        CPrintToChatAll("\x03【合成】恭喜玩家%N成功合成炎神护甲永久", Client);
    } else CPrintToChat(Client, "\x03【提示】你没有足够的材料!");
}

/*炎神之盾 */
public Action:MenuFunc_XWSMLH(Client)
{
    new Handle:menu = CreatePanel();
	
    decl String:line[1024];	
    Format(line, sizeof(line), "炎神之盾 \n套装碎片A:%d个 套装碎片B:%d个 套装碎片S:%d个", ACL[Client], BCL[Client], SCL[Client]);
    SetPanelTitle(menu, line);
    Format(line, sizeof(line), "===================\n需要 套装碎片S15个 套装碎片B12个 装备宝石3块 极品生命之盾[30日] \n 生命碎片2个 限期:永久 \n======================!");
    DrawPanelText(menu, line);

    Format(line, sizeof(line), "确认合成");
    DrawPanelItem(menu, line);
    DrawPanelItem(menu, "返回合成菜单");
    DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

    SendPanelToClient(menu, Client, MenuHandler_XWSMLH, MENU_TIME_FOREVER);
    return Plugin_Handled;
}
public MenuHandler_XWSMLH(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: XWSMLHD(Client);
			case 2: MenuFunc_ZBLYZQ(Client);
		}
	}
}
public XWSMLHD(Client)
{
    if(PlayerItem[Client][ITEM_ZB][15] >= 30 && SCL[Client] >= 15 && BCL[Client] >= 12 && MFBS6[Client] >= 3 && MFBS7[Client] >=2)
    {
        PlayerItem[Client][ITEM_ZB][15]  -= 30;
        SCL[Client] -= 15;
        BCL[Client] -= 12;
        MFBS6[Client] -= 3;
        MFBS7[Client] -= 2;		
        SetZBItemTime(Client, 84, 999, false);			
        CPrintToChat(Client, "\x03【合成】你成功合成炎神之盾永久");
        CPrintToChatAll("\x03【合成】恭喜玩家%N成功合成炎神之盾】永久", Client);
    } else CPrintToChat(Client, "\x03【提示】你没有足够的材料!");
}

/*炎神之靴 */
public Action:MenuFunc_XWSDLH(Client)
{
    new Handle:menu = CreatePanel();
	
    decl String:line[1024];	
    Format(line, sizeof(line), "炎神之靴\n套装碎片A:%d个 套装碎片B:%d个 套装碎片S:%d个", ACL[Client], BCL[Client], SCL[Client]);
    SetPanelTitle(menu, line);
    Format(line, sizeof(line), "===================\n需要 套装碎片S15个 套装碎片B12个 装备宝石3块 极品鬼步靴子[30日] \n 生命碎片2个 限期:永久 \n======================!");
    DrawPanelText(menu, line);

    Format(line, sizeof(line), "确认合成");
    DrawPanelItem(menu, line);
    DrawPanelItem(menu, "返回合成菜单");
    DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

    SendPanelToClient(menu, Client, MenuHandler_XWSDLH, MENU_TIME_FOREVER);
    return Plugin_Handled;
}
public MenuHandler_XWSDLH(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: XWSDLHD(Client);
			case 2: MenuFunc_ZBLYZQ(Client);
		}
	}
}
public XWSDLHD(Client)
{
    if(PlayerItem[Client][ITEM_ZB][9]  >= 30 && SCL[Client] >= 15 && BCL[Client] >= 12 && MFBS6[Client] >= 3 && MFBS7[Client] >=2)
    {
        PlayerItem[Client][ITEM_ZB][9] -= 30;
        SCL[Client] -= 15;
        BCL[Client] -= 12;
        MFBS6[Client] -= 3;
        MFBS7[Client] -= 2;		
        SetZBItemTime(Client, 83, 999, false);			
        CPrintToChat(Client, "\x03【合成】你成功合成炎神之靴永久");
        CPrintToChatAll("\x03【合成】恭喜玩家%N成功合成炎神之靴永久", Client);
    } else CPrintToChat(Client, "\x03【提示】你没有足够的材料!");
}



/*炎神枪膛 */
public Action:MenuFunc_QJQTLH(Client)
{
    new Handle:menu = CreatePanel();
	
    decl String:line[1024];	
    Format(line, sizeof(line), "【炎神枪膛】\n套装碎片A:%d个 套装碎片B:%d个 套装碎片S:%d个", ACL[Client], BCL[Client], SCL[Client]);
    SetPanelTitle(menu, line);
    Format(line, sizeof(line), "===================\n需要 套装碎片S10个 套装碎片B10个 装备宝石3块 极品改造枪膛[30日] \n 生命碎片2个 限期:永久 \n======================!");
    DrawPanelText(menu, line);

    Format(line, sizeof(line), "确认合成");
    DrawPanelItem(menu, line);
    DrawPanelItem(menu, "返回合成菜单");
    DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

    SendPanelToClient(menu, Client, MenuHandler_QJQTLH, MENU_TIME_FOREVER);
    return Plugin_Handled;
}
public MenuHandler_QJQTLH(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: QJQTLHD(Client);
			case 2: MenuFunc_ZBLYZQ(Client);
		}
	}
}
public QJQTLHD(Client)
{
    if(PlayerItem[Client][ITEM_ZB][33] >= 30 && SCL[Client] >= 10 && BCL[Client] >= 10 && MFBS6[Client] >= 3 && MFBS7[Client] >=2)
    {
        PlayerItem[Client][ITEM_ZB][33] -= 30;
        SCL[Client] -= 10;
        BCL[Client] -= 10;
        MFBS6[Client] -= 3;
        MFBS7[Client] -= 2;		
        SetZBItemTime(Client, 82, 999, false);			
        CPrintToChat(Client, "\x03【合成】你成功合成炎神枪膛永久");
        CPrintToChatAll("\x03【合成】恭喜玩家%N成功合成炎神枪膛永久", Client);
    } else CPrintToChat(Client, "\x03【提示】你没有足够的材料!");
}

//使用道具
public Action:MenuFunc_MFBSBAG(Client)
{
	new Handle:menu = CreatePanel();
	  
	decl String:line[256];   
	Format(line, sizeof (line), "═══魔法宝石背包═══");    
	SetPanelTitle(menu, line);   
	Format(line, sizeof (line), "使用初级经验宝石: %d个", MFBS1[Client]);   
	DrawPanelItem(menu, line);	
	Format(line, sizeof (line), "使用中级经验宝石: %d个", MFBS2[Client]);  
	DrawPanelItem(menu, line);
	Format(line, sizeof (line), "使用高级经验宝石: %d个", MFBS3[Client]);   
	DrawPanelItem(menu, line);	
	Format(line, sizeof (line), "使用极品经验宝石: %d个", MFBS4[Client]);  
	DrawPanelItem(menu, line);  
	Format(line, sizeof (line), "使用VIP经验宝石: %d个", MFBS5[Client]);   
	DrawPanelItem(menu, line);	
	Format(line, sizeof (line), "魔法宝石系统说明");  
	DrawPanelItem(menu, line); 
	DrawPanelItem(menu, "返回背包");  
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);
  
	SendPanelToClient(menu, Client, MenuHandler_MFBSBAG, MENU_TIME_FOREVER);   
	return Plugin_Handled;
}
public MenuHandler_MFBSBAG(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1:SYCJBS(Client);
            case 2:SYZJBS(Client);
			case 3:SYGJBS(Client);
            case 4:SYJPBS(Client);
			case 5:SYVIPBS(Client);
			case 6:MenuFunc_MFBSSM(Client);
			case 7:MenuFunc_IBag(Client);
		}
	}
}
public SYCJBS(Client)
{   
    if(IsPlayerAlive(Client))	
	{
	   if(MFBS1[Client] >= 1)    
	   {       
		    MFBS1[Client] -= 1;		
		    EXP[Client] += 10000;    
		    CPrintToChatAll("\x03[系统]\04%N使用了初级经验宝石获得10000经验!", Client);	    
	    } else CPrintToChat(Client, "\x03【提示】你没有这个宝石!");
	} else CPrintToChat(Client, "{green}【宝石】死亡状态下无法使用!");
}
public SYZJBS(Client)
{   
    if(IsPlayerAlive(Client))	
	{
	   if(MFBS2[Client] >= 1)    
	   {       
		    MFBS2[Client] -= 1;		
		    EXP[Client] += 20000;      
		    CPrintToChatAll("\x03[系统]\04%N使用了中等经验宝石获得20000经验!", Client);	    
	    } else CPrintToChat(Client, "\x03【提示】你没有这个宝石!");
	} else CPrintToChat(Client, "{green}【宝石】死亡状态下无法使用!");
}
public SYGJBS(Client)
{   
    if(IsPlayerAlive(Client))	
	{
	  if(MFBS3[Client] >= 1)    
	  {       
		    MFBS3[Client] -= 1;		
		    EXP[Client] += 30000;         
		    CPrintToChatAll("\x03[系统]\04%N使用了高级经验宝石获得30000经验！", Client);	    
	    } else CPrintToChat(Client, "\x03【提示】你没有这个宝石!");
	} else CPrintToChat(Client, "{green}【宝石】死亡状态下无法使用!");
}
public SYJPBS(Client)
{   
    if(IsPlayerAlive(Client))	
	{
	   if(MFBS4[Client] >= 1)    
	   {       
		    MFBS4[Client] -= 1;		
		    EXP[Client] += 40000;      
		    CPrintToChatAll("\x03[系统]\04%N使用了极品经验宝石获得40000经验!", Client);	    
	    } else CPrintToChat(Client, "\x03【提示】你没有这个宝石!");
    } else CPrintToChat(Client, "{green}【宝石】死亡状态下无法使用!");
}
public SYVIPBS(Client)
{   
   if(IsPlayerAlive(Client))	
	{
	  if(MFBS5[Client] >= 1)    
	  {       
		    MFBS5[Client] -= 1;		
		    EXP[Client] += 50000;          
		    CPrintToChatAll("\x03[系统]\04%N使用了VIP经验宝石获得50000经验", Client);	    
	    } else CPrintToChat(Client, "\x03【提示】你没有这个宝石!");
    } else CPrintToChat(Client, "{green}【宝石】死亡状态下无法使用!");
}

//魔法宝石系统说明
public Action:MenuFunc_MFBSSM(Client)
{
	new Handle:menu = CreatePanel();
	decl String:line[256];
	
	Format(line, sizeof(line), "宝石系统说明:\n初级宝石可以获得10000经验 \n中等经验宝石可获得 20000经验 \n高级可获得30000经验 极品可得40000经验\nVIP专属可获得50000经验.");
	DrawPanelText(menu, line);
	
	DrawPanelItem(menu, "返回宝石背包");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_MFBSSM, MENU_TIME_FOREVER);
	CloseHandle(menu);
	return Plugin_Handled;
}
public MenuHandler_MFBSSM(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1: MenuFunc_MFBSBAG(Client); //宝石背包
		}
	}
}


//使用道具
public Action:MenuFunc_TSDJBB(Client)
{
	new Handle:menu = CreatePanel();
	  
	decl String:line[256];   
	Format(line, sizeof (line), "═══特殊道具背包 快捷键[U]═══ \n═══拥有不删档道具:%d个═══", BSD[Client]);    
	SetPanelTitle(menu, line);  

	Format(line, sizeof (line), "武器补给:%d次", TSBS[Client]);  
	DrawPanelItem(menu, line); 	
 	
	Format(line, sizeof (line), "特殊道具系统说明");  
	DrawPanelItem(menu, line); 
	
	DrawPanelItem(menu, "返回背包");  
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);
  
	SendPanelToClient(menu, Client, MenuHandler_TSDJBB, MENU_TIME_FOREVER);   
	return Plugin_Handled;
}
public MenuHandler_TSDJBB(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{	
			case 1:TSBSDJSY(Client);				
			case 2:MenuFunc_LLXTK(Client);
			case 3:MenuFunc_IBag(Client);
		}
	}
}

public TSBSDJSY(Client)
{   
	if(TSBS[Client] >= 1)    
	{       
		TSBS[Client] -= 1;
		CheatCommand(Client, "give", "pipe_bomb");	
		CheatCommand(Client, "give", "rifle_ak47");
		CheatCommand(Client, "give", "first_aid_kit");		
		CPrintToChatAll("\x03[系统]\04%N使用了\x04一次武器补给道具！", Client);	    
	} else CPrintToChat(Client, "\x03【提示】你没有武器补给道具!"); 
}

//道具系统说明
public Action:MenuFunc_LLXTK(Client)
{
	new Handle:menu = CreatePanel();
	decl String:line[256];
	
	Format(line, sizeof(line), "道具系统说明:\n直接按相应按键使用即可.");
	DrawPanelText(menu, line);
	
	DrawPanelItem(menu, "返回道具背包");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_LLXTK, MENU_TIME_FOREVER);
	CloseHandle(menu);
	return Plugin_Handled;
}
public MenuHandler_LLXTK(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1: MenuFunc_TSDJBB(Client); //道具背包
		}
	}
}


//使用力量
public Action:MenuFunc_Equipmentsale(Client)
{
	new Handle:menu = CreatePanel();
	  
	decl String:line[256];   
	Format(line, sizeof (line), "═══力量背包═══");    
	SetPanelTitle(menu, line);   
	Format(line, sizeof (line), "使用天使之力: %d", LisA[Client]);   
	DrawPanelItem(menu, line);	
	Format(line, sizeof (line), "使用恶魔之力: %d", LisB[Client]);  
	DrawPanelItem(menu, line);  
	Format(line, sizeof (line), "使用地狱之力: %d", LisC[Client]);  
	DrawPanelItem(menu, line);  	
	Format(line, sizeof (line), "使用圣灵之力: %d", LisD[Client]);  
	DrawPanelItem(menu, line); 	
	Format(line, sizeof (line), "力量系统说明");  
	DrawPanelItem(menu, line); 
	Format(line, sizeof (line), "卸下力量");  
	DrawPanelItem(menu, line);
	DrawPanelItem(menu, "返回背包");  
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);
  
	SendPanelToClient(menu, Client, MenuHandler_Equipmentsale, MENU_TIME_FOREVER);   
	return Plugin_Handled;
}
public MenuHandler_Equipmentsale(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1:CSTOU(Client);
            case 2:CSJIA(Client);
			case 3:CSJIC(Client);
			case 4:CSJID(Client);			
			case 5:MenuFunc_LLXT(Client);
			case 6:MenuFunc_LLXX(Client);
			case 7:MenuFunc_IBag(Client);
		}
	}
}
public CSTOU(Client)
{   
	if(Lis[Client] == 0)    
	{	    
		if(LisA[Client] > 0)        
		{            
			Lis[Client] = 1;       
		} 	
	} else PrintHintText(Client, "你已经拥有特殊力量了!");	
}

public CSJIA(Client)
{   
	if(Lis[Client] == 0)    
	{	    
		if(LisB[Client] > 0)        
		{            
			Lis[Client] = 2;       
		}	
	} else PrintHintText(Client, "你已经拥有特殊力量了!");	
}

public CSJIC(Client)
{   
	if(Lis[Client] == 0)    
	{	    
		if(LisC[Client] > 0)        
		{            
			Lis[Client] = 3;       
		}	
	} else PrintHintText(Client, "你已经拥有特殊力量了!");	
}

public CSJID(Client)
{   
	if(Lis[Client] == 0)    
	{	    
		if(LisD[Client] > 0)        
		{            
			Lis[Client] = 4;       
		}	
	} else PrintHintText(Client, "你已经拥有特殊力量了!");	
}

//卸下力量
public Action:MenuFunc_LLXX(Client)
{
	new Handle:menu = CreatePanel();
	  
	decl String:line[256];   
	Format(line, sizeof (line), "═══卸下力量═══");    
	SetPanelTitle(menu, line);   
	Format(line, sizeof (line), "卸下天使之力: %d", LisA[Client]);   
	DrawPanelItem(menu, line);	
	Format(line, sizeof (line), "卸下恶魔之力: %d", LisB[Client]);  
	DrawPanelItem(menu, line);  
	Format(line, sizeof (line), "卸下地狱之力: %d", LisC[Client]);  
	DrawPanelItem(menu, line);
	Format(line, sizeof (line), "卸下圣灵之力: %d", LisD[Client]);  
	DrawPanelItem(menu, line);	
	DrawPanelItem(menu, "返回力量背包");  
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);
  
	SendPanelToClient(menu, Client, MenuHandler_LLXX, MENU_TIME_FOREVER);   
	return Plugin_Handled;
}
public MenuHandler_LLXX(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1:CSTOUX(Client);
            case 2:CSJIAX(Client);
			case 3:CSJICX(Client);
			case 4:CSJIDX(Client);			
			case 5:MenuFunc_Equipmentsale(Client);
		}
	}
}
public CSTOUX(Client)
{   
	if(Lis[Client] == 1)    
	{	    
		if(LisA[Client] > 0)        
		{            
			Lis[Client] = 0;       
		}	
	} else PrintHintText(Client, "你没有装备天使力量!");	
}

public CSJIAX(Client)
{   
	if(Lis[Client] == 2)    
	{	    
		if(LisB[Client] > 0)        
		{            
			Lis[Client] = 0;       
		}	
	} else PrintHintText(Client, "你没有装备恶魔力量!");	
}

public CSJICX(Client)
{   
	if(Lis[Client] == 3)    
	{	    
		if(LisC[Client] > 0)        
		{            
			Lis[Client] = 0;       
		}	
	} else PrintHintText(Client, "你没有装备地狱力量!");	
}

public CSJIDX(Client)
{   
	if(Lis[Client] == 4)    
	{	    
		if(LisD[Client] > 0)        
		{            
			Lis[Client] = 0;       
		}	
	} else PrintHintText(Client, "你没有装备圣灵力量!");	
}

//力量系统说明
public Action:MenuFunc_LLXT(Client)
{
	new Handle:menu = CreatePanel();
	decl String:line[256];
	
	Format(line, sizeof(line), "力量系统说明:\n天使之力可以加快速度与增强跳跃的高度\n恶魔之力则是增加暴击几率与攻击力\n地狱之力全面提升圣灵力量隐藏力量\n力量是开启炎神宝盒开出.");
	DrawPanelText(menu, line);
	
	DrawPanelItem(menu, "返回力量背包");
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_LLXT, MENU_TIME_FOREVER);
	CloseHandle(menu);
	return Plugin_Handled;
}
public MenuHandler_LLXT(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1: MenuFunc_Equipmentsale(Client); //力量背包
		}
	}
}


//取出物品
public MenuFunc_GetBag(Client)
{
	
	new Handle:menu = CreateMenu(MenuHandler_GetBag);
	decl String:line[64];
	new bagnum = I_BagSize[Client] - GetClientBagSize(Client);
	new itemnum[5];
	
	for (new i; i < 5; i++)
		itemnum[i] = GetClientBagWeapon(Client, i);
	
	Format(line, sizeof(line), "提取物品(剩余空间:%d)", bagnum);	
	SetMenuTitle(menu, line);

	Format(line, sizeof(line), "枪械武器(总数:%d 手续费:200$)", itemnum[0]);
	AddMenuItem(menu, "item0", line);

	Format(line, sizeof(line), "近战武器(总数:%d 手续费:200$)", itemnum[1]);
	AddMenuItem(menu, "item1", line);	

	Format(line, sizeof(line), "投掷武器(总数:%d)", itemnum[2]);
	AddMenuItem(menu, "item2", line);	
	
	Format(line, sizeof(line), "药物物品(总数:%d)", itemnum[3]);
	AddMenuItem(menu, "item3", line);	

	Format(line, sizeof(line), "其他物品(总数:%d)", itemnum[4]);
	AddMenuItem(menu, "item4", line);	
	
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
}

public MenuHandler_GetBag(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param == MenuCancel_ExitBack)
			MenuFunc_IBag(Client);
	}
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 0: MenuFunc_Bag_Gun(Client); //提取枪械武器
			case 1: MenuFunc_Bag_Melee(Client); //提取近战武器
			case 2: MenuFunc_Bag_Bomb(Client); //提取投掷武器
			case 3: MenuFunc_Bag_Medic(Client); //提取药物物品
			case 4: MenuFunc_Bag_Other(Client); //提取其他物品
		}
	}
}


//背包扩充
public BuyBag(Client)
{
	new n_BagCost;
	if (BAGCOST[Client] >= 1000)
		n_BagCost = buybagcost + BAGCOST[Client];
	else
		n_BagCost = buybagcost;
		
	if (Cash[Client] >= n_BagCost)
	{
		Cash[Client] -= n_BagCost;
		I_BagSize[Client] += 1;
		PrintHintText(Client, "购买成功,你的背包已经扩充了一个位置!");
	}
	else
		PrintHintText(Client, "你的金钱不足,无法购买!");
}


//保存物品
public MenuFunc_SaveBag(Client)
{
	
	new Handle:menu = CreateMenu(MenuHandler_SaveBag);
	decl String:line[64];
	new bagnum = I_BagSize[Client] - GetClientBagSize(Client);
	Format(line, sizeof(line), "存入物品(剩余空间:%d)", bagnum);
	SetMenuTitle(menu, line);

	Format(line, sizeof(line), "存入枪械武器");
	AddMenuItem(menu, "item0", line);

	Format(line, sizeof(line), "存入近战武器");
	AddMenuItem(menu, "item1", line);	

	Format(line, sizeof(line), "存入投掷武器");
	AddMenuItem(menu, "item2", line);	
	
	Format(line, sizeof(line), "存入药物物品");
	AddMenuItem(menu, "item3", line);	

	Format(line, sizeof(line), "存入其他物品");
	AddMenuItem(menu, "item4", line);	

	Format(line, sizeof(line), "存入全部物品");
	AddMenuItem(menu, "item5", line);		
	
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
}

public MenuHandler_SaveBag(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param == MenuCancel_ExitBack)
			MenuFunc_IBag(Client);
	}
	if(action == MenuAction_Select)
	{
		new size = GetClientBagSize(Client);
		if (size >= I_BagSize[Client])
		{
			PrintHintText(Client, "你的背包已满,无法再存入物品!");
			MenuFunc_SaveBag(Client);
			return;
		}
				
		if (param < 5)
		{
			new type = CheckWeaponBag(Client, param);
			new bagnum = I_BagSize[Client] - GetClientBagSize(Client);
			if (type >= 0)
			{
				new String:name[64];
				if (param == 0)
					Format(name, sizeof(name), "%s", Bag_DisGunName[type]);
				else if (param == 1)
					Format(name, sizeof(name), "%s", Bag_DisMeleeName[type]);
				else if (param == 2)
					Format(name, sizeof(name), "%s", Bag_DisBombName[type]);
				else if (param == 3)
					Format(name, sizeof(name), "%s", Bag_DisMedicName[type]);
				else if (param == 4)
					Format(name, sizeof(name), "%s", Bag_DisOtherName[type]);
				
				CPrintToChat(Client, "\x03[系统]{green}物品: \x03%s {green}保存成功!剩余 \x03%d {green}个背包位置.", name, bagnum);
				CPrintToChatAll("\x03[背包] \x03%N {olive}将手中的 \x03%s {olive}存进了自己的包内!", Client, name);
			}
			else
				PrintHintText(Client, "物品保存失败,可能该物品无法被保存!");
		}
		else
		{
			new num;
			for(new i; i < 5; i++)
			{
				new type = CheckWeaponBag(Client, i);
				if (type > -1)
					num++;
			}
			
			if (num > 0)
			{
				new bagnum = I_BagSize[Client] - GetClientBagSize(Client);
				CPrintToChat(Client, "\x03[系统] \x03%d{green} 件物品保存成功!剩余 \x03%d {green}个背包位置.", num, bagnum);
				CPrintToChatAll("\x03[背包] \x03%N {olive}将手中的 \x03%d {olive}件物品存进了自己的包内!", Client, num);
			}
			else
				CPrintToChat(Client, "\x03[系统] \x03物品保存失败!当前身上没有有效的物品可以保存.");
		}
		
		MenuFunc_SaveBag(Client);
	}
}

//检查物品类型
public CheckWeaponBag(Client, WeaponSlot)
{
	if (!IsValidPlayer(Client) || IsFakeClient(Client))
		return -2;
	
	new weaponid = GetPlayerWeaponSlot(Client, WeaponSlot);
	new String:weaponname[64];
	new saveweapon = -1;
	if (weaponid > 0)
	{
		GetEdictClassname(weaponid, weaponname, sizeof(weaponname));
		if (WeaponSlot == 0)
		{
			//new clip = GetEntProp(weaponid, Prop_Send, "m_iClip1");
			//new ammo = GetEntData(Client, ammoOffset+(68));
			//PrintToChatAll("clip: %d ammo: %d", clip, ammo);
			for(new i; i < Bag_Size[BAG_GUN]; i++)
			{
				if (StrContains(weaponname, Bag_GunName[i], false) >= 0)
				{
					if (AddWeaponInBag(Client, BAG_GUN, i, weaponid) > 0)
						saveweapon = i;
					break;
				}
			}
		}
		else if (WeaponSlot == 1)
		{
			GetEntPropString(weaponid, Prop_Data, "m_ModelName", weaponname, sizeof(weaponname));
			for(new i; i < Bag_Size[BAG_MELEE]; i++)
			{
				if (StrContains(weaponname, Bag_MeleeName[i], false) >= 0)
				{
					if (AddWeaponInBag(Client, BAG_MELEE, i, weaponid) > 0)
						saveweapon = i;
					break;
				}
			}		
		}
		else if (WeaponSlot == 2)
		{
			for(new i; i < Bag_Size[BAG_BOMB]; i++)
			{
				if (StrContains(weaponname, Bag_BombName[i], false) >= 0)
				{
					if (AddWeaponInBag(Client, BAG_BOMB, i, weaponid) > 0)
						saveweapon = i;
					break;
				}
			}		
		}
		else if (WeaponSlot == 3)
		{
			for(new i; i < Bag_Size[BAG_MEDIC]; i++)
			{
				if (StrContains(weaponname, Bag_MedicName[i], false) >= 0)
				{
					if (AddWeaponInBag(Client, BAG_MEDIC, i, weaponid) > 0)
						saveweapon = i;
					break;
				}
			}		
		}
		else if (WeaponSlot == 4)
		{
			for(new i; i < Bag_Size[BAG_OTHER]; i++)
			{
				if (StrContains(weaponname, Bag_OtherName[i], false) >= 0)
				{
					if (AddWeaponInBag(Client, BAG_OTHER, i, weaponid) > 0)
						saveweapon = i;
					break;
				}
			}		
		}
	}
	
	if (saveweapon >= 0)
		return saveweapon;
	else
		return -1;
}

//保存物品数据
public AddWeaponInBag(Client, WeaponType, WeaponNum, id)
{
	new size = GetClientBagSize(Client);
	if (size >= I_BagSize[Client])
		return 0;
	
	I_Bag[Client][WeaponType][WeaponNum] += 1;
	RemoveEdict(id);
	if (WeaponType == BAG_MELEE)
		CheatCommand(Client, "give", "pistol");
		
	return 1;
}

//获取玩家背包物品总数
public GetClientBagSize(Client)
{	
	new size;
	
	for (new i; i < Bag_Size[BAG_GUN]; i++)
	{
		size += I_Bag[Client][BAG_GUN][i];
	}
	for (new i; i < Bag_Size[BAG_MELEE]; i++)
	{
		size += I_Bag[Client][BAG_MELEE][i];
	}
	for (new i; i < Bag_Size[BAG_BOMB]; i++)
	{
		size += I_Bag[Client][BAG_BOMB][i];
	}
	for (new i; i < Bag_Size[BAG_MEDIC]; i++)
	{
		size += I_Bag[Client][BAG_MEDIC][i];
	}
	for (new i; i < Bag_Size[BAG_OTHER]; i++)
	{
		size += I_Bag[Client][BAG_OTHER][i];
	}
	
	return size;
}

//获取玩家物品数量
public GetClientBagWeapon(Client, WeaponType)
{	
	new size;
	
	for (new i; i < Bag_Size[WeaponType]; i++)
		size += I_Bag[Client][WeaponType][i];

	return size;
}

//枪械武器提取
public MenuFunc_Bag_Gun(Client)
{
	new Handle:menu = CreateMenu(MenuHandler_Bag_Gun);
	decl String:line[256], String:info[256];

	SetMenuTitle(menu, "我的背包(手续费:200$):");
	for (new i; i < Bag_Size[BAG_GUN]; i++)
	{
		Format(line, sizeof(line), "%s(数量:%d)", Bag_DisGunName[i], I_Bag[Client][BAG_GUN][i]);
		Format(info, sizeof(info), "%s", Bag_GunName[i]);
		AddMenuItem(menu, info, line);	
	}
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
}

public MenuHandler_Bag_Gun(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param == MenuCancel_ExitBack)
			MenuFunc_IBag(Client);
	}
	if(action == MenuAction_Select)
	{
		
		if (I_Bag[Client][BAG_GUN][param] > 0)
		{
			if (Cash[Client] >= 200)
			{
				new String:info[64];
				GetMenuItem(menu, param, info, sizeof(info));
				CheatCommand(Client, "give", info);
				I_Bag[Client][BAG_GUN][param] -= 1;
				Cash[Client] -= 200;
				CPrintToChatAll("\x03[背包] {red}%N {olive}从背包内拿出了 \x03%s {olive}花费 \x03-200$", Client, Bag_DisGunName[param]);
			}
			else
				PrintHintText(Client, "你没有足够的金钱提取武器,提取枪械武器(装满子弹)需要200金钱手续费!");
		}
		else
			PrintHintText(Client, "你背包内没有该物品!");
			
		MenuFunc_Bag_Gun(Client);
	}
}

//近战武器提取
public MenuFunc_Bag_Melee(Client)
{
	new Handle:menu = CreateMenu(MenuHandler_Bag_Melee);
	decl String:line[256], String:info[256];

	SetMenuTitle(menu, "我的背包(手续费:200$):");
	for (new i; i < Bag_Size[BAG_MELEE]; i++)
	{
		Format(line, sizeof(line), "%s(数量:%d)", Bag_DisMeleeName[i], I_Bag[Client][BAG_MELEE][i]);
		Format(info, sizeof(info), "%s", Bag_MeleeName[i]);
		AddMenuItem(menu, info, line);	
	}
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
}

public MenuHandler_Bag_Melee(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param == MenuCancel_ExitBack)
			MenuFunc_IBag(Client);
	}
	if(action == MenuAction_Select)
	{		
		if (I_Bag[Client][BAG_MELEE][param] > 0)
		{
			if (Cash[Client] >= 200)
			{
				new String:info[64];
				GetMenuItem(menu, param, info, sizeof(info));
				CheatCommand(Client, "give", info);
				I_Bag[Client][BAG_MELEE][param] -= 1;
				Cash[Client] -= 200;
				CPrintToChatAll("\x03[背包] {red}%N {olive}从背包内拿出了 \x03%s  {olive}花费 \x03200$", Client, Bag_DisMeleeName[param]);
			}
			else
				PrintHintText(Client, "你没有足够的金钱提取武器,提取近战武器(回满耐久)需要200$手续费!");	
		}
		else
			PrintHintText(Client, "你背包内没有该物品!");
	
		MenuFunc_Bag_Melee(Client);
	}
}


//投掷武器提取
public MenuFunc_Bag_Bomb(Client)
{
	new Handle:menu = CreateMenu(MenuHandler_Bag_Bomb);
	decl String:line[256], String:info[256];

	SetMenuTitle(menu, "我的背包:");
	for (new i; i < Bag_Size[BAG_BOMB]; i++)
	{
		Format(line, sizeof(line), "%s(数量:%d)", Bag_DisBombName[i], I_Bag[Client][BAG_BOMB][i]);
		Format(info, sizeof(info), "%s", Bag_BombName[i]);
		AddMenuItem(menu, info, line);	
	}
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
}

public MenuHandler_Bag_Bomb(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param == MenuCancel_ExitBack)
			MenuFunc_IBag(Client);
	}
	if(action == MenuAction_Select)
	{

		if (I_Bag[Client][BAG_BOMB][param] > 0)
		{
			new String:info[64];
			GetMenuItem(menu, param, info, sizeof(info));
			CheatCommand(Client, "give", info);
			I_Bag[Client][BAG_BOMB][param] -= 1;
			CPrintToChatAll("\x03[背包] \x03%N {olive}从背包内拿出了 \x03%s", Client, Bag_DisBombName[param]);
		}
		else
			PrintHintText(Client, "你背包内没有该物品!");
	
		MenuFunc_Bag_Bomb(Client);
	}
}


//药物物品提取
public MenuFunc_Bag_Medic(Client)
{
	new Handle:menu = CreateMenu(MenuHandler_Bag_Medic);
	decl String:line[256], String:info[256];

	SetMenuTitle(menu, "我的背包:");
	for (new i; i < Bag_Size[BAG_MEDIC]; i++)
	{
		Format(line, sizeof(line), "%s(数量:%d)", Bag_DisMedicName[i], I_Bag[Client][BAG_MEDIC][i]);
		Format(info, sizeof(info), "%s", Bag_MedicName[i]);
		AddMenuItem(menu, info, line);	
	}
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
}

public MenuHandler_Bag_Medic(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param == MenuCancel_ExitBack)
			MenuFunc_IBag(Client);
	}
	if(action == MenuAction_Select)
	{

		if (I_Bag[Client][BAG_MEDIC][param] > 0)
		{
			new String:info[64];
			GetMenuItem(menu, param, info, sizeof(info));
			CheatCommand(Client, "give", info);
			I_Bag[Client][BAG_MEDIC][param] -= 1;
			CPrintToChatAll("\x03[背包] {red}%N {olive}从背包内拿出了 \x03%s", Client, Bag_DisMedicName[param]);
		}
		else
			PrintHintText(Client, "你背包内没有该物品!");
	
		MenuFunc_Bag_Medic(Client);
	}
}



//其他物品提取
public MenuFunc_Bag_Other(Client)
{
	new Handle:menu = CreateMenu(MenuHandler_Bag_Other);
	decl String:line[256], String:info[256];

	SetMenuTitle(menu, "我的背包:");
	for (new i; i < Bag_Size[BAG_OTHER]; i++)
	{
		Format(line, sizeof(line), "%s(数量:%d)", Bag_DisOtherName[i], I_Bag[Client][BAG_OTHER][i]);
		Format(info, sizeof(info), "%s", Bag_OtherName[i]);
		AddMenuItem(menu, info, line);	
	}
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);	
}

public MenuHandler_Bag_Other(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_End)	
		CloseHandle(menu);
	else if (action == MenuAction_Cancel)
	{
		if (param == MenuCancel_ExitBack)
			MenuFunc_IBag(Client);
	}
	if(action == MenuAction_Select)
	{

		if (I_Bag[Client][BAG_OTHER][param] > 0)
		{
			new String:info[64];
			GetMenuItem(menu, param, info, sizeof(info));
			CheatCommand(Client, "give", info);
			I_Bag[Client][BAG_OTHER][param] -= 1;
			CPrintToChatAll("\x03[背包] {red}%N {olive}从背包内拿出了 \x03%s", Client, Bag_DisOtherName[param]);
		}
		else
			PrintHintText(Client, "你背包内没有该物品!");
	
		MenuFunc_Bag_Other(Client);
	}
}