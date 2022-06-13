#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <string>
#include"lista.h"
using namespace std;
using namespace sf;

int N = 30, M = 20;
float velocidad = 0;
int size = 16;
int w = 16 * N;
int cant = 0;
bool wait = false,menus=true,gameover=false,scoreMenu=false;
int dir, num = 1,score=0,pos=205 ,puestoArray=0;
int topTen [10];

sf::Event evento;
sf::Font font;
sf::Image menu;
sf::Image scoreMenuImage;
sf::SoundBuffer buffer;
sf::Sound sound;
RenderWindow window(VideoMode(w, 480), "Snake Snake SNAKE!!!!!");



struct Snake
{
    int x, y;
    struct Snake* siguiente = nullptr;
    struct Snake* anterior = nullptr;


};

struct Snake* cabeza = nullptr;
struct Snake* ultimo = cabeza;

struct Fruit
{
    int x, y,w,z;

} f;

void changeState()
{
    
    
    if (Keyboard::isKeyPressed(Keyboard::Enter) && pos==205)
     menus = false;

    if (Keyboard::isKeyPressed(Keyboard::Enter) && pos == 285 && menus==true)
    {
        menus = false;
        scoreMenu = true;
    }

    if (Keyboard::isKeyPressed(Keyboard::Escape) && scoreMenu == true)
    {
        scoreMenu = false;
        gameover = false;
        cabeza->x = 0;
        cabeza->y = 0;
        menus = true;
    }

    if (menus == false && Keyboard::isKeyPressed(Keyboard::Enter))
    {
        wait = false;
    }

    if (menus == false && Keyboard::isKeyPressed(Keyboard::Space))
    {
        window.clear();
        gameover = false;
        menus = true;
        cabeza->x = 0;
        cabeza->y = 0;
        
        num = 1;
        dir = 0;
        velocidad = 0;

        if (puestoArray < 10)
        {
            topTen[puestoArray] = score;
            puestoArray++;

            for (int i = 0;i < 10;i++)
            {
                for (int j = i + 1;j < 10;j++)
                {
                    if (topTen[i] < topTen[j])
                    {
                        int temp = topTen[i];
                        topTen[i] = topTen[j];
                        topTen[j] = temp;
                        
                    }
                }
            }

        }
       
        score = 0;

        for (int i = 0;i < 10;i++)
        {
            cout << topTen[i] << "\n";
        }

    }
        
    
}

void changeVelocity()
{
    if (Keyboard::isKeyPressed(Keyboard::C))
        velocidad = 0.05;
        
    if (Keyboard::isKeyPressed(Keyboard::X))
        velocidad = 0;
}

int selectMenu()
{
    
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        sound.setBuffer(buffer);
        sound.play();
        pos = 285;
    }
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        sound.setBuffer(buffer);
        sound.play();
        pos = 205;
    }
   
    return pos;

}

void incrementarCuerpo()
{
    struct Snake* nuevo = new Snake;
    

    if (cabeza == nullptr)
    {
        cabeza = nuevo;
        ultimo = nuevo;

        nuevo->x = 0;
        nuevo->y = 0;
        
    }
    else
    {
        struct Snake* jugador = ultimo;
       
        jugador->siguiente = nuevo;
        nuevo->anterior = jugador;
        nuevo->x = nuevo->anterior->x;
        nuevo->y = nuevo->anterior->y;
        jugador = jugador->siguiente;
        ultimo = nuevo;
           
        cant++;


    }

    
}

void choquePared()
{
    //Pared lateral
    if (cabeza->x > N || cabeza->x<0)
    {
        cabeza->x = 0;
        if (cabeza->x < 0)
            cabeza->x = N;

        wait = true;
        gameover = true;
        
        num = 1;
    }//Fin pared lateral

    //Pared superior/inferior
    if (cabeza->y > M || cabeza->y<0)
    {
        cabeza->y = 0;
        if (cabeza->y < 0)
            cabeza->y = M;

        wait = true;
        gameover = true;
        

        num = 1;

    }
}

void danio()
{
    struct Snake* choque = cabeza;
    struct Snake* temp1;
    while (choque != nullptr && choque->siguiente != nullptr && cant>1)
    {
        if (cabeza->x == choque->siguiente->x && cabeza->y == choque->siguiente->y || cabeza->x > N || cabeza->y > M)
        {
            temp1 = cabeza->siguiente;
            while (temp1 != NULL) 
            {
                cabeza->siguiente = temp1->siguiente;
                temp1->siguiente = NULL;
                free(temp1);
                temp1 = cabeza->siguiente;
            }
            ultimo = cabeza;
            cant = 0;
            num = 1;
            return;
        }
        choque = choque->siguiente;

    }
}


void Update()
{
    
    struct Snake* jugador = ultimo;
    do
    {
        if (jugador->anterior != nullptr)
        {
            jugador->x = jugador->anterior->x ;
            jugador->y = jugador->anterior->y ;
        }
        
            jugador = jugador->anterior;
        
    } while (jugador != nullptr);

    if (dir == 0) cabeza->y += 1;
    if (dir == 1) cabeza->x -= 1;
    if (dir == 2) cabeza->x += 1;
    if (dir == 3) cabeza->y -= 1;

    if ((cabeza->x == f.x) && (cabeza->y == f.y))
    {
        num++;
        incrementarCuerpo();
        f.x = rand() % N;
        f.y = rand() % M;
        score += 10;
    }

    if ((cabeza->x == f.w) && (cabeza->y == f.z))
    {
        num++;
        incrementarCuerpo();
        f.w = rand() % N;
        f.z = rand() % M;
        score += 20;
    }
    danio();
    choquePared();

  
}


