#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include"funciones.h"
///PROTOTIPO DEL JUEGO
void empezarJuego();

void empezarJuego(int prac, int cj){
    bool l[10][2],full=false,poker=false,generala=false,gene_servida=false,escalera=false,ganaporgene[2];
    int i,num_ronda,vuelta=0,tam=5,vec[5],puntuacion[2],punter[4],contador=0,cont2=0,canr=10,vt[2],x=0;
    char sq,jugador_1[2][20];;
    ///Pone en verdadero los puntos que se dara a elegir en cada ronda
    for(i=0; i<10; i++){
        l[i][0]=true;
        l[i][1]=true;
    }
    ///Vector de tiradas y puntuacion
    vt[0]=0;
    vt[1]=0;
    puntuacion[0]=0;
    puntuacion[1]=0;
    ///Pide el nombre del jugador o los jugadores
    jugadores(jugador_1,cj);

    if(prac==1){
        rlutil::locate(10,18);
        cout<<"Ingresar la cantidad de rondas con los que se quiere probar: ";
        cin>>canr;
        while(canr<1){
            rlutil::locate(10,19);
            cout<<"Ingrese una ronda mayor o igual a 1: ";
            cin>>canr;
        }
    }
    for (num_ronda=0; num_ronda<canr*cj; num_ronda++){
        if(num_ronda%cj==0){
            x++;
        }
        for(i=0; i<4; i++){
            ///Vector para asignar los puntos de las 4 jugadas
            punter[i]=0;
        }
        vuelta=1;
        rlutil::cls();
        marco(jugador_1,num_ronda,puntuacion,cj,vt,x);
        if(prac==1){
            for(i=0; i<5; i++)
            {
                cout<<"Ingresar los dados correspondientes: ";
                cin>>vec[i];
            }
        }else{
            ///Dados aleatorios
            cargardado(vec,5);
        }
        ///Estilo dado
        dados(vec,5);
        cout<<endl<<endl;
        ///Si no es practica, puede tirar
        if(prac!=1){
            cout<<"        Queres volver a tirar algunos dados \n         o queres conservar los actuales?\n"<<endl;
            cout<<"         Si queres volver a tirar, ingresa s, \n             en caso contrario, ingresa n"<<endl;
            cin>>sq;
        }
        rlutil::cls();
        marco(jugador_1,num_ronda,puntuacion,cj,vt,x);
        if (sq=='s'&&prac!=1){
            vueltas(vec,sq,vuelta,num_ronda,jugador_1,puntuacion,cj,vt,prac,x);
        }
        ///Acumula tiradas
        vt[num_ronda%cj]+=vuelta;
        rlutil::cls();
        marco(jugador_1,num_ronda,puntuacion,cj,vt,x);
        dados(vec,5);
        cout<<endl<<endl;
        int tama=6,contd[6];
        ///Contador de los dados iguales
        mirarnumeros(vec,tam,contd,tama);

        full=false,poker=false,generala=false,gene_servida=false,escalera=false;
        general_gene(vec,tam,generala,vuelta,gene_servida,contador,cont2,contd);
        if (gene_servida==true&&cj==1){
            ganaporgene[0]=true;
            ///suma 50 por generala servida
            puntuacion[0] += 50;
            break;
        }
        juegofull(contd,tama,full);
        juegopoker(vec,contd,tama,poker);
        juegoescalera(vec,contd,tama,escalera);
        if (escalera==true){
            punter[0]=25;
        }
        if (full==true){
            punter[1]=30;
        }
        if (poker==true){
            punter[2]=40;
        }
        if (generala==true){
            punter[3]=50;
        }

        juegos_posibles(vec,contd,tama,punter,gene_servida,l,cj,num_ronda,contador);
        if(gene_servida!=true){
            seleccionar(l,vec,contd,puntuacion,cj,num_ronda,punter);
        }
        if(gene_servida==true&&num_ronda%cj==1&&contador<2&&cont2!=3){
            ganaporgene[1]=true;
            break;
        }
        else{
            if(num_ronda%cj==1&&cont2!=0&&contador<2&&cont2!=3){
                ganaporgene[0]=true;
                break;
            }
            else{
                if(contador==2&&cont2!=3){
                    cout<<"ambos sacaron generala servida, por lo cual se\ncancelara la opcion de sacar generala\ny seguira la partida"<<endl;
                    l[9][0]=false;
                    l[9][1]=false;
                    cont2++;
                    system("pause");
                }
            }
        }
    }
    ganar(puntuacion,vt,jugador_1,cj,ganaporgene);
    mayorPuntuacion(puntuacion,jugador_1,cj,ganaporgene);
}
#endif // JUEGO_H_INCLUDED
