/**********************************************************************
   荣誉称号系统
 *****************************************************************/
public Action:MenuFunc_RYCH(Client)
{ 
	new Handle:menu = CreatePanel();
	
	decl String:WDCH[16];	   
	if(BJCH[Client] == 0)			Format(WDCH, sizeof(WDCH), "未获得");   
	else if(BJCH[Client] == 1)	    Format(WDCH, sizeof(WDCH), "坦克杀手");
	else if(BJCH[Client] == 2)	    Format(WDCH, sizeof(WDCH), "僵尸猎手");	
	else if(BJCH[Client] == 3)	    Format(WDCH, sizeof(WDCH), "拒绝乘骑");	
	else if(BJCH[Client] == 4)	    Format(WDCH, sizeof(WDCH), "文明者");
	else if(BJCH[Client] == 5)	    Format(WDCH, sizeof(WDCH), "瘦身教练");
	else if(BJCH[Client] == 6)	    Format(WDCH, sizeof(WDCH), "执法者");
	else if(BJCH[Client] == 7)	    Format(WDCH, sizeof(WDCH), "哭泣杀手");
	else if(BJCH[Client] == 8)	    Format(WDCH, sizeof(WDCH), "救助者");
	else if(BJCH[Client] == 9)	    Format(WDCH, sizeof(WDCH), "好队友");
	else if(BJCH[Client] == 10)	    Format(WDCH, sizeof(WDCH), "强化好手");
	else if(BJCH[Client] == 11)	    Format(WDCH, sizeof(WDCH), "百折不挠");	
	else if(BJCH[Client] == 12)	    Format(WDCH, sizeof(WDCH), "拒绝吸烟");	
	
	  
	decl String:line[256];   
	Format(line, sizeof(line),    
	"================荣誉称号:当前称号[%s]============= \n 当前系统总称号[12个] \n===============================", WDCH);    
	SetPanelTitle(menu, line);	
	
	Format(line, sizeof(line), "装备称号");  
	DrawPanelItem(menu, line);

	Format(line, sizeof(line), "卸下称号");  
	DrawPanelItem(menu, line);

	Format(line, sizeof(line), "称号获取方式");  
	DrawPanelItem(menu, line);		
	
	DrawPanelItem(menu, "返回RPG选单");   
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);
    
	SendPanelToClient(menu, Client, MenuHandler_RYCH, MENU_TIME_FOREVER);     
	return Plugin_Handled;
}

public MenuHandler_RYCH(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{		
			case 1: MenuFunc_ZBCH(Client);
			case 2: MenuFunc_XXCH(Client);
			case 3: MenuFunc_CHHQFS(Client);			
			case 4: MenuFunc_RPG(Client);				
		}
	}
}

/* 称号系统介绍 */
public Action:MenuFunc_CHHQFS(Client)
{
    new Handle:menu = CreatePanel();
	
    decl String:line[1024];	
    Format(line, sizeof(line), "===========称号介绍================");
    SetPanelTitle(menu, line);
    Format(line, sizeof(line), "坦克杀手:击杀坦克1000只你当前击杀:%d只", TKSL[Client]);
    DrawPanelText(menu, line);
	
    Format(line, sizeof(line), "僵尸猎手:击杀普通僵尸100000只你当前击杀:%d只", XGSL[Client]);
    DrawPanelText(menu, line);

    Format(line, sizeof(line), "拒绝乘骑:击杀猴子1000只你当前击杀:%d只", HZSL[Client]);
    DrawPanelText(menu, line);

    Format(line, sizeof(line), "文明者:击杀口水婆1000只你当前击杀:%d只", PPSL[Client]);
    DrawPanelText(menu, line);	
	
    DrawPanelItem(menu, "下一页");
    DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

    SendPanelToClient(menu, Client, MenuHandler_CHHQFS, MENU_TIME_FOREVER);
    return Plugin_Handled;
}
public MenuHandler_CHHQFS(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: MenuFunc_CHHQFS2(Client);
			case 2: MenuFunc_RYCH(Client);			
		}
	}
}

