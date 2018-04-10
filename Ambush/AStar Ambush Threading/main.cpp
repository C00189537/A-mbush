#include "World.h"


int worker(void* data);
SDL_sem* gDataLock = NULL;
int collisionData = -1, enemyData = -1;
World world;

int main(int argc, char* argv[])
{
	SDL_Window* window = SDL_CreateWindow("Ambush", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	SDL_Renderer* r = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawBlendMode(r, SDL_BLENDMODE_BLEND);

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

		SDL_SetRenderDrawColor(r, 0, 0, 0, 0);
		SDL_RenderClear(r);

		if (deltaTime > timePerFrame) {
			input.handleInput(e);

			world.update(deltaTime);

			lastTime = currentTime;
		}

		world.draw(r);

		SDL_RenderPresent(r);
	}

	//Wait for threads to finish
	SDL_WaitThread(threadA, NULL);
	SDL_WaitThread(threadB, NULL);
	/*SDL_WaitThread(threadC, NULL);
	SDL_WaitThread(threadD, NULL);
	SDL_WaitThread(threadE, NULL);
	SDL_WaitThread(threadF, NULL);
	SDL_WaitThread(threadG, NULL);
	SDL_WaitThread(threadH, NULL);*/

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
		//Lock
		SDL_SemWait(gDataLock);

		//Index of the entity to be checked
		//printf("%s gets %d\n", data, collisionData);
		//printf("%s gets %d\n", data, enemyData);

		//"increment the index
		collisionData++;
		if (collisionData >= world.tileSize())
		{
			//Reset the search
			collisionData = 0;
		}
		if (world.generateEnemiesPath == true)
		{
			enemyData++;
		}
		if (enemyData >= world.MAX_ENEMIES)
		{
			world.generateEnemiesPath = false;
		}
		//Print post work data
		//printf("%s sets %d\n\n", data, collisionData);
		//printf("%s sets %d\n", data, enemyData);

		//Unlock
		SDL_SemPost(gDataLock);

		if (world.tileSize() >= 0)
		{
			world.checkCollision(collisionData);
		}
		if (world.generateEnemiesPath)
		{
			//std::cout << "generateEnemies" << std::endl;
		}
	}

	printf("%s finished!\n\n", data);

	return 0;
}

