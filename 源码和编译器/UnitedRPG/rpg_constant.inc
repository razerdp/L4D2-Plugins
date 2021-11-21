/************************************************************************
*	各种常量变量
************************************************************************/
#define CVAR_FLAGS FCVAR_PLUGIN|FCVAR_NOTIFY
#define COMMAND_FILTER COMMAND_FILTER_CONNECTED|COMMAND_FILTER_NO_BOTS
#define DEFAULT_TIMER_FLAGS TIMER_REPEAT|TIMER_FLAG_NO_MAPCHANGE

/**********************
*	 拜师收徒
**********************/
new String:shifu[MAXPLAYERS+1][MAX_NAME_LENGTH];//师傅名字
new String:tudi[MAXPLAYERS+1][MAX_NAME_LENGTH];//徒弟名字
new shifuNem[MAXPLAYERS+1];//师傅数量
new tudiNem[MAXPLAYERS+1];//徒弟数量
new Cbution[MAXPLAYERS+1];//贡献值
new ticeship[MAXPLAYERS+1];//出师数
new tudLv[MAXPLAYERS+1];//徒弟等级
new tudNL[MAXPLAYERS+1];//徒弟转生
new tudEXP[MAXPLAYERS+1];//徒弟经验
new shifLv[MAXPLAYERS+1];//徒弟等级
new shifNL[MAXPLAYERS+1];//徒弟转生
new shifEXP[MAXPLAYERS+1];//徒弟经验
/**********************
*	 玩家基本数据
**********************/
new MP[MAXPLAYERS+1];
#define KTLimit 5	//TK上限
new Handle:NewLifeLv;	//转生最低等级要求
#define PasswordRemindSecond 10	//密码提示间隔
#define PasswordLength 64	//最大密码长度
new bool:IsPasswordConfirm[MAXPLAYERS+1]	= {	false, ...};
new PasswordRemindTime[MAXPLAYERS+1];

/* 玩家真实等级 */
#define PLAYER_LV[%1]			(Lv[%1] + NewLifeCount[%1] * 100)

/* 死亡和倒地奖励惩罚 */
#define DEATH_EXP[%1]			Lv[%1] * 20
#define DEATH_CASH[%1]			Lv[%1] * 10
#define INCAP_EXP[%1]			Lv[%1] * 1.5
#define INCAP_CASH[%1]			Lv[%1] * 0.5

/**********************
*	 玩家属性
**********************/
/** 等级上限 **/
#define Limit_Lv 9999
/** 属性上限 **/
#define Limit_Str 10000
#define Limit_Agi 1000
#define Limit_Health 10000
#define Limit_Endurance 1000
#define Limit_Intelligence 10000
#define Limit_Crits 10000
#define Limit_CritMin 10000
#define Limit_CritMax 10000
/** 属性效能 **/
#define Effect_Str 0.00025
#define Effect_Agi 0.0005		//敏捷增加比率 1000敏捷= 100%的移动速度
#define Effect_Health 0.025
#define Effect_Endurance 0.001
#define Effect_MaxEndurance 0.5
//暴击效能
#define Effect_Crits 0.008
#define Effect_CritMin 0.005
#define Effect_CritMax 0.005
#define BasicIMP 1
#define BasicMaxMP 700000
/** 属性效果 **/
//普通属性
#define StrEffect[%1]				 Str[%1]*Effect_Str	//Str[%1]*(1+Lis[%1])*Effect_Str
#define AgiEffect[%1]				 Agi[%1]*Effect_Agi	//Agi[%1]*(1+Lis[%1])*Effect_Agi
#define HealthEffect[%1]			 Health[%1]*Effect_Health	//Health[%1]*(1+Lis[%1])*Effect_Health
#define EnduranceEffect[%1]			 (Endurance[%1] * Effect_Endurance > 0.95 ? 0.95 : Endurance[%1] * Effect_Endurance)		//*(1+Lis[%1])
#define IntelligenceEffect_IMP[%1]	 (BasicIMP + Lv[%1] + Intelligence[%1] / 2)		//*(1+Lis[%1])

//暴击属性
#define CritsEffect[%1]		Crits[%1]*Effect_Crits	//*(1+Lis[%1])
#define CritMinEffect[%1]	CritMin[%1]*Effect_CritMin	//*(1+Lis[%1])
#define CritMaxEffect[%1]	CritMax[%1]*Effect_CritMax+CritMinEffect[%1]	//*(1+Lis[%1])
//MP最大值
#define MaxMP[%1]					BasicMaxMP + 1 * (Lv[%1] + Intelligence[%1]) + ZB_MPBuffer[%1]

/**********************
*	 幸存者通用技能
**********************/
new HealingCounter[MAXPLAYERS+1];

//治疗术
#define HealingEffect[%1]							20 + ZB_Healing[%1]
#define HealingDuration[%1]						30 + HealingLv[%1]
//地震术
#define EarthQuakeRadius[%1]				300 + 30 * EarthQuakeLv[%1]		//地震术范围 20 + 26 * 地震术等级
#define EarthQuakeMaxKill[%1]				15 + 2 * EarthQuakeLv[%1]
//重机枪
#define GELINMaxDmg[%1]					     20+20 * GELINLv[%1]
//强化苏醒术
#define EndranceQualityEffect[%1]				0.3 + 1.00*EndranceQualityLv[%1]

/**********************
*	 工程师
**********************/
/* 职业属性需求 */
#define JOB1_Str 15
#define JOB1_Agi 15
#define JOB1_Health 15
#define JOB1_Endurance 15
#define JOB1_Intelligence 40
new bool:IsSatelliteCannonReady[MAXPLAYERS+1];
#define SatelliteCannon_Sound_Launch		"animation/bombing_run_01.wav"

//制造子弹
#define AmmoMakingEffect[%1]					5*AmmoMakingLv[%1]
#define AmmoMakingmissEffect[%1]					0
//卫星炮术
#define SatelliteCannonTKExpFactor				1
#define SatelliteCannonLaunchTime				2.0
#define SatelliteCannonDamage[%1]				Str[%1] / 100 + 300 + 600 * SatelliteCannonLv[%1]
#define SatelliteCannonSurvivorDamage[%1]		1 + SatelliteCannonLv[%1]
#define SatelliteCannonCDTime[%1]				30.0
#define SatelliteCannonRadius[%1]				150 + 100*SatelliteCannonLv[%1]
#define SatelliteCannonmissTKExpFactor				10
#define SatelliteCannonmissLaunchTime				1.0
//射速加强术
#define FireSpeedEffect[%1]						0.1*FireSpeedLv[%1]




/**********************
*	 士兵
**********************/
/* 职业属性需求 */
#define JOB2_Str 35
#define JOB2_Agi 10
#define JOB2_Health 10
#define JOB2_Endurance 35
#define JOB2_Intelligence 10
/* 加速冲刺术 */
new bool:IsSprintEnable[MAXPLAYERS+1];
/* 无限子弹术 */
new bool:IsInfiniteAmmoEnable[MAXPLAYERS+1];
/* 狂暴者模式 */
new ChainkbLightningLv[MAXPLAYERS+1];
new bool:IsChainkbed[MAXPLAYERS+1];
new HealingkbLv[MAXPLAYERS+1];
new HealingkbCounter[MAXPLAYERS+1];
new HealingwxLv[MAXPLAYERS+1];
new HealingwxCounter[MAXPLAYERS+1];
new HealinggbdLv[MAXPLAYERS+1];
new HealinggbdCounter[MAXPLAYERS+1];
new bool:IsBioShieldkbEnable[MAXPLAYERS+1];
new bool:IsBioShieldkbReady[MAXPLAYERS+1];
#define ChainkbLightning_Sound_launch		"music/zombat/slayer/fiddle/violin_slayer_02_01e.wav"
#define ChainkbLightning_Particle_hit		"electrical_arc_01_system"

//攻防加强术
#define EnergyEnhanceEffect_MaxEndurance[%1]	(0.004 * EnergyEnhanceLv[%1])
#define EnergyEnhanceEffect_Endurance[%1]		(0.0075 * EnergyEnhanceLv[%1])
#define EnergyEnhanceEffect_Attack[%1]			(0.016 * EnergyEnhanceLv[%1])
//加速冲刺术
#define SprintEffect[%1]						Agi[%1] / 1500 + 0.5 + 0.01 * SprintLv[%1]
#define SprintDuration[%1]						5.0 + SprintLv[%1]
#define MP_Sprint							3000 //释放时需要的MP
//无限子弹术
#define InfiniteAmmoDuration[%1]				20.0 + 2.0*InfiniteAmmoLv[%1]
#define MP_Ammo							3000 //释放时需要的MP
//狂暴模式关联
#define ChainkbLightningInterval[%1]				1.0
#define ChainkbLightningDamage[%1]				600 + 1*ChainkbLightningLv[%1]
#define ChainkbLightningRadius[%1]				0 + 0*ChainkbLightningLv[%1]
#define ChainkbLightningLaunchRadius[%1]			170 + 50*ChainkbLightningLv[%1]
#define MP_ChainkbLightning					3000 //释放时需要的MP
//狂暴模式关联
#define HealingkbEffect							999
#define HealingkbDuration[%1]						49 + HealingkbLv[%1]
#define HealingwxEffect							999
#define HealingwxDuration[%1]						49 + HealingwxLv[%1]
#define HealinggbdEffect							999
#define HealinggbdDuration[%1]						49 + HealinggbdLv[%1]

/**********************
*	 生物专家
**********************/
/* 职业属性需求 */
#define JOB3_Str 10
#define JOB3_Agi 35
#define JOB3_Health 10
#define JOB3_Endurance 10
#define JOB3_Intelligence 35
/* 无敌术 */
new bool:IsBioShieldEnable[MAXPLAYERS+1];
new bool:IsBioShieldReady[MAXPLAYERS+1];
/* 反伤术 */
new bool:IsDamageReflectEnable[MAXPLAYERS+1];
/* 近战嗜血术 */
new bool:IsMeleeSpeedEnable[MAXPLAYERS+1];
/* 承受伤害经验 */
#define BearDmgExp[%1]						Lv[%1] / 700 + 0.1
#define BearDmgCash[%1]						Lv[%1] / 900 + 0.1
/* 潜能大暴发 */
new bool:IsBioShieldmissEnable[MAXPLAYERS+1];
new bool:IsBioShieldmissReady[MAXPLAYERS+1];
new HealingBallmissLv[MAXPLAYERS+1];
new HealingBallmissExp[MAXPLAYERS+1];
new bool:IsHealingBallmissEnable[MAXPLAYERS+1];
new Handle:HealingBallmissTimer[MAXPLAYERS+1];
//#define HealingBall_Particle			"st_elmos_fire_cp0"
#define HealingBallmiss_Particle_Effect	"st_elmos_fire_cp0"
#define HealingBallmiss_Sound_Lanuch	"ambient/fire/gascan_ignite1.wav"
#define HealingBallmiss_Sound_Heal		"buttons/bell1.wav"
new ChainmissLightningLv[MAXPLAYERS+1];
new bool:IsChainmissed[MAXPLAYERS+1];
#define ChainmissLightning_Sound_launch		"plats/churchbell_end.wav"
#define ChainmissLightning_Particle_hit		"electrical_arc_01_system"

/* 武器速度 */
new WRQ[MAXPLAYERS+1];
new WRQL;
new Float:Multi[MAXPLAYERS+1];

/* 承担伤害 */
new BearDamage[MAXPLAYERS+1][MAXPLAYERS+1];

//无敌术
#define BioShieldDuration[%1]					5.0 + 1.0*BioShieldLv[%1]
#define BioShieldCDTime[%1]						80.0 - 1.0*BioShieldLv[%1]
#define BioShieldSideEffect[%1]					0.2 + 0.01*BioShieldLv[%1]
#define BioShieldmissDuration[%1]					0.5 + 0*BioShieldmissLv[%1]
#define BioShieldmissCDTime[%1]						400.0 - 0.0*BioShieldmissLv[%1]
#define BioShieldmissSideEffect					0
#define BioShieldkbDuration[%1]					45.0 + 5.0*BioShieldkbLv[%1]
#define BioShieldkbCDTime[%1]						161.0 - 1.0*BioShieldkbLv[%1]
#define BioShieldkbSideEffect					0
//反伤术
#define DamageReflectEffect[%1]					Endurance[%1] + 25.0 * DamageReflectLv[%1]			//耐力等级 + 5 * 40 = 500 + 400 = 900
#define DamageReflectDuration[%1]				10.0 + 2.0 * DamageReflectLv[%1]
#define DamageReflectSideEffect[%1]				0.2 + 0.01*DamageReflectLv[%1]
//近战嗜血术
#define MeleeSpeedEffect[%1]					MeleeSpeedLv[%1]*0.1
#define MeleeSpeedDuration[%1]					20.0 + 1.0*MeleeSpeedLv[%1]
//基因改造
#define GeneHealthEffect[%1]					20 * GeneLv[%1]
#define GeneEndEffect[%1]						(0.0048 * GeneLv[%1])
//潜能大爆发关联
#define ChainmissLightningDamage[%1]				Str[%1]*300 + 300 * ChainmissLightningLv[%1]
#define ChainmissLightningRadius[%1]				0 + 0*ChainmissLightningLv[%1]
#define ChainmissLightningCDTime[%1]				120.0 - 0*ChainmissLightningLv[%1]
#define ChainmissLightningLaunchRadius[%1]			90000 + 1*ChainmissLightningLv[%1]


