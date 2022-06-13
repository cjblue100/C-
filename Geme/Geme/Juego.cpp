#include "Juego.h"
#include <iostream>

Juego::Juego()
{}
Juego::~Juego()
{}

void Juego::init(const char* tittle, int x, int y, int w, int h, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsistemas inicializados..." << std::endl;
        window = SDL_CreateWindow("CBR", x, y, w, h, flags);
        if (window)
        {
            std::cout << "Ventana creada" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Render creado" << std::endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

}

void Juego::handleEvents()
{
    SDL_Event evento;
    SDL_PollEvent(&evento);
    switch (evento.type) {
    case SDL_QUIT:
        isRunning = false;
        break;

    default:
        break;

    }
}

void Juego::update()
{}

void Juego::render()
{
    SDL_RenderClear(renderer);// Aqui le agregamos cosas al Render
    SDL_RenderPresent(renderer);
}

void Juego::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer;
    SDL_Quit();

    std::cout << "Juego limpiado" << std::endl;

}

bool Juego::running() { return isRunning; }