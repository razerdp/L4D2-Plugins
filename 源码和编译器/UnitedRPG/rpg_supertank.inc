/************************************************************************
*	超级坦克功能
************************************************************************/

//设置坦克第一阶段||紫炎坦克
public Action:SetFirtsTankHealth(Handle:timer, any:Client)
{	
	if(IsValidPlayer(Client) && IsValidEntity(Client))
	{
		new Float:random = GetRandomFloat(0.0, 100.0);
		tanktype[Client] = 0;
		
		if (random <= GetConVarFloat(sm_supertank_bossratio))
		{
			tanktype[Client] = TANK5;
			new health = SuperTank_Health[TANK5];
			new Float:speed = GetConVarFloat(sm_supertank_speed[tanktype[Client]]);
			new String:color[32];
			GetConVarString(sm_supertank_color_boss, color, sizeof(color));
			SetClientHealth(Client,health);		
			SetEntPropFloat(Client, Prop_Send, "m_flLaggedMovementValue", speed);
			SetEntityRenderMode(Client, RenderMode:0);
			DispatchKeyValue(Client, "rendercolor", color);
			PerformGlow(Client, 3, 0, 255, 0, 255);
			CPrintToChatAll("{red}紫炎坦克出场:\x03%N \n{red}生命值:\x03%d {red}速度倍率:\x03%.1f", Client, health, speed);
			CPrintToChatAll("\x03紫炎坦克技能:\n\x03拥有所有阶段的坦克技能{red}并且血量速度都是最强大的!!!");		
			CreateTimer(1.0, SuperBossAbsTimer, Client, TIMER_REPEAT);		
			
		}
		else if (random <= GetConVarFloat(sm_supertank_Killerratio))// Invalid 默认关闭,已经失效
		{
			tanktype[Client] = TANK6;
			new health = SuperTank_Health[TANK6];
			new Float:speed = GetConVarFloat(sm_supertank_speed[tanktype[Client]]);
			new String:color[32];
			GetConVarString(sm_supertank_color_Killer, color, sizeof(color));
			SetClientHealth(Client,health);
			SetEntPropFloat(Client, Prop_Send, "m_flLaggedMovementValue", speed);
			SetEntityRenderMode(Client, RenderMode:0);
			DispatchKeyValue(Client, "rendercolor", color);
			PerformGlow(Client, 3, 0, 0, 255, 0);
			CPrintToChatAll("{red}闪电坦克出场:\x03%N \n{red}生命值:\x03%d {red}速度倍率:\x03%.1f", Client, health, speed);
			CPrintToChatAll("\x03闪电坦克技能:\n\x03拥有所有阶段的坦克技能{red}并且血量速度都是最强大的!!!");				
		}
		else//4段Tank接口
		{
			if(TimerUpdate[Client] != INVALID_HANDLE)
			{
				KillTimer(TimerUpdate[Client]);
				TimerUpdate[Client] = INVALID_HANDLE;
			}
			CreateTimer(0.0, UpdateSuperTank, Client, TIMER_FLAG_NO_MAPCHANGE);
		}
		
			/* 瞬移技能 */
		if(Timer_FatalMirror[Client] != INVALID_HANDLE)
		{
			KillTimer(Timer_FatalMirror[Client]);
			Timer_FatalMirror[Client] = INVALID_HANDLE;
		}
		Timer_FatalMirror[Client] = CreateTimer(SuperTank_Warp, FatalMirror, Client, TIMER_REPEAT);	
		SetTankXiXingDaFa(Client);	

	}
	
	KillTimer(timer);
}

public Action:UpdateSuperTank(Handle:Timer, Client)
{
	if(IsValidPlayer(Client) && IsValidEntity(Client) && GetEntProp(Client, Prop_Send, "m_zombieClass")==CLASS_TANK)
	{
		if(!tanktype[Client])
		{
			SuperTank_TANK1(Client);
		}
		else
		{
			new Float:DefHealth = float(SuperTank_Health[TANK1]);
			new Float:TankHealth = float(GetClientHealth(Client));
			
			if(TankHealth<=(DefHealth*GetConVarFloat(sm_supertank_health_second)) && tanktype[Client]==TANK1)
			{
				SuperTank_TANK2(Client);
			}
			else if(TankHealth<=(DefHealth*GetConVarFloat(sm_supertank_health_third))&& tanktype[Client]==TANK2)
			{
				SuperTank_TANK3(Client);
			}
			else if(TankHealth<=(DefHealth*GetConVarFloat(sm_supertank_health_forth))&& tanktype[Client]==TANK3)
			{
				SuperTank_TANK4(Client);
				return;
			}
		}
		CreateTimer(1.0, UpdateSuperTank, Client, TIMER_FLAG_NO_MAPCHANGE);
	}
}

/** 坦克技能子程序 **/

//技能_吸星大法_设置
SetTankXiXingDaFa(Client)
{
	new Float:xixingtime = GetConVarFloat(sm_supertank_xixing_interval);
	if (xixingtime <= 0)
		return;
	else
		CreateTimer(xixingtime, TankAdsTimer, Client);
}

//技能_吸星大法_大地震攻击
stock SkillEarthQuakez(Client, target)
{
	decl Float:Pos[3], Float:tPos[3];
	
	if(IsPlayerIncapped(target))
	{
		for(new i = 1; i <= GetMaxClients(); i++)
		{
			if(i == Client)
				continue;
			if(!IsClientInGame(i) || GetClientTeam(i) != 2)
				continue;
			
			GetClientAbsOrigin(Client, Pos);
			GetClientAbsOrigin(i, tPos);
			if(GetVectorDistance(tPos, Pos) < GetConVarFloat(sm_supertank_quake_radiusz))
			{
				EmitSoundToClient(i, SOUND_QUAKE);
				ScreenShake(i, 60.0);
				Smash(Client, i, GetConVarFloat(sm_supertank_quake_forcez), 1.0, 1.5);
			}
		}
	}
}

