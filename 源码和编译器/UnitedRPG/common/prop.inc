// 设置玩家移动速度
stock SetPropMovement(client, Float:speed, PropType:type = Prop_Data)
{
	speed = speed > 2.0 ? 2.0 : speed;
	SetEntPropFloat(client, type, "m_flLaggedMovementValue", speed);
}

// 限制give
#define ENT_SLOT0_MAX	17
#define ENT_SLOT1_MAX	15
#define ENT_SLOT2_MAX	3
#define ENT_SLOT3_MAX	4
#define ENT_SLOT4_MAX	2

static String:Ent_Slot0[ENT_SLOT0_MAX][] = { "smg_silenced", "smg", "pumpshotgun", "shotgun_chrome", "autoshotgun", "shotgun_spas", "hunting_rifle", "sniper_military", "rifle", "rifle_ak47", "rifle_desert", "grenade_launcher", "rifle_m60", "rifle_sg552", "smg_mp5", "sniper_awp", "sniper_scout" };
static String:Ent_Slot1[ENT_SLOT1_MAX][] = { "pistol", "pistol_magnum", "baseball_bat", "cricket_bat", "crowbar", "electric_guitar", "fireaxe", "frying_pan", "golfclub", "katana", "hunting_knife", "machete", "riotshield", "tonfa", "chainsaw" };
static String:Ent_Slot2[ENT_SLOT2_MAX][] = { "molotov", "vomitjar", "pipe_bomb" };
static String:Ent_Slot3[ENT_SLOT3_MAX][] = { "first_aid_kit", "defibrillator", "upgradepack_explosive", "upgradepack_incendiary" };
static String:Ent_Slot4[ENT_SLOT4_MAX][] = { "adrenaline", "pain_pills" };

stock bool:Ent_Give(Client, String:EntName[])
{
	if(!IsValidPlayer(Client)) return false;
	decl i, ent, ActiveWeapon, String:entclass[65], bool:skip;
	ent = 0, skip= false;

	for(i = 0; i < ENT_SLOT0_MAX; i++)
	{
		if(ent) break;
		if (StrEqual(EntName, Ent_Slot0[i], false))
			ent = GetPlayerWeaponSlot(Client, 0);
	}

	for(i = 0; i < ENT_SLOT1_MAX; i++)
	{
		if(ent) break;
		if (StrEqual(EntName, Ent_Slot1[i], false))
			ent = GetPlayerWeaponSlot(Client, 1);
	}

	for(i = 0; i < ENT_SLOT2_MAX; i++)
	{
		if(ent) break;
		if (StrEqual(EntName, Ent_Slot2[i], false))
			ent = GetPlayerWeaponSlot(Client, 2);
	}

	for(i = 0; i < ENT_SLOT3_MAX; i++)
	{
		if(ent) break;
		// 避免药包使用状态购买药包玩家卡住
		if (StrEqual(EntName, Ent_Slot3[i], false))
		{

			ActiveWeapon = GetEntPropEnt(Client, Prop_Send, "m_hActiveWeapon");
			if (IsValidEdict(ActiveWeapon) && IsValidEntity(ActiveWeapon))
				GetEdictClassname(ActiveWeapon, entclass, sizeof(entclass));

			ent = GetPlayerWeaponSlot(Client, 3);
			skip = (StrContains(entclass, EntName, false) >= 0);
		}

	}

	for(i = 0; i < ENT_SLOT4_MAX; i++)
	{
		if(ent) break;
		if (StrEqual(EntName, Ent_Slot4[i], false))
			ent = GetPlayerWeaponSlot(Client, 4);
	}

	// 避免在电锯使用状态下购买物品可以刷物品的bug
	if(GetClientButtons(Client) & IN_ATTACK)
		return false;

	if(!skip)
	{
		if(ent  && ent != -1) RemoveEdict(ent);
		CheatCommand(Client, "give", EntName);
	}

	return true;
}