#include "FreeRoamCameraController.hpp"
#include <Qt>

FreeRoamCameraController::FreeRoamCameraController()
	: CameraController()
{
}

void FreeRoamCameraController::handleKeyboardInput(Camera &camera, KeyboardState &keyboard, float nSpeed)
{
	glm::vec3 v3Right(camera.getRightDir());
	v3Right[1] = 0;
	v3Right = glm::normalize(v3Right);
	glm::vec3 v3Forward(camera.getLookDir());
	v3Forward[1] = 0.f;
	v3Forward = glm::normalize(v3Forward);

	glm::vec3 v3Translate(0);

	if (keyboard.getKeyPressed(Qt::Key_W))
	{
		v3Translate += nSpeed*5.0f*v3Forward;
	}
	if (keyboard.getKeyPressed(Qt::Key_A))
	{
		v3Translate += nSpeed*-5.0f*v3Right;
	}
	if (keyboard.getKeyPressed(Qt::Key_S))
	{
		v3Translate += nSpeed*-5.0f*v3Forward;
	}
	if (keyboard.getKeyPressed(Qt::Key_D))
	{
		v3Translate += nSpeed*5.0f*v3Right;
	}
	if (keyboard.getKeyPressed(Qt::Key_Q))
	{
		v3Translate += glm::vec3(0,nSpeed*-5.0f,0);
	}
	if (keyboard.getKeyPressed(Qt::Key_E))
	{
		v3Translate += glm::vec3(0,nSpeed*5.0f,0);
	}

	camera.translate(v3Translate);
}

void FreeRoamCameraController::handleMouseInput(Camera &camera, MouseState &mouse, float nSpeed)
{
	if (mouse.getButtonPressed(Qt::RightButton))
	{
		if (mouse.getDeltaY() != 0 || mouse.getDeltaX() != 0)
		{
			camera.rotate(nSpeed*-15.0f*mouse.getDeltaY(), camera.getRightDir()); // Rotate up / down
			camera.rotate(nSpeed*-25.0f*mouse.getDeltaX(), glm::vec3(0.f, 1.f, 0.f)); // Rotate left / right
		}
	}
}