//技能_吸星大法_开始倒计时
public Action:TankAdsTimer(Handle:timer, any:client)
{
	if (IsValidPlayer(client) && IsPlayerAlive(client) && GetEntProp(client, Prop_Send, "m_zombieClass") == CLASS_TANK && tanktype[client] > 0)
	{
		new Float:pos[3];
		new Float:range;
		if (tanktype[client] >= TANK5)
			range = GetConVarFloat(sm_supertank_xixing_range) * 2.0;
		else
			range = GetConVarFloat(sm_supertank_xixing_range) * 2.0 * 2.0;
			
		SetEntityMoveType(client, MOVETYPE_NONE);
		SetEntProp(client, Prop_Data, "m_takedamage", 0, 1);
		GetEntPropVector(client, Prop_Send, "m_vecOrigin", pos);	
		//(目标, 初始半径, 最终半径, 效果1, 效果2, 渲染贴(0), 渲染速率(15), 持续时间(10.0), 播放宽度(20.0),播放振幅(0.0), 颜色(Color[4]), (播放速度)10, (标识)0)
		TE_SetupBeamRingPoint(pos, range - 0.1, range, g_BeamSprite, g_HaloSprite, 0, 15, 7.0, 50.0, 0.0, RedColor, 10, 0);
		TE_SendToAll();
		TE_SetupBeamRingPoint(pos, 0.1, range, g_BeamSprite, g_HaloSprite, 0, 15, 7.0, 5.0, 0.0, YellowColor, 10, 0);
		TE_SendToAll();
		
		if (tanktype[client] == TANK5)
			CPrintToChatAll("{red}紫炎坦克:%N {red}即将使用万象引天,开始倒计时!", client);
		else if (tanktype[client] == TANK6)
			CPrintToChatAll("{red}闪电坦克:%N {red}即将使用万象引天,开始倒计时!", client);
		else
			CPrintToChatAll("{red}第 %d 阶段坦克:\x03%N {red}即将使用万象引天,开始倒计时!", tanktype[client], client);	
			
		Xixing[client] = 0;
		
		//倒计时吸人
		CreateTimer(1.0, TankAdsTimer_A, client, TIMER_REPEAT);
		KillTimer(timer);
	}	
}

//技能_吸星大法_倒计时与释放
public Action:TankAdsTimer_A(Handle:timer, any:client)
{
	if (IsValidPlayer(client) && IsPlayerAlive(client) && GetEntProp(client, Prop_Send, "m_zombieClass") == CLASS_TANK && tanktype[client] > 0)
	{
		new Float:pos[3];
		new Float:entpos[3];
		new Float:distance;
		new Float:range;
		if (tanktype[client] >= TANK5)
			range = GetConVarFloat(sm_supertank_xixing_range);
		else
			range = GetConVarFloat(sm_supertank_xixing_range) * 2.0;
			
		Xixing[client]++;
		if (Xixing[client] >= 6)
		{	
			if (tanktype[client] == TANK5)
				PrintHintTextToAll("紫炎坦克: %N 使用万象引天,将[%.0f]码范围内的幸存者吸附过来!", client, range);	
			else if (tanktype[client] == TANK6)
				PrintHintTextToAll("闪电坦克: %N 使用万象引天,将[%.0f]码范围内的幸存者吸附过来!", client, range);	
			else
				PrintHintTextToAll("第[%d]阶段坦克: %N 使用万象引天,将[%.0f]码范围内的幸存者吸附过来!", tanktype[client], client, range);

			GetEntPropVector(client, Prop_Send, "m_vecOrigin", pos);
			
			Xixing[client] = 0;
			
			for (new i = 1; i <= MaxClients; i++)
			{
				if (!IsValidPlayer(i) || !IsPlayerAlive(i) || GetClientTeam(i) != 2)
					continue;
				
				//对比距离
				GetEntPropVector(i, Prop_Send, "m_vecOrigin", entpos);
				distance = GetVectorDistance(pos, entpos);
				if (distance <= range)
				{
					if(PLAYER_LV[i] <= 30)
					{
						CPrintToChat(i, "\x03由于你等级低于\x0530级\x03,被系统判定为\x05新手,\x03将免疫坦克的\x05万象引天!");
						PrintHintText(i, "由于你等级低于30级,被系统判定为新手,将免疫坦克的万象引天!");
					}
					else
					{
						TeleportEntity(i, pos, NULL_VECTOR, NULL_VECTOR);
						EmitSoundToAll(SOUND_DCLAW, i);
						XingxingTankType(client, i);
					}
				}		
			}
			
			//产生随机特感
			SpawnRandomInfected(client, pos);
			
			if (tanktype[client] == TANK1)
			{
				CPrintToChatAll("\x03第一阶段坦克万象引天: \n{red}吸住人产生爆炸冲击波和小团火焰来造成伤害!");
			}
			else if (tanktype[client] == TANK2)
			{
				CPrintToChatAll("\x03第二阶段坦克万象引天: \n\x03吸住人产生爆炸冲击波和小团火焰来造成伤害!");
				CPrintToChatAll("\x05吸住人后产生冰冻效果,使幸存者持续减速!");
			}
			else if (tanktype[client] == TANK3)
			{
				CPrintToChatAll("\x03第三阶段坦克万象引天: \n\x03吸住人产生爆炸冲击波来造成伤害!");
				CPrintToChatAll("\x05吸住人后产生震击效果来震飞幸存者!");
				CPrintToChatAll("{red}吸住人后产生大范围的地狱火!");
			}
			else if (tanktype[client] == TANK4)
			{
				CPrintToChatAll("\x03第四阶段坦克万象引天: \n\x03吸住人产生爆炸冲击波来造成伤害!");
				CPrintToChatAll("\x05吸住人后产生大范围的地狱火!");
				CPrintToChatAll("\x03吸住人后产生冰冻效果,使幸存者持续减速!");
				CPrintToChatAll("{red}吸住人后对被吸住的人进行致盲袭击!");
			}
			else if (tanktype[client] == TANK5)
			{
				CPrintToChatAll("\x03紫炎坦克万象引天: \n\x05吸住人产生爆炸冲击波来造成伤害!");
				CPrintToChatAll("\x05吸住人后产生大范围的地狱火!");
				CPrintToChatAll("\x03吸住人后产生冰冻效果,使幸存者持续减速!");
				CPrintToChatAll("{red}吸住人后对被吸住的人进行致盲袭击!");
			}
			else if (tanktype[client] == TANK6)
			{
				CPrintToChatAll("\x03闪电坦克万象引天: \n\x05吸住人产生爆炸冲击波来造成伤害!");
				CPrintToChatAll("\x05吸住人后产生大范围的地狱火!");
				CPrintToChatAll("\x03吸住人后产生冰冻效果,使幸存者持续减速!");
				CPrintToChatAll("{red}吸住人后对被吸住的人进行致盲袭击!");
			}
				
			SetEntityMoveType(client, MOVETYPE_WALK);
			SetEntProp(client, Prop_Data, "m_takedamage", 2, 1);
			new Float:xixingtime = GetConVarFloat(sm_supertank_xixing_interval);
			if (xixingtime > 0)
				CreateTimer(xixingtime, TankAdsTimer, client);
			
			KillTimer(timer);
		}
		else
		{
			SetEntityMoveType(client, MOVETYPE_NONE);
			if (tanktype[client] == TANK5)
				PrintHintTextToAll("紫炎坦克:%N 即将使用[%.0f]范围的万象引天,请赶紧躲开!! \n---------- 倒计时: %d 秒 ----------", client, range, 6 - Xixing[client]);
			else if (tanktype[client] == TANK6)
				PrintHintTextToAll("闪电坦克:%N 即将使用[%.0f]范围的万象引天,请赶紧躲开!! \n---------- 倒计时: %d 秒 ----------", client, range, 6 - Xixing[client]);
			else
				PrintHintTextToAll("第[%d]阶段坦克:%N 即将使用[%.0f]范围的万象引天,请赶紧躲开!! \n---------- 倒计时: %d 秒 ----------", tanktype[client], client, range, 6 - Xixing[client]);
		}
	}
	else
		KillTimer(timer);
}

