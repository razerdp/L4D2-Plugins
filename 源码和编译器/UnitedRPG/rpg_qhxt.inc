
public Action:MenuFunc_psdx(Client)
{
	decl String:line[128];
	new Handle:menu = CreatePanel();
	Format(line, sizeof(line), "══════════════════");
	SetPanelTitle(menu, line);

	Format(line, sizeof(line), "强化失败达到300次可领取补偿");
	DrawPanelText(menu, line);
	Format(line, sizeof(line), "══════════════════");
	DrawPanelText(menu, line);
	DrawPanelItem(menu, "领取");
	DrawPanelItem(menu, "返回");
	
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);
	SendPanelToClient(menu, Client, MenuHandler_psdx, MENU_TIME_FOREVER);
	CloseHandle(menu);
	return Plugin_Handled;
}

public MenuHandler_psdx(Handle:menu, MenuAction:action, Client, param)//基础菜单	
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: psdx(Client);
			case 2: MenuFunc_Qhcd(Client);
		}
	}
}

public psdx(Client)
{
    if(Sxcs[Client] >= 300)   
	{
	    Sxcs[Client] -= 300;
	    new Qhjl = GetRandomInt(1, 3);
		
	    switch (Qhjl)       
	    {    
		    case 1:           
			{               
	           Cash[Client] += 1000000;
	           BZBNZ[Client] = 1;				   
	           PrintHintTextToAll("[安抚]:玩家%N强化失败100次，获得安抚基金100万", Client);           
			}
			case 2:           
			{     
	           Lv[Client] += 15;
	           BZBNZ[Client] = 1;				
	           PrintHintTextToAll("[安抚]:玩家%N强化失败100次，获得等级15级", Client);           
			}
			case 3:           
			{    
	           Lv[Client] += 20;
	           BZBNZ[Client] = 1;				
	           PrintHintTextToAll("[安抚]:玩家%N强化失败100次，获得等级20级", Client);           
			}
	    }
    }else CPrintToChat(Client, "\x01[\x04安抚\x01]\x03：\x05破碎的心愿未达标");
        
}

//强化系统
public Action:MenuFunc_Qhqz(Client)
{
	new ak47 = 5 * AK47[Client] + DMG_AK47;
	new m60 =  5 * M60[Client] + DMG_M60;
	new m16 =  5 * M16[Client] + DMG_M16;
	new spas = 3 * PZ[Client] + DMG_SPAS;
	new awp = 12 * AWP[Client] + DMG_AWP;
	decl String:line[256];
	new Handle:menu = CreatePanel();
	Format(line, sizeof(line), "==============强化系统==========");
	SetPanelTitle(menu, line);
	Format(line, sizeof(line),"说明：强化金币5万[当前金币：%d]", Cash[Client]);
	DrawPanelText(menu, line);
	Format(line, sizeof(line),"物品：【强化石】目前拥有：%d个", Qhs[Client]);
	DrawPanelText(menu, line);
	Format(line, sizeof(line),"=================================");
	DrawPanelText(menu, line);
	
	Format(line, sizeof(line), "M16伤害强化【伤害%d】【强化LV%d】", m16, M16[Client]);
	DrawPanelItem(menu, line);
	
	Format(line, sizeof(line), "AK47伤害强化【伤害%d】【强化LV%d】", ak47, AK47[Client]);
	DrawPanelItem(menu, line);
	
	Format(line, sizeof(line), "AWP伤害强化【伤害%d】【强化LV%d】", awp, AWP[Client]);
	DrawPanelItem(menu, line);
	
	Format(line, sizeof(line), "喷子伤害强化【伤害%d】【强化LV%d】", spas, PZ[Client]);
	DrawPanelItem(menu, line);
	
	Format(line, sizeof(line), "M60伤害强化【伤害%d】【强化LV%d】", m60, M60[Client]);
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_Qhqz, MENU_TIME_FOREVER);

	CloseHandle(menu);

	return Plugin_Handled;
}
public MenuHandler_Qhqz(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select) {
		switch(param) {
			case 1:
			    if (Qhs[Client] > 0)
			    {  
			        qhm161(Client);
			    }else CPrintToChat(Client, "你没有强化石");
			case 2:
			    if (Qhs[Client] > 0)
			    {  
			        qhak471(Client);
			    }else CPrintToChat(Client, "你没有强化石");
			case 3:
			    if (Qhs[Client] > 0)
			    {  
			        qhawp1(Client);
			    }else CPrintToChat(Client, "你没有强化石");	
			case 4:
			    if (Qhs[Client] > 0)
			    {  
			        qhpz1(Client);
			    }else CPrintToChat(Client, "你没有强化石");
			case 5:
			    if (Qhs[Client] > 0)
			    {  
			        qhm601(Client);
			    }else CPrintToChat(Client, "你没有强化石");				
		}
	}
}