/**********************
*	 心灵医生
**********************/
/* 职业属性需求 */
#define JOB4_Str 5
#define JOB4_Agi 30
#define JOB4_Health 30
#define JOB4_Endurance 5
#define JOB4_Intelligence 30
/* 选择传送术 */
new bool:IsTeleportToSelectEnable[MAXPLAYERS+1];
/* 审判光球术 */
new bool:IsHolyBoltEnable[MAXPLAYERS+1];
new LightBallReward[MAXPLAYERS+1];
/* 审判光球经验 */
#define LightBallExp							0.15
#define LightBallCash						0.01
/* 心灵传送术 */
new bool:IsTeleportTeamEnable[MAXPLAYERS+1];
/* 治疗光球术 */
new HealingBallExp[MAXPLAYERS+1];
new bool:IsHealingBallEnable[MAXPLAYERS+1];
new Handle:HealingBallTimer[MAXPLAYERS+1];
//#define HealingBall_Particle			"st_elmos_fire_cp0"
#define HealingBall_Particle_Effect	"st_elmos_fire_cp0"
#define HealingBall_Sound_Lanuch	"ambient/fire/gascan_ignite1.wav"
#define HealingBall_Sound_Heal		"buttons/bell1.wav"
/* 全体传送术 */
new bool:IsTeleportTeamztEnable[MAXPLAYERS+1];

//医师拉人增加额外经验比例
#define Job4_ExtraReward[%1]					Lv[%1] + TeleportToSelectLv[%1] + HolyBoltLv[%1] + TeleportTeamLv[%1]
//治疗光球术
#define HealingBallInterval[%1]						0.05
#define HealingBallEffect[%1]					5 + HealingBallLv[%1]
#define HealingBallRadius[%1]					1000 + 1000 * HealingBallLv[%1]
#define HealingBallDuration[%1]					30.0
#define HealingBallmissInterval						1.0
#define HealingBallmissEffect[%1]					900
#define HealingBallmissRadius[%1]					300 + 100*HealingBallLv[%1]
#define HealingBallmissDuration[%1]					3.0 + 0*HealingBallLv[%1]
#define HealingBallDamage[%1]						Intelligence[%1] / 100 + 100 * FireBallLv[%1]
#define HealingBallLife							10.0
//审判光球术
#define LightBallHealth[%1]						Intelligence[%1] + HolyBoltLv[%1] * 5 - HolyBoltLv[%1]
#define LightBallDamage[%1]						ZB_MPBuffer[%1] * 1 + 200 * HolyBoltLv[%1] + NewLifeCount[%1] * 2000



/**********************
*	 魔法师
**********************/
/* 职业属性需求 */
#define JOB5_Str 5
#define JOB5_Agi 5
#define JOB5_Health 5
#define JOB5_Endurance 5
#define JOB5_Intelligence 80
/* 地狱火 */
new bool:FireBallCD[MAXPLAYERS+3];
#define FireBall_Model				"models/props_unique/airport/atlas_break_ball.mdl"
#define FireBall_Sound_Impact01		"ambient/fire/gascan_ignite1.wav"
#define FireBall_Sound_Impact02		"ambient/atmosphere/firewerks_burst_01.wav"
#define FireBall_Particle_Fire01	"molotov_explosion"
#define FireBall_Particle_Fire02	"gas_explosion_fireball2"
#define FireBall_Particle_Fire03	"fire_small_03"
/* 寒冰爆弹 */
new bool:FreezeCD[MAXPLAYERS+1];	//冰球术冷却
new bool:IsFreeze[MAXPLAYERS+1];
#define IceBall_Sound_Impact01		"animation/van_inside_hit_wall.wav"
#define IceBall_Sound_Impact02		"ambient/explosions/explode_3.wav"
#define IceBall_Sound_Freeze		"physics/glass/glass_pottery_break3.wav"
#define IceBall_Sound_Defrost		"physics/glass/glass_sheet_break1.wav"
#define IceBall_Particle_Ice01		"pillardust_highrise"
/* 连锁闪电术 */
new bool:IsChained[MAXPLAYERS+1];
new bool:ChainLightningCD[MAXPLAYERS+1];
#define ChainLightning_Sound_launch		"ambient/energy/zap1.wav"
#define ChainLightning_Particle_hit		"electrical_arc_01_system"
/* 终结式暴雷 */
new bool:IsSatelliteCannonmissReady[MAXPLAYERS+1];
#define SatelliteCannonmiss_Sound_Launch		"animation/bridge_destruct_swt_01.wav"

//地狱火
#define FireIceBallLife							10.0
#define FireBallDamageInterval[%1]				1.0
#define FireBallDamage[%1]						ZB_MPBuffer[%1] * 1 + 500 * FireBallLv[%1] + NewLifeCount[%1] * 2000
#define FireBallTKDamage[%1]					1
#define FireBallDuration[%1]					3.0 + 0.03 * FireBallLv[%1]
#define FireBallRadius[%1]						100 + 10 * FireBallLv[%1]
//寒冰爆弹
#define IceBallDamage[%1]						ZB_MPBuffer[%1] * 1 + 550 * IceBallLv[%1] + NewLifeCount[%1] * 2000
#define IceBallTKDamage[%1]						1
#define IceBallDuration[%1]						3.0
#define IceBallRadius[%1]						400
//连锁闪电术
#define ChainLightningInterval[%1]				1.0
#define ChainLightningDamage[%1]				ZB_MPBuffer[%1] * 1 + 100 * ChainLightningLv[%1] + NewLifeCount[%1] * 2000   // 闪电伤害，智力加成
#define ChainLightningRadius[%1]				0 + ChainLightningLv[%1]     //连锁范围
#define ChainLightningLaunchRadius[%1]			500 + 20*ChainLightningLv[%1]  //发动范围
#define ChainmissLightningInterval[%1]				1.0
//终结式暴雷
#define SatelliteCannonmissDamage[%1]				ZB_MPBuffer[%1] * 1 + 100000 * SatelliteCannonmissLv[%1] + NewLifeCount[%1] * 2000
#define SatelliteCannonmissSurvivorDamage[%1]		100 + 0*SatelliteCannonmissLv[%1]
#define SatelliteCannonmissCDTime[%1]				60.0 - 0*SatelliteCannonmissLv[%1]
#define SatelliteCannonmissRadius[%1]				600.0 * SatelliteCannonmissLv[%1]

/**********************
*	 弹药师
**********************/
/* 职业属性需求 */
#define JOB6_Str 200
#define JOB6_Agi 40
#define JOB6_Health 30
#define JOB6_Endurance 30
#define JOB6_Intelligence 100

//破碎弹
new bool:Broken_Ammo[MAXPLAYERS+1] = false;
#define BrokenAmmoDamage[%1]						200 * BrokenAmmoLv[%1]
#define BrokenAmmoDuration[%1]						30.0 + 1.0 * BrokenAmmoLv[%1]
#define BrokenAmmoRange								45
#define LvLimit_BrokenAmmo							50
#define MP_BrokenAmmo								10000
//渗毒弹
new bool:Poison_Ammo[MAXPLAYERS+1] = false;
#define PoisonAmmoDamage[%1]						30 * PoisonAmmoLv[%1]
#define PoisonAmmoDamageTime[%1]					1.0
#define PoisonAmmoDuration[%1]						30.0 + 1.0 * PoisonAmmoLv[%1]
#define LvLimit_PoisonAmmo							80
#define MP_PoisonAmmo								10000
//嗜血弹
new bool:SuckBlood_Ammo[MAXPLAYERS+1] = false;
#define SuckBloodAmmoPBB[%1]						1.5 * SuckBloodAmmoLv[%1]
#define SuckBloodAmmoDuration[%1]					30.0 + 1.0 * SuckBloodAmmoLv[%1]
#define SOUND_SUCKBLOOD "level/puck_slide_down.wav"
#define LvLimit_SuckBloodAmmo						50
#define MP_SuckBloodAmmo								10000
//区域爆破
new bool:AreaBlasting[MAXPLAYERS+1];
#define AreaBlastingDamage[%1]						100 * AreaBlastingLv[%1]
#define AreaBlastingRange[%1]						3 + 1 * AreaBlastingLv[%1]
#define AreaBlastingCD[%1]							2.0
#define LvLimit_AreaBlasting						30
#define MP_AreaBlasting								15000
//镭射激光炮
new bool:LaserGun[MAXPLAYERS+1];
//激光镭射计时
new Float:LaserGunDamagetimer[MAXPLAYERS+1];
#define LaserGunDamage[%1]							 60000 * LaserGunLv[%1]
#define LaserGunCD[%1]								200.0 + 160.0 * LaserGunLv[%1]
#define LaserGunDuration[%1]						3.0 + 1.0 * LaserGunLv[%1]


/**********************
*	 勾魂使者
**********************/
/* 职业属性需求 */
#define JOB7_Str 350
#define JOB7_Agi 20
#define JOB7_Health 50
#define JOB7_Endurance 50
#define JOB7_Intelligence 30
//审判领域相关
new bool:AreaBlastingex[MAXPLAYERS+1];
#define SatelliteCannon_Sound_Launch		"animation/bombing_run_01.wav"
#define AreaBlastingexLaunchTime				1.0
#define AreaBlastingexDamage[%1]                20000 + 20*AreaBlastingexLv[%1]
#define AreaBlastingexRange[%1]                 3000 + 10*AreaBlastingexLv[%1]
#define AreaBlastingexCD[%1]                    40.0 - 1.0*AreaBlastingexLv[%1]
//灵力上限
#define GeneHealthzEffect[%1]					10 * LinliLv[%1]


/**********************
*	死神
**********************/
/* 职业属性需求 */
#define JOB8_Str 50
#define JOB8_Agi 50
#define JOB8_Health 50
#define JOB8_Endurance 50
#define JOB8_Intelligence 50
//大地之怒相关
#define DyzhRadius[%1]				10+ 10 * DyzhLv[%1]
#define DyzhMaxKill[%1]				10+ 10 * DyzhLv[%1]
//死神之力
#define GeneHealthzkEffect[%1]					3 * SszlLv[%1]

/**********************
*	黑暗行者
**********************/
/* 职业属性需求 */
#define JOB9_Str 10
#define JOB9_Agi 10
#define JOB9_Health 30
#define JOB9_Endurance 10
#define JOB9_Intelligence 20
//超强地震相关
#define CqdzRadius[%1]				10 + 10 * CqdzLv[%1]
#define CqdzMaxKill[%1]				50 + 10 * CqdzLv[%1]
//射速加强
#define HassEffect[%1]						0.3 * HassLv[%1]
//子弹工程
#define ZdgcEffect[%1]					6 * ZdgcLv[%1]

/**********************
*	死亡祭师
**********************/
/* 职业属性需求 */
#define JOB10_Str 20
#define JOB10_Agi 40
#define JOB10_Health 30
#define JOB10_Endurance 30
#define JOB10_Intelligence 20
/* 死亡护体 */
new bool:IsSWHTEnable[MAXPLAYERS+1];
new bool:IsSWHTReady[MAXPLAYERS+1];
/* 无限能源 */
new bool:IsWXNYEnable[MAXPLAYERS+1];

//无限子弹术
#define WXNYDuration[%1]				60.0 + 2.0*WXNYLv[%1]
//死亡护体
#define SWHTDuration[%1]					5.0 + 1.0*SWHTLv[%1]
#define SWHTCDTime[%1]						80.0 - 1.0*SWHTLv[%1]
#define SWHTSideEffect[%1]					0.2 + 0.01*SWHTLv[%1]

//死亡改造
#define SWGZEffect[%1]					6 * SWGZLv[%1]

/**********************
*	雷电使者
**********************/
/* 职业属性需求 */
#define JOB11_Str 40
#define JOB11_Agi 40
#define JOB11_Health 30
#define JOB11_Endurance 30
#define JOB11_Intelligence 20
new bool:IsYLTJReady[MAXPLAYERS+1];
/* 雷电子 */
new bool:IsLDZed[MAXPLAYERS+1];
#define LDZ_Sound_launch		"ambient/energy/zap1.wav"
#define LDZ_Particle_hit		"electrical_arc_01_system"

//雷电子
#define LDZInterval[%1]				2.0
#define LDZDamage[%1]		5000+30 * LDZLv[%1]
#define LDZCD[%1]					5.0
#define LDZRadius[%1]				50 + LDZLv[%1]
#define LDZLaunchRadius[%1]			30 + 15*LDZLv[%1]
#define LDZmissInterval[%1]				1.0
/* 光之速 */
new bool:IsGZSEnable[MAXPLAYERS+1];

