#include "World.h"

int worker(void* data);
SDL_sem* gDataLock = NULL;
int gData = -1;

int main(int argc, char* argv[])
{
	SDL_Window* window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Event *e = new SDL_Event();

	EventListener *eventListener = new EventListener;

	InputHandler input(eventListener);
	World world(eventListener);

	bool running = true;

	const float FPS = 60;
	const float timePerFrame = 1.0f / FPS;
	float currentTime = 0;
	float lastTime = 0;
	float deltaTime = 0;

	

	gDataLock = SDL_CreateSemaphore(1);
	srand(SDL_GetTicks());
	SDL_Thread* threadA = SDL_CreateThread(worker, "Thread A", (void*)"Thread A");
	SDL_Delay(16 + rand() % 32);
	SDL_Thread* threadB = SDL_CreateThread(worker, "Thread B", (void*)"Thread B");


	while (running) {
		currentTime = SDL_GetTicks();

		deltaTime = (currentTime - lastTime) / 1000;

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		if (deltaTime > timePerFrame) {
			input.handleInput(e);

			world.update(deltaTime);

			lastTime = currentTime;
		}

		world.draw(renderer);

		SDL_RenderPresent(renderer);
	}

	//Wait for threads to finish
	SDL_WaitThread(threadA, NULL);
	SDL_WaitThread(threadB, NULL);

	return 0;
}


int worker(void* data)
{

	printf("%s starting...\n", data);

	srand(SDL_GetTicks());


	//Work 5 times
	for (int i = 0; i < 5; ++i)
	{
		//Wait randomly
		SDL_Delay(16 + rand() % 32);

		//Lock
		SDL_SemWait(gDataLock);

		//Print pre work data
		printf("%s gets %d\n", data, gData);

		//"Work"
		gData = rand() % 256;

		//Print post work data
		printf("%s sets %d\n\n", data, gData);

		//Unlock
		SDL_SemPost(gDataLock);

		//Wait randomly
		SDL_Delay(16 + rand() % 640);
	}

	printf("%s finished!\n\n", data);

	return 0;
}

