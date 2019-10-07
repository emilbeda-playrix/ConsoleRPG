#pragma once
#include "commonInc.h"

class Serializer
{
public:
	virtual void Serialize(TiXmlElement &elem) = 0;
};