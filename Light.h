#ifndef HEADERS_ENTITIES_LIGHT_H_
#define HEADERS_ENTITIES_LIGHT_H_

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <type_traits>
#include "uniform.h"
#include "Primitive.h"
#include "Cube.h"
#include "Sphere.h"

template <class T>
class Light: public Primitive {
private:
	static_assert(std::is_base_of<Primitive, T>::value, "T is not derived from Primitive");
	glm::vec3 color;
public:
	Light(glm::vec3& color) : Primitive(T(color)) {
		this->color = color;
	};

	inline glm::vec3 GetColor() { return color; }
};

#endif // !HEADERS_ENTITIES_LIGHT_H_