//光之速
#define GZSEffect[%1]						Agi[%1] / 1500 + 0.5 + 0.01 * GZSLv[%1]
#define GZSDuration[%1]						6.0 + GZSLv[%1]

/* 电磁感应 */
new bool:IsYLTJmissReady[MAXPLAYERS+1];
#define YLTJ_Sound_Launch		"ambient/fire/gascan_ignite1.wav"
//电磁感应
#define YLTJDamage[%1]				 20000 + 50 * YLTJLv[%1]
#define YLTJSurvivorDamage[%1]		10 + 0*YLTJLv[%1]
#define YLTJCDTime[%1]				20.0 - 0*YLTJLv[%1]
#define YLTJRadius[%1]				50.0 * YLTJLv[%1]
#define YLTJLaunchTime				2.0

//雷子弹
new bool:LZD_Ammo[MAXPLAYERS+1] = false;
#define LZDDamage[%1]			           300 * LZDLv[%1]
#define LZDDuration[%1]						30.0 + 1.0 * LZDLv[%1]
#define LZDRange								45
#define LZDSurvivorDamage[%1]               1 
#define LvLimit_LZD							40
#define LZDCDTime[%1]						3.0
#define MP_LZD								9000

/**********************
*	影武者
**********************/
/* 职业属性需求 */
#define JOB12_Str 20
#define JOB12_Agi 40
#define JOB12_Health 30
#define JOB12_Endurance 30
#define JOB12_Intelligence 20
/* 风暴之怒 */
new bool:FBZNCD[MAXPLAYERS+3];
#define FBZN_Model				"models/props_unique/airport/atlas_break_ball.mdl"
#define FBZN_Sound_Impact01		"ambient/fire/gascan_ignite1.wav"
#define FBZN_Sound_Impact02		"ambient/atmosphere/firewerks_burst_01.wav"
#define FBZN_Particle_Fire01	"molotov_explosion"
#define FBZN_Particle_Fire02	"gas_explosion_fireball2"
#define FBZN_Particle_Fire03	"fire_small_03"
//风暴之怒
#define FBZNIceBallLife							5.0
#define FBZNDamageInterval[%1]				1.0
#define FBZNDamage[%1]					ZB_MPBuffer[%1] * 1 + 1500 * FBZNLv[%1] + NewLifeCount[%1] * 2000
#define FBZNDuration[%1]						4.0
#define FBZNTKDamage[%1]					1
#define FBZNCDTime[%1]						6.0
#define FBZNRadius[%1]						400

/* 玄冰风暴 */
new bool:FreefbCD[MAXPLAYERS+1];	//冰球术冷却
new bool:IsXBFB[MAXPLAYERS+1];
#define XBFB_Sound_Impact01		"animation/van_inside_hit_wall.wav"
#define XBFB_Sound_Impact02		"ambient/explosions/explode_3.wav"
#define XBFB_Sound_Freeze		"physics/glass/glass_pottery_break3.wav"
#define XBFB_Sound_Defrost		"physics/glass/glass_sheet_break1.wav"
#define XBFB_Particle_Ice01		"pillardust_highrise"
//玄冰风暴
#define XBFBDamage[%1]					ZB_MPBuffer[%1] * 1 + 1500 * XBFBLv[%1] + NewLifeCount[%1] * 2000
#define XBFBTKDamage[%1]						1
#define XBFBDuration[%1]						4.0
#define XBFBCDTime[%1]				5.0
#define XBFBRadius[%1]						300

/* 武者之光 */
new bool:IsWZZGmissReady[MAXPLAYERS+1];
new bool:IsWZZGReady[MAXPLAYERS+1];
#define WZZG_Sound_Launch		"ambient/fire/gascan_ignite1.wav"
//武者之光
#define WZZGDamage[%1]				50000 + 100 * WZZGLv[%1]
#define WZZGSurvivorDamage[%1]		5 + 0*WZZGLv[%1]
#define WZZGCDTime[%1]				60.0
#define WZZGRadius[%1]				10.0 * WZZGLv[%1]
#define WZZGLaunchTime				0.0

/**********************
*	审判者
**********************/
/* 职业属性需求 */
#define JOB13_Str 60
#define JOB13_Agi 60
#define JOB13_Health 50
#define JOB13_Endurance 50
#define JOB13_Intelligence 70
/* 毁灭之书 */
new bool:HMZSCD[MAXPLAYERS+3];
#define HMZS_Model				"models/props_unique/airport/atlas_break_ball.mdl"
#define HMZS_Sound_Impact01		"ambient/fire/gascan_ignite1.wav"
#define HMZS_Sound_Impact02		"ambient/atmosphere/firewerks_burst_01.wav"
#define HMZS_Particle_Fire01	"molotov_explosion"
#define HMZS_Particle_Fire02	"gas_explosion_fireball2"
#define HMZS_Particle_Fire03	"fire_small_03"
//毁灭之书
#define HMZSIceBallLife							10.0
#define HMZSDamageInterval[%1]				1.0
#define HMZSDamage[%1]						ZB_MPBuffer[%1] * 1 + 3000 * HMZSLv[%1] + NewLifeCount[%1] * 2000
#define HMZSTKDamage[%1]					1
#define HMZSDuration[%1]					6.0 + 0.03 * HMZSLv[%1]
#define HMZSRadius[%1]						30 * HMZSLv[%1]

/* 审判之书 */
new bool:IsSPZSed[MAXPLAYERS+1];
#define SPZS_Sound_launch		"ambient/energy/zap1.wav"
#define SPZS_Particle_hit		"electrical_arc_01_system"

//审判之书
#define SPZSInterval[%1]				2.0
#define SPZSDamage[%1]				    150 * SPZSLv[%1]
#define SPZSRadius[%1]				0 + SPZSLv[%1]
#define SPZSLaunchRadius[%1]			60 + 40*SPZSLv[%1]
#define SPZSmissInterval[%1]				1.0


/* 极冰盛宴 */
new bool:IsJBSY[MAXPLAYERS+1];
#define JBSY_Sound_Impact01		"animation/van_inside_hit_wall.wav"
#define JBSY_Sound_Impact02		"ambient/explosions/explode_3.wav"
#define JBSY_Sound_Freeze		"physics/glass/glass_pottery_break3.wav"
#define JBSY_Sound_Defrost		"physics/glass/glass_sheet_break1.wav"
#define JBSY_Particle_Ice01		"pillardust_highrise"
//玄冰风暴
#define JBSYDamage[%1]					ZB_MPBuffer[%1] * 1 + 1500 * JBSYLv[%1] + NewLifeCount[%1] * 2000
#define JBSYTKDamage[%1]						1
#define JBSYDuration[%1]						4.0
#define JBSYCDTime[%1]				5.0
#define JBSYRadius[%1]						300


/**********************
*	毒龙
**********************/
/* 职业属性需求 */
#define JOB14_Str 20
#define JOB14_Agi 30
#define JOB14_Health 20
#define JOB14_Endurance 25
#define JOB14_Intelligence 100

//坚硬身躯
#define JYSQEffect[%1]					5 * JYSQLv[%1]

/* 嗜血之光 */
new bool:IsSXZGEnable[MAXPLAYERS+1];
new SXZGReward[MAXPLAYERS+1];
/* 嗜血之光经验 */
#define SXZGExp							1.0
#define SXZGCash						0.1
//嗜血之光
#define SXZGHealth[%1]						SXZGLv[%1] * 1 + SXZGLv[%1] * 10 - SXZGLv[%1]
#define SXZGDamage[%1]						ZB_MPBuffer[%1] * 1 + 3000 * SXZGLv[%1]
#define SXZGCD[%1]							4.0

//毒龙爆破
new bool:BBBS[MAXPLAYERS+1];
#define BBBSSound_Launch		"animation/bombing_run_01.wav"
#define BBBSDamage[%1]						ZB_MPBuffer[%1] * 1 + 1000 * BBBSLv[%1] + NewLifeCount[%1] * 2000
#define BBBSRange[%1]						300 + 15 * BBBSLv[%1]
#define BBBSCD[%1]							5.0
#define LvLimit_BBBS						50
#define MP_BBBS							15000

/* 毒龙之光 */
new bool:IsDSZGmissReady[MAXPLAYERS+1];
new bool:IsDSZGReady[MAXPLAYERS+1];
#define DSZG_Sound_Launch		"ambient/fire/gascan_ignite1.wav"
//毒龙之光
#define DSZGDamage[%1]				ZB_MPBuffer[%1] * 1 + 1000 * DSZGLv[%1] + NewLifeCount[%1] * 2000
#define DSZGSurvivorDamage[%1]		5 + 0*DSZGLv[%1]
#define DSZGCDTime[%1]				6.0
#define DSZGRadius[%1]				15.0 * DSZGLv[%1]
#define DSZGLaunchTime				0.0


/**********************
*	幻影统帅
**********************/
/* 职业属性需求 */
#define JOB15_Str 50
#define JOB15_Agi 50
#define JOB15_Health 50
#define JOB15_Endurance 50
#define JOB15_Intelligence 100
/* 幻影之炎 */
new bool:PHFRCD[MAXPLAYERS+3];
#define PHFR_Model				"models/props_unique/airport/atlas_break_ball.mdl"
#define PHFR_Sound_Impact01		"ambient/fire/gascan_ignite1.wav"
#define PHFR_Sound_Impact02		"ambient/atmosphere/firewerks_burst_01.wav"
#define PHFR_Particle_Fire01	"molotov_explosion"
#define PHFR_Particle_Fire02	"gas_explosion_fireball2"
#define PHFR_Particle_Fire03	"fire_small_03"
//幻影之炎
#define PHFRIceBallLife							10.0
#define PHFRDamageInterval[%1]				1.0
#define PHFRDamage[%1]						ZB_MPBuffer[%1] * 1 + 1000 * PHFRLv[%1] + NewLifeCount[%1] * 2000
#define PHFRTKDamage[%1]					1
#define PHFRCDTime[%1]						6.0
#define PHFRDuration[%1]					4.0 + 0.03 * XBFBLv[%1]
#define PHFRRadius[%1]						1000

//幻影爆破
new bool:PHAB[MAXPLAYERS+1];
#define PHAB_Sound_Launch	            	"animation/bombing_run_01.wav"
#define PHABDamage[%1]						ZB_MPBuffer[%1] * 1 + 1000 * PHABLv[%1] + NewLifeCount[%1] * 2000
#define PHABRange[%1]						300 + 15 * PHABLv[%1]
#define PHABCD[%1]							6.0
#define LvLimit_PHAB						50
#define MP_PHAB								15000

/* 幻影之血 */
new bool:IsPHZGEnable[MAXPLAYERS+1];
new PHZGReward[MAXPLAYERS+1];
/* 幻影之血经验 */
#define PHZGExp							0.0
#define PHZGCash						0.0
//幻影之血
#define PHZGHealth[%1]						Intelligence[%1] + PHZGLv[%1] * 10 - PHZGLv[%1]
#define PHZGDamage[%1]						PHZGLv[%1] * 999

//幻影炮术
#define PHSCTKExpFactor				10
#define PHSCLaunchTime				0.5
#define PHSCDamage[%1]				4600 * PHSCLv[%1]
#define PHSCSurvivorDamage[%1]		20 + PHSCLv[%1]
#define PHSCCDTime[%1]				60.0
#define PHSCRadius[%1]				2000 + 10*PHSCLv[%1]
#define PHSCmissTKExpFactor				10
#define PHSCmissLaunchTime				4.0

/**********************
*	复仇者
**********************/
/* 职业属性需求 */
#define JOB16_Str 50
#define JOB16_Agi 100
#define JOB16_Health 200
#define JOB16_Endurance 50
#define JOB16_Intelligence 500
/* 死亡契约 */
new bool:IsPHFRAEnable[MAXPLAYERS+1];
new bool:IsPHFRAReady[MAXPLAYERS+1];
#define PHFRADuration[%1]					5.0 + 1.0*PHFRALv[%1]
#define PHFRACDTime[%1]						60.0
#define PHFRASideEffect[%1]					0.6


/* 复仇欲望 */
new bool:IsPHABAEnable[MAXPLAYERS+1];
#define PHZGAExp							1.0
#define PHZGACash						0.1
#define PHABAEffect[%1]						Agi[%1] / 1500 + 0.5 + 0.01 * PHABALv[%1]
#define PHABADuration[%1]					30.0 + PHABLv[%1]
#define LvLimit_PHABA						50


/* 爆破光球 */
new bool:IsPHZGAEnable[MAXPLAYERS+1];
new PHZGAReward[MAXPLAYERS+1];
#define PHZGAHealth[%1]						 PHZGALv[%1] * 0
#define PHZGADamage[%1]						PHZGALv[%1] * 650 + 1 * ZB_MPBuffer[%1] + NewLifeCount[%1] * 2000

