//任務系統
public Action:MenuFunc_RWCD(Client)
{   
	new Handle:menu = CreatePanel();
		   
	decl String:line[1024];   
	Format(line, sizeof(line), "****任務菜單***\n任務系統簡介:任務系統分為2種: \n普通任務與主線任務，主線任務是隨機獲得的");   
	SetPanelTitle(menu, line);   
	
	Format(line, sizeof(line), "═══普通任務═══");   
	DrawPanelItem(menu, line);   	
	
	Format(line, sizeof(line), "═══主線任務═══");   
	DrawPanelItem(menu, line);		
   
	DrawPanelItem(menu, "返回RPG選單");   
	DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
 
	SendPanelToClient(menu, Client, MenuHandler_RWCD, MENU_TIME_FOREVER);  
	return Plugin_Handled;
}
public MenuHandler_RWCD(Handle:menu, MenuAction:action, Client, param)
{
    if (action == MenuAction_Select) 
    {
        switch (param)
        {	        
			case 1: 
			{
                if(Renwu[Client] == 0)
                {
                    MenuFunc_Renwuxi(Client);
                }
                if(Renwu[Client] == 1)
                {
                    MenuFunc_Shizhesa(Client);
                }				
            }			//普通任務	
			case 2:
			{
                if(ZXRW[Client] == 0)
                {
                    XZZXRW(Client);	
                }
                if(ZXRW[Client] == 1)
                {
                    MenuFunc_KSZXRWD(Client);
                }				
            }									
			case 3: MenuFunc_RPG(Client); 
		}   
	}
}

public XZZXRW(Client)
{
    if(ZXRW[Client] == 0)   
	{
	    new ZXRWLQ = GetRandomInt(1, 8);
		
	    switch (ZXRWLQ)       
	    {    
		    case 1:           
			{               
	           ZXRW[Client] += 1;						
	           KSZXRW[Client] += 1;						
	           MenuFunc_KSZXRWD(Client);	          
			}
			case 2:           
			{   
	           ZXRW[Client] += 1;						
	           KSZXRW[Client] += 2;						
	           MenuFunc_KSZXRWD(Client);			         
			}
			case 3:           
			{   
	           ZXRW[Client] += 1;						
	           KSZXRW[Client] += 3;						
	           MenuFunc_KSZXRWD(Client);			          
			}
			case 4:           
			{     
	           ZXRW[Client] += 1;						
	           KSZXRW[Client] += 4;						
	           MenuFunc_KSZXRWD(Client);				          
			}
			case 5:           
			{    
	           ZXRW[Client] += 1;						
	           KSZXRW[Client] += 5;						
	           MenuFunc_KSZXRWD(Client);				
			}	
			case 6:           
			{    
	           ZXRW[Client] += 1;						
	           KSZXRW[Client] += 6;						
	           MenuFunc_KSZXRWD(Client);				
			}	
			case 7:           
			{    
	           ZXRW[Client] += 1;						
	           KSZXRW[Client] += 7;						
	           MenuFunc_KSZXRWD(Client);				
			}	
			case 8:           
			{    
	           ZXRW[Client] += 1;						
	           KSZXRW[Client] += 8;						
	           MenuFunc_KSZXRWD(Client);				
			}			
	    }
    }
}	

