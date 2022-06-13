#include "Juego.h"
#include <iostream>
#include "TextureManger.h"
#include "GameObj.h"
#include "Inicio.h"
#include "menuA.h"
#include "playerObj.h"
#include "manzanaObj.h"
#include "text.h"
GameObj* player = nullptr;
//GameObj* enemy;
Inicio* menu=nullptr;
menuA* selection = nullptr;
playerObj* exa = nullptr;
manzanaObj* apple=nullptr;
text* texto;
SDL_Renderer* Juego::renderer = nullptr;
state estado;

Juego::Juego()
{
    estado = start;
}
Juego::~Juego()
{}


state Juego::getState()
{
    return estado;
}

state Juego::setState(state esta)
{
    estado = esta;
    return estado;
}

void Juego::init(const char* tittle, int x, int y, int w, int h, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
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
            std::cout<<"Render creado" << std::endl;
        }
        isRunning = true;
    }
    
    if (TTF_Init() == -1)
    {
        cout << "ERROR TTF";
    }
    
    menu = new Inicio("C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/inicio.png");
    player = new GameObj("C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/selectA.png",60,70);
    selection = new menuA("C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/selector.png", "C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/selectA.png", 28, 70);
    exa = new playerObj("C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/Mochila.png", 
                        "C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/newton_1.png", 
                        "C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/newton_3.png", 
                         120, 184);
    apple = new manzanaObj( "C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/selectA.png", "C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/G.png","C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/selectA.png" ,"C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/granade.png","C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/over.png" ,60, 30);

  /*  enemy = new GameObj("C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/enemigo.png", 100, 100);*/
   

   /* SDL_Surface* tmpSurface = IMG_Load("C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/flecha.png");
    playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);*/
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
    
    player->moveCursor(evento);
    player->estadoRender(player->pressEnter(evento, player->evaluateY(),estado), "C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/selectA.png");
    menu->estadoRender(player->pressEnter(evento, player->evaluateY(),estado),"C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/mapanew.png", "C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/inicio.png");
    selection->selectLVL(evento,estado);
    menu->enterLVL(selection->getLVL(), "C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/mapanew.png","C://Users/Carlos/source/repos/Game/Game/Graphics/Imagenes/LVL.png",estado,evento);
    exa->moveP(evento,estado);
    apple->selectQuest();
    apple->moveMa(evento,estado);
    apple->moveGra(evento, estado);
    apple->randomLetter();
    apple->reiniciolvl(evento);
    
    apple->palabra();
    close(evento, player->evaluateY());
    
}

void Juego::update()
{
    menu->update();
    exa->update();
    player->update();
    selection->update();
    apple->update();
    
    
    /*enemy->update();*/
    

}

void Juego::render()
{
    // Aqui le agregamos cosas al Render
    apple->colision(estado, exa->getX(), exa->getY());
    SDL_RenderClear(renderer);
    menu->Render();
    exa->Render(estado);
    player->Render();
    selection->Render(estado);
    
    apple->Render(estado);
    
  /*  enemy->Render();*/
    
    SDL_RenderPresent(renderer);
}

void Juego::close(SDL_Event evento,int pos)
{
    if (evento.type == SDL_KEYDOWN && estado == start)
    {

        switch (evento.key.keysym.sym) {
        case SDLK_RETURN:

            if (pos == 1)
                isRunning = false;

            break;

        }
    }
}

void Juego::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer;
    SDL_Quit();

    std::cout << "Juego limpiado" << std::endl;

}

bool Juego::running() { return isRunning; }