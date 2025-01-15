///----------------------------------------------------------------------------------------------------
/// Copyright (c) Raidcore.GG - All rights reserved.
///
/// Name         :  Definitions.h
/// Description  :  Definitions for public-facing real-time API.
/// Authors      :  K. Bieniek
///----------------------------------------------------------------------------------------------------

#ifndef RTAPI_DEFINITIONS_H
#define RTAPI_DEFINITIONS_H

#define RTAPI_VERSION 1

#include <cstdint>

enum class EGameState : uint32_t
{
	CharacterSelection,
	CharacterCreation,
	Cinematic,
	LoadingScreen,
	Gameplay
};

enum class ELanguage : uint32_t
{

};

struct GameData
{
	int        Build;
	EGameState State;
	ELanguage  Language;
};

enum class ETime : uint32_t
{
	Dawn,
	Day,
	Dusk,
	Night
};

struct WorldData
{
	float Cursor[3]; // The position in the world where the cursor is hovered over.
	ETime TimeOfDay;
};

struct CharacterData
{
	char  AccountName[32];
	char  CharacterName[20];
	float Position[3];
	float Facing[3];
	int   IsAlive   : 1;
	int   IsDowned  : 1;
	int   IsInWater : 1;
	int   IsGliding : 1;
};

struct CameraData
{
	float Position[3];
	float Facing[3];
	float FOV;
	int   IsActionCamera : 1;
	int   IsControlled   : 1;
};

enum class ESquadRole : uint32_t
{
	Member,
	Lieutenant,
	Commander
};

struct SquadMember
{
	char       AccountName[32];
	char       CharacterName[20];
	int        Subgroup;
	ESquadRole Role;
	int        Profession;
	int        EliteSpecialization;
};

enum class EGroupType : uint32_t
{
	Party,
	RaidSquad,
	Squad
};

struct GroupData
{
	float       Markers[8][3];
	int         MembersCount; // Members is only filled until count is matched and are sorted by subgroup.
	SquadMember Members[50];
};

struct RealTimeData
{
	GameData      Game;
	WorldData     World;
	CharacterData Character;
	CameraData    Camera;
	GroupData     Group; // Party / Squad
};

#endif
