///----------------------------------------------------------------------------------------------------
/// Copyright (c) Raidcore.GG - All rights reserved.
///
/// Name         :  RTAPI.h
/// Description  :  Definitions for public-facing real-time API.
/// Authors      :  K. Bieniek
///----------------------------------------------------------------------------------------------------

#ifndef RTAPI_DEFINITIONS_H
#define RTAPI_DEFINITIONS_H

#define DL_RTAPI                      "RTAPI"
#define EV_RTAPI_GROUP_MEMBER_JOINED  "RTAPI_GROUP_MEMBER_JOINED"
#define EV_RTAPI_GROUP_MEMBER_LEFT    "RTAPI_GROUP_MEMBER_LEFT"
#define EV_RTAPI_GROUP_MEMBER_UPDATED "RTAPI_GROUP_MEMBER_UPDATED"

#include <cstdint>

namespace RTAPI
{
	///----------------------------------------------------------------------------------------------------
	/// EGameState Enumeration
	///----------------------------------------------------------------------------------------------------
#ifdef __cplusplus
	enum class EGameState : uint32_t
	{
		CharacterSelection,
		CharacterCreation,
		Cinematic,
		LoadingScreen,
		Gameplay
	};
#else
	enum EGameState
	{
		GS_CharacterSelection,
		GS_CharacterCreation,
		GS_Cinematic,
		GS_LoadingScreen,
		GS_Gameplay
	};
#endif

	///----------------------------------------------------------------------------------------------------
	/// EGameLanguage Enumeration
	///----------------------------------------------------------------------------------------------------
#ifdef __cplusplus
	enum class EGameLanguage : uint32_t
	{
		English,
		Korean,
		French,
		German,
		Spanish,
		Chinese
	};
#else
	enum EGameLanguage
	{
		GL_English,
		GL_Korean,
		GL_French,
		GL_German,
		GL_Spanish,
		GL_Chinese
	};
#endif

	///----------------------------------------------------------------------------------------------------
	/// ETimeOfDay Enumeration
	///----------------------------------------------------------------------------------------------------
#ifdef __cplusplus
	enum class ETimeOfDay : uint32_t
	{
		Dawn,
		Day,
		Dusk,
		Night
	};
#else
	enum ETimeOfDay
	{
		TOD_Dawn,
		TOD_Day,
		TOD_Dusk,
		TOD_Night
	};
#endif

	///----------------------------------------------------------------------------------------------------
	/// ECharacterState Enumeration
	///----------------------------------------------------------------------------------------------------
#ifdef __cplusplus
	enum class ECharacterState : uint32_t
	{
		IsAlive      = 1 << 0,
		IsDowned     = 1 << 1,
		IsInCombat   = 1 << 2,
		IsSwimming   = 1 << 3, // aka. Is on water surface
		IsUnderwater = 1 << 4, // aka. Is diving
		IsGliding    = 1 << 5,
		IsFlying     = 1 << 6
	};
#else
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
#endif

	///----------------------------------------------------------------------------------------------------
	/// EMapType Enumeration
	///----------------------------------------------------------------------------------------------------
#ifdef __cplusplus
	enum class EMapType : uint32_t
	{
		AutoRedirect,
		CharacterCreation,
		PvP,
		GvG,
		Instance,
		Public,
		Tournament,
		Tutorial,
		UserTournament,
		WvW_EternalBattlegrounds,
		WvW_BlueBorderlands,
		WvW_GreenBorderlands,
		WvW_RedBorderlands,
		WVW_FortunesVale,
		WvW_ObsidianSanctum,
		WvW_EdgeOfTheMists,
		Public_Mini,
		BigBattle,
		WvW_Lounge
	};
#else
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
#endif

	///----------------------------------------------------------------------------------------------------
	/// EGroupType Enumeration
	///----------------------------------------------------------------------------------------------------
#ifdef __cplusplus
	enum class EGroupType : uint32_t
	{
		None,
		Party,
		RaidSquad,
		Squad
	};
#else
	enum EGroupType
	{
		GT_None,
		GT_Party,
		GT_RaidSquad,
		GT_Squad
	};
#endif

	///----------------------------------------------------------------------------------------------------
	/// GroupMember Struct
	///----------------------------------------------------------------------------------------------------
	typedef struct GroupMember
	{
		char     AccountName[32];
		char     CharacterName[20];
		int32_t  Subgroup;            // 0 for parties, 1-15 according to the squad's subgroup
		int32_t  Profession;          // 0-9 = Profession; -1 Unknown -> e.g. on loading screen or logged out
		int32_t  EliteSpecialization; // Third Spec ID, not necessarily elite; or -1 Unknown -> e.g. on loading screen or logged out
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
		int32_t         GameBuild;
#ifdef __cplusplus
		EGameState      GameState;
		EGameLanguage   Language;
#else
		uint32_t        GameState;
		uint32_t        Language;
#endif

		/* Instance/World Data */
#ifdef __cplusplus
		ETimeOfDay      TimeOfDay;
#else
		uint32_t        TimeOfDay;
#endif
		int32_t         MapID;
#ifdef __cplusplus
		EMapType        MapType;
#else
		uint32_t        MapType;
#endif
		char            IPAddress[4];
		float           Cursor[3];          // Location of cursor in the world
		float           SquadMarkers[8][3]; // Locations of squad markers
#ifdef __cplusplus
		EGroupType      GroupType;
#else
		uint32_t        GroupType;
#endif
		uint32_t        GroupMemberCount;
		uint32_t        RESERVED2;

		/* Player Data */
		uint32_t        RESERVED1;
		char            AccountName[32];
		char            CharacterName[20];
		float           CharacterPosition[3];
		float           CharacterFacing[3];
		int32_t         Profession;
		int32_t         EliteSpecialization;
		int32_t         MountIndex;
#ifdef __cplusplus
		ECharacterState CharacterState;
#else
		uint32_t        CharacterState;
#endif

		/* Camera Data */
		float           CameraPosition[3];
		float           CameraFacing[3];
		float           CameraFOV;
		uint32_t        IsActionCamera : 1;
	} RealTimeData;
}

#endif