public qhm161(Client)
{
    if(Cash[Client] > 50000 && M16[Client] <= 20)   
	{
	    Cash[Client] -= 50000;
	    Qhs[Client] -= 1;
	    new Qhjl = GetRandomInt(1, 4);
		
	    switch (Qhjl)       
	    {    
		    case 1:           
			{               
	           M16[Client] ++;
	           QHSL[Client] ++;			   
	           CPrintToChatAll("\x01[\x03枪械强化\x01]\x05玩家\x04 %N \x03【强化LV%d】M16 \x05成功，\x04祝贺他吧", Client, M16[Client]);           
			}
			case 2:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 3:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 4:           
			{     
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
	    }
    }
    if(Cash[Client] > 80000 && M16[Client] > 20  && M16[Client] <= 40 && Qhs[Client] > 3)   
	{
	    Cash[Client] -= 80000;
	    Qhs[Client] -= 3;
	    new Qhjl = GetRandomInt(1, 5);
		
	    switch (Qhjl)       
	    {    
		    case 1:           
			{               
	           M16[Client] ++;
	           QHSL[Client] ++;			   
	           CPrintToChatAll("\x01[\x03枪械强化\x01]\x05玩家\x04 %N \x03【强化LV%d】M16 \x05成功，\x04祝贺他吧", Client, M16[Client]);           
			}
			case 2:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 3:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 4:           
			{     
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 5:           
			{     
				M16[Client] --;			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05悲剧，你掉了一级");           
			}
	    }
    }
    if(M16[Client] > 40)   
	{
	    CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05已达上限无法强化");
    }
    if(QHSL[Client] >= 100)   
	{
		QHHSZ[Client] = 1;	
		QHSL[Client] = 0;		
    }		
	else CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05金币不足或材料不足");
        
}

public qhak471(Client)
{
    if(Cash[Client] > 50000 && AK47[Client] <= 20)   
	{
	    Cash[Client] -= 50000;
	    Qhs[Client] -= 1;
	    new Qhjl = GetRandomInt(1, 4);
		
	    switch (Qhjl)       
	    {    
		    case 1:           
			{               
	           AK47[Client] ++;
	           QHSL[Client] ++;			   
	           CPrintToChatAll("\x01[\x03枪械强化\x01]\x05玩家\x04 %N \x03【强化LV%d】AK47 \x05成功，\x04祝贺他吧", Client, AK47[Client]);           
			}
			case 2:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 3:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 4:           
			{     
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
	    }
    }
    if(Cash[Client] > 80000 && AK47[Client] > 20  && AK47[Client] <= 40 && Qhs[Client] > 3)   
	{
	    Cash[Client] -= 80000;
	    Qhs[Client] -= 3;
	    new Qhjl = GetRandomInt(1, 5);
		
	    switch (Qhjl)       
	    {    
		    case 1:           
			{               
	           AK47[Client] ++;
	           QHSL[Client] ++;			   
	           CPrintToChatAll("\x01[\x03枪械强化\x01]\x05玩家\x04 %N \x03【强化LV%d】AK47 \x05成功，\x04祝贺他吧", Client, AK47[Client]);           
			}
			case 2:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 3:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 4:           
			{     
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 5:           
			{     
				AK47[Client] --;			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05悲剧，你掉了一级");           
			}
	    }
    }
    if(AK47[Client] > 40)   
	{
	    CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05已达上限无法强化");
    }
    if(QHSL[Client] >= 100)   
	{
		QHHSZ[Client] = 1;	
		QHSL[Client] = 0;		
    }		
	else CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05金币不足或材料不足");
        
}

public qhawp1(Client)
{
    if(Cash[Client] > 50000 && AWP[Client] <= 20)   
	{
	    Cash[Client] -= 50000;
	    Qhs[Client] -= 1;
	    new Qhjl = GetRandomInt(1, 4);
		
	    switch (Qhjl)       
	    {    
		    case 1:           
			{               
	           AWP[Client] ++;
	           QHSL[Client] ++;			   
	           CPrintToChatAll("\x01[\x03枪械强化\x01]\x05玩家\x04 %N \x03【强化LV%d】AWP \x05成功，\x04祝贺他吧", Client, AWP[Client]);          
			}
			case 2:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 3:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 4:           
			{     
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
	    }
    }
    if(Cash[Client] > 80000 && AWP[Client] > 20  && AWP[Client] <= 40 && Qhs[Client] > 3)   
	{
	    Cash[Client] -= 80000;
	    Qhs[Client] -= 3;
	    new Qhjl = GetRandomInt(1, 5);
		
	    switch (Qhjl)       
	    {    
		    case 1:           
			{               
	           AWP[Client] ++;
	           QHSL[Client] ++;			   
	           CPrintToChatAll("\x01[\x03枪械强化\x01]\x05玩家\x04 %N \x03【强化LV%d】AWP \x05成功，\x04祝贺他吧", Client, AWP[Client]);          
			}
			case 2:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 3:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 4:           
			{     
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 5:           
			{     
				AWP[Client] --;			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05悲剧，你掉了一级");           
			}
	    }
    }
    if(AWP[Client] > 40)   
	{
	    CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05已达上限无法强化");
    }
    if(QHSL[Client] >= 100)   
	{
		QHHSZ[Client] = 1;	
		QHSL[Client] = 0;		
    }		
	else CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05金币不足或材料不足");
        
}

public qhpz1(Client)
{
    if(Cash[Client] > 50000 && PZ[Client] <= 20)   
	{
	    Cash[Client] -= 50000;
	    Qhs[Client] -= 1;
	    new Qhjl = GetRandomInt(1, 4);
		
	    switch (Qhjl)       
	    {    
		    case 1:           
			{               
	           PZ[Client] ++;
	           QHSL[Client] ++;			   
	           CPrintToChatAll("\x01[\x03枪械强化\x01]\x05玩家\x04 %N \x03【强化LV%d】喷子 \x05成功，\x04祝贺他吧", Client, PZ[Client]);         
			}
			case 2:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 3:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 4:           
			{     
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
	    }
    }
    if(Cash[Client] > 80000 && PZ[Client] > 20  && PZ[Client] <= 40 && Qhs[Client] > 3)   
	{
	    Cash[Client] -= 80000;
	    Qhs[Client] -= 1;
	    new Qhjl = GetRandomInt(1, 5);
		
	    switch (Qhjl)       
	    {    
		    case 1:           
			{               
	           PZ[Client] ++;
	           QHSL[Client] ++;			   
	           CPrintToChatAll("\x01[\x03枪械强化\x01]\x05玩家\x04 %N \x03【强化LV%d】喷子 \x05成功，\x04祝贺他吧", Client, PZ[Client]);         
			}
			case 2:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 3:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 4:           
			{     
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 5:           
			{     
				PZ[Client] --			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05悲剧，你掉了一级");           
			}
	    }
    }
    if(PZ[Client] > 40)   
	{
	    CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05已达上限无法强化");
    }
    if(QHSL[Client] >= 100)   
	{
		QHHSZ[Client] = 1;	
		QHSL[Client] = 0;		
    }		
	else CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05金币不足或材料不足");
        
}

public qhm601(Client)
{
    if(Cash[Client] > 50000 && M60[Client] <= 20)   
	{
	    Cash[Client] -= 50000;
	    Qhs[Client] -= 1;
	    new Qhjl = GetRandomInt(1, 4);
		
	    switch (Qhjl)       
	    {    
		    case 1:           
			{               
	           M60[Client] ++;
	           QHSL[Client] ++;			   
	           CPrintToChatAll("\x01[\x03枪械强化\x01]\x05玩家\x04 %N \x03【强化LV%d】M6O \x05成功，\x04祝贺他吧", Client, M60[Client]);         
			}
			case 2:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 3:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 4:           
			{     
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
	    }
    }
    if(Cash[Client] > 80000 && M60[Client] > 20  && M60[Client] <= 40 && Qhs[Client] > 3)   
	{
	    Cash[Client] -= 80000;
	    Qhs[Client] -= 3;
	    new Qhjl = GetRandomInt(1, 5);
		
	    switch (Qhjl)       
	    {    
		    case 1:           
			{               
	           M60[Client] ++;
	           QHSL[Client] ++;			   
	           CPrintToChatAll("\x01[\x03枪械强化\x01]\x05玩家\x04 %N \x03【强化LV%d】M6O \x05成功，\x04祝贺他吧", Client, M60[Client]);         
			}
			case 2:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 3:           
			{   
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 4:           
			{     
				Sxcs[Client] ++			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05失败");           
			}
			case 5:           
			{     
				M60[Client] --;			
				CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05悲剧，你掉了一级");           
			}
	    }
    }
    if(M60[Client] > 40)   
	{
	    CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05已达上限无法强化");
    }
    if(QHSL[Client] >= 100)   
	{
		QHHSZ[Client] = 1;	
		QHSL[Client] = 0;		
    }	
	else CPrintToChat(Client, "\x01[\x04强化\x01]\x03：\x05金币不足或材料不足");
        
}

public Action:MenuFunc_CLbuy(Client)
{
	decl String:line[256];
	new Handle:menu = CreatePanel();
	Format(line, sizeof(line), "========材料换取系统======");
	SetPanelTitle(menu, line);
	Format(line, sizeof(line),"说明：一定数量的材料可以换取金币");
	DrawPanelText(menu, line);
	Format(line, sizeof(line),"大量材料可以换取随机装备");
	DrawPanelText(menu, line);
	Format(line, sizeof(line),"====================");
	DrawPanelText(menu, line);
	
	Format(line, sizeof(line), "BOSS的心愿【拥有：%d】", BSXY[Client]);
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "强化石【拥有%d】", Qhs[Client]);
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_CLbuy, MENU_TIME_FOREVER);

	CloseHandle(menu);

	return Plugin_Handled;
}
public MenuHandler_CLbuy(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select) {
		switch(param) {
			case 1:
			    if (BSXY[Client] > 0)
			    {  
			        MenuFunc_huodong(Client);
			    }else CPrintToChat(Client, "你没有BOSS心愿，无法进入");
			case 2:
			    if (Qhs[Client] > 0)
			    {  
			        MenuFunc_huodong1(Client);
			    }else CPrintToChat(Client, "你没有强化石，击无法进入");				
		}
	}
}

public Action:MenuFunc_huodong(Client)
{
	new Handle:menu = CreatePanel();
	
	decl String:line[1024], String:wq[1024], String:wq1[1024], String:wq2[1024];	    
	if (BSXY[Client] < 10)
		Format(wq, sizeof(wq), "未达到");
	else if (BSXY[Client] >= 10)
		Format(wq, sizeof(wq), "可领取");
	if (BSXY[Client] < 30)
		Format(wq1, sizeof(wq1), "未达到");
	else if (BSXY[Client] >= 30)
		Format(wq1, sizeof(wq1), "可领取");
	if (BSXY[Client] < 50)
		Format(wq2, sizeof(wq2), "未达到");
	else if (BSXY[Client] >= 50)
		Format(wq2, sizeof(wq2), "可领取");
		
	Format(line, sizeof(line), "【BOSS心愿】 拥有:%d个", BSXY[Client]);
	SetPanelTitle(menu, line);
	
	Format(line, sizeof(line), "换取金币5万【%s】", wq);
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "换取经验5万【%s】", wq1);
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "换取神器随机2天【%s】", wq2);
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_huodong, MENU_TIME_FOREVER);
	return Plugin_Handled;
}

public MenuHandler_huodong(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: huod(Client);
			case 2: huod1(Client);
			case 3: huod2(Client);
		}
	}
}

public huod(Client)//戒指
{   
	if(BSXY[Client] >= 10)    
	{       
		Cash[Client] += 50000;	
		BSXY[Client] -= 10		
		CPrintToChatAll("\x02[\x04材料\x02],\x03玩家 \x04%N \x03出售\x0510个\x04BOSS心愿，\x05获得5万金币", Client);	    
	} else CPrintToChat(Client, "你的材料不足10个");
}
public huod1(Client)//鞋子
{   
	if(BSXY[Client] >= 30)    
	{       
		EXP[Client] += 50000;
		BSXY[Client] -= 30		
		CPrintToChatAll("\x02[\x04材料\x02],\x03玩家 \x04%N \x03出售\x0530个\x04【BOSS心愿】，\x05获得5万经验", Client);	    
	} else CPrintToChat(Client, "你的材料不足30个");
}
public huod2(Client)//血盾
{   
	if(BSXY[Client] >= 50)    
	{   
		BSXY[Client] -= 50    
		new RandomGiv = GetRandomInt(0, 3);
		switch(RandomGiv)
		{
			case 0: 
			{
				SetZBItemTime(Client, 9, 2, false); 
			}
			case 1: 
			{
				SetZBItemTime(Client, 25, 2, false); 
			}
			case 2: 
			{
				SetZBItemTime(Client, 10, 2, false); 
			}
			case 3: 
			{
				SetZBItemTime(Client, 11, 2, false); 
			}	
        }			
		CPrintToChatAll("\x02[\x04材料\x02],\x03玩家 \x04%N \x03出售\x0550个\x04【BOSS心愿】，\x05获得\x04随机神器2天", Client);	    
	} else CPrintToChat(Client, "你的材料不足50个");
}

public Action:MenuFunc_huodong1(Client)
{
	new Handle:menu = CreatePanel();
	
	decl String:line[1024], String:wq[1024], String:wq1[1024], String:wq2[1024], String:wq3[1024];	    
	if (Qhs[Client] < 10)
		Format(wq, sizeof(wq), "未达到");
	else if (Qhs[Client] >= 10)
		Format(wq, sizeof(wq), "可领取");
	if (Qhs[Client] < 50)
		Format(wq, sizeof(wq1), "未达到");
	else if (Qhs[Client] >= 50)
		Format(wq1, sizeof(wq1), "可领取");
	if (Qhs[Client] < 100)
		Format(wq2, sizeof(wq2), "未达到");
	else if (Qhs[Client] >= 100)
		Format(wq2, sizeof(wq2), "可领取");
	if (Qhs[Client] < 200)
		Format(wq3, sizeof(wq3), "未达到");
	else if (Qhs[Client] >= 200)
		Format(wq3, sizeof(wq3), "可领取");
		
	Format(line, sizeof(line), "【强化石】 拥有:%d个", Qhs[Client]);
	SetPanelTitle(menu, line);
	
	Format(line, sizeof(line), "10000【%s】", wq);
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "80000【%s】", wq1);
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "150000【%s】", wq2);
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "250000【%s】", wq3);
	DrawPanelItem(menu, line);

	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_huodong1, MENU_TIME_FOREVER);
	return Plugin_Handled;
}

