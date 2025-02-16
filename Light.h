#ifndef HEADERS_ENTITIES_LIGHT_H_
#define HEADERS_ENTITIES_LIGHT_H_

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "uniform.h"
#include "Primitive.h"

class Light: public Primitive {
private:
	Primitive* object;
public:
	Light(Primitive* object) : Primitive(*object) {
		this->object = object;
	};
	inline ~Light() { delete object; }
};

#endif // !HEADERS_ENTITIES_LIGHT_H_