public Action:MenuFunc_CHHQFS2(Client)
{
    new Handle:menu = CreatePanel();
	
    decl String:line[1024];	
    Format(line, sizeof(line), "===========称号介绍================");
    SetPanelTitle(menu, line);
    Format(line, sizeof(line), "瘦身教练:击杀胖子1000只你当前击杀:%d只", PZSL[Client]);
    DrawPanelText(menu, line);
	
    Format(line, sizeof(line), "执法者:击杀冲撞者1000只你当前击杀:%d只", DXSL[Client]);
    DrawPanelText(menu, line);	
	
    Format(line, sizeof(line), "哭泣杀手:击杀女巫500只你当前击杀:%d只", NWSL[Client]);
    DrawPanelText(menu, line);

    Format(line, sizeof(line), "救助者:复活队友1000次你当前复活:%d次", DRSL[Client]);
    DrawPanelText(menu, line);		
	
    DrawPanelItem(menu, "下一页");
    DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

    SendPanelToClient(menu, Client, MenuHandler_CHHQFS2, MENU_TIME_FOREVER);
    return Plugin_Handled;
}
public MenuHandler_CHHQFS2(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: MenuFunc_CHHQFS3(Client);		
		}
	}
}

public Action:MenuFunc_CHHQFS3(Client)
{
    new Handle:menu = CreatePanel();
	
    decl String:line[1024];	
    Format(line, sizeof(line), "===========称号介绍================");
    SetPanelTitle(menu, line);
    Format(line, sizeof(line), "好队友:拉起队友10000次你当前拉起:%d次", BRSL[Client]);
    DrawPanelText(menu, line);
	
    Format(line, sizeof(line), "强化好手:强化武器成功100次你当前成功:%d次", QHSL[Client]);
    DrawPanelText(menu, line);	
	
    Format(line, sizeof(line), "百折不挠:强化失败3000次你当前失败:%d次", Sxcs[Client]);
    DrawPanelText(menu, line);

    Format(line, sizeof(line), "拒绝吸烟:击杀烟鬼1000只你当前击杀:%d只", YGSL[Client]);
    DrawPanelText(menu, line);	
	
    DrawPanelItem(menu, "返回称号菜单");
    DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

    SendPanelToClient(menu, Client, MenuHandler_CHHQFS3, MENU_TIME_FOREVER);
    return Plugin_Handled;
}
public MenuHandler_CHHQFS3(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: MenuFunc_RYCH(Client);			
		}
	}
}

public Action:MenuFunc_XXCH(Client)
{
	new Handle:menu = CreatePanel();		

	decl String:WDCHE[16];	   
	if(BJCH[Client] == 0)			Format(WDCHE, sizeof(WDCHE), "未获得");   
	else if(BJCH[Client] == 1)	    Format(WDCHE, sizeof(WDCHE), "坦克杀手");
	else if(BJCH[Client] == 2)	    Format(WDCHE, sizeof(WDCHE), "僵尸猎手");	
	else if(BJCH[Client] == 3)	    Format(WDCHE, sizeof(WDCHE), "拒绝乘骑");	
	else if(BJCH[Client] == 4)	    Format(WDCHE, sizeof(WDCHE), "文明者");
	else if(BJCH[Client] == 5)	    Format(WDCHE, sizeof(WDCHE), "瘦身教练");
	else if(BJCH[Client] == 6)	    Format(WDCHE, sizeof(WDCHE), "执法者");
	else if(BJCH[Client] == 7)	    Format(WDCHE, sizeof(WDCHE), "哭泣杀手");
	else if(BJCH[Client] == 8)	    Format(WDCHE, sizeof(WDCHE), "救助者");
	else if(BJCH[Client] == 9)	    Format(WDCHE, sizeof(WDCHE), "好队友");
	else if(BJCH[Client] == 10)	    Format(WDCHE, sizeof(WDCHE), "强化好手");
	else if(BJCH[Client] == 11)	    Format(WDCHE, sizeof(WDCHE), "百折不挠");	
	else if(BJCH[Client] == 12)	    Format(WDCHE, sizeof(WDCHE), "拒绝吸烟");		
	
	decl String:line[256];   
	Format(line, sizeof (line), "═════════卸下称号════════════");    
	SetPanelTitle(menu, line);  
	
	Format(line, sizeof (line), "装备的称号:[%s]", WDCHE);   
	DrawPanelItem(menu, line);
	
	DrawPanelItem(menu, "返回称号系统");  
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);
  
	SendPanelToClient(menu, Client, MenuHandler_XXCH, MENU_TIME_FOREVER);   
	return Plugin_Handled;
}
public MenuHandler_XXCH(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1:XXCH1(Client);			
			case 2:MenuFunc_RYCH(Client);
		}
	}
}