//闪电光球
new bool:IsPHSDEnable[MAXPLAYERS+1];
new Handle:PHSDTimer[MAXPLAYERS+1];
#define HealingBall_Particle_Effect	"st_elmos_fire_cp0"
#define HealingBall_Sound_Lanuch	"ambient/fire/gascan_ignite1.wav"
#define HealingBall_Sound_Heal		"buttons/bell1.wav"
#define PHSDDamage[%1]				30000 +30 * PHSDLv[%1]
#define PHSDInterval[%1]						1.0
#define PHSDEffect[%1]					5 + PHSDLv[%1]
#define PHSDRadius[%1]					100 + 20 * PHSDLv[%1]
#define PHSDDuration[%1]					30.0

//献祭
#define XJLightningInterval[%1]				1.0
#define XJLightningDamage[%1]				30000
#define XJLightningRadius[%1]				500
#define XJLightningLaunchRadius[%1]			400
#define XJEffect							999
#define XJDuration[%1]					 60.0*XJLv[%1]
#define XJCDTime[%1]						120.0
#define XJADuration[%1]						60.0* XJALv[%1]
#define XJDamageInterval[%1]				1.0
#define XJBDuration[%1]					1.0
new XJALv[MAXPLAYERS+1];
new XJACounter[MAXPLAYERS+1];
new XJLightningLv[MAXPLAYERS+1];
new bool:IsXJed[MAXPLAYERS+1];
new bool:IsXJEnable[MAXPLAYERS+1];
new bool:IsXJReady[MAXPLAYERS+1];

/**********************
*	大祭祀
**********************/
/* 职业属性需求 */
#define JOB17_Str 10
#define JOB17_Agi 10
#define JOB17_Health 10
#define JOB17_Endurance 20
#define JOB17_Intelligence 100

//祭祀之光
new bool:IsLLLZEnable[MAXPLAYERS+1];
new Handle:LLLZTimer[MAXPLAYERS+1];
#define HealingBall_Particle_Effect	"st_elmos_fire_cp0"
#define HealingBall_Sound_Lanuch	"ambient/fire/gascan_ignite1.wav"
#define HealingBall_Sound_Heal		"buttons/bell1.wav"
#define LLLZDamage[%1]				20000 + 100 * LLLZLv[%1]
#define LLLZInterval[%1]						1.0
#define LLLZEffect[%1]					5 + LLLZLv[%1]
#define LLLZRadius[%1]					100 + 20 * LLLZLv[%1]
#define LLLZDuration[%1]					30.0

/* 魔法冲击 */
new bool:IsLLLEmissReady[MAXPLAYERS+1];
new bool:IsLLLEReady[MAXPLAYERS+1];
#define LLLE_Sound_Launch		"ambient/fire/gascan_ignite1.wav"
//魔法冲击
#define LLLEDamage[%1]              ZB_MPBuffer[%1] * 1 + 500 * LLLELv[%1] + NewLifeCount[%1] * 2000
#define LLLESurvivorDamage[%1]		  1*LLLELv[%1]
#define LLLECDTime[%1]				  2.0
#define LLLERadius[%1]				  5.0 * LLLELv[%1]
#define LLLELaunchTime				  0.0

/* 毁灭压制 */
#define LLLS_Sound_Impact01		"animation/van_inside_hit_wall.wav"
#define LLLS_Sound_Impact02		"ambient/explosions/explode_3.wav"
#define LLLS_Sound_Freeze		"physics/glass/glass_pottery_break3.wav"
#define LLLS_Sound_Defrost		"physics/glass/glass_sheet_break1.wav"
#define LLLS_Particle_Ice01		"pillardust_highrise"
//毁灭压制
#define LLLSDamage[%1]						ZB_MPBuffer[%1] * 1 + 1000 * LLLSLv[%1] + NewLifeCount[%1] * 2000
#define LLLSTKDamage[%1]						1
#define LLLSDuration[%1]						5.0
#define LLLSCDTime[%1]				5.0
#define LLLSRadius[%1]						300

/**********************
*	 狂战士
**********************/
/* 职业属性需求 */
#define JOB18_Str 55
#define JOB18_Agi 55
#define JOB18_Health 55
#define JOB18_Endurance 55
#define JOB18_Intelligence 40
/* 幻影剑舞 */
new bool:IsHYJWEnable[MAXPLAYERS+1];
//近战伤害
#define DMG_MELEE[%1]				ZB_Healing[%1] * 1 + 10 * Endurance[%1] + HYJWLv[%1] * 400 + 3000 * NewLifeCount[%1]

//幻影剑舞
#define HYJWEffect[%1]					    HYJWLv[%1]*0.1
#define HYJWDuration[%1]					10.0 + 1.0*HYJWLv[%1]

//怒气爆发
new bool:NQBF[MAXPLAYERS+1];
#define NQBFSound_Launch		            "animation/bombing_run_01.wav"
#define NQBFDamage[%1]						ZB_Healing[%1] * 1 + 4000 * NQBFLv[%1] + 1500 * NewLifeCount[%1]
#define NQBFRange[%1]						300 + 15 * NQBFLv[%1]
#define NQBFCD[%1]							5.0
#define LvLimit_NQBF						50
#define MP_NQBF							    15000


//血之狂暴
#define XZKBLightningInterval[%1]				1.0
#define XZKBLightningDamage[%1]				    60000
#define XZKBLightningRadius[%1]			        	700
#define XZKBLightningLaunchRadius[%1]			500
#define XZKBEffect							    999
#define XZKBDuration[%1]					 300.0*XZKBLv[%1]
#define XZKBCDTime[%1]						30.0
#define XZKBADuration[%1]						300.0* XZKBALv[%1]
#define XZKBDamageInterval[%1]				1.0
#define XZKBBDuration[%1]					1.0
new XZKBALv[MAXPLAYERS+1];
new XZKBACounter[MAXPLAYERS+1];
new XZKBLightningLv[MAXPLAYERS+1];
new bool:IsXZKBed[MAXPLAYERS+1];
new bool:IsXZKBEnable[MAXPLAYERS+1];
new bool:IsXZKBReady[MAXPLAYERS+1];




/**********************
*	变异坦克
**********************/
/* 职业属性需求 */
#define JOB19_Str 10
#define JOB19_Agi 10
#define JOB19_Health 10
#define JOB19_Endurance 20
#define JOB19_Intelligence 100

//变身坦克
#define BSTKMaxDmg[%1]					     20+20 * BSTKLv[%1]


/**********************
*	 技能等级上限
**********************/
#define LvLimit_Healing				50
#define LvLimit_Healingkb			2
#define LvLimit_Healingwx			2
#define LvLimit_Healinggbd			2
#define LvLimit_EndranceQuality		30
#define LvLimit_EarthQuake		    30
#define LvLimit_AmmoMaking			40	//子弹制造术
#define LvLimit_SatelliteCannon		30	//卫星轨道炮
#define LvLimit_SatelliteCannonmiss	1
#define LvLimit_FireSpeed			30	//工程师 射术上限
#define LvLimit_EnergyEnhance		60
#define LvLimit_Sprint				50	//士兵冲刺
#define LvLimit_BioShield			30
#define LvLimit_BioShieldmiss		2
#define LvLimit_BioShieldkb			2
#define LvLimit_DamageReflect		30		//反伤术
#define LvLimit_MeleeSpeed			40
#define LvLimit_InfiniteAmmo		50		//士兵无限子弹
#define LvLimit_TeleportToSelect	40		//选择传送术
#define LvLimit_HolyBolt		    50	//心灵传送术
#define LvLimit_TeleportTeam		40		//集体传送术
#define LvLimit_TeleportTeamzt		2
#define LvLimit_HPRegeneration		30
#define LvLimit_SuperInfected		30
#define LvLimit_InfectedSummon		30
#define LvLimit_FireBall			50	//地狱火
#define LvLimit_IceBall				50	//寒冰爆弹
#define LvLimit_ChainLightning		50	//闪电连锁术
#define LvLimit_ChainmissLightning	30
#define LvLimit_ChainkbLightning	30
#define LvLimit_HealingBall			50	//治疗光球术
#define LvLimit_HealingBallmiss		5
#define LvLimit_Gene				100
#define LvLimit_Gouhun			    2
#define LvLimit_Linli		        10
#define LvLimit_AreaBlastingex		3
#define LvLimit_Aynl		        3
#define LvLimit_Sszl				20
#define LvLimit_Dyzh				40
#define LvLimit_LaserGun			2
#define LvLimit_Zdgc				25
#define LvLimit_Cqdz				30
#define LvLimit_Hass				21
#define LvLimit_SWHT				40
#define LvLimit_WXNY				40
#define LvLimit_SWGZ				15
#define LvLimit_LDZ		            80	//雷电子
#define LvLimit_YLTJ		        80  //电磁感应
#define LvLimit_GZS			     	80	//光之速
#define LvLimit_FBZN				30	//风暴之怒
#define LvLimit_XBFB				30	//玄冰风暴
#define LvLimit_SPZS				30	//审判之书
#define LvLimit_HMZS				30	//毁灭之书
#define LvLimit_JYSQ				15	//坚硬身躯
#define LvLimit_SXZG				30	//吸血之光
#define LvLimit_DSZG				30	//毒龙之光
#define LvLimit_WZZG				30	//武者之光
#define LvLimit_PHFR				30	//幻影之炎
#define LvLimit_PHZG				30	//幻影之血
#define LvLimit_PHSC				30	//幻影炮术
#define LvLimit_PHFRA				1	//死亡契约
#define LvLimit_PHZGA				100	//爆破光球
#define LvLimit_PHSD				100	//闪电光球
#define LvLimit_XJ		            1   //献祭
#define LvLimit_LLLZ		        100 //祭祀之光
#define LvLimit_LLLE				30	//魔法冲击
#define LvLimit_LLLS				50	//毁灭压制
#define LvLimit_GELIN				1	//重机枪等级
#define LvLimit_HYJW				40  //幻影剑舞
#define LvLimit_NQBF				50  //怒气爆发
#define LvLimit_XZKB		        1   //血之狂暴
#define LvLimit_JBSY		        30  //极冰盛宴
#define LvLimit_BSTK		        1  //变身坦克


/* 幸存者经验值 */
new Handle:JockeyKilledExp;
new Handle:HunterKilledExp;
new Handle:ChargerKilledExp;
new Handle:SmokerKilledExp;
new Handle:SpitterKilledExp;
new Handle:BoomerKilledExp;
new Handle:TankKilledExp;
new Handle:WitchKilledExp;
new Handle:ZombieKilledExp;
new Handle:TeammateKilledExp;
new Handle:ReviveTeammateExp;
new Handle:ReanimateTeammateExp;
new Handle:HealTeammateExp;

/* 幸存者金钱 */
new Handle:JockeyKilledCash;
new Handle:HunterKilledCash;
new Handle:ChargerKilledCash;
new Handle:SmokerKilledCash;
new Handle:SpitterKilledCash;
new Handle:BoomerKilledCash;
new Handle:TankKilledCash;
new Handle:WitchKilledCash;
new Handle:ZombieKilledCash;
new Handle:TeammateKilledCash;
new Handle:ReviveTeammateCash;
new Handle:ReanimateTeammateCash;
new Handle:HealTeammateCash;

/* 蘑菇云核弹 */
new nuclearamount[MAXPLAYERS+1];
new DurationTime[MAXPLAYERS+1];
new DurationTime2[MAXPLAYERS+1];

new Handle:Cvar_nuclearEnable, Handle:Cvar_nuclearAmount, Handle:CvarDurationTime, Handle:CvarDurationTime2, Handle:CvarDamageRadius,
Handle:CvarCloudRadius, Handle:CvarDamageforce, Handle:CvarCloudDamage;

new hedancolor[4] = {255,0,0,255};

new Handle:timer_handle[MAXPLAYERS+1][128];
new Handle:hurtdata[MAXPLAYERS+1][128];
new Handle:Cvar_nuclearTime   = INVALID_HANDLE;

new halo;
new fire;
new white;

/* 特殊商店 */
new Handle:RemoveKTCost;//消除大过
new Handle:ResetStatusCost;//遗忘河药水
new Handle:TomeOfExpCost;//经验之书
new Handle:TomeOfExpEffect;//水晶会员

/* 彩票 */
#define	diceNumMin	1
#define	diceNumMax	35
new Handle:LotteryWeakenCommonsHpTimer = INVALID_HANDLE;

new AdminDiceNum[MAXPLAYERS+1]			=	{-1, ...};
new bool:IsGlowClient[MAXPLAYERS+1]		=	{false, ...};
new Handle:LotteryEnable;
new Handle:LotteryCost;
new Handle:LotteryRecycle;

/* 升级奖励 */
new Handle:LvUpSP;
new Handle:LvUpKSP;
new Handle:LvUpCash;

/* 升级成本 */
new Handle:LvUpExpRate;

