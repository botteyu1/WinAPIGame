#pragma once

enum class UpdateOrder
{
	Player,
	Monster,
	PlayerUI,
};

enum class RenderOrder
{
	BackGround,
	BackGroundObject,
	BackGroundObject2,
	VFX,
	Trap,
	Obstacle,
	Play,
	Obstaclefly,
	VFX2,
	UI,
	Dialouge,
	LevelChange,
};

#define TILESIZE 100.0f