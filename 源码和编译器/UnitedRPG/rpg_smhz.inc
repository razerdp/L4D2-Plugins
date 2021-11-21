/* 神秘盒子 */
public Action:MenuFunc_SMHZK(Client)
{
	new Handle:menu = CreatePanel();

	decl String:line[1024];
	Format(line, sizeof(line), "═══神秘盒子 (拥有: %d个)═══", SMHZ[Client]);
	SetPanelTitle(menu, line);
	Format(line, sizeof(line), "据说开出来的都是神装:装备有5天10天15天20天和30天!");
	DrawPanelText(menu, line);

	Format(line, sizeof(line), "购买盒子(需玄币:2000)");
	DrawPanelItem(menu, line);

	Format(line, sizeof(line), "开启盒子(需金币:1000)");
	DrawPanelItem(menu, line);
	DrawPanelItem(menu, "离开", ITEMDRAW_DISABLED);

	SendPanelToClient(menu, Client, MenuHandler_SMHZK, MENU_TIME_FOREVER);
	return Plugin_Handled;
}

public MenuHandler_SMHZK(Handle:menu, MenuAction:action, Client, param)
{
	if (action == MenuAction_Select)
	{
		switch (param)
		{
			case 1: SMHZ111(Client);
            case 2: UseSMHZJ(Client);
		}
	}
}

public SMHZ111(Client)
{
    if(XB[Client] >= 2000)
    {
        XB[Client] -= 2000;
        SMHZ[Client]++;
        CPrintToChat(Client,"\x03[系统]\04你\x04购买了\x05 【神秘盒子】,当前玄币%d!", XB[Client]);	CPrintToChat(Client,"\x03[系统]\x04成功购买0(*^__^*)0!");
	} else CPrintToChat(Client, "\x05【提示】你没有足够的玄!");
    MenuFunc_SMHZK(Client)
}