//技能_吸星大法_坦克阶段判断技能
XingxingTankType(Client, target)
{
	new Float:pos[3];
	GetEntPropVector(Client, Prop_Send, "m_vecOrigin", pos);
	if (tanktype[Client] == TANK1)
	{
		SuperTank_LittleFlower(Client, pos, EXPLODE);
		SuperTank_LittleFlower(Client, pos, MOLOTOV);
	}
	else if (tanktype[Client] == TANK2)
	{
		SuperTank_LittleFlower(Client, pos, EXPLODE);
		SuperTank_LittleFlower(Client, pos, MOLOTOV);
		PlayerSlowDown(target);
	}
	else if (tanktype[Client] == TANK3)
	{
		SuperTank_LittleFlower(Client, pos, EXPLODE);
		CreateTimer(1.0, TankAdsTimer_B, target);	
		SuperTank_LittleFlower(Client, pos, MOLOTOV);
	}
	else if (tanktype[Client] == TANK4 || tanktype[Client] == TANK5 || tanktype[Client] == TANK6)
	{
		SuperTank_LittleFlower(Client, pos, EXPLODE);
		SuperTank_LittleFlower(Client, pos, MOLOTOV);
		PlayerSlowDown(target);	
		ScreenFade(target, 0, 0, 0, 235, 0, 0);
		new Float:dreadmax = GetConVarFloat(sm_supertank_xixing_dread);
		CreateTimer(dreadmax, DreadTimer, target);
	}
}


//技能_吸星大法_吸人后的震击
public Action:TankAdsTimer_B(Handle:timer, any:client)
{
	new Float:smashmax = GetConVarFloat(sm_supertank_xixing_abs);
	Smash(client, client, smashmax, 1.0, 1.5);
	EmitSoundToClient(client, SOUND_QUAKE);
	KillTimer(timer);
}

//技能_吸星大法_范围减速
PlayerSlowDown(Target)
{
	new Float:slowspeed = GetConVarFloat(sm_supertank_xixing_slowspeed);
	new Float:time = GetConVarFloat(sm_supertank_xixing_slowtime);
	PlayerSpeed[Target] = GetEntPropFloat(Target, Prop_Send, "m_flLaggedMovementValue");
	SetEntPropFloat(Target, Prop_Send, "m_flLaggedMovementValue", slowspeed);
	ScreenFade(Target, 10, 10, 235, 80, 100, 1);
	CreateTimer(time, PlayerSlowDownReset, Target);
}

//技能_地震攻击
SkillEarthQuake(Client, target)
{
	decl Float:Pos[3], Float:tPos[3];
	
	if(IsPlayerIncapped(target))
	{
		for(new i = 1; i <= GetMaxClients(); i++)
		{
			if(i == Client)
				continue;
			if(!IsClientInGame(i) || GetClientTeam(i) != 2)
				continue;
			
			GetClientAbsOrigin(Client, Pos);
			GetClientAbsOrigin(i, tPos);
			if(GetVectorDistance(tPos, Pos) < GetConVarFloat(sm_supertank_quake_radius))
			{
				EmitSoundToClient(i, SOUND_QUAKE);
				ScreenShake(i, 10.0);
				Smash(Client, i, GetConVarFloat(sm_supertank_quake_force), 1.0, 1.5);
			}
		}
	}
}

//技能_致盲攻击
SkillDreadClaw(target)
{
	visibility[target] = GetConVarInt(sm_supertank_dreadrate);
	CreateTimer(GetConVarFloat(sm_supertank_dreadinterval), DreadTimer, target);
	EmitSoundToAll(SOUND_DCLAW, target);
	ScreenFade(target, 0, 0, 0, visibility[target], 0, 0);
}

//技能_重力攻击
SkillGravityClaw(target)
{
	if (IsValidEntity(target))
		SetEntityGravity(target, 0.95);
	CreateTimer(GetConVarFloat(sm_supertank_gravityinterval), GravityTimer, target);
	EmitSoundToAll(SOUND_GCLAW, target);
	ScreenFade(target, 0, 0, 100, 80, 4000, 1);
	ScreenShake(target, 30.0);
}

//技能_火焰攻击
SkillBurnClaw(Client, target)
{
	new health = GetClientHealth(target);
	new dmg = health / 10;
		
	if (GeneLv[target] > 0)
		dmg = dmg - RoundToNearest(dmg * GeneEndEffect[target]);
	
	DealDamage(Client, target, dmg, 0, "tank_fireclaw");			
	EmitSoundToAll(SOUND_BCLAW, target);
	ScreenFade(target, 200, 0, 0, 150, 80, 1);
	ScreenShake(target, 50.0);
}

//技能_彗星石头
SkillCometStrike(Client, target, type)
{	
	decl Float:pos[3];
	GetClientAbsOrigin(target, pos);
	
	if(type == MOLOTOV)
	{
		SuperTank_LittleFlower(Client, pos, EXPLODE);
		SuperTank_LittleFlower(Client, pos, MOLOTOV);
	}
	else if(type == EXPLODE)
		SuperTank_LittleFlower(Client, pos, EXPLODE);
}

//技能_火焰喷发(被攻击)
SkillFlameGush(Client, target)
{
	decl Float:pos[3];
		
	SkillBurnClaw(Client, target);
	GetClientAbsOrigin(Client, pos);
	SuperTank_LittleFlower(Client, pos, MOLOTOV);
}

/******************************************************
*	坦克计时器子程序
*******************************************************/
public Action:ParticleTimer(Handle:timer, any:Client)
{
	if(tanktype[Client] == TANK3)
		AttachParticle(Client, PARTICLE_THIRD, 1.0);
	else if(tanktype[Client] == TANK4)
		AttachParticle(Client, PARTICLE_FORTH, 1.0);
	else
		KillTimer(timer);
}

//重力还原计时器
public Action:GravityTimer(Handle:timer, any:target)
{
	if (IsValidPlayer(target) && IsValidEntity(target))
		CreateTimer(0.1, StatusUp, target);
}

