#ifndef GoopEngine_hpp
#define GoopEngine_hpp

#include <SDL2/SDL.h>

namespace Goop
{
	class GoopEngine
	{
		public:
			GoopEngine();
			~GoopEngine();

			// systems methods called by main.cpp
			void init();
			void quit();

			// user defined methods
			void load();
			void update();
			//void keyPressed();
			//void mousePressed();
			//void gamepadPressed();
			void render();

			// return methods
			bool isRunning() {return running;}
		private:
			bool running;

			SDL_Window* window;
			SDL_Renderer* renderer;
	};
}

#endif
