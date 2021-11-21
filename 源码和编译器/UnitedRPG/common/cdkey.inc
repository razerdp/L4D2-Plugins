// 激活码激活限制
#define SERVER_NO  4

#include "UnitedRPG/ArchiveSystems/SQLiteCDKey/Include.inc"

/* 激活码 */
public Action:Command_CDKey(Client, args)
{
	if(GetConVarBool(h_CDKeyEnable))
	{
		Command_SQLiteCDKey(Client, args);
		return Plugin_Handled;
	}

	decl String:arg[64];
	
	// 用户是否登陆
	if(!IsPasswordConfirm[Client])
	{
		CPrintToChat(Client, "\x04[提示]\x05您还未登陆，请登陆后再使用此功能！");
		return Plugin_Handled;
	}

	// 参数是否大于0
	if(args < 1) 
	{
		ReplyToCommand(Client, "\x04[提示]\x05使用用法:/cdkey 0123456789\n0123456789换成您的激活码，/cdkey和激活码中间有空格！");
		return Plugin_Handled;
	}

	GetCmdArg(1, arg, PasswordLength);
	TrimString(arg);

	if(StrEqual(arg, "", true)) {
		CPrintToChat(Client, "\x04[提示]\x05激活码不能为空！");
		return Plugin_Handled;
	}

	ReplaceString(arg, sizeof(arg), "\034", "");
	ReplaceString(arg, sizeof(arg), "\'", "");
	ReplaceString(arg, sizeof(arg), "//", "");

	new Handle:query = db_query("select `id`, `cdkey`, `cash`, `is_used`, `server_no` from orders where is_used = 0 and server_no in (0, %d) and cdkey = '%s'", SERVER_NO, arg);
	if( query != INVALID_HANDLE && SQL_GetRowCount(query) > 0 && SQL_FetchRow(query) )
	{
		new orderId = SQL_FetchInt(query, 0);
		new cash = SQL_FetchInt(query, 2);
		CloseHandle(query);

		if(cash <= 0)
		{
			CPrintToChat(Client, "\x04[提示]\x05由于充值系统调整，您的激活码需要找[纯白、色]<qq:402035985>进行更新！");
			return Plugin_Handled;
		}

		// 更新为已使用过
		query = db_query("update orders set is_used = 1, use_time = sysdate(), act_user = '%s' where id = %d", SafeReturnClientName(Client), orderId);
		if(query == INVALID_HANDLE) {
			CPrintToChat(Client, "\x04[系统]\x05激活失败！");
			return Plugin_Handled;
		}
		CloseHandle(query);

		XB[Client] += cash;
		CPrintToChatAllEx(Client, "\x04[提示]{olive}%N {teamcolor}使用激活码成功领取了 {green}%d {teamcolor}求生币", Client, cash);
		CDKEY_Discount(Client, cash);

	} else {
		CPrintToChat(Client, "\x04[提示]\x05你输入的CDKEY无效或已过期,请确认你的CDKEY是否正确！");
	}

	CloseHandle(query);
	ClientSaveToFileSave(Client);
	return Plugin_Handled;
}

/**
 * 9月29日 - 10月1日 求生币特惠活动
 */
stock CDKEY_Discount(Client, num)
{
	// 附送求生币
	new ext = 0;
	if(GetMonth() != 11) return;
	if(GetDay() < 11 || GetDay() > 30) return;

	ext = num;

	if(ext > 0)
	{
		XB[Client] += ext;
		CPrintToChatAll("{olive}[提示]{green}%N {red}在活动期间激活求生币，又额外获得系统赠送的 {green}%d {red}求生币", Client, ext);
	}
}

//获取当前月份
stock GetDay()
{
	new String:text[32];
	FormatTime(text, sizeof(text), "%d");
	new day = StringToInt(text);
	return day;
}
