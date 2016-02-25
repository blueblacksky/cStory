#ifndef INPUT_H
#define INPUT_H

#include <map>
#include "SDL.h"

class Input{
public:
	void beginNewFrame();
	void keyUpEvent(const SDL_Event& event);
	void keyDownEvent(const SDL_Event& event);

	bool wasKeyboardButtonPressed(SDL_Scancode keyboardButton);
	bool wasKeyboardButtonReleased(SDL_Scancode keyboardButton);
	bool isKeyboardButtonHeld(SDL_Scancode keyboardButton);

private:
	std::map<SDL_Scancode, bool> _heldKeyboardButtons;
	std::map<SDL_Scancode, bool> _pressedKeyboardButtons;
	std::map<SDL_Scancode, bool> _releasedKeyboardButtons;
};
#endif