//隐形计时器
public Action:StealthTimer(Handle:timer, any:Client)
{
	if(tanktype[Client] == TANK3)
	{
		new s_lv = GetTeamLvCount(2, 1);
		if(s_lv >= 300){
			PerformGlow(Client, 0, 0, 0, 0, 0);		//取消tank轮廓
			CPrintToChatAll("{red}TANK恶魔附体,产生隐身效果,请大家小心!");
		}
		alpharate[Client] = 255;
		Remove(Client);
	}
}

//致盲计时器
public Action:DreadTimer(Handle:timer, any:target)
{
	visibility[target] -= 8;
	
	if(visibility[target] < 0)  
		visibility[target] = 0;
		
	ScreenFade(target, 0, 0, 0, visibility[target], 0, 1);
	
	if(visibility[target] <= 0)
	{
		visibility[target] = 0;
		KillTimer(timer);
	}
}

//坦克瞬移计时器
public Action:WarpTimer(Handle:timer, any:Client)
{
	if(IsValidPlayer(Client) && IsValidEntity(Client) && IsPlayerAlive(Client) && tanktype[Client] > 0 && Xixing[Client] <= 0)
	{
		decl Float:pos[3], Float:t_pos[3];
		new target = GetRandomSurvivor();
			
		for(new i = 1; i <= MaxClients; i++)
		{
			if(!IsValidPlayer(i) || !IsValidEntity(i) || GetClientTeam(i) != 2 || IsPlayerIncapped(i))
				continue;
				
			EmitSoundToClient(i, SOUND_WARP);
		}	
		GetClientAbsOrigin(Client, pos);
		if (IsValidPlayer(target))
		{
			GetClientAbsOrigin(target, t_pos);
		}
		else
		{
			SetEntityMoveType(Client, MOVETYPE_WALK);
			SetEntProp(Client, Prop_Data, "m_takedamage", 2, 1);
			KillTimer(timer);
		}
		
		//(开始坐标, 结束坐标, 效果1, 效果2,渲染帧(0), 渲染速率(15), 持续时间, 播放宽度, 播放振幅(0.0)颜色, 播放速度(10))
		TE_SetupBeamPoints(pos, t_pos, g_BeamSprite, g_HaloSprite, 0, 15, 5.0, 50.0, 50.0, 5, 0.0, YellowColor, 10);
		TE_SendToAll();
		//(目标, 初始半径, 最终半径, 效果1, 效果2, 渲染贴(0), 渲染速率(15), 持续时间(10.0), 播放宽度(20.0),播放振幅(0.0), 颜色(Color[4]), (播放速度)10, (标识)0)
		TE_SetupBeamRingPoint(pos, 250.0, 250.0 - 0.1, g_BeamSprite, g_HaloSprite, 0, 15, 5.0, 20.0, 0.0, BlueColor, 10, 0);
		TE_SendToAll();
		TE_SetupBeamRingPoint(pos, 0.1, 250.0, g_BeamSprite, g_HaloSprite, 0, 15, 5.0, 10.0, 0.0, GreenColor, 10, 0);
		TE_SendToAll();
		
		TE_SetupBeamRingPoint(t_pos, 250.0, 250.0 - 0.1, g_BeamSprite, g_HaloSprite, 0, 15, 5.0, 20.0, 0.0, RedColor, 10, 0);
		TE_SendToAll();
		TE_SetupBeamRingPoint(t_pos, 0.1, 250.0, g_BeamSprite, g_HaloSprite, 0, 15, 5.0, 10.0, 0.0, GreenColor, 10, 0);
		TE_SendToAll();		
		
		PrintHintTextToAll("超级坦克 %N 瞬移到了 %N 的身边,请赶紧躲开!!", Client, target);
		CPrintToChatAll("\x03超级坦克 \x05%N \x03瞬移到了 {red}%N \x03的身边,请赶紧躲开!!", Client, target);
		ShowParticle(pos, PARTICLE_WARP, 2.0);
		TeleportEntity(Client, t_pos, NULL_VECTOR, NULL_VECTOR);
		ShowParticle(t_pos, PARTICLE_WARP, 2.0);
		SetEntityMoveType(Client, MOVETYPE_WALK);
		SetEntProp(Client, Prop_Data, "m_takedamage", 2, 1);
		new Float:xixingtime = GetConVarFloat(sm_supertank_xixing_interval);
		if (xixingtime <= 0)
			CreateTimer(0.1, TankAdsTimer, Client);
	}
	else
		KillTimer(timer);
}

//获取随机有效幸存者
GetRandomSurvivor()
{
	new Handle:array;
	array = CreateArray(1, 0);
	
	for(new i = 1; i <= MaxClients; i++)
	{
		if(!IsValidPlayer(i) || !IsValidEntity(i) || !IsPlayerAlive(i) || GetClientTeam(i) != 2 || PLAYER_LV[i] <= 30)
			continue;
		PushArrayCell(array, i);
	}
	
	if (GetArraySize(array) <= 0)
	{
		ClearArray(array);
		for(new i = 1; i <= MaxClients; i++)
		{
			if(!IsValidPlayer(i) || !IsValidEntity(i) || !IsPlayerAlive(i) || GetClientTeam(i) != 2)
				continue;
			PushArrayCell(array, i);
		}	
	}
	
	if (GetArraySize(array) <= 0)
		return 0;
	
	new maxsize = GetArraySize(array) - 1;
	new clientNum = GetArrayCell(array, GetRandomInt(0, maxsize));
	return clientNum;
}

public Action:FatalMirror(Handle:timer, any:Client)
{
	if(IsValidPlayer(Client) && IsValidEntity(Client) && IsPlayerAlive(Client) && tanktype[Client] > 0)
	{
		/* Stop moving and prevent all damage for a while */
		SetEntityMoveType(Client, MOVETYPE_NONE);
		SetEntProp(Client, Prop_Data, "m_takedamage", 0, 1);
		
		/* Teleport to position that survivor exsited 2sec ago */
		CreateTimer(0.1, WarpTimer, Client);
	}
	else
	{
		KillTimer(timer);
		Timer_FatalMirror[Client] = INVALID_HANDLE;
	}
}

//紫炎坦克地震计时器
public Action:SuperBossAbsTimer(Handle:timer, any:Client)
{
	if (!IsValidPlayer(Client) || !IsPlayerAlive(Client) || tanktype[Client] != TANK5)
		return Plugin_Stop;
	
	new Float:pos[3];
	new Float:entpos[3];
	new Float:distance;
	new Float:range = GetConVarFloat(sm_supertank_bossrange);
	
	GetEntPropVector(Client, Prop_Send, "m_vecOrigin", pos);
	EmitSoundToAll(SOUND_ABS, Client);
	for (new i = 1; i <= MaxClients; i++)
	{
		if (!IsValidPlayer(i) || !IsPlayerAlive(i) || GetClientTeam(i) != 2)
			continue;
		
		//对比距离
		GetEntPropVector(i, Prop_Send, "m_vecOrigin", entpos);
		distance = GetVectorDistance(pos, entpos);

		if (distance <= range)
		{
			new Float:power = 100.0 - distance / 10.0;
			ScreenShake(i, power);
			PrintHintText(i, "你离紫炎坦克越近你的震击感会越强烈,请远离紫炎坦克!!");
		}		
	}	
	return Plugin_Continue;
}

