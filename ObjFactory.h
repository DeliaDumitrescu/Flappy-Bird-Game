#ifndef OBJF_H
#define OBJF_H

#include <SFML/Graphics.hpp>
#include "Objects.h"
#include "Bird.h"
#include "Pipes.h"
#include "Text.h"

class ObjectFactory
{
public:
	Object* Create(const char objName[])
	{
		if (objName == "bird") return new Bird;
		else if (objName == "pipe") return new Pipe;
		else if (objName == "text") return new Text;
		/// else -> pe mai tarziu
	}
};

#endif