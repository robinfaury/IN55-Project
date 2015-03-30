#include "Sphere.h"

Sphere::Sphere() : Object3D()
{
	generate(15, 15);
	
	computeNormalOnVertex();

	loadVBO();
}

Sphere::Sphere(int M, int N) : Object3D()
{
	M = (M<4)? 4 : M;
	N = (N<4)? 4 : N;
	generate(M, N);
	
	computeNormalOnVertex();

	loadVBO();
}

void Sphere::generate(int M, int N)
{

	this->drawingMode = GL_QUADS;

	std::vector<glm::vec3> vertex;

	for (int m=1; m<M; ++m)
		for (int n=0; n<N; ++n)
			vertex.push_back(glm::vec3(sin(glm::pi<float>()*m/M)*cos(2*glm::pi<float>()*n/N), sin(glm::pi<float>()*m/M)*sin(2*glm::pi<float>()*n/N), cos(glm::pi<float>()*m/M)));

	for (int n=0; n<N; ++n)
	{
		this->vertices.push_back(glm::vec3(0.0, 0.0, 1.0));
		this->vertices.push_back(glm::vec3(0.0, 0.0, 1.0));
		this->vertices.push_back(vertex[n]);
		this->vertices.push_back(vertex[(n+1)%N]);
	}
	for (int m=0; m<M-2; ++m)
	{
		for (int n=0; n<N; ++n)
		{
			this->vertices.push_back(vertex[N*(m+1)+n]);
			this->vertices.push_back(vertex[N*(m+1)+(n+1)%N]);
			this->vertices.push_back(vertex[N*m+(n+1)%N]);
			this->vertices.push_back(vertex[N*m+n]);
		}
	}
	for (int n=0; n<N; ++n)
	{
		this->vertices.push_back(vertex[N*(M-2)+(n+1)%N]);
		this->vertices.push_back(vertex[N*(M-2)+n]);
		this->vertices.push_back(glm::vec3(0.0, 0.0, -1.0));
		this->vertices.push_back(glm::vec3(0.0, 0.0, -1.0));
	}
	
	for (int i=0; i<this->vertices.size(); ++i)
		this->normals.push_back(glm::normalize(this->vertices[i]));

}

Sphere::~Sphere()
{
}