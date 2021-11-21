SQLite_SerializationInfo(Client, String:buffer[], maxlength)
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

	//Implode(tmp, sizeof(tmp), ",", buffer, maxlength);
	
	//changed by MicroLeo. 数组数据转换字符串
	new String:tmpStr[96][16];
	for(new i=0;i<96;i++)
	{
		IntToString(tmp[i],tmpStr[i],16);
	}
	ImplodeStrings(tmpStr,96,",",buffer,maxlength);
}

// 反序列化
SQLite_UnSerializationInfo(Client,const String:buffer[])
{
	
	//new tmp[96] = 0;
	//Explode(buffer, ",", tmp, sizeof(tmp));
	
	//changed by MicroLeo 字符串拆分转换
	new String:tmp[96][16];
	ExplodeString(buffer,",",tmp,96,16);
	
	// 顺序一旦确定，前后位置不可随意调换
	VIPTYOVER[Client] = StringToInt(tmp[0]);
	Robot_appendage[Client] = StringToInt(tmp[1]);
	Libao[Client] = StringToInt(tmp[2]);
	Lyxz[Client] = StringToInt(tmp[3]);
	LibaoLv[Client] = StringToInt(tmp[4]);
	Eqbox[Client] = StringToInt(tmp[5]);
	Renwu[Client] = StringToInt(tmp[6]);
	Jenwu[Client] = StringToInt(tmp[7]);
	Pugan[Client] = StringToInt(tmp[8]);
	Tegan[Client] = StringToInt(tmp[9]);
	TYangui[Client] = StringToInt(tmp[10]);
	TPangzi[Client] = StringToInt(tmp[11]);
	TLieshou[Client] = StringToInt(tmp[12]);
	TKoushui[Client] = StringToInt(tmp[13]);
	THouzhi[Client] = StringToInt(tmp[14]);
	TXiaoniu[Client] = StringToInt(tmp[15]);
	TDaxinxin[Client] = StringToInt(tmp[16]);
	Qhs[Client] = StringToInt(tmp[17]);
	M16[Client] = StringToInt(tmp[18]);
	AK47[Client] = StringToInt(tmp[19]);
	PZ[Client] = StringToInt(tmp[20]);
	AWP[Client] = StringToInt(tmp[21]);
	M60[Client] = StringToInt(tmp[22]);
	GZ[Client] = StringToInt(tmp[23]);
	BSXY[Client] = StringToInt(tmp[24]);
	Sxcs[Client] = StringToInt(tmp[25]);
	Lis[Client] = StringToInt(tmp[26]);
	LisA[Client] = StringToInt(tmp[27]);
	LisB[Client] = StringToInt(tmp[28]);
	LisC[Client] = StringToInt(tmp[29]);
	LisD[Client] = StringToInt(tmp[30]);
	JLXT1[Client] = StringToInt(tmp[31]);
	JLXT2[Client] = StringToInt(tmp[32]);
	JLXT3[Client] = StringToInt(tmp[33]);
	JLXT4[Client] = StringToInt(tmp[34]);
	JLXT5[Client] = StringToInt(tmp[35]);
	JLXT6[Client] = StringToInt(tmp[36]);
	JLXT7[Client] = StringToInt(tmp[37]);
	ACL[Client] = StringToInt(tmp[38]);
	SCL[Client] = StringToInt(tmp[39]);
	BCL[Client] = StringToInt(tmp[40]);
	MFBS1[Client] = StringToInt(tmp[41]);
	MFBS2[Client] = StringToInt(tmp[42]);
	MFBS3[Client] = StringToInt(tmp[43]);
	MFBS4[Client] = StringToInt(tmp[44]);
	MFBS5[Client] = StringToInt(tmp[45]);
	MFBS6[Client] = StringToInt(tmp[46]);
	MFBS7[Client] = StringToInt(tmp[47]);
	LQDY[Client] = StringToInt(tmp[48]);
	FHCS[Client] = StringToInt(tmp[49]);
	BSZG[Client] = StringToInt(tmp[50]);
	JRCS[Client] = StringToInt(tmp[51]);
	LRCS[Client] = StringToInt(tmp[52]);
	PTJS[Client] = StringToInt(tmp[53]);
	TANKSL[Client] = StringToInt(tmp[54]);
	KSZXRW[Client] = StringToInt(tmp[55]);
	ZXRW[Client] = StringToInt(tmp[56]);
	Crits[Client] = StringToInt(tmp[57]);
	CritMin[Client] = StringToInt(tmp[58]);
	CritMax[Client] = StringToInt(tmp[59]);
	YWZZS[Client] = StringToInt(tmp[60]);
	BSD[Client] = StringToInt(tmp[61]);
	BJCH[Client] = StringToInt(tmp[62]);
	TKSL[Client] = StringToInt(tmp[63]);
	XGSL[Client] = StringToInt(tmp[64]);
	HZSL[Client] = StringToInt(tmp[65]);
	PZSL[Client] = StringToInt(tmp[66]);
	PPSL[Client] = StringToInt(tmp[67]);
	DXSL[Client] = StringToInt(tmp[68]);
	NWSL[Client] = StringToInt(tmp[69]);
	DRSL[Client] = StringToInt(tmp[70]);
	BRSL[Client] = StringToInt(tmp[71]);
	YGSL[Client] = StringToInt(tmp[72]);
	QHSL[Client] = StringToInt(tmp[73]);
	TKSLZ[Client] = StringToInt(tmp[74]);
	XGSLZ[Client] = StringToInt(tmp[75]);
	HZSLZ[Client] = StringToInt(tmp[76]);
	PZSLZ[Client] = StringToInt(tmp[77]);
	PPSLZ[Client] = StringToInt(tmp[78]);
	DXSLZ[Client] = StringToInt(tmp[79]);
	NWSLZ[Client] = StringToInt(tmp[80]);
	DRSLZ[Client] = StringToInt(tmp[81]);
	BRSLZ[Client] = StringToInt(tmp[82]);
	QHHSZ[Client] = StringToInt(tmp[83]);
	BZBNZ[Client] = StringToInt(tmp[84]);
	YGSLZ[Client] = StringToInt(tmp[85]);
	TZZS[Client] = StringToInt(tmp[86]);
	YLDY[Client] = StringToInt(tmp[87]);
	DDCS[Client] = StringToInt(tmp[88]);
	TSBS[Client] = StringToInt(tmp[89]);
	Lottery[Client] = StringToInt(tmp[90]);
	Hunpo[Client] = StringToInt(tmp[91]);
	I_BagSize[Client] = StringToInt(tmp[92]);
	PlayerXHItemSize[Client] = StringToInt(tmp[93]);
	PlayerZBItemSize[Client] = StringToInt(tmp[94]);
	SMHZ[Client] = StringToInt(tmp[95]);
}