public XXCH1(Client)
{   
	if(BJCH[Client] >= 1)    
	{	    
		if(BJCH[Client] == 1)        
		{            
			TKSLZ[Client] = 1; 	
		} 
		else if(BJCH[Client] == 2)        
		{            
			XGSLZ[Client] = 1; 	
		}
		else if(BJCH[Client] == 3)        
		{            
			HZSLZ[Client] = 1; 	
		}
		else if(BJCH[Client] == 4)        
		{            
			PPSLZ[Client] = 1; 	
		}	
		else if(BJCH[Client] == 5)        
		{            
			PZSLZ[Client] = 1; 	
		}	
		else if(BJCH[Client] == 6)        
		{            
			DXSLZ[Client] = 1; 	
		}	
		else if(BJCH[Client] == 7)        
		{            
			NWSLZ[Client] = 1; 	
		}
		else if(BJCH[Client] == 8)        
		{            
			DRSLZ[Client] = 1; 	
		}
		else if(BJCH[Client] == 9)        
		{            
			BRSLZ[Client] = 1; 	
		}
		else if(BJCH[Client] == 10)        
		{            
			QHHSZ[Client] = 1; 	
		}
		else if(BJCH[Client] == 11)        
		{            
			BZBNZ[Client] = 1; 	
		}
		else if(BJCH[Client] == 12)        
		{            
			YGSLZ[Client] = 1; 	
		}		
		BJCH[Client] = 0;		
	} else PrintHintText(Client, "你没有装备任何称号!");	
}