/* 僵尸被击杀次数计算 */
new ZombiesKillCount[MAXPLAYERS+1];

/* 技能成本 */
new Handle:Cost_Healing;
new Handle:Cost_EarthQuake;
new Handle:Cost_AmmoMaking;
new Handle:Cost_SatelliteCannon;
new Handle:Cost_SatelliteCannonmiss;
new Handle:Cost_BioShield;
new Handle:Cost_BioShieldmiss;
new Handle:Cost_DamageReflect;
new Handle:Cost_MeleeSpeed;
new Handle:Cost_TeleportToSelect;
new Handle:Cost_HolyBolt;
new Handle:Cost_TeleportTeammate;
new Handle:Cost_HealingBall;
new Handle:Cost_FireBall;
new Handle:Cost_IceBall;
new Handle:Cost_ChainLightning;
new Handle:Cost_AreaBlastingex;
new Handle:Cost_Dyzh;
new Handle:Cost_Zdgc;
new Handle:Cost_Cqdz;
new Handle:Cost_SWHT;
new Handle:Cost_WXNY;
new Handle:Cost_GZS;
new Handle:Cost_LDZ;
new Handle:Cost_YLTJ;
new Handle:Cost_FBZN;
new Handle:Cost_XBFB;
new Handle:Cost_HMZS;
new Handle:Cost_SPZS;
new Handle:Cost_SXZG;
new Handle:Cost_DSZG;
new Handle:Cost_WZZG;
new Handle:Cost_PHFR;
new Handle:Cost_PHZG;
new Handle:Cost_PHSC;
new Handle:Cost_PHFRA;
new Handle:Cost_PHZGA;
new Handle:Cost_PHSD;
new Handle:Cost_PHABA;
new Handle:Cost_XJ;
new Handle:Cost_LLLZ;
new Handle:Cost_LLLE;
new Handle:Cost_LLLS;
new Handle:Cost_BBBS;
new Handle:Cost_HYJW;
new Handle:Cost_NQBF;
new Handle:Cost_XZKB;
new Handle:Cost_JBSY;


/* 洗点模式 */
#define General	1
#define Shop	2
#define Admin	3
#define NewLife	0

/* 玩家资讯显示模式 */
#define colored	1
#define simple	2


/* 上弹 */
new S_rActiveW		= -1;
new S_rStartDur		= -1;
new S_rInsertDur	= -1;
new S_rEndDur		= -1;
new S_rPlayRate		= -1;
new s_rTimeIdle		= -1;
new S_rNextPAtt		= -1;
new s_rNextAtt		= -1;

/* 购物商店 */
new Handle:CfgNormalItemShopEnable;
new Handle:CfgSelectedGunShopEnable;
new Handle:CfgMeleeShopEnable;
/* Number of Normal Items */
#define NORMALITEMMAX 13
/* Number of Selected Guns */
#define SELECTEDGUNMAX 9
/* Number of Selected Melees */
#define SELECTEDMELEEMAX 13
/* Number of Robot */
#define ROBOTMAX 17
new String:WeaponName[ROBOTMAX][]={ "猎枪","M16突击步枪","战术散弹枪", "散弹枪", "乌兹冲锋枪", "手枪", "麦格农手枪","AK47",
"SCAR步枪", "SG552步枪", "铬钢散弹枪", "战斗散弹枪", "自动式狙击枪", "SCOUT轻型狙弹枪", "AWP麦格农狙击枪", "MP5冲锋枪", "灭音冲锋枪"};

/* 商品价格 */
new Handle:CfgNormalItemCost[NORMALITEMMAX];
new Handle:CfgSelectedGunCost[SELECTEDGUNMAX];
new Handle:CfgMeleeCost[SELECTEDMELEEMAX];
new Handle:CfgRobotCost[ROBOTMAX];
/* 音效 */
#define TSOUND			"ui/critical_event_1.wav"
#define EQSOUND		"animation/bombing_run_01.wav"
/* 圈圈颜色 */
//new CyanColor[4] 	= {0, 255, 255, 255};
new CyanColor[4]	={0,146,220,241};
new PurpleColor[4]	= {255, 0, 255, 255};
new RedColor[4]		= {255, 0, 0, 255};
new WhiteColor[4]	= {255, 255, 255, 255};
new BlueColor[4]	= {80, 80, 255, 255};
new YellowColor[4]	= {255, 255, 0, 255};
new ClaretColor[4]	= {255, 0, 0, 255};
new GreenColor[4]		= { 80, 240, 5, 255};

new Handle:gConf = INVALID_HANDLE;
new Handle:fSHS = INVALID_HANDLE;
new Handle:fTOB = INVALID_HANDLE;

#define SOUND_TRACING	"items/suitchargeok1.wav"
#define SOUND_TRACINGMISS	"ambient/weather/thunderstorm/lightning_strike_4.wav"

/* Particle */
#define PARTICLE_EARTHQUAKEEFFECT	"awning_collapse"
#define PARTICLE_INFECTEDSUMMON	"electrical_arc_01_parent"
#define PARTICLE_SCEFFECT	"gen_hit_up"
#define PARTICLE_HLEFFECT	"embers_medium_03"

#define DamageDisplayBuffer 5
#define DamageDisplayLength 64
#define ALIVE 0
#define NORMALDEAD 1
#define HEADSHOT 2
new DamageToTank[MAXPLAYERS+1][MAXPLAYERS+1];
new String:DamageDisplayString[MAXPLAYERS+1][DamageDisplayBuffer][DamageDisplayLength];
new LastDamage[MAXPLAYERS+1];

/************ Robot设置 ************/
#define SOUNDCLIPEMPTY	"weapons/ClipEmpty_Rifle.wav"
#define SOUNDRELOAD		"weapons/shotgun/gunother/shotgun_load_shell_2.wav"
#define SOUNDREADY		"weapons/shotgun/gunother/shotgun_pump_1.wav"

#define WEAPONCOUNT 17

#define SOUND0 "weapons/hunting_rifle/gunfire/hunting_rifle_fire_1.wav"
#define SOUND1 "weapons/rifle/gunfire/rifle_fire_1.wav"
#define SOUND2 "weapons/auto_shotgun/gunfire/auto_shotgun_fire_1.wav"
#define SOUND3 "weapons/shotgun/gunfire/shotgun_fire_1.wav"
#define SOUND4 "weapons/SMG/gunfire/smg_fire_1.wav"
#define SOUND5 "weapons/pistol/gunfire/pistol_fire.wav"
#define SOUND6 "weapons/magnum/gunfire/magnum_shoot.wav"
#define SOUND7 "weapons/rifle_ak47/gunfire/rifle_fire_1.wav"
#define SOUND8 "weapons/rifle_desert/gunfire/rifle_fire_1.wav"
#define SOUND9 "weapons/sg552/gunfire/sg552-1.wav"
#define SOUND10 "weapons/shotgun_chrome/gunfire/shotgun_fire_1.wav"
#define SOUND11 "weapons/auto_shotgun_spas/gunfire/shotgun_fire_1.wav"
#define SOUND12 "weapons/sniper_military/gunfire/sniper_military_fire_1.wav"
#define SOUND13 "weapons/scout/gunfire/scout_fire-1.wav"
#define SOUND14 "weapons/awp/gunfire/awp1.wav"
#define SOUND15 "weapons/mp5navy/gunfire/mp5-1.wav"
#define SOUND16 "weapons/smg_silenced/gunfire/smg_fire_1.wav"

#define MODEL0 "weapon_hunting_rifle"
#define MODEL1 "weapon_rifle"
#define MODEL2 "weapon_autoshotgun"
#define MODEL3 "weapon_pumpshotgun"
#define MODEL4 "weapon_smg"
#define MODEL5 "weapon_pistol"
#define MODEL6 "weapon_pistol_magnum"
#define MODEL7 "weapon_rifle_ak47"
#define MODEL8 "weapon_rifle_desert"
#define MODEL9 "weapon_rifle_sg552"
#define MODEL10 "weapon_shotgun_chrome"
#define MODEL11 "weapon_shotgun_spas"
#define MODEL12 "weapon_sniper_military"
#define MODEL13 "weapon_sniper_scout"
#define MODEL14 "weapon_sniper_awp"
#define MODEL15 "weapon_smg_mp5"
#define MODEL16 "weapon_smg_silenced"

/* Particle */
#define PARTICLE_BLOOD	"blood_impact_infected_01"

new String:SOUND[WEAPONCOUNT+3][70]=
{SOUND0, SOUND1, SOUND2, SOUND3, SOUND4, SOUND5, SOUND6, SOUND7,SOUND8,SOUND9, SOUND10, SOUND11,SOUND12,SOUND13,SOUND14, SOUND15,SOUND16,SOUNDCLIPEMPTY, SOUNDRELOAD, SOUNDREADY};

new String:MODEL[WEAPONCOUNT][32]=
{MODEL0, MODEL1, MODEL2, MODEL3, MODEL4, MODEL5,MODEL6, MODEL7,MODEL8,MODEL9,MODEL10, MODEL11, MODEL12 ,MODEL13,MODEL14, MODEL15, MODEL16};

new Float:fireinterval[WEAPONCOUNT]={0.25, 0.068, 0.30, 0.65, 0.060, 0.20, 0.33, 0.145, 0.14, 0.064, 0.65, 0.30, 0.265, 0.9, 1.25, 0.065, 0.055};
new Float:bulletaccuracy[WEAPONCOUNT]={1.15, 1.4, 3.5, 3.5, 1.6, 1.7 , 1.7, 1.5, 1.6, 1.5, 3.5, 3.5, 1.15, 1.00, 0.8, 1.6 ,1.6};
new Float:weaponbulletdamage[WEAPONCOUNT]={90.0, 30.0, 25.0, 30.0, 20.0, 30.0, 60.0, 70.0, 40.0, 40.0, 30.0, 30.0, 90.0, 100.0, 150.0, 35.0, 35.0};
new weaponclipsize[WEAPONCOUNT]={15, 50, 10, 8, 50, 30, 8, 40, 20, 50, 8, 10, 30, 15, 20, 50, 50};
new weaponbulletpershot[WEAPONCOUNT]={1, 1, 7, 7, 1, 1, 1, 1, 1, 1, 7, 7,1, 1, 1,1,1};
new Float:weaponloadtime[WEAPONCOUNT]={2.0, 1.5, 0.3, 0.3, 1.5, 1.5, 1.9, 1.5, 1.5, 1.6, 0.3, 0.3, 2.0,2.0, 2.0, 1.5, 1.5};
new weaponloadcount[WEAPONCOUNT]={15, 50, 1,1, 50, 30, 8, 40, 60, 50, 1, 1, 30, 15, 20, 50, 50};
new bool:weaponloaddisrupt[WEAPONCOUNT]={false,false, true, true,false,false, false, false, false, true, true, false, false, false, false, false};

new robot[MAXPLAYERS+1];
new robot_clone[MAXPLAYERS+1];
new keybuffer[MAXPLAYERS+1];
new keybuffer_clone[MAXPLAYERS+1];
new weapontype[MAXPLAYERS+1];
new bullet[MAXPLAYERS+1];
new bullet_clone[MAXPLAYERS+1];
new Float:firetime[MAXPLAYERS+1];
new Float:firetime_clone[MAXPLAYERS+1];
new bool:reloading[MAXPLAYERS+1];
new bool:reloading_clone[MAXPLAYERS+1];
new Float:reloadtime[MAXPLAYERS+1];
new Float:reloadtime_clone[MAXPLAYERS+1];
new Float:scantime[MAXPLAYERS+1];
new Float:scantime_clone[MAXPLAYERS+1];
new Float:walktime[MAXPLAYERS+1];
new Float:walktime_clone[MAXPLAYERS+1];
new Float:botenerge[MAXPLAYERS+1];
new Float:botenerge_clone[MAXPLAYERS+1];

new SIenemy[MAXPLAYERS+1];
new CIenemy[MAXPLAYERS+1];

new SIenemy_clone[MAXPLAYERS+1];
new CIenemy_clone[MAXPLAYERS+1];

new Float:robotangle[MAXPLAYERS+1][3];	//机器人角度

new Handle:RobotReactiontime = INVALID_HANDLE;
new Handle:RobotEnergy = INVALID_HANDLE;		//机器人能量
new Handle:CfgRobotUpgradeCost[3] = INVALID_HANDLE;

new Float:robot_reactiontime;
new Float:robot_energy;

new bool:robot_gamestart = false;
new bool:robot_gamestart_clone = false;

new RobotCount[MAXPLAYERS+1];

/* 感染者CLASS */
#define CLASS_SMOKER		1
#define CLASS_BOOMER		2
#define CLASS_HUNTER		3
#define CLASS_SPITTER	4
#define CLASS_JOCKEY		5
#define CLASS_CHARGER	6
#define CLASS_WITCH		7
#define CLASS_TANK		8

