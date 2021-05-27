
#include "mesh.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using namespace glm;
using namespace agl;



Mesh::Mesh() 
{
	min_bound = glm::vec3(0);
	max_bound = glm::vec3(0);
	num_vertices = 0;
	num_triangles = 0;
	position = new float[0];
	normal = new float[0];
    index = new unsigned int[0];
}

Mesh::~Mesh()
{
	delete[] position;
	delete[] normal;
	delete[] index;
}

bool Mesh::loadPLY(const std::string& filename)
{
	float min_x = 0;
	float min_y = 0;
	float min_z = 0;
	float max_x = 0;
	float max_y = 0; 
	float max_z = 0;
	float holder = 0;
	ifstream readFile(filename);
	string text;
	if (!readFile) 
	{
		cerr << "unable to read file" << endl;
		return false;
	}
	readFile >> text;
	if (text != "ply")
	{
		cerr << "incorrect file format" << endl;
		return false;
	}
	getline(readFile, text);
	getline(readFile, text);
	getline(readFile, text);
	readFile >> text;
	readFile >> text;
	readFile >> num_vertices;
	getline(readFile, text);
	getline(readFile, text);
	getline(readFile, text);
	getline(readFile, text);
	getline(readFile, text);
	getline(readFile, text);
	getline(readFile, text);
	readFile >> text;
	readFile >> text;
	readFile >> num_triangles;
	getline(readFile, text);
	getline(readFile, text);
	getline(readFile, text);
	position = new float[3 * num_vertices];
	normal = new float[3 * num_vertices];
	index = new unsigned int[3 * num_triangles];
	for (int i = 0; i < num_vertices; i++)
	{
		
		readFile >> holder;
	    position[i * 3] = holder;
		if (holder > max_x)
		{
			max_x = holder;
		}
		else if (holder < min_x)
		{
			min_x = holder;
		}

		readFile >> holder;
		position[i * 3 + 1] = holder;
		if (holder > max_y)
		{
			max_y = holder;
		}
		else if (holder < min_y)
		{
			min_y = holder;
		}
			
		readFile >> holder;
		position[i * 3 + 2] = holder;
		if (holder > max_z)
		{
			max_z = holder;
		}
		else if (holder < min_z)
		{
			min_z = holder;
		}
		readFile >> normal[i * 3];
		readFile >> normal[i * 3 + 1];
		readFile >> normal[i * 3 + 1];
	}

	min_bound.x = min_x;
	min_bound.y = min_y;
	min_bound.z = min_z;
	max_bound.x = max_x;
	max_bound.y = max_y;
	max_bound.z = max_z;

	for (int i = 0; i < num_triangles; i++)
	{
		readFile >> text;
		readFile >> index[i * 3];
		readFile >> index[i * 3 + 1];
		readFile >> index[i * 3 + 2];
	}
	readFile.close();
	return true;
}

glm::vec3 Mesh::getMinBounds() const
{
  return min_bound;
}

glm::vec3 Mesh::getMaxBounds() const
{
  return max_bound;
}

int Mesh::numVertices() const
{
   return num_vertices;
}

int Mesh::numTriangles() const
{
   return num_triangles;
}

float* Mesh::positions() const
{
	return position;
}

float* Mesh::normals() const
{
   return normal;
}

unsigned int* Mesh::indices() const
{
   return index;
}

