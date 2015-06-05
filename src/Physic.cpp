#include "Physic.h"

Physic::Physic(float masse, float gravityInfluance) : Componant()
{
	this->masse = masse;
	this->gravityInfluance = gravityInfluance;
}

Physic::~Physic()
{

}