SQLite_SerializationSkill(Client, String:buffer[], maxlength)
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

	//Implode(tmp, sizeof(tmp), ",", buffer, maxlength);
	
	//by MicroLeo
	new String:tmpStr[74][16];
	for(new i=0;i<74;i++)
	{
		IntToString(tmp[i],tmpStr[i],16);
	}
	ImplodeStrings(tmpStr,74,",",buffer,maxlength);
	//end
}

SQLite_UnSerializationSkill(Client,const String:buffer[])
{
	
	//new tmp[74];
	//Explode(buffer, ",", tmp, sizeof(tmp));
	
	//changed by MicroLeo 字符串拆分转换
	new String:tmp[74][16];
	ExplodeString(buffer, ",", tmp, 74, 16);
	
	// 顺序一旦确定，前后位置不可随意调换
	HealingLv[Client] = StringToInt(tmp[0]);
	EarthQuakeLv[Client] = StringToInt(tmp[1]);
	EndranceQualityLv[Client] = StringToInt(tmp[2]);
	AmmoMakingLv[Client] = StringToInt(tmp[3]);
	FireSpeedLv[Client] = StringToInt(tmp[5]);
	SatelliteCannonLv[Client] = StringToInt(tmp[6]);
	EnergyEnhanceLv[Client] = StringToInt(tmp[7]);
	SprintLv[Client] = StringToInt(tmp[8]);
	InfiniteAmmoLv[Client] = StringToInt(tmp[9]);
	BioShieldkbLv[Client] = StringToInt(tmp[10]);
	BioShieldLv[Client] = StringToInt(tmp[11]);
	DamageReflectLv[Client] = StringToInt(tmp[12]);
	MeleeSpeedLv[Client] = StringToInt(tmp[13]);
	BioShieldmissLv[Client] = StringToInt(tmp[14]);
	GeneLv[Client] = StringToInt(tmp[15]);
	TeleportToSelectLv[Client] = StringToInt(tmp[16]);
	HolyBoltLv[Client] = StringToInt(tmp[17]);
	TeleportTeamLv[Client] = StringToInt(tmp[18]);
	HealingBallLv[Client] = StringToInt(tmp[19]);
	TeleportTeamztLv[Client] = StringToInt(tmp[20]);
	FireBallLv[Client] = StringToInt(tmp[21]);
	IceBallLv[Client] = StringToInt(tmp[22]);
	ChainLightningLv[Client] = StringToInt(tmp[23]);
	SatelliteCannonmissLv[Client] = StringToInt(tmp[24]);
	BrokenAmmoLv[Client] = StringToInt(tmp[25]);
	PoisonAmmoLv[Client] = StringToInt(tmp[26]);
	SuckBloodAmmoLv[Client] = StringToInt(tmp[27]);
	AreaBlastingLv[Client] = StringToInt(tmp[28]);
	LaserGunLv[Client] = StringToInt(tmp[29]);
	GouhunLv[Client] = StringToInt(tmp[30]);
	LinliLv[Client] = StringToInt(tmp[31]);
	AreaBlastingexLv[Client] = StringToInt(tmp[32]);
	SszlLv[Client] = StringToInt(tmp[33]);
	AynlLv[Client] = StringToInt(tmp[34]);
	DyzhLv[Client] = StringToInt(tmp[35]);
	HassLv[Client] = StringToInt(tmp[36]);
	ZdgcLv[Client] = StringToInt(tmp[37]);
	CqdzLv[Client] = StringToInt(tmp[38]);
	SWHTLv[Client] = StringToInt(tmp[39]);
	WXNYLv[Client] = StringToInt(tmp[40]);
	SWGZLv[Client] = StringToInt(tmp[41]);
	LDZLv[Client] = StringToInt(tmp[42]);
	GZSLv[Client] = StringToInt(tmp[43]);
	YLTJLv[Client] = StringToInt(tmp[44]);
	LZDLv[Client] = StringToInt(tmp[45]);
	FBZNLv[Client] = StringToInt(tmp[46]);
	XBFBLv[Client] = StringToInt(tmp[47]);
	WZZGLv[Client] = StringToInt(tmp[48]);
	SPZSLv[Client] = StringToInt(tmp[49]);
	HMZSLv[Client] = StringToInt(tmp[50]);
	JYSQLv[Client] = StringToInt(tmp[51]);
	SXZGLv[Client] = StringToInt(tmp[52]);
	DSZGLv[Client] = StringToInt(tmp[54]);
	PHFRLv[Client] = StringToInt(tmp[55]);
	PHABLv[Client] = StringToInt(tmp[56]);
	PHZGLv[Client] = StringToInt(tmp[57]);
	PHSCLv[Client] = StringToInt(tmp[58]);
	PHFRALv[Client] = StringToInt(tmp[59]);
	PHABALv[Client] = StringToInt(tmp[60]);
	PHZGALv[Client] = StringToInt(tmp[61]);
	PHSDLv[Client] = StringToInt(tmp[62]);
	XJLv[Client] = StringToInt(tmp[63]);
	LLLZLv[Client] = StringToInt(tmp[64]);
	LLLELv[Client] = StringToInt(tmp[65]);
	LLLSLv[Client] = StringToInt(tmp[66]);
	BBBSLv[Client] = StringToInt(tmp[67]);
	GELINLv[Client] = StringToInt(tmp[68]);
	HYJWLv[Client] = StringToInt(tmp[69]);
	NQBFLv[Client] = StringToInt(tmp[70]);
	XZKBLv[Client] = StringToInt(tmp[71]);
	JBSYLv[Client] = StringToInt(tmp[72]);
	BSTKLv[Client] = StringToInt(tmp[73]);
	//end
}




