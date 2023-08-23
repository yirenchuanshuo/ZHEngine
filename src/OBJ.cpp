#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include "check_gl.hpp"
#include "OBJ.hpp"


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
			Vertex vertex;
			s >> vertex.x >> vertex.y >> vertex.z;
			vertices.push_back(vertex);
		}
		else if (line.substr(0, 2) == "f")
		{
			std::istringstream s(line.substr(2));
			std::string sa, sb, sc;
			Face face;
			s >> sa >> sb >> sc;
			std::istringstream(sa) >> face.a;
			std::istringstream(sb) >> face.b;
			std::istringstream(sc) >> face.c;
			face.a--;
			face.b--;
			face.c--;
			faces.push_back(face);
		}
	}
	file.close();
	std::cout << "Loaded" << vertices.size() << "vertices.\n";
}

void OBJ::draw_obj(bool isFlat)
{
}
