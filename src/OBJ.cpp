#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include "check_gl.hpp"
#include "OBJ.hpp"


static glm::vec3 perspective_divide(glm::vec4 pos)
{
	return glm::vec3(pos.x / pos.w, pos.y / pos.w, pos.z / pos.w);
}

void OBJ::load_obj(std::string path)
{
	std::ifstream file(path);
	if (!file.is_open())
	{
		std::cerr << "Failed to Open file: " << path << '\n';
		return;
	}

	std::string line;
	while (std::getline(file, line)) {
		if (line.substr(0, 2) == "v ")
		{
			std::istringstream s(line.substr(2));
			glm::vec3 vertex;
			s >> vertex.x >> vertex.y >> vertex.z;
			vertices.push_back(vertex);
		}
		else if (line.substr(0, 2) == "f ")
		{
			std::istringstream s(line.substr(2));
			std::string splitted;
			std::vector<unsigned int>indices;
			while (std::getline(s, splitted, ' '))
			{
				unsigned int index;
				std::istringstream(splitted) >> index;
				indices.push_back(index - 1);
			}
			for (size_t i = 2; i < indices.size(); i++)
			{
				glm::uvec3 face = { indices[0],indices[i - 1],indices[i] };
				faces.push_back(face);
			}
			
		}
	}
	file.close();
	std::cout << "Loaded " << vertices.size() << " vertices, " << faces.size() << " faces.\n";
}

void OBJ::draw_obj()
{
	glBegin(GL_TRIANGLES);

	for (auto const& face : faces)
	{
		auto const& a = vertices.at(face.x);
		auto const& b = vertices.at(face.y);
		auto const& c = vertices.at(face.z);

		glVertex3fv(glm::value_ptr(a));
		glVertex3fv(glm::value_ptr(b));
		glVertex3fv(glm::value_ptr(c));
	}

	CHECK_GL(glEnd());
}