//使用称号
public Action:MenuFunc_ZBCH(Client)
{
	new Handle:menu = CreatePanel();
	
	decl String:ZBCH1S[16];	   
	if(TKSLZ[Client] == 0)			Format(ZBCH1S, sizeof(ZBCH1S), "未获取");   
	else if(TKSLZ[Client] == 1)	    Format(ZBCH1S, sizeof(ZBCH1S), "坦克杀手");	
	
	decl String:ZBCH2S[16];	   
	if(XGSLZ[Client] == 0)			Format(ZBCH2S, sizeof(ZBCH2S), "未获取");   
	else if(XGSLZ[Client] == 1)	    Format(ZBCH2S, sizeof(ZBCH2S), "僵尸猎手");	

	decl String:ZBCH3S[16];	   
	if(HZSLZ[Client] == 0)			Format(ZBCH3S, sizeof(ZBCH3S), "未获取");   
	else if(HZSLZ[Client] == 1)	    Format(ZBCH3S, sizeof(ZBCH3S), "拒绝乘骑");

	decl String:ZBCH4S[16];	   
	if(PPSLZ[Client] == 0)			Format(ZBCH4S, sizeof(ZBCH4S), "未获取");   
	else if(PPSLZ[Client] == 1)	    Format(ZBCH4S, sizeof(ZBCH4S), "文明者");

	decl String:ZBCH5S[16];	   
	if(PZSLZ[Client] == 0)			Format(ZBCH5S, sizeof(ZBCH5S), "未获取");   
	else if(PZSLZ[Client] == 1)	    Format(ZBCH5S, sizeof(ZBCH5S), "瘦身教练");	
	
	decl String:ZBCH6S[16];	   
	if(DXSLZ[Client] == 0)			Format(ZBCH6S, sizeof(ZBCH6S), "未获取");   
	else if(DXSLZ[Client] == 1)	    Format(ZBCH6S, sizeof(ZBCH6S), "执法者");

	decl String:ZBCH7S[16];	   
	if(NWSLZ[Client] == 0)			Format(ZBCH7S, sizeof(ZBCH7S), "未获取");   
	else if(NWSLZ[Client] == 1)	    Format(ZBCH7S, sizeof(ZBCH7S), "哭泣杀手");			

	decl String:WDCHA[16];	   
	if(BJCH[Client] == 0)			Format(WDCHA, sizeof(WDCHA), "未获得");   
	else if(BJCH[Client] == 1)	    Format(WDCHA, sizeof(WDCHA), "坦克杀手");
	else if(BJCH[Client] == 2)	    Format(WDCHA, sizeof(WDCHA), "僵尸猎手");	
	else if(BJCH[Client] == 3)	    Format(WDCHA, sizeof(WDCHA), "拒绝乘骑");	
	else if(BJCH[Client] == 4)	    Format(WDCHA, sizeof(WDCHA), "文明者");
	else if(BJCH[Client] == 5)	    Format(WDCHA, sizeof(WDCHA), "瘦身教练");
	else if(BJCH[Client] == 6)	    Format(WDCHA, sizeof(WDCHA), "执法者");
	else if(BJCH[Client] == 7)	    Format(WDCHA, sizeof(WDCHA), "哭泣杀手");
	else if(BJCH[Client] == 8)	    Format(WDCHA, sizeof(WDCHA), "救助者");
	else if(BJCH[Client] == 9)	    Format(WDCHA, sizeof(WDCHA), "好队友");
	else if(BJCH[Client] == 10)	    Format(WDCHA, sizeof(WDCHA), "强化好手");
	else if(BJCH[Client] == 11)	    Format(WDCHA, sizeof(WDCHA), "百折不挠");	
	else if(BJCH[Client] == 12)	    Format(WDCHA, sizeof(WDCHA), "拒绝吸烟");		
	  
	decl String:line[256];   
	Format(line, sizeof(line),    
	"================荣誉称号:当前称号[%s]================== \n 当前系统总称号[12个] \n=========================================", WDCHA);    
	SetPanelTitle(menu, line);
	
	Format(line, sizeof (line), "%s", ZBCH1S);   
	DrawPanelItem(menu, line);
	
	Format(line, sizeof (line), "%s", ZBCH2S);  
	DrawPanelItem(menu, line); 
	
	Format(line, sizeof (line), "%s", ZBCH3S);  
	DrawPanelItem(menu, line); 
	
	Format(line, sizeof (line), "%s", ZBCH4S);   
	DrawPanelItem(menu, line);
	
	Format(line, sizeof (line), "%s", ZBCH5S);  
	DrawPanelItem(menu, line);
	
	Format(line, sizeof (line), "%s", ZBCH6S);  
	DrawPanelItem(menu, line); 

	Format(line, sizeof (line), "%s", ZBCH7S);  
	DrawPanelItem(menu, line); 

	Format(line, sizeof (line), "下一页");  
	DrawPanelItem(menu, line); 	
 	
	DrawPanelItem(menu, "返回称号系统");  
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);
  
	SendPanelToClient(menu, Client, MenuHandler_ZBCH, MENU_TIME_FOREVER);   
	return Plugin_Handled;
}
public MenuHandler_ZBCH(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1:ZBCH1(Client);
            case 2:ZBCH2(Client);
			case 3:ZBCH3(Client);
            case 4:ZBCH4(Client);
            case 5:ZBCH5(Client);
            case 6:ZBCH6(Client);
            case 7:ZBCH7(Client);
			case 8:MenuFunc_ZBCH2(Client);			
			case 9:MenuFunc_RYCH(Client);
		}
	}
}
public ZBCH1(Client)
{   
	if(BJCH[Client] == 0)    
	{	    
		if(TKSLZ[Client] == 1)        
		{            
			BJCH[Client] = 1 	
			TKSLZ[Client] = 0
		} 	
	} else PrintHintText(Client, "你已经装备了称号!");	
}

