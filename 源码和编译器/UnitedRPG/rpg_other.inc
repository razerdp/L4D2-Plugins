/************************************************************************
*	其他功能
************************************************************************/

//伤害显示
public DisplayDamage(const Damage, const DeadType, const attacker)
{
	for(new i = DamageDisplayBuffer-1; i >= 1; i--)
	{
		strcopy(DamageDisplayString[attacker][i], DamageDisplayLength, DamageDisplayString[attacker][i-1]);
	}
	switch (DeadType)
	{
		case ALIVE: Format(DamageDisplayString[attacker][0], DamageDisplayLength, MSG_DAMAGEDISPLAY, Damage);
		case NORMALDEAD: Format(DamageDisplayString[attacker][0], DamageDisplayLength, MSG_DAMAGEDISPLAY_DEAD, Damage);
		case HEADSHOT: Format(DamageDisplayString[attacker][0], DamageDisplayLength, MSG_DAMAGEDISPLAY_HEADSHOT, Damage);
	}
	PrintCenterText(attacker, "%s\n%s\n%s\n%s\n%s", DamageDisplayString[attacker][4], DamageDisplayString[attacker][3], DamageDisplayString[attacker][2], DamageDisplayString[attacker][1], DamageDisplayString[attacker][0]);
	if(DamageDisplayCleanTimer[attacker] != INVALID_HANDLE)	KillTimer(DamageDisplayCleanTimer[attacker]);
	DamageDisplayCleanTimer[attacker] = CreateTimer(2.5, DamageDisplayCleanTimerFunction, attacker);
}

public Action:DamageDisplayCleanTimerFunction(Handle:timer, any:Client)
{
	KillTimer(timer);
	DamageDisplayCleanTimer[Client] = INVALID_HANDLE;
	if(IsValidPlayer(Client))
	{
		if(!IsFakeClient(Client))
		{
			for(new j = 0; j < DamageDisplayBuffer; j++)
			{
				strcopy(DamageDisplayString[Client][j], DamageDisplayLength, "");
			}
		}
	}
}

public Action:ZombiesKillCountFunction(Handle:timer, any:attacker)
{
	KillTimer(timer);
	ZombiesKillCountTimer[attacker] = INVALID_HANDLE;
	if (IsValidPlayer(attacker))
	{
		if(JD[attacker] == 7)        
		{           
			Hunpo[attacker] += ZombiesKillCount[attacker];
			CPrintToChat(attacker, "{green}【魂魄】成功击杀,您获得了感染者魂魄!");      
		}
		if(XGSLZ[attacker] == 0)
        {
            if(XGSL[attacker] < 100000)
            {
                XGSL[attacker] += ZombiesKillCount[attacker];
            }
            if(XGSL[attacker] == 100000)
            {
                XGSLZ[attacker] = 1;							
            }				
        }		
		if(Renwu[attacker] == 1)
        {
            if(Jenwu[attacker] == 1)
            {
                Pugan[attacker] += ZombiesKillCount[attacker];
            }
            if(Jenwu[attacker] == 3)
            {
                Pugan[attacker] += ZombiesKillCount[attacker];
            }
            if(Jenwu[attacker] == 6)
            {
                Pugan[attacker] += ZombiesKillCount[attacker];
            }
            if(Jenwu[attacker] == 7)
            {
                Pugan[attacker] += ZombiesKillCount[attacker];
            }
            if(Jenwu[attacker] == 12)
            {
                Pugan[attacker] += ZombiesKillCount[attacker];
            }			
        }	
		if(ZXRW[attacker] == 1)
        {
            if(KSZXRW[attacker] == 1)
            {
                PTJS[attacker] += ZombiesKillCount[attacker];
            }
            if(KSZXRW[attacker] == 4)
            {
                PTJS[attacker] += ZombiesKillCount[attacker];
            }	
            if(KSZXRW[attacker] == 6)
            {
                PTJS[attacker] += ZombiesKillCount[attacker];
            }
            if(KSZXRW[attacker] == 8)
            {
                PTJS[attacker] += ZombiesKillCount[attacker];
            }			
        }		
		if (ZombiesKillCount[attacker] > 0)
		{
			EXP[attacker] += (GetConVarInt(ZombieKilledExp)*ZombiesKillCount[attacker]);
			Cash[attacker] += GetConVarInt(ZombieKilledCash)*ZombiesKillCount[attacker] + VIPAdd(attacker, GetConVarInt(ZombieKilledCash)*ZombiesKillCount[attacker], 1, false);
			CPrintToChat(attacker, MSG_EXP_KILL_ZOMBIES, ZombiesKillCount[attacker], GetConVarInt(ZombieKilledExp)*ZombiesKillCount[attacker], GetConVarInt(ZombieKilledCash)*ZombiesKillCount[attacker]);
		}
		ZombiesKillCount[attacker]=0;
	}
}

//旁观超时踢出
public Action:Timer_KickLookOnPlayer(Handle:timer, any:Client)
{
	new kicktime;
	if (VIP[Client] >= 1)
		kicktime = 300;
	else
		kicktime = 150;
		
	if (IsValidPlayer(Client) && !IsFakeClient(Client) && GetClientTeam(Client) == 1)
	{
		if (IsAdminPlayer(Client))
			KillTimer(timer);
			
		KickLookOnPlayer[Client]++;
		if (KickLookOnPlayer[Client] >= kicktime)
		{
			KickClient(Client, "由于你旁观过久,已经被服务器踢出.");
			CPrintToChatAll("\x05[系统]\x03由于\x05%N\x03旁观时间超过\x055分钟\x03,已被服务器踢出!", Client);
			KickLookOnPlayer[Client] = 0;
			KillTimer(timer);
		}
		else
		{
			//if (VIP[Client] >= 1)
				//PrintHintText(Client, "你正在旁观, %d 秒后会被踢出(会员:600+1200秒),输入!rpg选择加入游戏即可加入游戏!", kicktime - KickLookOnPlayer[Client]);
			//else
			    PrintHintText(Client, "你正在旁观, %d 秒后会被踢出,输入!join选择加入游戏即可加入游戏!", kicktime - KickLookOnPlayer[Client]);
		}
	}
	else
		KickLookOnPlayer[Client] = 0, KillTimer(timer);
}

//取暴击伤害
public GetCritsDmg(Client, Dmg)
{
	new Float:Random = GetRandomFloat(0.0 , 100.0);
	if (Random <= CritsEffect[Client])
	{
		new Float:RandomDmg = GetRandomFloat(CritMinEffect[Client], CritMaxEffect[Client]);
		new CritDmg = RoundToNearest(Dmg * RandomDmg * 2);
		if (CritDmg > 0)
			return CritDmg;
	}
	else
		return 0;
		
	return 0;
}
//取团队当前人数
stock CountPlayersTeam(team, bool:allowfake = false)
{
	new Count = 0;
	for (new i=1;i<=MaxClients;i++)
	{
		if (IsClientConnected(i) && IsClientInGame(i) && GetClientTeam(i) == team)
		{
			if (!allowfake)
			{
				if (!IsFakeClient(i))
					Count++;
			}
			else
				Count++;
		}
	}
	return Count;
}

//检查服务器当前人数
public GetAllPlayerCount()
{
	new count = 0;
	for (new i = 1; i <= MaxClients; i++)
	{
		if (IsValidPlayer(i) && !IsFakeClient(i))
		{
			count++;
		}
	}
	
	return count;
}

//检查服务器最大人数
public maxclToolzDowntownCheck()
{
	new Handle:invalid = INVALID_HANDLE;
	new Handle:downtownrun = FindConVar("l4d_maxplayers");
	new Handle:toolzrun = FindConVar("sv_maxplayers");
	new connectmaxnum;
	
	//游戏默认人数在运作
	if (downtownrun != invalid)
	{
		//Is Downtown used for slot patching? if yes use it for Max Players
		new downtown = GetConVarInt(FindConVar("l4d_maxplayers"));
		if (downtown >= 1)
		{
			connectmaxnum = GetConVarInt(FindConVar("l4d_maxplayers"));
		}
	}

	//L4DToolz人数控制在运作
	if (toolzrun != invalid)
	{
		//Is L4DToolz used for slot patching? if yes use it for Max Players
		new toolz = GetConVarInt(FindConVar("sv_maxplayers"));
		if (toolz >= 1)
		{
			connectmaxnum = GetConVarInt(FindConVar("sv_maxplayers"));
		}
	}

	//No Downtown or L4DToolz running using fallback (possible x/32)
	if (downtownrun == invalid && toolzrun == invalid)
	{
		connectmaxnum = MaxClients;
	}
	return connectmaxnum;
}

public bool:WeaponIsGun(String:weapon[])
{
	if (StrEqual(weapon, "pistol", false))
		return true;
	if (StrEqual(weapon, "pistol_magnum", false))
		return true;
	if (StrEqual(weapon, "smg_silenced", false))
		return true;
	if (StrEqual(weapon, "smg", false))
		return true;
	if (StrEqual(weapon, "pumpshotgun", false))
		return true;
	if (StrEqual(weapon, "shotgun_chrome", false))
		return true;
	if (StrEqual(weapon, "autoshotgun", false))
		return true;
	if (StrEqual(weapon, "shotgun_spas", false))
		return true;
	if (StrEqual(weapon, "hunting_rifle", false))
		return true;
	if (StrEqual(weapon, "sniper_military", false))
		return true;
	if (StrEqual(weapon, "rifle", false))
		return true;
	if (StrEqual(weapon, "rifle_ak47", false))
		return true;	
	if (StrEqual(weapon, "rifle_desert", false))
		return true;
	if (StrEqual(weapon, "grenade_launcher", false))
		return true;
	if (StrEqual(weapon, "rifle_m60", false))
		return true;
	if (StrEqual(weapon, "rifle_sg552", false))
		return true;
	if (StrEqual(weapon, "smg_mp5", false))
		return true;
	if (StrEqual(weapon, "sniper_awp", false))
		return true;
	if (StrEqual(weapon, "sniper_scout", false))
		return true;
		
	return false;
}

