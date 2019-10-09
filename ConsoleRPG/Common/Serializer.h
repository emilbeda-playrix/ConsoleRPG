#pragma once
#include "commonInc.h"

class Serializer
{
public:
	virtual void Serialize(tinyxml2::XMLElement& elem) = 0;
	virtual void Deserialize(tinyxml2::XMLElement &elem) = 0;
};