public ZBCH2(Client)
{   
	if(BJCH[Client] == 0)    
	{	    
		if(XGSLZ[Client] == 1)        
		{            
			BJCH[Client] = 2 	
			XGSLZ[Client] = 0
		} 	
	} else PrintHintText(Client, "你已经装备了称号!");	
}

public ZBCH3(Client)
{   
	if(BJCH[Client] == 0)    
	{	    
		if(HZSLZ[Client] == 1)        
		{            
			BJCH[Client] = 3 	
			HZSLZ[Client] = 0
		} 	
	} else PrintHintText(Client, "你已经装备了称号!");	
}

public ZBCH4(Client)
{   
	if(BJCH[Client] == 0)    
	{	    
		if(PPSLZ[Client] == 1)        
		{            
			BJCH[Client] = 4 	
			PPSLZ[Client] = 0
		} 	
	} else PrintHintText(Client, "你已经装备了称号!");	
}

public ZBCH5(Client)
{   
	if(BJCH[Client] == 0)    
	{	    
		if(PZSLZ[Client] == 1)        
		{            
			BJCH[Client] = 5 	
			PZSLZ[Client] = 0
		} 	
	} else PrintHintText(Client, "你已经装备了称号!");	
}

public ZBCH6(Client)
{   
	if(BJCH[Client] == 0)    
	{	    
		if(DXSLZ[Client] == 1)        
		{            
			BJCH[Client] = 6 	
			DXSLZ[Client] = 0
		} 	
	} else PrintHintText(Client, "你已经装备了称号!");	
}

public ZBCH7(Client)
{   
	if(BJCH[Client] == 0)    
	{	    
		if(NWSLZ[Client] == 1)        
		{            
			BJCH[Client] = 7	
			NWSLZ[Client] = 0
		} 	
	} else PrintHintText(Client, "你已经装备了称号!");	
}