/* 判断玩家是否有效 */
stock bool:IsValidPlayer(Client, bool:AllowBot = true, bool:AllowDeath = true)
{
	if (Client < 1 || Client > MaxClients)
		return false;
	if (!IsClientConnected(Client) || !IsClientInGame(Client))
		return false;
	if (!AllowBot)
	{
		if (IsFakeClient(Client))
			return false;
	}

	if (!AllowDeath)
	{
		if (!IsPlayerAlive(Client))
			return false;
	}	
	
	return true;
}

/* 是否管理员 */
public bool:IsAdminPlayer(Client)
{
	new AdminId:admin = GetUserAdmin(Client);
	if(admin != INVALID_ADMIN_ID)
		return true;
	else
		return false;
}

/* 检查队伍是否已满 */
stock bool:IsTeamFull(team)
{
	// Spectator's team is never full :P
	if (team == 1)
		return false;
	
	new SurvivorMaxPlayer = GetConVarInt(cv_survivor_limit);
	new InfectedMaxPlayer = GetConVarInt(cv_infected_limit);
	new max;
	new count;
	new i;
	
	// we count the players in the survivor's team
	if (team == 2)
	{
		max = SurvivorMaxPlayer;
		count = 0;
		for (i=1; i<=MaxClients; i++)
			if (IsClientInGame(i) && !IsFakeClient(i) && GetClientTeam(i)==2)
				count++;
		}
	else if (team == 3) // we count the players in the infected's team
	{
		max = InfectedMaxPlayer;
		count = 0;
		for (i=1; i<=MaxClients; i++)
			if (IsClientInGame(i) && !IsFakeClient(i) && GetClientTeam(i)==3)
				count++;
		}
	
	// If full ...
	if (count >= max)	return true;
	else	return false;
}



stock bool:IsPlayerOnFire(Client)
{
	if (GetEntProp(Client, Prop_Data, "m_fFlags") & FL_ONFIRE)
		return true;
	return false;
}
stock bool:IsPlayerOnGround(Client)
{
	if (GetEntDataEnt2(Client, FindSendPropOffs("CBasePlayer", "m_hGroundEntity")) != -1)
		return true;
	return false;
}

stock bool:IsCommonInfected(iEntity)
{
	if(iEntity > 0 && IsValidEntity(iEntity) && IsValidEdict(iEntity))
	{
		decl String:strClassName[64];
		GetEdictClassname(iEntity, strClassName, sizeof(strClassName));
		return StrEqual(strClassName, "infected");
	}
	return false;
}

stock bool:IsWitch(iEntity)
{
	if(iEntity > 0 && IsValidEntity(iEntity) && IsValidEdict(iEntity))
	{
		decl String:strClassName[64];
		GetEdictClassname(iEntity, strClassName, sizeof(strClassName));
		return StrEqual(strClassName, "witch");
	}
	return false;
}

stock bool:IsPlayerGhost(Client)
{
	if (GetEntProp(Client, Prop_Send, "m_isGhost", 1) == 1)
		return true;
	return false;
}

stock bool:IsPlayerIncapped(Client)
{
	if (GetEntProp(Client, Prop_Send, "m_isIncapacitated") == 1)
		return true;
	else
		return false;
}

/* Execute Cheat Commads */
stock CheatCommand(Client, const String:command[], const String:arguments[])
{
    if (!Client) return;
    new admindata = GetUserFlagBits(Client);
    SetUserFlagBits(Client, ADMFLAG_ROOT);
    new flags = GetCommandFlags(command);
    SetCommandFlags(command, flags & ~FCVAR_CHEAT);
    FakeClientCommand(Client, "%s %s", command, arguments);
    SetCommandFlags(command, flags);
    SetUserFlagBits(Client, admindata);
}

/* 获取所观察的玩家信息 */
public Action:GetObserverTargetInfo(Client)
{
	if(!IsValidEntity(Client) || !IsClientInGame(Client))
		return Plugin_Handled;
		
	new mode	= GetEntPropEnt(Client, Prop_Send, "m_iObserverMode"),
		target	= GetEntPropEnt(Client, Prop_Send, "m_hObserverTarget");
	
	if (!IsValidPlayer(target, false))
		return Plugin_Handled;
	
	//mode -1未定义 0自己 1刚死亡时 2未知 3未知 4第一视角 5第三视角 6自由视角
	if((mode!=4 && mode!=5) || target==-1)
		return Plugin_Handled;
	
	new String:playerjod[16], String:s_vip[16], String:MYCH[16], String:MYTS[16];
	new health = GetEntProp(target, Prop_Data, "m_iHealth");
	new ZBNUM = GetHasZBItemCount(target);	
	if (JD[target] == 1)
		Format(playerjod, sizeof(playerjod), "工程师");
	else if (JD[target] == 2)
		Format(playerjod, sizeof(playerjod), "士兵");
	else if (JD[target] == 3)
		Format(playerjod, sizeof(playerjod), "圣骑士");
	else if (JD[target] == 4)
		Format(playerjod, sizeof(playerjod), "心灵医生");
	else if (JD[target] == 5)
		Format(playerjod, sizeof(playerjod), "魔法师");
	else if (JD[target] == 6)
		Format(playerjod, sizeof(playerjod), "弹药专家");
	else if (JD[target] == 7)
		Format(playerjod, sizeof(playerjod), "地狱使者");	
	else if (JD[target] == 8)
		Format(playerjod, sizeof(playerjod), "死神");
	else if (JD[target] == 9)
		Format(playerjod, sizeof(playerjod), "黑暗行者");		
	else if (JD[target] == 10)
		Format(playerjod, sizeof(playerjod), "死亡祭师");	
	else if (JD[target] == 11)
		Format(playerjod, sizeof(playerjod), "雷电使者");	
	else if (JD[target] == 12)
		Format(playerjod, sizeof(playerjod), "影武者");
	else if (JD[target] == 13)
		Format(playerjod, sizeof(playerjod), "审判者");	
	else if (JD[target] == 14)
		Format(playerjod, sizeof(playerjod), "毒龙");
	else if (JD[target] == 15)
		Format(playerjod, sizeof(playerjod), "幻影统帅");		
	else
		Format(playerjod, sizeof(playerjod), "未转职");
		
	if (VIP[target] == 1)
		Format(s_vip, sizeof(s_vip), "[白银VIP]");
	else if (VIP[target] == 2)
		Format(s_vip, sizeof(s_vip), "[黄金VIP]");
	else if (VIP[target] == 3)
		Format(s_vip, sizeof(s_vip), "[水晶VIP]");
	else if (VIP[target] == 4)
		Format(s_vip, sizeof(s_vip), "[至尊VIP]");
	else if (VIP[target] == 5)
		Format(s_vip, sizeof(s_vip), "[管理VIP]");
	else if (VIP[target] == 6)
		Format(s_vip, sizeof(s_vip), "[服主VIP]");
	else if (VIP[target] <= 0)
		Format(s_vip, sizeof(s_vip), "[普通玩家]");

	if (BJCH[target] == 1)
		Format(MYCH, sizeof(MYCH), "坦克杀手");
	else if (BJCH[target] == 2)
		Format(MYCH, sizeof(MYCH), "僵尸猎手");
	else if (BJCH[target] == 3)
		Format(MYCH, sizeof(MYCH), "拒绝乘骑");
	else if (BJCH[target] == 4)
		Format(MYCH, sizeof(MYCH), "文明者");
	else if (BJCH[target] == 5)
		Format(MYCH, sizeof(MYCH), "瘦身教练");	
	else if (BJCH[target] == 6)
		Format(MYCH, sizeof(MYCH), "执法者");
	else if (BJCH[target] == 7)
		Format(MYCH, sizeof(MYCH), "哭泣杀手");		
	else if (BJCH[target] == 8)
		Format(MYCH, sizeof(MYCH), "救助者");	
	else if (BJCH[target] == 9)
		Format(MYCH, sizeof(MYCH), "好队友");	
	else if (BJCH[target] == 10)
		Format(MYCH, sizeof(MYCH), "强化好手");
	else if (BJCH[target] == 11)
		Format(MYCH, sizeof(MYCH), "百折不挠");	
	else if (BJCH[target] == 12)
		Format(MYCH, sizeof(MYCH), "拒绝吸烟");			
	else
		Format(MYCH, sizeof(MYCH), "未获得");		
		
	if (ticeship[Client] < 1)
		Format(MYTS, sizeof(MYTS), "吊儿郎当");
	else if (ticeship[Client] >= 1 && ticeship[Client] <= 3)
		Format(MYTS, sizeof(MYTS), "初出茅庐");
	else if (ticeship[Client] >= 4 && ticeship[Client] <= 6)
		Format(MYTS, sizeof(MYTS), "略有小成");
	else if (ticeship[Client] >= 7 && ticeship[Client] <= 9)
		Format(MYTS, sizeof(MYTS), "为人师表");
	else if (ticeship[Client] >= 10 && ticeship[Client] <= 12)
		Format(MYTS, sizeof(MYTS), "一代宗师");	
	else if (ticeship[Client] >= 13)
		Format(MYTS, sizeof(MYTS), "万人崇仰");

		

	PrintHintText(Client, "观看: %s 职业:%s \nID:%N Lv:%d[%d转] 拥有装备:%d件 \n血量值:%d 魔法值:%d 称号:[%s] 称号:[%s] 师徒称号:[%s] ", s_vip, playerjod, target, Lv[target], NewLifeCount[target], ZBNUM, health, MP[target], MYCH, MYTS);
	return Plugin_Handled;
}

/* 读取任意一个玩家 */
public GetAnyClient()
{
	for(new i = 1; i <= MaxClients; i++)
	{
		if(IsValidEntity(i) && IsClientInGame(i))
			return i;
	}
	return -1;
}

