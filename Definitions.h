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

enum class EGameState
{
	CharacterSelection,
	CharacterCreation,
	Cinematic,
	LoadingScreen,
	Gameplay
};

enum class ELanguage
{

};

struct GameData
{
	int        Build;
	EGameState State;
	ELanguage  Language;
};

enum class ETime
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

enum class ECharState
{
	None,
	Alive,
	Downed,
	InWater,
	Gliding
};

struct CharacterData
{
	char       AccountName[32];
	char       CharacterName[20];
	float      Position[3];
	float      Facing[3];
	ECharState State;

	//BuildInfo ? // spec, traits, weapons
	//Gear / Build Template ? // name? everything?
	//TargetingSettings ?
	//SelfStats ?
};

struct CameraData
{
	float Position[3];
	float Facing[3];
	float FOV;
	bool  IsActionCamera;
	bool  IsControlled;
};

struct SquadMember
{
	char AccountName[32];
	char CharacterName[20];
	int  Subgroup;
	// role (leader, lieutenant, member, invited, etc)
	// profession
	// elitespec
};

struct SquadData
{
	float       Markers[8][3];
	int         MembersCount;  // Members is only filled until count is matched
	SquadMember Members[50];
};

struct RealTimeData
{
	GameData      Game;
	WorldData     World;
	CharacterData Character;
	CameraData    Camera;
	SquadData     Squad;
};

#endif
