#include "Puntaje.h"

Puntaje::Puntaje()
{
    for (int x = 0;x < 10;x++)
    {
        puntajes[x] = 0;
    }
    cosa = 0;
    y = 0;
}


void Puntaje::insertScore(int score,bool dead)
{
   
    
    if (dead == true) {
        if (cosa == 0) {
            puntajes[y] = score;


            for (int i = 0;i < 10;i++)
            {
                for (int j = i + 1;j < 10;j++)
                {
                    if (puntajes[i] < puntajes[j])
                    {
                        temp = puntajes[i];
                        puntajes[i] = puntajes[j];
                        puntajes[j] = temp;
                        cosa = 1;
                    }
                }
            }
        }
    }

}

void Puntaje::gotoxy(int x, int y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}



void Puntaje::printScore(bool dead)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoxy(23, 26);
    SetConsoleTextAttribute(h, 12);
    cout << (char)201;

    gotoxy(45, 26);
    cout << (char)187;

    gotoxy(45, 38);
    cout << (char)188;
    
    for (int v = 24;v < 45;v++) 
    {
        gotoxy(v, 26);
        cout << (char)205;
    }

    for (int v = 37;v > 26;v--)
    {
        gotoxy(23, v);
        cout << (char)186;
    }
        gotoxy(23, 38);
        cout << (char)200;
    
    for (int v = 24;v < 45;v++)
    {
        gotoxy(v, 38);
       cout << (char)205;
    }

    for (int v = 37;v > 26;v--)
    {
        gotoxy(45, v);
        cout << (char)186;
    }

   
    gotoxy(25, 27);
    SetConsoleTextAttribute(h, 10);
    cout << "Leaderboard: ";
    for (int i = 0; i < 10; ++i)
    {
        gotoxy(25, 28 + i);
        cout << "Puntaje: " << i + 1 << ":  ";
        printf("%d\n", puntajes[i]);

    }
    
}

void Puntaje::Restart(bool dead, char r)
{
    if (dead == true && r == 'r')
    {
        cosa = 0;

        gotoxy(10, 16);
        cout << "             ";
        for (int i = 0; i < 10; ++i)

        {
            gotoxy(10, 18 + i);
            cout << "             " << "   " << "  ";
            printf("           ", "         ");

        }

        if(y<10)
            y++;
        if (y == 10)
            y = 0;
    }
}