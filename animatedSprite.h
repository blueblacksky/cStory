#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <string>
#include <vector>

#include "sprite.h"
#include "globals.h"

class Graphics;

/* Animates sprite 
*  deifintion for sprite class
*/

class AnimatedSprite : Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphics, const std::string &filepath, int sourceX, int sourceY, int width, int height,
		float posX, float postY, float timeToUpdate);

	// plays animation
	void playAnimation(std::string animation, bool once = false);

	// updates animated sprite
	void update(int elapsedTime);

	// draws sprite
	void draw(Graphics &graphics, int x, int y);
	
	// sets up all animations for a sprite (required)
	virtual void setupAnimations();

protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;

	/* void addAnimation
	* Adds animation for the sprite
	* arguments : number of frames, where on sprite sheet animation begins, name of animation, width and height of each frame,
	* offset
	*/
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

	/*void resetAnimation
	* resets all animation for sprite
	*/
	void resetAnimation();

	/*void stopsAnimation
	* halts sprite animation
	*/
	void stopAnimation();

	/*void setVisible
	* changes animated sprite visibility
	*/
	void setVisible(bool visible);

	/*virtual void animationDone
	* logic fired when animation ends
	*/
	virtual void animationDone(std::string currentAnimation); 

private:
	std::map<std::string, std::vector<SDL_Rect> > _animations;
	std::map<std::string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed;
	bool _visible;
};

#endif