#define ENTITY_GASCAN	"models/props_junk/gascan001a.mdl"
#define ENTITY_PROPANE	"models/props_junk/propanecanister001a.mdl"

/* 超级坦克类型 */
#define TANK1		1
#define TANK2		2
#define TANK3		3
#define TANK4		4
#define TANK5		5
#define TANK6		6

#define MOLOTOV 		0
#define EXPLODE 		1

#define MODEL_DLCTANK	"models/infected/hulk_dlc3.mdl"
#define MODEL_TANK	"models/infected/hulk.mdl"

/* 超级坦克音效 */
#define SOUND_EXPLODE	"animation/bombing_run_01.wav"
#define SOUND_SPAWN		"music/pzattack/contusion.wav"
#define SOUND_BCLAW		"weapons/grenade_launcher/grenadefire/grenade_launcher_explode_1.wav"
#define SOUND_GCLAW		"plats/churchbell_end.wav"
#define SOUND_DCLAW		"ambient/random_amb_sounds/randbridgegroan_03.wav"
#define SOUND_QUAKE		"player/charger/hit/charger_smash_02.wav"
#define SOUND_STEEL		"physics/metal/metal_solid_impact_hard5.wav"
#define SOUND_CHANGE	"items/suitchargeok1.wav"
#define SOUND_HOWL		"player/tank/voice/pain/tank_fire_08.wav"
#define SOUND_WARP		"ambient/energy/zap9.wav"
#define SOUND_ABS			"level/coaster_loop03.wav"

/* 超级坦克粒子特效 */
#define PARTICLE_SPAWN	"electrical_arc_01_system"
#define PARTICLE_DEATH	"gas_explosion_main"
#define PARTICLE_THIRD	"apc_wheel_smoke1"
#define PARTICLE_FORTH	"aircraft_destroy_fastFireTrail"
#define PARTICLE_WARP	"water_splash"

new bool:IsRoundEnded;

new Handle:SpawnTimer    		= INVALID_HANDLE;
new Handle:CheckTimer    		= INVALID_HANDLE;

/* Timers设置 */
new Handle:ZombiesKillCountTimer[MAXPLAYERS+1]			= {	INVALID_HANDLE, ...};
new Handle:CheckExpTimer[MAXPLAYERS+1]					= {	INVALID_HANDLE, ...};
new Handle:HealingTimer[MAXPLAYERS+1]					= {	INVALID_HANDLE, ...};
new Handle:HealingkbTimer[MAXPLAYERS+1]					= {	INVALID_HANDLE, ...};
new Handle:HealingwxTimer[MAXPLAYERS+1]					= {	INVALID_HANDLE, ...};
new Handle:HealinggbdTimer[MAXPLAYERS+1]					= {	INVALID_HANDLE, ...};
new Handle:SprinDurationTimer[MAXPLAYERS+1]				= {	INVALID_HANDLE, ...};
new Handle:InfiniteAmmoDurationTimer[MAXPLAYERS+1]		= {	INVALID_HANDLE, ...};
new Handle:BioShieldDurationTimer[MAXPLAYERS+1]			= {	INVALID_HANDLE, ...};
new Handle:BioShieldCDTimer[MAXPLAYERS+1]				= {	INVALID_HANDLE, ...};
new Handle:BioShieldmissDurationTimer[MAXPLAYERS+1]			= {	INVALID_HANDLE, ...};
new Handle:BioShieldmissCDTimer[MAXPLAYERS+1]				= {	INVALID_HANDLE, ...};
new Handle:BioShieldkbDurationTimer[MAXPLAYERS+1]			= {	INVALID_HANDLE, ...};
new Handle:BioShieldkbCDTimer[MAXPLAYERS+1]				= {	INVALID_HANDLE, ...};
new Handle:DamageReflectDurationTimer[MAXPLAYERS+1]		= {	INVALID_HANDLE, ...};
new Handle:MeleeSpeedDurationTimer[MAXPLAYERS+1]		= {	INVALID_HANDLE, ...};
new Handle:FadeBlackTimer[MAXPLAYERS+1]					= {	INVALID_HANDLE, ...};
new Handle:TCChargingTimer[MAXPLAYERS+1]				= {	INVALID_HANDLE, ...};
new Handle:TTChargingTimer[MAXPLAYERS+1]				= {	INVALID_HANDLE, ...};
new Handle:TTChargingztTimer[MAXPLAYERS+1]				= {	INVALID_HANDLE, ...};
new Handle:SatelliteCannonCDTimer[MAXPLAYERS+1]			= {	INVALID_HANDLE, ...};
new Handle:SatelliteCannonmissCDTimer[MAXPLAYERS+1]			= {	INVALID_HANDLE, ...};
new Handle:DamageDisplayCleanTimer[MAXPLAYERS+1]		= {	INVALID_HANDLE, ...};
new Handle:WXNYDurationTimer[MAXPLAYERS+1]		= {	INVALID_HANDLE, ...};
new Handle:SWHTDurationTimer[MAXPLAYERS+1]			= {	INVALID_HANDLE, ...};
new Handle:SWHTCDTimer[MAXPLAYERS+1]				= {	INVALID_HANDLE, ...};
new Handle:GZSDurationTimer[MAXPLAYERS+1]				= {	INVALID_HANDLE, ...};
new Handle:YLTJmissCDTimer[MAXPLAYERS+1]			= {	INVALID_HANDLE, ...};
new Handle:DSZGmissCDTimer[MAXPLAYERS+1]			= {	INVALID_HANDLE, ...};
new Handle:WZZGmissCDTimer[MAXPLAYERS+1]			= {	INVALID_HANDLE, ...};
new Handle:PHABADurationTimer[MAXPLAYERS+1]				= {	INVALID_HANDLE, ...};
new Handle:PHFRADurationTimer[MAXPLAYERS+1]			= {	INVALID_HANDLE, ...};
new Handle:PHFRACDTimer[MAXPLAYERS+1]				= {	INVALID_HANDLE, ...};
new Handle:XJTimer[MAXPLAYERS+1]					= {	INVALID_HANDLE, ...};
new Handle:XJDurationTimer[MAXPLAYERS+1]			= {	INVALID_HANDLE, ...};
new Handle:XJCDTimer[MAXPLAYERS+1]				= {	INVALID_HANDLE, ...};
new Handle:LLLEmissCDTimer[MAXPLAYERS+1]			= {	INVALID_HANDLE, ...};
new Handle:HYJWDurationTimer[MAXPLAYERS+1]		= {	INVALID_HANDLE, ...};
new Handle:XZKBTimer[MAXPLAYERS+1]					= {	INVALID_HANDLE, ...};
new Handle:XZKBDurationTimer[MAXPLAYERS+1]			= {	INVALID_HANDLE, ...};
new Handle:XZKBCDTimer[MAXPLAYERS+1]				= {	INVALID_HANDLE, ...};



/* Sprite */
#define SPRITE_BEAM		"materials/sprites/laserbeam.vmt"
#define SPRITE_HALO		"materials/sprites/halo01.vmt"
#define SPRITE_GLOW		"materials/sprites/glow01.vmt"

new g_BeamSprite;
new g_HaloSprite;
new g_GlowSprite;

#define LASERMODE_NORMAL	0
#define LASERMODE_VARTICAL	1

new String:LogPath[256];

//不输入密码超时计算参数
new pwtimeout[MAXPLAYERS+1];
new Handle:cv_pwtimeout;
//加载地图卡住计算参数
new connectkicktime[MAXPLAYERS+1];
new Handle:cv_loadtimeout;
//MP恢复药水价格
new Handle:ResumeMP;
//人数上限
new Handle:cv_survivor_limit;
new Handle:cv_infected_limit;
//VIP经验金钱加成参数
new Handle:cv_vipexp;
new Handle:cv_vipcash;
new Handle:cv_vipbuy;
new Handle:cv_vippropsA;
new Handle:cv_vippropsB;
new Handle:cv_vippropsC;
new Handle:cv_vippropsD;
new Handle:cv_vippropsE;
new Handle:cv_vippropsF;
//VIP免费补给
new vip_item[MAXPLAYERS+1];
//首次注册赠送金钱
new Handle:cv_firtsreg;
//VIP名字保存
new String:VipName[MAXPLAYERS+1][MAX_NAME_LENGTH];
/* 医生防刷电击 */
new String:DoctorName[MAXPLAYERS+1][MAX_NAME_LENGTH];
/* 审判者防刷生命之书 */
new String:SPZName[MAXPLAYERS+1][MAX_NAME_LENGTH];
//禁止改名
new String:PlayerName[MAXPLAYERS+1][MAX_NAME_LENGTH];

#define CRIT_SOUND "weapons/grenade_launcher/grenadefire/grenade_launcher_explode_1.wav" //暴击音效

/** 超级坦克参数 **/
//难度平衡参数
new Handle:rpg_gamedifficulty	 			= INVALID_HANDLE;

//by MicroLeo
new Handle:rpg_gamedifficulty_tankHP_lv1	= INVALID_HANDLE;
new Handle:rpg_gamedifficulty_tankHP_lv2	= INVALID_HANDLE;
new Handle:rpg_gamedifficulty_tankHP_lv3	= INVALID_HANDLE;
new Handle:rpg_gamedifficulty_tankHP_lv4	= INVALID_HANDLE;
new Handle:rpg_gamedifficulty_tankHP_lv5	= INVALID_HANDLE;
new Handle:rpg_gamedifficulty_tankHP_lv6	= INVALID_HANDLE;
new Handle:rpg_gamedifficulty_tankHP_lv7	= INVALID_HANDLE;
//end

//紫炎坦克出现几率
new Handle:sm_supertank_bossratio	 		= INVALID_HANDLE;
new Handle:sm_supertank_bossrange	 		= INVALID_HANDLE;

//紫炎坦克出现几率
new Handle:sm_supertank_Killerratio	 		= INVALID_HANDLE;
//new Handle:sm_supertank_Killerrange	 	= INVALID_HANDLE;

//超级坦克生命值
new Handle:sm_supertank_health_max	 		= INVALID_HANDLE;
new Handle:sm_supertank_health_second 		= INVALID_HANDLE;
new Handle:sm_supertank_health_third	 	= INVALID_HANDLE;
new Handle:sm_supertank_health_forth	 	= INVALID_HANDLE;
new Handle:sm_supertank_health_boss	 	    = INVALID_HANDLE;
new Handle:sm_supertank_health_Killer	 	= INVALID_HANDLE;
new SuperTank_Health[7];
new Float:SuperTank_Warp;

//超级坦克生颜色
new Handle:sm_supertank_color_first 	 	= INVALID_HANDLE;
new Handle:sm_supertank_color_second	 	= INVALID_HANDLE;
new Handle:sm_supertank_color_third 	 	= INVALID_HANDLE;
new Handle:sm_supertank_color_forth		= INVALID_HANDLE;
new Handle:sm_supertank_color_boss			= INVALID_HANDLE;
new Handle:sm_supertank_color_Killer		= INVALID_HANDLE;

//玩家装备颜色
/*
new Handle:sm_playerequipment_color_SQ					= INVALID_HANDLE;
new Handle:sm_playerequipment_color_CQ					= INVALID_HANDLE;
new Handle:sm_playerequipment_color_GH					= INVALID_HANDLE;
new Handle:sm_playerequipment_color_TZ					= INVALID_HANDLE;
new Handle:sm_playerequipment_color_XQ					= INVALID_HANDLE;
new Handle:sm_playerequipment_color_DY					= INVALID_HANDLE;
new Handle:sm_playerequipment_color_TT					= INVALID_HANDLE;
new Handle:sm_playerequipment_color_SW					= INVALID_HANDLE;
new Handle:sm_playerequipment_color_LD					= INVALID_HANDLE;
new Handle:sm_playerequipment_color_AQ					= INVALID_HANDLE;
*/

//超级坦克速度
new Handle:sm_supertank_speed[7] 	 		= INVALID_HANDLE;

//超级坦克护甲
new Handle:sm_supertank_armor_tank[7]		= INVALID_HANDLE;

//超级坦克技能参数
//new Handle:sm_supertank_weight_second		= INVALID_HANDLE;
//new Handle:sm_supertank_stealth_third 	= INVALID_HANDLE;
new Handle:sm_supertank_gravityinterval 	= INVALID_HANDLE;
new Handle:sm_supertank_quake_radius 		= INVALID_HANDLE;
new Handle:sm_supertank_quake_force	    	= INVALID_HANDLE;
new Handle:sm_supertank_dreadinterval 		= INVALID_HANDLE;
new Handle:sm_supertank_dreadrate	 		= INVALID_HANDLE;
new Handle:sm_supertank_warp_interval		= INVALID_HANDLE;
new Handle:sm_supertank_quake_radiusz 		= INVALID_HANDLE;
new Handle:sm_supertank_quake_forcez	 	= INVALID_HANDLE;
//超级坦克吸星大法
new Handle:sm_supertank_xixing_range	 	= INVALID_HANDLE;
new Handle:sm_supertank_xixing_interval  	= INVALID_HANDLE;
new Handle:sm_supertank_xixing_abs			= INVALID_HANDLE;
new Handle:sm_supertank_xixing_dread		= INVALID_HANDLE;
new Handle:sm_supertank_xixing_slowspeed	= INVALID_HANDLE;
new Handle:sm_supertank_xixing_slowtime 	= INVALID_HANDLE;

