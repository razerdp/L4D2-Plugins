/*========================================================================
==========================================================================

					P	E	R	K	M	O	D	2
					-----------------------------
						by tPoncho, aka tP

				   I owe a great deal of thanks to:

							Skorpion1976
							  Uyukio
							spiderlemur
								olj
							grandwazir

						and a special thanks to
							AtomicStryker

			and to everyone else in the Sourcemod community
					for feedback and support! ^^

- version 1.0:
		Initial release
- version 1.0.1:
		Changed code for Blind Luck with Doku's
- version 1.0.2:
		Attempted fix for outrageous health values for survivors.
		Fix for Double Tap not working on team switches.
- version 1.1:
		Replaced Speed Demon with Grasshopper.
		Included CVars to disable perks.
		Fix for various tank perks either not applying or applying too
			many times (double the trouble health multiplier).
		Added more info to perk CVars for min and max values allowed.
		Added in a CVar to disable plugin adjustments to survivor crawling.
		Changing teams to survivors should grant perks.
- version 1.1.1:
		Fixed Martial Artist not resetting fatigue.
		Removed	debug messages (oops!)
- version 1.2:
		New perk for Boomers - Motion Sickness, boosts movement speed and
			lets you run while vomiting.
		Reinstated Speed Demon (for hunters).
		Nerfed Metabolic Boost default value from 1.5 to 1.4.
		Nerfed Tongue Twister default values slightly (pull speed 1.75->1.5,
			shoot speed	1.75->1.5, range 1.75 unchanged).
		Unbreakable now gives bonus buffer on being revived.
		Hopefully fixed problem with unbreakable not applying sometimes.
		Hopefully fixed problem with second tank not spawning with Double
			Trouble.
		Minor fixes for (mostly) harmless server errors
- version 1.3:
		Double Trouble tanks can no longer be frustrated as long as	both
			are alive (band-aid solution to the disappearing-tank-when-both-
			tanks-are-alive-and-one-gets-frustrated problem).
		Pack Rat now gives ammo based on max ammo values set by the server
			instead of absolute values.
		Nerfed Dead Wreckening default value
			(damage multiplier 1.0 -> 0.5).
		Added in an option for players to pick random perks.
		Added in a CVar to force random perks on players every roundstart.
		Revised the show-menu code slightly to always show the initial
			"customize/playNOW!" menu on roundstarts.
		Revised some code so that disabling a perk that changes ConVars
			will make the plugin stop modifying those ConVars.
		Added in ConVars to selectively disable ConVar modifying for the
			perks Helping Hand and Blind Luck.
		Renamed	ConVar "l4d_perkmod_spirit_crawling" to
			"l4d_perkmod_spirit_enable_convarchanges" to keep the naming
			system consistent with the other new ConVar-change-permission
			ConVars.
- version 1.4:
		Revised Spirit so that self-reviving doesn't reset black-and-
			white health (thanks to AtomicStryker!). Self-reviving through
			Spirit won't increase the revive count towards black-and-white
			health,	however.
		Reduced default Spirit cooldown values
			(versus and survival 210s -> 150s, campaign 540s -> 240s).
		Bots now receive random perks. The pool of perks that bots can choose
			from can be adjusted with "l4d_perkmod_bot_<type> <range>".
			General format is "1,2,3,4,5", "3,2,5", etc.
		Added CVars to disable entire perk trees, which will stop all perks
			under that tree from working, and also hide	the perk tree from
			player menus.
		Revised perk code so that non-CVar-adjusting perks will also cease
			functioning if disabled in general.
		Fixed some code that was causing CVar-adjusting perks to adjust CVars
			even when disabled in game modes other than campaign.
		Added CVar to disable the player's option to randomize their perks
			("l4d_perkmod_randomperks_enable")
		Added missing code to when a player selects "Play NOW!" on the
			initial perk menu, which wasn't applying some perk benefits
			(thanks again, AtomicStryker!)
		Added an OnPluginEnd function.
- version 1.4.1:
		Fixed problems with never-ending music.
		Merged Speed Demon with Old School. Reduced Speed Demon to 1.4x and
			Old School to 3/6/12. CVar names are unchanged.
		Seemed to be some problems with damage adds. Fixed.
- version 1.4.2:
		Fixed PKT errors showing up on clients' console.
- version 2.0.0a:
		Support for L4D2.
		Pack Rat works with L4D2 guns.
- version 2.0.1a:
		Newer, shinier version for L4D2!
		Reorganized Survivor perks into three categories.
		Rebalanced Survivor perk values.
		Martial Artist (remake): now increases melee attack speed.
		Efficient Killer (remake): now deals a flat +50% damage bonus to all damage.
		Modified Pack Rat to also work with grenade launchers.
		Updated Pyrotechnician to include vomit jars.
		Updated Chem Reliant to include adrenaline shots.
		Changed Dead Wreckening to better handle rounding. If rounding error
			can occur (say it calculates 1.5 damage), then it will randomly
			choose either the higher or the lower (1 or 2).
		Fixed an issue with Spirit firing on tank deaths - no, Valve,
			tank deaths do NOT count as being incapped! ^^
		Adrenal Glands no longer increases rock travel speed.
		Spirit no longer allows crawling.
		Added some code so some perks should recognize when a survivor is being
			disabled by a charger (ie., spirit).
		Removed Old School and Speed Demon perks.
		Converted a few perks that reduce cooldowns to not use CVars. Some
			perks still use CVars - namely, Helping Hand (revive time),
			Tongue Twister (everything about it), Drag and Drop (manual
			release, drop-to-ground/recovery time)
		Rewrote some class checks to check actual netprop values instead
			of checking model names.
- version 2.0.2a:
		Fixed cooldown-reducing perks; most had stopped working with the last update.
		Twin Spitfire now activates properly for the first attack after spawning.
		After going AFK (in coop), the menu shouldn't reset perks for the player.
		The menu should appear somewhat more consistently.
		Martial Artist (remake): Now allows the player to swing melee weapons twice
			 rapidly in succession, and reduces the maximum shove penalty for any weapon.
		Extreme Conditioning (new): gives a survivor +10% run speed.
- version 2.0.3a:
		Reinstated Speed Demon perk for hunters.
		Fixed Sleight of Hand bug that prevented being able to shoot after reloading.
- version 2.0.4a:
		Added backwards compatibility for L4D1.
		Fixed some major bugs with Spirit. Spirit will no longer attempt to revive a
			player immediately after being incapped, which should increase the reliability
			of the perk functioning, but it means that if the last survivor standing
			gets incapped, even if that survivor or another survivor has spirit, too bad.
		Added some extra checks for Unbreakable to fix some rare abuses.
		Fixed Double Trouble not spawning the second tank.
		Double Trouble no longer stops tanks from becoming frustrated.
- version 2.0.5a:
		Attempted fixes for stability.
- version 2.0.6a:
		Another attempt at fixing stability.
- version 2.0.7a:
		Fixed error messages for Unbreakable and Sleight of Hand.
		Revised Twin Spitfire to be more consistent in giving two shots.
		Increased Helping Hand bonus health from 10 to 15.
		Increased Spirit bonus health from 0 to 10.
		Plugin will now attempt to load values from the .cfg file on round start, in
			addition to loading it on plugin load.
- version 2.0.8a:
		Revised menu code, should properly show a player that a perk is disabled.
		Fixed a bug with Hard to Kill.
- version 2.0.9:
		Added Cavalier perk for Jockeys: gives 60% more health.
		Changed Spirit so that a self-revive counts as a revive - meaning each self-revive
			moves you one step closer to black-and-white health.
		Increased Spirit self-revive health bonus from 10 to 30
		Fixed some bugs with Unbreakable, wasn't giving bonus health buffer on revive or
			after being rescued from the closet.
		Reduced Unbreakable bonus health buffer on revive from 16 to 10 (0.8 -> 0.5 of
			Unbreakable health bonus value).
		Helping Hand now gives bonus health buffer to the reviver as well.
		Reduced Helping Hand bonus buffer from 15 to 10 for versus.
		Lowered Double the Trouble health modifier from 0.6 to 0.45
		Lowered Body Slam minimum pounce damage from 11 to 10
		Lowered Efficient Killer damage bonus from 0.3 to 0.2
		Lowered Grasshopper pounce speed multiplier from 1.3 to 1.2
- version 2.0.10:
		Added Frogger perk for Jockeys: 20% more damage, 30% more leap distance.
		Added Ghost Rider perk for Jockeys: near invisibility.
		Added Speeding Bullet perk for Chargers: charges are 30% faster and longer.
		Modified Scattering Ram to also give 30% more health.
		Revised menu code again, shouldn't display disabled perks.
- version 2.0.11:
		Adrenal Glands now also makes the tank unfrustratable.
		Increased Frogger damage from 0.2 -> 0.35
		Fixed Helping Hand bug that wasn't giving the reviver bonus health buffer.
		Fixed bug/exploit with Chem Reliant/Pyrotechnician/Unbreakable on switching
			from AFK to non-AFK.
		Fixed Pack Rat bug/exploit and updated some old code.
- version 2.0.12:
		The plugin will no longer read from the cfg file on round start,
			was probably causing some buffer overflows...
		Fixed a few minor errors.
- version 2.1.0:
		Twin Spitfire, Adrenal Glands and other cooldown-reducing perks should now
			work properly on Linux servers (nobody told me the offsets were all weird
			between Linux and Windows servers =.=). Still don't have offset numbers for
			L4D1 Linux, so it won't work for L4D1 Linux until I can find those numbers...
		Being rescued from the closet now gives bonus items with the corresponding perks
			(grenades for Pyrotechnician, pills for Chem Reliant).
		Added translations! (basically stole AtomicStryker's work =P)
- version 2.1.1:
		Added Mega Adhesive perk to spitters: slows survivor speed by 50% for up to two seconds
			after leaving spit.
		Added Smoke IT! perk to smokers: can walk while smoking (thanks to Olj for this perk!)
		Added Little Leaguer perk to survivor-tertiary: gives a baseball bat.
		Saying !perks should work more consistently (but perks may still not work properly
			on local servers!)
- version 2.1.2:
		Updated Martial Artist to now give 3 swings instead of 2, and shoving or drawing the
			melee weapon no longer "counts" as a swing.
		Helping Hand should now be properly granting the reviver half the bonus health buffer
			as well (was previously only granting it to the revivee).
- version 2.1.3:
		Double Tap now has a 15% chance per shot that a bullet will not be consumed.
		Rewrote Pack Rat to address multiple bugs.
		Added a CVar "l4d_perkmod_autoshowmenu" to enable or disable automatically showing the
			perks menu on roundstart.
		Updated offsets for ability and attack timers, cooldown-reducing perks (ie. Twin Spitfire)
			and attack speed increase perks (ie. Adrenal Glands) should now work properly.
- version 2.1.4:
		Increased Twin Spitfire delay in-between spits from 2.5s -> 6s.
		Increased Mega-Adhesive slow from 50% -> 60%.
		Updated Pack Rat further, should be less buggy... with any luck.
- version 2.1.5:
		Rewrote some code, Mega Adhesive should no longer interfere with other movement-changing
			infected perks.
		Fixed an exploit with faster reloading for Double Tap.
		Updated Pack Rat again to address more bugs.


==========================================================================
========================================================================*/



//=============================
// Start
//=============================

#pragma semicolon 1
#include <sourcemod>
#include <sdktools>
#define PLUGIN_VERSION "2.1.5"

//info
public Plugin:myinfo=
{
	name="PerkMod",
	author="tPoncho",
	description="Adds Call Of Duty-style perks for L4D",
	version=PLUGIN_VERSION,
	url=""
}



//=============================
// Declare Global Variables
//=============================

//init player perk vars
new g_iSur1[MAXPLAYERS+1];	//survivors, primary
new g_iSur2[MAXPLAYERS+1];	//survivors, secondary
new g_iSur3[MAXPLAYERS+1];	//survivors, tertiary
new g_iInf1[MAXPLAYERS+1];	//boomer
new g_iInf2[MAXPLAYERS+1];	//tank
new g_iConfirm[MAXPLAYERS+1];	//check if perks are confirmed, to prevent mid-game changing abuses
new g_iInf3[MAXPLAYERS+1];	//smoker
new g_iInf4[MAXPLAYERS+1];	//hunter
new g_iInf5[MAXPLAYERS+1];	//jockey
new g_iInf6[MAXPLAYERS+1];	//spitter
new g_iInf7[MAXPLAYERS+1];	//charger

//timer perks handle
new Handle:g_hTimerPerks = INVALID_HANDLE;

//PYROTECHNICIAN PERK
//track how many grenades are carried for pyrotechnician perk
new g_iGren[MAXPLAYERS+1];
//used so functions don't confuse legitimate grenade pickups
//with acquisitions from grenadier perk
new g_iGrenThrow[MAXPLAYERS+1];
//used to track which type of grenade was used;
//1 = pipe, 2 = molotov
new g_iGrenType[MAXPLAYERS+1];

//SPIRIT PERK
//0 = not incapped
//1 = incapped
new g_iPIncap[MAXPLAYERS+1];
//used to keep track of whether cooldown is in effect
new g_iSpiritCooldown[MAXPLAYERS+1];
//used to track the timers themselves
new Handle:g_iSpiritTimer[MAXPLAYERS+1];

//DOUBLE TAP PERK
//used to track who has the double tap perk
//index goes up to 18, but each index has
//a value indicating a client index with DT
//so the plugin doesn't have to cycle a full
//18 times per game frame
new g_iDTRegisterIndex[MAXPLAYERS+1] = -1;
//and this tracks how many have DT
new g_iDTRegisterCount = 0;
//this tracks the current active weapon id
//in case the player changes guns
new g_iDTEntid[MAXPLAYERS+1] = -1;
//used for the bullet conservation
new g_iDTEntid_firearm[MAXPLAYERS+1] = -1;
//this tracks the engine time of the next
//attack for the weapon, after modification
//(modified interval + engine time)
new Float:g_flDTNextTime[MAXPLAYERS+1] = -1.0;

//SLEIGHT OF HAND PERK
//this keeps track of the default values for
//reload speeds for the different shotgun types
//NOTE: I got these values over testing earlier
//and since it's a waste of processing time to
//retrieve these values constantly, we just use
//the pre-retrieved values
//NOTE: updated for L4D2, pump and chrome have
//identical values
const Float:g_flSoHAutoS = 0.666666;
const Float:g_flSoHAutoI = 0.4;
const Float:g_flSoHAutoE = 0.675;
const Float:g_flSoHSpasS = 0.5;
const Float:g_flSoHSpasI = 0.375;
const Float:g_flSoHSpasE = 0.699999;
const Float:g_flSoHPumpS = 0.5;
const Float:g_flSoHPumpI = 0.5;
const Float:g_flSoHPumpE = 0.6;

//MARTIAL ARTIST PERK
//similar to Double Tap
new g_iMARegisterIndex[MAXPLAYERS+1] = -1;
//and this tracks how many have MA
new g_iMARegisterCount = 0;
//these are similar to those used by Double Tap
new Float:g_flMANextTime[MAXPLAYERS+1] = -1.0;
new g_iMAEntid[MAXPLAYERS+1] = -1;
new g_iMAEntid_notmelee[MAXPLAYERS+1] = -1;
//this tracks the attack count, similar to twinSF
new g_iMAAttCount[MAXPLAYERS+1] = -1;

//PACK RAT PERK
//prevents perk from applying multiple times within a short interval
//ie. when two related events fire at the same time that both trigger PR
new bool:g_bPRalreadyApplying[MAXPLAYERS+1] = false;

//VARIOUS INFECTED PERKS
//this is used by most cooldown-reducing SI
//perks, keeps track of when an ability was used
new Float:g_flTimeStamp[MAXPLAYERS+1] = -1.0;
//contains id of target, for given disabler
new g_iMyDisableTarget[MAXPLAYERS+1] = -1;
//contains id of disabler, for given survivor
new g_iMyDisabler[MAXPLAYERS+1] = -1;

//BARF BAGGED PERK
//used to track how many survivors are boomed at a given time
//because spawning a whole mob per player is WAY too many
//also used indirectly to check if someone is currently vomited on
new g_iSlimed=0;

//DEAD WRECKENING PERK
//used to track who vomited on a survivor last
new g_iSlimerLast=0;

//TWIN SPITFIRE PERK
//similar to Double Tap
new g_iTwinSFShotCount[MAXPLAYERS+1] = 0;

//MEGA ADHESIVE PERK
new Handle:g_hMegaAdTimer[MAXPLAYERS+1] = INVALID_HANDLE;
new g_iMegaAdCount[MAXPLAYERS+1] = 0;

//TANKS
//tracks whether tanks are existent, and what perks have been given
//0 = no tank;
//1 = tank, but no special perks assigned yet;
//2 = tank, juggernaut has been given;
//3 = tank, double trouble has been given;
//4 = frustrated tank with double trouble is being passed to another player;
new g_iTank=0;
new g_iTankCount=0;		//tracks how many tanks there under double trouble modification
new g_iTankBotTicks=0;	//after 3 ticks, if tank is still a bot then give buffs
new g_iTank_MainId=0;	//tracks which tank is the "original", for Double Trouble
//similar to Double Tap, only used for punches
new g_iAdrenalRegisterCount = 0;
new g_iAdrenalRegisterIndex[MAXPLAYERS+1] = -1;
new Float:g_flAdrenalTimeStamp[MAXPLAYERS+1] = -1.0;

//VARS TO STORE CONVAR VALUES
//declare revive time var
new Float:g_flReviveTime= -1.0;
//declare vomit fatigue var
new Float:g_flVomitFatigue= -1.0;
//declare yoink tongue speed var
new Float:g_flTongueSpeed= -1.0;
new Float:g_flTongueFlySpeed= -1.0;
new Float:g_flTongueRange= -1.0;
//declare drag and drop vars
new Float:g_flTongueDropTime= -1.0;

//OFFSETS
new g_iHPBuffO			= -1;
new g_iHPBuffTimeO		= -1;
new g_iRevCountO		= -1;
new g_iMeleeFatigueO	= -1;
new g_iNextPAttO		= -1;
new g_iNextSAttO		= -1;
new g_iActiveWO			= -1;
new g_iShotStartDurO	= -1;
new g_iShotInsertDurO	= -1;
new g_iShotEndDurO		= -1;
new g_iPlayRateO		= -1;
new g_iShotRelStateO	= -1;
new g_iNextAttO			= -1;
new g_iTimeIdleO		= -1;
new g_iLaggedMovementO	= -1;
new g_iFrustrationO		= -1;
new g_iAbilityO			= -1;
new g_iClassO			= -1;
new g_iVMStartTimeO		= -1;
new g_iViewModelO		= -1;
new g_iIncapO			= -1;
new g_iIsGhostO			= -1;
new g_iClipO			= -1;

//these offsets refuse to be searched for (these netprops
//have unique names, but the SENDTABLE names are not unique - 
//usually DT_CountdownTimer, making it impossible to search
//for AFAIK...), so we'll just declare them here and hope
//Valve doesn't change them...

//these offsets are for L4D2, Windows
//next activation timer now +4 since valve update
//-----------------------------
//windows and linux offsets are checked
//during roundstart by comparing an offset
//to known offset numbers
new g_iNextActO = 1068;
new g_iAttackTimerO = 5436;

//these are for L4D2, Linux
//new g_iNextActO_linux = 1088;
//new g_iAttackTimerO_linux = 5444;



//=============================
// Declare Variables that track
// base L4D ConVars
//=============================

//tracks game mode
//0 = campaign, realism
//1 = survival
//2 = versus, scavenge, team variants
new g_iL4D_GameMode;

//tracks if the game is L4D 1 or 2
new g_iL4D_12 = 0;

//prevents certain functions from spamming too often
new bool:g_bIsRoundStart	 = false;
new bool:g_bIsLoading		 = false;


//=============================
// Declare Variables Related to
// the Plugin's Own ConVars
//=============================
//first line says the name of the perk
//second line describes how many types there are
//ie:
//"通用" = one variable across all game modes and difficulties
//"versus, non-versus" = one variable for versus games, one for non-versus games
//"normal, hard, expert" = separate variables for normal-versus-survival, advanced and expert


//幸存者技能设置
//强力射击, 伤害
//通用
new Handle:g_hStopping_enable;
new Handle:g_hStopping_enable_sur;
new Handle:g_hStopping_enable_vs;
new Handle:g_hStopping_dmgmult;
//相关变量
new g_iStopping_enable;
new g_iStopping_enable_sur;
new g_iStopping_enable_vs;
new Float:g_flStopping_dmgmult;

//精神医师 给予的生命和冷却
//战役, 生存, 对抗
new Handle:g_hSpirit_enable;
new Handle:g_hSpirit_enable_sur;
new Handle:g_hSpirit_enable_vs;
new Handle:g_hSpirit_buff;
new Handle:g_hSpirit_cd;
new Handle:g_hSpirit_cd_sur;
new Handle:g_hSpirit_cd_vs;
//相关变量
new g_iSpirit_enable;
new g_iSpirit_enable_sur;
new g_iSpirit_enable_vs;
new g_iSpirit_buff;
new g_iSpirit_cd;
new g_iSpirit_cd_sur;
new g_iSpirit_cd_vs;

//血量上升, 血量调整
//通用
new Handle:g_hUnbreak_enable;
new Handle:g_hUnbreak_enable_sur;
new Handle:g_hUnbreak_enable_vs;
new Handle:g_hUnbreak_hp;
//相关变量
new g_iUnbreak_enable;
new g_iUnbreak_enable_sur;
new g_iUnbreak_enable_vs;
new g_iUnbreak_hp;

//快射射击, 射击速度
//通用
new Handle:g_hDT_enable;
new Handle:g_hDT_enable_sur;
new Handle:g_hDT_enable_vs;
new Handle:g_hDT_rate;
new Handle:g_hDT_freechance;
//相关变量
new g_iDT_enable;
new g_iDT_enable_sur;
new g_iDT_enable_vs;
new Float:g_flDT_rate;
new Float:g_flDT_freechance;

//极速上弹,装弹速度
//通用
new Handle:g_hSoH_enable;
new Handle:g_hSoH_enable_sur;
new Handle:g_hSoH_enable_vs;
new Handle:g_hSoH_rate;
//相关变量
new g_iSoH_enable;
new g_iSoH_enable_sur;
new g_iSoH_enable_vs;
new Float:g_flSoH_rate;

//炸弹专家
new Handle:g_hPyro_enable;
new Handle:g_hPyro_enable_sur;
new Handle:g_hPyro_enable_vs;
new g_iPyro_enable;
new g_iPyro_enable_sur;
new g_iPyro_enable_vs;


//幸存者技能设置
//药丸专家, 药丸给予奖励数据
//通用
new Handle:g_hChem_enable;
new Handle:g_hChem_enable_sur;
new Handle:g_hChem_enable_vs;
new Handle:g_hChem_buff;
//相关变量
new g_iChem_enable;
new g_iChem_enable_sur;
new g_iChem_enable_vs;
new g_iChem_buff;

//急救医师, 缓冲和救援速度
//对抗, 禁用-对抗
new Handle:g_hHelpHand_enable;
new Handle:g_hHelpHand_enable_sur;
new Handle:g_hHelpHand_enable_vs;
new Handle:g_hHelpHand_convar;
new Handle:g_hHelpHand_timemult;
new Handle:g_hHelpHand_buff;
new Handle:g_hHelpHand_buff_vs;
//相关变量
new g_iHelpHand_enable;
new g_iHelpHand_enable_sur;
new g_iHelpHand_enable_vs;
new g_iHelpHand_convar;
new Float:g_flHelpHand_timemult;
new g_iHelpHand_buff;
new g_iHelpHand_buff_vs;

//弹药专家, 弹夹增幅设置
//通用
new Handle:g_hPack_enable;
new Handle:g_hPack_enable_sur;
new Handle:g_hPack_enable_vs;
new Handle:g_hPack_ammomult;
//相关变量
new g_iPack_enable;
new g_iPack_enable_sur;
new g_iPack_enable_vs;
new Float:g_flPack_ammomult;

//终极守护, 倒地HP设置
//通用
new Handle:g_hHard_enable;
new Handle:g_hHard_enable_sur;
new Handle:g_hHard_enable_vs;
new Handle:g_hHard_hpmult;
//相关变量
new g_iHard_enable;
new g_iHard_enable_sur;
new g_iHard_enable_vs;
new Float:g_flHard_hpmult;

//中华武术家, 近战挥舞速度
//战役, 禁用-战役
new Handle:g_hMA_enable;
new Handle:g_hMA_enable_sur;
new Handle:g_hMA_enable_vs;
new Handle:g_hMA_maxpenalty;
//相关变量
new g_iMA_enable;
new g_iMA_enable_sur;
new g_iMA_enable_vs;
new g_iMA_maxpenalty;

//凌波微步, 跑步速度
//战役, 禁用-战役
new Handle:g_hExtreme_enable;
new Handle:g_hExtreme_enable_sur;
new Handle:g_hExtreme_enable_vs;
new Handle:g_hExtreme_rate;
//相关变量
new g_iExtreme_enable;
new g_iExtreme_enable_sur;
new g_iExtreme_enable_vs;
new Float:g_flExtreme_rate;

//机枪手
new Handle:g_hLittle_enable;
new Handle:g_hLittle_enable_sur;
new Handle:g_hLittle_enable_vs;
//相关变量
new g_iLittle_enable;
new g_iLittle_enable_sur;
new g_iLittle_enable_vs;


//特感技能设置 (BOOMER) 胖子
//黑暗来袭, 冷却时间
//通用
new Handle:g_hBlind_enable;
new Handle:g_hBlind_cdmult;
//相关变量
new g_iBlind_enable;
new Float:g_flBlind_cdmult;

//呕吐攻击, 攻击伤害
//通用
new Handle:g_hDead_enable;
new Handle:g_hDead_dmgmult;
//相关变量
new g_iDead_enable;
new Float:g_flDead_dmgmult;

//超级呕吐
new Handle:g_hBarf_enable;
new g_iBarf_enable;

//移动呕吐
//通用
new Handle:g_hMotion_rate;
new Handle:g_hMotion_enable;
//相关变量s
new Float:g_flMotion_rate;
new g_iMotion_enable;


//特感技能设置 (SMOKER)长舌妇
//超级舌头, 舌头速度-拉人速度-舌头范围
//通用
new Handle:g_hTongue_enable;
new Handle:g_hTongue_speedmult;
new Handle:g_hTongue_pullmult;
new Handle:g_hTongue_rangemult;
//相关变量
new g_iTongue_enable;
new Float:g_flTongue_speedmult;
new Float:g_flTongue_pullmult;
new Float:g_flTongue_rangemult;

//致命舌头, 额外伤害
//正常, 困难, 专家
//*电脑所在难度下使用
new Handle:g_hSqueezer_enable;
new Handle:g_hSqueezer_dmgmult;
//相关变量
new g_iSqueezer_enable;
new Float:g_flSqueezer_dmgmult;

//舌头中断,冷却时间
//通用
new Handle:g_hDrag_enable;
new Handle:g_hDrag_cdmult;
//相关变量
new g_iDrag_enable;
new Float:g_flDrag_cdmult;

//拉人行走
new Handle:g_hSmokeItSpeed;
new Handle:g_hSmokeItTimer[MAXPLAYERS+1];
new Handle:g_hSmokeItMaxRange;
new Handle:g_hSmokeIt_enable;
//相关变量s
new Float:g_flSmokeItSpeed;
new bool:g_bSmokeItGrabbed[MAXPLAYERS+1];
new g_iSmokeItMaxRange;
new g_iSmokeIt_enable;



//特感技能设置(HUNTER) 亨特
//瞬间压制, 造成的额外伤害
//通用
new Handle:g_hBody_enable;
new Handle:g_hBody_minbound;
//相关变量
new g_iBody_enable;
new g_iBody_minbound;

//超级杀手 额外伤害
//正常, 困难, 专家
//*电脑所在难度下使用
new Handle:g_hEfficient_enable;
new Handle:g_hEfficient_dmgmult;
//相关变量
new g_iEfficient_enable;
new Float:g_flEfficient_dmgmult;

//超远袭击, 距离设置
//通用
new Handle:g_hGrass_enable;
new Handle:g_hGrass_rate;
//相关变量
new g_iGrass_enable;
new Float:g_flGrass_rate;

//终极杀手, 速度和伤害
//通用
new Handle:g_hSpeedDemon_enable;
new Handle:g_hSpeedDemon_rate;
new Handle:g_hSpeedDemon_dmgmult;
//相关变量
new g_iSpeedDemon_enable;
new Float:g_flSpeedDemon_rate;
new Float:g_flSpeedDemon_dmgmult;


//特感技能设置 (TANK) 坦克
//坦克狂化, 速度和冷却时间
//扔石头冷却时间, 挥拳冷却时间
//通用
new Handle:g_hAdrenal_enable;
new Handle:g_hAdrenal_punchcdmult;
new Handle:g_hAdrenal_throwcdmult;
//相关变量
new g_iAdrenal_enable;
new Float:g_flAdrenal_punchcdmult;
new Float:g_flAdrenal_throwcdmult;

//世界主宰,额外生命
//通用
new Handle:g_hJuggernaut_enable;
new Handle:g_hJuggernaut_hp;
//相关变量
new g_iJuggernaut_enable;
new g_iJuggernaut_hp;

//代谢增强, 增加的速度
//通用
new Handle:g_hMetabolic_enable;
new Handle:g_hMetabolic_speedmult;
//相关变量
new g_iMetabolic_enable;
new Float:g_flMetabolic_speedmult;

//召唤小弟,召唤特感数量
//通用
new Handle:g_hStorm_enable;
new Handle:g_hStorm_mobcount;
//相关变量
new g_iStorm_enable;
new g_iStorm_mobcount;

//心动呼唤, 生命分配
//通用
new Handle:g_hDouble_enable;
new Handle:g_hDouble_hpmult;
//相关变量
new g_iDouble_enable;
new Float:g_flDouble_hpmult;


//特感技能设置 (JOCKEY) 猴子
//风行者, 骑人速度
//通用
new Handle:g_hWind_enable;
new Handle:g_hWind_rate;
//相关变量
new g_iWind_enable;
new Float:g_flWind_rate;

//骑士, HP设置
new Handle:g_hCavalier_enable;
new Handle:g_hCavalier_hpmult;
//相关变量
new g_iCavalier_enable;
new Float:g_flCavalier_hpmult;

//终极骑士, 伤害和跳跃距离
new Handle:g_hFrogger_enable;
new Handle:g_hFrogger_dmgmult;
new Handle:g_hFrogger_rate;
//相关变量
new g_iFrogger_enable;
new Float:g_flFrogger_dmgmult;
new Float:g_flFrogger_rate;

//恶灵骑士, i隐身程度
new Handle:g_hGhost_enable;
new Handle:g_hGhost_alpha;
//相关变量
new g_iGhost_enable;
new g_iGhost_alpha;


//特感技能设置 (SPITTER)口水怪
//双重喷射, 第二次喷射延迟
//通用
new Handle:g_hTwinSF_enable;
new Handle:g_hTwinSF_delay;
//相关变量
new g_iTwinSF_enable;
new Float:g_flTwinSF_delay;

//粘皮带骨, 幸存者在口水上行走的缓慢速度
//通用
new Handle:g_hMegaAd_enable;
new Handle:g_hMegaAd_slow;
//相关变量
new g_iMegaAd_enable;
new Float:g_flMegaAd_slow;

/*没有这个技能估计是作者以后更新的技能, 最小伤害
//
new Handle:g_hLethal_enable;
new Handle:g_hLethal_minbound;
//相关变量
new g_iLethal_enable;
new g_iLethal_minbound;
*/


//特感技能设置 (CHARGER)牛
//愤怒的公牛,冲撞力量和血量
//通用
new Handle:g_hScatter_enable;
new Handle:g_hScatter_force;
new Handle:g_hScatter_hpmult;
//相关变量
new g_iScatter_enable;
new Float:g_flScatter_force;
new Float:g_flScatter_hpmult;

//极速冲撞, 冲撞速度
new Handle:g_hBullet_enable;
new Handle:g_hBullet_rate;
//相关变量
new g_iBullet_enable;
new Float:g_flBullet_rate;
/*
//unstoppable force, hpmult and runspeed mult
new Handle:g_hUnstop_enable;
new Handle:g_hUnstop_hpmult;
new Handle:g_hUnstop_rate;
//相关变量
new g_iUnstop_enable;
new Float:g_flUnstop_hpmult;
new Float:g_flUnstop_rate;
*/



//BOT CONTROLLER VARS
//these track the server's preference
//幸存者BOT可选择主菜单技能

//survivor
new Handle:g_hBot_Sur1;
new Handle:g_hBot_Sur2;
new Handle:g_hBot_Sur3;
//boomer
new Handle:g_hBot_Inf1;
//smoker
new Handle:g_hBot_Inf3;
//hunter
new Handle:g_hBot_Inf4;
//tank
new Handle:g_hBot_Inf2;
new Handle:g_hBot_Inf5;
new Handle:g_hBot_Inf6;
new Handle:g_hBot_Inf7;

//DEFAULT PERKS
//These vars track the server's
//given default perks, to account
//for disabling perks

//sur1
new Handle:g_hSur1_default;
new g_iSur1_default;

//sur2
new Handle:g_hSur2_default;
new g_iSur2_default;

//sur3
new Handle:g_hSur3_default;
new g_iSur3_default;

//inf1/boomer
new Handle:g_hInf1_default;
new g_iInf1_default;

//inf3/smoker
new Handle:g_hInf3_default;
new g_iInf3_default;

//inf4/hunter
new Handle:g_hInf4_default;
new g_iInf4_default;

//inf2/tank
new Handle:g_hInf2_default;
new g_iInf2_default;

//inf5/jockey
new Handle:g_hInf5_default;
new g_iInf5_default;

//inf6/spitter
new Handle:g_hInf6_default;
new g_iInf6_default;

//inf7/charger
new Handle:g_hInf7_default;
new g_iInf7_default;

//FORCE RANDOM PERKS
//tracks server setting for
//whether to force random perks

new Handle:g_hForceRandom;
new g_iForceRandom;

//ENABLE RANDOM PERKS BY PLAYER CHOICE
//tracks whether player can
//randomize their perks

new Handle:g_hRandomEnable;
new g_iRandomEnable;

//PERK TREES AVAILABILITY
//option for servers to completely
//disable entire perk trees

new Handle:g_hSur1_enable;
new Handle:g_hSur2_enable;
new Handle:g_hSur3_enable;
new Handle:g_hInf1_enable;
new Handle:g_hInf2_enable;
new Handle:g_hInf3_enable;
new Handle:g_hInf4_enable;
new Handle:g_hInf5_enable;
new Handle:g_hInf6_enable;
new Handle:g_hInf7_enable;
new g_iSur1_enable;
new g_iSur2_enable;
new g_iSur3_enable;
new g_iInf1_enable;
new g_iInf2_enable;
new g_iInf3_enable;
new g_iInf4_enable;
new g_iInf5_enable;
new g_iInf6_enable;
new g_iInf7_enable;

//this var keeps track of whether
//to enable DT and Stopping or not, so we don't
//have to do the checks every game frame, or
//every time someone gets hurt

new g_iDT_meta_enable = 1;
new g_iStopping_meta_enable = 1;
new g_iMA_meta_enable = 1;

//controls whether menu automatically shows
new Handle:g_hMenuAutoShow_enable;



//=============================
// Hooking, Initialize Vars
//=============================

public OnPluginStart()
{
	//Plugin version for online tracking
	CreateConVar("l4d_perkmod_version", PLUGIN_VERSION, "版本求生之路2 作者:tPoncho 汉化者:心动", FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_REPLICATED|FCVAR_NOTIFY);

	decl String:stGame[32];
	GetGameFolderName(stGame, 32);
	if (StrEqual(stGame, "left4dead2", false)==true)
	{
		g_iL4D_12 = 2;
		LogMessage("L4D 2 detected.");
	}
	else if (StrEqual(stGame, "left4dead", false)==true)
	{
		g_iL4D_12 = 1;
		LogMessage("L4D 1 detected.");
	}
	else
		SetFailState("Perkmod only supports L4D 1 or 2.");
	
	//PERK FUNCTIONS
	//anything here that pertains to the actual
	//workings of the perks (ie, events and timers)

	//hooks for Sur1 perks
	HookEvent("player_hurt", Event_PlayerHurtPre, EventHookMode_Pre);
	HookEvent("infected_hurt", Event_InfectedHurtPre, EventHookMode_Pre);
	HookEvent("item_pickup", Event_ItemPickup);
	HookEvent("spawner_give_item", Event_ItemPickup);
	HookEvent("weapon_fire", Event_WeaponFire);
	HookEvent("lunge_pounce", Event_PounceLanded);
	HookEvent("pounce_stopped", Event_PounceStop);
	HookEvent("player_ledge_grab", Event_LedgeGrab);
	HookEvent("player_team", Event_PlayerTeam);
	HookEvent("weapon_reload", Event_Reload);
	HookEvent("heal_success", Event_PlayerHealed);
	HookEvent("survivor_rescued", Event_PlayerRescued);
	HookEvent("pills_used", Event_PillsUsed, EventHookMode_Pre);
	HookEvent("revive_begin", Event_ReviveBeginPre, EventHookMode_Pre);
	HookEvent("revive_success", Event_ReviveSuccess);
	HookEvent("ammo_pickup", Event_AmmoPickup);
	HookEvent("player_incapacitated", Event_Incap);
	HookEvent("player_now_it", Event_PlayerNowIt);
	HookEvent("ability_use", Event_AbilityUsePre, EventHookMode_Pre);
	HookEvent("tongue_grab", Event_TongueGrabPre, EventHookMode_Pre);
	HookEvent("tongue_release", Event_TongueRelease);
	HookEvent("choke_end", Event_TongueRelease);
	HookEvent("tongue_broke_bent", Event_TongueRelease_novictimid);
	HookEvent("choke_stopped", Event_TongueRelease_newsmokerid);
	HookEvent("tongue_pull_stopped", Event_TongueRelease_newsmokerid);
	HookEvent("player_spawn", Event_PlayerSpawn);
	HookEvent("ability_use", Event_AbilityUse);
	HookEvent("tank_spawn", Event_Tank_Spawn);
	HookEvent("tank_frustrated", Event_Tank_Frustrated, EventHookMode_Pre);
	HookEvent("player_first_spawn", Event_PlayerFirstSpawn);
	HookEvent("player_transitioned", Event_PlayerTransitioned);
	HookEvent("player_connect_full", Event_PConnect);
	HookEvent("player_disconnect", Event_PDisconnect);
	HookEvent("round_start", Event_RoundStart);
	HookEvent("player_death", Event_PlayerDeath);
	HookEvent("round_end", Event_RoundEnd);
	//RegConsoleCmd("say", MenuOpen_OnSay);
	//RegConsoleCmd("say_team", MenuOpen_OnSay);
	RegConsoleCmd("sm_perks", MenuOpen_OnSay);
	HookConVarChange(FindConVar("mp_gamemode"),Convar_GameMode);

	//l4d2 only hooks
	if (g_iL4D_12 == 2)
	{
		HookEvent("jockey_ride", Event_JockeyRide);
		HookEvent("jockey_ride_end", Event_JockeyRideEnd);
		HookEvent("charger_pummel_start", Event_ChargerPummelStart);
		HookEvent("charger_pummel_end", Event_ChargerPummelEnd);
		HookEvent("charger_impact", Event_ChargerImpact);
		HookEvent("charger_charge_end", Event_ChargerChargeEnd);
		HookEvent("charger_carry_end", Event_ChargerChargeEnd);
		HookEvent("adrenaline_used", Event_PillsUsed, EventHookMode_Pre);
		HookEvent("player_jump", Event_Jump);
	}

	//debug
	//RegConsoleCmd("say", Debug_OnSay);
	//RegConsoleCmd("say_team", Debug_OnSay);

	//init vars
	g_flVomitFatigue	=	GetConVarFloat(FindConVar("z_vomit_fatigue"));
	g_flTongueSpeed		=	GetConVarFloat(FindConVar("tongue_victim_max_speed"));
	g_flTongueFlySpeed	=	GetConVarFloat(FindConVar("tongue_fly_speed"));
	g_flTongueRange		=	GetConVarFloat(FindConVar("tongue_range"));
	g_flTongueDropTime	=	GetConVarFloat(FindConVar("tongue_player_dropping_to_ground_time"));
	g_flReviveTime		=	GetConVarFloat(FindConVar("survivor_revive_duration"));

	//get offsets
	g_iHPBuffO			=	FindSendPropOffs("CTerrorPlayer","m_healthBuffer");
	g_iHPBuffTimeO		=	FindSendPropOffs("CTerrorPlayer","m_healthBufferTime");
	g_iRevCountO		=	FindSendPropOffs("CTerrorPlayer","m_currentReviveCount");
	g_iMeleeFatigueO	=	FindSendPropInfo("CTerrorPlayer","m_iShovePenalty");
	g_iNextPAttO		=	FindSendPropInfo("CBaseCombatWeapon","m_flNextPrimaryAttack");
	g_iNextSAttO		=	FindSendPropInfo("CBaseCombatWeapon","m_flNextSecondaryAttack");
	g_iActiveWO			=	FindSendPropInfo("CBaseCombatCharacter","m_hActiveWeapon");
	g_iShotStartDurO	=	FindSendPropInfo("CBaseShotgun","m_reloadStartDuration");
	g_iShotInsertDurO	=	FindSendPropInfo("CBaseShotgun","m_reloadInsertDuration");
	g_iShotEndDurO		=	FindSendPropInfo("CBaseShotgun","m_reloadEndDuration");
	g_iPlayRateO		=	FindSendPropInfo("CBaseCombatWeapon","m_flPlaybackRate");
	g_iShotRelStateO	=	FindSendPropInfo("CBaseShotgun","m_reloadState");
	g_iNextAttO			=	FindSendPropInfo("CTerrorPlayer","m_flNextAttack");
	g_iTimeIdleO		=	FindSendPropInfo("CTerrorGun","m_flTimeWeaponIdle");
	g_iLaggedMovementO	=	FindSendPropInfo("CTerrorPlayer","m_flLaggedMovementValue");
	g_iFrustrationO		=	FindSendPropInfo("Tank","m_frustration");
	g_iAbilityO			=	FindSendPropInfo("CTerrorPlayer","m_customAbility");
	g_iClassO			=	FindSendPropInfo("CTerrorPlayer","m_zombieClass");
	g_iVMStartTimeO		=	FindSendPropInfo("CTerrorViewModel","m_flLayerStartTime");
	g_iViewModelO		=	FindSendPropInfo("CTerrorPlayer","m_hViewModel");
	g_iIncapO			=	FindSendPropInfo("CTerrorPlayer","m_isIncapacitated");
	g_iIsGhostO			=	FindSendPropInfo("CTerrorPlayer","m_isGhost");
	g_iClipO			=	FindSendPropInfo("CTerrorGun","m_iClip1");

	//CREATE AND INITIALIZE CONVARS
	//everything related to the convars that adjust
	//certain values for the perks
	CreateConvars();

	//finally, run a command to exec the .cfg file
	//to load the server's preferences for these cvars
	AutoExecConfig(true , "perkmod");

	//and load translations
	LoadTranslations("plugin.perkmod");
}

//just to give me a bit less of a headache,
//all convar creation is called here
CreateConvars()
{
	//幸存者技能设置
	//强力射击
	g_hStopping_dmgmult = CreateConVar(
		"l4d_perkmod_stoppingpower_damagemultiplier" ,
		"0.15" ,
		"强力射击造成的额外伤害 (设定范围0.05 < 1.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hStopping_dmgmult, Convar_Stopping);
	g_flStopping_dmgmult = 0.15;

	g_hStopping_enable = CreateConVar(
		"l4d_perkmod_stoppingpower_enable" ,
		"1" ,
		"强力射击是否可在战役模式中使用, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hStopping_enable, Convar_Stopping_en);
	g_iStopping_enable = 1;

	g_hStopping_enable_sur = CreateConVar(
		"l4d_perkmod_stoppingpower_enable_survival" ,
		"1" ,
		"强力射击是否可在生存模式中使用, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hStopping_enable_sur, Convar_Stopping_en_sur);
	g_iStopping_enable_sur = 1;

	g_hStopping_enable_vs = CreateConVar(
		"l4d_perkmod_stoppingpower_enable_versus" ,
		"1" ,
		"强力射击是否可在对抗模式中使用, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hStopping_enable_vs, Convar_Stopping_en_vs);
	g_iStopping_enable_vs = 1;

	//炸弹专家
	g_hPyro_enable = CreateConVar(
		"l4d_perkmod_pyrotechnician_enable" ,
		"1" ,
		"炸弹专家是否可在战役模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hPyro_enable, Convar_Pyro_en);
	g_iPyro_enable = 1;

	g_hPyro_enable_sur = CreateConVar(
		"l4d_perkmod_pyrotechnician_enable_survival" ,
		"1" ,
		"炸弹专家是否可在生存模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hPyro_enable_sur, Convar_Pyro_en_sur);
	g_iPyro_enable_sur = 1;

	g_hPyro_enable_vs = CreateConVar(
		"l4d_perkmod_pyrotechnician_enable_versus" ,
		"1" ,
		"炸弹专家是否可在对抗模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hPyro_enable_vs, Convar_Pyro_en_vs);
	g_iPyro_enable_vs = 1;

	//精神医师
	g_hSpirit_buff = CreateConVar(
		"l4d_perkmod_spirit_bonusbuffer" ,
		"10" ,
		"精神医师倒地后起来拥有的血量 (设置范围 0 < 170)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSpirit_buff, Convar_SpiritBuff);
	g_iSpirit_buff=				30;

	g_hSpirit_cd = CreateConVar(
		"l4d_perkmod_spirit_cooldown" ,
		"60" ,
		"精神医师在战役模式中技能冷却时间 (设置范围 秒 1 < 1800)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSpirit_cd, Convar_SpiritCD);
	g_iSpirit_cd=				60;

	g_hSpirit_cd_sur = CreateConVar(
		"l4d_perkmod_spirit_cooldown_sur" ,
		"60" ,
		"精神医师在生存模式中技能冷却时间 (设置范围 秒 1 < 1800)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSpirit_cd_sur, Convar_SpiritCDsur);
	g_iSpirit_cd_sur=			60;

	g_hSpirit_cd_vs = CreateConVar(
		"l4d_perkmod_spirit_cooldown_vs" ,
		"60" ,
		"精神医师在对抗模式中技能冷却时间 (设置范围 秒 1 < 1800)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSpirit_cd_vs, Convar_SpiritCDvs);
	g_iSpirit_cd_vs=			60;

	g_hSpirit_enable = CreateConVar(
		"l4d_perkmod_spirit_enable" ,
		"1" ,
		"精神医师是否可在战役模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSpirit_enable, Convar_Spirit_en);
	g_iSpirit_enable = 1;

	g_hSpirit_enable_sur = CreateConVar(
		"l4d_perkmod_spirit_enable_survival" ,
		"1" ,
		"精神医师是否可在生存模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSpirit_enable_sur, Convar_Spirit_en_sur);
	g_iSpirit_enable_sur = 1;

	g_hSpirit_enable_vs = CreateConVar(
		"l4d_perkmod_spirit_enable_versus" ,
		"1" ,
		"精神医师是否可在对抗模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSpirit_enable_vs, Convar_Spirit_en_vs);
	g_iSpirit_enable_vs = 1;

	//快速射击
	g_hDT_rate = CreateConVar(
		"l4d_perkmod_doubletap_rate" ,
		"0.6667" ,
		"快速射击加强多少射速! (设置范围 0.2 < 0.9)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hDT_rate, Convar_DT);
	g_flDT_rate=			0.6667;

	g_hDT_freechance = CreateConVar(
		"l4d_perkmod_doubletap_freechance" ,
		"0.15" ,
		"快速射击: 开枪射击可能不消耗子弹 (设置范围 0.0 < 0.5)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hDT_freechance, Convar_DT_freechance);
	g_flDT_freechance=			0.15;

	g_hDT_enable = CreateConVar(
		"l4d_perkmod_doubletap_enable" ,
		"1" ,
		"快速射击是否可在战役模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hDT_enable, Convar_DT_en);
	g_iDT_enable = 1;

	g_hDT_enable_sur = CreateConVar(
		"l4d_perkmod_doubletap_enable_survival" ,
		"1" ,
		"快速射击是否可在生存模式中使用,0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hDT_enable_sur, Convar_DT_en_sur);
	g_iDT_enable_sur = 1;

	g_hDT_enable_vs = CreateConVar(
		"l4d_perkmod_doubletap_enable_versus" ,
		"1" ,
		"快射射击是否可在对抗模式中使用,0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hDT_enable_vs, Convar_DT_en_vs);
	g_iDT_enable_vs = 1;

	//极速上弹
	g_hSoH_rate = CreateConVar(
		"l4d_perkmod_sleightofhand_rate" ,
		"0.5714" ,
		"极速上弹上弹的速度 (设置范围 0.2 < 0.9)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSoH_rate, Convar_SoH);
	g_flSoH_rate=			0.5714;

	g_hSoH_enable = CreateConVar(
		"l4d_perkmod_sleightofhand_enable" ,
		"1" ,
		"极速上弹是否可在战役模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSoH_enable, Convar_SoH_en);
	g_iSoH_enable = 1;

	g_hSoH_enable_sur = CreateConVar(
		"l4d_perkmod_sleightofhand_enable_survival" ,
		"1" ,
		"极速上弹是否可在生存模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSoH_enable_sur, Convar_SoH_en_sur);
	g_iSoH_enable_sur = 1;

	g_hSoH_enable_vs = CreateConVar(
		"l4d_perkmod_sleightofhand_enable_versus" ,
		"1" ,
		"极速上弹是否可在对抗模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSoH_enable_vs, Convar_SoH_en_vs);
	g_iSoH_enable_vs = 1;

	//unbreakable
	g_hUnbreak_hp = CreateConVar(
		"l4d_perkmod_unbreakable_bonushealth" ,
		"20" ,
		"血量上升上升的血量 (设置范围 1 < 100)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hUnbreak_hp, Convar_Unbreak);
	g_iUnbreak_hp = 20;

	g_hUnbreak_enable = CreateConVar(
		"l4d_perkmod_unbreakable_enable" ,
		"1" ,
		"血量上升是否可在战役模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hUnbreak_enable, Convar_Unbreak_en);
	g_iUnbreak_enable = 1;

	g_hUnbreak_enable_sur = CreateConVar(
		"l4d_perkmod_unbreakable_enable_survival" ,
		"1" ,
		"血量上升是否可在生存模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hUnbreak_enable_sur, Convar_Unbreak_en_sur);
	g_iUnbreak_enable_sur = 1;

	g_hUnbreak_enable_vs = CreateConVar(
		"l4d_perkmod_unbreakable_enable_versus" ,
		"1" ,
		"血量上升是否可在对抗模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hUnbreak_enable_vs, Convar_Unbreak_en_vs);
	g_iUnbreak_enable_vs = 1;

	//药丸专家
	g_hChem_buff = CreateConVar(
		"l4d_perkmod_chemreliant_bonusbuffer" ,
		"10" ,
		"药丸专家使用药丸后给予额外的血量 (设置范围 1 < 150)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hChem_buff, Convar_Chem);
	g_iChem_buff = 10;

	g_hChem_enable = CreateConVar(
		"l4d_perkmod_chemreliant_enable" ,
		"1" ,
		"药丸专家是否可在战役模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hChem_enable, Convar_Chem_en);
	g_iChem_enable = 1;

	g_hChem_enable_sur = CreateConVar(
		"l4d_perkmod_chemreliant_enable_survival" ,
		"1" ,
		"药丸专家是否可在生存模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hChem_enable_sur, Convar_Chem_en_sur);
	g_iChem_enable_sur = 1;

	g_hChem_enable_vs = CreateConVar(
		"l4d_perkmod_chemreliant_enable_versus" ,
		"1" ,
		"药丸专家是否可在对抗模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hChem_enable_vs, Convar_Chem_en_vs);
	g_iChem_enable_vs = 1;

	//急救医师
	g_hHelpHand_timemult = CreateConVar(
		"l4d_perkmod_helpinghand_timemultiplier" ,
		"0.6" ,
		"急救医师救人速度  (设置范围 0.01 < 1.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hHelpHand_timemult, Convar_HelpTime);
	g_flHelpHand_timemult = 0.6;

	g_hHelpHand_buff = CreateConVar(
		"l4d_perkmod_helpinghand_bonusbuffer" ,
		"15" ,
		"急救医师在战役和生存模式中救援队友后给予多少生命 (设置范围 0 < 170)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hHelpHand_buff, Convar_HelpBuff);
	g_iHelpHand_buff = 15;

	g_hHelpHand_buff_vs = CreateConVar(
		"l4d_perkmod_helpinghand_bonusbuffer_vs" ,
		"10" ,
		"急救医师在对抗模式中救援队友后给予多少生命 (设置范围 0 < 170)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hHelpHand_buff_vs, Convar_HelpBuffvs);
	g_iHelpHand_buff_vs = 10;

	g_hHelpHand_enable = CreateConVar(
		"l4d_perkmod_helpinghand_enable" ,
		"1" ,
		"急救医师是否可在战役模式中使用, 0=禁用, 1=启用 " ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hHelpHand_enable, Convar_Help_en);
	g_iHelpHand_enable = 1;

	g_hHelpHand_enable_sur = CreateConVar(
		"l4d_perkmod_helpinghand_enable_survival" ,
		"1" ,
		"急救医师是否可在生存模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hHelpHand_enable_sur, Convar_Help_en_sur);
	g_iHelpHand_enable_sur = 1;

	g_hHelpHand_enable_vs = CreateConVar(
		"l4d_perkmod_helpinghand_enable_versus" ,
		"1" ,
		"急救医师是否可在对抗模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hHelpHand_enable_vs, Convar_Help_en_vs);
	g_iHelpHand_enable_vs = 1;

	g_hHelpHand_convar = CreateConVar(
		"l4d_perkmod_helpinghand_enable_convarchanges" ,
		"1" ,
		"急救医师是否会改变服务器参数; 设置为0关闭" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hHelpHand_convar, Convar_Help_convar);
	g_iHelpHand_convar = 1;

	//弹药专家
	g_hPack_ammomult = CreateConVar(
		"l4d_perkmod_packrat_ammomultiplier" ,
		"0.2" ,
		"弹药专家提升的子弹数量  (设置范围 0.01 < 1.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hPack_ammomult, Convar_Pack);
	g_flPack_ammomult = 0.2;

	g_hPack_enable = CreateConVar(
		"l4d_perkmod_packrat_enable" ,
		"1" ,
		"弹药专家是否可在战役模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hPack_enable, Convar_Pack_en);
	g_iPack_enable = 1;

	g_hPack_enable_sur = CreateConVar(
		"l4d_perkmod_packrat_enable_survival" ,
		"1" ,
		"弹药专家是否可在生存模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hPack_enable_sur, Convar_Pack_en_sur);
	g_iPack_enable_sur = 1;

	g_hPack_enable_vs = CreateConVar(
		"l4d_perkmod_packrat_enable_versus" ,
		"1" ,
		"弹药专家是否可在对抗模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hPack_enable_vs, Convar_Pack_en_vs);
	g_iPack_enable_vs = 1;

	//终极守护
	g_hHard_hpmult = CreateConVar(
		"l4d_perkmod_hardtokill_healthmultiplier" ,
		"0.5" ,
		"终极守护增加血量  (设置范围 0.01 < 3.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hHard_hpmult, Convar_Hard);
	g_flHard_hpmult = 0.5;

	g_hHard_enable = CreateConVar(
		"l4d_perkmod_hardtokill_enable" ,
		"1" ,
		"终极守护是否可在战役模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hHard_enable, Convar_Hard_en);
	g_iHard_enable = 1;

	g_hHard_enable_sur = CreateConVar(
		"l4d_perkmod_hardtokill_enable_survival" ,
		"1" ,
		"终极守护是否可在生存模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hHard_enable_sur, Convar_Hard_en_sur);
	g_iHard_enable_sur = 1;

	g_hHard_enable_vs = CreateConVar(
		"l4d_perkmod_hardtokill_enable_versus" ,
		"1" ,
		"终极守护是否可在对抗模式中使用, 0=禁用, 1=启用" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hHard_enable_vs, Convar_Hard_en_vs);
	g_iHard_enable_vs = 1;

	//中华武术家
	g_hMA_maxpenalty = CreateConVar(
		"l4d_perkmod_martialartist_maximumpenalty" ,
		"0" ,
		"中华武术家最大惩罚 (设置范围 0-6）" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hMA_maxpenalty, Convar_MA_maxpenalty);
	g_iMA_maxpenalty = 4;

	g_hMA_enable = CreateConVar(
		"l4d_perkmod_martialartist_enable" ,
		"1" ,
		"中华武术家是否可在战役模式中使用, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hMA_enable, Convar_MA_en);
	g_iMA_enable = 1;

	g_hMA_enable_sur = CreateConVar(
		"l4d_perkmod_martialartist_enable_survival" ,
		"1" ,
		"中华武术家是否可在生存模式中使用, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hMA_enable_sur, Convar_MA_en_sur);
	g_iMA_enable_sur = 1;

	g_hMA_enable_vs = CreateConVar(
		"l4d_perkmod_martialartist_enable_versus" ,
		"1" ,
		"中华武术家是否可在对抗模式中使用, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hMA_enable_vs, Convar_MA_en_vs);
	g_iMA_enable_vs = 1;

	//凌波微步
	g_hExtreme_rate = CreateConVar(
		"l4d_perkmod_extremeconditioning_rate" ,
		"1.1" ,
		"凌波微步速度 (设置范围 1.0 < 1.5)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hExtreme_rate, Convar_Extreme);
	g_flExtreme_rate = 1.1;

	g_hExtreme_enable = CreateConVar(
		"l4d_perkmod_extremeconditioning_enable" ,
		"1" ,
		"凌波微步是否可在战役模式中使用, 0=禁用, 1=开启" , 
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hExtreme_enable, Convar_Extreme_en);
	g_iExtreme_enable = 1;

	g_hExtreme_enable_sur = CreateConVar(
		"l4d_perkmod_extremeconditioning_enable_survival" ,
		"1" ,
		"凌波微步是否可在生存模式中使用, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hExtreme_enable_sur, Convar_Extreme_en_sur);
	g_iExtreme_enable_sur = 1;

	g_hExtreme_enable_vs = CreateConVar(
		"l4d_perkmod_extremeconditioning_enable_versus" ,
		"1" ,
		"凌波微步是否可在对抗模式中使用, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hExtreme_enable_vs, Convar_Extreme_en_vs);
	g_iExtreme_enable_vs = 1;

	//机枪手
	g_hLittle_enable = CreateConVar(
		"l4d_perkmod_littleleaguer_enable" ,
		"1" ,
		"机枪手是否可在战役模式中使用, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hLittle_enable, Convar_Little_en);
	g_iLittle_enable = 1;

	g_hLittle_enable_sur = CreateConVar(
		"l4d_perkmod_littleleaguer_enable_survival" ,
		"1" ,
		"机枪手是否可在生存模式中使用, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hLittle_enable_sur, Convar_Little_en_sur);
	g_iLittle_enable_sur = 1;

	g_hLittle_enable_vs = CreateConVar(
		"l4d_perkmod_littleleaguer_enable_versus" ,
		"1" ,
		"机枪手是否可在对抗模式中使用, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hLittle_enable_vs, Convar_Little_en_vs);
	g_iLittle_enable_vs = 1;



	//BOOMER  胖子
	//超级呕吐
	g_hBarf_enable = CreateConVar(
		"l4d_perkmod_barfbagged_enable" ,
		"1" ,
		"是否开启使用超级呕吐, 0=禁用, 1=启动" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hBarf_enable, Convar_Barf_en);
	g_iBarf_enable = 1;

	//黑暗来袭
	g_hBlind_cdmult = CreateConVar(
		"l4d_perkmod_blindluck_timemultiplier" ,
		"0.5" ,
		"黑暗来袭吐到后黑暗时间 默认是30=1.0 (设置范围 0.01 < 1.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hBlind_cdmult, Convar_Blind);
	g_flBlind_cdmult = 0.5;

	g_hBlind_enable = CreateConVar(
		"l4d_perkmod_blindluck_enable" ,
		"1" ,
		"是否开启使用黑暗来袭,  0=禁用, 1=启动 (提示:开启后将会修改服务器参数)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hBlind_enable, Convar_Blind_en);
	g_iBlind_enable = 1;

	//呕吐攻击
	g_hDead_dmgmult = CreateConVar(
		"l4d_perkmod_deadwreckening_damagemultiplier" ,
		"0.5" ,
		"呕吐攻击的攻击伤害 (设置范围 0.01 < 4.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hDead_dmgmult, Convar_Dead);
	g_flDead_dmgmult = 0.5;

	g_hDead_enable = CreateConVar(
		"l4d_perkmod_deadwreckening_enable" ,
		"1" ,
		"是否开启使用呕吐攻击, 0=禁用, 1=启动" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hDead_enable, Convar_Dead_en);
	g_iDead_enable = 1;

	//移动呕吐
	g_hMotion_rate = CreateConVar(
		"l4d_perkmod_motionsickness_rate" ,
		"1.25" ,
		"移动呕吐呕吐时速度 (设置范围 1.0 < 4.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hMotion_rate, Convar_Motion);
	g_flMotion_rate = 1.25;

	g_hMotion_enable = CreateConVar(
		"l4d_perkmod_motionsickness_enable" ,
		"1" ,
		"是否开启使用移动呕吐, 0=禁用, 1=启动 " ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hMotion_enable, Convar_Motion_en);
	g_iMotion_enable = 1;



	//SMOKER  长舌妇
	//超级舌头
	g_hTongue_speedmult = CreateConVar(
		"l4d_perkmod_tonguetwister_speedmultiplier" ,
		"1.5" ,
		"超级舌头射出时的速度 (设置范围 1.0 < 5.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hTongue_speedmult, Convar_TongueSpeed);
	g_flTongue_speedmult = 1.5;

	g_hTongue_pullmult = CreateConVar(
		"l4d_perkmod_tonguetwister_pullmultiplier" ,
		"1.5" ,
		"超级舌头拉人速度 (设置范围 1.0 < 5.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hTongue_pullmult, Convar_TonguePull);
	g_flTongue_pullmult = 1.5;

	g_hTongue_rangemult = CreateConVar(
		"l4d_perkmod_tonguetwister_rangemultiplier" ,
		"1.75" ,
		"超级舌头拉人范围 (设置范围 1.0 < 5.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hTongue_rangemult, Convar_TongueRange);
	g_flTongue_rangemult = 1.75;

	g_hTongue_enable = CreateConVar(
		"l4d_perkmod_tonguetwister_enable" ,
		"1" ,
		"是否开启超级舌头, 0=禁用, 1=开启 " ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hTongue_enable, Convar_Tongue_en);
	g_iTongue_enable = 1;

	//致命舌头
	g_hSqueezer_dmgmult = CreateConVar(
		"l4d_perkmod_squeezer_damagemultiplier" ,
		"0.5" ,
		"致命舌头伤害范围(设置范围 0.01 < 4.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSqueezer_dmgmult, Convar_Squeezer);
	g_flSqueezer_dmgmult = 0.5;

	g_hSqueezer_enable = CreateConVar(
		"l4d_perkmod_squeezer_enable" ,
		"1" ,
		"是否开启致命舌头, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSqueezer_enable, Convar_Squeezer_en);
	g_iSqueezer_enable = 1;

	//舌头中断
	g_hDrag_cdmult = CreateConVar(
		"l4d_perkmod_draganddrop_timemultiplier" ,
		"0.2" ,
		"舌头中断冷却时间 (设置范围 0.01 < 1.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hDrag_cdmult, Convar_Drag);
	g_flDrag_cdmult = 0.2;

	g_hDrag_enable = CreateConVar(
		"l4d_perkmod_draganddrop_enable" ,
		"1" ,
		"是否开启舌头中断, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hDrag_enable, Convar_Drag_en);
	g_iDrag_enable = 1;

	//拉人行走
	g_hSmokeItSpeed = CreateConVar(
		"l4d_perkmod_smokeit_speed" ,
		"0.21" ,
		"拉人行走时拉人速度" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	g_flSmokeItSpeed = 0.21;
	HookConVarChange(g_hSmokeItSpeed, Convar_SmokeIt_speed);

	g_hSmokeItMaxRange = CreateConVar(
		"l4d_perkmod_smokeit_tonguestretch" ,
		"950" ,
		"拉人行走时舌头最长可达范围，超过将会拉断" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	g_iSmokeItMaxRange = 950;
	HookConVarChange(g_hSmokeItMaxRange, Convar_SmokeIt_range);

	g_hSmokeIt_enable = CreateConVar(
		"l4d_perkmod_smokeit_enable" ,
		"1" ,
		"是否开启拉人行走, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSmokeIt_enable, Convar_SmokeIt_en);
	g_iSmokeIt_enable = 1;



	//HUNTER  亨特
	//瞬间压制
	g_hBody_minbound = CreateConVar(
		"l4d_perkmod_bodyslam_minbound" ,
		"10" ,
		"瞬间压制所造成的额外伤害 (设置范围 2 < 100)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hBody_minbound, Convar_Body);
	g_iBody_minbound = 10;

	g_hBody_enable = CreateConVar(
		"l4d_perkmod_bodyslam_enable" ,
		"1" ,
		"是否开启瞬间压制, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hBody_enable, Convar_Body_en);
	g_iBody_enable = 1;

	//超级杀手
	g_hEfficient_dmgmult = CreateConVar(
		"l4d_perkmod_efficientkiller_damagemultiplier" ,
		"0.2" ,
		"超级杀手造成的伤害 (设置范围 0.01 < 4.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hEfficient_dmgmult, Convar_Eff);
	g_flEfficient_dmgmult = 0.2;

	g_hEfficient_enable = CreateConVar(
		"l4d_perkmod_efficientkiller_enable" ,
		"1" ,
		"是否开启超级杀手, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hEfficient_enable, Convar_Eff_en);
	g_iEfficient_enable = 1;

	//超远袭击
	g_hGrass_rate = CreateConVar(
		"l4d_perkmod_grasshopper_rate" ,
		"1.2" ,
		"超远袭击增加的袭击距离 (设置范围 1.0 < 3.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hGrass_rate, Convar_Grass);
	g_flGrass_rate = 1.2;

	g_hGrass_enable = CreateConVar(
		"l4d_perkmod_grasshopper_enable" ,
		"1" ,
		"是否开启超远袭击, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hGrass_enable, Convar_Grass_en);
	g_iGrass_enable = 1;

	//终极杀手
	g_hSpeedDemon_rate = CreateConVar(
		"l4d_perkmod_speeddemon_rate" ,
		"1.4" ,
		"终极杀手的速度值 (设置范围 1.0 < 3.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSpeedDemon_rate, Convar_Demon);
	g_flSpeedDemon_rate = 1.4;

	g_hSpeedDemon_dmgmult = CreateConVar(
		"l4d_perkmod_speeddemon_damagemultiplier" ,
		"0.5" ,
		"终极杀手增加的伤害比例 (设置范围 0.01 < 4.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSpeedDemon_dmgmult, Convar_Demon_dmg);
	g_flSpeedDemon_dmgmult = 0.5;

	g_hSpeedDemon_enable = CreateConVar(
		"l4d_perkmod_speeddemon_enable" ,
		"1" ,
		"是否开启终极杀手, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSpeedDemon_enable, Convar_Demon_en);
	g_iSpeedDemon_enable = 1;



	//TANK   坦克
	//坦克狂化
	g_hAdrenal_punchcdmult = CreateConVar(
		"l4d_perkmod_adrenalglands_punchcooldownmultiplier" ,
		"0.5" ,
		"坦克狂化挥拳速度 (设置范围 0.01 < 1.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hAdrenal_punchcdmult, Convar_Adrenalpunchcd);
	g_flAdrenal_punchcdmult = 0.5;

	g_hAdrenal_throwcdmult = CreateConVar(
		"l4d_perkmod_adrenalglands_throwcooldownmultiplier" ,
		"0.4" ,
		"坦克狂化仍石头速度 (设置范围 0.01 < 1.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hAdrenal_throwcdmult, Convar_Adrenalthrowcd);
	g_flAdrenal_throwcdmult = 0.4;

	g_hAdrenal_enable = CreateConVar(
		"l4d_perkmod_adrenalglands_enable" ,
		"1" ,
		"是否开启坦克狂化, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hAdrenal_enable, Convar_Adrenal_en);
	g_iAdrenal_enable = 1;

	//世界主宰
	g_hJuggernaut_hp = CreateConVar(
		"l4d_perkmod_juggernaut_health" ,
		"3000" ,
		"世界主宰增加的生命值 (设置范围 1 < 99999)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hJuggernaut_hp, Convar_Jugg);
	g_iJuggernaut_hp = 3000;

	g_hJuggernaut_enable = CreateConVar(
		"l4d_perkmod_juggernaut_enable" ,
		"1" ,
		"是否开启世界主宰, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hJuggernaut_enable, Convar_Jugg_en);
	g_iJuggernaut_enable = 1;

	//代谢增强
	g_hMetabolic_speedmult = CreateConVar(
		"l4d_perkmod_metabolicboost_speedmultiplier" ,
		"1.4" ,
		"代谢增强增加的速度 (设置范围 1.01 < 3.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hMetabolic_speedmult, Convar_Met);
	g_flMetabolic_speedmult = 1.4;

	g_hMetabolic_enable = CreateConVar(
		"l4d_perkmod_metabolicboost_enable" ,
		"1" ,
		"是否开启代谢增强, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hMetabolic_enable, Convar_Met_en);
	g_iMetabolic_enable = 1;

	//召唤小弟
	g_hStorm_mobcount = CreateConVar(
		"l4d_perkmod_stormcaller_mobcount" ,
		"3" ,
		"召唤小弟召唤的数量 (设置范围 1 < 10)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hStorm_mobcount, Convar_Storm);
	g_iStorm_mobcount = 3;

	g_hStorm_enable = CreateConVar(
		"l4d_perkmod_stormcaller_enable" ,
		"1" ,
		"是否开启召唤小弟, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hStorm_enable, Convar_Storm_en);
	g_iStorm_enable = 1;

	//心动呼唤
	g_hDouble_hpmult = CreateConVar(
		"l4d_perkmod_doublethetrouble_healthmultiplier" ,
		"0.45" ,
		"心动呼唤呼唤的坦克血量比例,自身也会失去多少血 (设置范围 0.1 < 2.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hDouble_hpmult, Convar_Double);
	g_flDouble_hpmult = 0.45;

	g_hDouble_enable = CreateConVar(
		"l4d_perkmod_doublethetrouble_enable" ,
		"1" ,
		"是否开启心动呼唤, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hDouble_enable, Convar_Double_en);
	g_iDouble_enable = 1;



	//JOCKEY  猴子
	//风行者
	g_hWind_rate = CreateConVar(
		"l4d_perkmod_ridelikethewind_rate" ,
		"1.4" ,
		"风行者骑乘速度 (设置范围 1.0 < 3.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hWind_rate, Convar_Wind);
	g_flWind_rate = 1.4;

	g_hWind_enable = CreateConVar(
		"l4d_perkmod_ridelikethewind_enable" ,
		"1" ,
		"是否开启风行者, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hWind_enable, Convar_Wind_en);
	g_iWind_enable = 1;

	//骑士
	g_hCavalier_hpmult = CreateConVar(
		"l4d_perkmod_cavalier_healthmultiplier" ,
		"0.6" ,
		"骑士增加的额外血量 (设置范围 0.01 < 3.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hCavalier_hpmult, Convar_Cavalier);
	g_flCavalier_hpmult = 0.6;

	g_hCavalier_enable = CreateConVar(
		"l4d_perkmod_cavalier_enable" ,
		"1" ,
		"是否开启骑士, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hCavalier_enable, Convar_Cavalier_en);
	g_iCavalier_enable = 1;

	//终极骑士
	g_hFrogger_dmgmult = CreateConVar(
		"l4d_perkmod_frogger_damagemultiplier" ,
		"0.35" ,
		"终极骑士造成的额外伤害 (设置范围 0.01 < 4.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hFrogger_dmgmult, Convar_Frogger_dmgmult);
	g_flFrogger_dmgmult = 0.35;

	g_hFrogger_rate = CreateConVar(
		"l4d_perkmod_frogger_rate" ,
		"1.3" ,
		"终极骑士跳跃的距离 (设置范围 1.0 < 3.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hFrogger_rate, Convar_Frogger_rate);
	g_flFrogger_rate = 1.3;

	g_hFrogger_enable = CreateConVar(
		"l4d_perkmod_frogger_enable" ,
		"1" ,
		"是否开启终极骑士, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hFrogger_enable, Convar_Frogger_en);
	g_iFrogger_enable = 1;

	//恶灵骑士
	g_hGhost_alpha = CreateConVar(
		"l4d_perkmod_ghostrider_alpha" ,
		"25" ,
		"恶灵骑士隐身程度 (设置范围 0透明  < 255实体 )" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hGhost_alpha, Convar_Ghost);
	g_iGhost_alpha = 25;

	g_hGhost_enable = CreateConVar(
		"l4d_perkmod_ghostrider_enable" ,
		"1" ,
		"是否开启恶灵骑士, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hGhost_enable, Convar_Ghost_en);
	g_iGhost_enable = 1;



	//SPITTER 口水怪
	//双重喷射
	g_hTwinSF_delay = CreateConVar(
		"l4d_perkmod_twinspitfire_delay" ,
		"6" ,
		"双重喷射第二次喷射的时间 (设置范围 0.5 < 20.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hTwinSF_delay, Convar_TwinSF);
	g_flTwinSF_delay = 6.0;

	g_hTwinSF_enable = CreateConVar(
		"l4d_perkmod_twinspitfire_enable" ,
		"1" ,
		"是否开启双重喷射, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hTwinSF_enable, Convar_TwinSF_en);
	g_iTwinSF_enable = 1;

	//粘皮带骨
	g_hMegaAd_enable = CreateConVar(
		"l4d_perkmod_megaadhesive_enable" ,
		"1" ,
		"是否开启粘皮带骨, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hMegaAd_enable, Convar_MegaAd_en);
	g_iMegaAd_enable = 1;

	g_hMegaAd_slow = CreateConVar(
		"l4d_perkmod_megaadhesive_slowmultiplier" ,
		"0.6" ,
		"当幸存者碰到粘皮带骨上的速度 (设置范围 0 < 1.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hMegaAd_slow, Convar_MegaAd);
	g_flMegaAd_slow = 0.6;



	//CHARGER  牛
	//愤怒的公牛
	g_hScatter_force = CreateConVar(
		"l4d_perkmod_scatteringram_force" ,
		"1.6" ,
		"愤怒的公牛冲撞时的力量 (设置范围 1.0 < 3.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hScatter_force, Convar_Scatter_force);
	g_flScatter_force = 1.6;

	g_hScatter_hpmult = CreateConVar(
		"l4d_perkmod_scatteringram_healthmultiplier" ,
		"0.3" ,
		"愤怒的公牛给予的额外生命值 (设置范围 0.01 < 3.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hScatter_hpmult, Convar_Scatter_hpmult);
	g_flScatter_hpmult = 0.3;

	g_hScatter_enable = CreateConVar(
		"l4d_perkmod_scatteringram_enable" ,
		"1" ,
		"是否开启愤怒的公牛, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hScatter_enable, Convar_Scatter_en);
	g_iScatter_enable = 1;

	//超速冲撞
	g_hBullet_rate = CreateConVar(
		"l4d_perkmod_speedingbullet_rate" ,
		"1.5" ,
		"极速冲撞时的冲撞速度 (设置范围 1.0 < 10.0)" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hBullet_rate, Convar_Bullet);
	g_flBullet_rate = 1.5;

	g_hBullet_enable = CreateConVar(
		"l4d_perkmod_speedingbullet_enable" ,
		"1" ,
		"是否开启极速冲撞, 0=禁用, 1=开启" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hBullet_enable, Convar_Bullet_en);
	g_iBullet_enable = 1;



	//MISC  各种设置
	//电脑设置
	g_hBot_Sur1 = CreateConVar(
		"l4d_perkmod_bot_survivor1" ,
		"1,2,3" ,
		"幸存者BOT可选择主菜单技能: 1 = 强力射击, 2 = 极速上弹, 3 = 中华武术家" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );

	g_hBot_Sur2 = CreateConVar(
		"l4d_perkmod_bot_survivor2" ,
		"1,2,3" ,
		"幸存者BOT可选择副菜单技能: 1 = 血量上升, 2 = 精神医师, 3 = 急救医师" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );

	g_hBot_Sur3 = CreateConVar(
		"l4d_perkmod_bot_survivor3" ,
		"1,2" ,
		"幸存者BOT可选择辅助菜单技能: 1 = 弹药专家, 2 = 终极守护" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );

	g_hBot_Inf1 = CreateConVar(
		"l4d_perkmod_bot_boomer" ,
		"1,2,3" ,
		"Boomer Bot 可选择技能: 1 = 超级呕吐, 2 = 黑暗来袭, 3 = 呕吐攻击 " ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );

	g_hBot_Inf3 = CreateConVar(
		"l4d_perkmod_bot_smoker" ,
		"2,3" ,
		"smoker Bot 可选择技能: 1 = 超级舌头, 2 = 致命舌头, 3 = 拉人行走 " ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );

	g_hBot_Inf4 = CreateConVar(
		"l4d_perkmod_bot_hunter" ,
		"1" ,
		"hunter Bot 可选择技能: 1 =超级杀手, 2 = 终极杀手 " ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );

	g_hBot_Inf2 = CreateConVar(
		"l4d_perkmod_bot_tank" ,
		"1,2,3,4,5" ,
		"tank Bot 可选择技能: 1 = 坦克狂化, 2 = 世界主宰, 3 = 代谢增强, 4 = 召唤小弟, 5 = 心动呼唤" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );

	g_hBot_Inf5 = CreateConVar(
		"l4d_perkmod_bot_jockey" ,
		"1,2,3,4" ,
		"jockey Bot 可选择技能: 1 = 风行者, 2 = 骑士, 3 = 终极骑士, 4 = 恶灵骑士 " ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );

	g_hBot_Inf6 = CreateConVar(
		"l4d_perkmod_bot_spitter" ,
		"1,2" ,
		"spitter Bot 可选择技能: 1 = 双重喷射, 2 = 粘皮带骨 " ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );

	g_hBot_Inf7 = CreateConVar(
		"l4d_perkmod_bot_charger" ,
		"1,2" ,
		"charger Bot 可选择技能: 1 = 愤怒的公牛, 2 = 超速冲撞 " ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );

	//默认设置
	g_hSur1_default = CreateConVar(
		"l4d_perkmod_default_survivor1" ,
		"1" ,
		"幸存者默认选择主菜单技能: 1 = 强力射击, 2 = 快速射击, 3 = 极速上弹, 4 = 炸弹专家, 5 = 中华武术家" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSur1_default, Convar_Def_Sur1);
	g_iSur1_default = 1;

	g_hSur2_default = CreateConVar(
		"l4d_perkmod_default_survivor2" ,
		"1" ,
		"幸存者默认选择副菜单技能: 1 = 血量上升, 2 = 精神医师, 3 = 急救医师" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSur2_default, Convar_Def_Sur2);
	g_iSur2_default = 1;

	g_hSur3_default = CreateConVar(
		"l4d_perkmod_default_survivor3" ,
		"1" ,
		"幸存者默认选择副菜单技能: 1 = 弹药专家, 2 = 药丸专家, 3 = 终极守护" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSur3_default, Convar_Def_Sur3);
	g_iSur3_default = 1;

	g_hInf1_default = CreateConVar(
		"l4d_perkmod_default_boomer" ,
		"1" ,
		"特感默认菜单技能 Boomer: 1 = 超级呕吐, 2 = 黑暗来袭, 3 = 呕吐攻击" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hInf1_default, Convar_Def_Inf1);
	g_iInf1_default = 1;

	g_hInf2_default = CreateConVar(
		"l4d_perkmod_default_tank" ,
		"2" ,
		"特感默认菜单技能 Tank: 1 = 坦克狂化, 2 = 世界主宰, 3 = 代谢增强, 4 = 召唤小弟, 5 = 心动呼唤" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hInf2_default, Convar_Def_Inf2);
	g_iInf2_default = 2;

	g_hInf3_default = CreateConVar(
		"l4d_perkmod_default_smoker" ,
		"1" ,
		"特感默认菜单技能 Smoker: 1 = 超级舌头, 2 = 致命舌头, 3 = 拉人行走" ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hInf3_default, Convar_Def_Inf3);
	g_iInf3_default = 1;

	g_hInf4_default = CreateConVar(
		"l4d_perkmod_default_hunter" ,
		"1" ,
		"特感默认菜单技能 Hunter: 1 = 瞬间压制, 2 = 超级杀手, 3 = 超远袭击, 4 = 终极杀手, " ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hInf4_default, Convar_Def_Inf4);
	g_iInf4_default = 1;

	g_hInf5_default = CreateConVar(
		"l4d_perkmod_default_jockey" ,
		"1" ,
		"特感默认菜单技能 Jockey: " ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hInf5_default, Convar_Def_Inf5);
	g_iInf5_default = 1;

	g_hInf6_default = CreateConVar(
		"l4d_perkmod_default_spitter" ,
		"1" ,
		"特感默认菜单技能 Spitter: " ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hInf6_default, Convar_Def_Inf6);
	g_iInf6_default = 1;

	g_hInf7_default = CreateConVar(
		"l4d_perkmod_default_charger" ,
		"1" ,
		"特感默认菜单技能 Charger: " ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hInf7_default, Convar_Def_Inf7);
	g_iInf7_default = 1;



	//enable perk trees
	//-----------------
	g_hSur1_enable = CreateConVar(
		"l4d_perkmod_perktree_survivor1_enable" ,
		"1" ,
		"是否开启玩家选择主菜单技能 0=禁用 1=开启." ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSur1_enable, Convar_Sur1_en);
	g_iSur1_enable = 1;

	g_hSur2_enable = CreateConVar(
		"l4d_perkmod_perktree_survivor2_enable" ,
		"1" ,
		"是否开启玩家选择副菜单技能 0=禁用 1=开启." ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSur2_enable, Convar_Sur2_en);
	g_iSur2_enable = 1;

	g_hSur3_enable = CreateConVar(
		"l4d_perkmod_perktree_survivor3_enable" ,
		"1" ,
		"是否开启玩家选择辅助菜单技能 0=禁用 1=开启." ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hSur3_enable, Convar_Sur3_en);
	g_iSur3_enable = 1;

	g_hInf1_enable = CreateConVar(
		"l4d_perkmod_perktree_boomer_enable" ,
		"1" ,
		"是否开启玩家选择boomer菜单技能 0=禁用 1=开启." ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hInf1_enable, Convar_Inf1_en);
	g_iInf1_enable = 1;

	g_hInf2_enable = CreateConVar(
		"l4d_perkmod_perktree_tank_enable" ,
		"1" ,
		"是否开启玩家选择tank菜单技能 0=禁用 1=开启." ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hInf2_enable, Convar_Inf2_en);
	g_iInf2_enable = 1;

	g_hInf3_enable = CreateConVar(
		"l4d_perkmod_perktree_smoker_enable" ,
		"1" ,
		"是否开启玩家选择smoker菜单技能 0=禁用 1=开启." ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hInf3_enable, Convar_Inf3_en);
	g_iInf3_enable = 1;

	g_hInf4_enable = CreateConVar(
		"l4d_perkmod_perktree_hunter_enable" ,
		"1" ,
		"是否开启玩家选择hunter菜单技能 0=禁用 1=开启." ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hInf4_enable, Convar_Inf4_en);
	g_iInf4_enable = 1;

	g_hInf5_enable = CreateConVar(
		"l4d_perkmod_perktree_jockey_enable" ,
		"1" ,
		"是否开启玩家选择jockey菜单技能 0=禁用 1=开启." ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hInf5_enable, Convar_Inf5_en);
	g_iInf5_enable = 1;

	g_hInf6_enable = CreateConVar(
		"l4d_perkmod_perktree_spitter_enable" ,
		"1" ,
		"是否开启玩家选择spitter菜单技能 0=禁用 1=开启." ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hInf6_enable, Convar_Inf6_en);
	g_iInf6_enable = 1;

	g_hInf7_enable = CreateConVar(
		"l4d_perkmod_perktree_charger_enable" ,
		"1" ,
		"是否开启玩家选择charger菜单技能 0=禁用 1=开启." ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hInf7_enable, Convar_Inf7_en);
	g_iInf7_enable = 1;



	//force random perks
	g_hForceRandom = CreateConVar(
		"l4d_perkmod_forcerandomperks" ,
		"0" ,
		"是否玩家只能随机获得技能 0=禁用 1=开启." ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hForceRandom, Convar_ForceRandom);
	g_iForceRandom = 0;

	//enable random perk choice
	g_hRandomEnable = CreateConVar(
		"l4d_perkmod_randomperks_enable" ,
		"1" ,
		"1=是否允许玩家开始时随意选择技能 0=他们只能使用默认菜单技能." ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
	HookConVarChange(g_hRandomEnable, Convar_Random_en);
	g_iRandomEnable = 1;

	//misc game convars
	g_hMenuAutoShow_enable = CreateConVar(
		"l4d_perkmod_autoshowmenu" ,
		"1" ,
		"0=禁用菜单每一轮自动弹出 1=菜单每一轮开始时会自动弹出." ,
		FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY );
}
//=============================
// ConVar Changes
//=============================


//changes in base L4D convars
//---------------------------

//tracks changes in game mode
public Convar_GameMode (Handle:convar, const String:oldValue[], const String:newValue[])
{
	if (StrContains(newValue,"versus",false)!= -1
		|| StrContains(newValue,"scavenge",false)!= -1)
		g_iL4D_GameMode=2;
	else if (StrEqual(newValue,"survival",false)==true)
		g_iL4D_GameMode=1;
	else
		g_iL4D_GameMode=0;

	//----DEBUG----
	//PrintToChatAll("\x03gamemode change detected, new value: \x01%i",g_iL4D_GameMode);
}


//changes in perkmod convars
//---------------------------

//stopping power
//the enable/disable functions also call
//the checks-pre-calculate function
public Convar_Stopping (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.05)
		flF=0.05;
	else if (flF>1.0)
		flF=1.0;
	g_flStopping_dmgmult = flF;
}

public Convar_Stopping_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iStopping_enable = iI;

	Stopping_RunChecks();
}

public Convar_Stopping_en_sur (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iStopping_enable_sur = iI;

	Stopping_RunChecks();
}

public Convar_Stopping_en_vs (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iStopping_enable_vs = iI;

	Stopping_RunChecks();
}

//spirit
public Convar_SpiritBuff (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<0)
		iI=0;
	else if (iI>170)
		iI=170;
	g_iSpirit_buff = iI;
}

public Convar_SpiritCD (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<1)
		iI=1;
	else if (iI>1800)
		iI=1800;
	g_iSpirit_cd = iI;
}

public Convar_SpiritCDsur (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<1)
		iI=1;
	else if (iI>1800)
		iI=1800;
	g_iSpirit_cd_sur = iI;
}

public Convar_SpiritCDvs (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<1)
		iI=1;
	else if (iI>1800)
		iI=1800;
	g_iSpirit_cd_vs = iI;
}

public Convar_Spirit_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iSpirit_enable = iI;
}

public Convar_Spirit_en_sur (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iSpirit_enable_sur = iI;
}

public Convar_Spirit_en_vs (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iSpirit_enable_vs = iI;
}

//helping hand
public Convar_HelpTime (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.01)
		flF=0.01;
	else if (flF>1.0)
		flF=1.0;
	g_flHelpHand_timemult = flF;
}

public Convar_HelpBuff (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<1)
		iI=1;
	else if (iI>170)
		iI=170;
	g_iHelpHand_buff = iI;
}

public Convar_HelpBuffvs (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<1)
		iI=1;
	else if (iI>170)
		iI=170;
	g_iHelpHand_buff_vs = iI;
}

public Convar_Help_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iHelpHand_enable = iI;
}

public Convar_Help_en_sur (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iHelpHand_enable_sur = iI;
}

public Convar_Help_en_vs (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iHelpHand_enable_vs = iI;
}

public Convar_Help_convar (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iHelpHand_convar = iI;
}

//unbreakable
public Convar_Unbreak (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<1)
		iI=1;
	else if (iI>100)
		iI=100;
	g_iUnbreak_hp = iI;
}

public Convar_Unbreak_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iUnbreak_enable = iI;
}

public Convar_Unbreak_en_sur (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iUnbreak_enable_sur = iI;
}

public Convar_Unbreak_en_vs (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iUnbreak_enable_vs = iI;
}

//double tap
//the enable/disable functions also call
//for the run-on-game-frame-check function
public Convar_DT (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.02)
		flF=0.02;
	else if (flF>0.9)
		flF=0.9;
	g_flDT_rate = flF;
}

public Convar_DT_freechance (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.0)
		flF=0.0;
	else if (flF>0.5)
		flF=0.5;
	g_flDT_freechance = flF;
}

public Convar_DT_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iDT_enable = iI;

	DT_RunChecks();
}

public Convar_DT_en_sur (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iDT_enable_sur = iI;

	DT_RunChecks();
}

public Convar_DT_en_vs (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iDT_enable_vs = iI;

	DT_RunChecks();
}

//sleight of hand
public Convar_SoH (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.02)
		flF=0.02;
	else if (flF>0.9)
		flF=0.9;
	g_flSoH_rate = flF;
}

public Convar_SoH_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iSoH_enable = iI;
}

public Convar_SoH_en_sur (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iSoH_enable_sur = iI;
}

public Convar_SoH_en_vs (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iSoH_enable_vs = iI;
}

//chem reliant
public Convar_Chem (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<1)
		iI=1;
	else if (iI>150)
		iI=150;
	g_iChem_buff = iI;
}

public Convar_Chem_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iChem_enable = iI;
}

public Convar_Chem_en_sur (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iChem_enable_sur = iI;
}

public Convar_Chem_en_vs (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iChem_enable_vs = iI;
}

//pyrotechnician
public Convar_Pyro_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iPyro_enable = iI;
}

public Convar_Pyro_en_sur (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iPyro_enable_sur = iI;
}

public Convar_Pyro_en_vs (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iPyro_enable_vs = iI;
}

//pack rat
public Convar_Pack (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.01)
		flF=0.01;
	else if (flF>1.0)
		flF=1.0;
	g_flPack_ammomult = flF;
}

public Convar_Pack_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iPack_enable = iI;
}

public Convar_Pack_en_sur (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iPack_enable_sur = iI;
}

public Convar_Pack_en_vs (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iPack_enable_vs = iI;
}

//hard to kill
public Convar_Hard (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.01)
		flF=0.01;
	else if (flF>3.0)
		flF=3.0;
	g_flHard_hpmult = flF;
}

public Convar_Hard_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iHard_enable = iI;
}

public Convar_Hard_en_sur (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iHard_enable_sur = iI;
}

public Convar_Hard_en_vs (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iHard_enable_vs = iI;
}

//martial artist
//also rebuilds MA registry in order to
//reassign new speed values
public Convar_MA_maxpenalty (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<0)
		iI=0;
	else if (iI>6)
		iI=6;
	g_iMA_maxpenalty = iI;
	MA_Rebuild();
}

public Convar_MA_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iMA_enable = iI;
}

public Convar_MA_en_sur (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iMA_enable_sur = iI;
}

public Convar_MA_en_vs (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iMA_enable_vs = iI;
}

//extreme conditioning
public Convar_Extreme (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<1.0)
		flF=1.0;
	else if (flF>1.5)
		flF=1.5;
	g_flExtreme_rate = flF;
	Extreme_Rebuild();
}

public Convar_Extreme_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iExtreme_enable = iI;
}

public Convar_Extreme_en_sur (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iExtreme_enable_sur = iI;
}

public Convar_Extreme_en_vs (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iExtreme_enable_vs = iI;
}

//little leaguer
public Convar_Little_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iLittle_enable = iI;
}

public Convar_Little_en_sur (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iLittle_enable_sur = iI;
}

public Convar_Little_en_vs (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iLittle_enable_vs = iI;
}

//barf bagged
public Convar_Barf_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iBarf_enable = iI;
}

//blind luck
public Convar_Blind (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.01)
		flF=0.01;
	else if (flF>1.0)
		flF=1.0;
	g_flBlind_cdmult = flF;
}

public Convar_Blind_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iBlind_enable = iI;
}

//dead wreckening
public Convar_Dead (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.01)
		flF=0.01;
	else if (flF>4.0)
		flF=4.0;
	g_flDead_dmgmult = flF;
}

public Convar_Dead_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iDead_enable = iI;
}

//motion sickness
public Convar_Motion (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<1.0)
		flF=1.0;
	else if (flF>4.0)
		flF=4.0;
	g_flMotion_rate = flF;
}

public Convar_Motion_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iMotion_enable = iI;
}

//tongue twister
public Convar_TongueSpeed (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<1.0)
		flF=1.0;
	else if (flF>5.0)
		flF=5.0;
	g_flTongue_speedmult = flF;
}

public Convar_TonguePull (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<1.0)
		flF=1.0;
	else if (flF>5.0)
		flF=5.0;
	g_flTongue_pullmult = flF;
}

public Convar_TongueRange (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<1.0)
		flF=1.0;
	else if (flF>5.0)
		flF=5.0;
	g_flTongue_rangemult = flF;
}

public Convar_Tongue_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iTongue_enable = iI;
}

//squeezer
public Convar_Squeezer (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.1)
		flF=0.1;
	else if (flF>4.0)
		flF=4.0;
	g_flSqueezer_dmgmult = flF;
}

public Convar_Squeezer_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iSqueezer_enable = iI;
}

//drag and drop
public Convar_Drag (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.01)
		flF=0.01;
	else if (flF>1.0)
		flF=1.0;
	g_flDrag_cdmult = flF;
}

public Convar_Drag_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iDrag_enable = iI;
}

//smoke it
public Convar_SmokeIt_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iSmokeIt_enable = iI;
}

public Convar_SmokeIt_range (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	g_iSmokeItMaxRange = iI;
}

public Convar_SmokeIt_speed (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	g_flSmokeItSpeed = flF;
}

//efficient killer
public Convar_Eff (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.1)
		flF=0.1;
	else if (flF>4.0)
		flF=4.0;
	g_flEfficient_dmgmult = flF;
}

public Convar_Eff_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iEfficient_enable = iI;
}

//body slam
public Convar_Body (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<2)
		iI=2;
	else if (iI>100)
		iI=100;
	g_iBody_minbound = iI;
}

public Convar_Body_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iBody_enable = iI;
}

//grasshopper
public Convar_Grass (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<1.0)
		flF=1.0;
	else if (flF>3.0)
		flF=3.0;
	g_flGrass_rate = flF;
}

public Convar_Grass_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iGrass_enable = iI;
}

//speed demon
public Convar_Demon (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<1.0)
		flF=1.0;
	else if (flF>3.0)
		flF=3.0;
	g_flSpeedDemon_rate = flF;
}

public Convar_Demon_dmg (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.1)
		flF=0.1;
	else if (flF>4.0)
		flF=4.0;
	g_flSpeedDemon_dmgmult = flF;
}

public Convar_Demon_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iSpeedDemon_enable = iI;
}

//ride like the wind
public Convar_Wind (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<1.0)
		flF=1.0;
	else if (flF>3.0)
		flF=3.0;
	g_flWind_rate = flF;
}

public Convar_Wind_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iWind_enable = iI;
}

//cavalier
public Convar_Cavalier (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.0)
		flF=0.0;
	else if (flF>3.0)
		flF=3.0;
	g_flCavalier_hpmult = flF;
}

public Convar_Cavalier_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iCavalier_enable = iI;
}

//frogger
public Convar_Frogger_dmgmult (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.0)
		flF=0.0;
	else if (flF>3.0)
		flF=3.0;
	g_flFrogger_dmgmult = flF;
}

public Convar_Frogger_rate (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<1.0)
		flF=1.0;
	else if (flF>3.0)
		flF=3.0;
	g_flFrogger_rate = flF;
}

public Convar_Frogger_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iFrogger_enable = iI;
}

//ghost rider
public Convar_Ghost (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<0)
		iI=0;
	else if (iI>255)
		iI=255;
	g_iGhost_alpha = iI;
}

public Convar_Ghost_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iGhost_enable = iI;
}

//twin spitfire
public Convar_TwinSF (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.5)
		flF=0.5;
	else if (flF>20.0)
		flF=20.0;
	g_flTwinSF_delay = flF;
}

public Convar_TwinSF_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iTwinSF_enable = iI;
}

//mega adhesive
public Convar_MegaAd_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iMegaAd_enable = iI;
}

public Convar_MegaAd (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.0)
		flF=0.0;
	else if (flF>3.0)
		flF=3.0;
	g_flMegaAd_slow = flF;
}


//scattering ram
public Convar_Scatter_force (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<1.0)
		flF=1.0;
	else if (flF>3.0)
		flF=3.0;
	g_flScatter_force = flF;
}

public Convar_Scatter_hpmult (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.0)
		flF=0.0;
	else if (flF>3.0)
		flF=3.0;
	g_flScatter_hpmult = flF;
}

public Convar_Scatter_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iScatter_enable = iI;
}


//speeding bullet
public Convar_Bullet (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<1.0)
		flF=1.0;
	else if (flF>10.0)
		flF=10.0;
	g_flBullet_rate = flF;
}

public Convar_Bullet_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iBullet_enable = iI;
}


//adrenal glands
public Convar_Adrenalpunchcd (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.01)
		flF=0.01;
	else if (flF>1.0)
		flF=1.0;
	g_flAdrenal_punchcdmult = flF;
}

public Convar_Adrenalthrowcd (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.01)
		flF=0.01;
	else if (flF>1.0)
		flF=1.0;
	g_flAdrenal_throwcdmult = flF;
}

public Convar_Adrenal_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iAdrenal_enable = iI;
}

//juggernaut
public Convar_Jugg (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<1)
		iI=1;
	else if (iI>99999)
		iI=99999;
	g_iJuggernaut_hp = iI;
}

public Convar_Jugg_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iJuggernaut_enable = iI;
}

//metabolic boost
public Convar_Met (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<1.01)
		flF=1.01;
	else if (flF>3.0)
		flF=3.0;
	g_flMetabolic_speedmult = flF;
}

public Convar_Met_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iMetabolic_enable = iI;
}

//storm caller
public Convar_Storm (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<1)
		iI=1;
	else if (iI>10)
		iI=10;
	g_iStorm_mobcount = iI;
}

public Convar_Storm_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iStorm_enable = iI;
}

//double the trouble
public Convar_Double (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new Float:flF=StringToFloat(newValue);
	if (flF<0.1)
		flF=0.1;
	else if (flF>2.0)
		flF=2.0;
	g_flDouble_hpmult = flF;
}

public Convar_Double_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;
	g_iDouble_enable = iI;
}

//default perks
public Convar_Def_Sur1 (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<=0)
		iI=1;
	else if (iI>5)
		iI=5;

	g_iSur1_default=iI;
}

public Convar_Def_Sur2 (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<=0)
		iI=1;
	else if (iI>3)
		iI=3;

	g_iSur2_default=iI;
}

public Convar_Def_Sur3 (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<=0)
		iI=1;
	else if (iI>3)
		iI=3;

	g_iSur3_default=iI;
}

public Convar_Def_Inf1 (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<=0)
		iI=1;
	else if (iI>3)
		iI=3;

	g_iInf1_default=iI;
}

public Convar_Def_Inf2 (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<=0)
		iI=1;
	else if (iI>5)
		iI=5;

	g_iInf2_default=iI;
}

public Convar_Def_Inf3 (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<=0)
		iI=1;
	else if (iI>3)
		iI=3;

	g_iInf3_default=iI;
}

public Convar_Def_Inf4 (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<=0)
		iI=1;
	else if (iI>5)
		iI=5;

	g_iInf4_default=iI;
}

public Convar_Def_Inf5 (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<=0)
		iI=1;
	else if (iI>5)
		iI=5;

	g_iInf5_default=iI;
}

public Convar_Def_Inf6 (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<=0)
		iI=1;
	else if (iI>5)
		iI=5;

	g_iInf6_default=iI;
}

public Convar_Def_Inf7 (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI<=0)
		iI=1;
	else if (iI>5)
		iI=5;

	g_iInf7_default=iI;
}

//force random perks
public Convar_ForceRandom (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;

	g_iForceRandom=iI;
}

//enable random perk choice
public Convar_Random_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;

	g_iRandomEnable=iI;
}

//perk trees
public Convar_Sur1_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;

	g_iSur1_enable=iI;

	RunChecksAll();
}

public Convar_Sur2_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;

	g_iSur2_enable=iI;
	RunChecksAll();
}

public Convar_Sur3_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;

	g_iSur3_enable=iI;
	RunChecksAll();
}

public Convar_Inf1_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;

	g_iInf1_enable=iI;
	RunChecksAll();
}

public Convar_Inf2_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;

	g_iInf2_enable=iI;
	RunChecksAll();
}

public Convar_Inf3_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;

	g_iInf3_enable=iI;
	RunChecksAll();
}

public Convar_Inf4_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;

	g_iInf4_enable=iI;
	RunChecksAll();
}

public Convar_Inf5_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;

	g_iInf5_enable=iI;
	RunChecksAll();
}

public Convar_Inf6_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;

	g_iInf6_enable=iI;
	RunChecksAll();
}

public Convar_Inf7_en (Handle:convar, const String:oldValue[], const String:newValue[])
{
	new iI=StringToInt(newValue);
	if (iI==0)
		iI=0;
	else
		iI=1;

	g_iInf7_enable=iI;
	RunChecksAll();
}





//====================================================
//====================================================
//					P	E	R	K	S
//====================================================
//====================================================



//=============================
// Events Directly related to perks
//=============================

//this trigger only runs on players, not common infected
public Action:Event_PlayerHurtPre (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iAtt=GetClientOfUserId(GetEventInt(event,"attacker"));
	new iVic=GetClientOfUserId(GetEventInt(event,"userid"));

	if (iVic==0) return Plugin_Continue;

	new iType=GetEventInt(event,"type");
	new iDmgOrig=GetEventInt(event,"dmg_health");

	//----DEBUG----
	//new String:sWeapon[128];
	//GetEventString(event,"weapon",sWeapon,128);
	//PrintToChatAll("\x03attacker:\x01%i\x03 weapon:\x01%s\x03 type:\x01%i\x03 amount: \x01%i",iAtt,sWeapon,iType,iDmgOrig);


	//check for dead wreckening damage add for zombies
	if (DeadWreckening_DamageAdd(iAtt,iVic,iType,iDmgOrig)==1)
		return Plugin_Continue;

	if (iAtt==0) return Plugin_Continue;

	new iTA=GetClientTeam(iAtt);
	decl String:stWpn[16];
	GetEventString(event,"weapon",stWpn,16);

	//----DEBUG----
	//if (iTA==2) PrintToChatAll("\x03weapon:\x01%s\x03 type:\x01%i",stWpn,iType);

	//if damage is from survivors to a non-survivor,
	//check for damage add (stopping power)
	if (Stopping_DamageAdd(iAtt,iVic,iTA,iDmgOrig,stWpn)==1)
		return Plugin_Continue;

	//otherwise, check for infected damage add types
	//(body slam, efficient killer, squeezer)

	//...check for body slam
	if (BodySlam_DamageAdd(iAtt,iVic,iTA,iType,stWpn,iDmgOrig)==1)
		return Plugin_Continue;

	//run speed demon checks
	if (SpeedDemon_DamageAdd(iAtt,iVic,iTA,iType,stWpn,iDmgOrig)==1)
		return Plugin_Continue;

	//run efficient killer checks
	if (EfficientKiller_DamageAdd(iAtt,iVic,iTA,iType,stWpn,iDmgOrig)==1)
		return Plugin_Continue;

	//check for squeezer
	if (Squeezer_DamageAdd(iAtt,iVic,iTA,stWpn,iDmgOrig)==1)
		return Plugin_Continue;

	//run mega adhesive checks
	if (MegaAd_SlowEffect (iAtt, iVic, stWpn)==1)
		return Plugin_Continue;

	//run frogger checks
	if (Frogger_DamageAdd(iAtt,iVic,iTA,stWpn,iDmgOrig)==1)
		return Plugin_Continue;

	return Plugin_Continue;
}

public Event_Incap (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));

	if (iCid==0) return;

	if (GetClientTeam(iCid) == 2
		&& GetEntData(iCid,g_iIncapO) != 0 )
		g_iPIncap[iCid]=1;

	HardToKill_OnIncap(iCid);
}

//called when player is healed
public Event_PlayerHealed (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"subject"));
	if (iCid==0 || g_iConfirm[iCid]==0) return;

	Unbreakable_OnHeal(iCid);
}

//called when survivor spawns from closet
public Event_PlayerRescued (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"victim"));
	if (iCid==0 || g_iConfirm[iCid]==0)
		return;

	//reset vars related to spirit perk
	g_iMyDisabler[iCid] = -1;
	g_iPIncap[iCid]=0;
	g_iSpiritCooldown[iCid]=0;
	//reset var related to blind luck perk
	SetEntProp(iCid, Prop_Send, "m_iHideHUD", 0);
	//rebuilds double tap registry
	CreateTimer(0.3,Delayed_Rebuild,0);

	//checks for unbreakable health bonus
	Unbreakable_OnRescue(iCid);
	//check for pyrotechnician bonus grenade
	Event_Confirm_Grenadier (iCid);
	//check for chem reliant bonus pills
	Event_Confirm_ChemReliant(iCid);
}

//on game frame
public OnGameFrame()
{
	//if frames aren't being processed,
	//don't bother - otherwise we get LAG
	//or even disconnects on map changes, etc...
	
	if (IsServerProcessing()==false
		|| g_bIsLoading == true
		|| g_bIsRoundStart == true)
		return;

	DT_OnGameFrame();
	MA_OnGameFrame();
	Adrenal_OnGameFrame();
}

//on reload
public Event_Reload (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid==0)
		return;

	SoH_OnReload(iCid);
}

//on weapon fire
public Event_WeaponFire (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid==0)
		return;

	decl String:stWpn[24];
	GetEventString(event,"weapon",stWpn,24);

	Pyro_OnWeaponFire(iCid,stWpn);
	DT_OnWeaponFire(iCid,stWpn);
}
//on drug use
public Action:Event_PillsUsed (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"subject"));
	if (iCid==0) return Plugin_Continue;

	Chem_OnDrugUsed(iCid);

	return Plugin_Continue;
}

//on revive begin
public Action:Event_ReviveBeginPre (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));

	if (iCid==0) return Plugin_Continue;

	HelpHand_OnReviveBegin (iCid);

	return Plugin_Continue;
}

//on revive end
public Event_ReviveSuccess (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	new iSub=GetClientOfUserId(GetEventInt(event,"subject"));

	if (iCid==0 || iSub==0) return;

	new iLedge=GetEventInt(event,"ledge_hang");
	//player is labelled as no longer incapped
	g_iPIncap[iSub]=0;

	Unbreakable_OnRevive(iSub, iLedge);
	HelpHand_OnReviveSuccess(iCid,iSub,iLedge);
}

//detects when a person is hanging from a ledge
public Event_LedgeGrab (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));

	if (iCid==0) return;

	//----DEBUG----
	//PrintToChatAll("\x03spirit ledge grab detected, client: \x01%i",iCid);

	g_iPIncap[iCid]=1;
	g_iMyDisabler[iCid] = 0;
}

public Action:Event_AbilityUsePre (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid==0 || g_iConfirm[iCid]==0) return Plugin_Continue;
	decl String:stAb[24];
	GetEventString(event,"ability",stAb,24);

	//----DEBUG----
	//PrintToChatAll("\x03ability used: \x01%s", st_ab);

	TongueTwister_OnAbilityUse(iCid,stAb);

	return Plugin_Continue;
}

public Event_AbilityUse (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid==0)
		return;

	decl String:stAb[24];
	GetEventString(event,"ability",stAb,24);

	//----DEBUG----
	//PrintToChatAll("\x03ability used: \x01%s", stAb);

	if (Grass_OnAbilityUse(iCid,stAb)==1)
		return;

	if (Bullet_OnAbilityUse(iCid,stAb)==1)
		return;
}

public Event_Jump (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid==0)
		return;

	Frogger_OnJump(iCid);
}

//on becoming slimed, check if player will lose hud
public Event_PlayerNowIt (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iAtt=GetClientOfUserId(GetEventInt(event,"attacker"));
	new iVic=GetClientOfUserId(GetEventInt(event,"userid"));

	if (iAtt==0 || iVic==0) return;

	//----DEBUG----
	//PrintToChatAll("\x03slimed detected, victim/client: \x01%i\x03, attacker: \x01%i",iVic,iAtt);

	//tell plugin another one got slimed (pungent)
	g_iSlimed++;
	//update plugin var for who vomited last (dead wreckening)
	g_iSlimerLast=iAtt;

	//check for blind luck
	BlindLuck_OnIt(iAtt,iVic);

	//check for barf bagged
	BarfBagged_OnIt(iAtt);

	CreateTimer(15.0,PlayerNoLongerIt,iVic);
}

public Action:Event_TongueGrabPre (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	new iVic = GetClientOfUserId(GetEventInt(event,"victim"));
	if (iCid==0) return Plugin_Continue;

	//spirit perk, tell plugin player is disabled by smoker
	g_iMyDisabler[iVic] = iCid;
	//+Inf, tell plugin attacker is disabling
	g_iMyDisableTarget[iCid] = iVic;

	TongueTwister_OnTongueGrab(iCid);
	Drag_OnTongueGrab(iCid);
	SmokeIt_OnTongueGrab(iCid, iVic);

	return Plugin_Continue;
}

public Event_TongueRelease (Handle:event, const String:name[], bool:dontBroadcast)
{
	//+Inf, tell plugin attacker is no longer disabling
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid!=0) g_iMyDisableTarget[iCid] = -1;
	//tell plugin player is free
	new iVic=GetClientOfUserId(GetEventInt(event,"victim"));
	if (iVic!=0) g_iMyDisabler[iVic] = -1;

	TongueTwister_OnTongueRelease();
	SmokeIt_OnTongueRelease(iCid);
}

public Event_TongueRelease_novictimid (Handle:event, const String:name[], bool:dontBroadcast)
{
	//+Inf, tell plugin attacker is no longer disabling
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid!=0) g_iMyDisableTarget[iCid] = -1;
	//tell plugin player is free
	//new iVic=GetClientOfUserId(GetEventInt(event,"victim"));
	//if (iVic!=0) g_iMyDisabler[iVic] = -1;

	TongueTwister_OnTongueRelease();
	SmokeIt_OnTongueRelease(iCid);
}

public Event_TongueRelease_newsmokerid (Handle:event, const String:name[], bool:dontBroadcast)
{
	//+Inf, tell plugin attacker is no longer disabling
	new iCid=GetClientOfUserId(GetEventInt(event,"smoker"));
	if (iCid!=0) g_iMyDisableTarget[iCid] = -1;
	//tell plugin player is free
	new iVic=GetClientOfUserId(GetEventInt(event,"victim"));
	if (iVic!=0) g_iMyDisabler[iVic] = -1;

	TongueTwister_OnTongueRelease();
	SmokeIt_OnTongueRelease(iCid);
}

public Event_PounceLanded (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iAtt=GetClientOfUserId(GetEventInt(event,"userid"));
	new iVic=GetClientOfUserId(GetEventInt(event,"victim"));

	if (iVic==0 || iAtt==0) return;

	//----DEBUG----
	//PrintToChatAll("\x03pounce land detected, client: \x01%i\x03, victim: \x01%i",iAtt,iVic);

	//spirit victim state is disabled by hunter
	g_iMyDisabler[iVic] = iAtt;
	//+Inf, attacker is disabling someone
	g_iMyDisableTarget[iAtt] = iVic;
}

public Event_PounceStop (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iAtt=GetClientOfUserId(GetEventInt(event,"userid"));
	new iVic=GetClientOfUserId(GetEventInt(event,"victim"));

	if (iVic==0 || iAtt==0) return;

	//----DEBUG----
	//PrintToChatAll("\x03pounce stop detected, attacker: \x01%i\x03, victim: \x01%i",iAtt,iVic);

	//victim is no longer disabled
	g_iMyDisabler[iVic] = -1;
	//+Inf, attacker no longer disabling
	g_iMyDisableTarget[iAtt] = -1;
}

public Event_JockeyRide (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iAtt=GetClientOfUserId(GetEventInt(event,"userid"));
	new iVic=GetClientOfUserId(GetEventInt(event,"victim"));

	if (iVic==0 || iAtt==0) return;

	//----DEBUG----
	//PrintToChatAll("\x03ride start detected, client: \x01%i\x03, victim: \x01%i",iAtt,iVic);

	//spirit victim state is disabled
	g_iMyDisabler[iVic] = iAtt;
	//+Inf, attacker is disabling someone
	g_iMyDisableTarget[iAtt] = iVic;

	Wind_OnRideStart(iAtt,iVic);
}

public Event_JockeyRideEnd (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iAtt=GetClientOfUserId(GetEventInt(event,"userid"));
	new iVic=GetClientOfUserId(GetEventInt(event,"victim"));

	if (iVic==0 || iAtt==0) return;

	//----DEBUG----
	//PrintToChatAll("\x03ride end detected, attacker: \x01%i\x03, victim: \x01%i",iAtt,iVic);

	//victim is no longer disabled
	g_iMyDisabler[iVic] = -1;
	//+Inf, attacker no longer disabling
	g_iMyDisableTarget[iAtt] = -1;

	Wind_OnRideEnd(iAtt,iVic);

	//since ride like the wind changes the survivor's speeds,
	//reapply extreme conditioning if necessary
	Extreme_Rebuild();
}

public Event_ChargerPummelStart (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iAtt=GetClientOfUserId(GetEventInt(event,"userid"));
	new iVic=GetClientOfUserId(GetEventInt(event,"victim"));

	if (iVic==0 || iAtt==0) return;

	//----DEBUG----
	//PrintToChatAll("\x03ride start detected, client: \x01%i\x03, victim: \x01%i",iAtt,iVic);

	//spirit victim state is disabled
	g_iMyDisabler[iVic] = iAtt;
	//+Inf, attacker is disabling someone
	g_iMyDisableTarget[iAtt] = iVic;
}

public Event_ChargerPummelEnd (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iAtt=GetClientOfUserId(GetEventInt(event,"userid"));
	new iVic=GetClientOfUserId(GetEventInt(event,"victim"));

	if (iVic==0 || iAtt==0) return;

	//----DEBUG----
	//PrintToChatAll("\x03ride end detected, attacker: \x01%i\x03, victim: \x01%i",iAtt,iVic);

	//victim is no longer disabled
	g_iMyDisabler[iVic] = -1;
	//+Inf, attacker no longer disabling
	g_iMyDisableTarget[iAtt] = -1;
}

public Event_ChargerImpact (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iAtt=GetClientOfUserId(GetEventInt(event,"userid"));
	new iVic=GetClientOfUserId(GetEventInt(event,"victim"));

	if (iVic==0 || iAtt==0) return;

	//----DEBUG----
	//PrintToChatAll("\x03charger impact detected, attacker: \x01%i\x03, victim: \x01%i",iAtt,iVic);

	Scatter_OnImpact(iAtt,iVic);
}

public Event_ChargerChargeEnd (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));

	if (iCid==0) return;

	//----DEBUG----
	//PrintToChatAll("\x03charger charge end detected, attacker: \x01%i\x03, victim: \x01%i",iAtt,iVic);

	SetEntDataFloat(iCid, g_iLaggedMovementO, 1.0, true);
}

//** a very important event! =P
public Event_PlayerSpawn (Handle:event, const String:name[], bool:dontBroadcast)
{
	//stop if game hasn't finished loading
	if (g_bIsLoading == true
		|| g_bIsRoundStart == true)
		return;

	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));

	//show the perk menu if their perks are unconfirmed
	if (IsClientInGame(iCid)==true
		&& IsFakeClient(iCid)==false
		&& g_iConfirm[iCid]==0)
		CreateTimer(3.0,Timer_ShowTopMenu,iCid);

	SetEntDataFloat(iCid,g_iLaggedMovementO, 1.0 ,true);
	TwinSF_ResetShotCount(iCid);

	//check survivors for max health
	//they probably don't have any confirmed perks
	//since they just spawned, so set max to 100
	if (GetClientTeam(iCid)==2)
	{
		if ( GetEntProp(iCid,Prop_Data,"m_iHealth") > 100 )
			SetEntProp(iCid,Prop_Data,"m_iHealth", 100 );

		//set survivor bot's perks
		if (IsFakeClient(iCid)==true)
		{
			g_iConfirm[iCid]=1;
			g_iSur1[iCid] = Bot_Sur1_PickRandom();
			g_iSur2[iCid] = Bot_Sur2_PickRandom();
			g_iSur3[iCid] = Bot_Sur3_PickRandom();

			//----DEBUG----
			//PrintToChatAll("\x03survivor bot 1: \x01%i\x03, 2:\x01%i",g_iSur1[iCid],g_iSur2[iCid]);
		}

		//----DEBUG----
		//PrintToChatAll("\x03spawned survivor \x01%i\x03 health \x01%i", iCid, GetEntProp(iCid,Prop_Data,"m_iHealth") );

		return;
	}

	new iClass = GetEntData(iCid, g_iClassO);

	//check for smoker first
	if (iClass == 1)
	{
		//----DEBUG----
		//PrintToChatAll("\x03smoker model detected");

		//run a max health check before
		//doing anything else
		new iMaxHP = GetConVarInt(FindConVar("z_gas_health"));
		if ( GetEntProp(iCid,Prop_Data,"m_iHealth") > iMaxHP)
			SetEntProp(iCid,Prop_Data,"m_iHealth", iMaxHP );

		//set bot perks
		if (IsFakeClient(iCid)==true)
		{
			g_iInf3[iCid] = Bot_Inf3_PickRandom();
			g_iConfirm[iCid]=1;

			//----DEBUG----
			//PrintToChatAll("\x03-smoker bot perk \x01%i",g_iInf3[iCid]);
		}

		//----DEBUG----
		//PrintToChatAll("\x03spawned smoker \x01%i\x03 health \x01%i\x03, maxhp \x01%i", iCid, GetEntProp(iCid,Prop_Data,"m_iHealth"), iMaxHP );

		TongueTwister_OnSpawn(iCid);
		Drag_OnSpawn(iCid);

		return;
	}

	//then check for hunter
	else if (iClass == 3)
	{
		//run a max health check before
		//doing anything else
		new iMaxHP = GetConVarInt(FindConVar("z_hunter_health"));
		if ( GetEntProp(iCid,Prop_Data,"m_iHealth") > iMaxHP)
			SetEntProp(iCid,Prop_Data,"m_iHealth", iMaxHP );

		//set bot perks
		if (IsFakeClient(iCid)==true)
		{
			g_iInf4[iCid] = Bot_Inf4_PickRandom();
			g_iConfirm[iCid]=1;

			//----DEBUG----
			//PrintToChatAll("\x03-hunter bot perk \x01%i",g_iInf4[iCid]);
		}

		//----DEBUG----
		//PrintToChatAll("\x03spawned hunter \x01%i\x03 health \x01%i\x03, maxhp \x01%i", iCid, GetEntProp(iCid,Prop_Data,"m_iHealth"), iMaxHP );

		SpeedDemon_OnSpawn(iCid);

		return;
	}

	//lastly, check for boomer
	else if (iClass == 2)
	{
		//run a max health check before
		//doing anything else
		new iMaxHP = GetConVarInt(FindConVar("z_exploding_health"));
		if ( GetEntProp(iCid,Prop_Data,"m_iHealth") > iMaxHP)
			SetEntProp(iCid,Prop_Data,"m_iHealth", iMaxHP );

		//set bot perks
		if (IsFakeClient(iCid)==true)
		{
			g_iInf1[iCid] = Bot_Inf1_PickRandom();
			g_iConfirm[iCid]=1;

			//----DEBUG----
			//PrintToChatAll("\x03-boomer bot perk \x01%i",g_iInf1[iCid]);
		}

		//----DEBUG----
		//PrintToChatAll("\x03spawned boomer \x01%i\x03 health \x01%i\x03, maxhp \x01%i", iCid, GetEntProp(iCid,Prop_Data,"m_iHealth"), iMaxHP );

		Motion_OnSpawn(iCid);
		BlindLuck_OnSpawn(iCid);

		return;
	}

	//check for spitter
	else if (iClass == 4
		&& g_iL4D_12 == 2)
	{
		new iMaxHP = GetConVarInt(FindConVar("z_spitter_health"));
		if ( GetEntProp(iCid,Prop_Data,"m_iHealth") > iMaxHP)
			SetEntProp(iCid,Prop_Data,"m_iHealth", iMaxHP );

		//----DEBUG----
		//PrintToChatAll("\x03spitter spawned");

		//set bot perks
		if (IsFakeClient(iCid)==true)
		{
			g_iInf6[iCid] = Bot_Inf6_PickRandom();
			g_iConfirm[iCid]=1;

			//----DEBUG----
			//PrintToChatAll("\x03-spitter bot perk \x01%i",g_iInf1[iCid]);
		}

		//----DEBUG----
		//PrintToChatAll("\x03spawned spitter \x01%i\x03 health \x01%i\x03, maxhp \x01%i", iCid, GetEntProp(iCid,Prop_Data,"m_iHealth"), iMaxHP );

		TwinSF_OnSpawn(iCid);

		return;
	}

	//check for jockey
	else if (iClass == 5
		&& g_iL4D_12 == 2)
	{
		new iMaxHP = GetConVarInt(FindConVar("z_jockey_health"));
		if ( GetEntProp(iCid,Prop_Data,"m_iHealth") > iMaxHP)
			SetEntProp(iCid,Prop_Data,"m_iHealth", iMaxHP );

		//set bot perks
		if (IsFakeClient(iCid)==true)
		{
			g_iInf5[iCid] = Bot_Inf5_PickRandom();
			g_iConfirm[iCid]=1;

			//----DEBUG----
			//PrintToChatAll("\x03-jockey bot perk \x01%i",g_iInf1[iCid]);
		}

		//----DEBUG----
		//PrintToChatAll("\x03spawned jockey \x01%i\x03 health \x01%i\x03, maxhp \x01%i", iCid, GetEntProp(iCid,Prop_Data,"m_iHealth"), iMaxHP );

		Cavalier_OnSpawn(iCid);
		Ghost_OnSpawn(iCid);

		return;
	}

	//check for charger
	else if (iClass == 6
		&& g_iL4D_12 == 2)
	{
		new iMaxHP = GetConVarInt(FindConVar("z_charger_health"));
		if ( GetEntProp(iCid,Prop_Data,"m_iHealth") > iMaxHP)
			SetEntProp(iCid,Prop_Data,"m_iHealth", iMaxHP );

		//----DEBUG----
		//PrintToChatAll("\x03charger spawned");

		//set bot perks
		if (IsFakeClient(iCid)==true)
		{
			g_iInf7[iCid] = Bot_Inf7_PickRandom();
			g_iConfirm[iCid]=1;

			//----DEBUG----
			//PrintToChatAll("\x03-charger bot perk \x01%i",g_iInf1[iCid]);
		}

		//----DEBUG----
		//PrintToChatAll("\x03spawned charger \x01%i\x03 health \x01%i\x03, maxhp \x01%i", iCid, GetEntProp(iCid,Prop_Data,"m_iHealth"), iMaxHP );

		Scatter_OnSpawn(iCid);

		return;
	}
}

//if item that was picked up is a grenade type, set carried amount in var
public Event_ItemPickup (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid==0) return;
	if (g_iConfirm[iCid]==0)
		return;

	new String:stWpn[24];
	GetEventString(event,"item",stWpn,24);

	//check for grenadier perk
	Pyro_Pickup(iCid,stWpn);

	//check for pack rat perk
	PR_Pickup(iCid, stWpn);
}

//set default perks for connecting players
public Event_PConnect(Handle:event, const String:name[], bool:dontBroadcast)
{
	//stop if game is loading
	if (g_bIsLoading == true
		|| g_bIsRoundStart == true)
		return;

	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid==0) return;

	//if any of the perks are set to 0, set default values
	if (g_iSur1[iCid]==0)
		g_iSur1[iCid] = g_iSur1_default;
	if (g_iSur2[iCid]==0)
		g_iSur2[iCid] = g_iSur2_default;
	if (g_iSur3[iCid]==0)
		g_iSur3[iCid] = g_iSur3_default;
	if (g_iInf1[iCid]==0)
		g_iInf1[iCid] = g_iInf1_default;
	if (g_iInf2[iCid]==0)
		g_iInf2[iCid] = g_iInf2_default;
	if (g_iInf3[iCid]==0)
		g_iInf3[iCid] = g_iInf3_default;
	if (g_iInf4[iCid]==0)
		g_iInf4[iCid] = g_iInf4_default;
	if (g_iInf5[iCid]==0)
		g_iInf5[iCid] = g_iInf5_default;
	if (g_iInf6[iCid]==0)
		g_iInf6[iCid] = g_iInf6_default;
	if (g_iInf7[iCid]==0)
		g_iInf7[iCid] = g_iInf7_default;
	g_iConfirm[iCid]=0;
	g_iGren[iCid]=0;
	g_iGrenThrow[iCid]=0;
	g_iGrenType[iCid]=0;
	g_iMyDisabler[iCid] = -1;
	g_iMyDisableTarget[iCid] = -1;
	g_iPIncap[iCid]=0;
	g_iSpiritCooldown[iCid]=0;

}

//reset perk values when disconnected
//closes timer for spirit cooldown
//and rebuilds DT registry
public Event_PDisconnect(Handle:event, const String:name[], bool:dontBroadcast)
{
	if (g_bIsLoading == true
		|| g_bIsRoundStart == true)
		return;

	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid==0) return;
	g_iSur1[iCid]=0;
	g_iSur2[iCid]=0;
	g_iSur3[iCid]=0;
	g_iInf1[iCid]=0;
	g_iInf2[iCid]=0;
	g_iInf3[iCid]=0;
	g_iInf4[iCid]=0;
	g_iInf5[iCid]=0;
	g_iInf6[iCid]=0;
	g_iInf7[iCid]=0;
	g_iConfirm[iCid]=0;
	g_iGren[iCid]=0;
	g_iGrenThrow[iCid]=0;
	g_iGrenType[iCid]=0;
	g_iMyDisabler[iCid] = -1;
	g_iMyDisableTarget[iCid] = -1;
	g_iPIncap[iCid]=0;
	g_iSpiritCooldown[iCid]=0;

	if (g_iSpiritTimer[iCid]!=INVALID_HANDLE)
	{
		KillTimer(g_iSpiritTimer[iCid]);
		g_iSpiritTimer[iCid]=INVALID_HANDLE;
	}
	RebuildAll();
	TwinSF_ResetShotCount(iCid);
}

//call menu on first spawn, otherwise set default values for bots
public Event_PlayerFirstSpawn (Handle:event, const String:name[], bool:dontBroadcast)
{
	if (g_bIsLoading == true
		|| g_bIsRoundStart == true)
		return;

	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid==0) return;
	if (g_iConfirm[iCid]==0
		&& IsFakeClient(iCid)==false)
	{
		CreateTimer(3.0,Timer_ShowTopMenu,iCid);
		PrintHintText(iCid,"%t", "WelcomeMessageHint");
		PrintToChat(iCid,"\x03[心动] %t", "WelcomeMessageChat");
	}
}

//checks to show perks menu on roundstart
//and resets various vars to default
public Event_RoundStart (Handle:event, const String:name[], bool:dontBroadcast)
{
	//tell plugin to not run this function repeatedly until we're done
	if (g_bIsRoundStart == true)
		return;
	else
		g_bIsRoundStart = true;

	//----DEBUG----
	//PrintToChatAll("\x03round start detected");

	//for l4d1, need to change some offsets
	if (g_iL4D_12 == 1)
	{
		//L4D1, Windows
		g_iNextActO = 888;
		g_iAttackTimerO = 1488;
	}
	else if (g_iL4D_12 == 2)
	{
		//check for Linux or Windows by checking
		//a base offset, NextPrimaryAttack for weapons
		//--------------------------------------------
		//numbers have changed since last valve update
		//usually +4 - next activation timer changed for
		//both windows and linux, attack timer changed
		//only for linux, next primary attack changed
		//for both windows and linux

		if (g_iNextPAttO == 5088)
		{
			//L4D2, Windows
			g_iNextActO = 1068;
			g_iAttackTimerO = 5436;
		}
		else if (g_iNextPAttO == 5104)
		{
			//L4D2, Linux
			g_iNextActO = 1092;
			g_iAttackTimerO = 5448;
		}
	}

	//AutoExecConfig(false , "perkmod");

	for (new iI=1 ; iI<=MaxClients ; iI++)
	{
		//----DEBUG----
		//PrintToChatAll("\x03-cycle %i",iI);

		//reset vars related to spirit perk
		g_iPIncap[iI]=0;
		g_iSpiritCooldown[iI]=0;
		//reset var related to pack rat perk
		g_bPRalreadyApplying[iI] = false;
		//reset var related to various hunter/smoker perks
		g_iMyDisabler[iI] = -1;
		g_iMyDisableTarget[iI] = -1;

		//reset var pointing to client's spirit timer
		//and close the timer handle
		if (g_iSpiritTimer[iI]!=INVALID_HANDLE)
		{
			KillTimer(g_iSpiritTimer[iI]);
			g_iSpiritTimer[iI]=INVALID_HANDLE;
		}

		TwinSF_ResetShotCount(iI);

		//before we run any functions on players
		//check if the game has any players to prevent
		//stupid error messages cropping up on the server
		if (IsServerProcessing()==false)
			continue;

		//only run these commands if player is in-game
		if (IsClientInGame(iI)==true)
		{
			//reset run speeds for martial artist
			SetEntDataFloat(iI,g_iLaggedMovementO, 1.0 ,true);

			if (IsFakeClient(iI)==true) continue;
			//show the perk menu if their perks are unconfirmed
			if (g_iConfirm[iI]==0)
				CreateTimer(3.0,Timer_ShowTopMenu,iI);
			//reset var related to blind luck perk
			//SendConVarValue(iI,hCvar,"0");
			SetEntProp(iI, Prop_Send, "m_iHideHUD", 0);
		}

	}

	decl Handle:hCvar;

	//reset vomit vars

	if (g_iInf1_enable==1
		&& g_iMotion_enable==1)
	{
		hCvar=FindConVar("z_vomit_fatigue");
		ResetConVar(hCvar,false,false);
		g_flVomitFatigue=GetConVarFloat(hCvar);
	}

	//reset tongue vars

	if (g_iInf3_enable==1
		&& g_iTongue_enable==1)
	{
		hCvar=FindConVar("tongue_victim_max_speed");
		ResetConVar(hCvar,false,false);
		g_flTongueSpeed=GetConVarFloat(hCvar);

		hCvar=FindConVar("tongue_range");
		ResetConVar(hCvar,false,false);
		g_flTongueRange=GetConVarFloat(hCvar);

		hCvar=FindConVar("tongue_fly_speed");
		ResetConVar(hCvar,false,false);
		g_flTongueFlySpeed=GetConVarFloat(hCvar);
	}

	if (g_iInf3_enable==1
		&& g_iDrag_enable==1)
	{
		ResetConVar(FindConVar("tongue_allow_voluntary_release"),false,false);

		hCvar=FindConVar("tongue_player_dropping_to_ground_time");
		ResetConVar(hCvar,false,false);
		g_flTongueDropTime=GetConVarFloat(hCvar);
	}

	//reset tank attack intervals
	//and rock throw force

	//finally, clear DT and MA registry
	ClearAll();
	//recalculate DT and stopping power
	//permissions on game frame
	RunChecksAll();
	//reset boomer vars
	g_iSlimed		= 0;
	g_iSlimerLast	= 0;
	//reset tank vars
	g_iTank			= 0;
	g_iTankCount	= 0;

	//detect gamemode and difficulty
	new String:stArg[MAXPLAYERS+1];
	//next, check gamemode
	GetConVarString(FindConVar("mp_gamemode"),stArg,64);
	if (StrContains(stArg,"versus",false)!= -1
		|| StrContains(stArg,"scavenge",false)!= -1)
		g_iL4D_GameMode=2;
	else if (StrEqual(stArg,"survival",false)==true)
		g_iL4D_GameMode=1;
	else
		g_iL4D_GameMode=0;

	//start global timer that
	//forces bots to have some perks
	//among other things
	if (g_hTimerPerks != INVALID_HANDLE)
	{
		KillTimer(g_hTimerPerks);
		g_hTimerPerks = INVALID_HANDLE;
	}
	g_hTimerPerks = CreateTimer(2.0,TimerPerks,0,TIMER_REPEAT);

	//finally, tell plugin that loading is over and that roundstart can run again
	g_bIsRoundStart = false;
	g_bIsLoading = false;

	//----DEBUG----
	//PrintToChatAll("\x03-difficulty \x01%i\x03, gamemode \x01%i",g_iL4D_Difficulty,g_iL4D_GameMode);

	//----DEBUG----
	//PrintToChatAll("\x03-end round start routine");
}

//resets some temp vars related to perks
public Event_PlayerDeath (Handle:event, const String:name[], bool:dontBroadcast)
{
	if (g_bIsLoading == true
		|| g_bIsRoundStart == true)
		return;

	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid==0) return;
	//reset vars related to spirit perk
	g_iMyDisabler[iCid] = -1;
	g_iMyDisableTarget[iCid] = -1;
	g_iPIncap[iCid]=0;
	g_iSpiritCooldown[iCid]=0;
	//and also close the spirit cooldown timer
	//and nullify the var pointing to it
	if (g_iSpiritTimer[iCid]!=INVALID_HANDLE)
	{
		KillTimer(g_iSpiritTimer[iCid]);
		g_iSpiritTimer[iCid]=INVALID_HANDLE;
	}
	TwinSF_ResetShotCount(iCid);

	if (IsClientInGame(iCid)==true
		&& IsFakeClient(iCid)==false)
	{
		//reset var related to blind luck perk
		//SendConVarValue(iCid,FindConVar("sv_cheats"),"0");
		SetEntProp(iCid, Prop_Send, "m_iHideHUD", 0);
	}

	//rebuild registries for double tap and martial artist
	RebuildAll();

	//reset movement rate from martial artist
	SetEntDataFloat(iCid,g_iLaggedMovementO, 1.0 ,true);


	//Tank Routine
	//------------
	new iClass = GetEntData(iCid, g_iClassO);

	//----DEBUG----
	//PrintToChatAll("\x03player model: %s",st_class);

	//just because I'm not exactly sure...
	if (iClass == 7 || iClass == 8)
	{
		//if a tank is dead, recount the number of tanks left
		//start from zero...
		g_iTankCount=0;
		//...and count up
		for (new iI=1 ; iI<=MaxClients ; iI++)
		{
			if (IsClientInGame(iI)==true
				&& IsPlayerAlive(iI)==true
				&& GetClientTeam(iI)==3)
			{
				iClass = GetEntData(iI, g_iClassO);
				if (iClass==7 || iClass==8)
					g_iTankCount++;

				//----DEBUG----
				//PrintToChatAll("\x03-counting \x01%i",iI);
			}
		}

		//----DEBUG----
		//PrintToChatAll("\x03new g_iTankCount= \x01%i",g_iTankCount);

		//if there are no more double trouble tanks, tell plugin there's no more tanks
		if (g_iTankCount==0)
			g_iTank=0;
		//if for some reason it goes below 0, reset vars
		else if (g_iTankCount<0)
		{
			g_iTankCount=0;
			g_iTank=0;
		}

		//----DEBUG----
		//PrintToChatAll("\x03-end tank death routine");
	}

	//----DEBUG----
	//PrintToChatAll("\x03end death routine for \x01%i",iCid);
}


//sets confirm to 0 and redisplays perks menu
public Event_PlayerTransitioned (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid==0) return;
	//reset their confirm perks var
	//and show the menu
	g_iConfirm[iCid]=0;
	/*CreateTimer(1.0,Timer_ShowTopMenu,iCid);
	//since we just changed maps
	//reset everything for the spirit cooldown timer
	if (g_iSpiritTimer[iCid]!=INVALID_HANDLE)
	{
		KillTimer(g_iSpiritTimer[iCid]);
		g_iSpiritTimer[iCid]=INVALID_HANDLE;
	}*/
}

//resets everyone's confirm values on round end, mainly for survival and campaign
public Event_RoundEnd (Handle:event, const String:name[], bool:dontBroadcast)
{
	//----DEBUG----
	//PrintToChatAll("round end detected");

	ClearAll();

	for (new iI=1 ; iI<=MaxClients ; iI++)
	{
		g_iConfirm[iI]=0;
	}

	if (g_hTimerPerks != INVALID_HANDLE)
	{
		KillTimer(g_hTimerPerks);
		g_hTimerPerks = INVALID_HANDLE;
	}

	//tells plugin we're about to start loading
	g_bIsLoading = true;
}

//as round end function above
public OnMapEnd()
{
	//----DEBUG----
	//PrintToChatAll("map end detected");

	ClearAll();

	for (new iI=1 ; iI<=MaxClients ; iI++)
	{
		g_iConfirm[iI]=0;
	}

	if (g_hTimerPerks != INVALID_HANDLE)
	{
		KillTimer(g_hTimerPerks);
		g_hTimerPerks = INVALID_HANDLE;
	}

	//tells plugin we're about to start loading
	g_bIsLoading = true;
}

//Anything that uses a global timer for periodic
//checks is also called here; current functions called here:
//Sur1: Spirit
public Action:TimerPerks (Handle:timer, any:data)
{
	if (IsServerProcessing()==false)
	{
		KillTimer(timer);
		g_hTimerPerks = INVALID_HANDLE;
		return Plugin_Stop;
	}

	Spirit_Timer();

	return Plugin_Continue;
}

//called on a player changing teams
//and rebuilds DT registry (and MA as well)
public Event_PlayerTeam (Handle:event, const String:name[], bool:dontBroadcast)
{
	//----DEBUG----
	//PrintToChatAll("\x03change team detected");

	if (g_bIsLoading == true
		|| g_bIsRoundStart == true)
		return;

	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid==0
		|| IsValidEntity(iCid)==false
		|| IsClientInGame(iCid)==false) return;

	//reset vars related to spirit perk
	g_iPIncap[iCid]=0;
	g_iSpiritCooldown[iCid]=0;
	//reset var related to various hunter/smoker perks
	g_iMyDisabler[iCid] = -1;
	g_iMyDisableTarget[iCid] = -1;

	TwinSF_ResetShotCount(iCid);

	//reset var pointing to client's spirit timer
	//and close the timer handle
	if (g_iSpiritTimer[iCid]!=INVALID_HANDLE)
	{
		KillTimer(g_iSpiritTimer[iCid]);
		g_iSpiritTimer[iCid]=INVALID_HANDLE;
	}

	//reset runspeed
	SetEntDataFloat(iCid,g_iLaggedMovementO, 1.0 ,true);

	//reset blind perk sendprop
	if (IsFakeClient(iCid)==false)
		SetEntProp(iCid, Prop_Send, "m_iHideHUD", 0);

	//rebuild MA and DT registries
	CreateTimer(0.3,Delayed_Rebuild,0);

	//only allow changes of perks if team change was
	//to or from the infected team (implying it's versus)
	if (GetEventInt(event,"team")==3
		|| GetEventInt(event,"oldteam")==3)
	{
		g_iConfirm[iCid]=0;
		CreateTimer(1.0,Timer_ShowTopMenu,iCid);
		//apply perks if changing into survivors
		CreateTimer(0.3,Delayed_PerkChecks,iCid);
	}

	//----DEBUG----
	//PrintToChatAll("\x03-end change team routine");
}

//called when plugin is unloaded
//reset all the convars that had permission to run
public OnPluginEnd()
{
	g_bIsRoundStart = true;
	g_bIsLoading = true;

	//----DEBUG----
	//PrintToChatAll("\x03begin pluginend routine");

	for (new iI=1 ; iI<=MaxClients ; iI++)
	{
		//reset var pointing to client's spirit timer
		//and close the timer handle
		if (g_iSpiritTimer[iI]!=INVALID_HANDLE)
		{
			KillTimer(g_iSpiritTimer[iI]);
			g_iSpiritTimer[iI]=INVALID_HANDLE;
		}

		//before we run any functions on players
		//check if the game has any players to prevent
		//stupid error messages cropping up on the server
		if (IsServerProcessing()==false)
			continue;

		//only run these commands if player is in-game
		if (IsClientInGame(iI)==true)
		{
			//reset run speeds for martial artist
			SetEntDataFloat(iI,g_iLaggedMovementO, 1.0 ,true);

			//reset var related to blind luck perk
			//SendConVarValue(iI,hCvar,"0");
			SetEntProp(iI, Prop_Send, "m_iHideHUD", 0);
		}

	}

	decl Handle:hCvar;

	//reset vomit vars

	if (g_iInf1_enable==1
		&& g_iMotion_enable==1)
	{
		hCvar=FindConVar("z_vomit_fatigue");
		ResetConVar(hCvar,false,false);
	}

	//reset tongue vars

	if (g_iInf3_enable==1
		&& g_iTongue_enable==1)
	{
		hCvar=FindConVar("tongue_victim_max_speed");
		ResetConVar(hCvar,false,false);

		hCvar=FindConVar("tongue_range");
		ResetConVar(hCvar,false,false);

		hCvar=FindConVar("tongue_fly_speed");
		ResetConVar(hCvar,false,false);
	}

	if (g_iInf3_enable==1
		&& g_iDrag_enable==1)
	{
		ResetConVar(FindConVar("tongue_allow_voluntary_release"),false,false);

		hCvar=FindConVar("tongue_player_dropping_to_ground_time");
		ResetConVar(hCvar,false,false);
	}

	//finally, clear DT and MA registry
	ClearAll();

	if (g_hTimerPerks != INVALID_HANDLE)
		KillTimer(g_hTimerPerks);
	g_hTimerPerks = INVALID_HANDLE;

	g_bIsRoundStart = false;
	g_bIsLoading = false;

	//----DEBUG----
	//PrintToChatAll("\x03-end pluginend routine");
}







//=============================
// Misc. Perk Functions
//=============================

//This is a recently-added function adapted from the complex function I originally wrote
//for body slam. Simpler code I wrote for the other infected-to-survivor perks kept
//inadvertently killing the survivors when they weren't black-and-white... but since
//body slam never had that problem, I decided to use body slam's code to avoid that
//problem altogether... hence this giant function. However, since body slam doesn't fire
//if the original damage exceeds a minimum, it still has its own code.
InfToSurDamageAdd (any:iVic, any:iDmgAdd, any:iDmgOrig)
{
	//don't bother running if client id is zero
	//since sourcemod is intolerant of local servers
	//and if damage add is zero... why bother?
	if (iVic==0 || iDmgAdd<=0) return;

	new iHP=GetEntProp(iVic,Prop_Data,"m_iHealth");

	//CONDITION 1:
	//HEALTH > DMGADD
	//-----------------
	//if health>Min, then run normally
	//easiest condition, since we can
	//apply the damage directly to their hp
	if (iHP>iDmgAdd)
	{
		//----DEBUG----
		//PrintToChatAll("\x03iHP>%i condition",iDmgAdd);

		SetEntProp(iVic,Prop_Data,"m_iHealth", iHP-iDmgAdd );

		//----DEBUG----
		//PrintToChatAll("\x03-%i bonus damage", iDmgAdd );

		return;
	}

	//CONDITION 2:
	//HEALTH <= DMGADD
	//-----------------
	//otherwise, we gotta do a bit of work
	//if survivor's health is
	//less than or equal to 8
	else
	{
		//----DEBUG----
		//PrintToChatAll("\x03iHP<=%i condition",iDmgAdd);
		//PrintToChatAll("\x03-pre-mod iHP: \x01%i",iHP);

		new Float:flHPBuff=GetEntDataFloat(iVic,g_iHPBuffO);

		//CONDITION 2A:
		//HEALTH <= DMGADD
		//&& BUFFER > 0
		//-----------------
		//if victim has health buffer,
		//we need to do some extra work
		//to reduce health buffer as well
		if (flHPBuff>0)
		{
			//----DEBUG----
			//PrintToChatAll("\x03-flHPBuff>0 condition, pre-mod HPbuffer: \x01%f", flHPBuff);

			//since we know the damage add exceeds
			//health, we need to take the difference
			//and apply it to health buffer instead

			//we leave the survivor with 1 health
			//because the engine will take it away
			//when it applies the original damage
			//and we want to avoid strange death behaviour
			//(which occurs if victim's health falls below 0)
			new iDmgCount=iHP-1;
			iDmgAdd-=iDmgCount;
			SetEntProp(iVic,Prop_Data,"m_iHealth", iHP-iDmgCount );

			//and now we take the remainder of the
			//damage add and apply it to the health buffer.

			//if damage add is more than health buffer,
			//set damage add to health buffer amount
			new iHPBuff=RoundToFloor(flHPBuff);
			if (iHPBuff<iDmgAdd) iDmgAdd=iHPBuff;
			//and here we apply the damage to the buffer
			SetEntDataFloat(iVic,g_iHPBuffO, flHPBuff-iDmgAdd ,true);

			//finally, set the proper value in the event info

			//----DEBUG----
			//PrintToChatAll("\x03-damage to health: \x01%i\x03, current health: \x01%i",iDmgCount,GetEntProp(iVic,Prop_Data,"m_iHealth"));
			//PrintToChatAll("\x03-damage to buffer: \x01%i\x03, current buffer: \x01%f",iDmgAdd,GetEntDataFloat(iVic,g_iHPBuffO));

			return;
		}

		//CONDITION 2B:
		//HEALTH <= DMGADD
		//&& BUFFER <= 0
		//-----------------
		//without health buffer, it's straightforward
		//since we just need to apply however much
		//of the damage add we can to the victim's health
		else
		{
			//----DEBUG----
			//PrintToChatAll("\x03no temp hp condition");

			//if original damage exceeds health,
			//just skip the rest since there's no
			//health buffer to worry about,
			//and the engine will incap or kill
			//the survivor anyways with the base damage
			if (iDmgOrig>=iHP) return;

			//to prevent strange death behaviour,
			//reduce damage add to less than that
			//of remaining health if necessary
			if (iDmgAdd>=iHP) iDmgAdd=iHP-1;
			//and if this puts it below 0, just skip everything
			if (iDmgAdd<0) return;

			SetEntProp(iVic,Prop_Data,"m_iHealth", iHP-iDmgAdd );

			//----DEBUG----
			//PrintToChatAll("\x03-%i bonus damage", iDmgAdd );

			return;
		}
	}
}



//just because Sourcemod's RoundToCeil and RoundToFloor functions are
//currently unreliable, I've just written my own workable version
//returns the damage add, randomly picks between higher and lower rounded value
DamageAddRound (iDmgOrig, Float:flDmgMult)
{
	//calculate the damage add
	decl iDmgAdd;
	new Float:flDmg = iDmgOrig * flDmgMult;
	new iDmgRound = RoundToNearest(flDmg);

	//----DEBUG----
	//PrintToChatAll("\x03- fldmg \x01%f\x03 idmground \x01%i",flDmg,iDmgRound);

	//if rounding error can occur...
	new Float:flDmgDiff = iDmgRound - flDmg;
	//check if the rounded value is different from the actual value
	if ( flDmgDiff != 0 )
	{
		//if it is, check if we had rounded up
		if (flDmgDiff > 0)
		{
			//if it was rounded up, then randomize between the upper and lower value
			//and weigh it by each 0.1 amount the rounded value was off by
			if (GetRandomInt(1,10) <= (flDmgDiff * 10) )
				//since we rounded up earlier, just set dmgadd to rounded value
				iDmgAdd = iDmgRound;
			//otherwise, set the damage add to the rounded value minus 1
			else
				iDmgAdd = iDmgRound - 1;
		}
		//the other case is if we rounded down
		else
		{
			//same as above, except multiply it by a negative number to get the abs value
			if (GetRandomInt(1,10) <= (flDmgDiff * (-10)) )
				//since we rounded down earlier, set dmgadd to rounded value plus 1
				iDmgAdd = iDmgRound + 1;
			//otherwise, set the damage add to the rounded value
			else
				iDmgAdd = iDmgRound;
		}
	}

	//if the bonus damage is a clean integer value...
	else
	{
		//just use the value without further fussing
		iDmgAdd = iDmgRound;
	}



	//stop if damage add is <= 0
	if (iDmgAdd <= 0)
		return 0;

	//----DEBUG----
	//PrintToChatAll("\x03- idmgadd \x01%i\x03, idmgorig \x01%i", iDmgAdd, iDmgOrig );

	return iDmgAdd;
}

//on drying from slime, remove hud changes
//and lower count of people slimed (pungent)
public Action:PlayerNoLongerIt (Handle:timer, any:iCid)
{
	KillTimer(timer);
	if (IsServerProcessing()==false)
		return Plugin_Stop;

	if (IsClientInGame(iCid)==true
		&& IsFakeClient(iCid)==false)
		SetEntProp(iCid, Prop_Send, "m_iHideHUD", 0);
		//SendConVarValue(iCid,FindConVar("sv_cheats"),"0");

	//----DEBUG----
	//PrintToChatAll("\x03client \x01%i\x03 no longer it \n attempting to restore hud",iCid);
	//PrintToChatAll("\x03old g_iSlimed: \x01%i",g_iSlimed);

	if (g_iSlimed>4) g_iSlimed=3;
	else if (g_iSlimed<0) g_iSlimed=0;
	else g_iSlimed--;

	//----DEBUG----
	//PrintToChatAll("\x03new g_iSlimed: \x01%i",g_iSlimed);

	return Plugin_Stop;
}

RunChecksAll ()
{
	if (g_bIsLoading == true
		|| g_bIsRoundStart == true)
		return;

	Stopping_RunChecks();
	DT_RunChecks();
	MA_RunChecks();
}

public Action:Delayed_Rebuild (Handle:timer, any:data)
{
	KillTimer(timer);
	if (IsServerProcessing()==false)
		return Plugin_Continue;

	RebuildAll();

	return Plugin_Stop;
}

RebuildAll ()
{
	DT_Rebuild();
	MA_Rebuild();
	Adrenal_Rebuild();
	Extreme_Rebuild();
}

ClearAll ()
{
	DT_Clear();
	MA_Clear();
	Adrenal_Clear();
	Extreme_Rebuild();
}

//delayed perk checks
public Action:Delayed_PerkChecks (Handle:timer, any:iCid)
{
	KillTimer(timer);
	if (IsServerProcessing()==false)
		return Plugin_Stop;

	if (IsClientConnected(iCid)==false
		|| IsClientInGame(iCid)==false
		|| GetClientTeam(iCid)!=2)
		return Plugin_Stop;

	Event_Confirm_Unbreakable(iCid);
	Event_Confirm_Grenadier(iCid);
	Event_Confirm_ChemReliant(iCid);

	return Plugin_Stop;
}

//delayed show menu to prevent weird not-showing on
//campaign round restarts...
//... since 1.3, also checks if force random perks server
//setting is on; if so, then assigns perks instead
public Action:Timer_ShowTopMenu (Handle:timer, any:iCid)
{
	KillTimer(timer);
	if (IsServerProcessing()==false
		|| IsClientInGame(iCid)==false
		|| IsFakeClient(iCid)==true
		|| g_bIsLoading == true)
		return Plugin_Stop;

	if (GetConVarInt(g_hMenuAutoShow_enable)==0)
		return Plugin_Stop;

	//----DEBUG----
	//PrintToChatAll("\x03showing menu to \x01%i",iCid);

	if (g_iForceRandom==0)
	{
		new iT = GetClientTeam(iCid);
		if (iT==2)
			SendPanelToClient(Menu_Initial(iCid),iCid,Menu_ChooseInit,MENU_TIME_FOREVER);
		else if (iT==3)
			SendPanelToClient(Menu_Initial(iCid),iCid,Menu_ChooseInit_Inf,MENU_TIME_FOREVER);
	}
	else
		AssignRandomPerks(iCid);

	return Plugin_Stop;
}

//assigns random perks
AssignRandomPerks (iCid)
{
	//don't do anything if
	//the client id is whacked
	//or if confirm perks is set
	if (iCid > MaxClients
		|| iCid <= 0
		|| g_iConfirm[iCid]==1)
		return;

	//we track which perks are randomizable
	//in this array
	new iPerkType[10];
	//and keep track of which perk we're on
	decl iPerkCount;


	//SUR1 PERK
	//---------
	iPerkCount=0;

	//1 stopping power
	if (g_iStopping_enable==1			&&	g_iL4D_GameMode==0
		|| g_iStopping_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iStopping_enable_vs==1		&&	g_iL4D_GameMode==2)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//2 double tap
	if (g_iDT_enable==1			&&	g_iL4D_GameMode==0
		|| g_iDT_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iDT_enable_vs==1	&&	g_iL4D_GameMode==2)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;
	}	

	//3 sleight of hand
	if (g_iSoH_enable==1		&&	g_iL4D_GameMode==0
		|| g_iSoH_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iSoH_enable_vs==1	&&	g_iL4D_GameMode==2)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=3;
	}

	//4 pyrotechnician
	if (g_iPyro_enable==1			&&	g_iL4D_GameMode==0
		|| g_iPyro_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iPyro_enable_vs==1		&&	g_iL4D_GameMode==2)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=4;
	}

	//5 martial artist
	if (g_iMA_enable==1			&&	g_iL4D_GameMode==0
		|| g_iMA_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iMA_enable_vs==1	&&	g_iL4D_GameMode==2)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=5;
	}

	//randomize a perk
	if (iPerkCount>0)
		g_iSur1[iCid] = iPerkType[ GetRandomInt(1,iPerkCount) ];


	//SUR2 PERK
	//---------
	iPerkCount=0;

	//1 unbreakable
	if (g_iUnbreak_enable==1		&&	g_iL4D_GameMode==0
		|| g_iUnbreak_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iUnbreak_enable_vs==1	&&	g_iL4D_GameMode==2)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//2 spirit
	if (g_iSpirit_enable==1			&&	g_iL4D_GameMode==0
		|| g_iSpirit_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iSpirit_enable_vs==1	&&	g_iL4D_GameMode==2)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;
	}

	//3 helping hand
	if (g_iHelpHand_enable==1			&&	g_iL4D_GameMode==0
		|| g_iHelpHand_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iHelpHand_enable_vs==1		&&	g_iL4D_GameMode==2)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=3;
	}

	//randomize a perk
	if (iPerkCount>0)
		g_iSur2[iCid] = iPerkType[ GetRandomInt(1,iPerkCount) ];


	//SUR3 PERK
	//------------------

	iPerkCount=0;

	//1 pack rat
	if (g_iPack_enable==1			&&	g_iL4D_GameMode==0
		|| g_iPack_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iPack_enable_vs==1		&&	g_iL4D_GameMode==2)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//2 chem reliant
	if (g_iChem_enable==1			&&	g_iL4D_GameMode==0
		|| g_iChem_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iChem_enable_vs==1		&&	g_iL4D_GameMode==2)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;
	}

	//3 hard to kill
	if (g_iHard_enable==1			&&	g_iL4D_GameMode==0
		|| g_iHard_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iHard_enable_vs==1		&&	g_iL4D_GameMode==2)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=3;
	}

	//4 extreme conditioning
	if (g_iExtreme_enable==1		&&	g_iL4D_GameMode==0
		|| g_iExtreme_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iExtreme_enable_vs==1	&&	g_iL4D_GameMode==2)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=4;
	}

	//randomize a perk
	if (iPerkCount>0)
		g_iSur3[iCid] = iPerkType[ GetRandomInt(1,iPerkCount) ];


	//INF1 (BOOMER) PERK
	//------------------
	iPerkCount=0;

	//1 barf bagged
	if (g_iBarf_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//2 blind luck
	if (g_iBlind_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;
	}

	//3 dead wreckening
	if (g_iDead_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=3;
	}

	//4 motion sickness
	if (g_iMotion_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=4;
	}

	//randomize a perk
	if (iPerkCount>0)
		g_iInf1[iCid] = iPerkType[ GetRandomInt(1,iPerkCount) ];


	//INF3 (SMOKER) PERK
	//------------------
	iPerkCount=0;

	//1 tongue twister
	if (g_iTongue_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//2 squeezer
	if (g_iSqueezer_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;
	}

	//3 drag and drop
	if (g_iDrag_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=3;
	}

	//randomize a perk
	if (iPerkCount>0)
		g_iInf3[iCid] = iPerkType[ GetRandomInt(1,iPerkCount) ];


	//INF4 (HUNTER) PERK
	//------------------
	iPerkCount=0;

	//1 body slam
	if (g_iBody_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//2 efficient killer
	if (g_iEfficient_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;
	}

	//3 grasshopper
	if (g_iGrass_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=3;
	}

	//4 speed demon
	if (g_iSpeedDemon_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=4;
	}

	//randomize a perk
	if (iPerkCount>0)
		g_iInf4[iCid] = iPerkType[ GetRandomInt(1,iPerkCount) ];



	//INF5 (JOCKEY) PERK
	//------------------
	iPerkCount=0;

	//1 wind
	if (g_iWind_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//2 cavalier
	if (g_iCavalier_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;
	}

	//3 frogger
	if (g_iFrogger_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=3;
	}

	//4 ghost
	if (g_iGhost_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=4;
	}

	//randomize a perk
	if (iPerkCount>0)
		g_iInf5[iCid] = iPerkType[ GetRandomInt(1,iPerkCount) ];



	//INF6 (SPITTER) PERK
	//------------------
	iPerkCount=0;

	//1 twin spitfire
	if (g_iTwinSF_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//1 mega adhesive
	if (g_iMegaAd_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;
	}

	//randomize a perk
	if (iPerkCount>0)
		g_iInf6[iCid] = iPerkType[ GetRandomInt(1,iPerkCount) ];



	//INF7 (CHARGER) PERK
	//------------------
	iPerkCount=0;

	//1 scatter
	if (g_iScatter_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//1 bullet
	if (g_iBullet_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//randomize a perk
	if (iPerkCount>0)
		g_iInf7[iCid] = iPerkType[ GetRandomInt(1,iPerkCount) ];



	//INF2 (TANK) PERK
	//----------------
	iPerkCount=0;

	//1 adrenal glands
	if (g_iAdrenal_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//2 Juggernaut
	if (g_iJuggernaut_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;
	}

	//3 metabolic boost
	if (g_iMetabolic_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=3;
	}

	//4 stormcaller
	if (g_iStorm_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=4;
	}

	//5 double the trouble
	if (g_iDouble_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=5;
	}

	//randomize a perk
	if (iPerkCount>0)
		g_iInf2[iCid] = iPerkType[ GetRandomInt(1,iPerkCount) ];


	//finally, confirm perks
	//and run the necessary functions
	//as if the player had confirmed
	//their perks through the traditional way
	g_iConfirm[iCid]=1;
	Event_Confirm_Unbreakable(iCid);
	Event_Confirm_Grenadier(iCid);
	Event_Confirm_ChemReliant(iCid);
	Event_Confirm_DT(iCid);
	Event_Confirm_MA(iCid);
	Extreme_Rebuild();

	//lastly, show a panel to the player
	//showing what perks they were given
	SendPanelToClient(Menu_ShowChoices(iCid),iCid,Menu_DoNothing,15);

}

//picks a random perk for bots
Bot_Sur1_PickRandom ()
{
	//stop if sur1 perks are disabled
	if (g_iSur1_enable==0)
		return 0;

	new iPerkType[12];
	new iPerkCount=0;

	decl String:stPerk[24];
	if (g_hBot_Sur1 != INVALID_HANDLE)
		GetConVarString(g_hBot_Sur1,stPerk,24);
	else
		stPerk = "1,2,3";

	//stopping power
	if (StrContains(stPerk,"1",false) != -1
		&& g_iStopping_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//sleight of hand
	if (StrContains(stPerk,"2",false) != -1
		&& g_iSpirit_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=3;
	}

	//martial artist
	if (StrContains(stPerk,"3",false) != -1
		&& g_iUnbreak_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=5;
	}

	//randomize
	if (iPerkCount>0)
		return iPerkType[ GetRandomInt(1,iPerkCount) ];
	else
		return 0;
}

Bot_Sur2_PickRandom ()
{
	//stop if sur2 perks are disabled
	if (g_iSur2_enable==0)
		return 0;

	new iPerkType[12];
	new iPerkCount=0;

	decl String:stPerk[24];
	if (g_hBot_Sur2 != INVALID_HANDLE)
		GetConVarString(g_hBot_Sur2,stPerk,24);
	else
		stPerk = "1,2,3";

	//unbreakable
	if (StrContains(stPerk,"1",false) != -1
		&& g_iChem_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//spirit
	if (StrContains(stPerk,"2",false) != -1
		&& g_iHelpHand_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;
	}

	//helping hand
	if (StrContains(stPerk,"3",false) != -1
		&& g_iPack_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=3;
	}

	//randomize
	if (iPerkCount>0)
		return iPerkType[ GetRandomInt(1,iPerkCount) ];
	else
		return 0;
}

Bot_Sur3_PickRandom ()
{
	//stop if sur2 perks are disabled
	if (g_iSur3_enable==0)
		return 0;

	new iPerkType[12];
	new iPerkCount=0;

	decl String:stPerk[24];
	if (g_hBot_Sur3 != INVALID_HANDLE)
		GetConVarString(g_hBot_Sur3,stPerk,24);
	else
		stPerk = "1,2";

	//pack rat
	if (StrContains(stPerk,"1",false) != -1
		&& g_iChem_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//hard to kill
	if (StrContains(stPerk,"2",false) != -1
		&& g_iPack_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=3;
	}

	//randomize
	if (iPerkCount>0)
		return iPerkType[ GetRandomInt(1,iPerkCount) ];
	else
		return 0;
}

Bot_Inf1_PickRandom ()
{
	//stop if boomer perks are disabled
	if (g_iInf1_enable==0)
		return 0;

	//----DEBUG----
	//PrintToChatAll("\x03begin random perk for boomer");

	new iPerkType[12];
	new iPerkCount=0;

	decl String:stPerk[24];
	if (g_hBot_Inf1 != INVALID_HANDLE)
		GetConVarString(g_hBot_Inf1,stPerk,24);
	else
		stPerk = "1,2,3";

	//----DEBUG----
	//PrintToChatAll("\x03-stPerk: \x01%s",stPerk);

	//barf bagged
	if (StrContains(stPerk,"1",false) != -1
		&& g_iBarf_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;

		//----DEBUG----
		//PrintToChatAll("\x03-count \x01%i\x03, type \x01%i",iPerkCount,iPerkType[iPerkCount]);
	}

	//blind luck
	if (StrContains(stPerk,"2",false) != -1
		&& g_iBlind_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;

		//----DEBUG----
		//PrintToChatAll("\x03-count \x01%i\x03, type \x01%i",iPerkCount,iPerkType[iPerkCount]);
	}

	//dead wreckening
	if (StrContains(stPerk,"3",false) != -1
		&& g_iDead_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=3;

		//----DEBUG----
		//PrintToChatAll("\x03-count \x01%i\x03, type \x01%i",iPerkCount,iPerkType[iPerkCount]);
	}

	//randomize
	decl iReturn;
	if (iPerkCount>0)
		iReturn = iPerkType[ GetRandomInt(1,iPerkCount) ];
	else
		iReturn = 0;

	//----DEBUG----
	//PrintToChatAll("\x03-returning \x01%i",iReturn);

	return iReturn;
}

Bot_Inf2_PickRandom ()
{
	//stop if tank perks are disabled
	if (g_iInf2_enable==0)
		return 0;

	new iPerkType[12];
	new iPerkCount=0;

	decl String:stPerk[24];
	if (g_hBot_Inf2 != INVALID_HANDLE)
		GetConVarString(g_hBot_Inf2,stPerk,24);
	else
		stPerk = "1,2,3,4,5";

	//adrenal glands
	if (StrContains(stPerk,"1",false) != -1
		&& g_iAdrenal_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//juggernaut
	if (StrContains(stPerk,"2",false) != -1
		&& g_iJuggernaut_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;
	}

	//metabolic boost
	if (StrContains(stPerk,"3",false) != -1
		&& g_iMetabolic_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=3;
	}

	//storm caller
	if (StrContains(stPerk,"4",false) != -1
		&& g_iStorm_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=4;
	}

	//double trouble
	if (StrContains(stPerk,"5",false) != -1
		&& g_iDouble_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=5;
	}

	//randomize
	if (iPerkCount>0)
		return iPerkType[ GetRandomInt(1,iPerkCount) ];
	else
		return 0;
}

Bot_Inf3_PickRandom ()
{
	//stop if smoker perks are disabled
	if (g_iInf3_enable==0)
		return 0;

	new iPerkType[12];
	new iPerkCount=0;

	decl String:stPerk[24];
	if (g_hBot_Inf3 != INVALID_HANDLE)
		GetConVarString(g_hBot_Inf3,stPerk,24);
	else
		stPerk = "1,2,3";

	//tongue twister
	if (StrContains(stPerk,"1",false) != -1
		&& g_iTongue_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//squeezer
	if (StrContains(stPerk,"2",false) != -1
		&& g_iSqueezer_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;
	}

	//drag and drop
	if (StrContains(stPerk,"3",false) != -1
		&& g_iDrag_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=3;
	}

	//randomize
	if (iPerkCount>0)
		return iPerkType[ GetRandomInt(1,iPerkCount) ];
	else
		return 0;
}

Bot_Inf4_PickRandom ()
{
	//stop if hunter perks are disabled
	if (g_iInf4_enable==0)
		return 0;

	new iPerkType[12];
	new iPerkCount=0;

	decl String:stPerk[24];
	if (g_hBot_Inf4 != INVALID_HANDLE)
		GetConVarString(g_hBot_Inf4,stPerk,24);
	else
		stPerk = "1,2";

	//efficient killer
	if (StrContains(stPerk,"1",false) != -1
		&& g_iEfficient_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//speed demon
	if (StrContains(stPerk,"2",false) != -1
		&& g_iSpeedDemon_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=4;
	}

	//randomize
	if (iPerkCount>0)
		return iPerkType[ GetRandomInt(1,iPerkCount) ];
	else
		return 0;
}

Bot_Inf5_PickRandom ()
{
	//stop if jockey perks are disabled
	if (g_iInf5_enable==0)
		return 0;

	new iPerkType[12];
	new iPerkCount=0;

	decl String:stPerk[24];
	if (g_hBot_Inf5 != INVALID_HANDLE)
		GetConVarString(g_hBot_Inf5,stPerk,24);
	else
		stPerk = "1,2,3,4";

	//ride like the wind
	if (StrContains(stPerk,"1",false) != -1
		&& g_iWind_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//cavalier
	if (StrContains(stPerk,"2",false) != -1
		&& g_iCavalier_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;
	}

	//frogger
	if (StrContains(stPerk,"3",false) != -1
		&& g_iFrogger_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=3;
	}

	//ghost
	if (StrContains(stPerk,"4",false) != -1
		&& g_iGhost_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=4;
	}

	//randomize
	if (iPerkCount>0)
		return iPerkType[ GetRandomInt(1,iPerkCount) ];
	else
		return 0;
}

Bot_Inf6_PickRandom ()
{
	//stop if spitter perks are disabled
	if (g_iInf6_enable==0)
		return 0;

	new iPerkType[12];
	new iPerkCount=0;

	decl String:stPerk[24];
	if (g_hBot_Inf6 != INVALID_HANDLE)
		GetConVarString(g_hBot_Inf6,stPerk,24);
	else
		stPerk = "1";

	//twin spitfire
	if (StrContains(stPerk,"1",false) != -1
		&& g_iTwinSF_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//mega adhesive
	if (StrContains(stPerk,"2",false) != -1
		&& g_iMegaAd_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;
	}

	//randomize
	if (iPerkCount>0)
		return iPerkType[ GetRandomInt(1,iPerkCount) ];
	else
		return 0;
}

Bot_Inf7_PickRandom ()
{
	//stop if charger perks are disabled
	if (g_iInf7_enable==0)
		return 0;

	new iPerkType[12];
	new iPerkCount=0;

	decl String:stPerk[24];
	if (g_hBot_Inf7 != INVALID_HANDLE)
		GetConVarString(g_hBot_Inf7,stPerk,24);
	else
		stPerk = "1,2";

	//scattering ram
	if (StrContains(stPerk,"1",false) != -1
		&& g_iScatter_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=1;
	}

	//scattering ram
	if (StrContains(stPerk,"2",false) != -1
		&& g_iBullet_enable==1)
	{
		iPerkCount++;
		iPerkType[iPerkCount]=2;
	}

	//randomize
	if (iPerkCount>0)
		return iPerkType[ GetRandomInt(1,iPerkCount) ];
	else
		return 0;
}





//=============================
// Sur1: Stopping Power
//=============================

//pre-calculates whether stopping power should
//run, since damage events can occur pretty often
Stopping_RunChecks ()
{
	if (g_iSur1_enable==1
		&& (g_iStopping_enable==1		&&	g_iL4D_GameMode==0
		|| g_iStopping_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iStopping_enable_vs==1		&&	g_iL4D_GameMode==2))
		g_iStopping_meta_enable=1;
	else
		g_iStopping_meta_enable=0;
}

//main damage add function
Stopping_DamageAdd (iAtt, iVic, iTA, iDmgOrig, String:stWpn[])
{
	//check if perk is disabled
	if (g_iStopping_meta_enable==0)
		return 1;

	if (iTA==2
		&& g_iSur1[iAtt]==1
		&& g_iConfirm[iAtt]==1
		&& GetClientTeam(iVic)!=2)
	{
		if (StrEqual(stWpn,"melee",false)==true)
		{
			//----DEBUG----
			//PrintToChatAll("\x03melee weapon detected, not firing");

			return 1;
		}

		//----DEBUG----
		//PrintToChatAll("\x03Pre-mod bullet damage: \x01%i", GetEventInt(event,"dmg_health"));

		new iDmgAdd= RoundToNearest(iDmgOrig * g_flStopping_dmgmult);
		new iHP=GetEntProp(iVic,Prop_Data,"m_iHealth");
		//to prevent strange death behaviour,
		//only deal the full damage add if health > damage add
		if (iHP>iDmgAdd)
		{
			SetEntProp(iVic,Prop_Data,"m_iHealth", iHP-iDmgAdd );
		}
		//if health < damage add, only deal health-1 damage
		else
		{
			iDmgAdd=iHP-1;
			//don't bother if the modified damage add
			//ends up being an insignificant amount
			if (iDmgAdd<0)
				return 1;
			SetEntProp(iVic,Prop_Data,"m_iHealth", iHP-iDmgAdd );
		}

		//----DEBUG----
		//PrintToChatAll("\x03Post-mod bullet damage: \x01%i",GetEventInt(event,"dmg_health"));

		return 1;
	}

	return 0;
}

//against common infected
public Event_InfectedHurtPre (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"attacker"));

	if (iCid==0 || g_iConfirm[iCid]==0)
		return;

	//check if perk is disabled
	if (g_iStopping_meta_enable==0)
		return;

	//----DEBUG----
	//PrintToChatAll("\x03infected hurt, iAtt: %i, iEntid: %i, i_odmg: %i, iHP: %i",iAtt,iEntid,i_odmg,GetEntProp(iEntid,Prop_Data,"m_iHealth"));

	if (g_iSur1[iCid]==1
		&& GetClientTeam(iCid)==2)
	{
		new iEntid=GetEventInt(event,"entityid");
		new i_odmg=GetEventInt(event,"amount");
		new i_dmga=RoundToNearest(i_odmg * g_flStopping_dmgmult);

		//----DEBUG----
		//PrintToChatAll("\x03Pre-mod damage: \x01%i, \x03pre-mod health: \x01%i", GetEventInt(event,"amount"),GetEntProp(iEntid,Prop_Data,"m_iHealth"));

		SetEntProp(iEntid,Prop_Data,"m_iHealth", GetEntProp(iEntid,Prop_Data,"m_iHealth")-i_dmga );
		//******SetEventInt(event,"dmg_health", i_odmg+i_dmga );

		//----DEBUG----
		//PrintToChatAll("\x03Post-mod damage: \x01%i, \x03post-mod health: \x01%i",GetEventInt(event,"amount"),GetEntProp(iEntid,Prop_Data,"m_iHealth"));
	}
}


//=============================
// Sur1: Double Tap
//=============================

//called on round starts and on convar changes
//does the checks to determine whether DT
//should be run every game frame
DT_RunChecks ()
{
	if (g_iSur1_enable==1
		&& (g_iDT_enable==1		&&	g_iL4D_GameMode==0
		|| g_iDT_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iDT_enable_vs==1	&&	g_iL4D_GameMode==2))
		g_iDT_meta_enable=1;
	else
		g_iDT_meta_enable=0;
}

//called on confirming perks
//simply adds player to registry of DT users
Event_Confirm_DT (iCid)
{
	if (g_iDTRegisterCount<0)
		g_iDTRegisterCount=0;
	if (IsClientInGame(iCid)==true
		&& IsPlayerAlive(iCid)==true
		&& g_iSur1[iCid]==2
		&& g_iConfirm[iCid]==1
		&& GetClientTeam(iCid)==2)
	{
		g_iDTRegisterCount++;
		g_iDTRegisterIndex[g_iDTRegisterCount]=iCid;

		//----DEBUG----
		//PrintToChatAll("\x03double tap on confirm, registering \x01%i",iCid);
	}	
}

//called whenever the registry needs to be rebuilt
//to cull any players who have left or died, etc.
//(called on: player death, player disconnect,
//closet rescue, change teams)
DT_Rebuild ()
{
	//clears all DT-related vars
	DT_Clear();

	//if the server's not running or
	//is in the middle of loading, stop
	if (IsServerProcessing()==false)
		return;

	//----DEBUG----
	//PrintToChatAll("\x03double tap rebuilding registry");

	for (new iI=1 ; iI<=MaxClients ; iI++)
	{
		if (IsClientInGame(iI)==true
			&& IsPlayerAlive(iI)==true
			&& g_iSur1[iI]==2
			&& g_iConfirm[iI]==1
			&& GetClientTeam(iI)==2)
		{
			g_iDTRegisterCount++;
			g_iDTRegisterIndex[g_iDTRegisterCount]=iI;

			//----DEBUG----
			//PrintToChatAll("\x03-registering \x01%i",iI);
		}
	}
}

//called to clear out DT registry
//(called on: round start, round end, map end)
DT_Clear ()
{
	g_iDTRegisterCount=0;
	for (new iI=1 ; iI<=MaxClients ; iI++)
	{
		g_iDTRegisterIndex[iI]= -1;
		g_iDTEntid[iI] = -1;
		g_flDTNextTime[iI]= -1.0;
	}
}

//this is the big momma!
//since this is called EVERY game frame,
//we need to be careful not to run too many functions
//kinda hard, though, considering how many things
//we have to check for =.=
DT_OnGameFrame()
{
	//or if no one has DT, don't bother either
	if (g_iDTRegisterCount==0)
		return;

	//stop if perk is disabled
	if (g_iDT_meta_enable==0)
		return;

	//this tracks the player's id, just to
	//make life less painful...
	decl iCid;
	//this tracks the player's gun id
	//since we adjust numbers on the gun,
	//not the player
	decl iEntid;
	//this tracks the calculated next attack
	decl Float:flNextTime_calc;
	//this, on the other hand, tracks the current next attack
	decl Float:flNextTime_ret;
	//and this tracks next melee attack times
	decl Float:flNextTime2_ret;
	//and this tracks the game time
	new Float:flGameTime=GetGameTime();

	//theoretically, to get on the DT registry
	//all the necessary checks would have already
	//been run, so we don't bother with any checks here
	for (new iI=1; iI<=g_iDTRegisterCount; iI++)
	{
		//PRE-CHECKS: RETRIEVE VARS
		//-------------------------

		iCid = g_iDTRegisterIndex[iI];
		//stop on this client
		//when the next client id is null
		if (iCid <= 0
			|| IsValidEntity(iCid)==false)
			return;
		//skip this client if they're disabled
		//if (g_iMyDisabler[iCid] != -1) continue;

		//we have to adjust numbers on the gun, not the player
		//so we get the active weapon id here
		iEntid = GetEntDataEnt2(iCid,g_iActiveWO);
		//if the retrieved gun id is -1, then...
		//wtf mate? just move on
		if (iEntid == -1
			|| IsValidEntity(iEntid)==false)
			continue;

		//----DEBUG----
		/*
		new iNextAttO=	FindSendPropInfo("CTerrorPlayer","m_flNextAttack");
		new iIdleTimeO=	FindSendPropInfo("CTerrorGun","m_flTimeWeaponIdle");
		PrintToChatAll("\x03DT, NextAttack \x01%i %f\x03, TimeIdle \x01%i %f",
			iNextAttO,
			GetEntDataFloat(iCid,iNextAttO),
			iIdleTimeO,
			GetEntDataFloat(iEntid,iIdleTimeO)
			);
		*/


		//PRE-CHECK 1
		//-----------
		new iEntid_stored = g_iDTEntid[iCid];
		new Float:flNextTime_stored = g_flDTNextTime[iCid];
		//and here is the retrieved next attack time
		flNextTime_ret = GetEntDataFloat(iEntid,g_iNextPAttO);


		//CHECK 1: BEFORE ADJUSTED SHOT IS MADE
		//------------------------------------
		//since this will probably be the case most of
		//the time, we run this first
		//checks: gun is unchanged; time of shot has not passed
		//actions: nothing
		if (iEntid_stored == iEntid
			&& flNextTime_stored >= flNextTime_ret)
		{
			//----DEBUG----
			//PrintToChatAll("\x03DT client \x01%i\x03; before shot made",iCid );

			continue;
		}


		//PRE-CHECK 2
		//-----------
		//and for retrieved next melee time
		flNextTime2_ret = GetEntDataFloat(iEntid,g_iNextSAttO);

		//CHECK 2: INFER IF MELEEING
		//--------------------------
		//since we don't want to shorten the interval
		//incurred after swinging, we try to guess when
		//a melee attack is made
		//checks: if melee attack time > engine time
		//actions: nothign
		if (flNextTime2_ret > flGameTime)
		{
			//----DEBUG----
			//PrintToChatAll("\x03DT client \x01%i\x03; melee attack inferred",iCid );

			g_flDTNextTime[iCid]=flNextTime_ret;

			continue;
		}


		//CHECK 3: AFTER ADJUSTED SHOT IS MADE
		//------------------------------------
		//at this point, either a gun was swapped, or
		//the attack time needs to be adjusted
		//checks: stored gun id same as retrieved gun id,
		// and retrieved next attack time is after stored value
		if (iEntid_stored == iEntid
			&& flNextTime_stored < flNextTime_ret)
		{
			//----DEBUG----
			//PrintToChatAll("\x03DT after adjusted shot\n-pre, client \x01%i\x03; entid \x01%i\x03; enginetime\x01 %f\x03; NextTime_orig \x01 %f\x03; interval \x01%f",iCid,iEntid,flGameTime,flNextTime_ret, flNextTime_ret-flGameTime );

			//this is a calculation of when the next primary attack
			//will be after applying double tap values
			flNextTime_calc = ( flNextTime_ret - flGameTime ) * g_flDT_rate + flGameTime;

			//then we store the value
			g_flDTNextTime[iCid] = flNextTime_calc;

			//and finally adjust the value in the gun
			SetEntDataFloat(iEntid, g_iNextPAttO, flNextTime_calc, true);

			//----DEBUG----
			//PrintToChatAll("\x03-post, NextTime_calc \x01 %f\x03; new interval \x01%f",GetEntDataFloat(iEntid,g_iNextPAttO), GetEntDataFloat(iEntid,g_iNextPAttO)-flGameTime );

			continue;
		}


		//CHECK 4: ON WEAPON SWITCH
		//-------------------------
		//at this point, the only reason DT hasn't fired
		//should be that the weapon had switched
		//checks: retrieved gun id doesn't match stored id
		// or stored id is null
		//actions: updates stored gun id
		// and sets stored next attack time to retrieved value
		if (iEntid_stored != iEntid)
		{
			//----DEBUG----
			//PrintToChatAll("\x03DT client \x01%i\x03; weapon switch inferred",iCid );

			//now we update the stored vars
			g_iDTEntid[iCid]=iEntid;
			g_flDTNextTime[iCid]=flNextTime_ret;
			continue;
		}

		//----DEBUG----
		//PrintToChatAll("\x03DT client \x01%i\x03; reached end of checklist...",iCid );
	}
}

//the % chance for a bullet to be a freebie
DT_OnWeaponFire (iCid, String:stWpn[])
{
	//or if no one has DT, don't bother either
	if (g_iDTRegisterCount==0)
		return;

	//stop if perk is disabled
	if (g_iDT_meta_enable==0)
		return;

	//run the basic perkmod checks
	if (IsClientInGame(iCid)==false
		|| IsPlayerAlive(iCid)==false
		|| g_iSur1[iCid]!=2
		|| g_iConfirm[iCid]!=1
		|| GetClientTeam(iCid)!=2)
	{
		return;
	}

	//stop if gun fired is a prop (minigun/m2hb)
	if (strncmp(stWpn, "prop", 4, false) == 0)
	{
		//----DEBUG----
		//PrintToChatAll("\x03- prop detected, stWpn = \x01%s", stWpn);

		return;
	}

	//this tracks the player's gun id
	//since we adjust numbers on the gun,
	//not the player
	//we have to adjust numbers on the gun, not the player
	//so we get the active weapon id here
	new iEntid = GetEntDataEnt2(iCid,g_iActiveWO);
	//if the retrieved gun id is -1, then...
	//wtf mate? just move on
	if (iEntid == -1
		|| IsValidEntity(iEntid)==false)
		return;

	//----DEBUG----
	//PrintToChatAll("\x03DT conservation fired, stWpn = \x01%s\x03, iEntid \x01%i\x03, g_iDTEntid_firearm = \x01%i", stWpn, iEntid, g_iDTEntid_firearm[iCid]);



	//CHECK 1: WEAPON FIRED IS A FIREARM
	//----------------------------------
	//checks if weapon is a firearm by checking
	//if the entid stored in the global var is
	//the same as the entid of the fired weapon
	//if it isn't, then the fired weapon entid
	//will be checked in the next section
	//also the string check is to make sure this
	//doesn't fire when a player uses a minigun
	if (iEntid == g_iDTEntid_firearm[iCid])
	{
		//----DEBUG----
		//PrintToChatAll("\x03- shots fired");

		DT_BulletConservation(iEntid);
	}

	//at this point, we need to check the weapon
	//type and confirm it's a firearm at all - if
	//the player just switched weapons, then we
	//just update the global var with the new entid
	else
	{
		//make sure it's actually a firearm - 
		//all firearms' class ids have "pistol",
		//"rifle", "shotgun", "sniper" or "smg"
		if (StrContains(stWpn, "pistol", false)!= -1
			|| StrContains(stWpn, "smg", false)!= -1
			|| StrContains(stWpn, "rifle", false)!= -1
			|| StrContains(stWpn, "shotgun", false)!= -1
			|| StrContains(stWpn, "sniper", false)!= -1	)
		{
			//----DEBUG----
			//PrintToChatAll("\x03- firearm detected, updating global var");

			//update the global var to make processing
			//future shots faster
			g_iDTEntid_firearm[iCid] = iEntid;
			//and then run a chance for this bullet - would
			//suck if the first bullet was never conserved
			DT_BulletConservation(iEntid);
		}
		else
		{
			//----DEBUG----
			//PrintToChatAll("\x03- non firearm detected");

			//if it's not a firearm, then update global var
			//(doesn't really do anything)
			g_iDTEntid_firearm[iCid] = -1;
		}
	}
}

//function for bullet conservation - runs the chance and changes the gun parameters
DT_BulletConservation (iEntid)
{
	if (GetRandomInt(1,100) <= g_flDT_freechance * 100)
	{
		new iClip = GetEntData(iEntid, g_iClipO);
		SetEntData(iEntid, g_iClipO, iClip + 1 );

		//----DEBUG----
		//PrintToChatAll("\x03DT bullet conserved");
	}
}



//=============================
// Sur1: Sleight of Hand
//=============================

//on the start of a reload
SoH_OnReload (iCid)
{
	//check if perk is disabled
	if (g_iSur1_enable==0
		|| g_iSoH_enable==0		&&	g_iL4D_GameMode==0
		|| g_iSoH_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iSoH_enable_vs==0	&&	g_iL4D_GameMode==2)
		return;

	if (g_iSur1[iCid]==3
		&& g_iConfirm[iCid]==1
		&& GetClientTeam(iCid)==2)
	{
		//----DEBUG----
		//PrintToChatAll("\x03SoH client \x01%i\x03; start of reload detected",iCid );

		new iEntid = GetEntDataEnt2(iCid,g_iActiveWO);
		if (IsValidEntity(iEntid)==false) return;

		decl String:stClass[32];
		GetEntityNetClass(iEntid,stClass,32);

		//----DEBUG----
		//PrintToChatAll("\x03-class of gun: \x01%s",stClass );

		//for non-shotguns
		if (StrContains(stClass,"shotgun",false) == -1)
		{
			SoH_MagStart(iEntid,iCid);
			return;
		}

		//shotguns are a bit trickier since the game
		//tracks per shell inserted - and there's TWO
		//different shotguns with different values =.=
		else if (StrContains(stClass,"autoshotgun",false) != -1)
		{
			//crate a pack to send clientid and gunid through to the timer
			new Handle:hPack = CreateDataPack();
			WritePackCell(hPack, iCid);
			WritePackCell(hPack, iEntid);

			CreateTimer(0.1,SoH_AutoshotgunStart,hPack);
			return;
		}

		else if (StrContains(stClass,"shotgun_spas",false) != -1)
		{
			//crate a pack to send clientid and gunid through to the timer
			new Handle:hPack = CreateDataPack();
			WritePackCell(hPack, iCid);
			WritePackCell(hPack, iEntid);

			CreateTimer(0.1,SoH_SpasShotgunStart,hPack);
			return;
		}

		else if (StrContains(stClass,"pumpshotgun",false) != -1
			|| StrContains(stClass,"shotgun_chrome",false) != -1)
		{
			//crate a pack to send clientid and gunid through to the timer
			new Handle:hPack = CreateDataPack();
			WritePackCell(hPack, iCid);
			WritePackCell(hPack, iEntid);

			CreateTimer(0.1,SoH_PumpshotgunStart,hPack);
			return;
		}
	}
}

//called for mag loaders
SoH_MagStart (iEntid, iCid)
{
	//----DEBUG----
	//PrintToChatAll("\x05-magazine loader detected,\x03 gametime \x01%f", GetGameTime());

	new Float:flGameTime = GetGameTime();
	new Float:flNextTime_ret = GetEntDataFloat(iEntid,g_iNextPAttO);

	//----DEBUG----
	/*PrintToChatAll("\x03- pre, gametime \x01%f\x03, retrieved nextattack\x01 %i %f\x03, retrieved time idle \x01%i %f",
		flGameTime,
		g_iNextAttO,
		GetEntDataFloat(iCid,g_iNextAttO),
		g_iTimeIdleO,
		GetEntDataFloat(iEntid,g_iTimeIdleO)
		);*/

	//this is a calculation of when the next primary attack
	//will be after applying sleight of hand values
	//NOTE: at this point, only calculate the interval itself,
	//without the actual game engine time factored in
	new Float:flNextTime_calc = ( flNextTime_ret - flGameTime ) * g_flSoH_rate ;

	//we change the playback rate of the gun
	//just so the player can "see" the gun reloading faster
	SetEntDataFloat(iEntid, g_iPlayRateO, 1.0/g_flSoH_rate, true);

	//create a timer to reset the playrate after
	//time equal to the modified attack interval
	CreateTimer( flNextTime_calc, SoH_MagEnd, iEntid);

	//experiment to remove double-playback bug
	new Handle:hPack = CreateDataPack();
	WritePackCell(hPack, iCid);
	//this calculates the equivalent time for the reload to end
	//if the survivor didn't have the SoH perk
	new Float:flStartTime_calc = flGameTime - ( flNextTime_ret - flGameTime ) * ( 1 - g_flSoH_rate ) ;
	WritePackFloat(hPack, flStartTime_calc);
	//now we create the timer that will prevent the annoying double playback
	if ( (flNextTime_calc - 0.4) > 0 )
		CreateTimer( flNextTime_calc - 0.4 , SoH_MagEnd2, hPack);

	//and finally we set the end reload time into the gun
	//so the player can actually shoot with it at the end
	flNextTime_calc += flGameTime;
	SetEntDataFloat(iEntid, g_iTimeIdleO, flNextTime_calc, true);
	SetEntDataFloat(iEntid, g_iNextPAttO, flNextTime_calc, true);
	SetEntDataFloat(iCid, g_iNextAttO, flNextTime_calc, true);

	//----DEBUG----
	/*PrintToChatAll("\x03- post, calculated nextattack \x01%f\x03, gametime \x01%f\x03, retrieved nextattack\x01 %i %f\x03, retrieved time idle \x01%i %f",
		flNextTime_calc,
		flGameTime,
		g_iNextAttO,
		GetEntDataFloat(iCid,g_iNextAttO),
		g_iTimeIdleO,
		GetEntDataFloat(iEntid,g_iTimeIdleO)
		);*/
}

//called for autoshotguns
public Action:SoH_AutoshotgunStart (Handle:timer, Handle:hPack)
{
	KillTimer(timer);
	if (IsServerProcessing()==false)
		return Plugin_Stop;

	ResetPack(hPack);
	new iCid = ReadPackCell(hPack);
	new iEntid = ReadPackCell(hPack);
	CloseHandle(hPack);
	hPack = CreateDataPack();
	WritePackCell(hPack, iCid);
	WritePackCell(hPack, iEntid);

	if (iCid <= 0
		|| iEntid <= 0
		|| IsValidEntity(iCid)==false
		|| IsValidEntity(iEntid)==false
		|| IsClientInGame(iCid)==false)
		return Plugin_Stop;

	//----DEBUG----
	/*PrintToChatAll("\x03-autoshotgun detected, iEntid \x01%i\x03, startO \x01%i\x03, insertO \x01%i\x03, endO \x01%i",
		iEntid,
		g_iShotStartDurO,
		g_iShotInsertDurO,
		g_iShotEndDurO
		);
	PrintToChatAll("\x03- pre mod, start \x01%f\x03, insert \x01%f\x03, end \x01%f",
		g_flSoHAutoS,
		g_flSoHAutoI,
		g_flSoHAutoE
		);*/
				
	//then we set the new times in the gun
	SetEntDataFloat(iEntid,	g_iShotStartDurO,	g_flSoHAutoS*g_flSoH_rate,	true);
	SetEntDataFloat(iEntid,	g_iShotInsertDurO,	g_flSoHAutoI*g_flSoH_rate,	true);
	SetEntDataFloat(iEntid,	g_iShotEndDurO,		g_flSoHAutoE*g_flSoH_rate,	true);

	//we change the playback rate of the gun
	//just so the player can "see" the gun reloading faster
	SetEntDataFloat(iEntid, g_iPlayRateO, 1.0/g_flSoH_rate, true);

	//and then call a timer to periodically check whether the
	//gun is still reloading or not to reset the animation
	//but first check the reload state; if it's 2, then it
	//needs a pump/cock before it can shoot again, and thus
	//needs more time
	if (g_iL4D_12 == 2)
		CreateTimer(0.3,SoH_ShotgunEnd,hPack,TIMER_REPEAT);
	else if (g_iL4D_12 == 1)
	{
		if (GetEntData(iEntid,g_iShotRelStateO)==2)
			CreateTimer(0.3,SoH_ShotgunEndCock,hPack,TIMER_REPEAT);
		else
			CreateTimer(0.3,SoH_ShotgunEnd,hPack,TIMER_REPEAT);
	}

	//----DEBUG----
	/*PrintToChatAll("\x03- after mod, start \x01%f\x03, insert \x01%f\x03, end \x01%f",
		g_flSoHAutoS,
		g_flSoHAutoI,
		g_flSoHAutoE
		);*/

	return Plugin_Stop;
}

public Action:SoH_SpasShotgunStart (Handle:timer, Handle:hPack)
{
	KillTimer(timer);
	if (IsServerProcessing()==false)
		return Plugin_Stop;

	ResetPack(hPack);
	new iCid = ReadPackCell(hPack);
	new iEntid = ReadPackCell(hPack);
	CloseHandle(hPack);
	hPack = CreateDataPack();
	WritePackCell(hPack, iCid);
	WritePackCell(hPack, iEntid);

	if (iCid <= 0
		|| iEntid <= 0
		|| IsValidEntity(iCid)==false
		|| IsValidEntity(iEntid)==false
		|| IsClientInGame(iCid)==false)
		return Plugin_Stop;

	//----DEBUG----
	/*PrintToChatAll("\x03-autoshotgun detected, iEntid \x01%i\x03, startO \x01%i\x03, insertO \x01%i\x03, endO \x01%i",
		iEntid,
		g_iShotStartDurO,
		g_iShotInsertDurO,
		g_iShotEndDurO
		);
	PrintToChatAll("\x03- pre mod, start \x01%f\x03, insert \x01%f\x03, end \x01%f",
		g_flSoHSpasS,
		g_flSoHSpasI,
		g_flSoHSpasE
		);*/
				
	//then we set the new times in the gun
	SetEntDataFloat(iEntid,	g_iShotStartDurO,	g_flSoHSpasS*g_flSoH_rate,	true);
	SetEntDataFloat(iEntid,	g_iShotInsertDurO,	g_flSoHSpasI*g_flSoH_rate,	true);
	SetEntDataFloat(iEntid,	g_iShotEndDurO,		g_flSoHSpasE*g_flSoH_rate,	true);

	//we change the playback rate of the gun
	//just so the player can "see" the gun reloading faster
	SetEntDataFloat(iEntid, g_iPlayRateO, 1.0/g_flSoH_rate, true);

	//and then call a timer to periodically check whether the
	//gun is still reloading or not to reset the animation
	//but first check the reload state; if it's 2, then it
	//needs a pump/cock before it can shoot again, and thus
	//needs more time
	CreateTimer(0.3,SoH_ShotgunEnd,hPack,TIMER_REPEAT);

	//----DEBUG----
	/*PrintToChatAll("\x03- after mod, start \x01%f\x03, insert \x01%f\x03, end \x01%f",
		g_flSoHSpasS,
		g_flSoHSpasI,
		g_flSoHSpasE
		);*/

	return Plugin_Stop;
}

//called for pump shotguns
public Action:SoH_PumpshotgunStart (Handle:timer, Handle:hPack)
{
	KillTimer(timer);
	if (IsServerProcessing()==false)
		return Plugin_Stop;

	ResetPack(hPack);
	new iCid = ReadPackCell(hPack);
	new iEntid = ReadPackCell(hPack);
	CloseHandle(hPack);
	hPack = CreateDataPack();
	WritePackCell(hPack, iCid);
	WritePackCell(hPack, iEntid);

	if (iCid <= 0
		|| iEntid <= 0
		|| IsValidEntity(iCid)==false
		|| IsValidEntity(iEntid)==false
		|| IsClientInGame(iCid)==false)
		return Plugin_Stop;

	//----DEBUG----
	/*PrintToChatAll("\x03-pumpshotgun detected, iEntid \x01%i\x03, startO \x01%i\x03, insertO \x01%i\x03, endO \x01%i",
		iEntid,
		g_iShotStartDurO,
		g_iShotInsertDurO,
		g_iShotEndDurO
		);
	PrintToChatAll("\x03- pre mod, start \x01%f\x03, insert \x01%f\x03, end \x01%f",
		g_flSoHPumpS,
		g_flSoHPumpI,
		g_flSoHPumpE
		);*/

	//then we set the new times in the gun
	SetEntDataFloat(iEntid,	g_iShotStartDurO,	g_flSoHPumpS*g_flSoH_rate,	true);
	SetEntDataFloat(iEntid,	g_iShotInsertDurO,	g_flSoHPumpI*g_flSoH_rate,	true);
	SetEntDataFloat(iEntid,	g_iShotEndDurO,		g_flSoHPumpE*g_flSoH_rate,	true);

	//we change the playback rate of the gun
	//just so the player can "see" the gun reloading faster
	SetEntDataFloat(iEntid, g_iPlayRateO, 1.0/g_flSoH_rate, true);

	//and then call a timer to periodically check whether the
	//gun is still reloading or not to reset the animation
	if (g_iL4D_12 == 2)
		CreateTimer(0.3,SoH_ShotgunEnd,hPack,TIMER_REPEAT);
	else if (g_iL4D_12 == 1)
	{
		if (GetEntData(iEntid,g_iShotRelStateO)==2)
			CreateTimer(0.3,SoH_ShotgunEndCock,hPack,TIMER_REPEAT);
		else
			CreateTimer(0.3,SoH_ShotgunEnd,hPack,TIMER_REPEAT);
	}

	//----DEBUG----
	/*PrintToChatAll("\x03- after mod, start \x01%f\x03, insert \x01%f\x03, end \x01%f",
		g_flSoHPumpS,
		g_flSoHPumpI,
		g_flSoHPumpE
		);*/

	return Plugin_Stop;
}

//this resets the playback rate on non-shotguns
public Action:SoH_MagEnd (Handle:timer, any:iEntid)
{
	KillTimer(timer);
	if (IsServerProcessing()==false)
		return Plugin_Stop;

	//----DEBUG----
	//PrintToChatAll("\x03SoH reset playback, magazine loader");

	if (iEntid <= 0
		|| IsValidEntity(iEntid)==false)
		return Plugin_Stop;

	SetEntDataFloat(iEntid, g_iPlayRateO, 1.0, true);

	return Plugin_Stop;
}

public Action:SoH_MagEnd2 (Handle:timer, Handle:hPack)
{
	KillTimer(timer);
	if (IsServerProcessing()==false)
	{
		CloseHandle(hPack);
		return Plugin_Stop;
	}

	//----DEBUG----
	//PrintToChatAll("\x03SoH reset playback, magazine loader");

	ResetPack(hPack);
	new iCid = ReadPackCell(hPack);
	new Float:flStartTime_calc = ReadPackFloat(hPack);
	CloseHandle(hPack);

	if (iCid <= 0
		|| IsValidEntity(iCid)==false
		|| IsClientInGame(iCid)==false)
		return Plugin_Stop;

	//experimental, remove annoying double-playback
	new iVMid = GetEntDataEnt2(iCid,g_iViewModelO);
	SetEntDataFloat(iVMid, g_iVMStartTimeO, flStartTime_calc, true);

	//----DEBUG----
	//PrintToChatAll("\x03- end SoH mag loader, icid \x01%i\x03 starttime \x01%f\x03 gametime \x01%f", iCid, flStartTime_calc, GetGameTime());

	return Plugin_Stop;
}

public Action:SoH_ShotgunEnd (Handle:timer, Handle:hPack)
{
	//----DEBUG----
	//PrintToChatAll("\x03-autoshotgun tick");

	ResetPack(hPack);
	new iCid = ReadPackCell(hPack);
	new iEntid = ReadPackCell(hPack);

	if (IsServerProcessing()==false
		|| iCid <= 0
		|| iEntid <= 0
		|| IsValidEntity(iCid)==false
		|| IsValidEntity(iEntid)==false
		|| IsClientInGame(iCid)==false)
	{
		KillTimer(timer);
		return Plugin_Stop;
	}

	if (GetEntData(iEntid,g_iShotRelStateO)==0)
	{
		//----DEBUG----
		//PrintToChatAll("\x03-shotgun end reload detected");

		SetEntDataFloat(iEntid, g_iPlayRateO, 1.0, true);

		//new iCid=GetEntPropEnt(iEntid,Prop_Data,"m_hOwner");
		new Float:flTime=GetGameTime()+0.2;
		SetEntDataFloat(iCid,	g_iNextAttO,	flTime,	true);
		SetEntDataFloat(iEntid,	g_iTimeIdleO,	flTime,	true);
		SetEntDataFloat(iEntid,	g_iNextPAttO,	flTime,	true);

		KillTimer(timer);
		CloseHandle(hPack);
		return Plugin_Stop;
	}

	return Plugin_Continue;
}

//since cocking requires more time, this function does
//exactly as the above, except it adds slightly more time
public Action:SoH_ShotgunEndCock (Handle:timer, any:hPack)
{
	//----DEBUG----
	//PrintToChatAll("\x03-autoshotgun tick");

	ResetPack(hPack);
	new iCid = ReadPackCell(hPack);
	new iEntid = ReadPackCell(hPack);

	if (IsServerProcessing()==false
		|| iCid <= 0
		|| iEntid <= 0
		|| IsValidEntity(iCid)==false
		|| IsValidEntity(iEntid)==false
		|| IsClientInGame(iCid)==false)
	{
		KillTimer(timer);
		return Plugin_Stop;
	}

	if (GetEntData(iEntid,g_iShotRelStateO)==0)
	{
		//----DEBUG----
		//PrintToChatAll("\x03-shotgun end reload + cock detected");

		SetEntDataFloat(iEntid, g_iPlayRateO, 1.0, true);

		//new iCid=GetEntPropEnt(iEntid,Prop_Data,"m_hOwner");
		new Float:flTime= GetGameTime() + 1.0;
		SetEntDataFloat(iCid,	g_iNextAttO,	flTime,	true);
		SetEntDataFloat(iEntid,	g_iTimeIdleO,	flTime,	true);
		SetEntDataFloat(iEntid,	g_iNextPAttO,	flTime,	true);

		KillTimer(timer);
		CloseHandle(hPack);
		return Plugin_Stop;
	}

	return Plugin_Continue;
}



//=============================
// Sur1: Pyrotechnician
//=============================

//on pickup
Pyro_Pickup(iCid, String:stWpn[])
{
	if (g_iSur1[iCid]==4
		&& g_iSur1_enable==1
		&& (g_iPyro_enable==1		&&	g_iL4D_GameMode==0
		|| g_iPyro_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iPyro_enable_vs==1		&&	g_iL4D_GameMode==2))
	{
		//only bother with checks if they aren't throwing
		if (g_iGrenThrow[iCid]==0)
		{
			//check if the weapon is a grenade type
			if (StrEqual(stWpn,"pipe_bomb",false)==true
				|| StrEqual(stWpn,"molotov",false)==true
				|| StrEqual(stWpn,"vomitjar",false)==true)
			{
				decl String:stWpn2[24];
				if (stWpn[0]=='p')
					stWpn2="土制炸弹";
				else if (stWpn[0]=='v' && g_iL4D_12 == 2)
					stWpn2="胆汁";
				else
					stWpn2="燃烧弹";
				//if so, then check if either 0 or 2 are being carried
				//if true, then act normally and give player 2 grenades
				if (g_iGren[iCid]==0
					|| g_iGren[iCid]==2)
				{
					g_iGren[iCid]=2;
					PrintHintText(iCid,"炸弹专家: %t %i %s(s)", "GrenadierCarryHint", g_iGren[iCid], stWpn2);
				}
				//otherwise, only give them one and tell them to
				//throw the grenade before picking up another one;
				//this is to prevent abuses with throwing infinite nades
				else
				{
					g_iGren[iCid]=1;
					PrintHintText(iCid,"%t %s! %t", "GrenadierCantTake2Grenades_A", stWpn2, "GrenadierCantTake2Grenades_B");
				}
			}
		}
		//if they are in the middle of throwing, then reset the var
		else if (g_iGrenThrow[iCid]==1)
			g_iGrenThrow[iCid]=0;
	}
}

//called when tossing
Pyro_OnWeaponFire(iCid, String:stWpn[])
{
	//check if perk is enabled
	if (g_iSur1_enable==0
		|| g_iPyro_enable==0		&&	g_iL4D_GameMode==0
		|| g_iPyro_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iPyro_enable_vs==0		&&	g_iL4D_GameMode==2)
		return;

	if (g_iConfirm[iCid]==0
		|| g_iSur1[iCid]!=4) return;

	//----DEBUG----
	//PrintToChatAll("\x03 weapon fired: \x01%s", st_wpn);

	new bool:bPipe=StrEqual(stWpn,"pipe_bomb",false);
	new bool:bMol=StrEqual(stWpn,"molotov",false);
	new bool:bVomit=StrEqual(stWpn,"vomitjar",false);
	if (bPipe || bMol || bVomit)
	{
		g_iGren[iCid]--;		//reduce count by 1
		decl String:stWpn2[24];

		if (g_iGren[iCid]>0)		//do they still have grenades left?
		{
			if (bPipe==true)
			{
				g_iGrenType[iCid]=1;
				stWpn2="土制炸弹";
			}
			else if (bMol==true)
			{
				g_iGrenType[iCid]=2;
				stWpn2="燃烧弹";
			}
			else
			{
				g_iGrenType[iCid]=3;
				stWpn2="胆汁";
			}

			PrintHintText(iCid,"炸弹专家: %t %i %s(s) %t", "GrenadierCounter_A", g_iGren[iCid], stWpn2, "GrenadierCounter_B");
			CreateTimer(2.5,Grenadier_DelayedGive,iCid);
		}
	}
}

//gives the grenade a few seconds later 
//(L4D takes a while to remove the grenade from inventory after it's been thrown)
public Action:Grenadier_DelayedGive (Handle:timer,any:iCid)
{
	KillTimer(timer);
	if (IsServerProcessing()==false)
		return Plugin_Stop;

	if (iCid==0
		|| g_iConfirm[iCid]==0
		|| g_iSur1[iCid]!=4)
		return Plugin_Continue;

	new iflags=GetCommandFlags("give");
	new String:st_give[24];

	if (g_iGrenType[iCid]==1)
		st_give="give pipe_bomb";
	else if (g_iGrenType[iCid]==2)
		st_give="give molotov";
	else
		st_give="give vomitjar";

	g_iGrenType[iCid]=0;
	g_iGrenThrow[iCid]=1;	//client now considered to be "in the middle of throwing"
	SetCommandFlags("give", iflags & ~FCVAR_CHEAT);
	FakeClientCommand(iCid,st_give);
	SetCommandFlags("give", iflags);

	return Plugin_Stop;
}

//called on roundstarts or on confirming perks
//gives a random grenade to the player
Event_Confirm_Grenadier (iCid)
{
	if (iCid==0
		|| GetClientTeam(iCid)!=2
		|| IsPlayerAlive(iCid)==false
		|| g_iConfirm[iCid]==0
		|| g_iSur1[iCid]!=4)
		return;

	//check if perk is enabled
	if (g_iSur1_enable==0
		|| g_iPyro_enable==0		&&	g_iL4D_GameMode==0
		|| g_iPyro_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iPyro_enable_vs==0		&&	g_iL4D_GameMode==2)
		return;

	//reset grenade count on player
	g_iGren[iCid]=0;

	new iflags=GetCommandFlags("give");
	new String:st_give[24];

	decl iMax;
	if (g_iL4D_12 == 2)
		iMax = 2;
	else if (g_iL4D_12 == 1)
		iMax = 1;

	new iI=GetRandomInt(0,iMax);
	if (iI==0)
		st_give="give pipe_bomb";
	else if (iI==1)
		st_give="give molotov";
	else if (iI==2)
		st_give="give vomitjar";

	SetCommandFlags("give", iflags & ~FCVAR_CHEAT);
	FakeClientCommand(iCid,st_give);
	SetCommandFlags("give", iflags);
	return;
}



//=============================
// Sur1: Martial Artist
//=============================

MA_RunChecks ()
{
	if (g_iSur1_enable==1
		|| (g_iMA_enable==1		&&	g_iL4D_GameMode==0)
		|| (g_iMA_enable_sur==1	&&	g_iL4D_GameMode==1)
		|| (g_iMA_enable_vs==1	&&	g_iL4D_GameMode==2))
		g_iMA_meta_enable=1;
	else
		g_iMA_meta_enable=0;
}

//called on confirming perks
//adds player to registry of MA users
//and sets movement speed
Event_Confirm_MA (iCid, iWeapon=0)
{
	if (g_iMARegisterCount<0)
		g_iMARegisterCount=0;

	//check if perk is enabled
	if (g_iSur1_enable==0
		|| g_iMA_enable==0		&&	g_iL4D_GameMode==0
		|| g_iMA_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iMA_enable_vs==0	&&	g_iL4D_GameMode==2)
		return;

	if (IsClientInGame(iCid)==true
		&& IsPlayerAlive(iCid)==true
		&& g_iSur1[iCid]==5
		&& g_iConfirm[iCid]==1
		&& GetClientTeam(iCid)==2)
	{
		g_iMARegisterCount++;
		g_iMARegisterIndex[g_iMARegisterCount]=iCid;

		//give player the weapon of choice
		//0 = nothing
		//1 = baseball bat
		//2 = cricket bat
		//3 = crowbar
		//4 = electric guitar
		//5 = fire axe
		//6 = frying pan
		//7 = katana
		//8 = machete
		//9 = tonfa
		decl String:stS[MAXPLAYERS+1];
		switch (iWeapon)
		{
		case 1:
			stS="give rifle_m60";
		}

		//----DEBUG----
		//PrintToChatAll("\x03martial artist on confirm, registering \x01%i",iCid);
	}	
}

//called whenever the registry needs to be rebuilt
//to cull any players who have left or died, etc.
//resets survivor's speeds and reassigns speed boost
//(called on: player death, player disconnect,
//closet rescue, change teams, convar change)
MA_Rebuild ()
{
	//clears all DT-related vars
	MA_Clear();

	//if the server's not running or
	//is in the middle of loading, stop
	if (IsServerProcessing()==false)
		return;

	//check if perk is enabled
	if (g_iSur1_enable==0
		|| g_iMA_enable==0		&&	g_iL4D_GameMode==0
		|| g_iMA_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iMA_enable_vs==0	&&	g_iL4D_GameMode==2)
		return;

	//----DEBUG----
	//PrintToChatAll("\x03martial artist rebuilding registry");

	for (new iI=1 ; iI<=MaxClients ; iI++)
	{
		if (IsClientInGame(iI)==true
			&& IsPlayerAlive(iI)==true
			&& g_iSur1[iI]==5
			&& g_iConfirm[iI]==1
			&& GetClientTeam(iI)==2)
		{
			g_iMARegisterCount++;
			g_iMARegisterIndex[g_iMARegisterCount]=iI;

			//----DEBUG----
			//PrintToChatAll("\x03-registering \x01%i",iI);
		}
	}
}

//called to clear out registry
//and reset movement speeds
//(called on: round start, round end, map end)
MA_Clear ()
{
	g_iMARegisterCount=0;
	for (new iI=1 ; iI<=MaxClients ; iI++)
	{
		g_iMARegisterIndex[iI]= -1;
	}
}

MA_OnGameFrame()
{
	//stop if MA is disabled in any way
	if (g_iMA_meta_enable==0)
		return 0;

	//or if no one has DT, don't bother either
	if (g_iMARegisterCount==0)
		return 0;

	decl iCid;
	//this tracks the player's ability id
	decl iEntid;
	//this tracks the calculated next attack
	decl Float:flNextTime_calc;
	//this, on the other hand, tracks the current next attack
	decl Float:flNextTime_ret;
	//and this tracks the game time
	new Float:flGameTime=GetGameTime();

	for (new iI=1; iI<=g_iMARegisterCount; iI++)
	{
		//PRE-CHECKS 1: RETRIEVE VARS
		//---------------------------

		iCid = g_iMARegisterIndex[iI];
		//stop on this client
		//when the next client id is null
		if (iCid <= 0) return 0;
		//skip this client if they're disabled, or, you know, dead
		if (g_iMyDisabler[iCid] != -1) continue;
		if (IsPlayerAlive(iCid)==false) continue;

		//we have to adjust numbers on the gun, not the player
		//so we get the active weapon id here
		iEntid = GetEntDataEnt2(iCid,g_iActiveWO);
		//if the retrieved gun id is -1, then...
		//wtf mate? just move on
		if (iEntid == -1) continue;
		//and here is the retrieved next attack time
		flNextTime_ret = GetEntDataFloat(iEntid,g_iNextPAttO);

		//----DEBUG----
		//PrintToChat(iCid,"\x03shove penalty \x01%i\x03, max penalty \x01%i",GetEntData(iCid,g_iMeleeFatigueO), g_iMA_maxpenalty);

		//PRE-CHECKS 2: MOD SHOVE FATIGUE
		//-------------------------------
		if ( GetEntData(iCid,g_iMeleeFatigueO) > g_iMA_maxpenalty )
		{
			SetEntData(iCid, g_iMeleeFatigueO, g_iMA_maxpenalty);
		}





		//CHECK 1: IS PLAYER USING A KNOWN NON-MELEE WEAPON?
		//--------------------------------------------------
		//as the title states... to conserve processing power,
		//if the player's holding a gun for a prolonged time
		//then we want to be able to track that kind of state
		//and not bother with any checks
		//checks: weapon is non-melee weapon
		//actions: do nothing
		if (iEntid == g_iMAEntid_notmelee[iCid])
		{
			//----DEBUG----
			//PrintToChatAll("\x03MA client \x01%i\x03; non melee weapon, ignoring",iCid );

			g_iMAAttCount[iCid] = 0;
			continue;
		}



		//PRE CHECK 1.5
		//-------------
		new iMAEntid = g_iMAEntid[iCid];
		new iMAAttCount = g_iMAAttCount[iCid];

		//CHECK 1.5: THE PLAYER HASN'T SWUNG HIS WEAPON FOR A WHILE
		//-------------------------------------------------------
		//in this case, if the player made 1 swing of his 2 strikes,
		//and then paused long enough, we should reset his strike count
		//so his next attack will allow him to strike twice
		//checks: is the delay between attacks greater than 0.8s?
		//actions: set attack count to 0, and CONTINUE CHECKS
		if (iMAEntid == iEntid
			&& iMAAttCount != 0
			&& (flGameTime - flNextTime_ret) > 0.8)
		{
			//----DEBUG----
			//PrintToChatAll("\x03MA client \x01%i\x03; hasn't swung weapon",iCid );

			g_iMAAttCount[iCid] = 0;
		}



		//PRE CHECK 2
		//-----------
		new Float:flMANextTime = g_flMANextTime[iCid];

		//CHECK 2: BEFORE ADJUSTED ATT IS MADE
		//------------------------------------
		//since this will probably be the case most of
		//the time, we run this first
		//checks: weapon is unchanged; time of shot has not passed
		//actions: do nothing
		if (iMAEntid == iEntid
			&& flMANextTime >= flNextTime_ret)
		{
			//----DEBUG----
			//PrintToChatAll("\x03DT client \x01%i\x03; before shot made",iCid );

			continue;
		}



		//CHECK 3: AFTER ADJUSTED ATT IS MADE
		//------------------------------------
		//at this point, either a gun was swapped, or
		//the attack time needs to be adjusted
		//checks: stored gun id same as retrieved gun id,
		// and retrieved next attack time is after stored value
		//actions: adjusts next attack time
		if (iMAEntid == iEntid
			&& flMANextTime < flNextTime_ret)
		{
			//----DEBUG----
			//PrintToChatAll("\x03DT after adjusted shot\n-pre, client \x01%i\x03; entid \x01%i\x03; enginetime\x01 %f\x03; NextTime_orig \x01 %f\x03; interval \x01%f",iCid,iEntid,flGameTime,flNextTime_ret, flNextTime_ret-flGameTime );
			//new Float:flNextTime_retSA = GetEntDataFloat(iEntid,g_iNextSAttO);
			//PrintToChatAll("\x05DT\x03 enginetime\x01 %f\x03; nextPA \x01%f\x03; PAinterval \x01%f\x03\n nextSA \x01%f\x03 SAinterval \x01%f", flGameTime, flNextTime_ret, flNextTime_ret-flGameTime, flNextTime_retSA, flNextTime_retSA-flGameTime );



			//> CHECK FOR SHOVES/WEAPON DRAWS
			//-------------------------------
			new Float:flInterval = flNextTime_ret-flGameTime;
			if (flInterval > 0.7331
				&& flInterval < 0.7335)
			{
				//----DEBUG----
				//PrintToChatAll("\x05DT\x03 shove inferred");

				g_flMANextTime[iCid] = flNextTime_ret;
				continue;
			}
			if (flInterval < 0.534)
			{
				//----DEBUG----
				//PrintToChatAll("\x05DT\x03 weapon draw inferred");

				g_flMANextTime[iCid] = flNextTime_ret;
				continue;
			}


			g_iMAAttCount[iCid]++;
			if (g_iMAAttCount[iCid]>2)
				g_iMAAttCount[iCid]=0;
			iMAAttCount = g_iMAAttCount[iCid];

			//> MOD ATTACK
			//------------
			if (iMAAttCount == 1
				|| iMAAttCount == 2)
			{
				//this is a calculation of when the next primary attack
				//will be after applying double tap values
				//flNextTime_calc = ( flNextTime_ret - flGameTime ) * g_flMA_attrate + flGameTime;
				flNextTime_calc = flGameTime + 0.3 ;

				//then we store the value
				g_flMANextTime[iCid] = flNextTime_calc;

				//and finally adjust the value in the gun
				SetEntDataFloat(iEntid, g_iNextPAttO, flNextTime_calc, true);

				//----DEBUG----
				//PrintToChatAll("\x03-post, NextTime_calc \x01 %f\x03; new interval \x01%f",GetEntDataFloat(iEntid,g_iNextPAttO), GetEntDataFloat(iEntid,g_iNextPAttO)-flGameTime );

				continue;
			}

			//> DON'T MOD ATTACK
			//------------------
			if (g_iMAAttCount[iCid]==0)
			{
				g_flMANextTime[iCid] = flNextTime_ret;
				continue;
			}
		}



		//CHECK 4: CHECK THE WEAPON
		//-------------------------
		//lastly, at this point we need to check if we are, in fact,
		//using a melee weapon =P we check if the current weapon is
		//the same one stored in memory; if it is, move on;
		//otherwise, check if it's a melee weapon - if it is,
		//store and continue; else, continue.
		//checks: if the active weapon is a melee weapon
		//actions: store the weapon's entid into either
		// the known-melee or known-non-melee variable

		//----DEBUG----
		//PrintToChatAll("\x03DT client \x01%i\x03; weapon switch inferred",iCid );

		//check if the weapon is a melee
		decl String:stName[32];
		GetEntityNetClass(iEntid,stName,32);
		if (StrEqual(stName,"CTerrorMeleeWeapon",false)==true)
		{
			//if yes, then store in known-melee var
			g_iMAEntid[iCid]=iEntid;
			g_flMANextTime[iCid]=flNextTime_ret;
			continue;
		}
		else
		{
			//if no, then store in known-non-melee var
			g_iMAEntid_notmelee[iCid]=iEntid;
			continue;
		}
	}

	return 0;
}



//=============================
// Sur2: Unbreakable
//=============================

//on heal; gives 80% of bonus hp
Unbreakable_OnHeal (iCid)
{
	//check if perk is enabled
	if (g_iSur2_enable==0
		|| g_iUnbreak_enable==0			&&	g_iL4D_GameMode==0
		|| g_iUnbreak_enable_sur==0		&&	g_iL4D_GameMode==1
		|| g_iUnbreak_enable_vs==0		&&	g_iL4D_GameMode==2)
		return;

	if (g_iSur2[iCid]==1)
	{
		CreateTimer(0.5,Unbreakable_Delayed_Heal,iCid);
		//SetEntProp(iCid,Prop_Data,"m_iHealth", GetEntProp(iCid,Prop_Data,"m_iHealth")+(g_iUnbreak_hp*8/10) );

		//run a check to see if for whatever reason
		//the player's health is above 200
		//since 200 is the clamped maximum for unbreakable
		//in which case we set their health to 200
		if (GetEntProp(iCid,Prop_Data,"m_iHealth") > 200)
			CreateTimer(0.5,Unbreakable_Delayed_SetHigh,iCid);

		PrintHintText(iCid,"血量上升: %t!", "UnbreakableHint");
	}
}

//called when player confirms his choices;
//gives 30 hp (to bring hp to 130, assuming survivor
//wasn't stupid and got himself hurt before confirming perks)
Event_Confirm_Unbreakable (iCid)
{
	new iHP=GetEntProp(iCid,Prop_Data,"m_iHealth");
	if (iCid==0 || g_iConfirm[iCid]==0) return;
	new TC=GetClientTeam(iCid);

	//check if perk is enabled
	if (g_iSur2_enable==0
		|| g_iUnbreak_enable==0			&&	g_iL4D_GameMode==0
		|| g_iUnbreak_enable_sur==0		&&	g_iL4D_GameMode==1
		|| g_iUnbreak_enable_vs==0		&&	g_iL4D_GameMode==2)
	{
		//if not, check if hp is higher than it should be
		if (iHP>100
			&& TC==2)
		{
			//if it IS higher, reduce hp to 100
			//otherwise, no way to know whether previous owner
			//had unbreakable, so give the incoming player
			//the benefit of doubt
			CreateTimer(0.5,Unbreakable_Delayed_SetLow,iCid);
		}
		return;
	}

	//if we've gotten up to this point, the perk is enabled
	if (g_iSur2[iCid]==1
		&& TC==2)
	{
		if (iHP>100
			&& iHP < (100+g_iUnbreak_hp) )
			CreateTimer(0.5,Unbreakable_Delayed_Max,iCid);
		else if (iHP<=100)
			CreateTimer(0.5,Unbreakable_Delayed_Normal,iCid);
		PrintHintText(iCid,"血量上升: %t!", "UnbreakableHint");

		//run a check to see if for whatever reason
		//the player's health is above 200
		//since 200 is the clamped maximum for unbreakable
		//in which case we set their health to 200
		if (GetEntProp(iCid,Prop_Data,"m_iHealth") > 200)
			CreateTimer(0.5,Unbreakable_Delayed_SetHigh,iCid);
	}
	//if not, check if hp is higher than it should be
	else if (g_iSur2[iCid]!=1
		&& iHP>100
		&& TC==2)
	{
		//if it IS higher, reduce hp to 100
		//otherwise, no way to know whether previous owner
		//had unbreakable, so give the incoming player
		//the benefit of doubt
		CreateTimer(0.5,Unbreakable_Delayed_SetLow,iCid);
	}
}

//on rescue; gives 50% of bonus hp
Unbreakable_OnRescue (iCid)
{
	if (g_iSur2[iCid]==1)
	{
		//check if perk is enabled
		if (g_iSur2_enable==0
			|| g_iUnbreak_enable==0			&&	g_iL4D_GameMode==0
			|| g_iUnbreak_enable_sur==0		&&	g_iL4D_GameMode==1
			|| g_iUnbreak_enable_vs==0		&&	g_iL4D_GameMode==2)
			return;

		CreateTimer(0.5,Unbreakable_Delayed_Rescue,iCid);
		PrintHintText(iCid,"血量上升: %t!", "UnbreakableHint");

		//run a check to see if for whatever reason
		//the player's health is above 200
		//since 200 is the clamped maximum for unbreakable
		//in which case we set their health to 200
		if (GetEntProp(iCid,Prop_Data,"m_iHealth") > 200)
			CreateTimer(0.5,Unbreakable_Delayed_SetHigh,iCid);
	}
}

//on revive; gives 50% of bonus hp in temp hp
Unbreakable_OnRevive (iSub, iLedge)
{
	//check for unbreakable for the subject
	//only fires if they were NOT hanging from a ledge
	if (g_iSur2[iSub]==1
		&& g_iConfirm[iSub]==1
		&& iLedge == 0)
	{
		//check if perk is enabled
		if (g_iSur1_enable==1
			&& (g_iUnbreak_enable==1	&&	g_iL4D_GameMode==0
			|| g_iUnbreak_enable_sur==1	&&	g_iL4D_GameMode==1
			|| g_iUnbreak_enable_vs==1	&&	g_iL4D_GameMode==2))
		{
			SetEntDataFloat(iSub,g_iHPBuffO, GetEntDataFloat(iSub,g_iHPBuffO)+(g_iUnbreak_hp/2) ,true);
			PrintHintText(iSub,"血量上升: %t!", "UnbreakableHint");
		}
	}
}

//these timer functions apply health bonuses
//after a delay, hopefully to avoid bugs
public Action:Unbreakable_Delayed_Max (Handle:timer, any:iCid)
{
	if (IsServerProcessing()==true
		&& IsValidEntity(iCid)==true
		&& IsClientInGame(iCid)==true)
		SetEntProp(iCid,Prop_Data,"m_iHealth", 100+g_iUnbreak_hp );

	KillTimer(timer);
	return Plugin_Stop;
}

public Action:Unbreakable_Delayed_Normal (Handle:timer, any:iCid)
{
	if (IsServerProcessing()==true
		&& IsValidEntity(iCid)==true
		&& IsClientInGame(iCid)==true)
	{
		SetEntProp(iCid,Prop_Data,"m_iHealth", GetEntProp(iCid,Prop_Data,"m_iHealth")+g_iUnbreak_hp );

		if (GetEntProp(iCid,Prop_Data,"m_iHealth") > (100+g_iUnbreak_hp) )
			SetEntProp(iCid,Prop_Data,"m_iHealth", 100+g_iUnbreak_hp );
	}

	KillTimer(timer);
	return Plugin_Stop;
}

public Action:Unbreakable_Delayed_Heal (Handle:timer, any:iCid)
{
	if (IsServerProcessing()==true
		&& IsValidEntity(iCid)==true
		&& IsClientInGame(iCid)==true)
	{
		SetEntProp(iCid,Prop_Data,"m_iHealth", GetEntProp(iCid,Prop_Data,"m_iHealth") + (g_iUnbreak_hp*8/10) );

		if (GetEntProp(iCid,Prop_Data,"m_iHealth") > (100+g_iUnbreak_hp) )
			SetEntProp(iCid,Prop_Data,"m_iHealth", 100+g_iUnbreak_hp );
	}

	KillTimer(timer);
	return Plugin_Stop;
}

public Action:Unbreakable_Delayed_Rescue (Handle:timer, any:iCid)
{
	if (IsServerProcessing()==true
		&& IsValidEntity(iCid)==true
		&& IsClientInGame(iCid)==true)
	{
		SetEntProp(iCid,Prop_Data,"m_iHealth", GetEntProp(iCid,Prop_Data,"m_iHealth") + (g_iUnbreak_hp/2) );

		if (GetEntProp(iCid,Prop_Data,"m_iHealth") > (100+g_iUnbreak_hp) )
			SetEntProp(iCid,Prop_Data,"m_iHealth", 100+g_iUnbreak_hp );
	}

	KillTimer(timer);
	return Plugin_Stop;
}

public Action:Unbreakable_Delayed_SetHigh (Handle:timer, any:iCid)
{
	if (IsServerProcessing()==true
		&& IsValidEntity(iCid)==true
		&& IsClientInGame(iCid)==true)
		SetEntProp(iCid,Prop_Data,"m_iHealth", 200 );

	KillTimer(timer);
	return Plugin_Stop;
}

public Action:Unbreakable_Delayed_SetLow (Handle:timer, any:iCid)
{
	if (IsServerProcessing()==true
		&& IsValidEntity(iCid)==true
		&& IsClientInGame(iCid)==true)
		SetEntProp(iCid,Prop_Data,"m_iHealth", 100 );

	KillTimer(timer);
	return Plugin_Stop;
}



//=============================
// Sur2: Spirit
//=============================

//called by global timer "TimerPerks"
//periodically runs checks to see if anyone should self-revive
//since sometimes self-revive won't fire if someone's being disabled
//by, say, a hunter
Spirit_Timer ()
{
	//check if perk is enabled
	if (g_iSur2_enable==0		
		|| g_iSpirit_enable==0		&&	g_iL4D_GameMode==0
		|| g_iSpirit_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iSpirit_enable_vs==0	&&	g_iL4D_GameMode==2)
		return;

	//this var counts how many people are incapped
	//but for the first part, it checks whether anyone has spirit
	new iCount=0;

	//preliminary check; if no one has
	//the spirit perk, this function will return
	for (new iI=1 ; iI<=MaxClients ; iI++)
	{
		if (g_iSur2[iI]==2)
		{
			iCount++;
			break;
		}
	}
	if (iCount<=0) return;
	else iCount=0;

	//----DEBUG----
	//PrintToChatAll("\x03spirit timer check");

	//this array will hold client ids
	//for the possible candidates for self-revives
	new iCid[18];

	for (new iI=1 ; iI<=MaxClients ; iI++)
	{
		//fill array with whoever's incapped
		if (IsClientInGame(iI)==true
			&& GetClientTeam(iI)==2
			&& GetEntData(iI,g_iIncapO) != 0 )
		{
			iCount++;
			iCid[iCount]=iI;

			//----DEBUG----
			//PrintToChatAll("\x03-incap registering \x01%i",iI);
		}
	}

	//if the first two client ids are null, or
	//if the count was zero OR one, return
	//since someone can't self-revive if they're
	//the only ones incapped!
	if (iCount<=1
		|| iCid[1]<=0
		|| iCid[2]<=0)
		return;

	//----DEBUG----
	//PrintToChatAll("\x03-beginning self-revive checks, iCount=\x01%i",iCount);

	//now we check for someone to revive
	//and we only revive one person at a time
	for (new iI=1 ; iI<=iCount ; iI++)
	{
		//----DEBUG----
		//PrintToChatAll("\x03- iledge value \x01%i",GetEntData(iCid[iI],g_iLedgeO));

		//client ids are stored incrementally (X in 1, Y in 2, Z in 3,...)
		//in the array iCid[], and iI increases per tick, hence this mess =P
		//in short, here we use iCid[iI], NOT iI!
		if (g_iConfirm[iCid[iI]]==1
			&& g_iSur2[iCid[iI]]==2
			&& g_iMyDisabler[iCid[iI]] == -1
			&& g_iSpiritCooldown[iCid[iI]]==0
			&& IsClientInGame(iCid[iI])==true
			&& IsPlayerAlive(iCid[iI])==true
			&& GetClientTeam(iCid[iI])==2)
		{
			//----DEBUG----
			//PrintToChatAll("\x03-reviving \x01%i",iCid[iI]);

			//retrieve revive count
			new iRevCount_ret = GetEntData(iCid[iI], g_iRevCountO, 1);

			//create a data pack to pass down info
			//so we effectively only execute spirit's state changes
			//if we detect that the self-revive did in fact execute
			new Handle:hPack = CreateDataPack();
			WritePackCell(hPack,iCid[iI]);
			WritePackCell(hPack,iRevCount_ret);

			//here we give health through the console command
			//which is used to revive the player (no other way
			//I know of, setting the m_isIncapacitated in
			//CTerrorPlayer revives them but they can't move!)
			new iflags=GetCommandFlags("give");
			SetCommandFlags("give", iflags & ~FCVAR_CHEAT);
			FakeClientCommand(iCid[iI],"give health");
			SetCommandFlags("give", iflags);

			//and remove their health here (since "give health" gives them 100!)
			CreateTimer(0.5,Spirit_ChangeHP,hPack);

			//here we check if there's anyone else with
			//the spirit perk who's also incapped, so we
			//know if we should continue allowing crawling

			//first, check if crawling adjustments are allowed
			//if not, then just break right away
			/*if (g_iSpirit_crawling==0
				|| g_iSpirit_enable==0)
				break;

			new iCrawlClient=-1;
			for (new iI2=1 ; iI2<=MaxClients ; iI2++)
			{
				if (g_iConfirm[iI2]==0) continue;
				if (g_iSur1[iI2]==3
					&& g_iPIncap[iI2]!=0)
				{
					iCrawlClient=iI2;
					break;
				}
			}
			if (iCrawlClient>0)
				SetConVarInt(FindConVar("survivor_allow_crawling"),1,false,false);
			else
				SetConVarInt(FindConVar("survivor_allow_crawling"),0,false,false);*/

			//finally, since spirit fired, break the loop
			//since we only want one person to self-revive at a time
			return;
		}
	}
	return;
}

//cooldown timer
public Action:Spirit_CooldownTimer (Handle:timer, any:iCid)
{
	KillTimer(timer);
	g_iSpiritTimer[iCid]=INVALID_HANDLE;
	//if the cooldown's been turned off,
	//that means a new round has started
	//and we can skip everything here
	if (IsServerProcessing()==false
		|| g_iSpiritCooldown[iCid]==0)
		return Plugin_Stop;

	g_iSpiritCooldown[iCid]=0;

	//and this sends the client a hint message
	if (IsClientInGame(iCid)==true
		&& IsPlayerAlive(iCid)==true
		&& GetClientTeam(iCid)==2
		&& IsFakeClient(iCid)==false)
		PrintHintText(iCid,"%t", "SpiritTimerFinishedMessage");

	return Plugin_Stop;
}

//timer for removing hp
//(like juggernaut, removing it too quickly
//confuses the game and doesn't remove it =/)
public Action:Spirit_ChangeHP (Handle:timer, any:hPack)
{
	//----DEBUG----
	//PrintToChatAll("\x05spirit\x03 init changehp");

	//retrieve vars from pack
	ResetPack(hPack);
	new iCid = ReadPackCell(hPack);
	new iRevCount_ret = ReadPackCell(hPack);
	CloseHandle(hPack);

	//only execute spirit functions after checks pass
	if (IsServerProcessing()==true
		&& IsClientInGame(iCid) == true
		&& GetEntData(iCid,g_iIncapO) == 0
		&& IsPlayerAlive(iCid)==true
		&& GetClientTeam(iCid)==2)
	{
		//----DEBUG----
		//PrintToChatAll("\x05spirit\x03 checks passed");

		//set revive count after self-revive
		SetEntData(iCid, g_iRevCountO, iRevCount_ret+1, 1);
		if (iRevCount_ret+1 >= 2)
		{
			//borrowed from Crimson Fox's Black and White Defib code
			SetEntProp(iCid, Prop_Send, "m_isGoingToDie", 1);
		}
		//and we give them bonus health buffer here
		SetEntDataFloat(iCid,g_iHPBuffO, GetEntDataFloat(iCid,g_iHPBuffO)+g_iSpirit_buff ,true);
		//set their health back to 1
		SetEntityHealth(iCid,1);

		//get the proper cd number for the game mode
		new iTime;
		if (g_iL4D_GameMode==2)
			iTime=g_iSpirit_cd_vs;
		else if (g_iL4D_GameMode==1)
			iTime=g_iSpirit_cd_sur;
		else
			iTime=g_iSpirit_cd;

		//spirit-specific functions
		g_iSpiritTimer[iCid]=CreateTimer(iTime*1.0,Spirit_CooldownTimer,iCid);
		g_iPIncap[iCid]=0;
		g_iSpiritCooldown[iCid]=1;

		//show a message if it's not a bot
		if (IsFakeClient(iCid)==false)
			PrintHintText(iCid,"精神医师: %t!", "SpritSuccessMessage");
	}

	//always destroy the timer, since it's possible spirit may not have executed
	KillTimer(timer);
	return Plugin_Stop;
}



//=============================
// Sur2: Helping Hand
//=============================

//fired before reviving begins,reduces revive time
HelpHand_OnReviveBegin (iCid)
{
	//check if cvar changes are allowed
	//for this perk; if not, then stop
	if (g_iHelpHand_convar==0)
		return 0;

	//check if perk is enabled
	if (g_iSur2_enable==0
		|| g_iHelpHand_enable==0		&&	g_iL4D_GameMode==0
		|| g_iHelpHand_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iHelpHand_enable_vs==0		&&	g_iL4D_GameMode==2)
		return 0;

	//----DEBUG----
	//PrintToChatAll("\x03revive begin detected, reviver: \x01%i\x03, subject: \x01%i",iCid,iSub);

	//check for helping hand
	if (g_iSur2[iCid]==3
		&& g_iConfirm[iCid]==1)
	{
		//----DEBUG----
		//PrintToChatAll("\x03-perk present, setting revive time to \x01%f",g_flReviveTime/2);

		SetConVarFloat(FindConVar("survivor_revive_duration"), g_flReviveTime * g_flHelpHand_timemult ,false,false);
		return 0;
	}

	//otherwise, reset the revive duration
	else
	{
		//----DEBUG----
		//PrintToChatAll("\x03-no perk, attempting to reset revive time to \x01%f",g_flReviveTime);

		SetConVarFloat(FindConVar("survivor_revive_duration"),g_flReviveTime,false,false);
		return 0;
	}
}

HelpHand_OnReviveSuccess (iCid, iSub, iLedge)
{
	//----DEBUG----
	//PrintToChatAll("\x05helphand\x03 reviver: \x01%i\x03, subject: \x01%i",iCid,iSub);

	//then check for helping hand
	if (g_iSur2[iCid]==3
		&& g_iConfirm[iCid]==1
		&& g_iSur2_enable==1
		&& (g_iHelpHand_enable==1		&&	g_iL4D_GameMode==0
		|| g_iHelpHand_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iHelpHand_enable_vs==1		&&	g_iL4D_GameMode==2))
	{
		switch (iLedge)
		{
		case 1:
			{
				g_iMyDisabler[iSub] = -1;

				//----DEBUG----
				//PrintToChatAll("\x03-ledge hang save detected");
			}
		case 0:
			{
				//----DEBUG----
				//PrintToChatAll("\x03-m_healthBuffer offset: \x01%i",iHPBuffO);
				//PrintToChatAll("\x03-client \x01%i\x03 value at offset: \x01%f",iSub,GetEntDataFloat(iSub,g_iHPBuffO));

				decl iBuff;
				if (g_iL4D_GameMode==2)
					iBuff=g_iHelpHand_buff_vs;
				else
					iBuff=g_iHelpHand_buff;

				SetEntDataFloat(iSub,g_iHPBuffO, GetEntDataFloat(iSub,g_iHPBuffO)+iBuff ,true);

				CreateTimer(0.5, HelpHand_Delayed, iCid);

				//----DEBUG----
				//PrintToChatAll("\x03-value at offset, post-mod: \x01%f",GetEntDataFloat(iSub,g_iHPBuffO));

				new String:st_name[24];
				GetClientName(iSub,st_name,24);
				PrintHintText(iCid,"急救医师: %t %s!", "HelpingHandDonorHint", st_name);
				GetClientName(iCid,st_name,24);
				PrintHintText(iSub,"急救医师: %s %t",st_name, "HelpingHandReceiverHint");
			}
		}
	}

	//----DEBUG----
	//PrintToChatAll("\x03-revive end, attempting to reset revive time to \x01%f",g_flReviveTime);

	//only adjust the convar if
	//convar changes are allowed
	//for this perk
	if (g_iHelpHand_convar==1
		&& g_iSur2_enable==1
		&& (g_iHelpHand_enable==1		&&	g_iL4D_GameMode==0
		|| g_iHelpHand_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iHelpHand_enable_vs==1		&&	g_iL4D_GameMode==2))
		SetConVarFloat(FindConVar("survivor_revive_duration"),g_flReviveTime,false,false);

	//and then check if we need to continue allowing crawling
	//by running checks through everyone...
	//...but first, check if spirit convar changes are allowed
	/*if (g_iSur1_enable==1
		&& g_iSpirit_crawling==1
		&& (g_iSpirit_enable==1		&&	g_iL4D_GameMode==0
		|| g_iSpirit_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iSpirit_enable_vs==1	&&	g_iL4D_GameMode==2))
	{
		new iCrawlClient=-1;
		for (new iI2=1 ; iI2<=MaxClients ; iI2++)
		{
			if (g_iConfirm[iI2]==0) continue;
			if (g_iSur2[iI2]==2
				&& g_iPIncap[iI2]!=0)
			{
				iCrawlClient=iI2;
				break;
			}
		}
		if (iCrawlClient>0)
			SetConVarInt(FindConVar("survivor_allow_crawling"),1,false,false);
		else
			SetConVarInt(FindConVar("survivor_allow_crawling"),0,false,false);
	}*/

	return 0;
}

public Action:HelpHand_Delayed (Handle:timer, any:iCid)
{
	if (IsServerProcessing()==true
		&& IsValidEntity(iCid)==true
		&& IsClientInGame(iCid)==true
		&& GetClientTeam(iCid)==2)
	{
		//----DEBUG----
		//PrintToChatAll("\x05helphand\x03 attempting to give reviver bonus to \x01%i",iCid);
		//new g_iHPBuffTimeO;
		//g_iHPBuffTimeO = FindSendPropOffs("CTerrorPlayer","m_healthBufferTime");
		//PrintToChatAll("\x03- health buffer time \x01%i %f",g_iHPBuffTimeO, GetEntDataFloat(iCid,g_iHPBuffTimeO));

		decl iBuff;
		if (g_iL4D_GameMode==2)
			iBuff=g_iHelpHand_buff_vs;
		else
			iBuff=g_iHelpHand_buff;

		//SetEntProp(iCid,Prop_Data,"m_iHealth", GetEntProp(iCid,Prop_Data,"m_iHealth")+ iBuff/3 );

		SetEntDataFloat(iCid, g_iHPBuffTimeO, GetGameTime(), true);
		new Float:flBuff_ret = GetEntDataFloat(iCid,g_iHPBuffO);
		if (flBuff_ret <= 0)
			flBuff_ret = 0.0;
		SetEntDataFloat(iCid, g_iHPBuffO, flBuff_ret + iBuff/2 , true);
	}

	KillTimer(timer);
	return Plugin_Stop;
}



//=============================
// Sur3: Pack Rat
//=============================

//on gun pickup
PR_Pickup(iCid, String:stWpn[])
{
	if (g_iSur3[iCid]==1
		&& g_iSur2_enable==1
		&& (g_iPack_enable==1		&&	g_iL4D_GameMode==0
		|| g_iPack_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iPack_enable_vs==1		&&	g_iL4D_GameMode==2))
	{
		if (StrContains(stWpn, "smg", false)!= -1
			|| StrContains(stWpn, "rifle", false)!= -1
			|| StrContains(stWpn, "shotgun", false)!= -1
			|| StrContains(stWpn, "sniper", false)!= -1	)
		{
			PR_GiveFullAmmo(iCid);
		}
	}
}

//on ammo pickup, check if pack rat is in effect
public Event_AmmoPickup (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid==0)
		return;

	if (g_iSur3[iCid]==1
		&& g_iConfirm[iCid]==1
		&& g_iSur3_enable==1
		&& (g_iPack_enable==1			&&	g_iL4D_GameMode==0
			|| g_iPack_enable_sur==1	&&	g_iL4D_GameMode==1
			|| g_iPack_enable_vs==1		&&	g_iL4D_GameMode==2))
	{
		PR_GiveFullAmmo(iCid);
	}
}

//gives full ammo
PR_GiveFullAmmo (iCid)
{
	//formula: max + pack rat + max clip size - currently in clip
	//new iAmmoO=FindDataMapOffs(iCid,"m_iAmmo");

	if (g_iL4D_12 == 2)
	{
		if (g_bPRalreadyApplying[iCid] == false)
		{
			g_bPRalreadyApplying[iCid] = true;
			CreateTimer(0.1, PR_GiveFullAmmo_delayed, iCid);
		}
		else
			return;
	}
	else if (g_iL4D_12 == 1)
	{
		new iAmmoO=FindDataMapOffs(iCid,"m_iAmmo");
		decl iAmmoCount;

		//huntingrifle offset +8
		iAmmoCount = GetEntData(iCid, iAmmoO +8);
		SetEntData(iCid, iAmmoO	+8, RoundToNearest(iAmmoCount * (1 + g_flPack_ammomult)) );
		//rifle - offset +12
		iAmmoCount = GetEntData(iCid, iAmmoO +12);
		SetEntData(iCid, iAmmoO	+12, RoundToNearest(iAmmoCount * (1 + g_flPack_ammomult)) );
		//smg - offset +20
		iAmmoCount = GetEntData(iCid, iAmmoO +20);
		SetEntData(iCid, iAmmoO	+20, RoundToNearest(iAmmoCount * (1 + g_flPack_ammomult)) );
		//shotgun - offset +24
		iAmmoCount = GetEntData(iCid, iAmmoO +24);
		SetEntData(iCid, iAmmoO	+24, RoundToNearest(iAmmoCount * (1 + g_flPack_ammomult)) );
	}
}

//new technique - instead of running off a convar, adjusts ammo
//relative to what player already has in inventory after a delay
public Action:PR_GiveFullAmmo_delayed (Handle:timer, any:iCid)
{
	KillTimer(timer);

	if (g_bPRalreadyApplying[iCid] == true)
		g_bPRalreadyApplying[iCid] = false;
	else
		return Plugin_Stop;
	
	if (IsServerProcessing()==false
		|| IsValidEntity(iCid) == false
		|| IsClientInGame(iCid) == false
		|| IsPlayerAlive(iCid)==false
		|| GetClientTeam(iCid)!=2)
		return Plugin_Stop;

	new iAmmoO=FindDataMapOffs(iCid,"m_iAmmo");
	decl iAmmoO_offset;
	decl iAmmoCount;

	//checks each weapon type ammo in player's inventory
	//if non-zero, then assume player has that weapon
	//and adjust only that weapon's ammo

	//----DEBUG----
	//new iI = 0;
	//PrintToChatAll("\x05PR\x03 being feedback loop");
	//while (iI <= 64)
	//{
		//iAmmoCount = GetEntData(iCid, iAmmoO + iI);
		//PrintToChatAll("\x05PR\x03 iI = \x01%i\x03, value = \x01%i",iI, iAmmoCount);
		//iI++;
	//}

	//rifle - offset +12
	iAmmoO_offset = 12;
	iAmmoCount = GetEntData(iCid, iAmmoO + iAmmoO_offset);
	if (iAmmoCount > 0)
	{
		SetEntData(iCid, iAmmoO	+ iAmmoO_offset, RoundToNearest(iAmmoCount * (1 + g_flPack_ammomult)) );
		//return Plugin_Stop;
	}
	//smg - offset +20
	iAmmoO_offset = 20;
	iAmmoCount = GetEntData(iCid, iAmmoO + iAmmoO_offset);
	if (iAmmoCount > 0)
	{
		SetEntData(iCid, iAmmoO	+ iAmmoO_offset, RoundToNearest(iAmmoCount * (1 + g_flPack_ammomult)) );
		//return Plugin_Stop;
	}
	//auto-shotgun - now offset +32
	iAmmoO_offset = 32;
	iAmmoCount = GetEntData(iCid, iAmmoO + iAmmoO_offset);
	if (iAmmoCount > 0)
	{
		SetEntData(iCid, iAmmoO	+ iAmmoO_offset, RoundToNearest(iAmmoCount * (1 + g_flPack_ammomult)) );
		//return Plugin_Stop;
	}
	//pump shotgun - now offset +28
	iAmmoO_offset = 28;
	iAmmoCount = GetEntData(iCid, iAmmoO + iAmmoO_offset);
	if (iAmmoCount > 0)
	{
		SetEntData(iCid, iAmmoO	+ iAmmoO_offset, RoundToNearest(iAmmoCount * (1 + g_flPack_ammomult)) );
		//return Plugin_Stop;
	}
	//huntingrifle offset +32 - now +36
	iAmmoO_offset = 36;
	iAmmoCount = GetEntData(iCid, iAmmoO + iAmmoO_offset);
	if (iAmmoCount > 0)
	{
		SetEntData(iCid, iAmmoO	+ iAmmoO_offset, RoundToNearest(iAmmoCount * (1 + g_flPack_ammomult)) );
		//return Plugin_Stop;
	}
	//militarysniper offset +36 - now +40
	iAmmoO_offset = 40;
	iAmmoCount = GetEntData(iCid, iAmmoO + iAmmoO_offset);
	if (iAmmoCount > 0)
	{
		SetEntData(iCid, iAmmoO	+ iAmmoO_offset, RoundToNearest(iAmmoCount * (1 + g_flPack_ammomult)) );
		//return Plugin_Stop;
	}
	//grenade launcher offset +64
	iAmmoO_offset = 64;
	iAmmoCount = GetEntData(iCid, iAmmoO + iAmmoO_offset);
	if (iAmmoCount > 0)
	{
		SetEntData(iCid, iAmmoO	+ iAmmoO_offset, RoundToNearest(iAmmoCount * (1 + g_flPack_ammomult)) );
		//return Plugin_Stop;
	}

	return Plugin_Stop;
}



//=============================
// Sur3: Chem Reliant
//=============================

//on drug used
Chem_OnDrugUsed (iCid)
{
	//check if perk is enabled
	if (g_iSur3_enable==0
		|| g_iChem_enable==0			&&	g_iL4D_GameMode==0
		|| g_iChem_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iChem_enable_vs==0		&&	g_iL4D_GameMode==2)
		return 0;

	//----DEBUG----
	//PrintToChatAll("\x03Pill user: \x01%i", iCid);

	if (g_iSur3[iCid]==2
		&& g_iConfirm[iCid]==1)
	{
		new Float:flBuff=GetEntDataFloat(iCid,g_iHPBuffO);
		new iHP=GetEntProp(iCid,Prop_Data,"m_iHealth");
		
		//so we need to test the maxbound for
		//how much health buffer we can give
		//which can vary depending on whether
		//they have unbreakable or not

		//CASE 1: HAS UNBREAKABLE
		if (g_iSur2[iCid]==1
			&& g_iSur3_enable==1
			&& (g_iUnbreak_enable==1	&&	g_iL4D_GameMode==0
			|| g_iUnbreak_enable_sur==1	&&	g_iL4D_GameMode==1
			|| g_iUnbreak_enable_vs==1	&&	g_iL4D_GameMode==2))
		{
			//CASE 1A:
			//combined health + chem reliant < max health possible
			if (flBuff + iHP + g_iChem_buff < 100 + g_iUnbreak_hp)
				//this is the easiest, just give them chem reliant bonus
				SetEntDataFloat(iCid,g_iHPBuffO, flBuff+g_iChem_buff ,true);

			//CASE 1B:
			//combined health + chem reliant > max health possible
			else
				//this is a bit trickier, give them the difference
				//between the max health possible and their current health
				SetEntDataFloat(iCid,g_iHPBuffO, (100.0+g_iUnbreak_hp)-iHP ,true);
		}
		//CASE 2: DOES NOT HAVE UNBREAKABLE
		else
		{
			//CASE 1A:
			//combined health + chem reliant < max health possible
			if (flBuff + iHP + g_iChem_buff < 100)
				//this is the easiest, just give them chem reliant bonus
				SetEntDataFloat(iCid,g_iHPBuffO, flBuff+g_iChem_buff ,true);

			//CASE 1B:
			//combined health + chem reliant > max health possible
			else
				//this is a bit trickier, give them the difference
				//between the max health possible and their current health
				SetEntDataFloat(iCid,g_iHPBuffO, 100.0-iHP ,true);
		}
	}
	return 0;
}

//called on roundstart or on confirming perks,
//gives pills off the start
Event_Confirm_ChemReliant (iCid)
{
	if (iCid==0
		|| GetClientTeam(iCid)!=2
		|| IsPlayerAlive(iCid)==false
		|| g_iConfirm[iCid]==0
		|| g_iSur3[iCid]!=2)
		return;

	//check if perk is enabled
	if (g_iSur3_enable==0
		|| g_iChem_enable==0		&&	g_iL4D_GameMode==0
		|| g_iChem_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iChem_enable_vs==0		&&	g_iL4D_GameMode==2)
		return;

	new iflags=GetCommandFlags("give");
	SetCommandFlags("give", iflags & ~FCVAR_CHEAT);
	if (g_iL4D_12 == 1
		|| GetRandomInt(0,1)==1)
		FakeClientCommand(iCid,"give pain_pills");
	else
		FakeClientCommand(iCid,"give adrenaline");
	SetCommandFlags("give", iflags);

	return;
}



//=============================
// Sur3: Hard to Kill
//=============================

HardToKill_OnIncap (iCid)
{
	if (GetClientTeam(iCid)!=2
		|| g_iConfirm[iCid]==0
		|| GetClientTeam(iCid)!=2)
		return;

	if (g_iSur3_enable==0
		|| g_iHard_enable==0		&&	g_iL4D_GameMode==0
		|| g_iHard_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iHard_enable_vs==0		&&	g_iL4D_GameMode==2)
		return;

	if (g_iSur3[iCid]==3)
	{
		//new iHP=GetEntProp(iCid,Prop_Data,"m_iHealth");

		//----DEBUG----
		//PrintToChatAll("\x03hard to kill fire, client \x01%i\x03, health \x01%i",iCid,iHP);

		//SetEntProp(iCid,Prop_Data,"m_iHealth", iHP + RoundToNearest(iHP*g_flHard_hpmult) );
		//SetEntDataFloat(iCid,g_iHPBuffO, flHPBuff+300 ,true);
		CreateTimer(0.5,HardToKill_Delayed,iCid);

		//----DEBUG----
		//PrintToChatAll("\x03-postfire values, health \x01%i",GetEntProp(iCid,Prop_Data,"m_iHealth"));
	}
}

public Action:HardToKill_Delayed (Handle:timer, any:iCid)
{
	if (IsServerProcessing()==true
		&& IsValidEntity(iCid)==true
		&& IsClientInGame(iCid)==true
		&& GetClientTeam(iCid)==2)
	{
		new iHP=GetEntProp(iCid,Prop_Data,"m_iHealth");

		SetEntProp(iCid,Prop_Data,"m_iHealth", iHP + RoundToNearest(iHP*g_flHard_hpmult) );

		iHP = RoundToNearest( 300*(g_flHard_hpmult+1) );
		if (GetEntProp(iCid,Prop_Data,"m_iHealth") > iHP)
			SetEntProp(iCid,Prop_Data,"m_iHealth", iHP);
	}

	KillTimer(timer);
	return Plugin_Stop;
}



//=============================
// Sur3: Little Leaguer
//=============================

Event_Confirm_LittleLeaguer (iCid)
{
	if (iCid==0
		|| GetClientTeam(iCid)!=2
		|| IsPlayerAlive(iCid)==false
		|| g_iConfirm[iCid]==0
		|| g_iSur3[iCid]!=5)
		return;

	//check if perk is enabled
	if (g_iSur3_enable==0
		|| g_iChem_enable==0		&&	g_iL4D_GameMode==0
		|| g_iChem_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iChem_enable_vs==0		&&	g_iL4D_GameMode==2)
		return;

	new iflags=GetCommandFlags("give");
	SetCommandFlags("give", iflags & ~FCVAR_CHEAT);
	FakeClientCommand(iCid,"give rifle_m60");
	SetCommandFlags("give", iflags);

	return;
}



//=============================
// Sur3: Extreme Conditioning
//=============================

Extreme_Rebuild ()
{
	//if the server's not running or
	//is in the middle of loading, stop
	if (IsServerProcessing()==false)
		return;

	//check if perk is enabled
	if (g_iSur3_enable==0
		|| g_iExtreme_enable==0		&&	g_iL4D_GameMode==0
		|| g_iExtreme_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iExtreme_enable_vs==0	&&	g_iL4D_GameMode==2)
		return;

	//----DEBUG----
	//PrintToChatAll("\x03extreme cond rebuilding");

	for (new iI=1 ; iI<=MaxClients ; iI++)
	{
		if (IsClientInGame(iI)==true
			&& IsPlayerAlive(iI)==true
			&& g_iSur3[iI]==4
			&& g_iConfirm[iI]==1
			&& GetClientTeam(iI)==2)
		{
			if (g_iSur3[iI]==4
				&& g_iConfirm[iI]==1)
				SetEntDataFloat(iI,g_iLaggedMovementO, 1.0*g_flExtreme_rate ,true);
			else
				SetEntDataFloat(iI,g_iLaggedMovementO, 1.0 ,true);

			//----DEBUG----
			//PrintToChatAll("\x03-registering \x01%i",iI);
		}
	}
}




//=============================
// Inf1: Blind Luck
//=============================

BlindLuck_OnIt (iAtt, iVic)
{
	//don't blind bots as per grandwaziri's plugin, they suck enough anyways
	if (g_iInf1[iAtt]==2
		&& g_iConfirm[iAtt]==1
		&& IsFakeClient(iVic)==false)
	{
		//check if perk is enabled
		if (g_iInf1_enable==0
			|| g_iBlind_enable==0)
			return;

		SetEntProp(iVic, Prop_Send, "m_iHideHUD", 64);

		//----DEBUG----
		//PrintToChatAll("\x03-attempting to hide hud");
	}
	return;
}

BlindLuck_OnSpawn (iCid)
{
	//stop if convar changes are disallowed for this perk
	if (g_iBlind_enable==0
		|| g_iInf1_enable==0)
		return 0;

	if (g_iInf1[iCid]==2)
	{
		//----DEBUG----
		//PrintToChatAll("\x05drag\x03 creating timer");

		CreateTimer(1.0,Timer_BlindLuckChecks,iCid,TIMER_REPEAT);
	}
	
	return 0;
}

public Action:Timer_BlindLuckChecks (Handle:timer, any:iCid)
{
	//INITIAL CHECKS
	//--------------
	if (IsServerProcessing()==false
		|| iCid <= 0
		|| IsClientInGame(iCid)==false
		|| IsPlayerAlive(iCid)==false
		|| GetEntData(iCid, g_iClassO)!=2)
	{
		//----DEBUG----
		//if (IsServerProcessing()==false)			PrintToChatAll("\x03- server not processing, stopping");
		//else if (iCid <= 0)							PrintToChatAll("\x03- icid <= 0, stopping, client id \x01%i", iCid);
		//else if (IsClientInGame(iCid)==false)		PrintToChatAll("\x03- client not in game, stopping");
		//else if (IsPlayerAlive(iCid)==false)		PrintToChatAll("\x03- client not alive, stopping");
		//else if (GetEntData(iCid, g_iClassO)!=1)	PrintToChatAll("\x03- class not correct, stopping, class id \x01%i", GetEntData(iCid, g_iClassO));

		KillTimer(timer);
		return Plugin_Stop;
	}

	//----DEBUG----
	//PrintToChatAll("\x03- \x05blind luck \x03 tick");

	//RETRIEVE VARIABLES
	//------------------
	//get the ability ent id
	new iEntid = GetEntDataEnt2(iCid,g_iAbilityO);
	//if the retrieved gun id is -1, then move on
	if (iEntid == -1)
	{
		//----DEBUG----
		//PrintToChatAll("\x03- ientid == -1, stopping");

		KillTimer(timer);
		return Plugin_Stop;
	}
	//retrieve the next act time
	//new Float:flDuration_ret = GetEntDataFloat(iEntid,g_iNextActO+4);

	//----DEBUG----
	//if (g_iShow==1)
	//	PrintToChatAll("\x03- actsuppress dur \x01 %f\x03 timestamp \x01%f", GetEntDataFloat(iEntid, g_iSuppressO+4), GetEntDataFloat(iEntid, g_iSuppressO+8) );




	//CHECK 1: AFTER ADJUSTED SHOT IS MADE
	//------------------------------------
	//at this point, either a gun was swapped, or
	//the attack time needs to be adjusted
	//also, only change timer if it's the first shot

	//retrieve current timestamp
	new Float:flTimeStamp_ret = GetEntDataFloat(iEntid,g_iNextActO+8);

	if (g_flTimeStamp[iCid] < flTimeStamp_ret)
	{
		//----DEBUG----
		//PrintToChatAll("\x05BlindLuck:\x03 after adjusted shot\n-pre, client \x01%i\x03; entid \x01%i\x03; enginetime\x01 %f\x03; nextactivation: dur \x01 %f\x03 timestamp \x01%f",iCid,iEntid,GetGameTime(),GetEntDataFloat(iEntid, g_iNextActO+4), GetEntDataFloat(iEntid, g_iNextActO+8) );

		//update the timestamp stored in plugin
		g_flTimeStamp[iCid] = flTimeStamp_ret;

		//this calculates the time that the player theoretically
		//should have used his ability in order to use it
		//with the shortened cooldown
		//FOR EXAMPLE:
		//vomit, normal cooldown 30s, desired cooldown 6s
		//player uses it at T = 1:30
		//normally, game predicts it to be ready at T + 30s
		//so if we modify T to 1:06, it will be ready at 1:36
		//which is 6s after the player used the ability
		new Float:flTimeStamp_calc = flTimeStamp_ret - (GetConVarFloat(FindConVar("z_vomit_interval")) * (1 - g_flBlind_cdmult) );
		SetEntDataFloat(iEntid, g_iNextActO+8, flTimeStamp_calc, true);

		//----DEBUG----
		//PrintToChatAll("\x03-post, nextactivation dur \x01 %f\x03 timestamp \x01%f", GetEntDataFloat(iEntid, g_iNextActO+4), GetEntDataFloat(iEntid, g_iNextActO+8) );
	}

	return Plugin_Continue;
}



//=============================
// Inf1: Barf Bagged
//=============================

BarfBagged_OnIt (iAtt)
{
	//only spawn a mob if one guy got slimed
	//or if all four got slimed (max 2 extra mobs)
	if (g_iInf1[iAtt]==1
		&& g_iConfirm[iAtt]==1
		&& (g_iSlimed==1 || g_iSlimed==4))
	{
		//check if perk is enabled
		if (g_iInf1_enable==0
			|| g_iBarf_enable==0)
			return 0;

		//----DEBUG----
		//PrintToChatAll("\x03-attempting to spawn a mob, g_iSlimed=\x01%i",g_iSlimed);

		new iflags=GetCommandFlags("z_spawn");
		SetCommandFlags("z_spawn", iflags & ~FCVAR_CHEAT);
		FakeClientCommand(iAtt,"z_spawn mob auto");
		SetCommandFlags("z_spawn", iflags);

		if (g_iSlimed==4) PrintHintText(iAtt,"超级呕吐! %t", "BarfBaggedMobHint");
	}
	return 0;
}



//=============================
// Inf1: Dead Wreckening
//=============================

//damage add
DeadWreckening_DamageAdd (iAtt, iVic, iType, iDmgOrig)
{
	if (iAtt==0
		&& iType==128
		&& g_iSlimed>0
		&& g_iConfirm[g_iSlimerLast]==1
		&& g_iInf1[g_iSlimerLast]==3)
	{
		//check if perk is enabled
		if (g_iInf1_enable==0
			|| g_iDead_enable==0)
			return 1;

		//----DEBUG----
		//PrintToChatAll("\x03dead wreckening fire");

		new iDmgAdd = DamageAddRound (iDmgOrig, g_flDead_dmgmult);

		if (iDmgAdd==0)
			return 0;

		InfToSurDamageAdd(iVic, iDmgAdd ,iDmgOrig);
		
		return 1;
	}
	return 0;
}



//=============================
// Inf1: Motion Sickness
//=============================

Motion_OnSpawn (iCid)
{
	//stop here if the perk is disabled
	if (g_iMotion_enable==0
		|| g_iInf1_enable==0)
		return 0;

	//check for motion sickness
	if (g_iInf1[iCid]==4
		&& g_iConfirm[iCid]==1)
	{
		SetConVarFloat(FindConVar("z_vomit_fatigue"),0.0,false,false);
		SetEntDataFloat(iCid,g_iLaggedMovementO, 1.0*g_flMotion_rate ,true);
	}
	else
		SetConVarFloat(FindConVar("z_vomit_fatigue"), g_flVomitFatigue ,false,false);

	return 0;
}



//=============================
// Inf3: Tongue Twister
//=============================

TongueTwister_OnAbilityUse (iCid, String:stAb[])
{
	//check for smoker-type perks
	if (StrEqual(stAb,"ability_tongue",false)==true)
	{
		//stop if twister is disabled
		if (g_iTongue_enable==0)
			return 0;

		//check for twister
		if (g_iInf3[iCid]==1)
			SetConVarFloat(FindConVar("tongue_fly_speed"), g_flTongueFlySpeed*g_flTongue_speedmult ,false,false);
		else
			SetConVarFloat(FindConVar("tongue_fly_speed"),g_flTongueFlySpeed,false,false);
	}
	return 0;
}

TongueTwister_OnTongueGrab (iCid)
{
	//stop if twister is disabled
	if (g_iInf3_enable==0
		|| g_iTongue_enable==0)
		return 0;

	//----DEBUG----
	//PrintToChatAll("\x03yoink grab fired, client: \x01%i",iCid);

	if (g_iConfirm[iCid]==1
		&& g_iInf3[iCid]==1)
		SetConVarFloat(FindConVar("tongue_victim_max_speed"), g_flTongueSpeed*g_flTongue_pullmult ,false,false);
	else
		SetConVarFloat(FindConVar("tongue_victim_max_speed"),g_flTongueSpeed,false,false);

	return 0;
}

TongueTwister_OnTongueRelease ()
{
	//only reset these convars if twister is enabled
	if (g_iInf3_enable==1
		&& g_iTongue_enable==1)
	{
		//SetConVarFloat(FindConVar("tongue_victim_max_speed"),g_flTongueSpeed,false,false);
		//SetConVarFloat(FindConVar("tongue_fly_speed"),g_flTongueFlySpeed,false,false);
		CreateTimer(3.0,Timer_TongueRelease,0);
	}

	return 0;
}

public Action:Timer_TongueRelease (Handle:timer, any:data)
{
	KillTimer(timer);
	if (IsServerProcessing()==false)
		return Plugin_Stop;

	SetConVarFloat(FindConVar("tongue_victim_max_speed"),g_flTongueSpeed,false,false);
	SetConVarFloat(FindConVar("tongue_fly_speed"),g_flTongueFlySpeed,false,false);

	return Plugin_Stop;
}

TongueTwister_OnSpawn (iCid)
{
	//stop here if twister is disabled
	if (g_iInf3_enable==0
		|| g_iTongue_enable==0)
		return;

	//check for tongue twister
	if (g_iInf3[iCid]==1
		&& g_iConfirm[iCid]==1)
	{

		SetConVarFloat(FindConVar("tongue_range"), g_flTongueRange*g_flTongue_rangemult ,false,false);
		//----DEBUG----
		//PrintToChatAll("\x03-tongue range modified");
	}

	//otherwise, just reset convar
	else
	{
		SetConVarFloat(FindConVar("tongue_range"),g_flTongueRange,false,false);

		//----DEBUG----
		//PrintToChatAll("\x03-tongue range reset");
	}
}



//=============================
// Inf3: Squeezer
//=============================

//damage add function
Squeezer_DamageAdd (iAtt, iVic, iTA, String:stWpn[], iDmgOrig)
{
	if (iTA==3
		&& g_iConfirm[iAtt]==1
		&& StrEqual(stWpn,"smoker_claw")==true
		&& g_iInf3[iAtt]==2
		&& g_iMyDisableTarget[iAtt] == iVic)
	{
		//stop if perk is disabled
		if (g_iInf3_enable==0
			|| g_iSqueezer_enable==0)
			return 1;

		new iDmgAdd = DamageAddRound (iDmgOrig, g_flSqueezer_dmgmult);

		if (iDmgAdd==0)
			return 0;

		InfToSurDamageAdd(iVic, iDmgAdd ,iDmgOrig);

		return 1;
	}
	return 0;
}

//=============================
// Inf3: Drag and Drop
//=============================

//alters cooldown to be faster
Drag_OnTongueGrab (iCid)
{
	//----DEBUG----
	//PrintToChatAll("\x03drag and drop running checks");

	//stop if drag and drop is disabled
	if (g_iInf3_enable==0
		|| g_iDrag_enable==0)
		return;

	//if attacker id is null, reset vars
	if (iCid<=0) 
	{
		SetConVarInt(FindConVar("tongue_allow_voluntary_release"),0,false,false);
		SetConVarFloat(FindConVar("tongue_player_dropping_to_ground_time"),g_flTongueDropTime,false,false);
		return ;
	}

	//check for drag and drop
	if (g_iInf3[iCid]==3
		&& g_iConfirm[iCid]==1)
	{
		//----DEBUG----
		//PrintToChatAll("\x03and again! reducing cooldown to \x01%f",g_flTongueHitDelay/2);

		SetConVarInt(FindConVar("tongue_allow_voluntary_release"),1,false,false);
		SetConVarFloat(FindConVar("tongue_player_dropping_to_ground_time"),0.2,false,false);

		//CreateTimer(0.5,Timer_DragChecks,iCid,TIMER_REPEAT);

		return ;
	}

	//all else fails, reset vars
	else
	{
		//----DEBUG----
		//PrintToChatAll("\x03and again! resetting cooldown to \x01%f",g_flTongueHitDelay);

		SetConVarInt(FindConVar("tongue_allow_voluntary_release"),0,false,false);
		SetConVarFloat(FindConVar("tongue_player_dropping_to_ground_time"),g_flTongueDropTime,false,false);
		return ;
	}
}

Drag_OnSpawn(iCid)
{
	//stop if grasshopper is disabled
	if (g_iInf3_enable==0
		|| g_iDrag_enable==0)
		return 0;

	if (GetClientTeam(iCid)==3
		&& g_iInf3[iCid]==3
		&& g_iConfirm[iCid]==1)
	{
		//----DEBUG----
		//PrintToChatAll("\x05drag\x03 creating timer");

		CreateTimer(1.0,Timer_DragChecks,iCid,TIMER_REPEAT);
		return 1;
	}

	return 0;
}

public Action:Timer_DragChecks (Handle:timer, any:iCid)
{
	//INITIAL CHECKS
	//--------------
	if (IsServerProcessing()==false
		|| iCid <= 0
		|| IsClientInGame(iCid)==false
		|| IsPlayerAlive(iCid)==false
		|| GetEntData(iCid, g_iClassO)!=1)
	{
		//----DEBUG----
		//if (IsServerProcessing()==false)			PrintToChatAll("\x03- server not processing, stopping");
		//else if (iCid <= 0)							PrintToChatAll("\x03- icid <= 0, stopping, client id \x01%i", iCid);
		//else if (IsClientInGame(iCid)==false)		PrintToChatAll("\x03- client not in game, stopping");
		//else if (IsPlayerAlive(iCid)==false)		PrintToChatAll("\x03- client not alive, stopping");
		//else if (GetEntData(iCid, g_iClassO)!=1)	PrintToChatAll("\x03- class not correct, stopping, class id \x01%i", GetEntData(iCid, g_iClassO));

		KillTimer(timer);
		return Plugin_Stop;
	}

	//----DEBUG----
	//PrintToChatAll("\x03- \x05drag\x03 tick");

	//RETRIEVE VARIABLES
	//------------------
	//get the ability ent id
	new iEntid = GetEntDataEnt2(iCid,g_iAbilityO);
	//if the retrieved gun id is -1, then move on
	if (iEntid == -1)
	{
		//----DEBUG----
		//PrintToChatAll("\x03- ientid == -1, stopping");

		KillTimer(timer);
		return Plugin_Stop;
	}
	//retrieve the next act time
	new Float:flDuration_ret = GetEntDataFloat(iEntid,g_iNextActO+4);

	//----DEBUG----
	//if (g_iShow==1)
	//	PrintToChatAll("\x03- actsuppress dur \x01 %f\x03 timestamp \x01%f", GetEntDataFloat(iEntid, g_iSuppressO+4), GetEntDataFloat(iEntid, g_iSuppressO+8) );




	//CHECK 1: PAUSE?
	//---------------
	//Valve seems to have a weird way of forcing a
	//pause before the cooldown timer starts: by setting
	//the timers to some arbitrarily high number =/
	//IIRC no cooldown exceeds 100s (highest is 30?) so
	//if any values exceed 100, then let timer continue running
	if (flDuration_ret > 100.0)
	{
		//----DEBUG----
		//PrintToChatAll("\x03DT retrieved duration > 100");

		return Plugin_Continue;
	}



	//CHECK 2: AFTER ADJUSTED SHOT IS MADE
	//------------------------------------
	//at this point, either a gun was swapped, or
	//the attack time needs to be adjusted
	//also, only change timer if it's the first shot

	//retrieve current timestamp
	new Float:flTimeStamp_ret = GetEntDataFloat(iEntid,g_iNextActO+8);

	if (g_flTimeStamp[iCid] < flTimeStamp_ret)
	{
		//----DEBUG----
		//PrintToChatAll("\x05Drag:\x03 after adjusted shot\n-pre, client \x01%i\x03; entid \x01%i\x03; enginetime\x01 %f\x03; nextactivation: dur \x01 %f\x03 timestamp \x01%f",iCid,iEntid,GetGameTime(),GetEntDataFloat(iEntid, g_iNextActO+4), GetEntDataFloat(iEntid, g_iNextActO+8) );

		//update the timestamp stored in plugin
		g_flTimeStamp[iCid] = flTimeStamp_ret;

		//this calculates the time that the player theoretically
		//should have used his ability in order to use it
		//with the shortened cooldown
		//FOR EXAMPLE:
		//vomit, normal cooldown 30s, desired cooldown 6s
		//player uses it at T = 1:30
		//normally, game predicts it to be ready at T + 30s
		//so if we modify T to 1:06, it will be ready at 1:36
		//which is 6s after the player used the ability
		new Float:flTimeStamp_calc = flTimeStamp_ret - (GetConVarFloat(FindConVar("tongue_hit_delay")) * (1 - g_flDrag_cdmult) );
		SetEntDataFloat(iEntid, g_iNextActO+8, flTimeStamp_calc, true);

		//----DEBUG----
		//PrintToChatAll("\x03-post, nextactivation dur \x01 %f\x03 timestamp \x01%f", GetEntDataFloat(iEntid, g_iNextActO+4), GetEntDataFloat(iEntid, g_iNextActO+8) );
	}

	return Plugin_Continue;
}



//=============================
// Inf3: Smoke IT!
//=============================

public Action:SmokeIt_OnTongueGrab(Smoker, Victim)
{
	if (g_iInf3_enable==0
		|| g_iSmokeIt_enable==0
		|| g_iInf3[Smoker]!=4
		|| g_iConfirm[Smoker]!=1)
		return Plugin_Continue;

	//new Smoker = GetClientOfUserId(GetEventInt(event, "userid"));
	if (IsFakeClient(Smoker)) return Plugin_Continue;
	new Handle:pack;
	g_bSmokeItGrabbed[Smoker] = true;
	//new Victim = GetClientOfUserId(GetEventInt(event, "victim"));
	SetEntityMoveType(Smoker, MOVETYPE_ISOMETRIC);
	SetEntDataFloat(Smoker, g_iLaggedMovementO, g_flSmokeItSpeed, true);
	g_hSmokeItTimer[Smoker] = CreateDataTimer(0.2, SmokeItTimerFunction, pack, TIMER_FLAG_NO_MAPCHANGE|TIMER_REPEAT);
	WritePackCell(pack, Smoker);
	WritePackCell(pack, Victim);
	//new Float:speed = GetEntDataFloat(Smoker, speedOffset);
	//PrintToChatAll("Speed: %f", speed);
	return Plugin_Continue;
}

public Action:SmokeItTimerFunction(Handle:timer, Handle:pack)
{
	ResetPack(pack);
	new Smoker = ReadPackCell(pack);
	if ((!IsValidClient(Smoker))||(GetClientTeam(Smoker)!=3)||(IsFakeClient(Smoker))||(g_bSmokeItGrabbed[Smoker] = false))
	{
		g_hSmokeItTimer[Smoker] = INVALID_HANDLE;
		return Plugin_Stop;
	}
			
	new Victim = ReadPackCell(pack);
	if ((!IsValidClient(Victim))||(GetClientTeam(Victim)!=2)||(g_bSmokeItGrabbed[Smoker] = false))
	{
		g_hSmokeItTimer[Smoker] = INVALID_HANDLE;
		return Plugin_Stop;
	}
			
	new Float:SmokerPosition[3];
	new Float:VictimPosition[3];
	GetClientAbsOrigin(Smoker,SmokerPosition);
	GetClientAbsOrigin(Victim,VictimPosition);
	new distance = RoundToNearest(GetVectorDistance(SmokerPosition, VictimPosition));
	//PrintToChatAll("Distance: %i", distance);
	if (distance>g_iSmokeItMaxRange)
	{
		SlapPlayer(Smoker, 0, false);
		//PrintToChatAll("\x03BREAK");
	}
	return Plugin_Continue;
}

public Action:SmokeIt_OnTongueRelease(Smoker)
{
	//new Smoker = GetClientOfUserId(GetEventInt(event, "userid"));
	g_bSmokeItGrabbed[Smoker] = false;
	SetEntityMoveType(Smoker, MOVETYPE_CUSTOM);
	SetEntDataFloat(Smoker, g_iLaggedMovementO, 1.0, true);
	if (g_hSmokeItTimer[Smoker] != INVALID_HANDLE)
	{
		KillTimer(g_hSmokeItTimer[Smoker], true);
		g_hSmokeItTimer[Smoker] = INVALID_HANDLE;
	}
	//new Float:speed = GetEntDataFloat(Smoker, speedOffset);
	//PrintToChatAll("Release Event Fired, Speed: %f", speed);
}

public IsValidClient(client)
{
	if (client == 0)
		return false;
	
	if (!IsClientConnected(client))
		return false;
	
	//if (IsFakeClient(client))
		//return false;
	
	if (!IsClientInGame(client))
		return false;
	
	if (!IsPlayerAlive(client))
		return false;
	return true;
}





//=============================
// Inf4: Body Slam
//=============================

//damage function
BodySlam_DamageAdd (iAtt, iVic, iTA, iType, String:stWpn[], iDmgOrig)
{
	//----DEBUG----
	//PrintToChatAll("\x03-hunter claw damage detected, type: \x01%i",GetEventInt(event,"type"));

	if (iTA==3
		&& g_iConfirm[iAtt]==1
		&& StrEqual(stWpn,"hunter_claw")==true
		&& iType==1
		&& g_iInf4[iAtt]==1)
	{
		//stop if body slam is disabled
		if (g_iInf4_enable==0
			|| g_iBody_enable==0)
			return 1;

		//----DEBUG----
		//PrintToChatAll("\x03body slam check");

		new iMinBound = g_iBody_minbound;

		//body slam only fires if pounce damage
		//was less than 8 (sets minimum pounce damage)
		//or whatever the minimum bound is (was originally 8...)
		if (iDmgOrig<iMinBound)
		{
			//----DEBUG----
			//PrintToChatAll("\x03body slam fire, running checks");

			new iHP=GetEntProp(iVic,Prop_Data,"m_iHealth");

			//if health>8, then run normally
			if (iHP>iMinBound)
			{
				//----DEBUG----
				//PrintToChatAll("\x03iHP>8 condition");

				SetEntProp(iVic,Prop_Data,"m_iHealth", iHP-(iMinBound-iDmgOrig) );
				PrintHintText(iAtt,"Body Slam: %i %t!", iMinBound-iDmgOrig, "BonusDamageText");

				//----DEBUG----
				//PrintToChatAll("\x03-%i bonus damage", (iMinBound-iDmgOrig) );

				return 1;
			}
			//otherwise, we gotta do a bit of work
			//if survivor's health is
			//less than or equal to 8
			else
			{
				//----DEBUG----
				//PrintToChatAll("\x03iHP<8 condition");
				//PrintToChatAll("\x03-iDmgOrig<8 and iHP>1, iDmgOrig: \x01%i\x03, pre-mod iHP: \x01%i",iDmgOrig,iHP);

				new Float:flHPBuff=GetEntDataFloat(iVic,g_iHPBuffO);

				//if victim has health buffer,
				//we need to do some extra work
				//to reduce health buffer as well
				if (flHPBuff>0)
				{
					//----DEBUG----
					//PrintToChatAll("\x03-flHPBuff>0 condition, pre-mod HPbuffer: \x01%f", flHPBuff);

					new iDmgAdd= iMinBound-iDmgOrig ;

					//if damage add exceeds health,
					//then we need to take the difference
					//and apply it to health buffer instead
					if (iDmgAdd>=iHP)
					{
						//----DEBUG----
						//PrintToChatAll("\x03-iDmgAdd>=iHP condition, pre-mod iDmgAdd: \x01%i",iDmgAdd);

						//we leave the survivor with 1 health
						//because the engine will take it away
						//when it applies the original damage
						//and we want to avoid strange death behaviour
						new iDmgCount=iHP-1;
						iDmgAdd-=iDmgCount;
						SetEntProp(iVic,Prop_Data,"m_iHealth", iHP-iDmgCount );

						//if damage add is more than health buffer,
						//set damage add to health buffer amount
						new iHPBuff=RoundToFloor(flHPBuff);
						if (iHPBuff<iDmgAdd) iDmgAdd=iHPBuff;
						SetEntDataFloat(iVic,g_iHPBuffO, flHPBuff-iDmgAdd ,true);
						PrintHintText(iAtt,"Body Slam: %i bonus damage!", iDmgCount+iDmgAdd);

						//----DEBUG----
						//PrintToChatAll("\x03-damage to health: \x01%i\x03, current health: \x01%i",iDmgCount,GetEntProp(iVic,Prop_Data,"m_iHealth"));
						//PrintToChatAll("\x03-damage to buffer: \x01%i\x03, current buffer: \x01%f",iDmgAdd,GetEntDataFloat(iVic,g_iHPBuffO));

						return 1;
					}

					//if damage add is less than health
					//remaining, then we simply deal
					//the extra damage and let the engine
					//deal with the rest
					else
					{
						//----DEBUG----
						//PrintToChatAll("\x03-iDmgAdd<iHP condition");

						SetEntProp(iVic,Prop_Data,"m_iHealth", iHP-iDmgAdd );
						PrintHintText(iAtt,"Body Slam: %i bonus damage!", iDmgAdd);
						return 1;
					}
				}

				//otherwise, it's straightforward
				//- just reduce victim's hp
				else
				{
					//----DEBUG----
					//PrintToChatAll("\x03no temp hp condition");

					//if original damage exceeds health,
					//just skip the rest since there's no
					//health buffer to worry about
					if (iDmgOrig>=iHP) return 1;
					new iDmgAdd= iMinBound-(iHP-iDmgOrig) ;
					//to prevent strange death behaviour,
					//reduce damage add to less than that
					//of remaining health if necessary
					if (iDmgAdd>=iHP) iDmgAdd=iHP-1;
					SetEntProp(iVic,Prop_Data,"m_iHealth", iHP-iDmgAdd );
					PrintHintText(iAtt,"Body Slam: %i bonus damage!", iDmgAdd);

					//----DEBUG----
					//PrintToChatAll("\x03-iHP<8, %i bonus damage", iDmgAdd );

					return 1;
				}
			}
		}
		return 1;
	}

	return 0;
}



//=============================
// Inf4: Efficient Killer
//=============================

//damage function
EfficientKiller_DamageAdd (iAtt,iVic,iTA,iType,String:stWpn[],iDmgOrig)
{
	if (iTA==3
		&& g_iConfirm[iAtt]==1
		&& StrEqual(stWpn,"hunter_claw")==true
		&& iType==128
		&& g_iInf4[iAtt]==2)
	{
		//stop if eff.killer is disabled
		if (g_iInf4_enable==0
			|| g_iEfficient_enable==0)
			return 1;

		new iDmgAdd = DamageAddRound (iDmgOrig, g_flEfficient_dmgmult);

		if (iDmgAdd==0)
			return 0;

		InfToSurDamageAdd(iVic, iDmgAdd ,iDmgOrig);
		return 1;
	}

	return 0;
}



//=============================
// Inf4: Speed Demon
//=============================

//damage function
SpeedDemon_DamageAdd (iAtt,iVic,iTA,iType,String:stWpn[],iDmgOrig)
{
	if (iTA==3
		&& g_iConfirm[iAtt]==1
		&& StrEqual(stWpn,"hunter_claw")==true
		&& iType==128
		&& g_iInf4[iAtt]==4
		&& g_iMyDisableTarget[iAtt] == -1)
	{
		//stop if eff.killer is disabled
		if (g_iInf4_enable==0
			|| g_iEfficient_enable==0)
			return 1;

		new iDmgAdd = DamageAddRound (iDmgOrig, g_flSpeedDemon_dmgmult);

		if (iDmgAdd==0)
			return 0;

		//----DEBUG----
		//PrintToChatAll("\x05speed demon\x03 damage bonus \x01%i",iDmgAdd);

		InfToSurDamageAdd(iVic, iDmgAdd ,iDmgOrig);
		return 1;
	}

	return 0;
}

SpeedDemon_OnSpawn (iCid)
{
	//stop here if the perk is disabled
	if (g_iSpeedDemon_enable==0
		|| g_iInf4_enable==0)
		return 0;

	//check for motion sickness
	if (g_iInf4[iCid]==4
		&& g_iConfirm[iCid]==1)
	{
		SetEntDataFloat(iCid,g_iLaggedMovementO, 1.0*g_flSpeedDemon_rate ,true);
		return 1;
	}
	else
		SetEntDataFloat(iCid,g_iLaggedMovementO, 1.0 ,true);

	return 0;
}



//=============================
// Inf4: Grasshopper
//=============================

Grass_OnAbilityUse (iCid,String:stAb[])
{
	//stop if grasshopper is disabled
	if (g_iInf4_enable==0
		|| g_iGrass_enable==0)
		return 0;

	if (GetClientTeam(iCid)==3
		&& g_iInf4[iCid]==3
		&& g_iConfirm[iCid]==1)
	{
		//check if it's a pounce/lunge
		if (StrEqual(stAb,"ability_lunge",false)==true)
		{
			CreateTimer(0.1,Grasshopper_DelayedVel,iCid);

			//----DEBUG----
			//PrintToChatAll("\x03grasshopper fired");

			return 1;
		}
	}

	return 0;
}

//delayed velocity change, since the hunter doesn't
//actually start moving until some time after the event
public Action:Grasshopper_DelayedVel (Handle:timer, any:iCid)
{
	KillTimer(timer);
	if (IsServerProcessing()==false)
		return Plugin_Stop;

	decl Float:vecVelocity[3];
	GetEntPropVector(iCid, Prop_Data, "m_vecVelocity", vecVelocity);
	vecVelocity[0] *= g_flGrass_rate;
	vecVelocity[1] *= g_flGrass_rate;
	vecVelocity[2] *= g_flGrass_rate;
	TeleportEntity(iCid, NULL_VECTOR, NULL_VECTOR, vecVelocity);

	return Plugin_Stop;
}


//=============================
// Inf5: Ride Like the Wind
//=============================

//for wind to work, must change VICTIM's speed
Wind_OnRideStart (iAtt,iVic)
{
	if (g_iInf5[iAtt]==1
		&& g_iConfirm[iAtt]==1
		&& g_iInf5_enable==1
		&& g_iWind_enable==1)
	{
		SetEntDataFloat(iVic,g_iLaggedMovementO, 1.0*g_flWind_rate ,true);

		//----DEBUG----
		//PrintToChatAll("\x03-wind apply");
	}
	else
		//reset their run speed
		SetEntDataFloat(iVic,g_iLaggedMovementO, 1.0 ,true);


	return 0;
}

Wind_OnRideEnd (iAtt,iVic)
{
	//----DEBUG----
	//PrintToChatAll("\x03-wind remove");

	//reset their run speed
	SetEntDataFloat(iAtt,g_iLaggedMovementO, 1.0 ,true);
	SetEntDataFloat(iVic,g_iLaggedMovementO, 1.0 ,true);
}



//=============================
// Inf5: Cavalier
//=============================

//set hp after a small delay, to avoid stupid bugs
Cavalier_OnSpawn (iCid)
{
	//stop here if the perk is disabled
	if (g_iCavalier_enable==0
		|| g_iInf5_enable==0)
		return 0;

	//check for perk
	if (g_iInf5[iCid]==2
		&& g_iConfirm[iCid]==1)
	{
		CreateTimer(0.1, Cavalier_ChangeHP, iCid);
		return 1;
	}
	return 0;
}

public Action:Cavalier_ChangeHP (Handle:timer, any:iCid)
{
	KillTimer(timer);
	if (IsServerProcessing()==false
		|| iCid<=0
		|| IsClientInGame(iCid)==false
		|| GetClientTeam(iCid)!=3)
		return Plugin_Stop;

	SetEntityHealth(iCid, RoundToNearest(GetEntProp(iCid,Prop_Data,"m_iHealth") * (1+g_flCavalier_hpmult) ) );

	new Float:flMaxHP = GetConVarInt(FindConVar("z_jockey_health")) * (1+g_flCavalier_hpmult);
	if ( GetEntProp(iCid,Prop_Data,"m_iHealth") > flMaxHP)
		SetEntProp(iCid,Prop_Data,"m_iHealth", RoundToNearest(flMaxHP) );

	//----DEBUG----
	//PrintToChatAll("\x03juggernaut apply hp boost, health\x01 %i", GetEntProp(iTankid,Prop_Data,"m_iHealth"));

	return Plugin_Stop;
}



//=============================
// Inf5: Frogger
//=============================

Frogger_DamageAdd (iAtt,iVic,iTA,String:stWpn[],iDmgOrig)
{
	if (iTA==3
		&& g_iConfirm[iAtt]==1
		&& StrEqual(stWpn,"jockey_claw")==true
		&& g_iInf5[iAtt]==3)
	{
		//stop if frogger is disabled
		if (g_iInf5_enable==0
			|| g_iFrogger_enable==0)
			return 1;

		new iDmgAdd = DamageAddRound (iDmgOrig, g_flFrogger_dmgmult);

		if (iDmgAdd==0)
			return 0;

		//----DEBUG----
		//PrintToChatAll("\x05frogger\x03 damage \x01%i", iDmgAdd);

		InfToSurDamageAdd(iVic, iDmgAdd ,iDmgOrig);
		return 1;
	}

	return 0;
}

Frogger_OnJump (iCid)
{
	//stop if frogger is disabled
	if (g_iInf5_enable==0
		|| g_iFrogger_enable==0
		|| GetEntData(iCid, g_iClassO) != 5)
		return 0;

	if (GetClientTeam(iCid)==3
		&& g_iInf5[iCid]==3
		&& g_iConfirm[iCid]==1)
	{
		CreateTimer(0.1,Frogger_DelayedVel,iCid);

		//----DEBUG----
		//PrintToChatAll("\x05frogger\x03 fired");

		return 1;
	}

	return 0;
}

//delayed velocity change, since the hunter doesn't
//actually start moving until some time after the event
public Action:Frogger_DelayedVel (Handle:timer, any:iCid)
{
	KillTimer(timer);
	if (IsServerProcessing()==false)
		return Plugin_Stop;

	decl Float:vecVelocity[3];
	GetEntPropVector(iCid, Prop_Data, "m_vecVelocity", vecVelocity);
	vecVelocity[0] *= g_flFrogger_rate;
	vecVelocity[1] *= g_flFrogger_rate;
	vecVelocity[2] *= g_flFrogger_rate;
	TeleportEntity(iCid, NULL_VECTOR, NULL_VECTOR, vecVelocity);

	return Plugin_Stop;
}



//=============================
// Inf5: Ghost Rider
//=============================

Ghost_OnSpawn (iCid)
{
	//stop if frogger is disabled
	if (g_iInf5_enable==0
		|| g_iGhost_enable==0)
		return 0;

	if (GetClientTeam(iCid)==3
		&& g_iInf5[iCid]==4
		&& g_iConfirm[iCid]==1)
	{
		SetEntityRenderMode(iCid, RENDER_TRANSCOLOR);
		SetEntityRenderColor(iCid, 190, 190, 255, g_iGhost_alpha);

		//----DEBUG----
		//PrintToChatAll("\x03ghost rider fired");

		return 1;
	}

	return 0;
}



//=============================
// Inf6: Twin Spitfire
//=============================

TwinSF_ResetShotCount (iCid)
{
	g_iTwinSFShotCount[iCid]=0;
}

TwinSF_OnSpawn(iCid)
{
	//----DEBUG----
	//PrintToChatAll("\x05twin sf\x03 on spawn");

	//stop if grasshopper is disabled
	if (g_iInf6_enable==0
		|| g_iTwinSF_enable==0)
		return 0;

	if (GetClientTeam(iCid)==3
		&& g_iInf6[iCid]==1
		&& g_iConfirm[iCid]==1)
	{
		//----DEBUG----
		//PrintToChatAll("\x03- creating timer");

		//update the timestamp stored in plugin to prevent confusion for timer function
		g_flTimeStamp[iCid] = GetEntDataFloat(GetEntDataEnt2(iCid,g_iAbilityO),g_iNextActO+8);
		//reset the shot count
		TwinSF_ResetShotCount(iCid);

		//create the timer to keep changing the spitter's delay
		CreateTimer(1.0,Timer_TwinSFChecks,iCid,TIMER_REPEAT);

		return 1;
	}

	return 0;
}

public Action:Timer_TwinSFChecks (Handle:timer, any:iCid)
{
	//INITIAL CHECKS
	//--------------
	if (IsServerProcessing()==false
		|| iCid <= 0
		|| IsClientInGame(iCid)==false
		|| IsPlayerAlive(iCid)==false
		|| GetEntData(iCid, g_iClassO)!=4)
	{
		g_iTwinSFShotCount[iCid]=0;
		KillTimer(timer);
		return Plugin_Stop;
	}

	//if this is the second, unmodified shot (shot count 1), stop
	//if (g_iTwinSFShotCount[iCid]==0)
		//return Plugin_Continue;

	//----DEBUG----
	//PrintToChatAll("\x03- tick");

	//RETRIEVE VARIABLES
	//------------------
	//get the ability ent id
	new iEntid = GetEntDataEnt2(iCid,g_iAbilityO);
	//if the retrieved gun id is -1, then move on
	if (iEntid == -1)
	{
		g_iTwinSFShotCount[iCid]=0;
		KillTimer(timer);
		return Plugin_Stop;
	}
	//retrieve the next act time
	new Float:flDuration_ret = GetEntDataFloat(iEntid,g_iNextActO+4);

	//----DEBUG----
	//if (g_iShow==1)
	//	PrintToChatAll("\x03- actsuppress dur \x01 %f\x03 timestamp \x01%f", GetEntDataFloat(iEntid, g_iSuppressO+4), GetEntDataFloat(iEntid, g_iSuppressO+8) );




	//CHECK 1: PAUSE?
	//---------------
	//Valve seems to have a weird way of forcing a
	//pause before the cooldown timer starts: by setting
	//the timers to some arbitrarily high number =/
	//IIRC no cooldown exceeds 100s (highest is 30?) so
	//if any values exceed 100, then let timer continue running
	if (flDuration_ret > 100.0)
	{
		//----DEBUG----
		//PrintToChatAll("\x03DT retrieved duration > 100");

		return Plugin_Continue;
	}



	//CHECK 2: AFTER ADJUSTED SHOT IS MADE
	//------------------------------------
	//at this point, either a gun was swapped, or
	//the attack time needs to be adjusted
	//also, only change timer if it's the first shot

	//retrieve current timestamp
	new Float:flTimeStamp_ret = GetEntDataFloat(iEntid,g_iNextActO+8);

	if (g_flTimeStamp[iCid] < flTimeStamp_ret)
	{
		//----DEBUG----
		//PrintToChatAll("\x05TwinSF:\x03 after adjusted shot\n-pre, client \x01%i\x03; entid \x01%i\x03; enginetime\x01 %f\x03; nextactivation: dur \x01 %f\x03 timestamp \x01%f",iCid,iEntid,GetGameTime(),GetEntDataFloat(iEntid, g_iNextActO+4), GetEntDataFloat(iEntid, g_iNextActO+8) );

		//update the timestamp stored in plugin
		g_flTimeStamp[iCid] = flTimeStamp_ret;
		//increase the shot count
		g_iTwinSFShotCount[iCid]++;

		//----DEBUG----
		//PrintToChatAll("\x05TwinSF\x03 shot count \x01%i", g_iTwinSFShotCount[iCid]);

		//check how many shots have been made
		if (g_iTwinSFShotCount[iCid] >= 3)
		{
			//----DEBUG----
			//PrintToChatAll("\x05TwinSF\x03 shot count >=3, setting to x-2");

			//reset shot count if more than 3 shots have been made
			g_iTwinSFShotCount[iCid] -= 2;
		}
		else if (g_iTwinSFShotCount[iCid] == 2)
		{
			//----DEBUG----
			//PrintToChatAll("\x05TwinSF\x03 shot count ==2, continuing");

			//don't do anything if one shot has been made
			return Plugin_Continue;
		}

		//this calculates the time that the player theoretically
		//should have used his ability in order to use it
		//with the shortened cooldown
		//FOR EXAMPLE:
		//vomit, normal cooldown 30s, desired cooldown 6s
		//player uses it at T = 1:30
		//normally, game predicts it to be ready at T + 30s
		//so if we modify T to 1:06, it will be ready at 1:36
		//which is 6s after the player used the ability
		new Float:flTimeStamp_calc = flTimeStamp_ret - (GetConVarFloat(FindConVar("z_spit_interval")) - g_flTwinSF_delay);
		SetEntDataFloat(iEntid, g_iNextActO+8, flTimeStamp_calc, true);

		//----DEBUG----
		//PrintToChatAll("\x03-post, nextactivation dur \x01 %f\x03 timestamp \x01%f", GetEntDataFloat(iEntid, g_iNextActO+4), GetEntDataFloat(iEntid, g_iNextActO+8) );
	}

	return Plugin_Continue;
}



//=============================
// Inf6: Mega Adhesive
//=============================

MegaAd_SlowEffect (iAtt, iVic, String:stWpn[])
{
	if (g_iConfirm[iAtt]==1
		&& StrEqual(stWpn,"insect_swarm")==true
		&& g_iInf6[iAtt]==2)
	{
		//stop if perk is disabled
		/*if (g_iInf6_enable==0
			|| g_iMegaAd_enable==0)
			return 1;*/

		//----DEBUG----
		//PrintToChatAll("\x05megaadhesive\x03 fire, client \x01%i\x03, pre-mod amount \x01%i", iVic, g_iMegaAdCount[iVic]);

		if (g_iMegaAdCount[iVic] <= 0)
		{
			g_iMegaAdCount[iVic] = 10;

			//check if another SI is disabling the survivor
			new iDisabler = g_iMyDisabler[iVic];
			if (iDisabler == -1)
				SetEntDataFloat(iVic,g_iLaggedMovementO, g_flMegaAd_slow ,true);
			else
			{
				//check if disabler is valid
				//if not, then just apply normal effects
				if (IsValidEntity(iDisabler)==false
					|| IsClientConnected(iDisabler)==false
					|| IsClientInGame(iDisabler)==false)
					SetEntDataFloat(iVic,g_iLaggedMovementO, g_flMegaAd_slow ,true);
				//otherwise if it's valid, then check the class
				//don't apply slow for jockeys or smokers
				else
				{
					//1 = smoker, 5 = jockey
					new iClass = GetEntData(iDisabler, g_iClassO);
					if (iClass != 1
						&& iClass != 5)
						SetEntDataFloat(iVic,g_iLaggedMovementO, g_flMegaAd_slow ,true);
				}
			}
		}
		else
			g_iMegaAdCount[iVic]++;

		if (g_hMegaAdTimer[iVic] == INVALID_HANDLE)
			g_hMegaAdTimer[iVic] = CreateTimer(0.3, MegaAd_Timer, iVic, TIMER_REPEAT);

		return 1;
	}
	return 0;
}

public Action:MegaAd_Timer (Handle:timer, any:iVic)
{
	if (IsServerProcessing()==false
		|| IsValidEntity(iVic)==false
		|| IsClientConnected(iVic)==false
		|| IsClientInGame(iVic)==false)
	{
		KillTimer(timer);
		g_hMegaAdTimer[iVic] = INVALID_HANDLE;
		return Plugin_Stop;
	}

	g_iMegaAdCount[iVic]--;

	//----DEBUG----
	//PrintToChatAll("\x03- tick, client \x01%i\x03 amount \x01%i", iVic, g_iMegaAdCount[iVic] );

	if (g_iMegaAdCount[iVic] > 0)
	{
		//SetEntDataFloat(iVic,g_iLaggedMovementO, g_flMegaAd_slow ,true);

		//check if another SI is disabling the survivor
		new iDisabler = g_iMyDisabler[iVic];
		if (iDisabler == -1)
			SetEntDataFloat(iVic,g_iLaggedMovementO, g_flMegaAd_slow ,true);
		else
		{
			//check if disabler is valid
			//if not, then just apply normal effects
			if (IsValidEntity(iDisabler)==false
				|| IsClientConnected(iDisabler)==false
				|| IsClientInGame(iDisabler)==false)
				SetEntDataFloat(iVic,g_iLaggedMovementO, g_flMegaAd_slow ,true);
			//otherwise if it's valid, then check the class
			//don't apply slow for jockeys or smokers
			else
			{
				//1 = smoker, 5 = jockey
				new iClass = GetEntData(iDisabler, g_iClassO);
				if (iClass != 1
					&& iClass != 5)
					SetEntDataFloat(iVic,g_iLaggedMovementO, g_flMegaAd_slow ,true);
			}
		}

		return Plugin_Continue;
	}
	else
	{
		//----DEBUG----
		//PrintToChatAll("\x03- duration over, killing timer");

		g_iMegaAdCount[iVic] = 0;
		SetEntDataFloat(iVic,g_iLaggedMovementO, 1.0 ,true);

		//check if survivor has extra run speed
		Extreme_Rebuild();

		KillTimer(timer);
		g_hMegaAdTimer[iVic] = INVALID_HANDLE;
		return Plugin_Stop;
	}
}



//=============================
// Inf7: Scattering Ram
//=============================

Scatter_OnImpact (iAtt,iVic)
{
	//stop if disabled
	if (g_iInf7_enable==0
		|| g_iScatter_enable==0)
		return 0;

	if (GetClientTeam(iAtt)==3
		&& g_iInf7[iAtt]==1
		&& g_iConfirm[iAtt]==1)
	{
		CreateTimer(0.1,Timer_ScatterForce,iVic);

		//----DEBUG----
		//PrintToChatAll("\x05Scatter \x03fired");

		return 1;
	}

	return 0;
}

Scatter_OnSpawn (iCid)
{
	//stop here if the perk is disabled
	if (g_iScatter_enable==0
		|| g_iInf7_enable==0)
		return 0;

	//check for perk
	if (g_iInf7[iCid]==1
		&& g_iConfirm[iCid]==1)
	{
		CreateTimer(0.1, Scatter_ChangeHP, iCid);
		return 1;
	}
	return 0;
}

public Action:Timer_ScatterForce (Handle:timer, any:iVic)
{
	KillTimer(timer);

	if (IsServerProcessing()==false)
		return Plugin_Stop;

	decl Float:vecVelocity[3];
	GetEntPropVector(iVic, Prop_Data, "m_vecVelocity", vecVelocity);
	vecVelocity[0] *= g_flScatter_force;
	vecVelocity[1] *= g_flScatter_force;
	vecVelocity[2] *= g_flScatter_force;
	TeleportEntity(iVic, NULL_VECTOR, NULL_VECTOR, vecVelocity);

	return Plugin_Stop;
}

public Action:Scatter_ChangeHP (Handle:timer, any:iCid)
{
	KillTimer(timer);
	if (IsServerProcessing()==false
		|| iCid<=0
		|| IsClientInGame(iCid)==false
		|| GetClientTeam(iCid)!=3)
		return Plugin_Stop;

	SetEntityHealth(iCid, RoundToNearest(GetEntProp(iCid,Prop_Data,"m_iHealth") * (1+g_flScatter_hpmult) ) );

	new Float:flMaxHP = GetConVarInt(FindConVar("z_charger_health")) * (1+g_flScatter_hpmult);
	if ( GetEntProp(iCid,Prop_Data,"m_iHealth") > flMaxHP)
		SetEntProp(iCid,Prop_Data,"m_iHealth", RoundToNearest(flMaxHP) );

	//----DEBUG----
	//PrintToChatAll("\x03juggernaut apply hp boost, health\x01 %i", GetEntProp(iTankid,Prop_Data,"m_iHealth"));

	return Plugin_Stop;
}



//=============================
// Inf7: Speeding Bullet
//=============================

Bullet_OnAbilityUse (iCid,String:stAb[])
{
	//stop if frogger is disabled
	if (g_iInf7_enable==0
		|| g_iBullet_enable==0)
		return 0;

	if (GetClientTeam(iCid)==3
		&& g_iInf7[iCid]==2
		&& g_iConfirm[iCid]==1)
	{
		//check if it's a pounce/lunge
		if (StrEqual(stAb,"ability_charge",false)==true)
		{
			SetEntDataFloat(iCid,g_iLaggedMovementO, 1.0*g_flBullet_rate ,true);

			//----DEBUG----
			//PrintToChatAll("\x03speeding bullet fired");

			return 1;
		}
	}

	return 0;
}



//=============================
// Inf2: Tank Perks
//=============================


//PRIMARY TANK FUNCTION		----------------------
//primary function for handling tank spawns
public Event_Tank_Spawn (Handle:event, const String:name[], bool:dontBroadcast)
{
	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));
	if (iCid==0
		|| GetClientTeam(iCid)!=3)
		return;

	//----DEBUG----
	//PrintToChatAll("\x03Tank Spawn detected, client \x01%i\x03,g_iTank \x01%i", iCid, g_iTank);

	//reset their run speed
	//from martial artist or speed demon
	SetEntDataFloat(iCid,g_iLaggedMovementO, 1.0 ,true);

	//stop if tank perks are disallowed
	if (g_iInf2_enable==0)
		return;

	//start a check if it's a bot
	if (IsFakeClient(iCid)==true)
	{
		g_iTankBotTicks=0;
		CreateTimer(2.5,Timer_TankBot,iCid,TIMER_REPEAT);
	}

	else
		CreateTimer(1.0,Timer_Tank_ApplyPerk,iCid);
}

public Action:Timer_Tank_ApplyPerk (Handle:timer, any:iCid)
{
	KillTimer(timer);
	Tank_ApplyPerk(iCid);
}

Tank_ApplyPerk (any:iCid)
{
	//why apply tank perks to non-infected?
	if (IsClientInGame(iCid)==false
		|| GetClientTeam(iCid)!=3)
		return;
	
	//and make sure we're dealing with a tank
	new String:st_class[32];
	GetClientModel(iCid,st_class,32);
	if (StrContains(st_class,"hulk",false) == -1)
		return;

	//----DEBUG----
	//PrintToChatAll("\x03applying perks; tank detected, model: \x01%s",st_class);

	//first battery of tests for perks 1-4 (not double trouble)
	if (g_iTank<2
		&& g_iConfirm[iCid]==1
		&& g_iInf2[iCid]<5)
	{
		switch (g_iInf2[iCid])
		{
		//check for adrenal glands
		case 1:
			{
				//----DEBUG----
				//PrintToChatAll("\x03applying adrenal glands");

				g_iTank=1;

				//stop if adrenal glands is disabled
				if (g_iAdrenal_enable==0)
					return;

				Adrenal_Rebuild();

				if (IsFakeClient(iCid)==false)
					PrintHintText(iCid,"坦克狂化: %t", "AdrenalGlandsHint");
				return ;
			}
		//check for juggernaut perk
		case 2:
			{
				//at least tell plugin that there's a tank
				g_iTank=1;

				//stop if juggernaut is disabled
				if (g_iJuggernaut_enable==0)
					return;

				//----DEBUG----
				//PrintToChatAll("\x03applying juggernaut");

				CreateTimer(0.1,Juggernaut_ChangeHP,iCid);

				//if it's gotten this far, juggernaut's
				//about to get applied so we tell plugin the news
				g_iTank=2;

				if (IsFakeClient(iCid)==false)
					PrintHintText(iCid,"世界主宰: %t", "JuggernautHint");

				return ;
			}

		//check for metabolic boost
		case 3:
			{
				//----DEBUG----
				//PrintToChatAll("\x03applying metabolic boost");

				g_iTank=1;

				SetEntDataFloat(iCid,g_iLaggedMovementO, 1.0*g_flMetabolic_speedmult ,true);
				if (IsFakeClient(iCid)==false)
					PrintHintText(iCid,"代谢增强: %t", "MetabolicHint");
				return ;
			}

		//check for storm caller
		case 4:
			{
				g_iTank=1;

				//stop if storm caller is disabled
				if (g_iStorm_enable==0)
					return;

				//----DEBUG----
				//PrintToChatAll("\x03applying storm caller");

				new iflags=GetCommandFlags("z_spawn");
				SetCommandFlags("z_spawn", iflags & ~FCVAR_CHEAT);
				for (new iI=0 ; iI<=g_iStorm_mobcount ; iI++)
				{
					FakeClientCommand(iCid,"z_spawn mob auto");
				}
				SetCommandFlags("z_spawn", iflags);
				if (IsFakeClient(iCid)==false)
					PrintHintText(iCid,"召唤小弟: %t", "StormCallerHint");

				return ;
			}
		}
	}

	//check for double trouble activation;
	//must have perk confirmed (g_iConfirm==1)
	//and double trouble must not be in effect (g_iTank!=3,4)
	else if (g_iInf2[iCid]==5
		&& g_iTank<3
		&& g_iConfirm[iCid]==1)
	{
		g_iTank=3;
		g_iTank_MainId=iCid;

		//stop if double trouble is disabled
		if (g_iDouble_enable==0)
			return;

		//recount the number of tanks left
		g_iTankCount=0;
		for (new iI=1 ; iI<=MaxClients ; iI++)
		{
			if (IsClientInGame(iI)==true
				&& IsPlayerAlive(iI)==true
				&& GetClientTeam(iI)==3)
			{
				GetClientModel(iI,st_class,32);
				if (StrContains(st_class,"hulk",false) != -1)
					g_iTankCount++;

				//----DEBUG----
				//PrintToChatAll("\x03-counting \x01%i",iI);
			}
		}
		
		//----DEBUG----
		//PrintToChatAll("\x03double trouble 1st tank apply");

		CreateTimer(1.0,DoubleTrouble_ChangeHP,iCid);
		CreateTimer(1.0,DoubleTrouble_SpawnTank,iCid);

		CreateTimer(3.0,DoubleTrouble_FrustrationTimer,iCid,TIMER_REPEAT);

		if (IsFakeClient(iCid)==false)
			PrintHintText(iCid,"心动呼唤: %t", "DoubleTroubleHint1");
		return ;
	}

	//if double trouble is activated (g_iTank==3)
	//subsequent tanks will have reduced hp
	else if (g_iTank==3)
	{
		//stop if double trouble is disabled
		if (g_iDouble_enable==0)
			return;

		//recount the number of tanks left
		g_iTankCount=0;
		for (new iI=1 ; iI<=MaxClients ; iI++)
		{
			if (IsClientInGame(iI)==true
				&& IsPlayerAlive(iI)==true
				&& GetClientTeam(iI)==3)
			{
				GetClientModel(iI,st_class,32);
				if (StrContains(st_class,"hulk",false) != -1)
					g_iTankCount++;

				//----DEBUG----
				//PrintToChatAll("\x03-counting \x01%i",iI);
			}
		}

		//----DEBUG----
		//PrintToChatAll("\x03double trouble 2nd+ tank apply");

		if (IsFakeClient(iCid)==false)
			PrintHintText(iCid,"%t", "DoubleTroubleHint2");
		CreateTimer(0.1,DoubleTrouble_ChangeHP,iCid);

		//CreateTimer(3.0,DoubleTrouble_FrustrationTimer,iCid,TIMER_REPEAT);

		decl Float:vecOrigin[3];
		GetClientAbsOrigin(g_iTank_MainId,vecOrigin);
		TeleportEntity(iCid,vecOrigin,NULL_VECTOR,NULL_VECTOR);

		return ;
	}

	//if frustrated double trouble tank is being passed, do nothing
	else if (g_iTank==4)
	{
		//----DEBUG----
		//PrintToChatAll("\x03double trouble, frustration pass (no perks granted)");

		g_iTank=3;
		return ;
	}

	//if none of the special perks apply, just tell plugin that there's a tank
	else
	{
		//----DEBUG----
		//PrintToChatAll("\x03nothing applied, setting g_iTank to 1");

		g_iTank=1;
		return ;
	}
}
//END PRIMARY TANK FUNCTION ----------------------

//timer functions to change tank's hp
//since doing it immediately doesn't seem to work =/
public Action:Juggernaut_ChangeHP (Handle:timer, any:iTankid)
{
	KillTimer(timer);
	if (IsServerProcessing()==false
		|| iTankid==0
		|| IsClientInGame(iTankid)==false
		|| GetClientTeam(iTankid)!=3)
		return Plugin_Stop;

	SetEntityHealth(iTankid, GetEntProp(iTankid,Prop_Data,"m_iHealth") + g_iJuggernaut_hp );

	//----DEBUG----
	//PrintToChatAll("\x03juggernaut apply hp boost, health\x01 %i", GetEntProp(iTankid,Prop_Data,"m_iHealth"));

	return Plugin_Stop;
}
public Action:DoubleTrouble_ChangeHP (Handle:timer, any:iTankid)
{
	KillTimer(timer);
	if (IsServerProcessing()==false
		|| iTankid==0
		|| IsClientInGame(iTankid)==false
		|| GetClientTeam(iTankid)!=3)
		return Plugin_Stop;

	SetEntityHealth(iTankid, RoundToCeil(GetEntProp(iTankid,Prop_Data,"m_iHealth")*g_flDouble_hpmult) );

	//----DEBUG----
	//PrintToChatAll("\x03double trouble apply hp reduction, health \x01%i", GetEntProp(iTankid,Prop_Data,"m_iHealth"));

	return Plugin_Stop;
}

public Action:DoubleTrouble_SpawnTank (Handle:timer, any:iCid)
{
	KillTimer(timer);
	if (IsServerProcessing()==false)
		return Plugin_Stop;

	//strip flags
	new iflags=GetCommandFlags("z_spawn");
	SetCommandFlags("z_spawn", iflags & ~FCVAR_CHEAT);

	decl iSpawner;
	new iCount = 0;
	new iReg[8] = 0;
	//before we can spawn the tank, need to find a suitable players
	for (new iI=1 ; iI<=MaxClients ; iI++)
	{
		if (IsClientInGame(iI)==true
			&& IsFakeClient(iI)==false
			&& GetClientTeam(iI)==3
			&& iI != iCid
			//check if client is either dead or a ghost
			&& ( GetClientHealth(iI)<=1 || GetEntData(iI,g_iIsGhostO)!=0 ) )
		{
			iCount++;
			iReg[iCount]=iI;
		}
	}

	//check if any players were available
	if (iCount==0)
	{
		iSpawner = CreateFakeClient("perkmod - bot tank spawner");
		CreateTimer(5.0, DoubleTrouble_KickBotSpawner, iSpawner, TIMER_REPEAT);
	}
	else
		iSpawner = iReg[ GetRandomInt(1,iCount) ];

	//----DEBUG----
	//PrintToChatAll("\x05double trouble\x03 spawner id \x01%i", iSpawner);

	//spawn the tank and reset flags
	FakeClientCommand(iSpawner,"z_spawn tank");
	SetCommandFlags("z_spawn", iflags);

	//----DEBUG----
	//PrintToChatAll("\x03double trouble attempting to spawn 2nd tank");

	return Plugin_Stop;
}

public Action:DoubleTrouble_KickBotSpawner (Handle:timer, any:iSpawner)
{
	if ((IsServerProcessing()==false
		&& IsFakeClient(iSpawner)==true)
		|| (IsClientInGame(iSpawner)==true
		&& IsClientInKickQueue(iSpawner)==false
		&& IsPlayerAlive(iSpawner)==false
		&& IsFakeClient(iSpawner)==true) )
	{
		KickClient(iSpawner);
		KillTimer(timer);
		return Plugin_Stop;
	}
	return Plugin_Continue;
}

Adrenal_Rebuild ()
{
	//clears all DT-related vars
	Adrenal_Clear();

	//if the server's not running or
	//is in the middle of loading, stop
	if (IsServerProcessing()==false)
		return;

	//----DEBUG----
	//PrintToChatAll("\x03martial artist rebuilding registry");

	if (g_iInf2_enable==0)
		return;

	for (new iI=1 ; iI<=MaxClients ; iI++)
	{
		if (IsClientInGame(iI)==true
			&& IsPlayerAlive(iI)==true
			&& GetClientTeam(iI)==3
			&& g_iInf2[iI]==1
			&& g_iConfirm[iI]==1)
		{
			g_iAdrenalRegisterCount++;
			g_iAdrenalRegisterIndex[g_iAdrenalRegisterCount]=iI;

			//----DEBUG----
			//PrintToChatAll("\x03-registering \x01%i",iI);
		}
	}
}

Adrenal_Clear ()
{
	g_iAdrenalRegisterCount=0;
	for (new iI=1 ; iI<=MaxClients ; iI++)
	{
		g_iAdrenalRegisterIndex[iI]= -1;
	}

	//----DEBUG----
	//PrintToChatAll("\x03cleared");
}

Adrenal_OnGameFrame()
{
	//or if no one has DT, don't bother either
	if (g_iAdrenalRegisterCount==0
		|| g_iTank<=0)
		return 0;

	decl iCid;
	//this tracks the player's ability id
	decl iEntid;
	//this tracks the calculated next attack
	decl Float:flTimeStamp_calc;
	//this, retrieved next attack
	decl Float:flDuration_ret;
	//this, on the other hand, tracks the current next attack
	decl Float:flTimeStamp_ret;

	for (new iI=1; iI<=g_iAdrenalRegisterCount; iI++)
	{
		//PUNCH MOD
		//---------

		//PRE-CHECKS 1: RETRIEVE VARS
		//---------------------------

		iCid = g_iAdrenalRegisterIndex[iI];
		//stop on this client
		//when the next client id is null
		if (iCid <= 0) return 0;

		//we have to adjust numbers on the gun, not the player
		//so we get the active weapon id here
		iEntid = GetEntDataEnt2(iCid,g_iActiveWO);
		//if the retrieved gun id is -1, then...
		//wtf mate? just move on
		if (iEntid == -1) continue;

		flDuration_ret = GetEntDataFloat(iEntid,g_iAttackTimerO+4);
		flTimeStamp_ret = GetEntDataFloat(iEntid,g_iAttackTimerO+8);

		//reset frustration
		SetEntData(iCid, g_iFrustrationO, 0);


		//CHECK 1: AFTER ADJUSTED ATT IS MADE
		//------------------------------------
		//at this point, either a gun was swapped, or
		//the attack time needs to be adjusted
		//checks: stored gun id same as retrieved gun id,
		// and retrieved next attack time is after stored value
		//actions: adjusts next attack time
		if (g_flAdrenalTimeStamp[iCid] < flTimeStamp_ret)
		{
			//----DEBUG----
			//PrintToChatAll("\x05Adrenal\x03 after adjusted shot\n-pre, client \x01%i\x03; entid \x01%i\x03; enginetime\x01 %f\x03; nextactivation: dur \x01 %f\x03 timestamp \x01%f",iCid,iEntid,GetGameTime(),GetEntDataFloat(iEntid, g_iAttackTimerO+4), GetEntDataFloat(iEntid, g_iAttackTimerO+8) );

			//update the timestamp stored in plugin
			g_flAdrenalTimeStamp[iCid] = flTimeStamp_ret;

			//this calculates the time that the player theoretically
			//should have used his ability in order to use it
			//with the shortened cooldown
			//FOR EXAMPLE:
			//vomit, normal cooldown 30s, desired cooldown 6s
			//player uses it at T = 1:30
			//normally, game predicts it to be ready at T + 30s
			//so if we modify T to 1:06, it will be ready at 1:36
			//which is 6s after the player used the ability
			flTimeStamp_calc = flTimeStamp_ret - (flDuration_ret * (1 - g_flAdrenal_punchcdmult) );
			SetEntDataFloat(iEntid, g_iAttackTimerO+8, flTimeStamp_calc, true);
			SetEntDataFloat(iEntid, g_iNextPAttO, flTimeStamp_calc, true);
			//SetEntDataFloat(iEntid, g_iNextSAttO, flTimeStamp_calc, true);

			//similar logic to above, but this change is necessary
			//so that the little cooldown gui is shown properly
			//SetEntDataFloat(iEntid, g_iNextActO+4, flNextAct_ret * (1 + 0.2) , true);

			//----DEBUG----
			//PrintToChatAll("\x03-post, nextactivation dur \x01 %f\x03 timestamp \x01%f", GetEntDataFloat(iEntid, g_iAttackTimerO+4), GetEntDataFloat(iEntid, g_iAttackTimerO+8) );

			continue;
		}



		//THROW MOD
		//---------

		//RETRIEVE VARIABLES
		//------------------
		//get the ability ent id
		iEntid = GetEntDataEnt2(iCid,g_iAbilityO);
		//if the retrieved gun id is -1, then move on
		if (iEntid == -1) continue;
		//retrieve the next act time
		flDuration_ret = GetEntDataFloat(iEntid,g_iNextActO+4);

		//----DEBUG----
		//if (g_iShow==1)
		//	PrintToChatAll("\x03- actsuppress dur \x01 %f\x03 timestamp \x01%f", GetEntDataFloat(iEntid, g_iSuppressO+4), GetEntDataFloat(iEntid, g_iSuppressO+8) );


		//CHECK 1: PAUSE?
		//---------------
		//Valve seems to have a weird way of forcing a
		//pause before the cooldown timer starts: by setting
		//the timers to some arbitrarily high number =/
		//IIRC no cooldown exceeds 100s (highest is 30?) so
		//if any values exceed 100, then let timer continue running
		if (flDuration_ret > 100.0)
		{
			//----DEBUG----
			//PrintToChatAll("\x03DT retrieved duration > 100");

			continue;
		}


		//CHECK 2: AFTER ADJUSTED SHOT IS MADE
		//------------------------------------
		//at this point, either a gun was swapped, or
		//the attack time needs to be adjusted
		//also, only change timer if it's the first shot

		//retrieve current timestamp
		flTimeStamp_ret = GetEntDataFloat(iEntid,g_iNextActO+8);

		if (g_flTimeStamp[iCid] < flTimeStamp_ret)
		{
			//----DEBUG----
			//PrintToChatAll("\x05TwinSF:\x03 after adjusted shot\n-pre, client \x01%i\x03; entid \x01%i\x03; enginetime\x01 %f\x03; nextactivation: dur \x01 %f\x03 timestamp \x01%f",iCid,iEntid,GetGameTime(),GetEntDataFloat(iEntid, g_iNextActO+4), GetEntDataFloat(iEntid, g_iNextActO+8) );

			//update the timestamp stored in plugin
			g_flTimeStamp[iCid] = flTimeStamp_ret;

			//this calculates the time that the player theoretically
			//should have used his ability in order to use it
			//with the shortened cooldown
			//FOR EXAMPLE:
			//vomit, normal cooldown 30s, desired cooldown 6s
			//player uses it at T = 1:30
			//normally, game predicts it to be ready at T + 30s
			//so if we modify T to 1:06, it will be ready at 1:36
			//which is 6s after the player used the ability

			//----DEBUG----
			//PrintToChatAll("\x03-calc, flTimeStamp_ret \x01%f\x03 flDuration_ret \x01%f\x03 g_flRockInterval \x01%f", flTimeStamp_ret, flDuration_ret, g_flAdrenal_throwcdmult );

			flTimeStamp_calc = flTimeStamp_ret - (flDuration_ret * g_flAdrenal_throwcdmult);
			SetEntDataFloat(iEntid, g_iNextActO+8, flTimeStamp_calc, true);

			//----DEBUG----
			//PrintToChatAll("\x03-post, nextactivation dur \x01 %f\x03 timestamp \x01%f", GetEntDataFloat(iEntid, g_iNextActO+4), GetEntDataFloat(iEntid, g_iNextActO+8) );
		}
	}

	return 0;
}

//resets frustration for double trouble tanks
//which is a band-aid solution =P for disappearing
//tanks whenever one becomes frustrated when there's
//two or more active tanks
public Action:DoubleTrouble_FrustrationTimer (Handle:timer, any:iCid)
{
	if (IsServerProcessing()==false)
	{
		KillTimer(timer);
		return Plugin_Stop;
	}

	//----DEBUG----
	/*
	PrintToChatAll("\x03tank frustration reset begin");
	if (IsServerProcessing()==false)
		PrintToChatAll("\x03- not processing");
	if (IsClientInGame(iCid)==false)
		PrintToChatAll("\x03- not ingame");
	if (IsFakeClient(iCid)==true)
		PrintToChatAll("\x03- is a bot");
	if (IsPlayerAlive(iCid)==false)
		PrintToChatAll("\x03- not alive");
	if (GetClientTeam(iCid)!=3)
		PrintToChatAll("\x03- not infected");
	*/

	//recount the number of tanks left
	decl String:st_class[32];
	g_iTankCount=0;
	for (new iI=1 ; iI<=MaxClients ; iI++)
	{
		if (IsClientInGame(iI)==true
			&& IsPlayerAlive(iI)==true
			&& GetClientTeam(iI)==3)
		{
			GetClientModel(iI,st_class,32);
			if (StrContains(st_class,"hulk",false) != -1)
				g_iTankCount++;

			//----DEBUG----
			//PrintToChatAll("\x03-counting \x01%i",iI);
		}
	}

	//----DEBUG----
	//if (g_iTankCount<=1)
		//PrintToChatAll("\x03- 1 or less tanks");

	//stop the timer if any of these
	//conditions are true
	if (IsClientInGame(iCid)==false
		|| IsFakeClient(iCid)==true
		|| IsPlayerAlive(iCid)==false
		|| GetClientTeam(iCid)!=3
		|| g_iTankCount<=1
		|| g_iInf2_enable==0
		|| g_iDouble_enable==0)
	{
		//----DEBUG----
		//PrintToChatAll("\x03- stopping, tankcount \x01%i",g_iTankCount);

		KillTimer(timer);
		return Plugin_Stop;
	}

	//----DEBUG----
	//PrintToChatAll("\x03- checks passed, tankcount \x01%i",g_iTankCount);

	SetEntData(iCid,g_iFrustrationO,0);

	//----DEBUG----
	//PrintToChatAll("\x03- client \x01%i\x03, current frustration \x01%i", iCid, GetEntData(iCid,g_iFrustrationO) );

	return Plugin_Continue;
}



//when switching players from frustration, reset tank's hp and speed boost
public Action:Event_Tank_Frustrated(Handle:event, const String:name[], bool:dontBroadcast)
{
	//----DEBUG----
	//PrintToChatAll("\x03tank frustration detected");

	new iCid=GetClientOfUserId(GetEventInt(event,"userid"));

	if (IsServerProcessing()==false
		|| iCid==0
		|| IsClientInGame(iCid)==false
		|| GetClientTeam(iCid)!=3)
		return Plugin_Continue;

	//if this is a tank spawned under double trouble, it gets no perks
	//setting g_iTank to 4 means any tank "spawns" get no perks
	//and the main tank spawn function won't do anything to the tank
	if (g_iTank==3) g_iTank=4;

	SetEntDataFloat(iCid,g_iLaggedMovementO, 1.0 ,true);
	
	return Plugin_Continue;
}


//timer to check for bots
public Action:Timer_TankBot (Handle:timer, any:iTankid)
{
	KillTimer(timer);

	if (IsServerProcessing()==false
		|| IsValidEntity(iTankid)==false
		|| IsClientInGame(iTankid)==false
		|| IsFakeClient(iTankid)==false
		|| g_iTankBotTicks>=4
		|| g_iInf2_enable==0)
	{
		//----DEBUG----
		//PrintToChatAll("\x03stopping bot timer");

		return Plugin_Stop;
	}

	if (IsClientInGame(iTankid)==true
		&& IsFakeClient(iTankid)==true)
	{
		g_iTankBotTicks++;

		//----DEBUG----
		//PrintToChatAll("\x03tankbot tick %i",g_iTankBotTicks);

		if (g_iTankBotTicks>=3)
		{
			//----DEBUG----
			//PrintToChatAll("\x03bot tank detected");

			//set bot perks
			g_iInf2[iTankid] = Bot_Inf2_PickRandom();
			g_iConfirm[iTankid]=1;

			//----DEBUG----
			//PrintToChatAll("\x03-tank bot perk \x01%i",g_iInf2[iTankid]);

			Tank_ApplyPerk(iTankid);
			return Plugin_Stop;
		}
	}
	return Plugin_Stop;
}





//====================================================
//====================================================
//					M	E	N	U
//====================================================
//====================================================



//=============================
//	CHAT CHECK, TOP MENU, SELECT SUBMENU
//=============================

//check chat
public Action:MenuOpen_OnSay(iCid, args)
{
	//if (iCid==0) return Plugin_Continue;
	//if (args<1) return Plugin_Continue;
	//decl String:st_chat[MAXPLAYERS+1];
	//GetCmdArg(1,st_chat,64);
	//if (StrEqual(st_chat,"!perks",false)==true)
	//{
	new iT = GetClientTeam(iCid);

	if (g_iConfirm[iCid]==0)
	{
		if (iT==2)
			SendPanelToClient(Menu_Initial(iCid),iCid,Menu_ChooseInit,MENU_TIME_FOREVER);
		else if (iT==3)
			SendPanelToClient(Menu_Initial(iCid),iCid,Menu_ChooseInit_Inf,MENU_TIME_FOREVER);
		return Plugin_Continue;
	}

	if (iT==2)
		SendPanelToClient(Menu_ShowChoices(iCid),iCid,Menu_DoNothing,15);
	else if (iT==3)
		SendPanelToClient(Menu_ShowChoices_Inf(iCid),iCid,Menu_DoNothing,15);
	//}
	return Plugin_Continue;
}

//build initial menu
public Handle:Menu_Initial (iCid)
{
	new Handle:menu = CreatePanel();
	decl String:stPanel[128];
	SetPanelTitle(menu, "技能系统");

	//"This server is using Perkmod"
	Format(stPanel, 128, "%t", "InitialMenuPanel1");
	DrawPanelText(menu, stPanel);
	//"Select option 1 to customize your perks"
	Format(stPanel, 128, "%t", "InitialMenuPanel2");
	DrawPanelText(menu, stPanel);
	//"Customize Perks"
	Format(stPanel, 128, "%t", "InitialMenuPanel3");
	DrawPanelItem(menu, stPanel);

	//random perks, enable only if cvar is set
	if (g_iRandomEnable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		//"You can opt to randomize your perks"
		Format(stPanel, 128, "%t", "InitialMenuPanel4");
		DrawPanelText(menu, stPanel);
		//"but you can't change them afterwards"
		Format(stPanel, 128, "%t", "InitialMenuPanel5");
		DrawPanelText(menu, stPanel);
		//"Randomize Perks"
		Format(stPanel, 128, "%t", "InitialMenuPanel6");
		DrawPanelItem(menu, stPanel);
	}

	//"Otherwise, you can use whatever"
	Format(stPanel, 128, "%t", "InitialMenuPanel7");
	DrawPanelText(menu, stPanel);
	//"perks you've selected already"
	Format(stPanel, 128, "%t", "InitialMenuPanel8");
	DrawPanelText(menu, stPanel);
	//"by using option 3"
	Format(stPanel, 128, "%t", "InitialMenuPanel9");
	DrawPanelText(menu, stPanel);
	//"PLAY NOW!"
	Format(stPanel, 128, "%t", "InitialMenuPanel10");
	DrawPanelItem(menu, stPanel);

	return menu;
}

public Menu_ChooseInit (Handle:topmenu, MenuAction:action, param1, param2)
{
	if (topmenu!=INVALID_HANDLE) CloseHandle(topmenu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			case 1:
				SendPanelToClient(Menu_Top(param1),param1,Menu_ChooseSubMenu,MENU_TIME_FOREVER);
			case 2:
				{
					AssignRandomPerks(param1);
					PrintHintText(param1,"心动: %t", "ThanksForChoosingMessage");
				}
			case 3:
				{
					g_iConfirm[param1]=1;
					Event_Confirm_Unbreakable(param1);
					Event_Confirm_Grenadier(param1);
					Event_Confirm_ChemReliant(param1);
					Event_Confirm_DT(param1);
					Event_Confirm_MA(param1);
					Event_Confirm_LittleLeaguer(param1);
					PrintHintText(param1,"心动: %t", "ThanksForChoosingMessage");
				}
			default:
				{
					if (IsClientInGame(param1)==true)
						SendPanelToClient(Menu_Top(param1),param1,Menu_ChooseSubMenu,MENU_TIME_FOREVER);
				}
		}
	}

	else
	{
		if (IsClientInGame(param1)==true)
			SendPanelToClient(Menu_Top(param1),param1,Menu_ChooseSubMenu,MENU_TIME_FOREVER);
	}
}

public Menu_ChooseInit_Inf (Handle:topmenu, MenuAction:action, param1, param2)
{
	if (topmenu!=INVALID_HANDLE) CloseHandle(topmenu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			case 1:
				SendPanelToClient(Menu_Top_Inf(param1),param1,Menu_ChooseSubMenu_Inf,MENU_TIME_FOREVER);
			case 2:
				{
					AssignRandomPerks(param1);
					PrintHintText(param1,"心动: %t", "ThanksForChoosingMessage");
				}
			case 3:
				{
					g_iConfirm[param1]=1;
					PrintHintText(param1,"心动: %t", "ThanksForChoosingMessage");
				}
			default:
				{
					if (IsClientInGame(param1)==true)
						SendPanelToClient(Menu_Top_Inf(param1),param1,Menu_ChooseSubMenu_Inf,MENU_TIME_FOREVER);
				}
		}
	}

	else
	{
		if (IsClientInGame(param1)==true)
			SendPanelToClient(Menu_Top_Inf(param1),param1,Menu_ChooseSubMenu_Inf,MENU_TIME_FOREVER);
	}
}

//build top menu
public Handle:Menu_Top (iCid)
{
	new Handle:menu = CreatePanel();
	SetPanelTitle(menu, "技能系统 - 主菜单");
	DrawPanelText(menu,"每个菜单可选一个技能");
	decl String:st_perk[32];
	decl String:st_display[MAXPLAYERS+1];

	//set name for sur1 perk
	if (g_iSur1[iCid]==1
		&& (g_iStopping_enable==1		&&	g_iL4D_GameMode==0
		|| g_iStopping_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iStopping_enable_vs==1		&&	g_iL4D_GameMode==2))
		st_perk="强力射击";
	else if (g_iSur1[iCid]==2
		&& (g_iDT_enable==1		&&	g_iL4D_GameMode==0
		|| g_iDT_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iDT_enable_vs==1	&&	g_iL4D_GameMode==2))
		st_perk="快速射击";
	else if (g_iSur1[iCid]==3
		&& (g_iSoH_enable==1		&&	g_iL4D_GameMode==0
		|| g_iSoH_enable_sur==1		&&	g_iL4D_GameMode==1
		|| g_iSoH_enable_vs==1		&&	g_iL4D_GameMode==2))
		st_perk="极速上弹";
	else if (g_iSur1[iCid]==4
		&& (g_iPyro_enable==1		&&	g_iL4D_GameMode==0
		|| g_iPyro_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iPyro_enable_vs==1		&&	g_iL4D_GameMode==2))
		st_perk="炸弹专家";
	else if (g_iSur1[iCid]==5
		&& g_iL4D_12 == 2
		&& (g_iMA_enable==1		&&	g_iL4D_GameMode==0
		|| g_iMA_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iMA_enable_vs==1	&&	g_iL4D_GameMode==2))
		st_perk="中华武术家";
	else
		st_perk="未设定";

	Format(st_display,64,"幸存者 - 主菜单 (%s)",st_perk);
	if (g_iSur1_enable==1)
		DrawPanelItem(menu,st_display);
	else
		DrawPanelItem(menu,"关闭", ITEMDRAW_NOTEXT);


	//set name for sur2 perk
	if (g_iSur2[iCid]==1
		&& (g_iUnbreak_enable==1		&&	g_iL4D_GameMode==0
		|| g_iUnbreak_enable_sur==1		&&	g_iL4D_GameMode==1
		|| g_iUnbreak_enable_vs==1		&&	g_iL4D_GameMode==2))
		st_perk="血量上升";
	else if (g_iSur2[iCid]==2
		&& (g_iSpirit_enable==1		&&	g_iL4D_GameMode==0
		|| g_iSpirit_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iSpirit_enable_vs==1	&&	g_iL4D_GameMode==2))
		st_perk="精神医师";
	else if (g_iSur2[iCid]==3
		&& (g_iHelpHand_enable==1		&&	g_iL4D_GameMode==0
		|| g_iHelpHand_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iHelpHand_enable_vs==1		&&	g_iL4D_GameMode==2))
		st_perk="急救医师";
	else
		st_perk="未设定";

	Format(st_display,64,"幸存者 - 副菜单 (%s)", st_perk);
	if (g_iSur2_enable==1)
		DrawPanelItem(menu,st_display);
	else
		DrawPanelItem(menu,"关闭", ITEMDRAW_NOTEXT);

	//set name for sur3 perk
	if (g_iSur3[iCid]==1
		&& (g_iPack_enable==1		&&	g_iL4D_GameMode==0
		|| g_iPack_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iPack_enable_vs==1		&&	g_iL4D_GameMode==2))
		st_perk="弹药专家";
	else if (g_iSur3[iCid]==2
		&& (g_iChem_enable==1		&&	g_iL4D_GameMode==0
		|| g_iChem_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iChem_enable_vs==1		&&	g_iL4D_GameMode==2))
		st_perk="药丸专家";
	else if (g_iSur3[iCid]==3
		&& (g_iHard_enable==1		&&	g_iL4D_GameMode==0
		|| g_iHard_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iHard_enable_vs==1		&&	g_iL4D_GameMode==2))
		st_perk="终极守护";
	else if (g_iSur3[iCid]==4
		&& (g_iExtreme_enable==1		&&	g_iL4D_GameMode==0
		|| g_iExtreme_enable_sur==1		&&	g_iL4D_GameMode==1
		|| g_iExtreme_enable_vs==1		&&	g_iL4D_GameMode==2))
		st_perk="凌波微步";
	else if (g_iSur3[iCid]==5
		&& (g_iLittle_enable==1			&&	g_iL4D_GameMode==0
		|| g_iLittle_enable_sur==1		&&	g_iL4D_GameMode==1
		|| g_iLittle_enable_vs==1		&&	g_iL4D_GameMode==2))
		st_perk="机枪手";
	else
		st_perk="未设置";

	Format(st_display,64,"幸存者 - 辅助菜单 (%s)", st_perk);
	if (g_iSur3_enable==1)
		DrawPanelItem(menu,st_display);
	else
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);

	DrawPanelItem(menu,st_display, ITEMDRAW_NOTEXT);
	DrawPanelItem(menu,st_display, ITEMDRAW_NOTEXT);
	DrawPanelItem(menu,st_display, ITEMDRAW_NOTEXT);
	DrawPanelItem(menu,st_display, ITEMDRAW_NOTEXT);
	Format(st_display, 64, "%t", "DoneNagPanel1");	
	DrawPanelText(menu, st_display);
	Format(st_display, 64, "%t", "DoneNagPanel2");	
	DrawPanelText(menu, st_display);
	Format(st_display, 64, "%t", "DoneNagPanel3");	
	DrawPanelItem(menu, st_display);
	return menu;
}

//choose a submenu from top perk menu
public Menu_ChooseSubMenu (Handle:topmenu, MenuAction:action, param1, param2)
{
	if (topmenu!=INVALID_HANDLE) CloseHandle(topmenu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			case 1:
				SendPanelToClient(Menu_Sur1Perk(param1),param1,Menu_ChooseSur1Perk,MENU_TIME_FOREVER);
			case 2:
				SendPanelToClient(Menu_Sur2Perk(param1),param1,Menu_ChooseSur2Perk,MENU_TIME_FOREVER);
			case 3:
				SendPanelToClient(Menu_Sur3Perk(param1),param1,Menu_ChooseSur3Perk,MENU_TIME_FOREVER);
			case 8:
				SendPanelToClient(Menu_Confirm(param1),param1,Menu_ChooseConfirm,MENU_TIME_FOREVER);
			default:
				{
					if (IsClientInGame(param1)==true)
						SendPanelToClient(Menu_Top(param1),param1,Menu_ChooseSubMenu,MENU_TIME_FOREVER);
				}
		}
	}

	else
	{
		if (IsClientInGame(param1)==true)
			SendPanelToClient(Menu_Top(param1),param1,Menu_ChooseSubMenu,MENU_TIME_FOREVER);
	}
}


//build top menu,infected
public Handle:Menu_Top_Inf (iCid)
{
	new Handle:menu = CreatePanel();
	SetPanelTitle(menu, "技能系统 - 主菜单");
	DrawPanelText(menu,"每个菜单可选一个技能");
	decl String:st_perk[32];
	decl String:st_display[MAXPLAYERS+1];
	decl iPerk;

	//set name for inf1 perk
	iPerk = g_iInf1[iCid];
	if (iPerk==1
		&& g_iBarf_enable==1)
		st_perk="超级呕吐";
	else if (iPerk==2
		&& g_iBlind_enable==1)
		st_perk="黑暗来袭";
	else if (iPerk==3
		&& g_iDead_enable==1)
		st_perk="呕吐攻击";
	else if (iPerk==4
		&& g_iMotion_enable==1)
		st_perk="移动呕吐";
	else
		st_perk="未设置";

	Format(st_display,64,"Boomer (%s)", st_perk);
	if (g_iInf1_enable==1)
		DrawPanelItem(menu,st_display);
	else
		DrawPanelItem(menu,st_display, ITEMDRAW_NOTEXT);

	//set name for inf3 perk
	iPerk = g_iInf3[iCid];
	if (iPerk==1
		&& g_iTongue_enable==1)
		st_perk="超级舌头";
	else if (iPerk==2
		&& g_iSqueezer_enable==1)
		st_perk="致命舌头";
	else if (iPerk==3
		&& g_iDrag_enable==1)
		st_perk="舌头中断";
	else if (iPerk==4
		&& g_iSmokeIt_enable==1)
		st_perk="拉人行走";
	else
		st_perk="未设置";

	Format(st_display,64,"Smoker (%s)", st_perk);
	if (g_iInf3_enable==1)
		DrawPanelItem(menu,st_display);
	else
		DrawPanelItem(menu,st_display, ITEMDRAW_NOTEXT);

	//set name for inf4 perk
	iPerk = g_iInf4[iCid];
	if (iPerk==1
		&& g_iBody_enable==1)
		st_perk="瞬间压制";
	else if (iPerk==2
		&& g_iEfficient_enable==1)
		st_perk="超级杀手";
	else if (iPerk==3
		&& g_iGrass_enable==1)
		st_perk="超远袭击";
	else if (iPerk==4
		&& g_iSpeedDemon_enable==1)
		st_perk="终极杀手";
	else
		st_perk="未设置";

	Format(st_display,64,"Hunter (%s)", st_perk);
	if (g_iInf4_enable==1)
		DrawPanelItem(menu,st_display);
	else
		DrawPanelItem(menu,st_display, ITEMDRAW_NOTEXT);

	//set name for inf5 perk
	iPerk = g_iInf5[iCid];
	if (iPerk==1
		&& g_iWind_enable==1)
		st_perk="风行者";
	else if (iPerk==2
		&& g_iCavalier_enable==1)
		st_perk="骑士";
	else if (iPerk == 3
		&& g_iFrogger_enable == 1)
		st_perk = "终极骑士";
	else if (iPerk == 4
		&& g_iGhost_enable == 1)
		st_perk = "恶灵骑士";
	else
		st_perk="未设置";

	Format(st_display,64,"Jockey (%s)", st_perk);
	if (g_iInf5_enable==1
		&& g_iL4D_12 == 2)
		DrawPanelItem(menu,st_display);
	else
		DrawPanelItem(menu,st_display, ITEMDRAW_NOTEXT);

	//set name for inf6 perk
	iPerk = g_iInf6[iCid];
	if (iPerk==1
		&& g_iTwinSF_enable==1)
		st_perk="双重喷射";
	else if (iPerk==2
		&& g_iMegaAd_enable==1)
		st_perk="粘皮带骨";
	else
		st_perk="未设置";

	Format(st_display,64,"Spitter (%s)", st_perk);
	if (g_iInf6_enable==1
		&& g_iL4D_12 == 2)
		DrawPanelItem(menu,st_display);
	else
		DrawPanelItem(menu,st_display, ITEMDRAW_NOTEXT);

	//set name for inf7 perk
	iPerk = g_iInf7[iCid];
	if (iPerk==1
		&& g_iScatter_enable==1)
		st_perk="愤怒的公牛";
	else if (iPerk == 2
		&& g_iBullet_enable == 1)
		st_perk = "超速冲撞";
	else
		st_perk="未设置";

	Format(st_display,64,"Charger (%s)", st_perk);
	if (g_iInf7_enable==1
		&& g_iL4D_12 == 2)
		DrawPanelItem(menu,st_display);
	else
		DrawPanelItem(menu,st_display, ITEMDRAW_NOTEXT);

	//set name for inf2 perk
	if (g_iInf2[iCid]==1
		&& g_iAdrenal_enable==1)
		st_perk="坦克狂化";
	else if (g_iInf2[iCid]==2
		&& g_iJuggernaut_enable==1)
		st_perk="世界主宰";
	else if (g_iInf2[iCid]==3
		&& g_iMetabolic_enable==1)
		st_perk="代谢增强";
	else if (g_iInf2[iCid]==4
		&& g_iStorm_enable==1)
		st_perk="召唤小弟";
	else if (g_iInf2[iCid]==5
		&& g_iDouble_enable==1)
		st_perk="心动呼唤";
	else
		st_perk="未设置";

	Format(st_display,64,"Tank (%s)", st_perk);
	if (g_iInf2_enable==1)
		DrawPanelItem(menu,st_display);
	else
		DrawPanelItem(menu,st_display, ITEMDRAW_NOTEXT);

	DrawPanelText(menu,"为了自己更好的生存");
	DrawPanelText(menu,"请认真选择技能");
	DrawPanelItem(menu,"确定");
	return menu;
}

//choose a submenu from top perk menu, infected
public Menu_ChooseSubMenu_Inf (Handle:topmenu, MenuAction:action, param1, param2)
{
	if (topmenu!=INVALID_HANDLE) CloseHandle(topmenu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			case 1:
				SendPanelToClient(Menu_Inf1Perk(param1),param1,Menu_ChooseInf1Perk,MENU_TIME_FOREVER);
			case 2:
				SendPanelToClient(Menu_Inf3Perk(param1),param1,Menu_ChooseInf3Perk,MENU_TIME_FOREVER);
			case 3:
				SendPanelToClient(Menu_Inf4Perk(param1),param1,Menu_ChooseInf4Perk,MENU_TIME_FOREVER);
			case 4:
				SendPanelToClient(Menu_Inf5Perk(param1),param1,Menu_ChooseInf5Perk,MENU_TIME_FOREVER);
			case 5:
				SendPanelToClient(Menu_Inf6Perk(param1),param1,Menu_ChooseInf6Perk,MENU_TIME_FOREVER);
			case 6:
				SendPanelToClient(Menu_Inf7Perk(param1),param1,Menu_ChooseInf7Perk,MENU_TIME_FOREVER);
			case 7:
				SendPanelToClient(Menu_Inf2Perk(param1),param1,Menu_ChooseInf2Perk,MENU_TIME_FOREVER);
			case 8:
				SendPanelToClient(Menu_Confirm(param1),param1,Menu_ChooseConfirm_Inf,MENU_TIME_FOREVER);
			default:
				{
					if (IsClientInGame(param1)==true)
						SendPanelToClient(Menu_Top_Inf(param1),param1,Menu_ChooseSubMenu_Inf,MENU_TIME_FOREVER);
				}
		}
	}

	else
	{
		if (IsClientInGame(param1)==true)
			SendPanelToClient(Menu_Top_Inf(param1),param1,Menu_ChooseSubMenu_Inf,MENU_TIME_FOREVER);
	}
}

//menu for confirming perk choices
public Handle:Menu_Confirm (iCid)
{
	new Handle:menu = CreatePanel();
	decl String:panel[128];
	Format(panel, 128, "%t", "ConfirmNagPanel1");	
	SetPanelTitle(menu, panel);
	
	DrawPanelText(menu,"");
	
	Format(panel, 128, "%t", "ConfirmNagPanel2");
	DrawPanelText(menu,panel);
	Format(panel, 128, "%t", "ConfirmNagPanel3");
	DrawPanelText(menu,panel);
	Format(panel, 128, "%t", "ConfirmNagPanel4");
	DrawPanelItem(menu,panel);
	Format(panel, 128, "%t", "ConfirmNagPanel5");
	DrawPanelText(menu,panel);
	Format(panel, 128, "%t", "ConfirmNagPanel6");
	DrawPanelText(menu,panel);
	Format(panel, 128, "%t", "ConfirmNagPanel7");
	DrawPanelText(menu,panel);
	Format(panel, 128, "%t", "ConfirmNagPanel8");
	DrawPanelItem(menu,panel);
	return menu;
}

//confirm
public Menu_ChooseConfirm (Handle:topmenu, MenuAction:action, param1, param2)
{
	if (topmenu!=INVALID_HANDLE) CloseHandle(topmenu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			case 1:
			{
				g_iConfirm[param1]=1;
				PrintToChat(param1,"\x03[心动] %t", "ConfirmedMessage");
				Event_Confirm_Unbreakable(param1);
				Event_Confirm_Grenadier(param1);
				Event_Confirm_ChemReliant(param1);
				Event_Confirm_DT(param1);
				Event_Confirm_MA(param1);
				Extreme_Rebuild();
				Event_Confirm_LittleLeaguer(param1);
			}
			case 2:
				SendPanelToClient(Menu_Top(param1),param1,Menu_ChooseSubMenu,MENU_TIME_FOREVER);
			default:
			{
				if (IsClientInGame(param1)==true)
					SendPanelToClient(Menu_Top(param1),param1,Menu_ChooseSubMenu,MENU_TIME_FOREVER);
			}
		}
	}

	else
		SendPanelToClient(Menu_Top(param1),param1,Menu_ChooseSubMenu,MENU_TIME_FOREVER);
}

public Menu_ChooseConfirm_Inf (Handle:topmenu, MenuAction:action, param1, param2)
{
	if (topmenu!=INVALID_HANDLE) CloseHandle(topmenu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			case 1:
			{
				g_iConfirm[param1]=1;
				PrintToChat(param1,"\x03[心动] %t", "ConfirmedMessage");
			}
			case 2:
				SendPanelToClient(Menu_Top_Inf(param1),param1,Menu_ChooseSubMenu_Inf,MENU_TIME_FOREVER);
			default:
			{
				if (IsClientInGame(param1)==true)
					SendPanelToClient(Menu_Top_Inf(param1),param1,Menu_ChooseSubMenu_Inf,MENU_TIME_FOREVER);
			}
		}
	}

	else
		SendPanelToClient(Menu_Top_Inf(param1),param1,Menu_ChooseSubMenu_Inf,MENU_TIME_FOREVER);
}

//do nothing
//for displaying perk choices after confirming
public Menu_DoNothing (Handle:topmenu, MenuAction:action, param1, param2)
{}

//shows perk choices
public Handle:Menu_ShowChoices (iCid)
{
	new Handle:menu=CreatePanel();
	SetPanelTitle(menu,"技能系统");
	decl String:st_perk[128];
	decl iPerk;
	//"Your perks for this round:"
	Format(st_perk, 128, "%t:", "MapPerksPanel");

	//show sur1 perk
	iPerk = g_iSur1[iCid];
	if (iPerk == 1
		&& (g_iStopping_enable==1		&&	g_iL4D_GameMode==0
		|| g_iStopping_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iStopping_enable_vs==1		&&	g_iL4D_GameMode==2))
		Format(st_perk,128,"强力射击 (+%i%% %t)", RoundToNearest(g_flStopping_dmgmult*100), "BonusDamageText" );
	else if (iPerk == 2
		&& (g_iDT_enable==1		&&	g_iL4D_GameMode==0
		|| g_iDT_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iDT_enable_vs==1	&&	g_iL4D_GameMode==2))
		Format(st_perk,128,"快速射击 (%t +%i%%)", "DoubleTapDescriptionPanel", RoundToNearest(100 * ((1/g_flDT_rate)-1) ) ) ;
	else if (iPerk == 3
		&& (g_iSoH_enable==1		&&	g_iL4D_GameMode==0
		|| g_iSoH_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iSoH_enable_vs==1	&&	g_iL4D_GameMode==2))
		Format(st_perk,128,"极速上弹 (%t +%i%%)", "SleighOfHandDescriptionPanel", RoundToNearest(100 * ((1/g_flSoH_rate)-1) ) ) ;
	else if (iPerk == 4
		&& (g_iPyro_enable==1		&&	g_iL4D_GameMode==0
		|| g_iPyro_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iPyro_enable_vs==1		&&	g_iL4D_GameMode==2))
		Format(st_perk,128,"炸弹专家 (%t)", "PyroDescriptionPanel");
	else if (iPerk == 5
		&& (g_iMA_enable==1		&&	g_iL4D_GameMode==0
		|| g_iMA_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iMA_enable_vs==1	&&	g_iL4D_GameMode==2))
		Format(st_perk,128,"中华武术家 (%t)", "MartialArtistDescriptionPanel");
	else
		Format(st_perk,128,"%t", "未设置");

	if (g_iSur1_enable==1)
	{
		DrawPanelItem(menu,"幸存者, 主菜单:");
		DrawPanelText(menu,st_perk);
	}

	//show sur2 perk
	iPerk = g_iSur2[iCid];
	if (iPerk == 1
		&& (g_iUnbreak_enable==1	&&	g_iL4D_GameMode==0
		|| g_iUnbreak_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iUnbreak_enable_vs==1	&&	g_iL4D_GameMode==2))
		Format(st_perk,128,"血量上升 (+%i %t)", g_iUnbreak_hp, "UnbreakableHint");
	else if (iPerk == 2
		&& (g_iSpirit_enable==1		&&	g_iL4D_GameMode==0
		|| g_iSpirit_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iSpirit_enable_vs==1	&&	g_iL4D_GameMode==2))
	{
		decl iTime;
		if (g_iL4D_GameMode==2)
			iTime=g_iSpirit_cd_vs;
		else if (g_iL4D_GameMode==1)
			iTime=g_iSpirit_cd_sur;
		else
			iTime=g_iSpirit_cd;
		Format(st_perk,128,"精神医师 (%t: %i 秒)", "SpiritDescriptionPanel", iTime/60 );
	}
	else if (iPerk == 3
		&& (g_iHelpHand_enable==1		&&	g_iL4D_GameMode==0
		|| g_iHelpHand_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iHelpHand_enable_vs==1		&&	g_iL4D_GameMode==2))
	{
		decl iBuff;
		if (g_iL4D_GameMode==2)
			iBuff=g_iHelpHand_buff_vs;
		else
			iBuff=g_iHelpHand_buff;
		if (g_iHelpHand_convar==1)
			Format(st_perk,128,"急救医师 (%t +%i)", "HelpingHandDescriptionPanel2", iBuff);
		else
			Format(st_perk,128,"急救医师 (%t +%i)", "HelpingHandDescriptionPanel", iBuff);
	}
	else
		Format(st_perk,128,"%t", "NotSet");

	if (g_iSur2_enable==1)
	{
		DrawPanelItem(menu,"幸存者, 副菜单:");
		DrawPanelText(menu,st_perk);
	}

	//show sur3 perk
	iPerk = g_iSur3[iCid];
	if (iPerk == 1
		&& (g_iPack_enable==1		&&	g_iL4D_GameMode==0
		|| g_iPack_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iPack_enable_vs==1		&&	g_iL4D_GameMode==2))
		Format(st_perk,128,"弹药专家 (%t +%i%%)", "PackRatDescriptionPanel", RoundToNearest(g_flPack_ammomult*100) );
	else if (iPerk == 2
		&& (g_iChem_enable==1		&&	g_iL4D_GameMode==0
		|| g_iChem_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iChem_enable_vs==1		&&	g_iL4D_GameMode==2))
		Format(st_perk,128,"药丸专家 (%t +%i)", "ChemReliantDescriptionPanel", g_iChem_buff);
	else if (iPerk == 3
		&& (g_iHard_enable==1			&&	g_iL4D_GameMode==0
		|| g_iHard_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iHard_enable_vs==1		&&	g_iL4D_GameMode==2))
		Format(st_perk,128,"终极守护 (+%i%% %t)", RoundToNearest(g_flHard_hpmult*100), "HardToKillDescriptionPanel" );
	else if (iPerk == 4
		&& (g_iExtreme_enable==1		&&	g_iL4D_GameMode==0
		|| g_iExtreme_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iExtreme_enable_vs==1	&&	g_iL4D_GameMode==2))
		Format(st_perk,128,"凌波微步 (+%i%% %t)", RoundToNearest(g_flExtreme_rate*100-100), "MartialArtistDescriptionPanelCoop" );
	else if (iPerk == 5
		&& (g_iLittle_enable==1		&&	g_iL4D_GameMode==0
		|| g_iLittle_enable_sur==1	&&	g_iL4D_GameMode==1
		|| g_iLittle_enable_vs==1	&&	g_iL4D_GameMode==2))
		Format(st_perk,128,"机枪手 (%t)", "LittleLeaguerDescriptionPanel" );
	else
		Format(st_perk,128,"%t", "NotSet");

	if (g_iSur2_enable==1)
	{
		DrawPanelItem(menu,"幸存者, 辅助菜单:");
		DrawPanelText(menu,st_perk);
	}

	return menu;
}



//shows perk choices, infected
public Handle:Menu_ShowChoices_Inf (iCid)
{
	new Handle:menu=CreatePanel();
	SetPanelTitle(menu,"技能系统: 已选择以下技能");
	decl String:st_perk[128];
	decl String:stDesc[128];
	decl iPerk;

	//show inf1 perk
	iPerk = g_iInf1[iCid];
	if (iPerk == 1
		&& g_iBarf_enable == 1)
	{
		st_perk="Boomer: 超级呕吐";
		Format(stDesc,128,"%t", "BarfBaggedDescriptionPanel");
	}
	else if (iPerk == 2
		&& g_iBlind_enable == 1)
	{
		st_perk="Boomer: 黑暗来袭";
		Format(stDesc,128,"%t", "AcidVomitDescriptionPanel");
	}
	else if (iPerk == 3
		&& g_iDead_enable == 1)
	{
		st_perk="Boomer: 呕吐攻击";
		Format(stDesc,128,"%t: +%i%%", "DeadWreckeningDescriptionPanel", RoundToNearest(100*g_flDead_dmgmult));
	}
	else if (iPerk == 4
		&& g_iMotion_enable == 1)
	{
		st_perk="Boomer: 移动呕吐";
		Format(stDesc,128,"%t", "MotionSicknessDescriptionPanel");
	}
	else
	{
		Format(st_perk,128,"Boomer: %t", "NotSet");
		stDesc = "";
	}

	if (g_iInf1_enable==1)
	{
		DrawPanelItem(menu,st_perk);
		DrawPanelText(menu,stDesc);
	}

	//show inf3 perk
	iPerk = g_iInf3[iCid];
	if (iPerk == 1
		&& g_iTongue_enable == 1)
	{
		st_perk="Smoker: 超级舌头";
		Format(stDesc,128,"%t", "TongueTwisterDescriptionPanel");
	}
	else if (iPerk == 2
		&& g_iSqueezer_enable == 1)
	{
		st_perk="Smoker: 致命舌头";
		Format(stDesc,128,"+%i%% %t", RoundToNearest(g_flSqueezer_dmgmult*100), "BonusDamageText" );
	}
	else if (iPerk == 3
		&& g_iDrag_enable == 1)
	{
		st_perk="Smoker: 舌头中断";
		Format(stDesc,128,"%t", "DragAndDropDescriptionPanel");
	}
	else if (iPerk == 4
		&& g_iSmokeIt_enable == 1)
	{
		st_perk="Smoker: 拉人行走";
		Format(stDesc,128,"%t", "SmokeItDescriptionPanel");
	}
	else
	{
		Format(st_perk,128,"Smoker: %t", "NotSet");
		stDesc = "";
	}

	if (g_iInf3_enable==1)
	{
		DrawPanelItem(menu,st_perk);
		DrawPanelText(menu,stDesc);
	}

	//show inf4 perk
	iPerk = g_iInf4[iCid];
	if (iPerk == 1
		&& g_iBody_enable == 1)
	{
		st_perk="Hunter: 瞬间压制";
		Format(stDesc,128,"%i %t", g_iBody_minbound, "BodySlamDescriptionPanel");
	}
	else if (iPerk == 2
		&& g_iEfficient_enable == 1)
	{
		st_perk="Hunter: 超级杀手";
		Format(stDesc,128,"+%i%% %t", RoundToNearest(g_flEfficient_dmgmult*100), "BonusDamageText" );
	}
	else if (iPerk == 3
		&& g_iGrass_enable == 1)
	{
		st_perk="Hunter: 超远袭击";
		Format(stDesc,128,"%t: +%i%%", "GrasshopperDescriptionPanel", RoundToNearest( (g_flGrass_rate - 1) * 100 ) );
	}
	else if (iPerk == 4
		&& g_iSpeedDemon_enable == 1)
	{
		st_perk="Hunter: 终极杀手";
		Format(stDesc,128,"+%i%% %t +%i%% %t", RoundToNearest(g_flSpeedDemon_dmgmult*100), "OldSchoolDescriptionPanel", RoundToNearest( (g_flSpeedDemon_rate - 1) * 100 ), "SpeedDemonDescriptionPanel" );
	}
	else
	{
		Format(st_perk,128,"Hunter: %t", "NotSet");
		stDesc = "";
	}
	if (g_iInf4_enable==1)
	{
		DrawPanelItem(menu,st_perk);
		DrawPanelText(menu,stDesc);
	}

	//show inf5 perk
	iPerk = g_iInf5[iCid];
	if (iPerk == 1
		&& g_iWind_enable == 1)
	{
		st_perk="Jockey: 风行者";
		Format(stDesc,128,"%t: +%i%%", "RideLikeTheWindDescriptionPanel", RoundToNearest( (g_flWind_rate - 1) * 100 ) );
	}
	else if (iPerk == 2
		&& g_iCavalier_enable == 1)
	{
		st_perk = "Jockey: 骑士";
		Format(stDesc,128,"+%i%% %t", RoundToNearest( g_flCavalier_hpmult * 100 ), "UnbreakableHint" );
	}
	else if (iPerk == 3
		&& g_iFrogger_enable == 1)
	{
		st_perk = "Jockey: 终极骑士";
		Format(stDesc, 128, "+%i%% %t +%i%% %t", RoundToNearest( (g_flFrogger_rate - 1) * 100 ), "FroggerDescriptionPanel", RoundToNearest(g_flFrogger_dmgmult*100), "BonusDamageText" );
	}
	else if (iPerk == 4
		&& g_iGhost_enable == 1)
	{
		st_perk = "Jockey: 恶灵骑士";
		Format(stDesc, 128, "%i%% %t", RoundToNearest( (1 - (g_iGhost_alpha/255.0)) *100 ), "GhostRiderDescriptionPanel" );
	}
	else
	{
		Format(st_perk,128,"Jockey: %t", "NotSet");
		stDesc = "";
	}

	if (g_iInf5_enable==1
		&& g_iL4D_12 == 2)
	{
		DrawPanelItem(menu,st_perk);
		DrawPanelText(menu,stDesc);
	}

	//show inf6 perk
	iPerk = g_iInf6[iCid];
	if (iPerk == 1
		&& g_iTwinSF_enable == 1)
	{
		st_perk="Spitter: 双重喷射";
		Format(stDesc, 128, "%t", "TwinSpitfireDescriptionPanel" );
	}
	if (iPerk == 2
		&& g_iMegaAd_enable == 1)
	{
		st_perk="Spitter: 粘皮带骨";
		Format(stDesc, 128, "%t", "MegaAdhesiveDescriptionPanel" );
	}
	else
	{
		Format(st_perk,128,"Spitter: %t", "NotSet");
		stDesc="";
	}

	if (g_iInf6_enable==1
		&& g_iL4D_12 == 2)
	{
		DrawPanelItem(menu,st_perk);
		DrawPanelText(menu,stDesc);
	}

	//show inf7 perk
	iPerk = g_iInf7[iCid];
	if (iPerk == 1
		&& g_iScatter_enable == 1)
	{
		st_perk="Charger: 愤怒的公牛";
		Format(stDesc, 128, "%t", "ScatteringRamDescriptionPanel" );
	}
	else if (iPerk == 2
		&& g_iBullet_enable == 1)
	{
		st_perk = "Charger: 超速冲撞";
		Format(stDesc, 128, "%t: +%i%%", "SpeedingBulletDescriptionPanel", RoundToNearest(g_flBullet_rate*100 - 100) );
	}
	else
	{
		Format(st_perk,128,"Charger: %t", "NotSet");
		stDesc="";
	}
	if (g_iInf7_enable==1
		&& g_iL4D_12 == 2)
	{
		DrawPanelItem(menu,st_perk);
		DrawPanelText(menu,stDesc);
	}
	
	//show inf2 perk
	iPerk = g_iInf2[iCid];
	if (iPerk == 1
		&& g_iAdrenal_enable == 1)
	{
		st_perk="Tank: 坦克狂化";
		Format(stDesc,128,"%t", "AdrenalGlandsDescriptionPanelShort");
	}
	else if (iPerk == 2
		&& g_iJuggernaut_enable == 1)
	{
		st_perk="Tank: 世界主宰";
		Format(stDesc,128,"+%i %t", g_iJuggernaut_hp, "UnbreakableHint");
	}
	else if (iPerk == 3
		&& g_iMetabolic_enable == 1)
	{
		st_perk="Tank: 代谢增强";
		Format(stDesc,128,"+%i%% %t", RoundToNearest((g_flMetabolic_speedmult-1)*100), "SpeedDemonDescriptionPanel");
	}
	else if (iPerk == 4
		&& g_iStorm_enable == 1)
	{
		st_perk="Tank: 召唤小弟";
		Format(stDesc,128,"%t", "StormCallerDescriptionPanel");
	}
	else if (iPerk == 5
		&& g_iDouble_enable == 1)
	{
		st_perk="Tank: 心动呼唤";
		Format(stDesc,128,"%t", "DoubleTroubleDescriptionPanel");
	}
	else
	{
		Format(st_perk,128,"Tank: %t", "NotSet");
		stDesc = "";
	}

	if (g_iInf2_enable)
	{
		DrawPanelItem(menu,st_perk);
		DrawPanelText(menu,stDesc);
	}

	return menu;
}



//=============================
//	SUR1 PERK CHOICE
//=============================

//build menu for Sur1 Perks
public Handle:Menu_Sur1Perk (client)
{
	new Handle:menu = CreatePanel();
	SetPanelTitle(menu, "技能系统 - 幸存者: 主菜单");
	decl String:st_display[MAXPLAYERS+1];
	decl String:st_current[10];

	//set name for perk 1
	if (g_iStopping_enable==0			&&	g_iL4D_GameMode==0
		|| g_iStopping_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iStopping_enable_vs==0		&&	g_iL4D_GameMode==2)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iSur1[client])
		{
			case 1: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"强力射击 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"+%i%% %t", RoundToNearest(g_flStopping_dmgmult*100), "BonusDamageText" );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 2
	if (g_iDT_enable==0			&&	g_iL4D_GameMode==0
		|| g_iDT_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iDT_enable_vs==0	&&	g_iL4D_GameMode==2)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iSur1[client])
		{
			case 2: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"快速射击 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t +%i%%", "DoubleTapDescriptionPanel", RoundToNearest(100 * ((1/g_flDT_rate)-1) ) );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 3
	if (g_iSoH_enable==0			&&	g_iL4D_GameMode==0
		|| g_iSoH_enable_sur==0		&&	g_iL4D_GameMode==1
		|| g_iSoH_enable_vs==0		&&	g_iL4D_GameMode==2)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iSur1[client])
		{
			case 3: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"极速上弹 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t +%i%%", "SleighOfHandDescriptionPanel", RoundToNearest(100 * ((1/g_flSoH_rate)-1) ) );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 4
	if (g_iPyro_enable==0			&&	g_iL4D_GameMode==0
		|| g_iPyro_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iPyro_enable_vs==0		&&	g_iL4D_GameMode==2)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iSur1[client])
		{
			case 4: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"炸弹专家 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t", "PyroDescriptionText1");
		DrawPanelText(menu, st_display);
		Format(st_display,64,"%t", "PyroDescriptionText2");
		DrawPanelText(menu, st_display);
	}

	//set name for perk 5
	if (g_iMA_enable==0			&&	g_iL4D_GameMode==0
		|| g_iMA_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iMA_enable_vs==0	&&	g_iL4D_GameMode==2
		|| g_iL4D_12 != 2)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iSur1[client])
		{
			case 5: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"中华武术家 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t", "MartialArtistDescriptionPanel1");
		DrawPanelText(menu, st_display);
		Format(st_display,64,"%t", "MartialArtistDescriptionPanel2");
		DrawPanelText(menu, st_display);
	}

	return menu;
}

//setting Sur1 perk and returning to top menu
public Menu_ChooseSur1Perk (Handle:menu, MenuAction:action, param1, param2)
{
	if (menu!=INVALID_HANDLE) CloseHandle(menu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			//stopping power
			case 1:
				g_iSur1[param1]=1;
			//double tap
			case 2:
				g_iSur1[param1]=2;
			//sleight of hand
			case 3:
				g_iSur1[param1]=3;
			//pyrotechnician
			case 4:
				g_iSur1[param1]=4;
			//martial artist
			case 5:
				g_iSur1[param1]=5;
		}
	}

	if (IsClientInGame(param1)==true)
		SendPanelToClient(Menu_Top(param1),param1,Menu_ChooseSubMenu,MENU_TIME_FOREVER);
}



//=============================
//	SUR2 CHOICE
//=============================

//build menu for Sur2 Perks
public Handle:Menu_Sur2Perk (client)
{
	new Handle:menu = CreatePanel();
	SetPanelTitle(menu, "技能系统 - 幸存者: 副菜单");
	decl String:st_display[MAXPLAYERS+1];
	decl String:st_current[10];

	//set name for perk 1
	if (g_iUnbreak_enable==0			&&	g_iL4D_GameMode==0
		|| g_iUnbreak_enable_sur==0		&&	g_iL4D_GameMode==1
		|| g_iUnbreak_enable_vs==0		&&	g_iL4D_GameMode==2)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iSur2[client])
		{
			case 1: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"血量上升 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"+%i %t", g_iUnbreak_hp, "UnbreakableHint" );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 2
	if (g_iSpirit_enable==0			&&	g_iL4D_GameMode==0
		|| g_iSpirit_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iSpirit_enable_vs==0	&&	g_iL4D_GameMode==2)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iSur2[client])
		{
			case 2: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"精神医师 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t", "SpiritDescriptionText" );
		DrawPanelText(menu,st_display);
		decl iTime;
		if (g_iL4D_GameMode==2)
			iTime=g_iSpirit_cd_vs;
		else if (g_iL4D_GameMode==1)
			iTime=g_iSpirit_cd_sur;
		else
			iTime=g_iSpirit_cd;
		Format(st_display,64,"+%i %t: %i 秒", g_iSpirit_buff, "SpritDescriptionText2", iTime/60 );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 3
	if (g_iHelpHand_enable==0			&&	g_iL4D_GameMode==0
		|| g_iHelpHand_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iHelpHand_enable_vs==0		&&	g_iL4D_GameMode==2)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iSur2[client])
		{
			case 3: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"急救医师 %s",st_current);
		DrawPanelItem(menu,st_display);

		decl iBuff;
		if (g_iL4D_GameMode==2)
			iBuff=g_iHelpHand_buff_vs;
		else
			iBuff=g_iHelpHand_buff;

		if (g_iHelpHand_convar==1)
		{
			Format(st_display,64,"%t +%i", "HelpingHandDescriptionPanel2", iBuff);
			DrawPanelText(menu,st_display);
		}
		else
		{
			Format(st_display,64,"%t +%i", "HelpingHandDescriptionPanel", iBuff);
			DrawPanelText(menu,st_display);
		}
	}

	return menu;
}

//setting Sur2 perk and returning to top menu
public Menu_ChooseSur2Perk (Handle:menu, MenuAction:action, param1, param2)
{
	if (menu!=INVALID_HANDLE) CloseHandle(menu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			//unbreakable
			case 1:
				g_iSur2[param1]=1;
			//spirit
			case 2:
				g_iSur2[param1]=2;
			//helping hand
			case 3:
				g_iSur2[param1]=3;
		}
	}

	if (IsClientInGame(param1)==true)
		SendPanelToClient(Menu_Top(param1),param1,Menu_ChooseSubMenu,MENU_TIME_FOREVER);
}



//=============================
//	SUR3 CHOICE
//=============================

//build menu for Sur3 Perks
public Handle:Menu_Sur3Perk (client)
{
	new Handle:menu = CreatePanel();
	SetPanelTitle(menu, "技能系统 - 幸存者: 副主菜单");
	decl String:st_display[MAXPLAYERS+1];
	decl String:st_current[10];

	//set name for perk 1
	if (g_iPack_enable==0			&&	g_iL4D_GameMode==0
		|| g_iPack_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iPack_enable_vs==0		&&	g_iL4D_GameMode==2)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iSur3[client])
		{
			case 1: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"弹药专家 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t +%i%%", "PackRatDescriptionPanel", RoundToNearest(g_flPack_ammomult*100) );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 2
	if (g_iChem_enable==0			&&	g_iL4D_GameMode==0
		|| g_iChem_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iChem_enable_vs==0		&&	g_iL4D_GameMode==2)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iSur3[client])
		{
			case 2: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"药丸专家 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t (+%i)", "ChemReliantDescriptionText", g_iChem_buff);
		DrawPanelText(menu,st_display);
		Format(st_display,64,"%t", "ChemReliantDescriptionText2");
		DrawPanelText(menu,st_display);
	}

	//set name for perk 3
	if (g_iHard_enable==0			&&	g_iL4D_GameMode==0
		|| g_iHard_enable_sur==0	&&	g_iL4D_GameMode==1
		|| g_iHard_enable_vs==0		&&	g_iL4D_GameMode==2)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iSur3[client])
		{
			case 3: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"终极守护 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t", "HardToKillDescriptionText");
		DrawPanelText(menu,st_display);
		Format(st_display,64,"+%i%% %t", RoundToNearest(100*g_flHard_hpmult), "HardToKillDescriptionText2" );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 4
	if (g_iExtreme_enable==0			&&	g_iL4D_GameMode==0
		|| g_iExtreme_enable_sur==0		&&	g_iL4D_GameMode==1
		|| g_iExtreme_enable_vs==0		&&	g_iL4D_GameMode==2)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iSur3[client])
		{
			case 4: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"凌波微步 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t: +%i%%", "MartialArtistDescriptionPanelCoop", RoundToNearest(100*g_flExtreme_rate-100) );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 5
	if (g_iLittle_enable==0				&&	g_iL4D_GameMode==0
		|| g_iLittle_enable_sur==0		&&	g_iL4D_GameMode==1
		|| g_iLittle_enable_vs==0		&&	g_iL4D_GameMode==2
		|| g_iL4D_12 != 2)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iSur3[client])
		{
			case 4: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"机枪手 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t", "LittleLeaguerDescriptionPanel" );
		DrawPanelText(menu,st_display);
	}

	return menu;
}

//setting Sur3 perk and returning to top menu
public Menu_ChooseSur3Perk (Handle:menu, MenuAction:action, param1, param2)
{
	if (menu!=INVALID_HANDLE) CloseHandle(menu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			//pack rat
			case 1:
				g_iSur3[param1]=1;
			//chem reliant
			case 2:
				g_iSur3[param1]=2;
			//hard to kill
			case 3:
				g_iSur3[param1]=3;
			//extreme cond
			case 4:
				g_iSur3[param1]=4;
			//little leaguer
			case 5:
				g_iSur3[param1]=5;
		}
	}

	if (IsClientInGame(param1)==true)
		SendPanelToClient(Menu_Top(param1),param1,Menu_ChooseSubMenu,MENU_TIME_FOREVER);
}



//=============================
//	INF1 CHOICE (BOOMER)
//=============================

//build menu for Inf1 Perks
public Handle:Menu_Inf1Perk (client)
{
	new Handle:menu = CreatePanel();
	SetPanelTitle(menu, "技能系统 - Boomer");
	decl String:st_display[128];
	decl String:st_current[10];

	//set name for perk 1
	if (g_iBarf_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf1[client])
		{
			case 1: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"超级呕吐 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,128,"%t", "BarfBaggedDescriptionPanel");
		DrawPanelText(menu,st_display);
	}

	//set name for perk 2
	if (g_iBlind_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf1[client])
		{
			case 2: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"黑暗来袭 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,128,"%t: %i%%", "AcidVomitDescriptionPanel", RoundToNearest(100 - g_flBlind_cdmult*100) );
		DrawPanelText(menu,st_display);
		DrawPanelText(menu,"(默认是15秒)");
	}

	//set name for perk 3
	if (g_iDead_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf1[client])
		{
			case 3: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"呕吐攻击 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,128,"%t: +%i%%", "DeadWreckeningDescriptionPanel", RoundToNearest(100*g_flDead_dmgmult));
		DrawPanelText(menu,st_display);
		DrawPanelText(menu,"吐在幸存者身上");
	}

	//set name for perk 4
	if (g_iMotion_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf1[client])
		{
			case 4: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"移动呕吐 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,128,"%t", "MotionSicknessDescriptionPanel");
		DrawPanelText(menu,st_display);
	}

	return menu;
}

//setting Inf1 perk and returning to top menu
public Menu_ChooseInf1Perk (Handle:menu, MenuAction:action, param1, param2)
{
	if (menu!=INVALID_HANDLE) CloseHandle(menu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			//barf bagged
			case 1:
				g_iInf1[param1]=1;
			//blind luck
			case 2:
				g_iInf1[param1]=2;
			//dead wreckening
			case 3:
				g_iInf1[param1]=3;
			//motion sickness
			case 4:
				g_iInf1[param1]=4;
		}
	}

	if (IsClientInGame(param1)==true)
		SendPanelToClient(Menu_Top_Inf(param1),param1,Menu_ChooseSubMenu_Inf,MENU_TIME_FOREVER);
}



//=============================
//	INF2 CHOICE (TANK)
//=============================

//build menu for Inf2 Perks
public Handle:Menu_Inf2Perk (client)
{
	new Handle:menu = CreatePanel();
	SetPanelTitle(menu, "技能系统 - Tank");
	decl String:st_display[MAXPLAYERS+1];
	decl String:st_current[10];

	//set name for perk 1
	if (g_iAdrenal_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf2[client])
		{
			case 1: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"坦克狂化 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t: +%i%%", "AdrenalGlandsDescriptionPanel1", RoundToNearest(100 * ((1/g_flAdrenal_punchcdmult)-1) ) );
		DrawPanelText(menu,st_display);
		Format(st_display,64,"%t: +%i%%", "AdrenalGlandsDescriptionPanel2", RoundToNearest(100 - 100*g_flAdrenal_throwcdmult ) );
		DrawPanelText(menu,st_display);
		Format(st_display,64,"%t", "AdrenalGlandsDescriptionPanel3" );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 2
	if (g_iJuggernaut_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf2[client])
		{
			case 2: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"世界主宰 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,128,"+%i %t", g_iJuggernaut_hp, "UnbreakableHint");
		DrawPanelText(menu,st_display);
	}

	//set name for perk 3
	if (g_iMetabolic_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf2[client])
		{
			case 3: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"代谢增强 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,128,"+%i%% %t", RoundToNearest((g_flMetabolic_speedmult-1)*100), "SpeedDemonDescriptionPanel");
		DrawPanelText(menu,st_display);
	}

	//set name for perk 4
	if (g_iStorm_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf2[client])
		{
			case 4: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"召唤小弟 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,128,"%t", "StormCallerDescriptionPanel");
		DrawPanelText(menu,st_display);
	}

	//set name for perk 5
	if (g_iDouble_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf2[client])
		{
			case 5: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"心动呼唤 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,128,"%t", "DoubleTroubleDescriptionPanel");
		DrawPanelText(menu,st_display);
		Format(st_display,128,"%t: -%i%%", "DoubleTroubleDescriptionPanel2", RoundToNearest(100 - g_flDouble_hpmult*100));
		DrawPanelText(menu,st_display);
	}

	return menu;
}

//setting Inf2 perk and returning to top menu
public Menu_ChooseInf2Perk (Handle:menu, MenuAction:action, param1, param2)
{
	if (menu!=INVALID_HANDLE) CloseHandle(menu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			//adrenal glands
			case 1:
				g_iInf2[param1]=1;
			//juggernaut
			case 2:
				g_iInf2[param1]=2;
			//metabolic boost
			case 3:
				g_iInf2[param1]=3;
			//storm caller
			case 4:
				g_iInf2[param1]=4;
			//double the trouble
			case 5:
				g_iInf2[param1]=5;
		}
	}

	if (IsClientInGame(param1)==true)
		SendPanelToClient(Menu_Top_Inf(param1),param1,Menu_ChooseSubMenu_Inf,MENU_TIME_FOREVER);
}



//=============================
//	INF3 CHOICE (SMOKER)
//=============================

//build menu for Inf3 Perks
public Handle:Menu_Inf3Perk (client)
{
	new Handle:menu = CreatePanel();
	SetPanelTitle(menu, "技能系统 - Smoker");
	decl String:st_display[MAXPLAYERS+1];
	decl String:st_current[10];

	//set name for perk 1
	if (g_iTongue_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf3[client])
		{
			case 1: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"超级舌头 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t: +%i%%", "TongueTwisterDescriptionPanel1", RoundToNearest(100*(g_flTongue_speedmult-1)) );
		DrawPanelText(menu,st_display);
		Format(st_display,64,"%t: +%i%%", "TongueTwisterDescriptionPanel2", RoundToNearest(100*(g_flTongue_rangemult-1)) );
		DrawPanelText(menu,st_display);
		Format(st_display,64,"%t: +%i%%", "TongueTwisterDescriptionPanel3", RoundToNearest(100*(g_flTongue_pullmult-1)) );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 2
	if (g_iSqueezer_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf3[client])
		{
			case 2: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"致命舌头 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t: +%i%%", "SqueezerDescriptionText", RoundToNearest(g_flSqueezer_dmgmult*100) );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 3
	if (g_iDrag_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf3[client])
		{
			case 3: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"舌头中断 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t", "DragAndDropDescriptionPanel" );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 4
	if (g_iSmokeIt_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf3[client])
		{
			case 3: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"拉人行走 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t", "SmokeItDescriptionPanel" );
		DrawPanelText(menu,st_display);
	}

	return menu;
}

//setting Inf3 perk and returning to top menu
public Menu_ChooseInf3Perk (Handle:menu, MenuAction:action, param1, param2)
{
	if (menu!=INVALID_HANDLE) CloseHandle(menu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			//tongue twister
			case 1:
				g_iInf3[param1]=1;
			//squeezer
			case 2:
				g_iInf3[param1]=2;
			//drag and drop
			case 3:
				g_iInf3[param1]=3;
			//smoke it!
			case 4:
				g_iInf3[param1]=4;
		}
	}

	if (IsClientInGame(param1)==true)
		SendPanelToClient(Menu_Top_Inf(param1),param1,Menu_ChooseSubMenu_Inf,MENU_TIME_FOREVER);
}



//=============================
//	INF4 CHOICE (HUNTER)
//=============================

//build menu for Inf4 Perks
public Handle:Menu_Inf4Perk (client)
{
	new Handle:menu = CreatePanel();
	SetPanelTitle(menu, "技能系统 - Hunter");
	decl String:st_display[MAXPLAYERS+1];
	decl String:st_current[10];

	//set name for perk 1
	if (g_iBody_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf4[client])
		{
			case 1: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"瞬间压制 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t %i", "BodySlamDescriptionPanel", g_iBody_minbound);
		DrawPanelText(menu,st_display);
	}

	//set name for perk 2
	if (g_iEfficient_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf4[client])
		{
			case 2: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"超级杀手 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"+%i%% %t", RoundToNearest(g_flEfficient_dmgmult*100), "BonusDamageText" );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 3
	if (g_iGrass_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf4[client])
		{
			case 3: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"超远袭击 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t: +%i%%", "GrasshopperDescriptionPanel", RoundToNearest( (g_flGrass_rate - 1) * 100 ) );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 4
	if (g_iSpeedDemon_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf4[client])
		{
			case 4: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"终极杀手 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"+%i%% %t +%i%% %t", RoundToNearest(g_flSpeedDemon_dmgmult*100), "OldSchoolDescriptionPanel", RoundToNearest( (g_flSpeedDemon_rate - 1) * 100 ), "SpeedDemonDescriptionPanel" );
		DrawPanelText(menu,st_display);
	}

	return menu;
}

//setting Inf4 perk and returning to top menu
public Menu_ChooseInf4Perk (Handle:menu, MenuAction:action, param1, param2)
{
	if (menu!=INVALID_HANDLE) CloseHandle(menu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			//body slam
			case 1:
				g_iInf4[param1]=1;
			//efficient killer
			case 2:
				g_iInf4[param1]=2;
			//grasshopper
			case 3:
				g_iInf4[param1]=3;
			//speed demon
			case 4:
				g_iInf4[param1]=4;
		}
	}

	if (IsClientInGame(param1)==true)
		SendPanelToClient(Menu_Top_Inf(param1),param1,Menu_ChooseSubMenu_Inf,MENU_TIME_FOREVER);
}



//=============================
//	INF5 CHOICE (JOCKEY)
//=============================

//build menu for Inf5 Perks
public Handle:Menu_Inf5Perk (client)
{
	new Handle:menu = CreatePanel();
	SetPanelTitle(menu, "技能系统 - Jockey");
	decl String:st_display[MAXPLAYERS+1];
	decl String:st_current[10];

	//set name for perk 1
	if (g_iWind_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf5[client])
		{
			case 1: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"风行者 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t: +%i%%", "RideLikeTheWindDescriptionPanel", RoundToNearest( (g_flWind_rate - 1) * 100 ) );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 2
	if (g_iCavalier_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf5[client])
		{
			case 2: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"骑士 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"+%i%% %t", RoundToNearest( g_flCavalier_hpmult * 100 ), "UnbreakableHint" );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 3
	if (g_iFrogger_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf5[client])
		{
			case 3: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"终极骑士 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"+%i%% %t +%i%% %t", RoundToNearest( (g_flFrogger_rate - 1) * 100 ), "FroggerDescriptionPanel", RoundToNearest(g_flFrogger_dmgmult*100), "BonusDamageText" );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 4
	if (g_iGhost_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf5[client])
		{
			case 4: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"恶灵骑士 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%i%% %t", RoundToNearest( (1 - (g_iGhost_alpha/255.0)) *100 ), "GhostRiderDescriptionPanel" );
		DrawPanelText(menu,st_display);
	}

	return menu;
}

//setting Inf5 perk and returning to top menu
public Menu_ChooseInf5Perk (Handle:menu, MenuAction:action, param1, param2)
{
	if (menu!=INVALID_HANDLE) CloseHandle(menu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			//ride like the wind
			case 1:
				g_iInf5[param1]=1;
			//cavalier
			case 2:
				g_iInf5[param1]=2;
			//frogger
			case 3:
				g_iInf5[param1]=3;
			//ghost
			case 4:
				g_iInf5[param1]=4;
		}
	}

	if (IsClientInGame(param1)==true)
		SendPanelToClient(Menu_Top_Inf(param1),param1,Menu_ChooseSubMenu_Inf,MENU_TIME_FOREVER);
}



//=============================
//	INF6 CHOICE (SPITTER)
//=============================

//build menu for Inf6 Perks
public Handle:Menu_Inf6Perk (client)
{
	new Handle:menu = CreatePanel();
	SetPanelTitle(menu, "技能系统 - Spitter");
	decl String:st_display[MAXPLAYERS+1];
	decl String:st_current[10];

	//set name for perk 1
	if (g_iTwinSF_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf6[client])
		{
			case 1: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"双重喷射 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64, "%t", "TwinSpitfireDescriptionPanel" );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 2
	if (g_iMegaAd_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf6[client])
		{
			case 2: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"粘皮带骨 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64, "%t: %i%%", "MegaAdhesiveDescriptionPanel", RoundToNearest( 100 - (g_flMegaAd_slow) * 100 ) );
		DrawPanelText(menu,st_display);
	}

	return menu;
}

//setting Inf5 perk and returning to top menu
public Menu_ChooseInf6Perk (Handle:menu, MenuAction:action, param1, param2)
{
	if (menu!=INVALID_HANDLE) CloseHandle(menu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			//twin spitfire
			case 1:
				g_iInf6[param1]=1;
			//mega adhesive
			case 2:
				g_iInf6[param1]=2;
		}
	}

	if (IsClientInGame(param1)==true)
		SendPanelToClient(Menu_Top_Inf(param1),param1,Menu_ChooseSubMenu_Inf,MENU_TIME_FOREVER);
}



//=============================
//	INF7 CHOICE (CHARGER)
//=============================

//build menu for Inf7 Perks
public Handle:Menu_Inf7Perk (client)
{
	new Handle:menu = CreatePanel();
	SetPanelTitle(menu, "技能系统 - Charger");
	decl String:st_display[MAXPLAYERS+1];
	decl String:st_current[10];

	//set name for perk 1
	if (g_iScatter_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf7[client])
		{
			case 1: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"愤怒的公牛 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"+%i%% %t", RoundToNearest(g_flScatter_hpmult*100), "ScatteringRamDescriptionPanel" );
		DrawPanelText(menu,st_display);
	}

	//set name for perk 2
	if (g_iBullet_enable==0)
	{
		DrawPanelItem(menu,"disabled", ITEMDRAW_NOTEXT);
	}
	else
	{
		switch (g_iInf7[client])
		{
			case 2: st_current="(当前)";
			default: st_current="";
		}
		Format(st_display,64,"超速冲撞 %s",st_current);
		DrawPanelItem(menu,st_display);
		Format(st_display,64,"%t: +%i%%", "SpeedingBulletDescriptionPanel", RoundToNearest(g_flBullet_rate*100 - 100) );
		DrawPanelText(menu,st_display);
	}

	return menu;
}

//setting Inf7 perk and returning to top menu
public Menu_ChooseInf7Perk (Handle:menu, MenuAction:action, param1, param2)
{
	if (menu!=INVALID_HANDLE) CloseHandle(menu);
	if (action==MenuAction_Select)
	{
		switch(param2)
		{
			//scatter
			case 1:
				g_iInf7[param1]=1;
			//bullet
			case 2:
				g_iInf7[param1]=2;
		}
	}

	if (IsClientInGame(param1)==true)
		SendPanelToClient(Menu_Top_Inf(param1),param1,Menu_ChooseSubMenu_Inf,MENU_TIME_FOREVER);
}



//=============================
//	DEBUG
//=============================
/*
public Action:Debug_OnSay(iCid, args)
{
	if (args<1) return Plugin_Continue;
	decl String:st_chat[32];
	GetCmdArg(1,st_chat,32);

	if (StrEqual(st_chat,"debug reset perks",false)==true)
	{
		g_iConfirm[iCid]=0;
		PrintToChat(iCid,"\x03[心动] [DEBUG] g_iConfirm has been reset to 0");
		RebuildAll();
		return Plugin_Continue;
	}

	if (StrEqual(st_chat,"debug spirit reset",false)==true)
	{
		PrintToChat(iCid,"\x03[心动] [DEBUG] spirit cooldown reset");
		g_iSpiritCooldown[iCid]=0;
		return Plugin_Continue;
	}

	if (StrEqual(st_chat,"debug death",false)==true)
	{
		new iDeathTimeO=FindSendPropOffs("CTerrorPlayer","m_flDeathTime");
		PrintToChat(iCid,"\x03[心动] [DEBUG] m_fldeathtime offset \x01%i\x03", iDeathTimeO);
		PrintToChat(iCid,"\x03[心动] [DEBUG] -value at offset: \x01%f", GetEntDataFloat(iCid,iDeathTimeO));
		return Plugin_Continue;
	}

	if (StrEqual(st_chat,"debug client",false)==true)
	{
		PrintToChat(iCid,"\x03[心动] [DEBUG] you are client: \x01%i", iCid);
		return Plugin_Continue;
	}

	if (StrEqual(st_chat,"debug anim",false)==true)
	{
		PrintToChat(iCid,"\x03[心动] [DEBUG] creating timer, client \x01%i\x03, gunid \x01%i",iCid,GetEntDataEnt2(iCid,g_iActiveWO));
		CreateTimer(0.2,Debug_AnimTimer,iCid,TIMER_REPEAT);

		return Plugin_Continue;
	}

	if (StrEqual(st_chat,"debug frustration",false)==true)
	{
		PrintToChat(iCid,"\x03[心动] [DEBUG] retrieving frustration values");
		new iOffs=FindSendPropOffs("Tank","m_frustration");
		PrintToChat(iCid,"\x03- offset \x01%i",iOffs);
		PrintToChat(iCid,"\x03- value at offset \x01%i", GetEntData(iCid,iOffs) );

		return Plugin_Continue;
	}

	if (StrEqual(st_chat,"debug stamina",false)==true)
	{
		PrintToChat(iCid,"\x03[心动] [DEBUG] creating timer, client \x01%i\x03",iCid);
		CreateTimer(0.2,Debug_StaminaTimer,iCid,TIMER_REPEAT);

		return Plugin_Continue;
	}

	if (StrEqual(st_chat,"debug maxclients",false)==true)
	{
		PrintToChat(iCid,"\x03[心动] [DEBUG] maxclients = \x01%i",MaxClients);

		return Plugin_Continue;
	}

	if (StrEqual(st_chat,"debug ammo2",false)==true)
	{
		//new iAmmoO=FindDataMapOffs(iCid,"m_iAmmo");
		new iEntid = GetEntDataEnt2(iCid,g_iActiveWO);
		new iPrimO = FindSendPropOffs("CTerrorGun","m_iExtraPrimaryAmmo");
		//PrintToChatAll("\x03[心动] [DEBUG] Ammo Counts, offset \x01%i",iAmmoO);
		//for (new i=0; i<=31; i++)
		//{
			//PrintToChatAll("\x03%i: iCid\x01 %i\x03 gun\x01 %i",i,GetEntData(iCid,iAmmoO),GetEntData(iEntid,iAmmoO));
		//}
		PrintToChatAll("\x03[心动] [DEBUG] extra primary ammo, offset \x01%i\x03 value \x01%i",iPrimO,GetEntData(iEntid,iPrimO));
	}

	if (StrEqual(st_chat,"debug ammo",false)==true)
	{
		new iAmmoO=FindDataMapOffs(iCid,"m_iAmmo");
		PrintToChatAll("\x03[心动] [DEBUG] Ammo Counts, offset \x01%i",iAmmoO);
		for (new i=0; i<=47; i++)
			PrintToChatAll("\x03%i: iCid\x01 %i\x03",i,GetEntData(iCid,iAmmoO+i));
	}

	if (StrEqual(st_chat,"debug shotgunanim",false)==true)
	{
		PrintToChat(iCid,"\x03[心动] [DEBUG] retrieving shotgun reload anim values");
		new iEntid = GetEntDataEnt2(iCid,g_iActiveWO);
		decl iOffs;
			
		iOffs=FindSendPropOffs("CBaseShotgun","m_reloadStartDuration");
		PrintToChat(iCid,"\x03- start, offset \x01%i",iOffs);
		PrintToChat(iCid,"\x03-- value at offset \x01%f", GetEntDataFloat(iEntid,iOffs) );

		iOffs=FindSendPropOffs("CBaseShotgun","m_reloadInsertDuration");
		PrintToChat(iCid,"\x03- insert, offset \x01%i",iOffs);
		PrintToChat(iCid,"\x03-- value at offset \x01%f", GetEntDataFloat(iEntid,iOffs) );

		iOffs=FindSendPropOffs("CBaseShotgun","m_reloadEndDuration");
		PrintToChat(iCid,"\x03- end, offset \x01%i",iOffs);
		PrintToChat(iCid,"\x03-- value at offset \x01%f", GetEntDataFloat(iEntid,iOffs) );

		return Plugin_Continue;
	}

	if (StrEqual(st_chat,"debug fatigue",false)==true)
	{
		PrintToChat(iCid,"\x03[心动] [DEBUG] shove penalty \x01%i\x03",GetEntData(iCid,g_iMeleeFatigueO));

		return Plugin_Continue;
	}

	return Plugin_Continue;
}

public Action:Debug_AnimTimer (Handle:timer, any:iCid)
{
	new iGun = GetEntDataEnt2(iCid,g_iActiveWO);

	new iAnimTimeO = FindSendPropOffs("CTerrorGun","m_flAnimTime");
	PrintToChat(iCid,"\x03 m_flAnimTime \x01%i",iAnimTimeO);
	PrintToChat(iCid,"\x03 - value \x01%f", GetEntDataFloat(iGun,iAnimTimeO));

	new iSimTimeO = FindSendPropOffs("CTerrorGun","m_flSimulationTime");
	PrintToChat(iCid,"\x03 m_flSimulationTime \x01%i",iSimTimeO);
	PrintToChat(iCid,"\x03 - value \x01%f", GetEntDataFloat(iGun,iSimTimeO));

	new iSequenceO = FindSendPropOffs("CTerrorGun","m_nSequence");
	PrintToChat(iCid,"\x03 m_nSequence \x01%i",iSequenceO);
	PrintToChat(iCid,"\x03 - value \x01%i", GetEntData(iGun,iSequenceO));
}

public Action:Debug_StaminaTimer (Handle:timer, any:iCid)
{
	new iStaminaO = FindSendPropOffs("CTerrorPlayer","m_flStamina");
	PrintToChat(iCid,"\x03 m_flStamina \x01%i",iStaminaO);
	PrintToChat(iCid,"\x03 - value \x01%f", GetEntDataFloat(iCid,iStaminaO));
}*/