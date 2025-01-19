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
	int32_t    Build;
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
	float   Cursor[3]; // The position in the world where the cursor is hovered over.
	ETime   TimeOfDay;
	int32_t MapID;
	int32_t MapType;
	char    IPAddress[4];
};

struct CharacterData
{
	char    AccountName[32];
	char    CharacterName[20];
	float   Position[3];
	float   Facing[3];
	int32_t Profession;
	int32_t EliteSpecialization;
	int32_t MountIndex;
	int32_t IsAlive   : 1;
	int32_t IsDowned  : 1;
	int32_t IsInWater : 1;
	int32_t IsGliding : 1;
};

struct CameraData
{
	float   Position[3];
	float   Facing[3];
	float   FOV;
};

struct SquadMember
{
	char       AccountName[32];
	char       CharacterName[20];
	int32_t    Subgroup;
	int32_t    Profession;
	int32_t    EliteSpecialization;
};

struct GroupData
{
	int32_t     MembersCount;
	float       Markers[8][3];
};

struct RealTimeData
{
	GameData      Game;
	WorldData     World;
	CharacterData Character;
	CameraData    Camera;
	GroupData     Group;
};

#endif