SQLite_SerializationEveryDaySign(Client, String:buffer[], maxlength)
{
/*
	new tmp[2] = 0;
	// 顺序一旦确定，前后位置不可随意调换
	tmp[0] = EveryDaySign[Client];
	tmp[1] = everyday1[Client];
	Implode(tmp, sizeof(tmp), ",", buffer, maxlength);
*/
	//changed by MicroLeo
	new String:tmpStr[2][16];
	IntToString(EveryDaySign[Client],tmpStr[0],16);
	IntToString(everyday1[Client],tmpStr[1],16);
	ImplodeStrings(tmpStr,2,",",buffer,maxlength);
}

SQLite_UnSerializationEveryDaySign(Client, String:buffer[])
{
/*
	new tmp[2] = 0;
	Explode(buffer, ",", tmp, sizeof(tmp));

	// 顺序一旦确定，前后位置不可随意调换
	EveryDaySign[Client] = tmp[0];
	everyday1[Client] = tmp[1];
*/
	//changed by MicroLeo
	new String:tmpStr[2][16];
	ExplodeString(buffer,",",tmpStr,2,16);
	EveryDaySign[Client] = StringToInt(tmpStr[0]);
	everyday1[Client] = StringToInt(tmpStr[1]);
}




SQLite_SerializationMaster(Client, String:buffer[], maxlength)
{
	decl String:Master[2][74];

	strcopy(Master[0], sizeof(Master[]), shifu[Client]);
	strcopy(Master[1], sizeof(Master[]), tudi[Client]);

	ImplodeStrings(Master, sizeof(Master), "{|}", buffer, maxlength);
}

