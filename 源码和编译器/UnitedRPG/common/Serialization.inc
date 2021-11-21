SerializationInfo(Client, String:buffer[], maxlength)
{
	new tmp[96] = 0;

	// 顺序一旦确定，前后位置不可随意调换
	tmp[0] = VIPTYOVER[Client];
	tmp[1] = Robot_appendage[Client];
	tmp[2] = Libao[Client];
	tmp[3] = Lyxz[Client];
	tmp[4] = LibaoLv[Client];
	tmp[5] = Eqbox[Client];
	tmp[6] = Renwu[Client];
	tmp[7] = Jenwu[Client];
	tmp[8] = Pugan[Client];
	tmp[9] = Tegan[Client];
	tmp[10] = TYangui[Client];
	tmp[11] = TPangzi[Client];
	tmp[12] = TLieshou[Client];
	tmp[13] = TKoushui[Client];
	tmp[14] = THouzhi[Client];
	tmp[15] = TXiaoniu[Client];
	tmp[16] = TDaxinxin[Client];
	tmp[17] = Qhs[Client];
	tmp[18] = M16[Client];
	tmp[19] = AK47[Client];
	tmp[20] = PZ[Client];
	tmp[21] = AWP[Client];
	tmp[22] = M60[Client];
	tmp[23] = GZ[Client];
	tmp[24] = BSXY[Client];
	tmp[25] = Sxcs[Client];
	tmp[26] = Lis[Client];
	tmp[27] = LisA[Client];
	tmp[28] = LisB[Client];
	tmp[29] = LisC[Client];
	tmp[30] = LisD[Client];
	tmp[31] = JLXT1[Client];
	tmp[32] = JLXT2[Client];
	tmp[33] = JLXT3[Client];
	tmp[34] = JLXT4[Client];
	tmp[35] = JLXT5[Client];
	tmp[36] = JLXT6[Client];
	tmp[37] = JLXT7[Client];
	tmp[38] = ACL[Client];
	tmp[39] = SCL[Client];
	tmp[40] = BCL[Client];
	tmp[41] = MFBS1[Client];
	tmp[42] = MFBS2[Client];
	tmp[43] = MFBS3[Client];
	tmp[44] = MFBS4[Client];
	tmp[45] = MFBS5[Client];
	tmp[46] = MFBS6[Client];
	tmp[47] = MFBS7[Client];
	tmp[48] = LQDY[Client];
	tmp[49] = FHCS[Client];
	tmp[50] = BSZG[Client];
	tmp[51] = JRCS[Client];
	tmp[52] = LRCS[Client];
	tmp[53] = PTJS[Client];
	tmp[54] = TANKSL[Client];
	tmp[55] = KSZXRW[Client];
	tmp[56] = ZXRW[Client];
	tmp[57] = Crits[Client];
	tmp[58] = CritMin[Client];
	tmp[59] = CritMax[Client];
	tmp[60] = YWZZS[Client];
	tmp[61] = BSD[Client];
	tmp[62] = BJCH[Client];
	tmp[63] = TKSL[Client];
	tmp[64] = XGSL[Client];
	tmp[65] = HZSL[Client];
	tmp[66] = PZSL[Client];
	tmp[67] = PPSL[Client];
	tmp[68] = DXSL[Client];
	tmp[69] = NWSL[Client];
	tmp[70] = DRSL[Client];
	tmp[71] = BRSL[Client];
	tmp[72] = YGSL[Client];
	tmp[73] = QHSL[Client];
	tmp[74] = TKSLZ[Client];
	tmp[75] = XGSLZ[Client];
	tmp[76] = HZSLZ[Client];
	tmp[77] = PZSLZ[Client];
	tmp[78] = PPSLZ[Client];
	tmp[79] = DXSLZ[Client];
	tmp[80] = NWSLZ[Client];
	tmp[81] = DRSLZ[Client];
	tmp[82] = BRSLZ[Client];
	tmp[83] = QHHSZ[Client];
	tmp[84] = BZBNZ[Client];
	tmp[85] = YGSLZ[Client];
	tmp[86] = TZZS[Client];
	tmp[87] = YLDY[Client];
	tmp[88] = DDCS[Client];
	tmp[89] = TSBS[Client];
	tmp[90] = Lottery[Client];
	tmp[91] = Hunpo[Client];
	tmp[92] = I_BagSize[Client];
	tmp[93] = PlayerXHItemSize[Client];
	tmp[94] = PlayerZBItemSize[Client];
	tmp[95] = SMHZ[Client];

	Implode(tmp, sizeof(tmp), ",", buffer, maxlength);
}

