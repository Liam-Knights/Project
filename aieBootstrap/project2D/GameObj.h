#pragma once
#include "entity.h"
#include "ObjectPool.h"
class GameObj :public entity
{
public:
	GameObj();
	~GameObj();


	//function made to program
	void updateGlobalTransform(float fDeltaTime);

	// a basic draw function it is epmty
	void Draw(aie::Renderer2D* m_2dRender);

private:
	int m_timer;
	int colour;
	ObjectPool* m_object;
};

