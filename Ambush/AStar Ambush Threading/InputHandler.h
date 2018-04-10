#pragma once

#include <SDL.h>
#include "Keys.h"

class InputHandler 
{
public:

	InputHandler(Keys *k);
	void handleInput(SDL_Event *e);

private:
	Keys *m_Keys;
	//SDL_Event *m_event;
};