// 反序列化
UnSerializationInfo(Client, String:buffer[])
{
	new tmp[96] = 0;
	Explode(buffer, ",", tmp, sizeof(tmp));

	// 顺序一旦确定，前后位置不可随意调换

	VIPTYOVER[Client] = tmp[0];
	Robot_appendage[Client] = tmp[1];
	Libao[Client] = tmp[2];
	Lyxz[Client] = tmp[3];
	LibaoLv[Client] = tmp[4];
	Eqbox[Client] = tmp[5];
	Renwu[Client] = tmp[6];
	Jenwu[Client] = tmp[7];
	Pugan[Client] = tmp[8];
	Tegan[Client] = tmp[9];
	TYangui[Client] = tmp[10];
	TPangzi[Client] = tmp[11];
	TLieshou[Client] = tmp[12];
	TKoushui[Client] = tmp[13];
	THouzhi[Client] = tmp[14];
	TXiaoniu[Client] = tmp[15];
	TDaxinxin[Client] = tmp[16];
	Qhs[Client] = tmp[17];
	M16[Client] = tmp[18];
	AK47[Client] = tmp[19];
	PZ[Client] = tmp[20];
	AWP[Client] = tmp[21];
	M60[Client] = tmp[22];
	GZ[Client] = tmp[23];
	BSXY[Client] = tmp[24];
	Sxcs[Client] = tmp[25];
	Lis[Client] = tmp[26];
	LisA[Client] = tmp[27];
	LisB[Client] = tmp[28];
	LisC[Client] = tmp[29];
	LisD[Client] = tmp[30];
	JLXT1[Client] = tmp[31];
	JLXT2[Client] = tmp[32];
	JLXT3[Client] = tmp[33];
	JLXT4[Client] = tmp[34];
	JLXT5[Client] = tmp[35];
	JLXT6[Client] = tmp[36];
	JLXT7[Client] = tmp[37];
	ACL[Client] = tmp[38];
	SCL[Client] = tmp[39];
	BCL[Client] = tmp[40];
	MFBS1[Client] = tmp[41];
	MFBS2[Client] = tmp[42];
	MFBS3[Client] = tmp[43];
	MFBS4[Client] = tmp[44];
	MFBS5[Client] = tmp[45];
	MFBS6[Client] = tmp[46];
	MFBS7[Client] = tmp[47];
	LQDY[Client] = tmp[48];
	FHCS[Client] = tmp[49];
	BSZG[Client] = tmp[50];
	JRCS[Client] = tmp[51];
	LRCS[Client] = tmp[52];
	PTJS[Client] = tmp[53];
	TANKSL[Client] = tmp[54];
	KSZXRW[Client] = tmp[55];
	ZXRW[Client] = tmp[56];
	Crits[Client] = tmp[57];
	CritMin[Client] = tmp[58];
	CritMax[Client] = tmp[59];
	YWZZS[Client] = tmp[60];
	BSD[Client] = tmp[61];
	BJCH[Client] = tmp[62];
	TKSL[Client] = tmp[63];
	XGSL[Client] = tmp[64];
	HZSL[Client] = tmp[65];
	PZSL[Client] = tmp[66];
	PPSL[Client] = tmp[67];
	DXSL[Client] = tmp[68];
	NWSL[Client] = tmp[69];
	DRSL[Client] = tmp[70];
	BRSL[Client] = tmp[71];
	YGSL[Client] = tmp[72];
	QHSL[Client] = tmp[73];
	TKSLZ[Client] = tmp[74];
	XGSLZ[Client] = tmp[75];
	HZSLZ[Client] = tmp[76];
	PZSLZ[Client] = tmp[77];
	PPSLZ[Client] = tmp[78];
	DXSLZ[Client] = tmp[79];
	NWSLZ[Client] = tmp[80];
	DRSLZ[Client] = tmp[81];
	BRSLZ[Client] = tmp[82];
	QHHSZ[Client] = tmp[83];
	BZBNZ[Client] = tmp[84];
	YGSLZ[Client] = tmp[85];
	TZZS[Client] = tmp[86];
	YLDY[Client] = tmp[87];
	DDCS[Client] = tmp[88];
	TSBS[Client] = tmp[89];
	Lottery[Client] = tmp[90];
	Hunpo[Client] = tmp[91];
	I_BagSize[Client] = tmp[92];
	PlayerXHItemSize[Client] = tmp[93];
	PlayerZBItemSize[Client] = tmp[94];
	SMHZ[Client] = tmp[95];
}