public MenuHandler_huodong1(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select) {
		switch (param)
		{
			case 1: huodq(Client);
			case 2: huod1q(Client);
			case 3: huod2q(Client);
			case 4: huod3q(Client);
		}
	}
}

public huodq(Client)//戒指
{   
	if(Qhs[Client] >= 1)    
	{       
		Cash[Client] += 10000;	
		Qhs[Client] -= 1		
		CPrintToChatAll("\x02[\x04材料\x02],\x03玩家 \x04%N \x03出售\x051个\x04强化石，\x05获得1万金币", Client);	    
	} else CPrintToChat(Client, "你的材料不足10个");
}
public huod1q(Client)//鞋子
{   
	if(Qhs[Client] >= 5)    
	{       
		Cash[Client] += 80000;
		Qhs[Client] -= 5		
		CPrintToChatAll("\x02[\x04材料\x02],\x03玩家 \x04%N \x03出售\x055个\x04【强化石】，\x05获得8万金币", Client);	    
	} else CPrintToChat(Client, "你的材料不足50个");
}
public huod2q(Client)//鞋子
{   
	if(Qhs[Client] >= 10)    
	{       
		Cash[Client] += 150000;
		Qhs[Client] -= 10		
		CPrintToChatAll("\x02[\x04材料\x02],\x03玩家 \x04%N \x03出售\x0510个\x04【强化石】，\x05获得15万金币", Client);	    
	} else CPrintToChat(Client, "你的材料不足100个");
}
public huod3q(Client)//鞋子
{   
	if(Qhs[Client] >= 20)    
	{       
		Cash[Client] += 250000;
		Qhs[Client] -= 20		
		CPrintToChatAll("\x02[\x04材料\x02],\x03玩家 \x04%N \x03出售\x0520个\x04【强化石】，\x05获得25万金币", Client);	    
	} else CPrintToChat(Client, "你的材料不足200个");
}