/* 读取准心位置 */
public GetTracePosition(client, Float:TracePos[3])
{
	decl Float:clientPos[3], Float:clientAng[3];

	GetClientEyePosition(client, clientPos);
	GetClientEyeAngles(client, clientAng);
	new Handle:trace = TR_TraceRayFilterEx(clientPos, clientAng, MASK_PLAYERSOLID, RayType_Infinite, TraceEntityFilterPlayer, client);
	if(TR_DidHit(trace))
		TR_GetEndPosition(TracePos, trace);

	CloseHandle(trace);
}
public bool:TraceEntityFilterPlayer(entity, contentsMask)
{
	return entity > MaxClients || !entity;
}

/* 推开效果 */
public PointPush(client, Float:center[3], force, radius, Float:duration)
{
	new push = CreateEntityByName("point_push");
	DispatchKeyValueFloat(push, "magnitude", float(force));
	DispatchKeyValueFloat(push, "radius", float(radius));
	DispatchKeyValueFloat(push, "inner_radius", float(force*2));
	DispatchKeyValue(push, "spawnflags", "24");
	DispatchSpawn(push);
	TeleportEntity(push, center, NULL_VECTOR, NULL_VECTOR);
	if(IsValidPlayer(client))
		AcceptEntityInput(push, "Enable", client, client);
	else 	
		AcceptEntityInput(push, "Enable", -1, -1);
	CreateTimer(duration, DeletePushForce, push);
	
	new exPhys = CreateEntityByName("env_physexplosion");
	DispatchKeyValueFloat(exPhys, "radius", float(radius));
	DispatchKeyValueFloat(exPhys, "inner_radius", float(force));
	DispatchKeyValueFloat(exPhys, "magnitude", force*0.5);
	DispatchKeyValue(exPhys, "spawnflags", "19");
	DispatchSpawn(exPhys);
	TeleportEntity(exPhys, center, NULL_VECTOR, NULL_VECTOR);
	if(IsValidPlayer(client))
		AcceptEntityInput(exPhys, "Explode", client, client);
	else 	
		AcceptEntityInput(exPhys, "Explode", -1, -1);
}
public Action:DeletePushForce(Handle:timer, any:ent)
{
	if (IsValidEntity(ent))
	{
		decl String:classname[64];
		GetEdictClassname(ent, classname, sizeof(classname));
		if (StrEqual(classname, "point_push", false))
		{
			AcceptEntityInput(ent, "Disable");
			AcceptEntityInput(ent, "Kill");
			RemoveEdict(ent);
		}
	}
}