//任務系統
public Action:MenuFunc_KSZXRWD(Client)
{
    new Handle:menu = CreatePanel();
	
    decl String:line[1024];
    if (KSZXRW[Client] == 1)
    {
        Format(line, sizeof(line), "═══【任務】死亡主宰(一)═══ \n【任務需求: 擊殺普通感染者!】\n【普通感染者:1200個】〤斬:%d個 \n【任務獎勵: 金錢30000$】 \n══════════════", PTJS[Client]);
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }	
    else if (KSZXRW[Client] == 2)
    {
        Format(line, sizeof(line), "═══【任務】後備醫療(一)═══ \n【任務需求: 擊殺TANK!】 \n【任務獎勵: 經驗3800 金錢: 8000】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【TANK10個】〤斬:%d個 \n【拉起隊友10次】拉起:%d次 \n══════════════", TANKSL[Client], LRCS[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }
    else if (KSZXRW[Client] == 3)
    {
        Format(line, sizeof(line), "═══【任務】後備醫療(二)═══ \n【任務需求: 擊殺TANK!】 \n【任務獎勵: 經驗5800 金錢: 8000】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【TANK10個】〤斬:%d個 \n【復活隊友10次】復活:%d次 \n══════════════", TANKSL[Client], JRCS[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }	
    else if (KSZXRW[Client] == 4)
    {
        Format(line, sizeof(line), "═══【任務】後備醫療(三)═══ \n【任務需求: 擊殺普通僵屍!】 \n【任務獎勵: 經驗5800 金錢: 8000 】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【普通僵屍1000個】〤斬:%d個 \n【復活隊友10次】拉起:%d次 \n══════════════", PTJS[Client], JRCS[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }	
    else if (KSZXRW[Client] == 5)
    {
        Format(line, sizeof(line), "═══【任務】死亡主宰(二)═══ \n【任務需求: 擊殺TANK!】 \n【任務獎勵: EXP+10000】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【TANK30個】〤斬:%d個 \n══════════════", TANKSL[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }	
    else if (KSZXRW[Client] == 6)
    {
        Format(line, sizeof(line), "═══【任務】死亡的眷戀═══ \n【任務需求: 擊殺TANK!】 \n【任務獎勵: S材料50個 】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【TANK10個】〤斬:%d個 \n 【普通僵屍1000個】〤斬:%d個 \n══════════════", TANKSL[Client], PTJS[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }	
    else if (KSZXRW[Client] == 7)
    {
        Format(line, sizeof(line), "═══【任務】救助者═══ \n【任務需求: 救起隊友!】 \n【任務獎勵: EXP+2000】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【拉起隊友20次】拉起:%d次 \n 【復活隊友15次】次數:%d次 \n══════════════", LRCS[Client], JRCS[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }	
    else if (KSZXRW[Client] == 8)
    {
        Format(line, sizeof(line), "═══【任務】滅絕僵屍═══ \n【任務需求: 殺死TANK和普通僵屍!】 \n【任務獎勵: 烈焰勛章10枚 金錢5000】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【擊殺TANK 10個】〤斬:%d個 \n 【擊殺普通僵屍1200個】〤斬:%d個 \n══════════════", TANKSL[Client], PTJS[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }		
	
    SendPanelToClient(menu, Client, MenuHandler_KSZXRWD, MENU_TIME_FOREVER);
    return Plugin_Handled;
}

public MenuHandler_KSZXRWD(Handle:menu, MenuAction:action, Client, param)
{
    if (action == MenuAction_Select) 
    {
        switch (param)
        {
	        case 1: ZXRWWC(Client);	
            case 2: ZXRWFQ(Client);	
            case 3: MenuFunc_RPG(Client);			
        }
    }
}
public ZXRWWC(Client)
{	
    if(KSZXRW[Client] == 1)
    {
        if(PTJS[Client] >= 3000)
        {
            Cash[Client] += 30000;
            PTJS[Client] = 0;
            ZXRW[Client] = 0;
            KSZXRW[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了金錢30000$!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 死亡主宰!", Client);
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(KSZXRW[Client] == 2)
    {
        if(TANKSL[Client] >= 10 && LRCS[Client] >= 10)
        {
            EXP[Client] += 3800;
            Cash[Client] += 8000;			
            TANKSL[Client] = 0;
            LRCS[Client] = 0;				
            KSZXRW[Client] = 0;
            ZXRW[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了經驗3800 金錢8000!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 後備醫療(一)!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(KSZXRW[Client] == 3)
    {
        if(TANKSL[Client] >= 10 && JRCS[Client] >= 10)
        {
            EXP[Client] += 5800;
            Cash[Client] += 8000;			
            TANKSL[Client] = 0;
            JRCS[Client] = 0;				
            KSZXRW[Client] = 0;
            ZXRW[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了經驗5800 金錢8000!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 後備醫療(二)!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }	
    if(KSZXRW[Client] == 4)
    {
        if(PTJS[Client] >= 1000 && JRCS[Client] >= 10)
        {
            EXP[Client] += 5800;
            Cash[Client] += 8000;			
            PTJS[Client] = 0;
            JRCS[Client] = 0;				
            KSZXRW[Client] = 0;
            ZXRW[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了經驗5800 金錢8000!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 後備醫療(三)!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(KSZXRW[Client] == 5)
    {
        if(TANKSL[Client] >= 30)
        {
            EXP[Client] += 10000;	
            TANKSL[Client] = 0;
            ZXRW[Client] = 0;
            KSZXRW[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,EXP+10000!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 死亡主宰!", Client);
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(KSZXRW[Client] == 6)
    {
        if(TANKSL[Client] >= 10 && PTJS[Client] >= 1000)
        {
            SCL[Client] += 50;		
            PTJS[Client] = 0;
            TANKSL[Client] = 0;
            ZXRW[Client] = 0;
            KSZXRW[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了和50個S材料!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 死亡的眷戀!", Client);
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }	
    if(KSZXRW[Client] == 7)
    {
        if(LRCS[Client] >= 20 && JRCS[Client] >= 10)
        {
            LRCS[Client] = 0;
            JRCS[Client] = 0;
            ZXRW[Client] = 0;
            KSZXRW[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得EXP2000個!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 救助者!", Client);
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(KSZXRW[Client] == 8)
    {
        if(TANKSL[Client] >= 10 && PTJS[Client] >= 1200)
        {
            Cash[Client] += 5000;
            Lyxz[Client] += 10;			
            PTJS[Client] = 0;
            TANKSL[Client] = 0;
            ZXRW[Client] = 0;
            KSZXRW[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了金錢5000和10枚烈焰勛章!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 滅絕僵屍!", Client);
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }	
}	
public ZXRWFQ(Client)
{	
    if(KSZXRW[Client] == 1)
    {
        PTJS[Client] = 0;
        ZXRW[Client] = 0;
        KSZXRW[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    }
    if(KSZXRW[Client] == 2)
    {
        TANKSL[Client] = 0;
        LRCS[Client] = 0;		
        ZXRW[Client] = 0;
        KSZXRW[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    }
    if(KSZXRW[Client] == 3)
    {
        TANKSL[Client] = 0;
        JRCS[Client] = 0;		
        ZXRW[Client] = 0;
        KSZXRW[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    }	
    if(KSZXRW[Client] == 4)
    {
        PTJS[Client] = 0;
        JRCS[Client] = 0;		
        ZXRW[Client] = 0;
        KSZXRW[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    }
    if(KSZXRW[Client] == 5)
    {
        TANKSL[Client] = 0;
        ZXRW[Client] = 0;
        KSZXRW[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    }
    if(KSZXRW[Client] == 6)
    {
        TANKSL[Client] = 0;
        PTJS[Client] = 0;		
        ZXRW[Client] = 0;
        KSZXRW[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    }	
    if(KSZXRW[Client] == 7)
    {
        LRCS[Client] = 0;
        JRCS[Client] = 0;		
        ZXRW[Client] = 0;
        KSZXRW[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    }
    if(KSZXRW[Client] == 8)
    {
        TANKSL[Client] = 0;
        PTJS[Client] = 0;		
        ZXRW[Client] = 0;
        KSZXRW[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    }	
}
//任務系統
public Action:MenuFunc_Renwuxis(Client)
{   
	new Handle:menu = CreatePanel();
	    
	decl String:CBAWU[1024];	    
	if(Jenwu[Client] == 0)			Format(CBAWU, sizeof(CBAWU), "未接");
	    
	decl String:line[1024];    
	Format(line, sizeof(line), "【任務列表 狀態:%s】", CBAWU);   
	SetPanelTitle(menu, line);    
	Format(line, sizeof(line), "金錢的欲望");    
	DrawPanelItem(menu, line);      
	Format(line, sizeof(line), "搶劫寶石");   
	DrawPanelItem(menu, line);       
	Format(line, sizeof(line), "無一生還");   
	DrawPanelItem(menu, line);   
	Format(line, sizeof(line), "死亡之時");   
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "黑暗入侵");   
	DrawPanelItem(menu, line);
	Format(line, sizeof(line), "勇者無畏");   
	DrawPanelItem(menu, line); 
	Format(line, sizeof(line), "[職業開啟]影武者之匙");    
	DrawPanelItem(menu, line); 	
	Format(line, sizeof(line), "下一頁");   
	DrawPanelItem(menu, line); 		
	DrawPanelItem(menu, "返回RPG選單"); 
	DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    
	SendPanelToClient(menu, Client, MenuHandler_Renwuxis, MENU_TIME_FOREVER);    
	return Plugin_Handled;
}

public MenuHandler_Renwuxis(Handle:menu, MenuAction:action, Client, param)
{    
	if (action == MenuAction_Select)     
	{
		switch (param)   
		{        
			case 1:
            {
				if(Lv[Client] > 0)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 7;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的等級還沒超過0級無法進行!");            
			}		
            case 2:
            {
				if(Lv[Client] > 0)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 8;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的等級還沒超過0級無法進行!");            
			}
            case 3:
            {
				if(Lv[Client] > 0)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 9;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的等級還沒超過0級無法進行!");            
			}
            case 4:
            {
			    if(Lv[Client] > 0)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 10;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的等級還沒超過0級無法進行!");            
			}
            case 5:
            {
			    if(Lv[Client] > 0)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 11;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的等級還沒超過0級無法進行!");            
			}
            case 6:
            {
			    if(Lv[Client] > 0)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 13;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的等級還沒超過0級無法進行");            
			}
			case 7:
            {
				if(NewLifeCount[Client] >= 4)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 15;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的還沒有轉生4次無法進行!");            
			}				
			case 8:MenuFunc_Renwuxi2(Client);		
        }
    }
}	

//任務系統
public Action:MenuFunc_Renwuxi2(Client)
{   
	new Handle:menu = CreatePanel();
	    
	decl String:CBAWU[1024];	    
	if(Jenwu[Client] == 0)			Format(CBAWU, sizeof(CBAWU), "未接");
	    
	decl String:line[1024];    
	Format(line, sizeof(line), "【任務列表 狀態:%s】", CBAWU);   
	SetPanelTitle(menu, line);
	
	Format(line, sizeof(line), "治療大隊");   
	DrawPanelItem(menu, line); 
	Format(line, sizeof(line), "嘗試失敗");   
	DrawPanelItem(menu, line); 	
	
	if(VIP[Client] > 0)
	{	    
		Format(line, sizeof(line), "貴族榮耀");       
		DrawPanelItem(menu, line);		
	}	
	DrawPanelItem(menu, "返回RPG選單"); 
	DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    
	SendPanelToClient(menu, Client, MenuHandler_Renwuxi2, MENU_TIME_FOREVER);    
	return Plugin_Handled;
}

public MenuHandler_Renwuxi2(Handle:menu, MenuAction:action, Client, param)
{    
	if (action == MenuAction_Select)     
	{
		switch (param)   
		{      
			case 1:
            {
				if(Lv[Client] > 0)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 16;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的等級還沒超過0級無法進行!");            
			}
			case 2:
            {
				if(Lv[Client] > 0)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 17;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的等級還沒超過0級無法進行!");            
			}			
			case 3:
            {
				if(VIP[Client] >= 1)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 4;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你不是VIP無法進行!");            
			}			
			case 4:MenuFunc_RPG(Client);		
        }
    }
}
//任務系統
public Action:Menu_Renwuxi(Client,args)
{
    if(Renwu[Client] == 0)
    {
        MenuFunc_Renwuxi(Client);
    }
    if(Renwu[Client] == 1)
    {
        MenuFunc_Shizhesa(Client);
    }	
    return Plugin_Handled;
}
public Action:MenuFunc_Renwuxi(Client)
{   
	new Handle:menu = CreatePanel();
	    
	decl String:CBAWU[1024];	    
	if(Jenwu[Client] == 0)			Format(CBAWU, sizeof(CBAWU), "未接");
	    
	decl String:line[1024];    
	Format(line, sizeof(line), "【任務列表 狀態:%s】", CBAWU);   
	SetPanelTitle(menu, line);    
	Format(line, sizeof(line), "殺出道路任務");    
	DrawPanelItem(menu, line);      
	Format(line, sizeof(line), "生存能力任務");   
	DrawPanelItem(menu, line);      
	Format(line, sizeof(line), "最終生還任務");   
	DrawPanelItem(menu, line);   
	Format(line, sizeof(line), "光輝時刻任務");   
	DrawPanelItem(menu, line);   
	Format(line, sizeof(line), "生存之道任務");   
	DrawPanelItem(menu, line); 
	Format(line, sizeof(line), "黑色狂歡任務");   
	DrawPanelItem(menu, line);  
	Format(line, sizeof(line), "神的救贖任務");   
	DrawPanelItem(menu, line); 	
	Format(line, sizeof(line), "下一頁");   
	DrawPanelItem(menu, line); 
	
	DrawPanelItem(menu, "返回RPG選單"); 
	DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    
	SendPanelToClient(menu, Client, MenuHandler_Renwuxi, MENU_TIME_FOREVER);    
	return Plugin_Handled;
}

public MenuHandler_Renwuxi(Handle:menu, MenuAction:action, Client, param)
{    
	if (action == MenuAction_Select)     
	{
		switch (param)   
		{        
			case 1:
            {
				if(Lv[Client] > 0)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 1;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的等級還沒超過0級無法進行!");            
			}		
            case 2:
            {
				if(Lv[Client] > 0)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 2;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的等級還沒超過0級無法進行!");            
			}
            case 3:
            {
				if(Lv[Client] > 0)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 3;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的等級還沒超過0級無法進行!");            
			}
            case 4:
            {
				if(Lv[Client] > 0)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 5;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的等級還沒超過0級無法進行!");            
			}
            case 5:
            {
				if(Lv[Client] > 0)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 6;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的等級還沒超過0級無法進行!");            
			}
            case 6:
            {
				if(Lv[Client] > 0)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 12;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的等級還沒超過0級無法進行!");            
			}
            case 7:
            {
				if(KTCount[Client] >= 1)
				{
					if(Jenwu[Client] == 0)
					{                        
						Renwu[Client] += 1;						
						Jenwu[Client] += 14;						
						MenuFunc_Shizhesa(Client);	
					}
				} else CPrintToChat(Client, "\x03【任務】\x05你的還沒有大過無法進行!");            
			}			
			case 8:MenuFunc_Renwuxis(Client);
			case 9:MenuFunc_RPG(Client);			
        }
    }
}

public Action:MenuFunc_Shizhesa(Client)
{
    new Handle:menu = CreatePanel();
	
    decl String:line[1024];
    if (Jenwu[Client] == 1)
    {
        Format(line, sizeof(line), "═══【任務】殺出道路═══ \n【任務需求: 擊殺普通感染者!】\n【普通感染者:300個】〤斬:%d個 \n【任務獎勵: 金錢1000$】 \n══════════════", Pugan[Client]);
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }	
    else if (Jenwu[Client] == 2)
    {
        Format(line, sizeof(line), "═══【任務】生存能力═══ \n【任務需求: 擊殺特殊感染者!】 \n【任務獎勵: 3000EXP經驗值】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【Smoker10個】〤斬:%d個 【Boomer10個】〤斬:%d個 \n【Hunter10個】〤斬:%d個 【Spitter10個】〤斬:%d個 \n【Jockey10個】〤斬:%d個 【Charger10個】〤斬:%d個 \n══════════════", TYangui[Client], TPangzi[Client], TLieshou[Client], TKoushui[Client], THouzhi[Client], TXiaoniu[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }
    else if (Jenwu[Client] == 3)
    {
        Format(line, sizeof(line), "═══【任務】最終生還═══ \n【任務需求: 感染者克星!】 \n【任務獎勵: 金錢5000$和A材料3個】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【普通感染者500個】〤斬:%d個 \n【特殊感染者30個】〤斬:%d個 \n══════════════", Pugan[Client], Tegan[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }
	else if (Jenwu[Client] == 4)
    {
        Format(line, sizeof(line), "═══【任務】貴族榮耀═══ \n【任務需求: 擊殺BOSS!】 \n【任務獎勵: 金錢5000$】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【Tank20個】〤斬:%d個 \n══════════════", TDaxinxin[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }
	else if (Jenwu[Client] == 5)
    {
        Format(line, sizeof(line), "═══【任務】光輝時刻═══ \n【任務需求: 擊殺BOSS!】 \n【任務獎勵: 金錢5000$和3個B材料】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【Tank30個】〤斬:%d個 【拉起隊友18次】拉起:%d次 \n══════════════", TDaxinxin[Client], LQDY[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }
	else if (Jenwu[Client] == 6)
    {
        Format(line, sizeof(line), "═══【任務】生存之道═══ \n【任務需求: 擊殺普通僵屍!】 \n【任務獎勵: 金錢2000$和2個A材料】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【小僵屍900個】〤斬:%d個 \n 【復活隊友5次】復活:%d次\n 【拉起隊友8次】拉起:%d次 \n══════════════", Pugan[Client], FHCS[Client], LQDY[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }
	else if (Jenwu[Client] == 12)
    {
        Format(line, sizeof(line), "═══【任務】黑色狂歡═══ \n【任務需求: 擊殺普通僵屍!】 \n【任務獎勵: 金錢8000$和4個A材料】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【小僵屍1500個】〤斬:%d個 \n 【復活隊友8次】復活:%d次 \n══════════════", Pugan[Client], LQDY[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }
	else if (Jenwu[Client] == 7)
    {
        Format(line, sizeof(line), "═══【任務】金錢的欲望═══ \n【任務需求: 擊殺普通感染者!】\n【普通感染者:3000個】〤斬:%d個 \n【任務獎勵: 金錢80000$】 \n══════════════", Pugan[Client]);
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }	
	else if (Jenwu[Client] == 8)
    {
        Format(line, sizeof(line), "═══【任務】搶劫寶石═══ \n【任務需求: 擊殺TANK!】 \n【任務獎勵: 初級經驗寶石1塊】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【TANK50個】〤斬:%d個 \n【拉起隊友15次】拉起:%d次 \n══════════════", TDaxinxin[Client], LQDY[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }
	else if (Jenwu[Client] == 9)
    {
        Format(line, sizeof(line), "═══【任務】無人永生═══ \n【任務需求: 擊殺bommer!】 \n【任務獎勵: 金錢10000$和A、b材料2個】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【BOMMER800個】〤斬:%d個 \n 【復活隊友8次】復活:%d次 \n【拉起隊友20次】拉起:%d次 \n══════════════", TPangzi[Client], FHCS[Client], LQDY[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }
	else if (Jenwu[Client] == 10)
    {
        Format(line, sizeof(line), "═══【任務】死亡之時═══ \n【任務需求: 擊殺猴子!】 \n【任務獎勵:和A材料8個】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【猴子200個】〤斬:%d個\n【復活隊友15次】復活:%d次 \n【拉起隊友50次】拉起:%d次  \n══════════════", THouzhi[Client], FHCS[Client], LQDY[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }
	else if (Jenwu[Client] == 11)
    {
        Format(line, sizeof(line), "═══【任務】黑暗入侵═══ \n【任務需求: 擊殺BOSS!】 \n【任務獎勵:S材料2個】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【TANK20個】〤斬:%d個 【SMOKER300個】〤斬:%d個 \n【復活隊友20次】復活:%d次 \n【拉起隊友80次】拉起:%d次 \n══════════════", TDaxinxin[Client], TYangui[Client], FHCS[Client], LQDY[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }
	else if (Jenwu[Client] == 13)
    {
        Format(line, sizeof(line), "═══【任務】勇者無畏═══ \n【任務需求: 復活隊友+拉起!】 \n【任務獎勵:炎神寶盒.可以隨機開出裝備】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【復活隊友500次】復活:%d次 \n【起隊友500次】拉起:%d次 \n══════════════", FHCS[Client], LQDY[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }
	else if (Jenwu[Client] == 14)
    {
        Format(line, sizeof(line), "═══【任務】神的救贖═══ \n【任務需求: 幫助隊友!】 \n【任務獎勵:  消除一次大過】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【復活隊友10次】復活:%d次 \n【拉起隊友100次】拉起:%d次 \n══════════════", FHCS[Client], LQDY[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }
	else if (Jenwu[Client] == 15)
    {
        Format(line, sizeof(line), "═══【任務】影武者之匙═══ \n【任務需求: 擊殺TANK!】 \n【任務獎勵:  有60%幾率獲得一個影之匙】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【擊殺Tank20個】擊殺:%d個 \n══════════════", TDaxinxin[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }
	else if (Jenwu[Client] == 16)
    {
        Format(line, sizeof(line), "═══【任務】治療大隊═══ \n【任務需求: 治療隊友!】 \n【任務獎勵:EXP+10000】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【醫療隊友100次】醫療:%d次 \n══════════════", YLDY[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }
	else if (Jenwu[Client] == 17)
    {
        Format(line, sizeof(line), "═══【任務】嘗試失敗═══ \n【任務需求: 嘗試倒地死亡!】 \n【任務獎勵: 20000金幣】 \n══════════════");
        SetPanelTitle(menu, line);
        Format(line, sizeof(line), "【倒地50次】倒地:%d次 \n══════════════", DDCS[Client]);
        DrawPanelText(menu, line);
        Format(line, sizeof(line), "完成任務");
        DrawPanelItem(menu, line);
        Format(line, sizeof(line), "放棄任務");
        DrawPanelItem(menu, line);
        DrawPanelItem(menu, "返回RPG選單");
        DrawPanelItem(menu, "離開", ITEMDRAW_DISABLED);
    }	
	
    SendPanelToClient(menu, Client, MenuHandler_Shizhesa, MENU_TIME_FOREVER);
    return Plugin_Handled;
}

public MenuHandler_Shizhesa(Handle:menu, MenuAction:action, Client, param)
{
    if (action == MenuAction_Select) 
    {
        switch (param)
        {
	        case 1: RENWUWAN(Client);	
            case 2: RENWUQI(Client);	
            case 3: MenuFunc_RPG(Client);			
        }
    }
}
public RENWUWAN(Client)
{	
    if(Jenwu[Client] == 1)
    {
        if(Pugan[Client] >= 300)
        {
            Cash[Client] += 1000;
            Pugan[Client] = 0;
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了金錢1000$!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 殺出道路!", Client);
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(Jenwu[Client] == 2)
    {
        if(TYangui[Client] >= 10 && TPangzi[Client] >= 10 && TLieshou[Client] >= 10 && TKoushui[Client] >= 10 && THouzhi[Client] >= 10 && TXiaoniu[Client] >= 10)
        {
            EXP[Client] += 3000;
            TYangui[Client] = 0;
            TPangzi[Client] = 0;
            TLieshou[Client] = 0;
            TKoushui[Client] = 0;
            THouzhi[Client] = 0;
            TXiaoniu[Client] = 0;
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了3000EXP經驗值!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 生存能力!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(Jenwu[Client] == 3)
    {
        if(Pugan[Client] >= 500 && Tegan[Client] >= 30)
        {
            Cash[Client] += 5000;
            ACL[Client] += 3;			
            Pugan[Client] = 0;
            Tegan[Client] = 0;
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了金錢5000$!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 最終生還!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(Jenwu[Client] == 4)
    {
        if(TDaxinxin[Client] >= 20)
        {
            Cash[Client] += 5000;
            TDaxinxin[Client] = 0;
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了金錢5000$!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 貴族榮耀!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(Jenwu[Client] == 5)
    {
        if(TDaxinxin[Client] >= 30 && LQDY[Client] >= 18)
        {
            Cash[Client] += 5000;
            BCL[Client] += 3;				
            TDaxinxin[Client] = 0;
            LQDY[Client] = 0;			
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了金錢5000$和B材料3個!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 光輝時刻!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(Jenwu[Client] == 6)
    {
        if(Pugan[Client] >= 900 && LQDY[Client] >= 8 && FHCS[Client] >= 5)
        {
            Cash[Client] += 2000;
            ACL[Client] += 2;	
            LQDY[Client] = 0;	
            FHCS[Client] = 0;				
            Pugan[Client] = 0;
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了金錢2000$和A材料2個!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 生存之道!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }	
    if(Jenwu[Client] == 12)
    {
        if(Pugan[Client] >= 1500 && FHCS[Client] >= 8)
        {
            Cash[Client] += 8000;
            ACL[Client] += 4;	
            FHCS[Client] = 0;				
            Pugan[Client] = 0;
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了金錢8000$和A材料4個!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 黑色狂歡!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(Jenwu[Client] == 7)
    {
        if(Pugan[Client] >= 3000)
        {
            Cash[Client] += 80000;
            Pugan[Client] = 0;
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了金錢80000$!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 金錢的欲望!", Client);
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(Jenwu[Client] == 8)
    {
        if(TDaxinxin[Client] >= 50 && LQDY[Client] >= 15)
        {
            MFBS1[Client] += 1;
            TDaxinxin[Client] = 0;
            LQDY[Client] = 0;				
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了魔法寶石1塊!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 搶劫寶石!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(Jenwu[Client] == 9 && LQDY[Client] >= 20 && FHCS[Client] >= 8)
    {
        if(TPangzi[Client] >= 500)
        {
            Cash[Client] += 10000;
            ACL[Client] += 2;	
            BCL[Client] += 2;				
            TPangzi[Client] = 0;
            LQDY[Client] = 0;	
            FHCS[Client] = 0;				
            Tegan[Client] = 0;
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了金錢10000$和A、b材料2個!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 無人永生!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(Jenwu[Client] == 10 && LQDY[Client] >= 50 && FHCS[Client] >= 15)
    {
        if(THouzhi[Client] >= 200)
        {
            ACL[Client] += 2;				
            TDaxinxin[Client] = 0;
            LQDY[Client] = 0;	
            FHCS[Client] = 0;				
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 死亡之時!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(Jenwu[Client] == 11)
    {
        if(TDaxinxin[Client] >= 20 && TYangui[Client] >= 120 && LQDY[Client] >= 20 && FHCS[Client] >= 80)
        {
            SCL[Client] += 2;			
            TDaxinxin[Client] = 0;
            LQDY[Client] = 0;	
            FHCS[Client] = 0;				
            TYangui[Client] = 0;			
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了S材料2個!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 黑暗入侵!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(Jenwu[Client] == 13)
    {
        if(LQDY[Client] >= 500 && FHCS[Client] >= 500)
        {
            Eqbox[Client]++;		
            LQDY[Client] = 0;	
            FHCS[Client] = 0;						
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您獲得了炎神寶盒!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 勇者無畏!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }	
    if(Jenwu[Client] == 14)
    {
        if(LQDY[Client] >= 100 && FHCS[Client] >= 10)
        {
            KTCount[Client] -= 1;			
            LQDY[Client] = 0;	
            FHCS[Client] = 0;						
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            PrintHintText(Client, "【任務】完成任務,您的大過消除了一次!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 神的救贖!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(Jenwu[Client] == 15)
    {
        if(TDaxinxin[Client] >= 20)
        {		
            TDaxinxin[Client] = 0;						
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            YWZZSCQ(Client);		
            PrintHintText(Client, "【任務】完成任務,開始抽取影之匙!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: [職業]影武者之匙!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(Jenwu[Client] == 16)
    {
        if(YLDY[Client] >= 100)
        {			
            YLDY[Client] = 0;						
            Jenwu[Client] = 0;
            Renwu[Client] = 0;	
            PrintHintText(Client, "【任務】完成任務,!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 治療大隊!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }
    if(Jenwu[Client] == 17)
    {
        if(DDCS[Client] >= 50)
        {		
            DDCS[Client] = 0;						
            Jenwu[Client] = 0;
            Renwu[Client] = 0;
            Cash[Client] += 20000;		
            PrintHintText(Client, "【任務】完成任務,獲得20000金幣!");
            CPrintToChatAll("\x03【任務】玩家%N完成了任務: 嘗試失敗!", Client);			
        } else PrintHintText(Client, "【任務】你沒達到所需要求!");	
    }	
}	
public RENWUQI(Client)
{	
    if(Jenwu[Client] == 1)
    {
        Pugan[Client] = 0;
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    } MenuFunc_RPG(Client);
    if(Jenwu[Client] == 2)
    {
        TYangui[Client] = 0;
        TPangzi[Client] = 0;
        TLieshou[Client] = 0;
        TKoushui[Client] = 0;
        THouzhi[Client] = 0;
        TXiaoniu[Client] = 0;
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    } MenuFunc_RPG(Client);
    if(Jenwu[Client] == 3)
    {
        Pugan[Client] = 0;
        Tegan[Client] = 0;
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    } MenuFunc_RPG(Client);
    if(Jenwu[Client] == 4)
    {
        TLieshou[Client] = 0;
        Tegan[Client] = 0;
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    }
    if(Jenwu[Client] == 5)
    {
        TLieshou[Client] = 0;
        LQDY[Client] = 0;		
        Tegan[Client] = 0;
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    } MenuFunc_RPG(Client);
    if(Jenwu[Client] == 6)
    {
        Pugan[Client] = 0;
        LQDY[Client] = 0;		
        FHCS[Client] = 0;				
        Tegan[Client] = 0;
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    } MenuFunc_RPG(Client);
    if(Jenwu[Client] == 12)
    {
        Pugan[Client] = 0;
        Tegan[Client] = 0;
        FHCS[Client] = 0;			
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    }
    if(Jenwu[Client] == 7)
    {
        Pugan[Client] = 0;
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    } MenuFunc_RPG(Client);
    if(Jenwu[Client] == 8)
    {
        TDaxinxin[Client] = 0;
        LQDY[Client] = 0;		
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    } MenuFunc_RPG(Client);
    if(Jenwu[Client] == 9)
    {
        TPangzi[Client] = 0;
        Tegan[Client] = 0;
        FHCS[Client] = 0;	
        LQDY[Client] = 0;			
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    } MenuFunc_RPG(Client);
    if(Jenwu[Client] == 10)
    {
        THouzhi[Client] = 0;
        FHCS[Client] = 0;	
        LQDY[Client] = 0;			
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    } MenuFunc_RPG(Client);
    if(Jenwu[Client] == 11)
    {
        TDaxinxin[Client] = 0;
        TYangui[Client] = 0;	
        FHCS[Client] = 0;	
        LQDY[Client] = 0;			
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    } MenuFunc_RPG(Client);
    if(Jenwu[Client] == 13)
    {
        TDaxinxin[Client] = 0;	
        FHCS[Client] = 0;	
        LQDY[Client] = 0;			
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    } MenuFunc_RPG(Client);
    if(Jenwu[Client] == 14)
    {	
        FHCS[Client] = 0;	
        LQDY[Client] = 0;			
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    } MenuFunc_RPG(Client);	
    if(Jenwu[Client] == 15)
    {	
        TDaxinxin[Client] = 0;			
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    } MenuFunc_RPG(Client);		
    if(Jenwu[Client] == 16)
    {		
        YLDY[Client] = 0;			
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    } MenuFunc_RPG(Client);
    if(Jenwu[Client] == 17)
    {		
        DDCS[Client] = 0;			
        Jenwu[Client] = 0;
        Renwu[Client] = 0;
        PrintHintText(Client, "【任務】你可以接受新任務了!");
    } MenuFunc_RPG(Client);		
}

public YWZZSCQ(Client)
{
    if(Lv[Client] >= 0)   
	{
	    new ZXRWLQSD = GetRandomInt(1, 6);
		
	    switch (ZXRWLQSD)       
	    {    	
			case 1:           
			{    
	           YWZZS[Client] += 1;
	           CPrintToChatAll("\x03【任務】玩家%N完成了任務抽到了影之匙!", Client);					   
			}
			case 2:           
			{    
	           YWZZS[Client] += 1;
	           CPrintToChatAll("\x03【任務】玩家%N完成了任務抽到了影之匙!", Client);					   
			}
			case 3:           
			{    
	           CPrintToChatAll("\x03【任務】玩家%N完成了任務沒抽到影之匙!", Client);					   
			}
			case 4:           
			{    
	           CPrintToChatAll("\x03【任務】玩家%N完成了任務沒抽到影之匙!", Client);					   
			}
			case 5:           
			{    
	           CPrintToChatAll("\x03【任務】玩家%N完成了任務沒抽到影之匙!", Client);					   
			}
			case 6:           
			{    
	           CPrintToChatAll("\x03【任務】玩家%N完成了任務沒抽到影之匙!", Client);					   
			}			
	    }
    }
}
