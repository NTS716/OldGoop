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
			void init(const char* windowTitle_arg, int windowWidth_arg, int windowHeight_arg);
			void handleEvents();
			void render();
			void quit();

			// user defined methods
			void load();
			void update();
			//void keyPressed();
			//void mousePressed();
			//void gamepadPressed();
			void draw();

			// return methods
			bool isRunning() {return running;}
			// bool isKeyDown(int key_arg);
			// bool isGamepadDown(int button_arg);
			// bool isMouseDown(int mouse_arg);
		private:
			bool running;

			const char* windowTitle;
			int windowWidth;
			int windowHeight;

			SDL_Window* window;
			SDL_Renderer* renderer;

			struct
			{
				int r;
				int g;
				int b;
				int a;
			} color;
	};
}

#endif