//范围减速恢复计时器
public Action:PlayerSlowDownReset(Handle:timer, any:Client)
{
	if (IsValidPlayer(Client))
		SetEntPropFloat(Client, Prop_Send, "m_flLaggedMovementValue", PlayerSpeed[Client]);
		
	KillTimer(timer);
}


/** 坦克其他子程序 **/

public Action:Remove(ent)
{
	if(IsValidEntity(ent) && tanktype[ent] > 0)
	{
		CreateTimer(0.1, fadeout, ent, TIMER_REPEAT);
		SetEntityRenderMode(ent, RENDER_TRANSCOLOR);
	}
}

public Action:fadeout(Handle:Timer, any:ent)
{
	if(!IsValidEntity(ent) || tanktype[ent] != TANK3)
	{
		KillTimer(Timer);
		return;
	}
	alpharate[ent] -= 2;
	
	if (alpharate[ent] < 0)  
		alpharate[ent] = 0;
		
	SetEntityRenderMode(ent, RENDER_TRANSCOLOR);
	SetEntityRenderColor(ent, 80, 80, 255, alpharate[ent]);
	if(alpharate[ent] <= 0)
	{
		KillTimer(Timer);
	}
}

SuperTank_LittleFlower(Client, Float:pos[3], type)
{
	/* Cause fire(type=0) or explosion(type=1) */
	new entity = CreateEntityByName("prop_physics");
	SetEntPropEnt(entity, Prop_Data, "m_hOwnerEntity", Client);
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
		AcceptEntityInput(entity, "break");
	}
}

/* 重置变量 */
InitData()
{
	for (new i = 1; i <= MaxClients; i++)
	{
		tanktype[i] = 0;
		if(TimerUpdate[i] != INVALID_HANDLE)
		{
			KillTimer(TimerUpdate[i]);
			TimerUpdate[i] = INVALID_HANDLE;
		}
		if(Timer_FatalMirror[i] != INVALID_HANDLE)
		{
			KillTimer(Timer_FatalMirror[i]);
			Timer_FatalMirror[i] = INVALID_HANDLE;
		}		
		
		alpharate[i] = 0;
		visibility[i] = 0;
		
		Xixing[i] = 0;
	}
}

//超级坦克等级平衡产生
Tank_Balance(Client)
{
	new num = AllLv_Count();

	if (num >= 1 && GetTankCount() < num + 1)
	{
		new i = GetTeamLvCount(2) - GetTeamLvCount(3);
		PrintHintTextToAll("当前幸存者阵营总等级(%d)高于感染者阵营(%d)级,所以系统增加[%d]只超级坦克.", GetTeamLvCount(2), i, num);
		CheatCommand(Client, "z_spawn", "tank auto");
	}
	
}

//取幸存者等级差
AllLv_Count()
{
	new s_lv;
	new i_lv;
	new more = GetConVarInt(sm_supertank_tankbalance);
	new num;
	for (new i = 1; i <= MaxClients; i++)
	{
		if (!IsValidPlayer(i) || IsFakeClient(i))
			continue;
			
		if (GetClientTeam(i) == 2)
			s_lv += Lv[i];
		else if (GetClientTeam(i) == 3)
			i_lv += Lv[i];
	}
	
	num = (s_lv - i_lv) / more;
	if (num >= 1)
		return num;
	else
		return 0;
}

//取阵营总等级
stock GetTeamLvCount(targetteam, type = 0)
{
	new s_lv;
	new i_lv;
	for (new i = 1; i <= MaxClients; i++)
	{
		if (!IsValidPlayer(i) || IsFakeClient(i))
			continue;
			
		if (GetClientTeam(i) == 2)
		{
			if (type == 0)
				s_lv += NewLifeCount[i] * 100;
			else
				s_lv += NewLifeCount[i] * 50;
			s_lv += Lv[i];
		}
		else if (GetClientTeam(i) == 3)
		{
			i_lv += NewLifeCount[i] * 100;
			i_lv += Lv[i];
		}
	}
	
	if (targetteam == 2)
		return s_lv;
	else if (targetteam == 3)
		return i_lv;
	else
		return 0;
}

//取坦克数量
GetTankCount()
{
	new count = 0;
	for (new i = 1; i <= MaxClients; i++)
	{
		if (!IsValidPlayer(i) || !IsPlayerAlive(i) || GetClientTeam(i) != 3)
			continue;
		if (GetEntProp(i, Prop_Send, "m_zombieClass") == CLASS_TANK)
			count++;
	}
	
	return count;
}