void Game()
{
    srand(time(0));
    menu.loadFromFile("images/menu.png");
    scoreMenuImage.loadFromFile("images/Top.png");
    buffer.loadFromFile("Sounds/selectSound.wav");
    font.loadFromFile("MGS2.ttf");
    
    
    Texture t1, t2, t3,t4,t5,t6,t7;
    t1.loadFromFile("images/white.png");
    t2.loadFromFile("images/red.png");
    t3.loadFromFile("images/marco.png");
    t4.loadFromImage(menu);
    t5.loadFromFile("images/shine.png");
    t6.loadFromFile("images/green.png");
    t7.loadFromImage(scoreMenuImage);
    Sprite sprite1(t1);
    Sprite sprite2(t2);
    Sprite sprite3(t3);
    Sprite sprite4(t4);
    Sprite sprite5(t5);
    Sprite sprite6(t6);
    Sprite sprite7(t7);
    Clock clock;
    float timer = 0, delay = 0.1;
    
    f.x = 10;
    f.y = 10;
    f.w = 15;
    f.z = 15;
    for (int x = 0;x < 10;x++)
    {
        topTen[x] = 0;
    }
    incrementarCuerpo();
    while (window.isOpen())
    {

        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left) && !menus) dir = 1;
        if (Keyboard::isKeyPressed(Keyboard::Right) && !menus) dir = 2;
        if (Keyboard::isKeyPressed(Keyboard::Up) && !menus) dir = 3;
        if (Keyboard::isKeyPressed(Keyboard::Down) && !menus) dir = 0;
        changeVelocity();

        if (timer > delay-velocidad  && !menus) 
        { 
            timer = 0; 
            Update();
        }

        ////// draw  ///////
        
            window.clear();
         if (!wait && !menus && !scoreMenu) {

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    sprite1.setPosition(i * 16, j * 16);  window.draw(sprite1);
                }
            }

            struct Snake* move = cabeza;
            
            while (move != nullptr)
            {
                sprite2.setPosition(move->x * 16,move->y * 16); window.draw(sprite2);
                
                move = move->siguiente;
                
            } 

            for (int i = 0; i < 30; i++)
            {
                for (int j = 20; j < 40; j++)
                {
                    sprite3.setPosition(i * 16, j * 16);  window.draw(sprite3);
                }
            }
            sf::String textow;
            sf::String Text;
          

            sprite2.setPosition(f.x * 16, f.y * 16);  window.draw(sprite2);
            sprite6.setPosition(f.w * 16, f.z * 16);  window.draw(sprite6);

            sf::Text text("S c o r e: ", font);
            text.setCharacterSize(30);
            text.setStyle(sf::Text::Bold);
            text.setFillColor(sf::Color::White);
            text.move(0.f, 340.f);
            window.draw(text);

            sf::Text puntaje(to_string(score), font);
            puntaje.setCharacterSize(30);
            puntaje.setStyle(sf::Text::Bold);
            puntaje.setFillColor(sf::Color::White);
            puntaje.move(100.f, 340.f);
            window.draw(puntaje);


            window.display();
        }

         if (wait && gameover && !scoreMenu)
         {
             changeState();

             sf::Text lost("\t\t\t\t GAME OVER \n\nPresiona Espacio para volver \nal menu principal", font);
             lost.setCharacterSize(25);
             lost.setStyle(sf::Text::Bold);
             lost.setFillColor(sf::Color::White);
             lost.move(80.f, 200.f);
             window.draw(lost);
             window.display();
         }

        if (menus)
        {
            for (int i = 0; i < 60; i++)
            {
                for (int j = 20; j < 40; j++)
                {
                    menu.setPixel(i, j, sf::Color::Black);
                    
                }
            }

            for (int i = 0;i < num;i++)
            {
                sprite5.setPosition(120, selectMenu());  window.draw(sprite5);
            }
           
            window.draw(sprite4);
            window.draw(sprite5);
            window.display();

          
        }
        
        if (scoreMenu)
        {
            for (int i = 0; i < 60; i++)
            {
                for (int j = 20; j < 40; j++)
                {
                    scoreMenuImage.setPixel(i, j, sf::Color::Black);

                }
            }
            int tab = 0;
            window.draw(sprite7);
            sf::Text printScore;
            for (int x = 0;x < 10;x++)
            {
                printScore.setFont(font);
                printScore.setPosition(150, 100 + tab);
                printScore.setString(to_string(x+1));
                window.draw(printScore);
                printScore.setPosition(169, 100 + tab);
                printScore.setString(".");
                window.draw(printScore);
                printScore.setPosition(180, 100 + tab);
                printScore.setString(to_string(topTen[x]));
                tab += 30;
                window.draw(printScore);
                
                
            }
            

            
            window.display();
        }


        changeState();
        
    }
   

}


int main()
{
    Game();
    return 0;
}
