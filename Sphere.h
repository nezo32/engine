#ifndef HEADERS_PRIMITIVES_SPHERE_H_
#define HEADERS_PRIMITIVES_SPHERE_H_

#define _USE_MATH_DEFINES

#include <math.h>
#include "Primitive.h"

class Sphere : public Primitive {
public:
	Sphere(glm::vec3 color = glm::vec3(0.5f, 0.5f, 0.5f)) : Primitive() {
		preferableDrawType = DRAW_TYPE_ELEMENT;

        std::vector<float> vertices;
        std::vector<float> normals;
        std::vector<float> texCoords;

        float radius = 1.f;
        int sectorCount = 100;
        int stackCount = 100;

        float x, y, z, xy;                              // vertex position
        float nx, ny, nz, lengthInv = 1.0f / radius;    // vertex normal
        float s, t;                                     // vertex texCoord

        float sectorStep = 2 * (float)M_PI / sectorCount;
        float stackStep = (float)M_PI / stackCount;
        float sectorAngle, stackAngle;

        for (int i = 0; i <= stackCount; ++i)
        {
            stackAngle = (float)M_PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
            xy = radius * cosf(stackAngle);             // r * cos(u)
            z = radius * sinf(stackAngle);              // r * sin(u)

            // add (sectorCount+1) vertices per stack
            // first and last vertices have same position and normal, but different tex coords
            for (int j = 0; j <= sectorCount; ++j)
            {
                sectorAngle = j * sectorStep;           // starting from 0 to 2pi

                // vertex position (x, y, z)
                x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
                y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
                vertices.push_back(x);
                vertices.push_back(y);
                vertices.push_back(z);

                // normalized vertex normal (nx, ny, nz)
                nx = x * lengthInv;
                ny = y * lengthInv;
                nz = z * lengthInv;
                normals.push_back(nx);
                normals.push_back(ny);
                normals.push_back(nz);

                // vertex tex coord (s, t) range between [0, 1]
                s = (float)j / sectorCount;
                t = (float)i / stackCount;
                texCoords.push_back(s);
                texCoords.push_back(t);
            }
        }


        std::vector<GLuint> indices;
        std::vector<int> lineIndices;
        int k1, k2;
        for (int i = 0; i < stackCount; ++i)
        {
            k1 = i * (sectorCount + 1);     // beginning of current stack
            k2 = k1 + sectorCount + 1;      // beginning of next stack

            for (int j = 0; j < sectorCount; ++j, ++k1, ++k2)
            {
                // 2 triangles per sector excluding first and last stacks
                // k1 => k2 => k1+1
                if (i != 0)
                {
                    indices.push_back(k1);
                    indices.push_back(k2);
                    indices.push_back(k1 + 1);
                }

                // k1+1 => k2 => k2+1
                if (i != (stackCount - 1))
                {
                    indices.push_back(k1 + 1);
                    indices.push_back(k2);
                    indices.push_back(k2 + 1);
                }

                // store indices for lines
                // vertical lines for all stacks, k1 => k2
                lineIndices.push_back(k1);
                lineIndices.push_back(k2);
                if (i != 0)  // horizontal lines except 1st stack, k1 => k+1
                {
                    lineIndices.push_back(k1);
                    lineIndices.push_back(k1 + 1);
                }
            }
        }

        std::vector<Vertex> v;

        for (auto [i, j] = std::tuple{ 0u, 0u }; i < vertices.size(); i += 3, j += 2) {
            v.push_back(Vertex{
                glm::vec3({vertices[i], vertices[i + 1], vertices[i + 2]}),
                color,
                glm::vec2({texCoords[j], texCoords[j + 1]}),
                glm::vec3({normals[i], normals[i + 1], normals[i + 2]}),
            });
        }

		setInitial(v, indices);
	}
};

#endif // !HEADERS_PRIMITIVES_SPHERE_H_