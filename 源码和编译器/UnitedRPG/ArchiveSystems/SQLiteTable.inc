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
 
//SQLite Table
#define	SQLiteDriver	"clientprefs"

#define	AccountTable	"UnitedRPG_UserAccount"
new const String:AccountField[] = 	"Account, PassWord, vLAN_Account, GameName, Admin, SteamID, AccountType, Status, LastLoginTime, LastLoginIP"

#define GameDataTable	"UnitedRPG_PublicGameData"
new const String:GameDataField[] =	"UserID, Account, vLAN_Account, SP, KSP, VIP, VIPTL, VIPYEAR, NewLifeCount, Lv, JD, Cash, XB, StatusPoint, SkillPoint, KTCount, Str, Agi, Health, Endurance, Intelligence, EXP, Info, Skill, Sing, Roobot, Master, Master2, BagData, ItemXH, ItemZB"

#define	CDKeyTable	"UnitedRPG_CDKey"
new const String:CDKeyField[] = 	"CDKey, InValid, ExchangeXB, BindAccount, Beneficiary, CDKeySpawnedTime, CDKeyUsedTime"