//超级坦克平衡
new Handle:sm_supertank_tankbalance 		= INVALID_HANDLE;

//超级坦克抵消伤害总值
new TankOffsetDmg[MAXPLAYERS+1][MAXPLAYERS+1];

//坦克伤害抵消几率
new Float:TankOffsetRadio;

/* Timer Handle */
new Handle:TimerUpdate[MAXPLAYERS+1] = INVALID_HANDLE;

/* Grobal */
new alpharate[MAXPLAYERS+1];
new visibility[MAXPLAYERS+1];
new tanktype[MAXPLAYERS+1];

/* 吸星大法 */
new Xixing[MAXPLAYERS+1];
new Float:PlayerSpeed[MAXPLAYERS+1];

//瞬移计时器
new Handle:Timer_FatalMirror[MAXPLAYERS+1];

//武器classname
new String:t_Gun[17][64] = { "weapon_autoshotgun", "weapon_grenade_launcher", "weapon_hunting_rifle", "weapon_pumpshotgun", "weapon_rifle", "weapon_rifle_ak47", "weapon_rifle_desert", "weapon_rifle_m60", "weapon_rifle_sg552", "weapon_shotgun_chrome", "weapon_shotgun_spas", "weapon_smg", "weapon_smg_mp5", "weapon_smg_silenced", "weapon_sniper_awp", "weapon_sniper_military", "weapon_sniper_scout"};
new String:t_Bomb[3][64] = { "weapon_molotov", "weapon_pipe_bomb", "weapon_vomitjar" };
new String:t_Medic[4][64] = { "weapon_adrenaline", "weapon_defibrillator", "weapon_first_aid_kit", "weapon_pain_pills" };
//new String:t_Other[3][64] = { "upgrade_ammo_explosive", "upgrade_ammo_incendiary" , "weapon_ammo_spawn" };
//new String:t_Melee[12][64] = { "baseball_bat", "cricket_bat" , "crowbar", "electric_guitar", "fireaxe", "frying_pan", "katana", "machete", "tonfa", "knife", "riotshield", "golfclub" };

//商店武器变量
new String:GunName[SELECTEDGUNMAX][]={ "MP5冲锋枪","Scout轻型狙击枪", "AWP重型狙击枪","SG552突击步枪","M60机枪","榴弹发射器", "AK47", "战斗散弹枪", "M16"};
new String:GunCode[SELECTEDGUNMAX][]={ "rifle_desert", "shotgun_chrome", "autoshotgun", "smg_silenced", "rifle_m60", "grenade_launcher", "rifle_ak47", "shotgun_spas", "rifle"};

new String:MeleeName[SELECTEDMELEEMAX][]={ "棒球棍", "板球棍", "铁撬", "电吉他", "斧头", "平底锅", "高尔夫球棍", "武士刀", "海豹匕首", "斩马刀", "盾牌", "警棍", "电锯"};
new String:MeleeCode[SELECTEDMELEEMAX][]={ "baseball_bat", "cricket_bat", "crowbar", "electric_guitar", "fireaxe", "frying_pan", "golfclub", "katana", "hunting_knife", "machete", "riotshield", "tonfa", "chainsaw"};

new String:NormalItemName[NORMALITEMMAX][]={ "子弹", "红外线", "高爆弹", "燃烧弹", "药包", "药丸", "肾上腺素", "电击器", "燃烧瓶", "土制炸弹","胆汁", "高爆子弹盒", "燃烧子弹盒"};

/* Robot工场*/
new String:RobotUpgradeName[3][]={ "提升攻击力(目前等级: %d/%d, 所需费用: %d)", "提升弹匣系统(目前等级: %d/%d, 所需费用: %d)", "提升侦察距离(目前等级: %d/%d, 所需费用: %d)"};
new String:RobotUpgradeInfo[3][]={ "目前攻击力系数: %.2f", "目前弹匣量系数: %.2f", "目前侦察距离: %d"};
new RobotUpgradeLimit[3]={50, 50, 20};
//#define RobotAttackEffect[%1]	0.2 + 0.025*RobotUpgradeLv[%1][0]
#define RobotAttackEffect[%1]	      Str[%1] * 0.0025 + 1 * ZB_GunDmg[%1] + NewLifeCount[%1] * 15
#define RobotAmmoEffect[%1]		            1.5 + 0.1*RobotUpgradeLv[%1][1]
#define RobotRangeEffect[%1]	            500 + 25*RobotUpgradeLv[%1][2]

//Robot变量
new Float:lasttime=0.0;
new button;
new Float:robotpos[3];
new Float:robotpos_clone[3];
new Float:robotvec[3];
new Float:robotvec_clone[3];
new Float:Clienteyepos[3];
new Float:Clientangle[3];
new Float:enemypos[3];
new Float:infectedorigin[3];
new Float:infectedeyepos[3];
new Float:chargetime;
new Float:chargetime_clone;

//旁观计时踢出
new KickLookOnPlayer[MAXPLAYERS+1];

//服务器最大人数
new Handle:cv_MaxPlayer;
new ServerPlayerLimit;

//普感生命值
new oldCommonHp;

//VIP设置变量
new viptarget;
new viptype;

//枪械伤害 武器伤害
#define DMG_AK47			60
#define DMG_M60				60
#define DMG_M16				60
#define DMG_MP5				60
#define DMG_SPAS			30
#define DMG_CHROME			30
#define DMG_AUTOSHOTGUN		30
#define DMG_PUMPSHOTGUN		30
#define DMG_HUNTING		    5	//一代连狙
#define DMG_SCOUT			5	//斯太尔轻型狙击枪
#define DMG_AWP				30
#define DMG_GL				20
#define DMG_SMG				30
#define DMG_SMG_S			20
#define DMG_MAGNUM			30


#define NAME_AK47				"rifle_ak47"
#define NAME_M60				"rifle_m60"
#define NAME_M16				"rifle"
#define NAME_MP5				"smg_mp5"
#define NAME_SPAS				"shotgun_spas"
#define NAME_CHROME			"shotgun_chrome"
#define NAME_AUTOSHOTGUN		"autoshotgun"
#define NAME_PUMPSHOTGUN		"pumpshotgun"
#define NAME_HUNTING			"hunting_rifle"
#define NAME_SCOUT			"sniper_scout"
#define NAME_AWP				"sniper_awp"
#define NAME_GL				"grenade_launcher"
#define NAME_SMG				"smg"
#define NAME_SMG_S			"smg_silenced"
#define NAME_MAGNUM			"pistol_magnum"
/*
枪械说明
 pistol_magnum|玛格南手枪
 autoshotgun|1代的连发霰弹枪
 shotgun_spas|2代的连发霰弹枪
 pumpshotgun|1代的单发霰弹枪
 shotgun_chrome|2代的单发霰弹枪
 hunting_rifle|1代的连狙
 sniper_military|2代的连狙
 rifle|M16突击步枪
 rifle_m60|M60突击步枪
 rifle_ak47|AK-47突击步枪
 rifle_desert|SCAR突击步枪(三连发)
 smg|轻型冲锋枪
 smg_silenced|消音轻型冲锋枪
 pistol|手枪
 weapon_grenade_launcher|榴弹发射器
 weapon_sniper_awp|麦格农重型狙击枪
 weapon_sniper_scout|斯太尔轻型狙击枪
 weapon_smg_mp5|MP5冲锋枪
 weapon_rifle_sg552|SIG SG552突击步枪
 */






//加密文件
/*
new Handle:PW_File;
new String:PW_Path[256];
new String:PW_Data[256];
*/

/* 回合坦克数量控制 */
new RoundTankLimit = 10;
new RoundTankNum = 0;

/* 大乐透 */
#define	DLT_MaxNum		24

new DLTNum[MAXPLAYERS+1];
new DLTCash[34];
new Float:DLT_Timer;
new Handle:DLT_Handle = INVALID_HANDLE;

/* 玩家轮廓状态 */
new PlayerGlowType[MAXPLAYERS+1];

#define NewLifeSKP[%1]		(NewLifeCount[%1] + 1) * 100
#define NewLifeSP[%1]		(NewLifeCount[%1] + 1) * 10
#define NewLifeGiveSKP[%1]		NewLifeCount[%1] * 100
#define NewLifeGiveSP[%1]		NewLifeCount[%1] * 10


/* 新人保护变量 */
//玩家总等级高于多少给予新人BUFF
#define RookieBuff_MaxLv		0
//低于多少级给予新人BUFF
#define RookieBuff_MinLv		100
//新人BUFF增加血量
#define RookieBuff_Health	500
//新人BUFF增加移动速度
#define RookieBuff_Speed		0.3
//保存已有BUFF玩家
new bool:HasBuffPlayer[MAXPLAYERS+1];

/* 每日签到 */
#define SIGNAWARD_EXP[%1]		400 + 100 * Lv[%1]
#define SIGNAWARD_CASH[%1]		200 + 10 * Lv[%1]
#define SIGNAWARD_VIPEXP[%1]		400 + 1000 * Lv[%1]
#define SIGNAWARD_VIPCASH[%1]		200 + 100 * Lv[%1]

new EveryDaySign[MAXPLAYERS+1];

new String:BotCheck[MAXPLAYERS+1][32];

new String:ServerTimePath[256];

/* 运行时间检测 */
#define RUNTIME_SEC	0
#define RUNTIME_MIN	1
new Handle:HD_ServerRuningTime;
new ServerRuningTime[2];



/*** 天赋 ****/
new MSTF[MAXPLAYERS+1];
new tgyj[MAXPLAYERS+1];
new DJYX[MAXPLAYERS+1];
new xstf[MAXPLAYERS+1];
new sxtf[MAXPLAYERS+1];
new NHYS[MAXPLAYERS+1];
new KBYS[MAXPLAYERS+1];
new ZHONGHUO[MAXPLAYERS+1];
new JIDONG[MAXPLAYERS+1];





/**********************
*	 玩家基本数据
**********************/
new ID[MAXPLAYERS+1];
new Lv[MAXPLAYERS+1];
new EXP[MAXPLAYERS+1];
new Cash[MAXPLAYERS+1];
new KTCount[MAXPLAYERS+1];	//误杀队友统计
new NewLifeCount[MAXPLAYERS+0];	//转生次数
new String:Password[MAXPLAYERS+1][64];
/**********************
*	 玩家背包数据
**********************/
new I_Bag[MAXPLAYERS+1][5][10];
new I_BagSize[MAXPLAYERS+1];
/**********************
*	 玩家属性
**********************/
new VIP[MAXPLAYERS+1];
new VIPTL[MAXPLAYERS+1];
new VIPYEAR[MAXPLAYERS+1];
new Str[MAXPLAYERS+1];
new Agi[MAXPLAYERS+1];
new Health[MAXPLAYERS+1];
new Endurance[MAXPLAYERS+1];
new Intelligence[MAXPLAYERS+1];
new SkillPoint[MAXPLAYERS+1];
new StatusPoint[MAXPLAYERS+1];
new Crits[MAXPLAYERS+1];
new CritMin[MAXPLAYERS+1];
new CritMax[MAXPLAYERS+1];
//强化系统
new Qhs[MAXPLAYERS+1];
new M16[MAXPLAYERS+1];
new AK47[MAXPLAYERS+1];
new PZ[MAXPLAYERS+1];
new AWP[MAXPLAYERS+1];
new M60[MAXPLAYERS+1];
new GZ[MAXPLAYERS+1]
new BSXY[MAXPLAYERS+1]
new Sxcs[MAXPLAYERS+1]
new XB[MAXPLAYERS+1]; //玄币
new XC[MAXPLAYERS+1]; //玄券
new Lyxz[MAXPLAYERS+1]; //烈焰勋章
new Libao[MAXPLAYERS+1]; //升级礼包
/*新增升级礼包防刷BUG*/
new LibaoLv[MAXPLAYERS+1];	//升级礼包等级变量
/*新增枪神附体*/
new Robot_appendage[MAXPLAYERS+1];
//VIP体验时间
new VIPTYOVER[MAXPLAYERS+1];
/*** 任务系统 ****/
new Eqbox[MAXPLAYERS+1]; //炎神宝盒
new SMHZ[MAXPLAYERS+1]; //神秘盒子
new Renwu[MAXPLAYERS+1];
new Jenwu[MAXPLAYERS+1];
new Pugan[MAXPLAYERS+1]; //普感
new Tegan[MAXPLAYERS+1]; //特感
new TYangui[MAXPLAYERS+1]; //烟鬼
new TPangzi[MAXPLAYERS+1]; //胖子
new TLieshou[MAXPLAYERS+1]; //猎手
new TKoushui[MAXPLAYERS+1]; //口水
new THouzhi[MAXPLAYERS+1]; //猴子
new TXiaoniu[MAXPLAYERS+1]; //小牛
new TDaxinxin[MAXPLAYERS+1]; //tank
new FHCS[MAXPLAYERS+1]; //复活队友的次数
new LQDY[MAXPLAYERS+1]; //拉起队友次数
new YLDY[MAXPLAYERS+1]; //医疗队友次数
new DDCS[MAXPLAYERS+1]; //倒地次数

