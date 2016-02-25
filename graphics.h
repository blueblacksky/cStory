#ifndef GRAPHICS_H
#define GRAPHICS_H


/* Defines the graphics class
*
*/

#include <map>
#include <string>
#include <SDL2_image.h>

struct SDL_Window;
struct SDL_Renderer;

class Graphics{
public:
	Graphics();
	~Graphics();

	/*SDL_Surface loadimage
	* load image into sprite sheet map if it doesn't exist 
	*/
	SDL_Surface* loadImage(const std::string &filePath);

	/*Draws a texture to a certain part of the screen*/
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/*Renders everything to the screen*/
	void flip();

	/*Clears the screen*/
	void clear();

	/*Returns the renderer*/
	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif