#include "input.h"

/*Input class
* Keeps track of input state
*/

// this is called at the beggining of each new frame to reset keyboard keys
void Input::beginNewFrame(){
	this->_pressedKeyboardButtons.clear();
	this->_releasedKeyboardButtons.clear();
}

// this is called when a key is pressed
void Input::keyDownEvent(const SDL_Event &event){
	this->_pressedKeyboardButtons[event.key.keysym.scancode] = true;
	this->_heldKeyboardButtons[event.key.keysym.scancode] = true;
}

//this is called when a key is released
void Input::keyUpEvent(const SDL_Event &event){
	this->_releasedKeyboardButtons[event.key.keysym.scancode] = true;
	this->_heldKeyboardButtons[event.key.keysym.scancode] = false;
}

//checks if key was pressed during current frame
bool Input::wasKeyboardButtonPressed(SDL_Scancode key){
	return this->_pressedKeyboardButtons[key];
}

//checks if key was released during current frame
bool Input::wasKeyboardButtonReleased(SDL_Scancode key){
	return this->_releasedKeyboardButtons[key];
}

//checks if key held during current frame
bool Input::isKeyboardButtonHeld(SDL_Scancode key){
	return this->_heldKeyboardButtons[key];
}