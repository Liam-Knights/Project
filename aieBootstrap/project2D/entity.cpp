#include "entity.h"



entity::entity()
{
	m_bActive = false;
}


entity::~entity()
{
}

void entity::setActive(bool bActive)
{
	m_bActive = bActive;
}

bool entity::getActive()
{
	return m_bActive;
}

void entity::updateGlobalTransform(float fDeltaTime)
{

}
void entity::Draw(aie::Renderer2D* m_2dRender)
{

}