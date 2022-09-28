#include "Screen.h"
namespace gogi {

	Screen::Screen(): 
		m_window(NULL),
		m_rendere(NULL),
		m_texture(NULL),
		m_buffer(NULL) {
		
	}
	bool Screen::init() {

		if (SDL_Init(SDL_INIT_EVERYTHING) < NULL) {
			cout << "SDL initalization failed" << endl;

			return false;
		}


		m_window = SDL_CreateWindow("Paricle Renderer",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenW, screenH, SDL_WINDOW_SHOWN);

		if (m_window == NULL) {
			SDL_Quit;

			return false;
		}


		m_rendere = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		m_texture = SDL_CreateTexture(m_rendere, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, screenW, screenH);

		if (m_rendere == NULL) {
			cout << "Renderer has not been created" << endl;
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		if (m_texture == NULL) {
			cout << "Texture has not been created" << endl;
			SDL_DestroyRenderer(m_rendere);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		Uint32* buffer = new Uint32[screenW * screenH];

		memset(buffer, 0, screenW * screenH * sizeof(Uint32));

		for (int i = 0; i < screenW * screenH; i++) {
			buffer[i] = 0xFFFF0000;
		}


		SDL_UpdateTexture(m_texture, NULL, buffer, screenW * sizeof(Uint32));
		SDL_RenderClear(m_rendere);
		SDL_RenderCopy(m_rendere, m_texture, NULL, NULL);
		SDL_RenderPresent(m_rendere);

		return true;
	}
	bool Screen::processEvents() {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return false;
			}
		}

		return true;
	}
	void Screen::close() {

		SDL_DestroyRenderer(m_rendere);
		SDL_DestroyTexture(m_texture);
		SDL_DestroyWindow(m_window);
		SDL_Quit();

		delete[] m_buffer;
		
	}

}