SerializationSkill(Client, String:buffer[], maxlength)
{
	new tmp[74] = 0;

	// 顺序一旦确定，前后位置不可随意调换
	tmp[0] = HealingLv[Client];
	tmp[1] = EarthQuakeLv[Client];
	tmp[2] = EndranceQualityLv[Client];
	tmp[3] = AmmoMakingLv[Client];
	tmp[5] = FireSpeedLv[Client];
	tmp[6] = SatelliteCannonLv[Client];
	tmp[7] = EnergyEnhanceLv[Client];
	tmp[8] = SprintLv[Client];
	tmp[9] = InfiniteAmmoLv[Client];
	tmp[10] = BioShieldkbLv[Client];
	tmp[11] = BioShieldLv[Client];
	tmp[12] = DamageReflectLv[Client];
	tmp[13] = MeleeSpeedLv[Client];
	tmp[14] = BioShieldmissLv[Client];
	tmp[15] = GeneLv[Client];
	tmp[16] = TeleportToSelectLv[Client];
	tmp[17] = HolyBoltLv[Client];
	tmp[18] = TeleportTeamLv[Client];
	tmp[19] = HealingBallLv[Client];
	tmp[20] = TeleportTeamztLv[Client];
	tmp[21] = FireBallLv[Client];
	tmp[22] = IceBallLv[Client];
	tmp[23] = ChainLightningLv[Client];
	tmp[24] = SatelliteCannonmissLv[Client];
	tmp[25] = BrokenAmmoLv[Client];
	tmp[26] = PoisonAmmoLv[Client];
	tmp[27] = SuckBloodAmmoLv[Client];
	tmp[28] = AreaBlastingLv[Client];
	tmp[29] = LaserGunLv[Client];
	tmp[30] = GouhunLv[Client];
	tmp[31] = LinliLv[Client];
	tmp[32] = AreaBlastingexLv[Client];
	tmp[33] = SszlLv[Client];
	tmp[34] = AynlLv[Client];
	tmp[35] = DyzhLv[Client];
	tmp[36] = HassLv[Client];
	tmp[37] = ZdgcLv[Client];
	tmp[38] = CqdzLv[Client];
	tmp[39] = SWHTLv[Client];
	tmp[40] = WXNYLv[Client];
	tmp[41] = SWGZLv[Client];
	tmp[42] = LDZLv[Client];
	tmp[43] = GZSLv[Client];
	tmp[44] = YLTJLv[Client];
	tmp[45] = LZDLv[Client];
	tmp[46] = FBZNLv[Client];
	tmp[47] = XBFBLv[Client];
	tmp[48] = WZZGLv[Client];
	tmp[49] = SPZSLv[Client];
	tmp[50] = HMZSLv[Client];
	tmp[51] = JYSQLv[Client];
	tmp[52] = SXZGLv[Client];
	tmp[54] = DSZGLv[Client];
	tmp[55] = PHFRLv[Client];
	tmp[56] = PHABLv[Client];
	tmp[57] = PHZGLv[Client];
	tmp[58] = PHSCLv[Client];
	tmp[59] = PHFRALv[Client];
	tmp[60] = PHABALv[Client];
	tmp[61] = PHZGALv[Client];
	tmp[62] = PHSDLv[Client];
	tmp[63] = XJLv[Client];
	tmp[64] = LLLZLv[Client];
	tmp[65] = LLLELv[Client];
	tmp[66] = LLLSLv[Client];
	tmp[67] = BBBSLv[Client];
	tmp[68] = GELINLv[Client];
	tmp[69] = HYJWLv[Client];
	tmp[70] = NQBFLv[Client];
	tmp[71] = XZKBLv[Client];
	tmp[72] = JBSYLv[Client];
	tmp[73] = BSTKLv[Client];

	Implode(tmp, sizeof(tmp), ",", buffer, maxlength);
}

