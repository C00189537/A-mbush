#include "InputHandler.h"

InputHandler::InputHandler(Keys *k) 
{
	m_Keys = k;
}

void InputHandler::handleInput(SDL_Event *e) {
	while (SDL_PollEvent(e)) 
	{
		switch (e->type) 
		{
		case SDL_KEYDOWN:
			if (!e->key.repeat) 
			{
				switch (e->key.keysym.sym) 
				{
				case SDLK_w:
					m_Keys->W = true;
					break;

				case SDLK_a:
					m_Keys->A = true;
					break;

				case SDLK_s:
					m_Keys->S = true;
					break;

				case SDLK_d:
					m_Keys->D = true;
					break;
				}
				break;
			}

		case SDL_KEYUP:
			if (!e->key.repeat) 
			{
				switch (e->key.keysym.sym)
				{
				case SDLK_w:
					m_Keys->W = false;
					break;

				case SDLK_a:
					m_Keys->A = false;
					break;

				case SDLK_s:
					m_Keys->S = false;
					break;

				case SDLK_d:
					m_Keys->D = false;
					break;
				}
				break;
			}
		}
	}
}