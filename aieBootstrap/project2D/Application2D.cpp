#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "loadScreen.h"
#include "splash.h"
#include "resourceManag.h"
#include "MenuState.h"
#include "GameState.h"
#include "PauseState.h"
#include <crtdbg.h>

using namespace aie;

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	_ASSERT(m_2dRenderer);
	m_2dRenderer = new Renderer2D();

	resourceManag<Font>::create();

	_ASSERT(m_stateMachine);
	m_stateMachine = new StateMachine();
	
	m_stateMachine->AddState(0, new GameState());
	m_stateMachine->AddState(1, new MenuState());
	m_stateMachine->AddState(2, new splash());
	m_stateMachine->AddState(3, new loadScreen());
	m_stateMachine->AddState(4, new PauseState());

	m_stateMachine->PushState(0);
	m_stateMachine->PushState(1);
	m_stateMachine->PushState(2);
	m_stateMachine->PushState(3);


	return true;
}

void Application2D::shutdown() 
{
	delete m_2dRenderer;
	delete m_stateMachine;
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;

	// input example
	Input* input = Input::getInstance();

	m_stateMachine->Update(deltaTime);

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

	m_stateMachine->Draw(m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();
}