#include "World.h"


int worker(void* data);
SDL_sem* gDataLock = NULL;
int gData = 0;
World world;

int main(int argc, char* argv[])
{
	SDL_Window* window = SDL_CreateWindow("Ambush", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	SDL_Event *e = new SDL_Event();
	Keys *keys = new Keys;

	InputHandler input(keys);
	world.create(keys);

	bool running = true;

	const float FPS = 60;
	const float timePerFrame = 1.0f / FPS;
	float currentTime = 0;
	float lastTime = 0;
	float deltaTime = 0;

	

	gDataLock = SDL_CreateSemaphore(1);
	srand(SDL_GetTicks());

	SDL_Thread* threadA = SDL_CreateThread(worker, "Thread A", (void*)"Thread A");
	SDL_Thread* threadB = SDL_CreateThread(worker, "Thread B", (void*)"Thread B");
	SDL_Thread* threadC = SDL_CreateThread(worker, "Thread C", (void*)"Thread C");

	SDL_Thread* threadD = SDL_CreateThread(worker, "Thread D", (void*)"Thread D");
	SDL_Thread* threadE = SDL_CreateThread(worker, "Thread E", (void*)"Thread E");
	SDL_Thread* threadF = SDL_CreateThread(worker, "Thread F", (void*)"Thread F");

	SDL_Thread* threadG = SDL_CreateThread(worker, "Thread G", (void*)"Thread G");
	SDL_Thread* threadH = SDL_CreateThread(worker, "Thread H", (void*)"Thread H");


	while (running) 
	{
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - lastTime) / 1000;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
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
	SDL_WaitThread(threadC, NULL);
	SDL_WaitThread(threadD, NULL);
	SDL_WaitThread(threadE, NULL);
	SDL_WaitThread(threadF, NULL);
	SDL_WaitThread(threadG, NULL);
	SDL_WaitThread(threadH, NULL);

	return 0;
}


int worker(void* data)
{

	printf("%s starting...\n", data);

	srand(SDL_GetTicks());

	bool run4ever = true;

	while(run4ever)
	{
		//Check the collision
		if (world.tileSize() > 0)
		{
			world.checkCollision(gData);
		}

		//Lock
		SDL_SemWait(gDataLock);

		//Index of the entity to be checked
		printf("%s gets %d\n", data, gData);

		//"increment the index
		gData++;
		if (gData >= world.tileSize())
		{
			//Reset the search
			gData = 0;
		}
		//Print post work data
		printf("%s sets %d\n\n", data, gData);

		//Unlock
		SDL_SemPost(gDataLock);

	}

	printf("%s finished!\n\n", data);

	return 0;
}