//使用称号
public Action:MenuFunc_ZBCH2(Client)
{
	new Handle:menu = CreatePanel();
	
	decl String:ZBCH8S[16];	   
	if(DRSLZ[Client] == 0)			Format(ZBCH8S, sizeof(ZBCH8S), "未获取");   
	else if(DRSLZ[Client] == 1)	    Format(ZBCH8S, sizeof(ZBCH8S), "救助者");

	decl String:ZBCH9S[16];	   
	if(BRSLZ[Client] == 0)			Format(ZBCH9S, sizeof(ZBCH9S), "未获取");   
	else if(BRSLZ[Client] == 1)	    Format(ZBCH9S, sizeof(ZBCH9S), "好队友");

	decl String:ZBCH10S[16];	   
	if(QHHSZ[Client] == 0)			Format(ZBCH10S, sizeof(ZBCH10S), "未获取");   
	else if(QHHSZ[Client] == 1)	    Format(ZBCH10S, sizeof(ZBCH10S), "强化好手");

	decl String:ZBCH11S[16];	   
	if(BZBNZ[Client] == 0)			Format(ZBCH11S, sizeof(ZBCH11S), "未获取");   
	else if(BZBNZ[Client] == 1)	    Format(ZBCH11S, sizeof(ZBCH11S), "百折不挠");

	decl String:ZBCH12S[16];	   
	if(YGSLZ[Client] == 0)			Format(ZBCH12S, sizeof(ZBCH12S), "未获取");   
	else if(YGSLZ[Client] == 1)	    Format(ZBCH12S, sizeof(ZBCH12S), "拒绝吸烟");	
	  
	decl String:WDCHS[16];	   
	if(BJCH[Client] == 0)			Format(WDCHS, sizeof(WDCHS), "未获得");   
	else if(BJCH[Client] == 1)	    Format(WDCHS, sizeof(WDCHS), "坦克杀手");
	else if(BJCH[Client] == 2)	    Format(WDCHS, sizeof(WDCHS), "僵尸猎手");	
	else if(BJCH[Client] == 3)	    Format(WDCHS, sizeof(WDCHS), "拒绝乘骑");	
	else if(BJCH[Client] == 4)	    Format(WDCHS, sizeof(WDCHS), "文明者");
	else if(BJCH[Client] == 5)	    Format(WDCHS, sizeof(WDCHS), "瘦身教练");
	else if(BJCH[Client] == 6)	    Format(WDCHS, sizeof(WDCHS), "执法者");
	else if(BJCH[Client] == 7)	    Format(WDCHS, sizeof(WDCHS), "哭泣杀手");
	else if(BJCH[Client] == 8)	    Format(WDCHS, sizeof(WDCHS), "救助者");
	else if(BJCH[Client] == 9)	    Format(WDCHS, sizeof(WDCHS), "好队友");
	else if(BJCH[Client] == 10)	    Format(WDCHS, sizeof(WDCHS), "强化好手");
	else if(BJCH[Client] == 11)	    Format(WDCHS, sizeof(WDCHS), "百折不挠");	
	else if(BJCH[Client] == 12)	    Format(WDCHS, sizeof(WDCHS), "拒绝吸烟");		  
	  
	decl String:line[256];   
	Format(line, sizeof(line),    
	"================荣誉称号:当前称号[%s]================== \n 当前系统总称号[12个] \n=========================================", WDCHS);    
	SetPanelTitle(menu, line);
	
	Format(line, sizeof (line), "%s", ZBCH8S);   
	DrawPanelItem(menu, line);
	
	Format(line, sizeof (line), "%s", ZBCH9S);  
	DrawPanelItem(menu, line); 
	
	Format(line, sizeof (line), "%s", ZBCH10S);  
	DrawPanelItem(menu, line); 
	
	Format(line, sizeof (line), "%s", ZBCH11S);   
	DrawPanelItem(menu, line);
	
	Format(line, sizeof (line), "%s", ZBCH12S);  
	DrawPanelItem(menu, line);

	Format(line, sizeof (line), "上一页");  
	DrawPanelItem(menu, line); 	
 	
	DrawPanelItem(menu, "返回称号系统");  
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);
  
	SendPanelToClient(menu, Client, MenuHandler_ZBCH2, MENU_TIME_FOREVER);   
	return Plugin_Handled;
}
public MenuHandler_ZBCH2(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch(param)
		{
			case 1:ZBCH8(Client);
            case 2:ZBCH9(Client);
			case 3:ZBCH10(Client);
            case 4:ZBCH11(Client);
            case 5:ZBCH12(Client);
			case 6:MenuFunc_ZBCH(Client);			
			case 7:MenuFunc_RYCH(Client);
		}
	}
}

public ZBCH8(Client)
{   
	if(BJCH[Client] == 0)    
	{	    
		if(DRSLZ[Client] == 1)        
		{            
			BJCH[Client] = 8	
			DRSLZ[Client] = 0
		} 	
	} else PrintHintText(Client, "你已经装备了称号!");	
}

public ZBCH9(Client)
{   
	if(BJCH[Client] == 0)    
	{	    
		if(BRSLZ[Client] == 1)        
		{            
			BJCH[Client] = 9	
			BRSLZ[Client] = 0
		} 	
	} else PrintHintText(Client, "你已经装备了称号!");	
}
public ZBCH10(Client)
{   
	if(BJCH[Client] == 0)    
	{	    
		if(QHHSZ[Client] == 1)        
		{            
			BJCH[Client] = 10	
			QHHSZ[Client] = 0
		} 	
	} else PrintHintText(Client, "你已经装备了称号!");	
}

public ZBCH11(Client)
{   
	if(BJCH[Client] == 0)    
	{	    
		if(NWSLZ[Client] == 1)        
		{            
			BJCH[Client] = 11	
			BZBNZ[Client] = 0
		} 	
	} else PrintHintText(Client, "你已经装备了称号!");	
}

public ZBCH12(Client)
{   
	if(BJCH[Client] == 0)    
	{	    
		if(YGSLZ[Client] == 1)        
		{            
			BJCH[Client] = 12	
			YGSLZ[Client] = 0
		} 	
	} else PrintHintText(Client, "你已经装备了称号!");	
}





