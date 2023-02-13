#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>

using namespace std;
#include"rlutil.h"
#include"funciones.h"
#include"juego.h"

int main(){
    int y=0;
    while(true){
        rlutil::hidecursor();
        rlutil::setBackgroundColor(rlutil::DARKGREY);
        rlutil::setColor(rlutil::YELLOW);
        rlutil::cls();
////////    TITULO    ////////
        rlutil::locate(40,10);
        cout<<"GENERALA"<<endl;

        rlutil::locate(38,9);
        cout<<(char)201;
        rlutil::locate(38,10);
        cout<<(char)186;
        rlutil::locate(38,11);
        cout<<(char)200;
        for(int i=39; i<=48; i++){
            rlutil::locate(i,11);
            cout<<(char)205;
        }
        for(int i=39; i<=48; i++){
            rlutil::locate(i,9);
            cout<<(char)205;
        }
        rlutil::locate(49,9);
        cout<<(char)187;
        rlutil::locate(49,10);
        cout<<(char)186;
        rlutil::locate(49,11);
        cout<<(char)188;
////////    MENU OPCIONES    ////////
        showMenu("MODO PRACTICA", 37, 14, y==0);
        showMenu("UN JUGADOR", 37, 15, y==1);
        showMenu("DOS JUGADORES", 37, 16, y==2);
        showMenu("MAYOR PUNTUACION", 37, 17, y==3);
        showMenu("SALIR", 37, 18, y==4);

        rlutil::locate(33,13);
        cout<<(char)201;
        for(int i=14; i<=18; i++){
            rlutil::locate(33,i);
            cout<<(char)186;
        }
        rlutil::locate(33,19);
        cout<<(char)200;
        for(int i=34; i<=53; i++){
            rlutil::locate(i,13);
            cout<<(char)205;
        }
        rlutil::locate(54,13);
        cout<<(char)187;
        for(int i=14; i<=18; i++){
            rlutil::locate(54,i);
            cout<<(char)186;
        }
        for(int i=34; i<=53; i++){
            rlutil::locate(i,19);
            cout<<(char)205;
        }
        rlutil::locate(54,19);
        cout<<(char)188<<endl;

        rlutil::locate(35,14 + y);
        cout<<(char)175;

        switch(rlutil::getkey()){
            case 14: //TECLA ARRIBA
                rlutil::locate(35,14 + y);
                cout<<" ";
                y--;
                if(y<0)
                {
                    y = 0;
                }
                break;
            case 15: //TECLA ABAJO
                rlutil::locate(35,14 + y);
                cout<<" ";
                y++;
                if(y>4)
                {
                    y = 4;
                }
                break;
            case 1: // TECLA ENTER
                switch(y){
                case 0:
                    rlutil::cls();
                    empezarJuego(1,1);
                    system("pause");
                    break;
                case 1:
                    rlutil::cls();
                    empezarJuego(0,1);
                    system("pause");
                    break;
                case 2:
                    rlutil::cls();
                    empezarJuego(0,2);
                    system("pause");
                    break;
                case 3:
                    rlutil::cls();
                    mostrarMaximaPuntuacion();
                    system("pause");
                    break;
                case 4:
                    exit(EXIT_SUCCESS);
                    break;
                }
                break;
            }
    }
    rlutil::showcursor();
    return 0;
}

