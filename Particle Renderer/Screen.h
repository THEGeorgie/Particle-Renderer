#pragma once
#include <SDL.h>
#include <iostream>
using namespace std;
#ifndef SCREEN_H_
#define SCREEN_H_
namespace gogi {
	class Screen
	{

	public:
		const static int screenW = 800;
		const static int screenH = 600;

	private:
		SDL_Window* m_window;
		SDL_Renderer* m_rendere;
		SDL_Texture* m_texture;
		Uint32* m_buffer;

	public:
		Screen();
		bool init();
		bool processEvents();
		void close();
		void update();
		void setPixle(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	};
}
#endif // !SCREEN_H_