UnSerializationSkill(Client, String:buffer[])
{
	new tmp[74] = 0;
	Explode(buffer, ",", tmp, sizeof(tmp));

	// 顺序一旦确定，前后位置不可随意调换
	HealingLv[Client] = tmp[0];
	EarthQuakeLv[Client] = tmp[1];
	EndranceQualityLv[Client] = tmp[2];
	AmmoMakingLv[Client] = tmp[3];
	FireSpeedLv[Client] = tmp[5];
	SatelliteCannonLv[Client] = tmp[6];
	EnergyEnhanceLv[Client] = tmp[7];
	SprintLv[Client] = tmp[8];
	InfiniteAmmoLv[Client] = tmp[9];
	BioShieldkbLv[Client] = tmp[10];
	BioShieldLv[Client] = tmp[11];
	DamageReflectLv[Client] = tmp[12];
	MeleeSpeedLv[Client] = tmp[13];
	BioShieldmissLv[Client] = tmp[14];
	GeneLv[Client] = tmp[15];
	TeleportToSelectLv[Client] = tmp[16];
	HolyBoltLv[Client] = tmp[17];
	TeleportTeamLv[Client] = tmp[18];
	HealingBallLv[Client] = tmp[19];
	TeleportTeamztLv[Client] = tmp[20];
	FireBallLv[Client] = tmp[21];
	IceBallLv[Client] = tmp[22];
	ChainLightningLv[Client] = tmp[23];
	SatelliteCannonmissLv[Client] = tmp[24];
	BrokenAmmoLv[Client] = tmp[25];
	PoisonAmmoLv[Client] = tmp[26];
	SuckBloodAmmoLv[Client] = tmp[27];
	AreaBlastingLv[Client] = tmp[28];
	LaserGunLv[Client] = tmp[29];
	GouhunLv[Client] = tmp[30];
	LinliLv[Client] = tmp[31];
	AreaBlastingexLv[Client] = tmp[32];
	SszlLv[Client] = tmp[33];
	AynlLv[Client] = tmp[34];
	DyzhLv[Client] = tmp[35];
	HassLv[Client] = tmp[36];
	ZdgcLv[Client] = tmp[37];
	CqdzLv[Client] = tmp[38];
	SWHTLv[Client] = tmp[39];
	WXNYLv[Client] = tmp[40];
	SWGZLv[Client] = tmp[41];
	LDZLv[Client] = tmp[42];
	GZSLv[Client] = tmp[43];
	YLTJLv[Client] = tmp[44];
	LZDLv[Client] = tmp[45];
	FBZNLv[Client] = tmp[46];
	XBFBLv[Client] = tmp[47];
	WZZGLv[Client] = tmp[48];
	SPZSLv[Client] = tmp[49];
	HMZSLv[Client] = tmp[50];
	JYSQLv[Client] = tmp[51];
	SXZGLv[Client] = tmp[52];
	DSZGLv[Client] = tmp[54];
	PHFRLv[Client] = tmp[55];
	PHABLv[Client] = tmp[56];
	PHZGLv[Client] = tmp[57];
	PHSCLv[Client] = tmp[58];
	PHFRALv[Client] = tmp[59];
	PHABALv[Client] = tmp[60];
	PHZGALv[Client] = tmp[61];
	PHSDLv[Client] = tmp[62];
	XJLv[Client] = tmp[63];
	LLLZLv[Client] = tmp[64];
	LLLELv[Client] = tmp[65];
	LLLSLv[Client] = tmp[66];
	BBBSLv[Client] = tmp[67];
	GELINLv[Client] = tmp[68];
	HYJWLv[Client] = tmp[69];
	NQBFLv[Client] = tmp[70];
	XZKBLv[Client] = tmp[71];
	JBSYLv[Client] = tmp[72];
	BSTKLv[Client] = tmp[73];
}