/* 难度控制 */
SetGameDifficulty()
{
	if (GetConVarInt(rpg_gamedifficulty) != 1)
		return;

	new s_lv = GetTeamLvCount(2, 1);
	if (s_lv < 50)
	{
		//游戏默认难度
		SetConVarString(FindConVar("z_difficulty"), "Normal");
		//坦克数量
		SetConVarInt(FindConVar("director_force_tank"), 1);
		//友军伤害
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_easy"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_normal"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_hard"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_expert"), 0.1);
		//火焰伤害
		//SetConVarFloat(FindConVar("survivor_burn_factor_easy"), 2.0);
		//SetConVarFloat(FindConVar("survivor_burn_factor_Normal"), 2.0);
		//SetConVarFloat(FindConVar("survivor_burn_factor_hard"), 2.0);
		//SetConVarFloat(FindConVar("survivor_burn_factor_expert"), 2.0);
		//普通感染者HP
		SetConVarInt(FindConVar("z_health"), 100);
		//特感HP
		SetConVarInt(FindConVar("z_charger_health"), 1000);
		SetConVarInt(FindConVar("z_hunter_health"), 800);
		SetConVarInt(FindConVar("z_jockey_health"), 650);
		SetConVarInt(FindConVar("z_gas_health"), 650);
		SetConVarInt(FindConVar("z_exploding_health"), 100);
		SetConVarInt(FindConVar("z_spitter_health"), 700);
		//坦克HP
		SuperTank_Health[TANK5] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv1, TANK5);
		SuperTank_Health[TANK6] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv1, TANK6);
		SuperTank_Health[TANK1] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv1, TANK1);
		//坦克瞬移间隔
		SuperTank_Warp = GetConVarFloat(sm_supertank_warp_interval);
		//黑白次数
		SetConVarInt(FindConVar("survivor_max_incapacitated_count"), 3);
		//坦克伤害抵消几率
		TankOffsetRadio = 15.0;
		CPrintToChatAll("\x03[公告]\x03当前幸存者等级为\x05(%d级)\x03,游戏难度自动调整为\x05[新手]", s_lv);	
	}
	else if (s_lv >= 50 && s_lv < 100)
	{
		//游戏默认难度
		SetConVarString(FindConVar("z_difficulty"), "Normal");
		//坦克数量
		SetConVarInt(FindConVar("director_force_tank"), 1);
		//友军伤害
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_easy"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_normal"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_hard"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_expert"), 0.1);
		//火焰伤害
		//SetConVarFloat(FindConVar("survivor_burn_factor_easy"), 2.0);
		//SetConVarFloat(FindConVar("survivor_burn_factor_Normal"), 2.0);
		//SetConVarFloat(FindConVar("survivor_burn_factor_hard"), 2.0);
		//SetConVarFloat(FindConVar("survivor_burn_factor_expert"), 2.0);
		//普通感染者HP
		SetConVarInt(FindConVar("z_health"), 100);
		//特感HP
		SetConVarInt(FindConVar("z_charger_health"), 1000);
		SetConVarInt(FindConVar("z_hunter_health"), 800);
		SetConVarInt(FindConVar("z_jockey_health"), 650);
		SetConVarInt(FindConVar("z_gas_health"), 650);
		SetConVarInt(FindConVar("z_exploding_health"), 100);
		SetConVarInt(FindConVar("z_spitter_health"), 700);
		//坦克HP
		SuperTank_Health[TANK5] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv2, TANK5);
		SuperTank_Health[TANK6] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv2, TANK6);
		SuperTank_Health[TANK1] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv2, TANK1);
		//坦克瞬移间隔
		SuperTank_Warp = GetConVarFloat(sm_supertank_warp_interval)*0.8;
		//黑白次数
		SetConVarInt(FindConVar("survivor_max_incapacitated_count"), 2);
		//坦克伤害抵消几率
		TankOffsetRadio = 30.0;
		CPrintToChatAll("\x03[公告]\x03当前幸存者等级为\x05(%d级)\x03,游戏难度自动调整\x05[简单]", s_lv);	
	}	
	else if (s_lv >= 100 && s_lv < 600)
	{
		//游戏默认难度
		SetConVarString(FindConVar("z_difficulty"), "Normal");
		//坦克数量
		SetConVarInt(FindConVar("director_force_tank"), 1);
		//友军伤害
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_easy"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_normal"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_hard"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_expert"), 0.1);
		//火焰伤害
		SetConVarFloat(FindConVar("survivor_burn_factor_easy"), 0.5);
		SetConVarFloat(FindConVar("survivor_burn_factor_Normal"), 1.0);
		SetConVarFloat(FindConVar("survivor_burn_factor_hard"), 1.5);
		SetConVarFloat(FindConVar("survivor_burn_factor_expert"), 2.0);
		//普通感染者HP
		SetConVarInt(FindConVar("z_health"), 100);
		//特感HP
		SetConVarInt(FindConVar("z_charger_health"), 1000);
		SetConVarInt(FindConVar("z_hunter_health"), 800);
		SetConVarInt(FindConVar("z_jockey_health"), 650);
		SetConVarInt(FindConVar("z_gas_health"), 650);
		SetConVarInt(FindConVar("z_exploding_health"), 100);
		SetConVarInt(FindConVar("z_spitter_health"), 700);
		//坦克HP
		SuperTank_Health[TANK5] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv3, TANK5);
		SuperTank_Health[TANK6] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv3, TANK6);
		SuperTank_Health[TANK1] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv3, TANK1);
		//坦克瞬移间隔
		SuperTank_Warp = GetConVarFloat(sm_supertank_warp_interval)*0.75;
		//黑白次数
		SetConVarInt(FindConVar("survivor_max_incapacitated_count"), 2);
		//坦克伤害抵消几率
		TankOffsetRadio = 30.0;
		CPrintToChatAll("\x03[公告]\x03当前幸存者等级为\x05(%d级)\x03,游戏难度自动调整\x05[简单]", s_lv);	
	}	
	else if (s_lv >= 600 && s_lv < 1000)
	{
		//游戏默认难度
		SetConVarString(FindConVar("z_difficulty"), "Normal");
		//坦克数量
		SetConVarInt(FindConVar("director_force_tank"), 1);
		//火焰伤害
		SetConVarFloat(FindConVar("survivor_burn_factor_easy"), 0.1);
		SetConVarFloat(FindConVar("survivor_burn_factor_Normal"), 0.1);
		SetConVarFloat(FindConVar("survivor_burn_factor_hard"), 0.1);
		SetConVarFloat(FindConVar("survivor_burn_factor_expert"), 0.1);
		//火焰伤害
		SetConVarFloat(FindConVar("survivor_burn_factor_easy"), 0.5);
		SetConVarFloat(FindConVar("survivor_burn_factor_Normal"), 1.0);
		SetConVarFloat(FindConVar("survivor_burn_factor_hard"), 1.5);
		SetConVarFloat(FindConVar("survivor_burn_factor_expert"), 2.0);
		//普通感染者HP
		SetConVarInt(FindConVar("z_health"), 100);
		//特感HP
		SetConVarInt(FindConVar("z_charger_health"), 1000);
		SetConVarInt(FindConVar("z_hunter_health"), 800);
		SetConVarInt(FindConVar("z_jockey_health"), 650);
		SetConVarInt(FindConVar("z_gas_health"), 650);
		SetConVarInt(FindConVar("z_exploding_health"), 100);
		SetConVarInt(FindConVar("z_spitter_health"), 700);
		//坦克HP
		SuperTank_Health[TANK5] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv4, TANK5);
		SuperTank_Health[TANK6] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv4, TANK6);
		SuperTank_Health[TANK1] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv4, TANK1);
		//坦克瞬移间隔
		SuperTank_Warp = GetConVarFloat(sm_supertank_warp_interval)*0.7;
		//黑白次数
		SetConVarInt(FindConVar("survivor_max_incapacitated_count"), 2);
		//坦克伤害抵消几率
		TankOffsetRadio = 30.0;
		CPrintToChatAll("\x03[公告]\x03当前幸存者等级为\x05(%d级)\x03,游戏难度自动调整\x05[简单]", s_lv);	
	}
	else if (s_lv >= 1000 && s_lv < 1600)
	{
		//游戏默认难度
		SetConVarString(FindConVar("z_difficulty"), "Normal");
		//坦克数量
		SetConVarInt(FindConVar("director_force_tank"), 1);
		//友军伤害
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_easy"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_normal"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_hard"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_expert"), 0.1);
		//火焰伤害
		SetConVarFloat(FindConVar("survivor_burn_factor_easy"), 1.0);
		SetConVarFloat(FindConVar("survivor_burn_factor_Normal"), 1.5);
		SetConVarFloat(FindConVar("survivor_burn_factor_hard"), 2.0);
		SetConVarFloat(FindConVar("survivor_burn_factor_expert"), 2.0);
		//普通感染者HP
		SetConVarInt(FindConVar("z_health"), 100);
		//特感HP
		SetConVarInt(FindConVar("z_charger_health"), 1000);
		SetConVarInt(FindConVar("z_hunter_health"), 800);
		SetConVarInt(FindConVar("z_jockey_health"), 650);
		SetConVarInt(FindConVar("z_gas_health"), 650);
		SetConVarInt(FindConVar("z_exploding_health"), 100);
		SetConVarInt(FindConVar("z_spitter_health"), 700);
		//坦克HP
		SuperTank_Health[TANK5] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv5, TANK5);
		SuperTank_Health[TANK6] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv5, TANK6);
		SuperTank_Health[TANK1] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv5, TANK1);
		//坦克瞬移间隔
		SuperTank_Warp = GetConVarFloat(sm_supertank_warp_interval)*0.65;
		//黑白次数
		SetConVarInt(FindConVar("survivor_max_incapacitated_count"), 2);
		//坦克伤害抵消几率
		TankOffsetRadio = 30.0;
		CPrintToChatAll("\x03[公告]\x03当前幸存者等级为\x05(%d级)\x03,游戏难度自动调整\x05[简单]", s_lv);	
	}
	else if (s_lv >= 1600 && s_lv < 2600)
	{
		//游戏默认难度
		SetConVarString(FindConVar("z_difficulty"), "Normal");
		//坦克数量
		SetConVarInt(FindConVar("director_force_tank"), 1);
		//友军伤害
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_easy"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_normal"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_hard"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_expert"), 0.1);
		//火焰伤害
		SetConVarFloat(FindConVar("survivor_burn_factor_easy"), 2.0);
		SetConVarFloat(FindConVar("survivor_burn_factor_Normal"), 2.0);
		SetConVarFloat(FindConVar("survivor_burn_factor_hard"), 2.0);
		SetConVarFloat(FindConVar("survivor_burn_factor_expert"), 2.0);
		//普通感染者HP
		SetConVarInt(FindConVar("z_health"), 100);
		//特感HP
		SetConVarInt(FindConVar("z_charger_health"), 1000);
		SetConVarInt(FindConVar("z_hunter_health"), 800);
		SetConVarInt(FindConVar("z_jockey_health"), 650);
		SetConVarInt(FindConVar("z_gas_health"), 650);
		SetConVarInt(FindConVar("z_exploding_health"), 100);
		SetConVarInt(FindConVar("z_spitter_health"), 700);
		//坦克HP
		SuperTank_Health[TANK5] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv6, TANK5);
		SuperTank_Health[TANK6] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv6, TANK6);
		SuperTank_Health[TANK1] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv6, TANK1);
		//坦克瞬移间隔
		SuperTank_Warp = GetConVarFloat(sm_supertank_warp_interval)*0.6;
		//黑白次数
		SetConVarInt(FindConVar("survivor_max_incapacitated_count"), 2);
		//坦克伤害抵消几率
		TankOffsetRadio = 30.0;
		CPrintToChatAll("\x03[公告]\x03当前幸存者等级为\x05(%d级)\x03,游戏难度自动调整\x05[简单]", s_lv);	
	}
	else if (s_lv >= 2600 && s_lv < 3600)
	{
		//游戏默认难度
		SetConVarString(FindConVar("z_difficulty"), "Normal");
		//坦克数量
		SetConVarInt(FindConVar("director_force_tank"), 1);
		//友军伤害
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_easy"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_normal"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_hard"), 0.1);
		SetConVarFloat(FindConVar("survivor_friendly_fire_factor_expert"), 0.1);
		//火焰伤害
		SetConVarFloat(FindConVar("survivor_burn_factor_easy"), 2.0);
		SetConVarFloat(FindConVar("survivor_burn_factor_Normal"), 2.0);
		SetConVarFloat(FindConVar("survivor_burn_factor_hard"), 2.0);
		SetConVarFloat(FindConVar("survivor_burn_factor_expert"), 2.0);
		//普通感染者HP
		SetConVarInt(FindConVar("z_health"), 100);
		//特感HP
		SetConVarInt(FindConVar("z_charger_health"), 1000);
		SetConVarInt(FindConVar("z_hunter_health"), 800);
		SetConVarInt(FindConVar("z_jockey_health"), 650);
		SetConVarInt(FindConVar("z_gas_health"), 650);
		SetConVarInt(FindConVar("z_exploding_health"), 100);
		SetConVarInt(FindConVar("z_spitter_health"), 700);
		//坦克HP
		SuperTank_Health[TANK5] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv7, TANK5);
		SuperTank_Health[TANK6] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv7, TANK6);
		SuperTank_Health[TANK1] = GetBalanceTankHP(rpg_gamedifficulty_tankHP_lv7, TANK1);
		//坦克瞬移间隔
		SuperTank_Warp = GetConVarFloat(sm_supertank_warp_interval)*0.55;
		//黑白次数
		SetConVarInt(FindConVar("survivor_max_incapacitated_count"), 2);
		//坦克伤害抵消几率
		TankOffsetRadio = 30.0;
		CPrintToChatAll("\x03[公告]\x03当前幸存者等级为\x05(%d级)\x03,游戏难度自动调整\x05[简单]", s_lv);	
	}
}

