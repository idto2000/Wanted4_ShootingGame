#pragma once

#include "Actor/Actor.h"
#include "Util/Timer.h"
#include "Enemy.h"

using namespace Wanted;

class Obstacle:public Actor
{
	RTTI_DECLARATIONS(Obstacle, Actor)
	
		// 이동 방향 열거형.
	enum class MoveDirection
	{
		None = -1,
		Left,
		Right
	};

public:
	Obstacle(const char* image = "(-O-)", int xPosition = 0, float speed = 0);
	~Obstacle();

	// Tick.
	virtual void Tick(float deltaTime) override;

	// 대미지 받았을 때 처리할 함수.
	void TackeDamaged();
	
	// 적 캐릭터와 충돌했을때 처리할 함수.
	void OnCollisionWithEnemy();

	// Player를 추적하는 함수
	void FollowPlayer(float deltaTime, Vector2 PlayerPos);

private:

	// 추적용 위치 저장 
	float xReal = 0.0f;
	float yReal = 0.0f;

	// 시야 범위 측정
	float detection = 20.0f;
	
private:

	MoveDirection direction = MoveDirection::None;

	float xPosition = 0.0f;
	float yPosition = 0.0f;
	float moveSpeed = 0.0f;
};