/* 名字信息设置 */
stock String:NameInfo(Client, mode)
{
	decl String:NameInfoString[192];
	if(StrEqual(Password[Client], "", true))
	{
		if(mode == colored)
		{
			if(IsClientInGame(Client))
			{
				if(GetClientTeam(Client) == 2)	Format(NameInfoString, sizeof(NameInfoString), "{green}[未注册]{blue}%N{default}", Client);
				else if(GetClientTeam(Client) == 3)	Format(NameInfoString, sizeof(NameInfoString), "{green}[未注册]{red}%N{default}", Client);
				else	Format(NameInfoString, sizeof(NameInfoString), "{green}[未注册]{default}%N", Client);
			}
		}
		else if(mode == simple) Format(NameInfoString, sizeof(NameInfoString), "[未注册]%N", Client);
	} else if(!IsPasswordConfirm[Client])
	{
		if(mode == colored)
		{
			if(IsClientInGame(Client))
			{
				if(GetClientTeam(Client) == 2)	Format(NameInfoString, sizeof(NameInfoString), "\x05[未登录]{red}%N{default}", Client);
				else if(GetClientTeam(Client) == 3)	Format(NameInfoString, sizeof(NameInfoString), "\x05[未登录]{red}%N{default}", Client);
				else	Format(NameInfoString, sizeof(NameInfoString), "\x05[未登录]{default}%N", Client);
			}
		}
		else if(mode == simple) Format(NameInfoString, sizeof(NameInfoString), "[未登录]%N", Client);
	} else
	{
		decl String:job[32];
		if(JD[Client] == 0)			Format(job, sizeof(job), "未转职");
		else if(JD[Client] == 1)	Format(job, sizeof(job), "工程师");
		else if(JD[Client] == 2)	Format(job, sizeof(job), "士兵");
		else if(JD[Client] == 3)	Format(job, sizeof(job), "圣骑士");
		else if(JD[Client] == 4)	Format(job, sizeof(job), "心灵医生");
		else if(JD[Client] == 5)	Format(job, sizeof(job), "魔法师");
		else if(JD[Client] == 6)	Format(job, sizeof(job), "弹药专家");
		else if(JD[Client] == 7)	Format(job, sizeof(job), "地狱使者");
		else if(JD[Client] == 8)	Format(job, sizeof(job), "死神");
		else if(JD[Client] == 9)	Format(job, sizeof(job), "黑暗行者");	
		else if(JD[Client] == 10)	Format(job, sizeof(job), "死亡祭师");	
		else if(JD[Client] == 11)	Format(job, sizeof(job), "雷电使者");
		else if(JD[Client] == 12)	Format(job, sizeof(job), "影武者");
		else if(JD[Client] == 13)	Format(job, sizeof(job), "审判者");
		else if(JD[Client] == 14)	Format(job, sizeof(job), "毒龙");
		else if(JD[Client] == 15)	Format(job, sizeof(job), "幻影统帅");	
		else if(JD[Client] == 16)	Format(job, sizeof(job), "复仇者");
		else if(JD[Client] == 17)	Format(job, sizeof(job), "大祭祀");
		else if(JD[Client] == 18)	Format(job, sizeof(job), "狂战士");

		decl String:CHXS[32];
		if(BJCH[Client] == 0)			Format(CHXS, sizeof(CHXS), "未获取");
		else if(BJCH[Client] == 1)	Format(CHXS, sizeof(CHXS), "坦克杀手");
		else if(BJCH[Client] == 2)	Format(CHXS, sizeof(CHXS), "僵尸猎手");	
		else if(BJCH[Client] == 3)	Format(CHXS, sizeof(CHXS), "拒绝乘骑");
		else if(BJCH[Client] == 4)	Format(CHXS, sizeof(CHXS), "文明者");
		else if(BJCH[Client] == 5)	Format(CHXS, sizeof(CHXS), "瘦身教练");	
		else if(BJCH[Client] == 6)	Format(CHXS, sizeof(CHXS), "执法者");
		else if(BJCH[Client] == 7)	Format(CHXS, sizeof(CHXS), "哭泣杀手");	
		else if(BJCH[Client] == 8)	Format(CHXS, sizeof(CHXS), "救助者");
		else if(BJCH[Client] == 9)	Format(CHXS, sizeof(CHXS), "好队友");
		else if(BJCH[Client] == 10)	Format(CHXS, sizeof(CHXS), "强化好手");
		else if(BJCH[Client] == 11)	Format(CHXS, sizeof(CHXS), "百折不挠");	
		else if(BJCH[Client] == 12)	Format(CHXS, sizeof(CHXS), "拒绝吸烟");			
					
		if(mode == colored)
		{
			if(IsClientInGame(Client))
			{
				if(GetClientTeam(Client) == 2)
				{
					if (VIP[Client] == 1)
						Format(NameInfoString, sizeof(NameInfoString), "\x03[%d转][Lv.%d %s][\x03%s]\x03[白银VIP]\x04%N\x03", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 2)
						Format(NameInfoString, sizeof(NameInfoString), "\x04[%d转][Lv.%d %s][\x03%s]\x03[黄金VIP]\x03%N\x04", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 3)
						Format(NameInfoString, sizeof(NameInfoString), "\x03[%d转][Lv.%d %s][\x03%s]\x03[水晶VIP]{red}%N\x05", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 4)
						Format(NameInfoString, sizeof(NameInfoString), "{red}[%d转][Lv.%d %s][\x03%s]\x05[至尊VIP]\x03%N{red}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);	
					else if (VIP[Client] == 5)
						Format(NameInfoString, sizeof(NameInfoString), "{red}[%d转][Lv.%d %s][\x03%s]\x05[管理VIP]\x03%N{red}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);	
					else if (VIP[Client] == 6)
						Format(NameInfoString, sizeof(NameInfoString), "{red}[%d转][Lv.%d %s][\x03%s]\x05[服主VIP]\x03%N{red}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);	
					else
						Format(NameInfoString, sizeof(NameInfoString), "\x05[%d转][Lv.%d %s][\x03%s]{red}%N{default}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
				}
				else if(GetClientTeam(Client) == 3)	
				{
					if (VIP[Client] == 1)
						Format(NameInfoString, sizeof(NameInfoString), "\x03[%d转][Lv.%d %s][\x03%s]\x03[白金VIP]\x04%N\x03", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 2)
						Format(NameInfoString, sizeof(NameInfoString), "\x04[%d转][Lv.%d %s][\x03%s]\x03[黄金VIP]\x03%N\x04", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 3)
						Format(NameInfoString, sizeof(NameInfoString), "\x03[%d转][Lv.%d %s][\x03%s]{red}[水晶VIP]{red}%N\x05", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 4)
						Format(NameInfoString, sizeof(NameInfoString), "{red}[%d转][Lv.%d %s][\x03%s]\x05[至尊VIP]\x03%N{red}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 5)
						Format(NameInfoString, sizeof(NameInfoString), "{red}[%d转][Lv.%d %s][\x03%s]\x05[管理VIP]\x03%N{red}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 6)
						Format(NameInfoString, sizeof(NameInfoString), "{red}[%d转][Lv.%d %s][\x03%s]\x05[服主VIP]\x03%N{red}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);						
					else
						Format(NameInfoString, sizeof(NameInfoString), "\x05[%d转][Lv.%d %s][\x03%s]{red}%N{default}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
				}
				else if(GetClientTeam(Client) == 4)	
				{
					if (VIP[Client] == 1)
						Format(NameInfoString, sizeof(NameInfoString), "\x03[%d转][Lv.%d %s][\x03%s]\x03[白银VIP]\x04%N\x03", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 2)
						Format(NameInfoString, sizeof(NameInfoString), "\x04[%d转][Lv.%d %s][\x03%s]\x03[黄金VIP]\x03%N\x04", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 3)
						Format(NameInfoString, sizeof(NameInfoString), "\x03[%d转][Lv.%d %s][\x03%s]{red}[水晶VIP]{red}%N\x05", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 4)
						Format(NameInfoString, sizeof(NameInfoString), "{red}[%d转][Lv.%d %s][\x03%s]\x05[至尊VIP]\x03%%N{red}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 5)
						Format(NameInfoString, sizeof(NameInfoString), "{red}[%d转][Lv.%d %s][\x03%s]\x05[管理VIP]\x03%N{red}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 6)
						Format(NameInfoString, sizeof(NameInfoString), "{red}[%d转][Lv.%d %s][\x03%s]\x05[服主VIP]\x03%N{red}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);	
					else
						Format(NameInfoString, sizeof(NameInfoString), "\x05[%d转][Lv.%d %s][\x03%s]{red}%N{default}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
				}

				else	
				{
					if (VIP[Client] == 1)
						Format(NameInfoString, sizeof(NameInfoString), "\x03[%d转][Lv.%d %s][\x03%s]\x03[白银VIP]\x04%N\x03", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 2)
						Format(NameInfoString, sizeof(NameInfoString), "\x04[%d转][Lv.%d %s][\x03%s]\x03[黄金VIP]\x03%N\x04", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 3)
						Format(NameInfoString, sizeof(NameInfoString), "\x03[%d转][Lv.%d %s][\x03%s]{red}[水晶VIP]{red}%N\x05", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 4)
						Format(NameInfoString, sizeof(NameInfoString), "{red}[%d转][Lv.%d %s][\x03%s]\x05[至尊VIP]\x03%N{red}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 5)
						Format(NameInfoString, sizeof(NameInfoString), "{red}[%d转][Lv.%d %s][\x03%s]\x05[管理VIP]\x03%N{red}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
					else if (VIP[Client] == 6)
						Format(NameInfoString, sizeof(NameInfoString), "{red}[%d转][Lv.%d %s][\x03%s]\x05[服主VIP]\x03%N{red}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);	
					else
						Format(NameInfoString, sizeof(NameInfoString), "\x05[%d转][Lv.%d %s][\x03%s]{default}%N{default}", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
				}
			}
		}
		else if(mode == simple) 
		{
			if (VIP[Client] == 1)
				Format(NameInfoString, sizeof(NameInfoString), "[%d转][Lv.%d %s][%s][白银VIP]%N", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
			else if (VIP[Client] == 2)
				Format(NameInfoString, sizeof(NameInfoString), "[%d转][Lv.%d %s][%s][黄金VIP]%N", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
			else if (VIP[Client] == 3)
				Format(NameInfoString, sizeof(NameInfoString), "[%d转][Lv.%d %s][%s][水晶VIP]%N", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
			else if (VIP[Client] == 4)
				Format(NameInfoString, sizeof(NameInfoString), "[%d转][Lv.%d %s][%s][至尊VIP]%N", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
			else if (VIP[Client] == 5)
				Format(NameInfoString, sizeof(NameInfoString), "[%d转][Lv.%d %s][%s][创世VIP]%N", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
			else if (VIP[Client] == 6)
				Format(NameInfoString, sizeof(NameInfoString), "[%d转][Lv.%d %s][%s][末日VIP]%N", NewLifeCount[Client], Lv[Client], job, CHXS, Client);	
			else
				Format(NameInfoString, sizeof(NameInfoString), "[%d转][Lv.%d %s][%s]%N", NewLifeCount[Client], Lv[Client], job, CHXS, Client);
		}
	}
	return NameInfoString;
}

/* 医生电击器防刷检测 */
public bool:DoctorDefibrillatorCheck(Client)
{
	if(!IsValidPlayer(Client) || IsFakeClient(Client))
		return false;
		
	new String:name[MAX_NAME_LENGTH];
	GetClientName(Client, name, sizeof(name));
	
	for(new i = 1; i <= MaxClients; i++)
	{	
		if (StrEqual(DoctorName[i], name))
			return false;
	}
	
	return true;	
}

/* 医生电击器重置 */
public ResetDoctor(Client)
{
	if (DoctorDefibrillatorCheck(Client))
	{
		if (JD[Client] == 4)
		{
			if (Lv[Client] < 50)
				defibrillator[Client] = 2;
			else
				defibrillator[Client] = 3;
			GetClientName(Client, DoctorName[Client], sizeof(DoctorName));
		}
	}
}


/* 审判者补给之书防刷检测 */
public bool:SPZFHZSCheck(Client)
{
	if(!IsValidPlayer(Client) || IsFakeClient(Client))
		return false;
		
	new String:name[MAX_NAME_LENGTH];
	GetClientName(Client, name, sizeof(name));
	
	for(new i = 1; i <= MaxClients; i++)
	{	
		if (StrEqual(SPZName[i], name))
			return false;
	}
	
	return true;	
}

/* 审判者补给之书重置 */
public ResetFHZS(Client)
{
	if (SPZFHZSCheck(Client))
	{
		if (JD[Client] == 13)
		{
			FHZS[Client] = 7;
			SMZS[Client] = 5;			
			GetClientName(Client, SPZName[Client], sizeof(SPZName));
		}
	}
}



/******************************************************
*	Gimmick functions
*******************************************************/

public LittleFlower(Float:pos[3], type, activator)
{
	/* Cause fire(type=0) or explosion(type=1) */
	new entity = CreateEntityByName("prop_physics");
	if (IsValidEntity(entity))
	{
		pos[2] += 10.0;
		if (type == 0)
			/* fire */
			DispatchKeyValue(entity, "model", ENTITY_GASCAN);
		else
			/* explode */
			DispatchKeyValue(entity, "model", ENTITY_PROPANE);
		DispatchSpawn(entity);
		SetEntData(entity, GetEntSendPropOffs(entity, "m_CollisionGroup"), 1, 1, true);
		TeleportEntity(entity, pos, NULL_VECTOR, NULL_VECTOR);
		SetEntityRenderMode(entity, RENDER_TRANSCOLOR);
		SetEntityRenderColor(entity, 0, 0, 0, 0);
		if(IsClientInGame(activator))
		{
			if(IsFakeClient(activator))	AcceptEntityInput(entity, "break", activator, activator);
			else
			{
				new Handle:pack;
				CreateDataTimer(0.1,Break,pack);
				WritePackCell(pack, entity);
				WritePackCell(pack, activator);
			}
		} else 	AcceptEntityInput(entity, "break", -1, -1);
	}
}

public Action:Break(Handle:timer, Handle:pack)
{
	new victim;
	new attacker;

	/* Set to the beginning and unpack it */
	ResetPack(pack);
	victim = ReadPackCell(pack);
	attacker = ReadPackCell(pack);
	DealDamage(attacker,victim,100,2);
}

public Smash(client, target, Float:power, Float:powHor, Float:powVec)
{
	if (!IsValidPlayer(client) || !IsValidPlayer(target))
		return;
		
	/* Blow off target */
	decl Float:HeadingVector[3], Float:AimVector[3];
	GetClientEyeAngles(client, HeadingVector);

	AimVector[0] = FloatMul(Cosine(DegToRad(HeadingVector[1])) ,power * powHor);
	AimVector[1] = FloatMul(Sine(DegToRad(HeadingVector[1])) ,power * powHor);

	decl Float:current[3];
	GetEntPropVector(target, Prop_Data, "m_vecVelocity", current);

	decl Float:resulting[3];
	resulting[0] = FloatAdd(current[0], AimVector[0]);
	resulting[1] = FloatAdd(current[1], AimVector[1]);
	resulting[2] = power * powVec;
	//tank地震技能 玩家重力增加
	new Float:PlayerGravity;
	PlayerGravity = GetEntityGravity(target) + 0.5;
	if( PlayerGravity > 1.0 ){
		PlayerGravity = 1.0;
	}
	SetEntityGravity(target, PlayerGravity);
	TeleportEntity(target, NULL_VECTOR, NULL_VECTOR, resulting);
}

public ScreenFade(target, red, green, blue, alpha, duration, type)
{
	if(IsClientInGame(target)){
		new Handle:msg = StartMessageOne("Fade", target);
		BfWriteShort(msg, 500);
		BfWriteShort(msg, duration);
		if (type == 0)
			BfWriteShort(msg, (0x0002 | 0x0008));
		else
			BfWriteShort(msg, (0x0001 | 0x0010));
		BfWriteByte(msg, red);
		BfWriteByte(msg, green);
		BfWriteByte(msg, blue);
		BfWriteByte(msg, alpha);
		EndMessage();
	}
}

public ScreenShake(target, Float:intensity)
{
	new Handle:msg;
	msg = StartMessageOne("Shake", target);

	BfWriteByte(msg, 0);
 	BfWriteFloat(msg, intensity);
 	BfWriteFloat(msg, 10.0);
 	BfWriteFloat(msg, 3.0);
	EndMessage();
}

public TriggerPanicEvent()
{
	new flager = GetAnyClient();
	if(flager == -1)  return;
	new flag = GetCommandFlags("director_force_panic_event");
	SetCommandFlags("director_force_panic_event", flag & ~FCVAR_CHEAT);
	FakeClientCommand(flager, "director_force_panic_event");
}

/******************************************************
*	粒子特效控制功能
*******************************************************/
public ShowParticle(Float:pos[3], String:particlename[], Float:time)
{
	/* Show particle effect you like */
	new particle = CreateEntityByName("info_particle_system");
	if (IsValidEdict(particle))
	{
		TeleportEntity(particle, pos, NULL_VECTOR, NULL_VECTOR);
		DispatchKeyValue(particle, "effect_name", particlename);
		DispatchKeyValue(particle, "targetname", "particle");
		DispatchSpawn(particle);
		ActivateEntity(particle);
		AcceptEntityInput(particle, "start");
		CreateTimer(time, DeleteParticles, particle);
	}
}

public AttachParticle(ent, String:particleType[], Float:time)
{
	decl String:tName[64];
	new particle = CreateEntityByName("info_particle_system");
	if (IsValidEdict(particle) && IsValidEdict(ent))
	{
		new Float:pos[3];
		GetEntPropVector(ent, Prop_Send, "m_vecOrigin", pos);
		TeleportEntity(particle, pos, NULL_VECTOR, NULL_VECTOR);
		GetEntPropString(ent, Prop_Data, "m_iName", tName, sizeof(tName));
		DispatchKeyValue(particle, "targetname", "tf2particle");
		DispatchKeyValue(particle, "parentname", tName); 
		DispatchKeyValue(particle, "effect_name", particleType);
		DispatchSpawn(particle);
		SetVariantString(tName);
		AcceptEntityInput(particle, "SetParent", particle, particle, 0);
		ActivateEntity(particle);
		AcceptEntityInput(particle, "start");
		CreateTimer(time, DeleteParticles, particle);
	}
}

public Action:DeleteParticles(Handle:timer, any:particle)
{
	/* Delete particle */
    if (IsValidEntity(particle) && IsValidEdict(particle))
	{
		new String:classname[64];
		GetEdictClassname(particle, classname, sizeof(classname));
		if (StrEqual(classname, "info_particle_system", false))
		{
			AcceptEntityInput(particle, "stop");
			AcceptEntityInput(particle, "kill");
			RemoveEdict(particle);
		}
	}
}

public PrecacheParticle(String:particlename[])
{
	/* Precache particle */
	new particle = CreateEntityByName("info_particle_system");
	if (IsValidEdict(particle))
	{
		DispatchKeyValue(particle, "effect_name", particlename);
		DispatchKeyValue(particle, "targetname", "particle");
		DispatchSpawn(particle);
		ActivateEntity(particle);
		AcceptEntityInput(particle, "start");
		CreateTimer(0.01, DeleteParticles, particle);
	}
}

/******************************************************
*	视觉效果Functions
*******************************************************/
public CreateLaserEffect(client, Float:targetpos[3], colRed, colGre, colBlu, alpha, Float:width, Float:duration, mode)
{
	decl color[4];
	color[0] = colRed;
	color[1] = colGre;
	color[2] = colBlu;
	color[3] = alpha;

	if(mode == LASERMODE_NORMAL)
	{
		/* Show laser between user and impact position */
		decl Float:myPos[3];

		GetClientEyePosition(client, myPos);
		TE_SetupBeamPoints(myPos, targetpos, g_BeamSprite, 0, 0, 0, duration, width, width, 1, 0.0, color, 0);
		TE_SendToAll();
	}
	else if(mode == LASERMODE_VARTICAL)
	{
		/* Show laser like lightning bolt */
		decl Float:lchPos[3];

		for(new i = 0; i < 3; i++)
			lchPos[i] = targetpos[i];
		lchPos[2] += 1000;
		TE_SetupBeamPoints(lchPos, targetpos, g_BeamSprite, 0, 0, 0, duration, width, width, 1, 2.0, color, 0);
		TE_SendToAll();
		TE_SetupGlowSprite(lchPos, g_GlowSprite, 1.5, 2.8, 230);
		TE_SendToAll();
	}
}
/******************************************************
*	制造伤害Functions
*******************************************************/
//制造伤害
stock DealDamage(attacker=0,victim,damage,dmg_type=0,String:weapon[]="")
{
	if(IsValidEdict(victim) && damage>0)
	{
		new String:victimid[64];
		new String:dmg_type_str[32];
		IntToString(dmg_type,dmg_type_str,32);
		new PointHurt = CreateEntityByName("point_hurt");
		if(PointHurt)
		{
			Format(victimid, 64, "victim%d", victim);
			DispatchKeyValue(victim,"targetname",victimid);
			DispatchKeyValue(PointHurt,"DamageTarget",victimid);
			DispatchKeyValueFloat(PointHurt,"Damage",float(damage));
			DispatchKeyValue(PointHurt,"DamageType",dmg_type_str);
			if(!StrEqual(weapon,""))
			{
				DispatchKeyValue(PointHurt,"classname",weapon);
			}
			DispatchSpawn(PointHurt);
			if(IsValidPlayer(attacker))
				AcceptEntityInput(PointHurt, "Hurt", attacker);
			else 	
				AcceptEntityInput(PointHurt, "Hurt", -1);
				
			RemoveEdict(PointHurt);
		}
	}
}

//制造重复伤害
stock DealDamageRepeat(attacker=0,victim,damage,dmg_type=0,String:weapon[]="", Float:DamageDelay = 0.1, Float:Duration = 1.0)
{
	if(IsValidEdict(victim) && damage>0)
	{
		new String:victimid[64];
		new String:dmg_type_str[32];
		IntToString(dmg_type,dmg_type_str,32);
		new PointHurt = CreateEntityByName("point_hurt");
		if(PointHurt)
		{
			Format(victimid, 64, "victim%d", victim);
			DispatchKeyValue(victim,"targetname",victimid);
			DispatchKeyValue(PointHurt,"DamageTarget",victimid);
			DispatchKeyValueFloat(PointHurt,"Damage",float(damage));
			DispatchKeyValue(PointHurt,"DamageType",dmg_type_str);
			if(!StrEqual(weapon,""))
			{
				DispatchKeyValue(PointHurt,"classname",weapon);
			}
			DispatchKeyValueFloat(PointHurt,"DamageDelay",DamageDelay);
			DispatchSpawn(PointHurt);
			if(IsClientInGame(attacker))
			{
				AcceptEntityInput(PointHurt, "TurnOn", attacker);
			} else 	AcceptEntityInput(PointHurt, "TurnOn", -1);
			CreateTimer(Duration, RemoveDealDamageRepeat, PointHurt);
		}
	}
}
public Action:RemoveDealDamageRepeat(Handle:timer, any:PointHurt)
{
	KillTimer(timer);

	if (IsValidEdict(PointHurt))
	{
		RemoveEdict(PointHurt);
	}
	return Plugin_Handled;
}
/******************************************************
*	其他Functions
*******************************************************/

/* 转换队伍 */
ChangeTeam(client, targetteam)
{
	if (!IsValidPlayer(client) || targetteam == 0)
		return;
	
	// If teams are the same ...
	if (GetClientTeam(client) == targetteam)
		return;
	
	// We check if target team is full...
	if (IsTeamFull(targetteam))
		return;
	
	// If player was on infected .... 
	if (GetClientTeam(client) == 3)
	{
		// ... and he wasn't a tank ...
		new iClass = GetEntProp(client, Prop_Send, "m_zombieClass");
		if (iClass != CLASS_TANK)
			ForcePlayerSuicide(client);	// we kill him
	}
	
	// If target is survivors .... we need to do a little trick ....
	if (targetteam == 2)
	{
		// first we switch to spectators ..
		ChangeClientTeam(client, 1); 
		
		// Search for an empty bot
		new bot = 1;
		while !(IsClientConnected(bot) && IsFakeClient(bot) && GetClientTeam(bot) == 2) do bot++;
			
		// force player to spec humans
		SDKCall(fSHS, bot, client); 
		
		// force player to take over bot
		SDKCall(fTOB, client, true); 
	}
	else // We change it's team ...
	{
		ChangeClientTeam(client, targetteam);
	}
}

/* 获取准心玩家信息 */
public Action:Timer_GetAimTargetMSG(Handle:timer, any:Client)
{	
	if (IsValidPlayer(Client) && !IsFakeClient(Client) && GetClientTeam(Client) == 2 && IsPlayerAlive(Client))
	{
		new target = GetClientAimTarget(Client, true);
		if (IsValidPlayer(target) && !IsFakeClient(target) && GetClientTeam(target) == 2 && IsPlayerAlive(target))
		{
			new String:playerjod[16], String:s_vip[16], String:WDCH[16], String:MYTC[16];
			new health = GetEntProp(target, Prop_Data, "m_iHealth");
			new ZBNUM = GetHasZBItemCount(target);			
			if (JD[target] == 1)
				Format(playerjod, sizeof(playerjod), "工程师");
			else if (JD[target] == 2)
				Format(playerjod, sizeof(playerjod), "士兵");
			else if (JD[target] == 3)
				Format(playerjod, sizeof(playerjod), "圣骑士");
			else if (JD[target] == 4)
				Format(playerjod, sizeof(playerjod), "心灵医生");
			else if (JD[target] == 5)
				Format(playerjod, sizeof(playerjod), "魔法师");
			else if (JD[target] == 6)
				Format(playerjod, sizeof(playerjod), "弹药专家");
			else if (JD[target] == 7)
				Format(playerjod, sizeof(playerjod), "地狱使者");
			else if (JD[target] == 8)
				Format(playerjod, sizeof(playerjod), "死神");	
			else if (JD[target] == 9)
				Format(playerjod, sizeof(playerjod), "黑暗行者");		
			else if (JD[target] == 10)
				Format(playerjod, sizeof(playerjod), "死亡祭师");	
			else if (JD[target] == 11)
				Format(playerjod, sizeof(playerjod), "雷电使者");
			else if (JD[target] == 12)
				Format(playerjod, sizeof(playerjod), "影武者");
			else if (JD[target] == 13)
				Format(playerjod, sizeof(playerjod), "审判者");
			else if (JD[target] == 14)
				Format(playerjod, sizeof(playerjod), "毒龙");	
			else if (JD[target] == 15)
				Format(playerjod, sizeof(playerjod), "幻影统帅");		
			else if (JD[target] == 16)
				Format(playerjod, sizeof(playerjod), "复仇者");	
			else if (JD[target] == 17)
				Format(playerjod, sizeof(playerjod), "大祭祀");	
			else if (JD[target] == 18)
				Format(playerjod, sizeof(playerjod), "狂战士");	
			else
				Format(playerjod, sizeof(playerjod), "未转职");
			
			if (VIP[target] == 1)
				Format(s_vip, sizeof(s_vip), "[白银VIP]");
			else if (VIP[target] == 2)
				Format(s_vip, sizeof(s_vip), "[黄金VIP]");
			else if (VIP[target] == 3)
				Format(s_vip, sizeof(s_vip), "[水晶VIP]");
			else if (VIP[target] == 4)
				Format(s_vip, sizeof(s_vip), "[至尊VIP]");	
			else if (VIP[target] == 5)
				Format(s_vip, sizeof(s_vip), "[管理VIP]");	
			else if (VIP[target] == 6)
				Format(s_vip, sizeof(s_vip), "[服主VIP]");	
			else if (VIP[target] <= 0)
				Format(s_vip, sizeof(s_vip), "[普通玩家]");
				
			if (BJCH[target] == 1)
				Format(WDCH, sizeof(WDCH), "坦克杀手");
			else if (BJCH[target] == 2)
				Format(WDCH, sizeof(WDCH), "僵尸猎手");	
			else if (BJCH[target] == 3)
				Format(WDCH, sizeof(WDCH), "拒绝乘骑");
			else if (BJCH[target] == 4)
				Format(WDCH, sizeof(WDCH), "文明者");
			else if (BJCH[target] == 5)
				Format(WDCH, sizeof(WDCH), "瘦身教练");
			else if (BJCH[target] == 6)
				Format(WDCH, sizeof(WDCH), "执法者");
			else if (BJCH[target] == 7)
				Format(WDCH, sizeof(WDCH), "哭泣杀手");	
			else if (BJCH[target] == 8)
				Format(WDCH, sizeof(WDCH), "救助者");
			else if (BJCH[target] == 9)
				Format(WDCH, sizeof(WDCH), "好队友");	
			else if (BJCH[target] == 10)
				Format(WDCH, sizeof(WDCH), "强化好手");	
			else if (BJCH[target] == 11)
				Format(WDCH, sizeof(WDCH), "百折不挠");
			else if (BJCH[target] == 12)
				Format(WDCH, sizeof(WDCH), "拒绝吸烟");				
			else
				Format(WDCH, sizeof(WDCH), "未获取");

			if (ticeship[Client] < 1)
				Format(MYTC, sizeof(MYTC), "吊儿郎当");
			else if (ticeship[Client] >= 1 && ticeship[Client] <= 3)
				Format(MYTC, sizeof(MYTC), "初出茅庐");
			else if (ticeship[Client] >= 4 && ticeship[Client] <= 6)
				Format(MYTC, sizeof(MYTC), "略有小成");
			else if (ticeship[Client] >= 7 && ticeship[Client] <= 9)
				Format(MYTC, sizeof(MYTC), "为人师表");
			else if (ticeship[Client] >= 10 && ticeship[Client] <= 12)
				Format(MYTC, sizeof(MYTC), "一代宗师");	
			else if (ticeship[Client] >= 13)
				Format(MYTC, sizeof(MYTC), "万人崇仰");				

			PrintHintText(Client, "身份: %s 职业:%s \nID:%N Lv:%d[%d转] 拥有装备:%d件 \n血量值:%d 魔法值:%d 称号:[%s] 师徒称号:[%s]", s_vip, playerjod, target, Lv[target], NewLifeCount[target], ZBNUM, health, MP[target], WDCH, MYTC);
		}
	}
}


/* 检测玩家是否输入密码,超时后T出 */
public Action:IsPWConfirm(Handle:timer, any:client)
{
	if (GetConVarInt(cv_pwtimeout) == 0)
		return Plugin_Stop;
	if (client < 1 || client > MaxClients)
		return Plugin_Stop;
	if (!IsClientInGame(client) || IsFakeClient(client))
		return Plugin_Stop;
	if (!IsPasswordConfirm[client])
	{
		pwtimeout[client] += 1;
		if (pwtimeout[client] >= GetConVarInt(cv_pwtimeout))
		{
			KickClient(client, "由于你长时间没有输入密码,所以你被服务器踢出");
			CPrintToChatAll("\x03玩家: {olive}%N \x03由于长时间没有输入密码,已经被服务器踢出了.", client);
			pwtimeout[client] = 0;
			return Plugin_Stop;
		}
		PrintHintText(client, "你没有注册,服务器将在 %d 后将你踢出 \n注册方法输入:/pw+空格+密码", GetConVarInt(cv_pwtimeout) - pwtimeout[client]);
		return Plugin_Continue;
	}
	else
	{
		PrintHintText(client, "登录成功!请记住你的密码和你的游戏名称,它们是互相绑定的!");
		return Plugin_Stop;
	}
}

/* 加载卡住检测 */
public Action:Kick_Connect(Handle:timer, any:client)
{
	if (client < 1 || client > MaxClients)
		return Plugin_Stop;
	if (!IsClientConnected(client) || IsFakeClient(client))
		return Plugin_Stop;
		
	if (IsClientInGame(client))
	{
		connectkicktime[client] = 0;
		return Plugin_Stop;
	}
	
	connectkicktime[client] += 1;
	if (connectkicktime[client] >= GetConVarInt(cv_loadtimeout))
	{
		connectkicktime[client] = 0;
		KickClient(client, "由于你卡在加载地图%d秒,所以被服务器踢出", GetConVarInt(cv_loadtimeout));
		CPrintToChatAll("玩家: \x03%N \x03由于加载地图超过%d秒,为防止卡人数,所以被服务器踢出!", client, GetConVarInt(cv_loadtimeout));
		return Plugin_Stop;
	}
	
	return Plugin_Continue;
}

/* 是否闰年 */
stock bool:IsLeapYear(i)
{
	if ((i % 4 == 0) && (i % 100 != 0) || (i % 400 == 0))
		return true;
	
	return false;
}

//获取今天日数
stock GetToday()
{
	new String:text[32];
	FormatTime(text, sizeof(text), "%d");
	new time = StringToInt(text);
	return time;
}

//获取今年最大日数
stock GetThisYearMaxDay(SelectYear = 0)
{
	new String:text[32];
	new year;
	new maxday;
	
	if (SelectYear == 0)
	{
		FormatTime(text, sizeof(text), "%Y");
		year = StringToInt(text);
	}
	else
		year = SelectYear;
	
	if (IsLeapYear(year))
		maxday = 366;
	else
		maxday = 365;
		
	return maxday;
}

//获取今年年份
stock GetThisYear()
{
	new String:text[32];
	FormatTime(text, sizeof(text), "%Y");
	new year = StringToInt(text);
	return year;
}

//获取当前月份
stock GetMonth()
{
	new String:text[32];
	FormatTime(text, sizeof(text), "%m");
	new month = StringToInt(text);
	return month;
}

/* 显示开火火光 */
stock ShowMuzzleFlash(client, Float:pos[3],  Float:angle[3], index)
{  
 	new particle = CreateEntityByName("info_particle_system");
	DispatchKeyValue(particle, "effect_name", "weapon_muzzle_flash_pistol"); 
	DispatchSpawn(particle);
	ActivateEntity(particle); 
	TeleportEntity(particle, pos, angle, NULL_VECTOR);
	AcceptEntityInput(particle, "start");	
	CreateTimer(0.01, DeleteParticles, particle, TIMER_FLAG_NO_MAPCHANGE);
	
}

/* 显示子弹轨迹 */
stock ShowTrack(client, Float:pos[3], Float:endpos[3] )
{  
 	decl String:temp[16]="";		
	new target = CreateEntityByName("info_particle_target");
	Format(temp, 64, "cptarget%d", target);
	DispatchKeyValue(target, "targetname", temp);	
	TeleportEntity(target, endpos, NULL_VECTOR, NULL_VECTOR); 
	ActivateEntity(target); 
	
	new particle = CreateEntityByName("info_particle_system");
	DispatchKeyValue(particle, "effect_name", PARTICLE_WEAPON_TRACER);
	DispatchKeyValue(particle, "cpoint1", temp);
	DispatchSpawn(particle);
	ActivateEntity(particle); 
	TeleportEntity(particle, pos, NULL_VECTOR, NULL_VECTOR);
	AcceptEntityInput(particle, "start");	
	CreateTimer(0.01, DeleteParticletargets, target, TIMER_FLAG_NO_MAPCHANGE);
	CreateTimer(0.01, DeleteParticles, particle, TIMER_FLAG_NO_MAPCHANGE);
}

/* 产生随机特感 */
public SpawnRandomInfected(Client, Float:pos[3])
{
	if (IsValidPlayer(Client))
	{
		new limit = GetRandomInt(3, 8);
		new type;
		new String:Name[6][32] = { "smoker","boomer","hunter","spitter","jockey","charger" };
		new String:text[64];		
		for (new i; i < limit; i++)
		{
			type = GetRandomInt(0, 5);
			Format(text, sizeof(text), "%s %.f %.f %.f", Name[type], pos[0], pos[1], pos[2]);
			CheatCommand(Client, "z_spawn", text);
		}
	}
}

/* 设置武器射速换弹速度 */
stock SetWeaponAttackSpeed(weaponid, Float:speed = 1.0, bool:LoadClip = false, bool:FireSpeed = false)
{
	if(IsValidEdict(weaponid))
	{
		decl String:entclass[64];
		GetEdictClassname(weaponid, entclass, sizeof(entclass));
		if(StrContains(entclass, "weapon") >= 0 && !StrEqual(entclass, "weapon_grenade_launcher"))
		{
			new Float:ETime = GetGameTime(); 
			new Float:time = (GetEntPropFloat(weaponid, Prop_Send, "m_flNextPrimaryAttack") - ETime) / speed;
			if (FireSpeed)
			{
				SetEntPropFloat(weaponid, Prop_Send, "m_flNextPrimaryAttack", time + ETime);
				time = (GetEntPropFloat(weaponid, Prop_Send, "m_flNextSecondaryAttack") - ETime) / speed;
				SetEntPropFloat(weaponid, Prop_Send, "m_flNextSecondaryAttack", time + ETime);
			}
			if (LoadClip)
			{
				SetEntPropFloat(weaponid, Prop_Send, "m_flPlaybackRate", speed);
				CreateTimer(time, ResetWeaponAttackSpeed, weaponid);
			}
		}
	}
}

public Action:ResetWeaponAttackSpeed(Handle:timer, any:ent)
{
	if(IsValidEdict(ent))
	{
		decl String:entclass[65];
		GetEdictClassname(ent, entclass, sizeof(entclass));
		if(StrContains(entclass, "weapon") >= 0)
			SetEntPropFloat(ent, Prop_Send, "m_flPlaybackRate", 1.0);
	}
	
	KillTimer(timer);
}

/* 名称获取玩家ID */
stock GetClientForName(String:name[], bool:fuzzy = false)
{
	new String:temp[32], Client;

	if (!fuzzy)
	{
		for (new i = 1; i <= MaxClients; i++)
		{
			if (IsValidPlayer(i, false))
			{
				GetClientName(i, temp, sizeof(temp));
				if (StrEqual(name, temp))
				{
					Client = i;
					break;
				}
			}
		}
	}
	else
	{
		for (new i = 1; i <= MaxClients; i++)
		{
			if (IsValidPlayer(i, false))
			{
				GetClientName(i, temp, sizeof(temp));
				if (StrContains(name, temp) >= 0)
				{
					Client = i;
					break;
				}
			}
		}	
	}
	
	return Client;
}

stock ChangeGameTimeSpeed(Float:speed = 0.2, Float:Duration = 5.0)
{
	decl i_Ent, Handle:h_pack;
	i_Ent = CreateEntityByName("func_timescale");
	DispatchKeyValueFloat(i_Ent, "desiredTimescale", speed);
	DispatchKeyValueFloat(i_Ent, "acceleration", 2.0);
	DispatchKeyValueFloat(i_Ent, "minBlendRate", 1.0);
	DispatchKeyValueFloat(i_Ent, "blendDeltaMultiplier", 2.0);
	DispatchSpawn(i_Ent);
	AcceptEntityInput(i_Ent, "Start");
	h_pack = CreateDataPack();
	WritePackCell(h_pack, i_Ent);
	Duration = Duration * speed;
	CreateTimer(Duration, ResetGameTimeSpeed, h_pack);
}

public Action:ResetGameTimeSpeed(Handle:Timer, Handle:h_pack)
{
	decl i_Ent;
	ResetPack(h_pack);
	i_Ent = ReadPackCell(h_pack);
	if(IsValidEntity(i_Ent) && IsValidEdict(i_Ent))
		AcceptEntityInput(i_Ent, "Stop");
}	

/* 实体轮廓设置 */
stock PerformGlow(Client, Type, Range = 0, Red = 0, Green = 0, Blue = 0)
{
	decl Color;
	Color = Red + Green * 256 + Blue * 65536;
	SetEntProp(Client, Prop_Send, "m_iGlowType", Type);
	SetEntProp(Client, Prop_Send, "m_nGlowRange", Range);
	SetEntProp(Client, Prop_Send, "m_glowColorOverride", Color);
}


/* 附加实体 */
stock AttachEntity(Owner, Entity, String:positon[]= "medkit", Float:pos[3] = NULL_VECTOR,Float:ang[3] = NULL_VECTOR)
{
	decl String:tname[32];
	Format(tname, sizeof(tname), "target%d", Owner);
	DispatchKeyValue(Owner, "targetname", tname); 		
	DispatchKeyValue(Entity, "parentname", tname);
	SetVariantString(tname);
	AcceptEntityInput(Entity, "SetParent",Entity, Entity, 0); 	
	
	if(strlen(positon)!=0)
	{
		SetVariantString(positon); 
		AcceptEntityInput(Entity, "SetParentAttachment");
	}
	TeleportEntity(Entity, pos, ang, NULL_VECTOR);
}

/* 创建克隆镜像 */
stock CreateClone(Client, iAnim, Float:Clone_Time = 5.0)
{
	decl Float:vAngles[3], Float:vOrigin[3], String:ModelName[64], Handle:pack, Clone;
	GetClientAbsOrigin(Client,vOrigin);
	GetClientEyeAngles(Client, vAngles);
	GetEntPropString(Client, Prop_Data, "m_ModelName", ModelName, sizeof(ModelName)); 
	
	if(iAnim > 0)
	{
		Clone = CreateEntityByName("prop_dynamic_override");
		SetEntityModel(Clone, ModelName);  	 
		TeleportEntity(Clone,  vOrigin, vAngles, NULL_VECTOR); 	
		SetEntProp(Clone, Prop_Send, "m_nSequence", iAnim);
		SetEntPropFloat(Clone, Prop_Send, "m_flPlaybackRate", 1.0); 	
		SetEntPropFloat(Clone, Prop_Send, "m_fadeMinDist", 10000.0); 
		SetEntPropFloat(Clone, Prop_Send, "m_fadeMaxDist", 20000.0); 
		
		if (IsValidPlayer(Client) && IsValidEntity(Client))
		{
			GotoThirdPerson(Client);
			SDKUnhook(Client, SDKHook_SetTransmit, OnSetTransmitClient);
			SDKHook(Client, SDKHook_SetTransmit, OnSetTransmitClient);
			HideEntity(Client, true)
			SetEntityMoveType(Client, MOVETYPE_NONE); 
			pack = CreateDataPack();
			CreateDataTimer(Clone_Time, Timer_KillClone, pack);
			WritePackCell(pack, Client);
			WritePackCell(pack, Clone);
		}
	}
	
	return Clone;
}

public Action:Timer_KillClone(Handle:timer, Handle:pack)
{
	ResetPack(pack);
	new Client = ReadPackCell(pack);
	new Clone = ReadPackCell(pack);
	if (IsValidPlayer(Client) && IsValidEntity(Client))
	{
		GotoFirstPerson(Client);	
		SetEntityMoveType(Client, MOVETYPE_WALK); 	
		HideEntity(Client, false);
	}
	
	if (IsValidEntity(Clone))
		AcceptEntityInput(Clone, "kill");
		
	KillTimer(timer);
}

public Action:OnSetTransmitClient(Climber, Client)
{
	
	if(Climber != Client)
	{
		if (GetClientTeam(Climber) == 2)
			return Plugin_Handled; 
		if (GetClientTeam(Climber) == 3 && GetClientTeam(Client) == 2)
			return Plugin_Handled; 
			
		return Plugin_Handled;
	}
	else 
		return Plugin_Continue;
}

//隐藏显示玩家
stock HideEntity(Entity, bool:Hide = false)
{
	
	if(!Hide) //显示
	{
		SetEntityRenderMode(Entity, RENDER_NORMAL);
		SetEntityRenderColor(Entity, 255, 255, 255, 255);
		if (IsValidPlayer(Entity) && PlayerGlowType[Entity] > -1)
			 SetEntProp(Entity, Prop_Send, "m_iGlowType", PlayerGlowType[Entity]);
	}
	else //隐藏
	{
		SetEntityRenderMode(Entity, RENDER_TRANSCOLOR);
		SetEntityRenderColor(Entity, 0, 0, 0, 0);
		if (IsValidPlayer(Entity))
			PlayerGlowType[Entity] = GetEntProp(Entity, Prop_Send, "m_iGlowType");
		SetEntProp(Entity, Prop_Send, "m_iGlowType", 0);
	}
}

//转到第三人称
stock GotoThirdPerson(Client)
{
	SetEntPropEnt(Client, Prop_Send, "m_hObserverTarget", 0);
	SetEntProp(Client, Prop_Send, "m_iObserverMode", 1);
	SetEntProp(Client, Prop_Send, "m_bDrawViewmodel", 0);
}

//转到第一人称
stock GotoFirstPerson(Client)
{
	SetEntPropEnt(Client, Prop_Send, "m_hObserverTarget", -1);
	SetEntProp(Client, Prop_Send, "m_iObserverMode", 0);
	SetEntProp(Client, Prop_Send, "m_bDrawViewmodel", 1);
}

/* 公告信息 */
stock Menu_GameAnnouncement(Client)
{
	decl String:line[256];
	new Handle:menu = CreatePanel();

	Format(line, sizeof(line), "今日公告:");			
	SetPanelTitle(menu, line);

	DrawPanelText(menu, " \n");
	if (IsPasswordConfirm[Client])
	{
		/*
		DrawPanelText(menu, "1.欢迎来到本服祝大家游戏愉快.");
		DrawPanelText(menu, "2 官方群:67513463 YY90236.");
		DrawPanelText(menu, "3.调整特感和坦克的掉落物品.");
		DrawPanelText(menu, "4.召唤重机枪指令/hl或者!hl【火】.");
		DrawPanelText(menu, "5.新职业复仇者【火】.");
		DrawPanelText(menu, "6.新装5件套上架了.");	
		*/		
	}
	else
	{
		DrawPanelText(menu, "你当前状态:[未注册或未登录]");
		DrawPanelText(menu, "未注册或未登录将无法保存存档,并且会失去很多奖励.");
	}
	DrawPanelText(menu, " \n");
	//DrawPanelText(menu, "************ \n官方群:67513463 YY90236 \n************");
	DrawPanelText(menu, " \n");
	DrawPanelItem(menu, "查看注册方法");
	DrawPanelItem(menu, "今日签到");
	DrawPanelItem(menu, "体验白银");
	DrawPanelItem(menu, "关闭菜单");	
	SendPanelToClient(menu, Client, MenuHandler_GameAnnouncement, MENU_TIME_FOREVER);
}
public MenuHandler_GameAnnouncement(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		switch (param)
		{
			case 1: CPrintToChat(Client, "\x05[注册方法]{olive}按Y打开聊天框[\x03输入/pw+空格(不包括加号)+你的密码{olive}你的名字就是你的账号！]按照以上方法操作即可.");
			case 2: PlayerSignXHToday(Client);
			case 3: VIP2TY(Client);
		}
		
		if (param > 0 && param < 4)
			Menu_GameAnnouncement(Client);
	}
}

/* 十进制转十六进制 */
stock String:IntToHex(Int)
{
	new i1, i2, String:hex[256], String:line[128];
	i1 = int;
	if (i1 == 0)
	{
		Format(hex, sizeof(hex), "0");
		return hex;
	}
		
	while (i1 > 0)
	{
		i2 = i1 % 16;
		i1 = i1 \ 16;
		if (i2 == 10)
			line[0] = 'A';
		else if (i2 == 11)
			line[0] = 'B';
		else if (i2 == 12)
			line[0] = 'C';
		else if (i2 == 13)
			line[0] = 'D';
		else if (i2 == 14)
			line[0] = 'E';
		else if (i2 == 15)
			line[0] = 'F';
		else
			IntToString(i2, line, sizeof(line));
			
		Format(hex, sizeof(hex), "%s%s", line, hex);
	}
	
	return hex;
}

/* 创建实体 */
stock CreateEntity(Client, const String:name[], const String:model[], Float:location[3]) 
{
	new entity = CreateEntityByName(name);
	if (StrEqual(model, "PROVIDED") == false)
		SetEntityModel(entity, model);
	DispatchSpawn(entity);
	ActivateEntity(entity);
	TeleportEntity(entity, location, NULL_VECTOR, NULL_VECTOR);
}

/* 玩家名字*/
public bool:CheckPlayerNameMatch(Client)
{
	decl String:s_Name[MAX_NAME_LENGTH], bool:true_name;
	true_name = false;
	GetClientName(Client, s_Name, sizeof(s_Name));
	for (new i = 1; i <= MaxClients; i++)
	{
		if (IsValidPlayer(i, false))
		{
			if (StrEqual(s_Name, PlayerName[i]))
			{
				true_name = true;
				break;
			}
		}
	}
	
	return true_name;
}

/* 玩家在同一回合内是否二次进入 */
public bool:IsFirstConnect(Client)
{
	if(!IsValidPlayer(Client))
		return false;
	new String:name[MAX_NAME_LENGTH];
	GetClientName(Client, name, sizeof(name));
	for(new i = 1; i <= MaxClients; i++)
	{	
		if (StrEqual(BotCheck[i], name))
			return false;		
	}
	return true;
}

/* 随机掉落道具 */
public RandomDropItemOnPostion(Client)
{
	decl String:DropName[64], DropSlot, DropItem;
	DropSlot = GetRandomInt(0, 3);
	if (DropSlot == 0)
	{
		DropItem = GetRandomInt(0, 15);
		strcopy(DropName, sizeof(DropName), t_Gun[DropItem]);
	}
	else if (DropSlot == 2)
	{
		DropItem = GetRandomInt(0, 2);
		strcopy(DropName, sizeof(DropName), t_Bomb[DropItem]);	
	}
	else if (DropSlot == 3)
	{
		DropItem = GetRandomInt(0, 3);
		strcopy(DropName, sizeof(DropName), t_Medic[DropItem]);	
	}
		
	DropItemOnPostion(Client, DropName, DropSlot, true);
}

/* 掉落道具 */
public DropItemOnPostion(Client, String:weapon[], slot, bool:glow)
{
	new ammo;
	new clip;
	new ammoOffset = FindSendPropInfo("CTerrorPlayer", "m_iAmmo");
	//LogToFileEx(LogPath, "[道具掉落]Slot:%d Name:%s", slot, weapon);
	if (slot == 0)
	{
		clip = 7;
		if (StrEqual(weapon, "weapon_rifle") || StrEqual(weapon, "weapon_rifle_sg552") || StrEqual(weapon, "weapon_rifle_desert") || StrEqual(weapon, "weapon_rifle_ak47"))
		{
			ammo = GetRandomInt(30, 160);
			SetEntData(Client, ammoOffset+(12), 0);
		}
		else if (StrEqual(weapon, "weapon_smg") || StrEqual(weapon, "weapon_smg_silenced") || StrEqual(weapon, "weapon_smg_mp5"))
		{
			ammo = GetRandomInt(30, 160);
			SetEntData(Client, ammoOffset+(20), 0);
		}
		else if (StrEqual(weapon, "weapon_pumpshotgun") || StrEqual(weapon, "weapon_shotgun_chrome"))
		{
			ammo = GetRandomInt(15, 50);
			SetEntData(Client, ammoOffset+(28), 0);
		}
		else if (StrEqual(weapon, "weapon_autoshotgun") || StrEqual(weapon, "weapon_shotgun_spas"))
		{
			ammo = GetRandomInt(20, 60);
			SetEntData(Client, ammoOffset+(32), 0);
		}
		else if (StrEqual(weapon, "weapon_hunting_rifle"))
		{
			ammo = GetRandomInt(30, 90);
			SetEntData(Client, ammoOffset+(36), 0);
		}
		else if (StrEqual(weapon, "weapon_sniper_scout") || StrEqual(weapon, "weapon_sniper_military") || StrEqual(weapon, "weapon_sniper_awp"))
		{
			ammo = GetRandomInt(30, 90);
			SetEntData(Client, ammoOffset+(40), 0);
		}
		else if (StrEqual(weapon, "weapon_grenade_launcher"))
		{
			ammo = GetRandomInt(10, 30);
			SetEntData(Client, ammoOffset+(68), 0);
		}
		else return;
	}	
	
	new index = CreateEntityByName(weapon);
	new Float:origin[3];
	new Float:ang[3];
	GetClientEyePosition(Client, origin);
	GetClientEyeAngles(Client, ang);
	GetAngleVectors(ang, ang, NULL_VECTOR, NULL_VECTOR);
	NormalizeVector(ang, ang);
	ScaleVector(ang, 150.0);	
	DispatchSpawn(index);
	TeleportEntity(index, origin, NULL_VECTOR, ang);		
	ActivateEntity(index); 		
	if (glow)
		PerformGlow(index, 3, 0, 240, 240, 240);

	if (slot == 0)
	{
		SetEntProp(index, Prop_Send, "m_iExtraPrimaryAmmo", ammo);
		SetEntProp(index, Prop_Send, "m_iClip1", clip);
	}
}

/* 给予玩家基本装备 */
public GivePlayerBaseWeapon(Client)
{
	if (IsValidPlayer(Client, false, false) && GetClientTeam(Client) == 2)
	{
		GetClientName(Client, BotCheck[Client], sizeof(BotCheck[]));
		new slot0 = GetPlayerWeaponSlot(Client, 0);
		new slot3 = GetPlayerWeaponSlot(Client, 3);
		new slot4 = GetPlayerWeaponSlot(Client, 4);
		new slot5 = GetPlayerWeaponSlot(Client, 5);		
		if (!IsValidEntity(slot0))
			CheatCommand(Client, "give", "rifle");
		if (!IsValidEntity(slot3))
			CheatCommand(Client, "give", "first_aid_kit");
		if (!IsValidEntity(slot4))
			CheatCommand(Client, "give", "adrenaline");
		if (!IsValidEntity(slot5))
			CheatCommand(Client, "give", "katana");			
			
		decl String:text[3][128];
		Format(text[0], sizeof(text[]), "你已领取了基础装备套装.");
		Format(text[1], sizeof(text[]), "套装物品:[M16 + 医疗包 + 肾上腺素 + 武士刀]");
		Format(text[2], sizeof(text[]), "(如果身上已有相同部位的道具将不会替换)");
		MenuFunc_MenuMessage(Client, "提示信息:", text, 3);
	}
}

/* 给予玩家基本装备_计时器 */
public Action:Timer_GivePlayerBW(Handle:timer, any:Client)
{
	if (IsValidPlayer(Client, false, false) && GetClientTeam(Client) == 2)
	{
		if (CheckPlayerBW(Client))
		{
			GivePlayerBaseWeapon(Client);
			CPrintToChatAll("\x03[领取基础装备]\x05玩家{olive}%N\x05领取了本回合的基础装备(M16+医疗包+肾上腺素+武士刀)!", Client);
		}
		
		KillTimer(timer);
	}
}

/* 给予玩家基本装备_检测 */
public bool:CheckPlayerBW(Client)
{
	decl String:temp[32];
	GetClientName(Client, temp, sizeof(temp));
	for (new i = 1; i <= MaxClients; i++)
	{
		if (StrEqual(temp, BotCheck[i]))
			return false;
	}
	
	return true;
}


/* 服务器运行时间计算 */
public Action:Timer_ServerRuningTime(Handle:timer)
{
	ServerRuningTime[RUNTIME_SEC] += 1;
	if (ServerRuningTime[RUNTIME_SEC] >= 60)
	{
		decl String:map[64];
		ServerRuningTime[RUNTIME_SEC] = 0;
		ServerRuningTime[RUNTIME_MIN] += 1;
		GetCurrentMap(map, sizeof(map));
		LogToFileEx(ServerTimePath, "---=================================================================---");
		LogToFileEx(ServerTimePath, "--- 当前地图: %s 服务器已运行时间: %d分%d秒 ---", map, ServerRuningTime[RUNTIME_MIN], ServerRuningTime[RUNTIME_SEC]);
		LogToFileEx(ServerTimePath, "---=================================================================---");
	}
}

/* 取当前连接中的玩家数 */
public GetConnectingPlayerNum(bool:allowbot)
{
	new num;
	for (new i = 1; i <= MaxClients; i++)
	{
		if (IsClientConnected(i) && !IsClientInGame(i))
		{
			if (!allowbot)
			{
				if (!IsFakeClient(i))
					num++;
			}
			else
				num++;
		}
	}
	
	return num;
}

/* 取一随机几率事件 */
public bool:GetRandomEvent(Float:radio)
{
	new Float:a = GetRandomFloat(0.0, 100.0);
	if (a <= radio)
		return true;
	return false;
}

/* 万用菜单提示 */
public MenuFunc_MenuMessage(Client, String:title[], String:text[][], LineNum)
{
	new Handle:menu = CreatePanel();
	SetPanelTitle(menu, title);
	
	DrawPanelText(menu, " \n");
	DrawPanelText(menu, "════════════════");
	for (new i; i < LineNum; i++)
		DrawPanelText(menu, text[i]);	
	DrawPanelText(menu, "════════════════");	
	DrawPanelText(menu, " \n");

	DrawPanelItem(menu, "我知道了");
	
	SendPanelToClient(menu, Client, MenuHandler_MenuMessage, MENU_TIME_FOREVER);
	CloseHandle(menu);
}
public MenuHandler_MenuMessage(Handle:menu, MenuAction:action, Client, param)
{
	if(action == MenuAction_Select)
	{
		if (param == 1)
			Menu_GameAnnouncement(Client);
	}
}

