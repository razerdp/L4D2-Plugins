/*****************************************************************************/

/*Author	= MicroLeo  */

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
 
new Handle:h_Debug = INVALID_HANDLE;

Debug_RegConVar()
{
	h_Debug = CreateConVar("l4d_SQLiteDebugEnabled", "0", "是否开启SQLite调试模式", FCVAR_PLUGIN|FCVAR_SPONLY|FCVAR_NOTIFY, true, 0.0, true, 1.0);
}


bool:DebugLogPath(String:path[],maxlen)
{
	if(GetConVarBool(h_Debug))
	{
		new String:date[21];
		FormatTime(date, sizeof(date), "%Y%m%d", -1);
		BuildPath(Path_SM, path, maxlen, "logs/SQLiteDebug_%s.log", date);
		return true;
	}
	return false;
}
