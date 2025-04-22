///----------------------------------------------------------------------------------------------------
/// Copyright (c) Raidcore.GG - Licensed under the MIT license.
///
/// Name         :  RTAPI.h
/// Description  :  Definitions for public-facing real-time API.
/// Authors      :  K. Bieniek
///----------------------------------------------------------------------------------------------------

#ifndef RTAPI_H
#define RTAPI_H

#define RTAPI_SIG                     0x2501A02C
#define DL_RTAPI                      "RTAPI"                      // DataLink is RealTimeData struct
#define EV_RTAPI_GROUP_MEMBER_JOINED  "RTAPI_GROUP_MEMBER_JOINED"  // Payload is RTAPI::GroupMember*
#define EV_RTAPI_GROUP_MEMBER_LEFT    "RTAPI_GROUP_MEMBER_LEFT"    // Payload is RTAPI::GroupMember*
#define EV_RTAPI_GROUP_MEMBER_UPDATED "RTAPI_GROUP_MEMBER_UPDATED" // Payload is RTAPI::GroupMember*

#include <cstdint>

///----------------------------------------------------------------------------------------------------
/// EGameState Enumeration
///----------------------------------------------------------------------------------------------------
enum EGameState
{
	GS_CharacterSelection,
	GS_CharacterCreation,
	GS_Cinematic,
	GS_LoadingScreen,
	GS_Gameplay
};

///----------------------------------------------------------------------------------------------------
/// EGameLanguage Enumeration
///----------------------------------------------------------------------------------------------------
enum EGameLanguage
{
	GL_English,
	GL_Korean,
	GL_French,
	GL_German,
	GL_Spanish,
	GL_Chinese
};

///----------------------------------------------------------------------------------------------------
/// ETimeOfDay Enumeration
///----------------------------------------------------------------------------------------------------
enum ETimeOfDay
{
	TOD_Dawn,
	TOD_Day,
	TOD_Dusk,
	TOD_Night
};

///----------------------------------------------------------------------------------------------------
/// ECharacterState Enumeration
///----------------------------------------------------------------------------------------------------
enum ECharacterState
{
	CS_IsAlive      = 1 << 0,
	CS_IsDowned     = 1 << 1,
	CS_IsInCombat   = 1 << 2,
	CS_IsSwimming   = 1 << 3, // aka. Is on water surface
	CS_IsUnderwater = 1 << 4, // aka. Is diving
	CS_IsGliding    = 1 << 5,
	CS_IsFlying     = 1 << 6
};

///----------------------------------------------------------------------------------------------------
/// EMapType Enumeration
///----------------------------------------------------------------------------------------------------
enum EMapType
{
	MT_AutoRedirect,
	MT_CharacterCreation,
	MT_PvP,
	MT_GvG,
	MT_Instance,
	MT_Public,
	MT_Tournament,
	MT_Tutorial,
	MT_UserTournament,
	MT_WvW_EternalBattlegrounds,
	MT_WvW_BlueBorderlands,
	MT_WvW_GreenBorderlands,
	MT_WvW_RedBorderlands,
	MT_WVW_FortunesVale,
	MT_WvW_ObsidianSanctum,
	MT_WvW_EdgeOfTheMists,
	MT_Public_Mini,
	MT_BigBattle,
	MT_WvW_Lounge
};

///----------------------------------------------------------------------------------------------------
/// EGroupType Enumeration
///----------------------------------------------------------------------------------------------------
enum EGroupType
{
	GT_None,
	GT_Party,
	GT_RaidSquad,
	GT_Squad
};

///----------------------------------------------------------------------------------------------------
/// GroupMember Struct
///----------------------------------------------------------------------------------------------------
typedef struct GroupMember
{
	char     AccountName[140];
	char     CharacterName[140];
	uint32_t Subgroup;            // 0 for parties, 1-15 according to the squad's subgroup
	uint32_t Profession;          // 1-9 = Profession; 0 Unknown -> e.g. on loading screen or logged out
	uint32_t EliteSpecialization; // Third Spec ID, not necessarily elite; or 0 Unknown -> e.g. on loading screen or logged out
	uint32_t IsSelf       : 1;
	uint32_t IsInInstance : 1;    // Is in the same map instance as the player.
	uint32_t IsCommander  : 1;
	uint32_t IsLieutenant : 1;
} GroupMember;

///----------------------------------------------------------------------------------------------------
/// RealTimeData Struct
///----------------------------------------------------------------------------------------------------
typedef struct RealTimeData
{
	/* Game Data */
	uint32_t GameBuild; // Set to 0 when RTAPI is unloaded.
	uint32_t GameState;
	uint32_t Language;

	/* Instance/World Data */
	uint32_t TimeOfDay;
	uint32_t MapID;
	uint32_t MapType;
	uint8_t  IPAddress[4];
	float    Cursor[3];          // Location of cursor in the world
	float    SquadMarkers[8][3]; // Locations of squad markers
	uint32_t GroupType;
	uint32_t GroupMemberCount;
	uint32_t RESERVED2;

	/* Player Data */
	uint32_t RESERVED1;
	char     AccountName[140];
	char     CharacterName[140];
	float    CharacterPosition[3];
	float    CharacterFacing[3];
	uint32_t Profession;
	uint32_t EliteSpecialization;
	uint32_t MountIndex;
	uint32_t CharacterState;

	/* Camera Data */
	float    CameraPosition[3];
	float    CameraFacing[3];
	float    CameraFOV;
	uint32_t IsActionCamera : 1;
} RealTimeData;

#endif
