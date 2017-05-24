#pragma once
class entity
{
public:
	entity();
	~entity();

	void setActive(bool bActive);
	bool getActive();

private:
	bool m_bActive;

};

