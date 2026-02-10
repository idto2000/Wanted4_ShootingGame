#include "Item.h"
#include "Engine/Engine.h"
#include "Level/Level.h"
#include "Util/Util.h"


Item::Item(const char* image, int xPosition, float speed) : super(image)
{
	
	// 화면의 가로 너비 측정.
	int screenWight = Engine::Get().GetWidth();

	int minX = 0;
	int maxX = screenWight - width - 1;

	//예외처리 
	if (maxX < minX)
	{
		maxX = minX;
	}

	//측정된 너비에서 랜덤하게 위치 선정
	int randomX = static_cast<int>(Util::Random(minX, maxX));

	// 변수 초기화
	this->moveSpeed = speed;

	//위치 적용 및 속도 초기화 
	this->xReal = static_cast<float>(randomX);
	this->yReal = 0.0f;

	//변수 동기화 유지
	this->xPosition = this->xReal;
	this->yPosition = this->yReal;
	
	//아이템 위치 설정
	SetPosition(Vector2(randomX, 0));

	//칼라 적용
	color = Color::Green;
}

Item::~Item()
{
}

void Item::Tick(float deltaTime)
{
	yReal += moveSpeed * deltaTime;

	xPosition = xReal;
	yPosition = yReal;

	// 화면 하단 이탈 검사
	if (position.y >= Engine::Get().GetHeight())
	{
		Destroy();
	}	

	SetPosition(Vector2(static_cast<int>(xReal), static_cast<int>(yReal)));
}

void Item::TackeDamaged()
{
	// 액터 제거.
	Destroy();
}
