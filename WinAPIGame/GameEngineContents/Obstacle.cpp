#include "Obstacle.h"
#include "TileMap.h"


//std::vector<Obstacle*> Obstacle::AllObstacle;


Obstacle::Obstacle() 
{
}

Obstacle::~Obstacle()
{
}



void Obstacle::Init(float4 _TilePos, int _Custom)
{
	int X =_TilePos.iX();
	int Y =_TilePos.iY();

	SetPos(TileMap::GetLevelTileMap()->GetTilePos(X, Y));
	SetTilePos(X, Y);

	ChanageState(ObstacleState::Idle);
}

void Obstacle::Update(float _Delta)
{
	StateUpdate(_Delta);
}

void Obstacle::ChanageState(ObstacleState _State)
{

	if (_State != State)
	{
		switch (_State)
		{
		case ObstacleState::Idle:
			IdleStart();
			break;
		case ObstacleState::Move:
			MoveStart();
			break;
		case ObstacleState::Death:
			DeathStart();
			break;
		case ObstacleState::Attack:
			AttackStart();
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
	case ObstacleState::Attack:
		AttackUpdate(_Delta);
		break;
	case ObstacleState::Max:
		break;
	default:
		break;
	}
}




