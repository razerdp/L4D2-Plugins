
/*****************************************************************************/

/*Author	= MicroLeo , Idea by UnitedRPG_V3.65 */

/*****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */
 
GetRandomSignature(String:buffer[], maxlen)
{
	//数字			48-57
	//大写LOWER 	65-90 
	//小写UPPER		97-122 
	
	for(new i=0;i<maxlen-1;i++)
	{
		switch(GetRandomInt(0,1))
		{
			case 0:
			{
				buffer[i] = GetRandomInt(48,57);
			}
			case 1:
			{
				switch(GetRandomInt(0,1))
				{
					case 0:
					{
						buffer[i] = GetRandomInt(65,90);
					}
					case 1:
					{
						buffer[i] = GetRandomInt(97,122);
					}
				}
			}
		}
	}
	
	DateSequence(buffer,maxlen);
}

//cdkey时间序列化,降低生成相同cdkey机率
DateSequence(String:cdkey[], maxlen)
{
	new thisyear = ThisYear();
	new month = ThisMonth();
	new today = ToDay();
	thisyear = thisyear>25 ? GetRandomInt(65,90) : 90-thisyear;
	month = month==11 ? GetRandomInt(65,77) : month==12 ? GetRandomInt(77,90) : 57-month+1; 
	today = today>26 ? GetRandomInt(97,122) : 122-today;
	
	cdkey[0] = today;
	new const index = maxlen/2;
	cdkey[index] = month;
	if(cdkey[index+1])
	{
		cdkey[index+1] = thisyear;
	}
}

ThisYear()
{
	new String:text[32];
	FormatTime(text, sizeof(text), "%y");
	new year = StringToInt(text);
	return year;
}

ThisMonth()
{
	new String:text[32];
	FormatTime(text, sizeof(text), "%m");
	new month = StringToInt(text);
	return month;
}

ToDay()
{
	new String:text[32];
	FormatTime(text, sizeof(text), "%d");
	new time = StringToInt(text);
	return time;
}

bool:IsInvalidSignature(const String:buffer[])
{
	for(new i=0;i<strlen(buffer);i++)
	{
		if(buffer[i]<48 || buffer[i]>57&&buffer[i]<65 || buffer[i]>90&&buffer[i]<97 || buffer[i]>122)
		{
			return true;
		}
	}
	return false;
}

