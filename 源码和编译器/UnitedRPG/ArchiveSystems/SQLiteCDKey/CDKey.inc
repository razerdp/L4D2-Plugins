
new Handle:h_CDKeyEnable;
new Handle:h_CDKeyLen;

SQLiteCDKey_OnPluginStart()
{
	h_CDKeyLen = CreateConVar("l4d_SQLiteCDKeyLenght", "10", "生成的CDKey长度,默认至少10位,最大32位", FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY, true, 10.0, true, 32.0);
	h_CDKeyEnable = CreateConVar("l4d_SQLiteCDKeyEnable", "1", "SQLite CDKey 系统开关", FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY, true, 0.0, true, 1.0);
	
	SQLite_CreateTable(h_SQLiteDatabase, CDKeyTable, CDKeyField, sizeof(CDKeyField), false);//尝试创建数据库表格"CDKey"
}

/* 激活码 */
Command_SQLiteCDKey(Client, args)
{
	decl String:arg[64];
	
	// 用户是否登陆
	if(!IsPasswordConfirm[Client]) 
	{
		CPrintToChat(Client, "\x04[提示] \x05您还未登陆，请登陆后再使用此功能！");
		return;
	}

	// 参数是否大于0
	if(args < 1)
	{
		ReplyToCommand(Client, "\x04[提示] \x05使用用法:/cdkey 0123456789\n0123456789换成您的CDKey，/cdkey和激活码中间有空格!");
		return;
	}

	GetCmdArg(1, arg, PasswordLength);
	TrimString(arg);

	if(StrEqual(arg, "", true))
	{
		CPrintToChat(Client, "\x04[提示] \x05CDKey不能为空！");
		return;
	}

	if(IsInvalidSignature(arg))
	{
		CPrintToChat(Client, "\x04[提示] \x05CDKey无效,请输入 英文字母或者数字!");
		return;
	}

	new Handle:query = SQLite_Query(h_SQLiteDatabase,"SELECT * FROM %s where CDKey = '%s'", CDKeyTable, arg);
	if( query != INVALID_HANDLE && SQL_GetRowCount(query) > 0 && SQL_FetchRow(query) )
	{
		new invalid = SQL_FetchInt(query, 1);//是否已经被激活
		new ExchangeXB = SQL_FetchInt(query, 2);//可兑换的玄币数量
		new String:BindAccount[32];
		new String:UserName[32];
		SQL_FetchString(query, 3, BindAccount, sizeof(BindAccount));
		Format(UserName,sizeof(UserName),"%N",Client);
		
		if(invalid == 1)
		{
			CPrintToChat(Client, "\x04[提示] \x05过期,此CDKey已经被使用过!");
			return;
		}
		
		if(strlen(BindAccount) && !StrEqual(BindAccount,UserName))
		{
			CPrintToChat(Client, "\x04[提示] \x05无效,此CDKey已经绑定指定帐户!");
			return;
		}

		// 更新为已使用过
		new String:time_str[12];
		FormatTime(time_str,sizeof(time_str),"%Y%m%d",-1);
		SQLite_Update(h_SQLiteDatabase,false,"UPDATE %s SET InValid=%d, Beneficiary='%N', CDKeyUsedTime='%s' WHERE CDKey='%s'",CDKeyTable, 1, Client, time_str, arg);

		XB[Client] += ExchangeXB;
		SQLiteArchiveSys_ClientSaveToFileSave(Client,false);
		CPrintToChatAllEx(Client, "\x04[提示] {olive}%N {teamcolor}使用CDKey激活码成功领取了 {green}%d {teamcolor}玄币", Client, ExchangeXB);
	} 
	else 
	{
		CPrintToChat(Client, "\x04[提示] \x05此CDKey未授权,请联系管理员!");
	}

	CloseHandle(query);
}

