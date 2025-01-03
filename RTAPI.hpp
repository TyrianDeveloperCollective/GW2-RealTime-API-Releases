///----------------------------------------------------------------------------------------------------
/// Copyright (c) Raidcore.GG - Licensed under the MIT license.
///
/// Name         :  RTAPI.hpp
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
/// RTAPI Namespace
///----------------------------------------------------------------------------------------------------
namespace RTAPI
{
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

	///----------------------------------------------------------------------------------------------------
	/// EGroupType Enumeration
	///----------------------------------------------------------------------------------------------------
	enum class EGroupType : uint32_t
	{
		None,
		Party,
		RaidSquad,
		Squad
	};

	///----------------------------------------------------------------------------------------------------
	/// GroupMember Struct
	///----------------------------------------------------------------------------------------------------
	struct GroupMember
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
	};

	///----------------------------------------------------------------------------------------------------
	/// RealTimeData Struct
	///----------------------------------------------------------------------------------------------------
	struct RealTimeData
	{
		/* Game Data */
		uint32_t        GameBuild; // Set to 0 when RTAPI is unloaded.
		EGameState      GameState;
		EGameLanguage   Language;
		/* Instance/World Data */
		ETimeOfDay      TimeOfDay;
		uint32_t        MapID;
		EMapType        MapType;
		uint8_t         IPAddress[4];
		float           Cursor[3];          // Location of cursor in the world
		float           SquadMarkers[8][3]; // Locations of squad markers
		EGroupType      GroupType;
		uint32_t        GroupMemberCount;
		uint32_t        RESERVED2;

		/* Player Data */
		uint32_t        RESERVED1;
		char            AccountName[140];
		char            CharacterName[140];
		float           CharacterPosition[3];
		float           CharacterFacing[3];
		uint32_t        Profession;
		uint32_t        EliteSpecialization;
		uint32_t        MountIndex;
		ECharacterState CharacterState;

		/* Camera Data */
		float           CameraPosition[3];
		float           CameraFacing[3];
		float           CameraFOV;
		uint32_t        IsActionCamera : 1;
	};
}

#endif