SQLite_UnSerializationMaster(Client, String:buffer[])
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




SQLite_SerializationMaster2(Client, String:buffer[], maxlength)
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


	//Implode(tmp, sizeof(tmp), ",", buffer, maxlength);
	
	//by MicroLeo
	new String:tmpStr[10][16];
	for(new i=0;i<10;i++)
	{
		IntToString(tmp[i],tmpStr[i],16);
	}
	ImplodeStrings(tmpStr,10,",",buffer,maxlength);
}

// 反序列化
SQLite_UnSerializationMaster2(Client, String:buffer[])
{
/*
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
*/
	//by MicroLeo
	new String:tmpStr[10][16];
	ExplodeString(buffer,",",tmpStr,10,16);
	shifuNem[Client] = StringToInt(tmpStr[0]);
	tudiNem[Client] = StringToInt(tmpStr[1]);
	ticeship[Client] = StringToInt(tmpStr[2]);
	Cbution[Client] = StringToInt(tmpStr[3]);
	tudLv[Client] = StringToInt(tmpStr[4]);
	tudNL[Client] = StringToInt(tmpStr[5]);
	tudEXP[Client] = StringToInt(tmpStr[6]);
	shifLv[Client] = StringToInt(tmpStr[7]);
	shifNL[Client] = StringToInt(tmpStr[8]);
	shifEXP[Client] = StringToInt(tmpStr[9]);
}