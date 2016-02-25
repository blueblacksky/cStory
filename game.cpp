#include <SDL.h>

#include <algorithm>
#include "game.h"
#include "graphics.h"
#include "input.h"
#include "animatedSprite.h"

/* Game class
*  Holds all information for main game loop
*/

namespace {
	const int FPS = 60; 
	const int MAX_FRAME_TIME = 6 * 1000 / FPS;
}

Game::Game(){
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game(){

}

void Game::gameLoop(){
	Graphics graphics;
	Input input;
	SDL_Event event;

	this->_player = AnimatedSprite(graphics, "resources\\sprites\\alucard_animations.png", 0, 0, 22, 50, 100, 100, 125);
	this->_player.setupAnimations();
	this->_player.playAnimation("Idle");

	int LAST_UPDATE_TIME = SDL_GetTicks();

	//start of game loop
	while (true){
		input.beginNewFrame();

		if (SDL_PollEvent(&event)){
			
			switch (event.type){
			case SDL_KEYDOWN:
				if (event.key.repeat == 0){
					input.keyDownEvent(event);
				}
				break;
			case SDL_KEYUP:
				input.keyUpEvent(event);
				break;
			}

			if (input.wasKeyboardButtonPressed(SDL_SCANCODE_ESCAPE) == true){
				atexit(SDL_Quit);
				return;
			}

		}

		//this limits frame rate
		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);
	}
}


void Game::draw(Graphics &graphics){
	graphics.clear();

	this->_player.draw(graphics, 100, 100);

	graphics.flip();
}

void Game::update(float elapsedTime) {
	this->_player.update(elapsedTime);
}