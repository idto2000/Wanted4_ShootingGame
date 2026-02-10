#include "ItemSpawner.h"
#include "Item.h"
#include "Level/Level.h"
#include "Engine/Engine.h"
#include "Util/Util.h"

static const char* ItemType[] =
{
	"+",
	"-",
	"@",
	"&",
	"%"
};

Wanted::ItemSpawner::ItemSpawner()
{
	// 적 생성 타이머 설정.
	timer.SetTargetTime(Util::RandomRange(2.0f, 3.0f));
}

void Wanted::ItemSpawner::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	SpawnerItem(deltaTime);
}

void Wanted::ItemSpawner::SpawnerItem(float deltaTime)
{
	timer.Tick(deltaTime);

	if (!timer.IsTimeOut())
	{
		return;
	}

	timer.Reset();

	static int length = sizeof(ItemType) / sizeof(ItemType[0]);

	// 랜덤 인덱스.
	int index = Util::Random(0, length - 1);

	// 생성 y 위치.
	int screenWight = Engine::Get().GetWidth();

	// 아이템 길이를 고려하여 여유값 지정
	int xPostion = Util::Random(0, screenWight - 6);

	//하강 속도를 랜덤하게 생성(0.5. ~ 2.5)
	float randomSpeed = Util::RandomRange(0.5f, 3.5f);

	// 아이템 생성 요청
	GetOwner()->AddNewActor(new Item(ItemType[index], xPostion, randomSpeed));
}