/* 随机掉落物品 */
DropRandomWeapon(Client)
{
	if (!IsValidPlayer(Client) || GetClientTeam(Client) != 3)
		return;
	
	new String:weapon[64];
	new max;
	for (new u = 1; u <= MaxClients; u++)
	{
		if (!IsValidPlayer(u) || IsFakeClient(u) || GetClientTeam(u) != 2 || !IsPlayerAlive(u))
			continue;
			
		max++;			
	}
	
	if (tanktype[Client] >= TANK1)
	{
		if (max <= 1)
			max = 1;
		else
			max = max / 1;
	}
	
	for(new i; i <= max; i++)
	{
		new gun = GetRandomInt(0, 16);
		new medic = GetRandomInt(0, 3);
		new bomb = GetRandomInt(0, 2);			
		Format(weapon, sizeof(weapon), t_Gun[gun]);
		Tank_CreateEntity(Client, weapon);
		Format(weapon, sizeof(weapon), t_Bomb[bomb]);
		Tank_CreateEntity(Client, weapon);
		Format(weapon, sizeof(weapon), t_Medic[medic]);
		Tank_CreateEntity(Client, weapon);
	}
	
	if (tanktype[Client] != TANK1)
		CPrintToChatAll("\x03[系统]\x03超级坦克\x03死亡,在坦克的死亡位置掉落了{red}%d\x03份{red}物品补给!", max * 6);
	else
		CPrintToChatAll("\x03[系统]\x03紫炎坦克\x03死亡,在坦克的死亡位置掉落了{red}%d\x03份{red}物品补给!", max * 8);
}

