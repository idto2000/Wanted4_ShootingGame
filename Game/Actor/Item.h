#pragma once

#include "Actor/Actor.h"
#include "Util/Timer.h"


using namespace Wanted;

class Item : public Actor
{
	RTTI_DECLARATIONS(Item, Actor)

		// 이동 방향 열거형.
		enum class MoveDirection
	{
		None = -1,
		Left,
		Right
	};

public:

	Item(const char* image = "(-O-)", int xPosition = 0, float speed = 0);
	~Item();
	
	//Tick
	virtual void Tick(float detaTime) override;

	// 플레이어와 충돌했을 때 
	void TackeDamaged();

private:

	//MoveDirection direction = MoveDirection::None;

	float xPosition = 0.0f;
	float yPosition = 0.0f;
	float moveSpeed = 0.0f;

	float yReal = 0.0f;
	float xReal = 0.0f;


};

