#ifndef OBJF_H
#define OBJF_H

#include <SFML/Graphics.hpp>
#include "Objects.h"
#include "Bird.h"
#include "Pipes.h"


class ObjectFactory
{
public:
	Object* Create(const char objName[])
	{
		if (objName == "bird") return new Bird;
		else
            return new Pipe;
	}
};

#endif