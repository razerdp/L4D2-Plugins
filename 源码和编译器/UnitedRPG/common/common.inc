#include "UnitedRPG/common/dbi.inc"
/************************************** 数组序列化及反序列化 ***************************************/
Implode(const array[], maxSize, const String:join[], String:buffer[], maxLength)
{
	new total = 0, length = 0, part_length = 0, String:_strings[128] = "";
	new join_length = strlen(join);
	for (new i=0; i<maxSize; i++)
	{
		new _num = array[i];
		IntToString(_num, _strings, sizeof(_strings));
		length = strcopy(buffer[total], maxLength-total, _strings);
		total += length;
		if (length < part_length)
		{
			break;
		}
		if (i != maxSize - 1)
		{
			length = strcopy(buffer[total], maxLength-total, join);
			total += length;
			if (length < join_length)
			{
				break;
			}
		}
	}
	return total;
}

Explode(const String:text[], const String:split[], buffers[], maxNum, bool:copyRemainder = false)
{
	new reloc_idx = 0, idx = 0, total = 0, String:_strings[128] = "";

	if (maxNum < 1 || !split[0])
	{
		return 0;
	}

	while ((idx = SplitString(text[reloc_idx], split, _strings, sizeof(_strings))) != -1)
	{
		buffers[total] = StringToInt(_strings);
		reloc_idx += idx;
		if (++total == maxNum)
		{
			if (copyRemainder)
			{
				strcopy(_strings, sizeof(_strings), text[reloc_idx-idx]);
				buffers[total-1] = StringToInt(_strings);
			}
			return total;
		}
	}

	strcopy(_strings, sizeof(_strings), text[reloc_idx]);
	buffers[total++] = StringToInt(_strings);

	return total;
}

/************************************** 数据过滤 ***************************************/

// 过滤字符串
stock GetFilterString(String:buffer[], maxLength, const String:text[])
{
	strcopy(buffer, maxLength, text);
	/* 取代玩家姓名中会导致错误的符号 */
	ReplaceString(buffer, maxLength, "\034", "{DQM}");//DQM Double quotation mark  \034 by MicroLeo
	ReplaceString(buffer, maxLength, "\'", "{SQM}");//SQM Single quotation mark
	ReplaceString(buffer, maxLength, "/*", "{SST}");//SST Slash Star
	ReplaceString(buffer, maxLength, "*/", "{STS}");//STS Star Slash
	ReplaceString(buffer, maxLength, "//", "{DSL}");//DSL Double Slash
	ReplaceString(buffer, maxLength, "\\", "{DSS}");
}

// [反向] 过滤字符串 [将过滤好的字符串转回普通字符串]
stock GetUnFilterString(String:buffer[], maxLength, const String:text[])
{
	strcopy(buffer, maxLength, text);
	/* 取代玩家姓名中会导致错误的符号 */
	ReplaceString(buffer, maxLength, "{DQM}", "\034");//DQM Double quotation mark	\034 by MicroLeo
	ReplaceString(buffer, maxLength, "{SQM}", "\'");//SQM Single quotation mark
	ReplaceString(buffer, maxLength, "{SST}", "/*");//SST Slash Star
	ReplaceString(buffer, maxLength, "{STS}", "*/");//STS Star Slash
	ReplaceString(buffer, maxLength, "{DSL}", "//");//DSL Double Slash
	ReplaceString(buffer, maxLength, "{DSS}", "\\");
}

/******************* 数据库存操作时必须使用以下方法[强制] ********************/

// 安全的获取用户名称
stock SafeGetClientName(Client, String:buffer[], maxLength = MAX_NAME_LENGTH)
{
	GetClientName(Client, buffer, maxLength);
	GetFilterString(buffer, maxLength, buffer);
}

// 安全返回用户名
stock String:SafeReturnClientName(Client)
{
	decl String:username[256];
	SafeGetClientName(Client, username);
	return username;
}

// 返回过滤好的字符串
stock String:ReturnFilterString(const String:text[])
{
	new String:result[1024];
	GetFilterString(result, sizeof(result), text);
	return result;
}

// 返回 [反] 过滤字符串
stock String:ReturnUnFilterString(const String:text[])
{
	decl String:result[1024];
	GetUnFilterString(result, sizeof(result), text);
	return result;
}

// 最小值，最大值，是否包括最小和最大
stock bool:IsBetween(min, max, num, include = true)
{
	if(include)
		if(num < min || num > max) return false;
	else
		if(num <= min || num >= max) return false;
	return true;
}

/**
 * 背包数据反序列化
 * @auther zhangnan
 * @param array data 背包数据
 * @param buffer 序列化后的字符串,大小不应该超过255字符
 * 注意：如果背包格数由大变小了，则会丢失用户背包格数外的数据
 */
stock bool:GetPlayerBag(const String:data[], buffer[][])
{
	if(strlen(data) < 1)
	{
		return false;
	}

	decl String:_buffer[5][254], maxlength;
	maxlength = sizeof(_buffer);

	ExplodeString(data, "|", _buffer, maxlength, sizeof(_buffer[]));

	for(new i = 0; i < maxlength; i++)
	{
		Explode(_buffer[i], ",", buffer[i], BagMax[i]);
	}
	return true;
}

/**
 * 背包数据序列化
 * @auther zhangnan
 * @param array data 背包数据
 * @param buffer 序列化后的字符串,大小不应该超过255字符
 * 注意：如果背包格数由大变小了，则会丢失用户背包格数外的数据
 */
stock bool:SetPlayerBag(const data[][], String:buffer[], maxLength)
{
	decl String:_buffer[5][254], maxlength;
	maxlength = sizeof(_buffer);

	for(new i = 0; i < maxlength; i++)
	{
		Implode(data[i], BagMax[i], ",", _buffer[i], sizeof(_buffer[]));
	}

	ImplodeStrings(_buffer, maxlength, "|", buffer, maxLength);
	return true;
}