/* 实体创建 */
stock Tank_CreateEntity(Client, String:classname[], bool:IsMelee = false)
{
	new entity;
	new Float:pos[3];
	GetClientAbsOrigin(Client, pos);
	if (!IsMelee)
		entity = CreateEntityByName(classname);
	else
	{
		entity = CreateEntityByName("weapon_melee_spawn");
		DispatchKeyValue(entity, "spawnflags", "2");
		DispatchKeyValue(entity, "melee_weapon", classname);
	}
		
		
	if (IsValidEntity(entity))
	{
		pos[0] = pos[0] + GetRandomFloat(-60.0, 60.0);
		pos[1] = pos[1] + GetRandomFloat(-60.0, 60.0);
		pos[2] = pos[2] + GetRandomFloat(40.0, 60.0);
		ActivateEntity(entity);
		DispatchSpawn(entity);
		TeleportEntity(entity, pos, NULL_VECTOR, NULL_VECTOR);
		SetEntPropFloat(entity, Prop_Send,"m_flModelScale", 0.5); 
		PerformGlow(entity, 3, 0, 240, 240 ,240);
	}
}


//by MicroLeo
SetClientHealth(client,&health)
{
	new String:heal[16];
	IntToString(health,heal,sizeof(heal));
	DispatchKeyValue(client, "max_health", heal);
	DispatchKeyValue(client, "health", heal);
}

//第一段形态
SuperTank_TANK1(Client)
{
	tanktype[Client] = TANK1;
	SuperTank_Health[TANK1] = !GetConVarBool(rpg_gamedifficulty) ? GetConVarInt(sm_supertank_health_max) : SuperTank_Health[TANK1]>0 ? SuperTank_Health[TANK1] : GetConVarInt(sm_supertank_health_max);
	new Float:speed = GetConVarFloat(sm_supertank_speed[tanktype[Client]]);	
	new String:color[32];
	
	GetConVarString(sm_supertank_color_first, color, sizeof(color));
	SetClientHealth(Client, SuperTank_Health[TANK1]);			
	SetEntPropFloat(Client, Prop_Send, "m_flLaggedMovementValue", speed);
	SetEntityRenderMode(Client, RenderMode:0);
	DispatchKeyValue(Client, "rendercolor", color);
	PerformGlow(Client, 3, 0, 0, 0, 255);
	CPrintToChatAll("{red}四阶段坦克出场:\x03%N \n{red}生命值:\x03%d 速度倍率:{red}%.1f", Client, SuperTank_Health[TANK1], speed);
	CPrintToChatAll("\x03此阶段拥有技能:\n{red}彗星石头:\x05投掷出的石头会产生爆炸对幸存者造成伤害!");
}

//第二段形态
SuperTank_TANK2(Client)
{
	tanktype[Client] = TANK2;
	new Float:speed = GetConVarFloat(sm_supertank_speed[tanktype[Client]]);	
	new String:color[32];
	
	GetConVarString(sm_supertank_color_second, color, sizeof(color));		
	SetEntPropFloat(Client, Prop_Send, "m_flLaggedMovementValue", speed);
	SetEntityRenderMode(Client, RenderMode:0);
	DispatchKeyValue(Client, "rendercolor", color);
	PerformGlow(Client, 3, 0, 0, 0, 255);
	CPrintToChatAll("\x03变身为第二阶段坦克:\x03%N \n{red}生命值:\x03%d 速度倍率:{red}%.1f", Client, GetClientHealth(Client), speed);
	//CPrintToChatAll("\x03此阶段拥有技能:\n{red}彗星石头:\x05投掷出的石头会产生爆炸对幸存者造成伤害!");
}

//第三段形态
SuperTank_TANK3(Client)
{
	tanktype[Client] = TANK3;
	new Float:speed = GetConVarFloat(sm_supertank_speed[tanktype[Client]]);	
	new String:color[32];
	
	GetConVarString(sm_supertank_color_third, color, sizeof(color));		
	SetEntPropFloat(Client, Prop_Send, "m_flLaggedMovementValue", speed);
	SetEntityRenderMode(Client, RenderMode:0);
	DispatchKeyValue(Client, "rendercolor", color);
	PerformGlow(Client, 3, 0, 0, 0, 255);
	CPrintToChatAll("\x03变身为第三阶段坦克:\x03%N \n{red}生命值:\x03%d 速度倍率:{red}%.1f", Client, GetClientHealth(Client), speed);
	//CPrintToChatAll("\x03此阶段拥有技能:\n{red}彗星石头:\x05投掷出的石头会产生爆炸对幸存者造成伤害!");
}

//第四段形态
SuperTank_TANK4(Client)
{
	tanktype[Client] = TANK4;
	new Float:speed = GetConVarFloat(sm_supertank_speed[tanktype[Client]]);	
	new String:color[32];
	
	GetConVarString(sm_supertank_color_forth, color, sizeof(color));		
	SetEntPropFloat(Client, Prop_Send, "m_flLaggedMovementValue", speed);
	SetEntityRenderMode(Client, RenderMode:0);
	DispatchKeyValue(Client, "rendercolor", color);
	PerformGlow(Client, 3, 0, 0, 0, 255);
	CPrintToChatAll("\x03变身为第四阶段坦克:\x03%N \n{red}生命值:\x03%d 速度倍率:{red}%.1f", Client, GetClientHealth(Client), speed);
	//CPrintToChatAll("\x03此阶段拥有技能:\n{red}彗星石头:\x05投掷出的石头会产生爆炸对幸存者造成伤害!");
}

GetBalanceTankHP(Handle:lv_hdl, type)
{
	new String:TankHP_Array[64];
	new String:TankHP[3][21];
	GetConVarString(lv_hdl, TankHP_Array, sizeof(TankHP_Array));
	if(strlen(TankHP_Array))
	{
		ExplodeString(TankHP_Array, ",", TankHP, 3, 21);
		switch(type)
		{
			case TANK1: return StringToInt(TankHP[0]);
			case TANK5: return StringToInt(TankHP[1]);
			case TANK6: return StringToInt(TankHP[2]);
		}
	}
	return 0;
}
//end