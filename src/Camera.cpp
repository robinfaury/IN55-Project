#include "Camera.h"

Camera::Camera() : m_phi(0.0), m_theta(0.0), m_orientation(), m_verticalAxis(0, 0, 1), m_lateralMovement(), m_position(), m_targetPoint()
{

}

Camera::Camera(glm::vec3 position, glm::vec3 targetPoint, glm::vec3 verticalAxis) : m_phi(0.0), m_theta(0.0), m_orientation(), m_verticalAxis(verticalAxis), m_lateralMovement(), m_position(position), m_targetPoint(targetPoint)
{

}

Camera::~Camera()
{

}

void Camera::changeOrientation(int x, int y)
{
	// actualisation des angles selon le déplacement (x, y) et la vitesse de déplacement de la caméra
	m_theta -= x * 0.5;
	m_phi -= y * 0.5;

	// limitation de l'ange d'orientation sur l'axe vertical à 89°
	if (m_phi > 89.0)
	{
		m_phi = 89.0;
	}
	if (m_phi < -89.0)
	{
		m_phi = -89.0;
	}

	// conversion des angles en radians
	float phiRad = m_phi * M_PI / 180;
	float thetaRad = m_theta * M_PI / 180;
	
	// calcul des coordonnées du vecteur orientation selon l'axe vertical
	if (m_verticalAxis.x == 1.0) // si c'est l'axe x
	{
		m_orientation.x = sin(phiRad); 
		m_orientation.y = cos(phiRad) * cos(thetaRad);
		m_orientation.z = cos(phiRad) * sin(thetaRad);
	}
	else if (m_verticalAxis.y == 1.0) // si c'est l'axe y
	{
		m_orientation.x = cos(phiRad) * sin(thetaRad);
		m_orientation.y = sin(phiRad);
		m_orientation.z = cos(phiRad) * cos(thetaRad);
	}
	else // si c'est l'axe z
	{
		m_orientation.x = cos(phiRad) * cos(thetaRad); 
		m_orientation.y = cos(phiRad) * sin(thetaRad); 
		m_orientation.z = sin(phiRad);
	}

	// calcul du déplacement latéral (normale au plan formé par le vecteur d'orientation et l'axe vertical)
	m_lateralMovement = glm::cross(m_verticalAxis, m_orientation);
	m_lateralMovement = glm::normalize(m_lateralMovement);

	// calcul du point cible visé par la caméra
	m_targetPoint = m_position + m_orientation;
}

void move(sf::Event const &event)
{
	
}