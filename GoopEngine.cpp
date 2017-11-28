#include "GoopEngine.hpp"

#include <iostream>
#include <stdlib.h>

using namespace Goop;
	
GoopEngine::GoopEngine()
{}

GoopEngine::~GoopEngine()
{}


void GoopEngine::init(const char* windowTitle_arg, int windowWidth_arg, int windowHeight_arg)
{

	// Initialize locals
	windowTitle = windowTitle_arg;
	windowWidth = windowWidth_arg;
	windowHeight = windowHeight_arg;
	color.r = 255; // Red
	color.g = 255; // Green
	color.b = 255; // Blue
	color.a = 255; // Alpha

	// Initialize subsystems.
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
		// Init failed, exit program.
		std::cout << "SDL_Init Error " << SDL_GetError() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	else {
		// SDL_Init success.
		std::cout << "Subsystems initialized successfully." << std::endl;
	}
	
	// Create the window.
	window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		// SDL_CreateWindow failed, quit SDL and exit program.
		std::cout << "SDL_CreateWindow Error " << SDL_GetError() << std::endl;
		SDL_Quit();
		std::exit(EXIT_FAILURE);
	}
	else {
		// SDL_CreateWindow success.
		std::cout << "Window created successfully."	<< std::endl;
	}

	// Create the Renderer.
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == nullptr) {
		// SDL_CreateRenderer failed, destroy the window, quit SDL and exit the program.
			std::cout << "SDL_CreateRenderer Error " << SDL_GetError() << std::endl;
			SDL_DestroyWindow(window);
			SDL_Quit();
			std::exit(EXIT_FAILURE);
	}
	else {
		// SDL_CreateRenderer success.
		std::cout << "SDL_Renderer created successfully." << std::endl;
	}

	// Everything is created, now we can run
		running = true;

}

void GoopEngine::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				running = false;
				break;

			default:
				break;
		}
	}
}

void GoopEngine::draw()
{}

void GoopEngine::update()
{}

void GoopEngine::render()
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(renderer);

	GoopEngine::draw();

	SDL_RenderPresent(renderer);
}

void GoopEngine::quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::exit(EXIT_FAILURE);
}
