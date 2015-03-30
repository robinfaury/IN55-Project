#ifndef CAMERA_H_
#define CAMERA_H_

#define _USE_MATH_DEFINES
#include <math.h>
#include <glm.hpp>
#include <gtx/transform.hpp>
#include <gtc/type_ptr.hpp>
#include <SFML\Graphics.hpp>

class Camera
{

protected:
	float m_phi; // angle d'orientation sur l'axe vertical
	float m_theta; // angle d'orientation sur l'axe horizontal
	glm::vec3 m_orientation; // vecteur orientation de la caméra

	glm::vec3 m_verticalAxis; // axe (x, y ou z) définit comme axe vertical
	glm::vec3 m_lateralMovement; // vecteur de mouvement latéral

	glm::vec3 m_position; // position de la caméra
	glm::vec3 m_targetPoint; // point cible visé par la caméra

public:
	Camera();
	Camera(glm::vec3 position, glm::vec3 targetPoint, glm::vec3 verticalAxis);
	~Camera();

	void changeOrientation(int x, int y);
	void move(sf::Event const &event);
	void lookAt(glm::mat4 &modelView);
};


#endif