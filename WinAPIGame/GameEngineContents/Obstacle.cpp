#include "Obstacle.h"


std::vector<Obstacle*> Obstacle::AllObstacle;


Obstacle::Obstacle() 
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::Init(float4 _Pos)
{
	SetPos(_Pos);
}

