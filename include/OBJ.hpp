#pragma once
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <vector>
#include <string>

struct Vertex
{
    float x, y, z;
};

struct Face
{
    unsigned int a, b, c;
};


struct OBJ {
    std::vector<Vertex> vertices;
    std::vector<Face> faces;

    void load_obj(std::string path);
    void draw_obj(bool isFlat);
}; 


