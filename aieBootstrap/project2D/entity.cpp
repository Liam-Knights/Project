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