#pragma once

enum class UpdateOrder
{
	Player,
	Monster,
};

enum class RenderOrder
{
	BackGround,
	Trap,
	Obstacle,
	Play,
	UI,
	LevelChange,
};

#define TILESIZE 100.0f