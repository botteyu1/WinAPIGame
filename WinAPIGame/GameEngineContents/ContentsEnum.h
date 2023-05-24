#pragma once

enum class UpdateOrder
{
	Player,
	Monster,
};

enum class RenderOrder
{
	BackGround,
	Obstacle,
	Play,
	PlayUI,
};

#define TILESIZE 100.0f