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
	PlayUI,
	LevelChange,
};

#define TILESIZE 100.0f