new Lis[MAXPLAYERS+1]; //力量
new LisA[MAXPLAYERS+1]; //天使
new LisB[MAXPLAYERS+1]; //恶魔
new LisC[MAXPLAYERS+1]; //地狱
new LisD[MAXPLAYERS+1]; //圣灵

new JLXT1[MAXPLAYERS+1]; //转回[龙魂]
new JLXT2[MAXPLAYERS+1]; //时空[龙魂]
new JLXT3[MAXPLAYERS+1]; //机器[龙魂]
new JLXT4[MAXPLAYERS+1]; //体力药水
new JLXT5[MAXPLAYERS+1]; //转回[龙魂]龙魂体力
new JLXT6[MAXPLAYERS+1]; //机器[龙魂]龙魂体力
new JLXT7[MAXPLAYERS+1]; //时空[龙魂]龙魂体力


//连续签到
new everyday1[MAXPLAYERS+1];
//魔法宝石
new MFBS1[MAXPLAYERS+1]; //初级经验宝石
new MFBS2[MAXPLAYERS+1]; //中等经验宝石
new MFBS3[MAXPLAYERS+1]; //高级经验宝石
new MFBS4[MAXPLAYERS+1]; //极品经验宝石
new MFBS5[MAXPLAYERS+1]; //VIP专用经验宝石
new MFBS6[MAXPLAYERS+1]; //装备合成宝石
new MFBS7[MAXPLAYERS+1]; //生命碎片


//合成材料
new ACL[MAXPLAYERS+1]; //套装碎片A
new SCL[MAXPLAYERS+1]; //套装碎片S
new BCL[MAXPLAYERS+1]; //套装碎片B

new BSZG[MAXPLAYERS+1]; //BOSS之光

//主线任务
new TANKSL[MAXPLAYERS+1];
new JRCS[MAXPLAYERS+1];
new PTJS[MAXPLAYERS+1];
new LRCS[MAXPLAYERS+1];
new ZXRW[MAXPLAYERS+1];
new KSZXRW[MAXPLAYERS+1];

new BSD[MAXPLAYERS+1]; //不删档道具
new TSBS[MAXPLAYERS+1]; //逃生匕首

//荣誉称号
new BJCH[MAXPLAYERS+1]; //称号显示
new TKSL[MAXPLAYERS+1];
new XGSL[MAXPLAYERS+1];
new HZSL[MAXPLAYERS+1];
new PPSL[MAXPLAYERS+1];
new PZSL[MAXPLAYERS+1];
new DXSL[MAXPLAYERS+1];
new NWSL[MAXPLAYERS+1];
new DRSL[MAXPLAYERS+1];
new BRSL[MAXPLAYERS+1];
new YGSL[MAXPLAYERS+1];
new QHSL[MAXPLAYERS+1];
//这里是装备称号的变量
new TKSLZ[MAXPLAYERS+1];//坦克杀手
new XGSLZ[MAXPLAYERS+1];//僵尸猎手
new HZSLZ[MAXPLAYERS+1];//拒绝乘骑
new PPSLZ[MAXPLAYERS+1];//文明者
new PZSLZ[MAXPLAYERS+1];//瘦身教练
new DXSLZ[MAXPLAYERS+1]; //执法者
new NWSLZ[MAXPLAYERS+1]; //哭泣杀手
new DRSLZ[MAXPLAYERS+1]; //救助者
new BRSLZ[MAXPLAYERS+1]; //好队友
new QHHSZ[MAXPLAYERS+1];  //强化好手
new BZBNZ[MAXPLAYERS+1];  //百折不挠
new YGSLZ[MAXPLAYERS+1];  //拒绝吸烟
//地狱模式
new TZZS[MAXPLAYERS+1]//地狱之匙
new TZMS[MAXPLAYERS+1]//地狱模式
new TZME[MAXPLAYERS+1]//坦克
new TZMC[MAXPLAYERS+1]//坦克模式
new TZMO[MAXPLAYERS+1]//透明模式


/**********************
*	 幸存者通用技能
**********************/
/** 治疗术 **/
new HealingLv[MAXPLAYERS+1];
/** 地震 **/
new EarthQuakeLv[MAXPLAYERS+1];
/** 重机枪 **/
new GELINLv[MAXPLAYERS+1];
/** 强化苏醒术 **/
new EndranceQualityLv[MAXPLAYERS+1];
/*** 职业基本资料 ***/
new JD[MAXPLAYERS+1] = {0, ...};

/**********************
*	 工程师
**********************/
/* 轨道炮 */
new SatelliteCannonLv[MAXPLAYERS+1];
/* 制造子弹 */
new AmmoMakingLv[MAXPLAYERS+1];
/* 超级射速 */
new FireSpeedLv[MAXPLAYERS+1];

/**********************
*	 士兵
**********************/
/* 钢铁之躯 */
new EnergyEnhanceLv[MAXPLAYERS+1];
/* 疾风步 */
new SprintLv[MAXPLAYERS+1];
/* 无限弹药 */
new InfiniteAmmoLv[MAXPLAYERS+1];
/* 炎之暴走 */
new BioShieldkbLv[MAXPLAYERS+1];

/**********************
*	 狂战士
**********************/
/* 霸体 */
new BioShieldLv[MAXPLAYERS+1];
/* 复仇反击 */
new DamageReflectLv[MAXPLAYERS+1];
/* 近战乱舞 */
new MeleeSpeedLv[MAXPLAYERS+1];
/* 基因改造 */
new GeneLv[MAXPLAYERS+1];
/* 狂暴嗜血 */
new BioShieldmissLv[MAXPLAYERS+1];


/**********************
*	 圣疗者
**********************/
/* 支援传送 */
new TeleportToSelectLv[MAXPLAYERS+1];
/* 审判光球术 */
new HolyBoltLv[MAXPLAYERS+1];
/* 心灵传送术 */
new TeleportTeamLv[MAXPLAYERS+1];
new defibrillator[MAXPLAYERS+1];
/* 治疗光球术 */
new HealingBallLv[MAXPLAYERS+1];
/* 吸引术 */
new TeleportTeamztLv[MAXPLAYERS+1];

/**********************
*	 魔法师
**********************/
/* 爆破 */
new FireBallLv[MAXPLAYERS+1];
/* 冰封 */
new IceBallLv[MAXPLAYERS+1];
/* 连锁闪电术 */
new ChainLightningLv[MAXPLAYERS+1];
/* 究极雷霆 */
new SatelliteCannonmissLv[MAXPLAYERS+1];

/**********************
*	弹药师
**********************/
//破碎弹
new BrokenAmmoLv[MAXPLAYERS+1];
//渗毒弹
new PoisonAmmoLv[MAXPLAYERS+1];
//吸血弹
new SuckBloodAmmoLv[MAXPLAYERS+1];
//区域爆破
new AreaBlastingLv[MAXPLAYERS+1];
//镭射激光炮
new LaserGunLv[MAXPLAYERS+1];

/**********************
*	地狱勾魂使者
**********************/
//魂魄
new Hunpo[MAXPLAYERS+1];
//勾魂之力
new GouhunLv[MAXPLAYERS+1];
//灵力上限
new LinliLv[MAXPLAYERS+1];
//审判领域
new AreaBlastingexLv[MAXPLAYERS+1];

/**********************
*	死神
**********************/
//死神之力
new SszlLv[MAXPLAYERS+1];
//暗影能量
new AynlLv[MAXPLAYERS+1];
//大地之怒
new DyzhLv[MAXPLAYERS+1];

/**********************
*	黑暗行者
**********************/
//黑暗射速
new HassLv[MAXPLAYERS+1];
//子弹工程
new ZdgcLv[MAXPLAYERS+1];
//超强地震
new CqdzLv[MAXPLAYERS+1];

/**********************
*	死亡祭师
**********************/
//死亡护体
new SWHTLv[MAXPLAYERS+1];
//无限能源
new WXNYLv[MAXPLAYERS+1];
//死亡改造
new SWGZLv[MAXPLAYERS+1];

/**********************
*	雷电使者
**********************/
//雷电子
new LDZLv[MAXPLAYERS+1];
//光之速
new GZSLv[MAXPLAYERS+1];
//引雷天降
new YLTJLv[MAXPLAYERS+1];
//雷子弹
new LZDLv[MAXPLAYERS+1];

/**********************
*	影武者
**********************/
//风暴之怒
new FBZNLv[MAXPLAYERS+1];
//玄冰风暴
new XBFBLv[MAXPLAYERS+1];
//影之匙
new YWZZS[MAXPLAYERS+1];
//武者之光
new WZZGLv[MAXPLAYERS+1];

/**********************
*	审判者
**********************/
//生命之书
new SMZS[MAXPLAYERS+1];
//补给之书
new FHZS[MAXPLAYERS+1];
//审判之书
new SPZSLv[MAXPLAYERS+1];
//毁灭之书
new HMZSLv[MAXPLAYERS+1];
//极冰盛宴
new JBSYLv[MAXPLAYERS+1];

/**********************
*	毒龙
**********************/
//坚硬身躯
new JYSQLv[MAXPLAYERS+1];
//嗜血之光
new SXZGLv[MAXPLAYERS+1];
//毒龙爆破
new BBBSLv[MAXPLAYERS+1];
//毒龙之光
new DSZGLv[MAXPLAYERS+1];

/**********************
*	幻影统帅
**********************/
//幻影之炎
new PHFRLv[MAXPLAYERS+1];
//幻影爆破
new PHABLv[MAXPLAYERS+1];
//幻影之血
new PHZGLv[MAXPLAYERS+1];
//幻影炮
new PHSCLv[MAXPLAYERS+1];

/**********************
*	复仇者
**********************/
//复仇欲望
new PHFRALv[MAXPLAYERS+1];
//爆破光球
new PHABALv[MAXPLAYERS+1];
//闪电火球
new PHZGALv[MAXPLAYERS+1];
//死亡契约
new PHSDLv[MAXPLAYERS+1];
//献祭
new XJLv[MAXPLAYERS+1];

/**********************
*	大祭祀
**********************/
//祭祀之光
new LLLZLv[MAXPLAYERS+1];
//魔法冲击
new LLLELv[MAXPLAYERS+1];
//魔法冲击
new LLLSLv[MAXPLAYERS+1];

/**********************
*	狂战士
**********************/
//祭祀之光
new HYJWLv[MAXPLAYERS+1];
//怒气爆发
new NQBFLv[MAXPLAYERS+1];
//献祭
new XZKBLv[MAXPLAYERS+1];

/**********************
*	坦克变异
**********************/
/** 变身坦克 **/
new BSTKLv[MAXPLAYERS+1];


/* 存档和排名 */
new String:SavePath[256];
new String:RankPath[256];
new Handle:RPGSave = INVALID_HANDLE;
new Handle:RPGRank = INVALID_HANDLE;

#define RankNo 100
new String:LevelRankClient[MAXPLAYERS+RankNo][256];
new LevelRank[MAXPLAYERS+RankNo];
new String:CashRankClient[MAXPLAYERS+RankNo][256];
new CashRank[MAXPLAYERS+RankNo];
new bool:IsAdmin[MAXPLAYERS+1]	=	{false, ...};

/* Robot升级设置 */
new RobotUpgradeLv[MAXPLAYERS+1][3];
/*  彩票卷 */
new Lottery[MAXPLAYERS+1]				=	{0, ...};

/* 道具最大数 :消耗道具最大值 -  装备道具最大值*/
new MaxItemNum[2] = { 9, 114 };

/* 存档变量 : 玩家ID - 道具类别 - 道具 */
new PlayerItem[MAXPLAYERS+1][2][114];	//装备总数
new PlayerXHItemSize[MAXPLAYERS+1];
new PlayerZBItemSize[MAXPLAYERS+1];

/* 道具类别 */
#define ITEM_XH			0	//消耗类道具
#define ITEM_ZB			1	//装备类道具
#define ITEM_XH_MAX		9
#define ITEM_ZB_MAX		114 //装备总数

new BagMax[5] = { 10, 5, 3, 4, 2 };
/* bot计时器 */
new Handle:Handle_BotTimer;

new Handle:LotteryTimerHandle[MAXPLAYERS+1];

//by MicroLeo
/*过关自动登录*/
new Handle:AutoLoginPack = INVALID_HANDLE;
new bool:b_IsCheckPack[MAXPLAYERS];//MAXPLAYERS=65
//end