#include "Obstacle.h"


//std::vector<Obstacle*> Obstacle::AllObstacle;


Obstacle::Obstacle() 
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::Init(float4 _Pos, int _TileX, int _TileY)
{
	SetPos(_Pos);
	SetTilePos(_TileX, _TileY);
	
}

void Obstacle::Update(float _Delta)
{
	StateUpdate(_Delta);
}

void Obstacle::ChanageState(float _Delta, ObstacleState _State)
{

	if (_State != State)
	{
		switch (_State)
		{
		case ObstacleState::Idle:
			IdleStart();
			break;
		case ObstacleState::Move:
			MoveStart(_Delta);
			break;
		case ObstacleState::Death:
			DeathStart(_Delta);
			break;
		case ObstacleState::Max:
			break;
		default:
			break;
		}
	}

	State = _State;
}

void Obstacle::StateUpdate(float _Delta)
{
	switch (State)
	{
	case ObstacleState::Idle:
		IdleUpdate(_Delta);
		break;
	case ObstacleState::Move:
		MoveUpdate(_Delta);
		break;
	case ObstacleState::Death:
		DeathUpdate(_Delta);
		break;
	case ObstacleState::Max:
		break;
	default:
		break;
	}
}