public Action:UseSMHZJ(Client)
{
    if(Cash[Client] >= 1000)
	{

	    if(SMHZ[Client]>0)
	    {
            SMHZ[Client]--;Cash[Client] -= 1000;
            new diceNum;
            diceNum = GetRandomInt(1, 110);
            switch (diceNum)
		    {
                case 1:
			    {
                    SetZBItemTime(Client, 110, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的武器】5日!", Client);
                }
				case 2:
			    {
                    SetZBItemTime(Client, 110, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的武器】10日!", Client);
                }
				case 3:
			    {
                    SetZBItemTime(Client, 110, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的武器】15日!", Client);
                }
				case 4:
			    {
                    SetZBItemTime(Client, 110, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的武器】20日!", Client);
                }
				case 5:
			    {
                    SetZBItemTime(Client, 110, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的武器】30日!", Client);
                }
				case 6:
			    {
                    SetZBItemTime(Client, 109, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的鞋子】5日!", Client);
                }
				case 7:
			    {
                    SetZBItemTime(Client, 109, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的鞋子】10日!", Client);
                }
				case 8:
			    {
                    SetZBItemTime(Client, 109, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的鞋子】15日!", Client);
                }
				case 9:
			    {
                    SetZBItemTime(Client, 109, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的鞋子】20日!", Client);
                }
				case 10:
			    {
                    SetZBItemTime(Client, 109, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的武器】30日!", Client);
                }
			    case 11:
			    {
                    SetZBItemTime(Client, 108, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的腰带】5日!", Client);
                }
				case 12:
			    {
                    SetZBItemTime(Client, 108, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的腰带】10日!", Client);
                }
				case 13:
			    {
                    SetZBItemTime(Client, 108, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的腰带】15日!", Client);
                }
				case 14:
			    {
                    SetZBItemTime(Client, 108, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的腰带】20日!", Client);
                }
				case 15:
			    {
                    SetZBItemTime(Client, 108, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的腰带】30日!", Client);
                }
				case 16:
			    {
                    SetZBItemTime(Client, 107, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的头盔】5日!", Client);
                }
				case 17:
			    {
                    SetZBItemTime(Client, 107, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的头盔】10日!", Client);
                }
				case 18:
			    {
                    SetZBItemTime(Client, 107, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的头盔】15日!", Client);
                }
				case 19:
			    {
                    SetZBItemTime(Client, 107, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的头盔】20日!", Client);
                }
				case 20:
			    {
                    SetZBItemTime(Client, 107, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的头盔】30日!", Client);
                }
				case 21:
			    {
                    SetZBItemTime(Client, 106, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的护肩】5日!", Client);
                }
				case 22:
			    {
                    SetZBItemTime(Client, 106, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的护肩】10日!", Client);
                }
				case 23:
			    {
                    SetZBItemTime(Client, 106, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的护肩】15日!", Client);
                }
				case 24:
			    {
                    SetZBItemTime(Client, 106, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的护肩】20日!", Client);
                }
				case 25:
			    {
                    SetZBItemTime(Client, 106, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的护肩】30日!", Client);
                }
				case 26:
			    {
                    SetZBItemTime(Client, 105, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的护甲】5日!", Client);
                }
				case 27:
			    {
                    SetZBItemTime(Client, 105, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的护甲】10日!", Client);
                }
				case 28:
			    {
                    SetZBItemTime(Client, 105, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的护甲】15日!", Client);
                }
				case 29:
			    {
                    SetZBItemTime(Client, 105, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的护甲】20日!", Client);
                }
				case 30:
			    {
                    SetZBItemTime(Client, 105, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【小野的护甲】30日!", Client);
                }
				case 31:
			    {
                    SetZBItemTime(Client, 99, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之力[神]】5日!", Client);
                }
				case 32:
			    {
                    SetZBItemTime(Client, 99, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之力[神]】10日!", Client);
                }
				case 33:
			    {
                    SetZBItemTime(Client, 99, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之力[神]】15日!", Client);
                }
				case 34:
			    {
                    SetZBItemTime(Client, 99, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之力[神]】20日!", Client);
                }
				case 35:
			    {
                    SetZBItemTime(Client, 99, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之力[神]】30日!", Client);
                }
				case 36:
			    {
                    SetZBItemTime(Client, 100, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之盾[神]】5日!", Client);
                }
				case 37:
			    {
                    SetZBItemTime(Client, 100, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之盾[神]】10日!", Client);
                }
				case 38:
			    {
                    SetZBItemTime(Client, 100, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之盾[神]】15日!", Client);
                }
				case 39:
			    {
                    SetZBItemTime(Client, 100, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之盾[神]】20日!", Client);
                }
				case 40:
			    {
                    SetZBItemTime(Client, 100, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之盾[神]】30日!", Client);
                }
				case 41:
			    {
                    SetZBItemTime(Client, 101, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之矛[神]】5日!", Client);
                }
				case 42:
			    {
                    SetZBItemTime(Client, 101, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之矛[神]】10日!", Client);
                }
				case 43:
			    {
                    SetZBItemTime(Client, 101, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之矛[神]】15日!", Client);
                }
				case 44:
			    {
                    SetZBItemTime(Client, 101, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之矛[神]】20日!", Client);
                }
				case 45:
			    {
                    SetZBItemTime(Client, 101, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之矛[神]】30日!", Client);
                }
				case 46:
			    {
                    SetZBItemTime(Client, 102, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之炎】5日!", Client);
                }
				case 47:
			    {
                    SetZBItemTime(Client, 102, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之炎】10日!", Client);
                }
				case 48:
			    {
                    SetZBItemTime(Client, 102, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之炎】15日!", Client);
                }
				case 49:
			    {
                    SetZBItemTime(Client, 102, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之炎】20日!", Client);
                }
				case 50:
			    {
                    SetZBItemTime(Client, 102, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之炎】30日!", Client);
                }
				case 51:
			    {
                    SetZBItemTime(Client, 103, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之翼[神]】5日!", Client);
                }
				case 52:
			    {
                    SetZBItemTime(Client, 103, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之翼[神]】10日!", Client);
                }
				case 53:
			    {
                    SetZBItemTime(Client, 103, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之翼[神]】15日!", Client);
                }
				case 54:
			    {
                    SetZBItemTime(Client, 103, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之翼[神]】20日!", Client);
                }
				case 55:
			    {
                    SetZBItemTime(Client, 103, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之翼[神]】30日!", Client);
                }
				case 56:
			    {
                    SetZBItemTime(Client, 104, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之手[神]】5日!", Client);
                }
				case 57:
			    {
                    SetZBItemTime(Client, 104, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之手[神]】10日!", Client);
                }
				case 58:
			    {
                    SetZBItemTime(Client, 104, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之手[神]】15日!", Client);
                }
				case 59:
			    {
                    SetZBItemTime(Client, 104, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之手[神]】20日!", Client);
                }
				case 60:
			    {
                    SetZBItemTime(Client, 104, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【末世之手[神]】30日!", Client);
                }
				case 61:
			    {
                    SetZBItemTime(Client, 89, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【龙王之怒】5日!", Client);
                }
				case 62:
			    {
                    SetZBItemTime(Client, 89, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【龙王之怒】10日!", Client);
                }
				case 63:
			    {
                    SetZBItemTime(Client, 89, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【龙王之怒】15日!", Client);
                }
				case 64:
			    {
                    SetZBItemTime(Client, 89, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【龙王之怒】20日!", Client);
                }
				case 65:
			    {
                    SetZBItemTime(Client, 89, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【龙王之怒】30日!", Client);
                }
				case 66:
			    {
                    SetZBItemTime(Client, 80, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【雷神】5日!", Client);
                }
				case 67:
			    {
                    SetZBItemTime(Client, 80, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【雷神】10日!", Client);
                }
				case 68:
			    {
                    SetZBItemTime(Client, 80, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【雷神】15日!", Client);
                }
				case 69:
			    {
                    SetZBItemTime(Client, 80, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【雷神】20日!", Client);
                }
				case 70:
			    {
                    SetZBItemTime(Client, 80, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【雷神】30日!", Client);
                }
				case 71:
			    {
                    SetZBItemTime(Client, 78, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【黑暗骑士】5日!", Client);
                }
				case 72:
			    {
                    SetZBItemTime(Client, 78, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【黑暗骑士】10日!", Client);
                }
				case 73:
			    {
                    SetZBItemTime(Client, 78, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【黑暗骑士】15日!", Client);
                }
				case 74:
			    {
                    SetZBItemTime(Client, 78, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【黑暗骑士】20日!", Client);
                }
				case 75:
			    {
                    SetZBItemTime(Client, 78, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【黑暗骑士】30日!", Client);
                }
				case 76:
			    {
                    SetZBItemTime(Client, 79, 5, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【黑暗加农】5日!", Client);
                }
				case 77:
			    {
                    SetZBItemTime(Client, 79, 10, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【黑暗加农】10日!", Client);
                }
				case 78:
			    {
                    SetZBItemTime(Client, 79, 15, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【黑暗加农】15日!", Client);
                }
				case 79:
			    {
                    SetZBItemTime(Client, 79, 20, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【黑暗加农】20日!", Client);
                }
				case 80:
			    {
                    SetZBItemTime(Client, 79, 30, false);
                    MenuFunc_SMHZK(Client);
                    CPrintToChatAll("\x05【公告】玩家%N打开神秘盒子获【黑暗加农】30日!", Client);
                }
            }
	    } else PrintHintText(Client, "【提示】你没有神秘盒子!");
    } else CPrintToChat(Client, "\x05【提示】所需金币不够, 无法开启!");
    return Plugin_Handled;
}

