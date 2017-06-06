#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "loadScreen.h"
#include "resourceManag.h"

using namespace aie;

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	m_2dRenderer = new Renderer2D();

	resourceManag<Font>::create();

	m_loadScreen = new StateMachine();
	m_loadScreen->AddState(0, new loadScreen());
	m_loadScreen->PushState(0);
	return true;
}

void Application2D::shutdown() 
{
	delete m_2dRenderer;
	delete m_loadScreen;
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;

	// input example
	Input* input = Input::getInstance();

	m_loadScreen->Update(deltaTime);

	// use arrow keys to move camera
	if (input->isKeyDown(INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;

	// example of audio
	if (input->wasKeyPressed(INPUT_KEY_SPACE))
		m_audio->play();

	// exit the application
	if (input->isKeyDown(INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
//	m_2dRenderer->setCameraPos(0, 0);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_loadScreen->Draw(m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();
}