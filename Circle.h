#ifndef HEADERS_PRIMITIVES_CIRCLE_H_
#define HEADERS_PRIMITIVES_CIRCLE_H_

#define _USE_MATH_DEFINES

#include <math.h>
#include "Primitive.h"

class Circle : public Primitive {
private:
public:
    Circle(glm::vec3 color = glm::vec3(0.5f, 0.5f, 0.5f)) : Primitive() {
        preferableDrawType = DRAW_TYPE_ELEMENT;

        std::vector<Vertex> v;

        float radius = 0.5f;
        int segmentCount = 80;
        float twicePi = 2 * (float)M_PI;


        v.push_back({
            glm::vec3(0.f, 0.f, 0.f),
            color,
            glm::vec2(0.f, 0.f),
            glm::vec3(0.f, 0.f, 1.f),
        });
        float x, y;
        for (int i = 0; i <= segmentCount; i++) {
            x = radius * cos(i * twicePi / segmentCount);
            y = radius * sin(i * twicePi / segmentCount);
            v.push_back({
                glm::vec3(x, y, 0.f),
                color,
                glm::vec2(0.f, 0.f),
                glm::vec3(0.f, 0.f, 1.f),
            });
        }

        v.push_back({
            glm::vec3(0.f, 0.f, 0.f),
            color,
            glm::vec2(0.f, 0.f),
            glm::vec3(0.f, 0.f, -1.f),
        });
        for (int i = 0; i <= segmentCount; i++) {
            x = radius * cos(i * twicePi / segmentCount);
            y = radius * sin(i * twicePi / segmentCount);
            v.push_back({
                glm::vec3(x, y, 0.f),
                color,
                glm::vec2(0.f, 0.f),
                glm::vec3(0.f, 0.f, -1.f),
            });
        }

        std::vector<GLuint> ind;
        for (GLuint i = 1; i < (v.size() - 2) / 2; i++) {
            ind.push_back(i);
            ind.push_back(i + 1);
            ind.push_back(0);
        }
        for (GLuint i = (v.size() - 2) / 2; i < v.size() - 1; i++) {
            ind.push_back(i + 1);
            ind.push_back(i);
            ind.push_back(segmentCount+2);
        }

        setInitial(v, ind);
    }
};

#endif // !HEADERS_PRIMITIVES_CIRCLE_H_