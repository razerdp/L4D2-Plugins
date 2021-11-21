new Handle:H_TopMenu;
new ExchangeClientIndex[MAXPLAYERS+1];

Menu_CDKeyMenu_Select(Client,Handle:h_TopMenu)
{
	H_TopMenu = h_TopMenu;
	new Handle:menu = CreateMenu(AdminCDKey_MenuHandler);
	SetMenuTitle(menu, "CDKey系统:");
	AddMenuItem(menu, "", "生成CDKey(公用)");
	AddMenuItem(menu, "", "生成CDKey(绑定帐户)");
	SetMenuExitBackButton(menu, true);
	DisplayMenu(menu, Client, MENU_TIME_FOREVER);
}
public AdminCDKey_MenuHandler(Handle:menu, MenuAction:action, Client, param2)
{
	if (action == MenuAction_End)
	{
		CloseHandle(menu);
	}
	else if (action == MenuAction_Cancel)
	{
		if (param2 == MenuCancel_ExitBack && H_TopMenu != INVALID_HANDLE)
		{
			DisplayTopMenu(H_TopMenu, Client, TopMenuPosition_LastCategory);
		}
	}
	else if (action == MenuAction_Select)
	{
		switch(param2)
		{
			case 0:
			{
				Menu_CDKeyMenu_Exchange(Client);
			}
			case 1:
			{
				Menu_CDKeyMenu_Bind(Client);
			}
		}
	}
}

Menu_CDKeyMenu_Bind(Client)
{
	new Handle:menu_bind = CreateMenu(AdminCDKey_MenuHandler_BindAccount);
	SetMenuTitle(menu_bind, "选择绑定用户:");
	ExchangeClientIndex[Client] = 0;
	for(new i=1;i<MaxClients;i++)
	{
		if(IsValidPlayer(i) && IsPasswordConfirm[i])
		{
			new String:Name[32];
			new String:UserID[4];
			Format(Name,sizeof(Name),"%N",i);
			Format(UserID,sizeof(UserID),"%d",i);

			AddMenuItem(menu_bind, UserID, Name);
		}
	}
				
	SetMenuExitBackButton(menu_bind, true);
	DisplayMenu(menu_bind, Client, MENU_TIME_FOREVER);
}
public AdminCDKey_MenuHandler_BindAccount(Handle:menu, MenuAction:action, Client, param2)
{
	if (action == MenuAction_End)
	{
		CloseHandle(menu);
	}
	else if (action == MenuAction_Cancel)
	{
		if (param2 == MenuCancel_ExitBack && H_TopMenu != INVALID_HANDLE)
		{
			Menu_CDKeyMenu_Select(Client,H_TopMenu);
		}
	}
	else if (action == MenuAction_Select)
	{
		new String:info[4];
		GetMenuItem(menu, param2, info, sizeof(info));
		ExchangeClientIndex[Client] = StringToInt(info);
		Menu_CDKeyMenu_Exchange(Client);
	}	
}

Menu_CDKeyMenu_Exchange(Client)
{
	new Handle:menu_Exchange = CreateMenu(AdminCDKey_MenuHandler_Exchange);
	SetMenuTitle(menu_Exchange, "请选择玄币数量:");
	
	AddMenuItem(menu_Exchange, "100", "100");
	AddMenuItem(menu_Exchange, "200", "200");
	AddMenuItem(menu_Exchange, "1000", "1000");
	AddMenuItem(menu_Exchange, "2500", "2500");
	AddMenuItem(menu_Exchange, "5000", "5000");
	AddMenuItem(menu_Exchange, "10000", "10000");
	AddMenuItem(menu_Exchange, "25000", "25000");

	SetMenuExitBackButton(menu_Exchange, true);
	DisplayMenu(menu_Exchange, Client, MENU_TIME_FOREVER);
}
public AdminCDKey_MenuHandler_Exchange(Handle:menu, MenuAction:action, Client, param2)
{
	if (action == MenuAction_End)
	{
		CloseHandle(menu);
	}
	else if (action == MenuAction_Cancel)
	{
		if (param2 == MenuCancel_ExitBack)
		{
			new Target = ExchangeClientIndex[Client];

			if(Target)
			{
				Menu_CDKeyMenu_Bind(Client);
			}
			else
			{
				Menu_CDKeyMenu_Select(Client,H_TopMenu);
			}
		}
	}
	else if (action == MenuAction_Select)
	{
		new String:info[12];
		new const cdkey_len = GetConVarInt(h_CDKeyLen)+1;
		new String:CDKey[cdkey_len];
		GetMenuItem(menu, param2, info, sizeof(info));
		GetRandomSignature(CDKey,cdkey_len);
		if(strlen(CDKey) && !IsInvalidSignature(CDKey))
		{
			new Target = ExchangeClientIndex[Client];
			new x_b = StringToInt(info);
			new String:TargetName[32];
			new String:ThisTime[16];
			
			if(!SQLite_IsFieldExists(h_SQLiteDatabase, CDKeyTable, CDKey))
			{
				PrintToChat(Client,"此CDKey生成有效!");
				
				if(IsValidPlayer(Target))
				{
					PrintToChat(Client,"\x01成功生成CDKey: \x04%s \x01| 价值:%d玄币 | 授权:%N",CDKey,x_b,Target);
					Format(TargetName,sizeof(TargetName), "%N", Target);
				}
				else
				{
					PrintToChat(Client,"\x01成功生成CDKey: \x04%s \x01| 价值:%d玄币 | 授权:公用",CDKey,x_b);
				}
				
				FormatTime(ThisTime,sizeof(ThisTime),"%Y%m%d",-1);
			
				SQLite_Insert(h_SQLiteDatabase, false, CDKeyTable, "CDKey, InValid, ExchangeXB, BindAccount, CDKeySpawnedTime", "'%s' ,%d ,%d, '%s', '%s'", CDKey, 0, x_b, strlen(TargetName)?TargetName:"", ThisTime);
			}
			else
			{
				PrintToChat(Client,"此CDKey生成无效,请重新生成(可能已经存在于数据库中)");
				Menu_CDKeyMenu_Exchange(Client);
				return;
			}
				
			ExchangeClientIndex[Client] = 0;
		}
		else
		{
			PrintToChat(Client,"所生成的CDKey格式可能不对,请检查源码.");
		}
	}	
}