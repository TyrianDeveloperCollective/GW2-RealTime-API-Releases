///----------------------------------------------------------------------------------------------------
/// Copyright (c) Raidcore.GG - All rights reserved.
///
/// Name         :  RTAPI.h
/// Description  :  Definitions for public-facing real-time API.
/// Authors      :  K. Bieniek
///----------------------------------------------------------------------------------------------------

#ifndef RTAPI_DEFINITIONS_H
#define RTAPI_DEFINITIONS_H

#define RTAPI_DATALINK "DL_RTAPI"

#include <cstdint>

namespace RTAPI
{
#ifdef __cplusplus
	///----------------------------------------------------------------------------------------------------
	/// EGameState Enumeration
	///----------------------------------------------------------------------------------------------------
	enum class EGameState : uint32_t
	{
		CharacterSelection,
		CharacterCreation,
		Cinematic,
		LoadingScreen,
		Gameplay
	};
#else
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
#endif

#ifdef __cplusplus
	///----------------------------------------------------------------------------------------------------
	/// EGameLanguage Enumeration
	///----------------------------------------------------------------------------------------------------
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
#endif

#ifdef __cplusplus
	///----------------------------------------------------------------------------------------------------
	/// ETimeOfDay Enumeration
	///----------------------------------------------------------------------------------------------------
	enum class ETimeOfDay : uint32_t
	{
		Dawn,
		Day,
		Dusk,
		Night
	};
#else
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
#endif

#ifdef __cplusplus
	///----------------------------------------------------------------------------------------------------
	/// ECharacterState Enumeration
	///----------------------------------------------------------------------------------------------------
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
#endif

#ifdef DEFINE_ENUM_FLAG_OPERATORS
DEFINE_ENUM_FLAG_OPERATORS(ECharacterState)
#endif

#ifdef __cplusplus
	///----------------------------------------------------------------------------------------------------
	/// EMapType Enumeration
	///----------------------------------------------------------------------------------------------------
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
#endif

	///----------------------------------------------------------------------------------------------------
	/// GroupMember Struct
	///----------------------------------------------------------------------------------------------------
	typedef struct GroupMember
	{
		char    AccountName[32];
		char    CharacterName[20];
		int32_t Subgroup;
		int32_t Profession;          // -1 = Unknown, 0-9 = Profession
		int32_t EliteSpecialization; // -1 = Unknown, value is id of elite spec
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

		/* Player Data */
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
		uint32_t        IsActionCamera;
	} RealTimeData;
}

#endif
