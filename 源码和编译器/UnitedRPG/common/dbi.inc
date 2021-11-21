// 数据库链接句柄
new Handle:db = INVALID_HANDLE;
new Handle:db_connectTimeout = INVALID_HANDLE;	// 连接超时时间

new bool:db_debug = true;
new String:db_log[256];
new String:db_sql_error_log[256];

new db_e_restart = 30;
new Handle:db_restart = INVALID_HANDLE;	// 连接超时时间



// build handle connect to server
db_connect()
{
	// creat db_log
	decl String:date[21];
	FormatTime(date, sizeof(date), "%y%m%d", -1);
	BuildPath(Path_SM, db_log, sizeof(db_log), "logs/mysql_%s.log", date);
	BuildPath(Path_SM, db_sql_error_log, sizeof(db_sql_error_log), "logs/sql_error_%s.log", date);

	// connect to db_server
	if( db == INVALID_HANDLE ) {
		decl String:error[255];
		db = SQL_DefConnect(error, sizeof(error));
		if( db == INVALID_HANDLE ) {
			LogToFileEx(db_log, "[error]db connect to db_server failed! [error: %s]", error);
			// SetFailState("数据库连接失败!");
			if(db_restart == INVALID_HANDLE)
			{
				db_restart = CreateTimer(1.0, ServerRestart, _, TIMER_REPEAT);
			}
			return;
		} else {
			LogToFileEx(db_log, "[success]db connect success!");
		}
	} else {
		LogToFileEx(db_log, "[notice]db has connected!");
	}

	// set chear set
	SQL_FastQuery(db , "SET NAMES 'utf8'");
}



/**
 * 格式化并执行壹个SQL
 * @param sSql			需要格式化的sql.
 * @return				Handle
 *
 * On error/Errors:   If the client is not connected an error will be thrown.
 */
Handle:db_query(const String:sSql[], any:...)
{
	if(db_connectTimeout != INVALID_HANDLE)
	{
		KillTimer(db_connectTimeout);
		db_connectTimeout = INVALID_HANDLE;
	}

	decl String:sql[512];
	decl String:error[512];

	VFormat(sql, sizeof(sql), sSql, 2);

	// 数据库意外断开后重连，确保数据库已连接
	if( db == INVALID_HANDLE ) {
		db_connect();
		if( db_debug )
		{
			LogToFileEx(db_log, "执行[sql:%s]时，发现数据库已意外断开，正在进行重连...", sql);
		}
		if(db == INVALID_HANDLE)
			return INVALID_HANDLE;
	}

	// 设置编码
	SQL_FastQuery(db , "SET NAMES 'utf8'");
	// 执行sql
	new Handle:query = SQL_Query(db, sql);
	// 调试模式将输出所有sql语句及错误
	if( db_debug ) {
		LogToFileEx(db_log, "[sql]%s", sql);
		if( query == INVALID_HANDLE ) {
			SQL_GetError(db, error, sizeof(error));
			LogToFileEx(db_sql_error_log, "[error]%s (sql:%s)", error, sql);
		}
	}
	db_connectTimeout = CreateTimer(10.0, db_closeConnect, _, TIMER_REPEAT);
	return query;
}


/**
 * 快速执行壹个sql，返回执行结果 true | false
 *
 */
bool:db_fastQuery(const String:sSql[], any:...)
{
	if(db_connectTimeout != INVALID_HANDLE)
	{
		KillTimer(db_connectTimeout);
		db_connectTimeout = INVALID_HANDLE;
	}

	decl String:sql[512];
	decl String:error[512];

	VFormat(sql, sizeof(sql), sSql, 2);

	// 数据库意外断开后重连，确保数据库已连接
	if( db == INVALID_HANDLE ) {
		db_connect();
		if( db_debug )
		{
			LogToFileEx(db_log, "执行[sql:%s]时，发现数据库已意外断开，正在进行重连...", sql);
		}
		if(db == INVALID_HANDLE)
			return false;
	}
	// 设置编码
	SQL_FastQuery(db , "SET NAMES 'utf8'");
	// 执行sql
	new bool:status = SQL_FastQuery(db, sql);
	// 调试模式将输出所有sql语句及错误
	if( db_debug ) {
		LogToFileEx(db_log, "[sql]%s", sql);
		if( !status ) {
			SQL_GetError(db, error, sizeof(error));
			LogToFileEx(db_sql_error_log, "[error]%s (sql:%s)", error, sql);
		}
	}
	db_connectTimeout = CreateTimer(10.0, db_closeConnect, _, TIMER_REPEAT);
	return status;
}


/**
 * 快速执行壹个sql，返回执行结果 true | false
 *
 */
bool:db_fastBigQuery(const String:sSql[], any:...)
{
	if(db_connectTimeout != INVALID_HANDLE)
	{
		KillTimer(db_connectTimeout);
		db_connectTimeout = INVALID_HANDLE;
	}

	decl String:sql[4096];
	decl String:error[4096];

	VFormat(sql, sizeof(sql), sSql, 2);

	// 数据库意外断开后重连，确保数据库已连接
	if( db == INVALID_HANDLE ) {
		db_connect();
		if( db_debug )
		{
			LogToFileEx(db_log, "执行[sql:%s]时，发现数据库已意外断开，正在进行重连...", sql);
		}
		if(db == INVALID_HANDLE)
			return false;
	}
	// 设置编码
	SQL_FastQuery(db , "SET NAMES 'utf8'");
	// 执行sql
	new bool:status = SQL_FastQuery(db, sql);
	// 调试模式将输出所有sql语句及错误
	if( db_debug ) {
		LogToFileEx(db_log, "[sql]%s", sql);
		if( !status ) {
			SQL_GetError(db, error, sizeof(error));
			LogToFileEx(db_sql_error_log, "[error]%s (sql:%s)", error, sql);
		}
	}
	db_connectTimeout = CreateTimer(10.0, db_closeConnect, _, TIMER_REPEAT);
	return status;
}

// 断开连接
public Action:db_closeConnect(Handle:Timer, any:arg)
{
	KillTimer(Timer);
	db_connectTimeout = INVALID_HANDLE;

	CloseHandle(db);
	db = INVALID_HANDLE;
}

// db连接异常服务器重启倒计时
public Action:ServerRestart(Handle:Timer, any:arg)
{
	if(db_e_restart > 0)
	{
		CPrintToChatAll("插件异常，%d秒后将自动重启服务器！", db_e_restart);
		// LogMessage("插件异常，%d秒后将自动重启服务器！", db_e_restart);
		db_e_restart--;
	}
	else
	{
		ServerCommand("exit");
	}
}