SerializationEveryDaySign(Client, String:buffer[], maxlength)
{
	new tmp[2] = 0;

	// 顺序一旦确定，前后位置不可随意调换
	tmp[0] = EveryDaySign[Client];
	tmp[1] = everyday1[Client];

	Implode(tmp, sizeof(tmp), ",", buffer, maxlength);
}

UnSerializationEveryDaySign(Client, String:buffer[])
{
	new tmp[2] = 0;
	Explode(buffer, ",", tmp, sizeof(tmp));

	// 顺序一旦确定，前后位置不可随意调换
	EveryDaySign[Client] = tmp[0];
	everyday1[Client] = tmp[1];
}




SerializationMaster(Client, String:buffer[], maxlength)
{
	decl String:Master[2][74];

	strcopy(Master[0], sizeof(Master[]), shifu[Client]);
	strcopy(Master[1], sizeof(Master[]), tudi[Client]);

	ImplodeStrings(Master, sizeof(Master), "{|}", buffer, maxlength);
}

UnSerializationMaster(Client, String:buffer[])
{
	decl String:Master[2][74], i, maxsize;
	maxsize = sizeof(Master);

	ExplodeString(buffer, "{|}", Master, sizeof(Master), sizeof(Master[]));

	for(i=0;i<maxsize;i++)
	{
		if(StrEqual(Master[i], "0", true))
		{
			strcopy(Master[i], sizeof(Master[]), "");
		}
	}

	strcopy(shifu[Client], sizeof(shifu[]), Master[0]);
	strcopy(tudi[Client], sizeof(tudi[]), Master[1]);
}




SerializationMaster2(Client, String:buffer[], maxlength)
{
	new tmp[10] = 0;

	// 顺序一旦确定，前后位置不可随意调换
	tmp[0] = shifuNem[Client];
	tmp[1] = tudiNem[Client];
	tmp[2] = ticeship[Client];
	tmp[3] = Cbution[Client];
	tmp[4] = tudLv[Client];
	tmp[5] = tudNL[Client];
	tmp[6] = tudEXP[Client];
	tmp[7] = shifLv[Client];
	tmp[8] = shifNL[Client];
	tmp[9] = shifEXP[Client];


	Implode(tmp, sizeof(tmp), ",", buffer, maxlength);
}

// 反序列化
UnSerializationMaster2(Client, String:buffer[])
{
	new tmp[10] = 0;
	Explode(buffer, ",", tmp, sizeof(tmp));

	// 顺序一旦确定，前后位置不可随意调换
	shifuNem[Client] = tmp[0];
	tudiNem[Client] = tmp[1];
	ticeship[Client] = tmp[2];
	Cbution[Client] = tmp[3];
	tudLv[Client] = tmp[4];
	tudNL[Client] = tmp[5];
	tudEXP[Client] = tmp[6];
	shifLv[Client] = tmp[7];
	shifNL[Client] = tmp[8];
	shifEXP[Client] = tmp[9];
}

