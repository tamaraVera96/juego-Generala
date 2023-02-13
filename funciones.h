#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
///PROTOTIPO
void cargarCadena(char *pal, int tam);
void showMenu(const char* text, int posx, int posy, bool selected);
void ganar(int puntuacion[],char jugador_1[2][20],int cj,bool ganaporgene[]);
void jugadores(char jugador_1[2][20],int cj);
void dados(int vec[],int tam);
void marco(char jugador_1[2][20],int num_ronda,int puntuacion[],int cj,int vt[],int x);
void general_gene(int vec[],int tama,bool& generala,int vuelta,bool& gene_servida,int& contador,int& cont2,int contd[]);
void juegopoker(int vec[],int contd[],int tama,bool& poker);
void juegos_posibles(int vec[],int contd[],int tama,int punter[],bool gene_servida,bool l[10][2],int cj,int num_ronda,int contador);
void juegofull(int contd[],int tama,bool& full);
void juegoescalera(int vec[],int contd[],int tama,bool& escalera);
void mirarnumeros(int vec[],int tam,int contd[],int tama);
void vueltas(int vec[],char sq,int& vuelta,int num_ronda,char jugador_1[2][20],int puntuacion[],int cj,int vt[],bool prac, int x);
void cargardado(int vec[], int tam);
void seleccionar(bool l[10][2],int vec[],int contd[], int puntuacion[],int cj,int num_ronda,int punter[]);
void mayorPuntuacion();
void mostrarMaximaPuntuacion();

void cargarCadena(char *pal, int tam) {
	int i;
	fflush(stdin);
	for(i=0; i<tam; i++) {
		pal[i]=cin.get();
		if(pal[i]=='\n') break;
	}
	pal[i]='\0';
	fflush(stdin);
}
void showMenu(const char* text, int posx, int posy, bool selected) {
	if(selected) {
		rlutil::setBackgroundColor(rlutil::CYAN);
	}
	rlutil::locate(posx,posy);
	cout<<text<<endl;
	rlutil::setBackgroundColor(rlutil::DARKGREY);
}
void ganar(int puntuacion[],int vt[],char jugador_1[2][20],int cj,bool ganaporgene[]) {
	int i,u,y;
	rlutil::cls();
	for (i=15; i<67; i++) {
		rlutil::locate(i,5);
		cout<<(char)220;
		rlutil::locate(i,30);
		cout<<(char)220;
	}
	rlutil::locate(66,5);
	cout<<(char)220;
	for (i=6; i<31; i++) {
		rlutil::locate(66,i);
		cout<<(char)219;
		rlutil::locate(15,i);
		cout<<(char)219;
	}
	if(puntuacion[0]>puntuacion[1]) {
		u=0;
		y=1;
	} else {
		if(puntuacion[0]<puntuacion[1]) {
			u=1;
			y=0;
		} else {
			if(vt[0]>vt[1]) {
				u=0;
				y=1;
			} else {
				if(vt[0]<vt[1]) {
					u=1;
					y=0;
				} else {
					rlutil::locate(20,10);
					cout<<"hubo un empate, tanto en puntos como en tiradas,\n por lo cual no habra un desempate.";
					getch();
				}
			}
		}
	}
/*	//Gana por generala y le suma 50 automaticamente
	  for(i=0; i<=1; i++){
	       if(ganaporgene[i]==true){
	           rlutil::locate(18,9);
	           cout<<"Ganaste Por generala servida, felicitaciones:";
	           rlutil::locate(40,22);
	           cout<<jugador_1[i]<<endl;
	           puntuacion[i]+=50;
	           getch();
	       }
	   }*/
	if(cj==1) {
		rlutil::locate(37,12);
		cout<<"GANASTE";
		rlutil::locate(16,15);
		cout<<"El ganador fue "<<jugador_1[u];
		rlutil::locate(16,17);
		cout<<"Gano con un puntaje de "<<puntuacion[u];
		rlutil::locate(16,19);
		cout<<"Con una cantidad de vueltas equivalente a: "<<vt[u];
		rlutil::locate(16,21);
	} else {
		rlutil::locate(32,10);
		cout<<"   GANO "<<jugador_1[u];
		rlutil::locate(16,13);
		cout<<"El ganador fue "<<jugador_1[u];
		rlutil::locate(16,15);
		cout<<"Gano con un puntaje de "<<puntuacion[u];
		rlutil::locate(16,17);
		cout<<"Con una cantidad de vueltas equivalente a: "<<vt[u];
		rlutil::locate(16,20);
		cout<<"El segundo puesto fue para "<<jugador_1[y];
		rlutil::locate(16,22);
		cout<<"Termino con un puntaje de "<<puntuacion[y];
		rlutil::locate(16,24);
		cout<<"Con una cantidad de vueltas equivalente a: "<<vt[y];
		rlutil::locate(16,26);
	}
	rlutil::locate(1,29);
	getch();
}
void jugadores(char jugador_1[2][20],int cj) {
	rlutil::setBackgroundColor(rlutil::DARKGREY);
	rlutil::setColor(rlutil::YELLOW);
	rlutil::cls();
	rlutil::locate(30,11);
	cout<<"Ingresar el nombre del primer jugador: "<<endl<<endl;
	rlutil::locate(37,15);
	cargarCadena(jugador_1[0],19);
	if(cj==2) {
		rlutil::locate(30,18);
		cout<<"Ingresar el nombre del segundo jugador: "<<endl<<endl;
		rlutil::locate(37,22);
		cargarCadena(jugador_1[1],19);
	}
}
void dados(int vec[],int tam) {
	int i;
	rlutil::locate(1,5);
	for(i=1; i<=5; i++) {
		cout<<"| Dado "<<i<<" |";
	}
	cout<<endl;
	for(i=0; i<5; i++) {
		cout<<"|        |";
	}
	cout<<endl;
	for (i=0; i<5; i++) {
		cout<<"|   "<<vec[i]<<"    |";
	}
	cout<<endl;
	for(i=0; i<5; i++) {
		cout<<"|________|";
	}

	rlutil::locate(1,9);
	cout<<"-----------------------------------------------------"<<endl;
	cout<<"-----------------------------------------------------"<<endl;
}
void marco(char jugador_1[2][20],int num_ronda,int puntuacion[],int cj,int vt[],int x) {
	int rond,rond_punt=0;
	if (num_ronda%cj==0) {
		rond=0;
	} else {
		rond=1;

	}
	if(puntuacion[1]>puntuacion[0]) {
		rond_punt=1;
	} else {
		rond_punt=0;
	}
	rlutil::setBackgroundColor(rlutil::DARKGREY);
	rlutil::setColor(rlutil::YELLOW);
	rlutil::cls();
	cout<<"\n";
	cout<<"   RONDA DE "<<jugador_1[rond];
	cout<<" || RONDA N"<<x;
	cout<<" || PUNTAJE TOTAL: "<<puntuacion[rond]<<endl;
	rlutil::locate(1,3);
	cout<<"-----------------------------------------------------"<<endl;
	cout<<"-----------------------------------------------------"<<endl;

	for(int i=1; i<=33; i++) {

		rlutil::locate(54,i);
		cout<<(char)186;
	}
	rlutil::locate(54,1);
	cout<<(char)201;
	rlutil::locate(54,33);
	cout<<(char)200;
	for(int i=55; i<=79; i++) {
		rlutil::locate(i,33);
		cout<<(char)205;
	}
	rlutil::locate(80,33);
	cout<<(char)188;
	for(int i=33; i>=3; i--) {
		rlutil::locate(80,i-1);
		cout<<(char)186;
	}
	rlutil::locate(80,1);
	cout<<(char)187;
	for(int i=80; i>=56; i--) {
		rlutil::locate(i-1,1);
		cout<<(char)205;
	}
	if(num_ronda>=cj) {
		rlutil::locate(58,4);
		cout<<"La mayor cantidad de"<<endl;
		rlutil::locate(58,5);
		cout<<"puntuacion la tiene"<<endl;
		rlutil::locate(65,6);
		cout<<jugador_1[rond_punt]<<endl;
		rlutil::locate(58,14);
		cout<<"La puntuacion mayor"<<endl;
		rlutil::locate(58,15);
		cout<<"De la partida es de"<<endl;
		rlutil::locate(63,16);
		cout<<puntuacion[rond_punt]<<" puntos"<<endl;
		rlutil::locate(58,23);
		cout<<"  La cantidad de";
		rlutil::locate(58,24);
		cout<<" tiradas realizadas";
		rlutil::locate(58,25);
		cout<<"por este usuario es:";
		rlutil::locate(67,26);
		cout<<vt[rond_punt];
	}
	rlutil::locate(1,6);
}
void general_gene(int vec[],int tama,bool& generala,int vuelta,bool& gene_servida,int& contador,int& cont2,int contd[]) {
	for (int i=0; i<6; i++) {
		if (contd[i]==5) {
			if(vuelta==1&&cont2<3) {
				gene_servida=true;
				contador++;
				cont2++;
				generala=true;
			} else {
				contador=0;
				generala=true;
			}
		}
	}
}
void juegopoker(int vec[],int contd[],int tama,bool& poker) {
	int i;
	for (i=0; i<6; i++) {
		if(contd[i]==4) {
			poker=true;
		}
	}
}
void juegos_posibles(int vec[],int contd[],int tama,int punter[],bool gene_servida,bool l[10][2],int cj,int num_ronda,int contador) {
	int i,n=num_ronda%cj;
	if((gene_servida!=true)||(l[9][n]==false)) {
		for(i=0; i<6; i++) {
			if(l[i][n]==true) {
				cout<<contd[i]*(i+1);
				cout<< " Puntos al numero: "<<i+1<<endl;
			}
		}
		if (l[6][n]==true) {
			cout<<punter[0]<<" Puntos en el juego de la escalera: 7";
		}
		cout<<endl;
		if(l[7][n]==true) {
			cout<<punter[1]<<" Puntos en el juego de full: 8";
		}
		cout<<endl;
		if (l[8][n]==true) {
			cout<<punter[2]<<" Puntos en el juego de poker: 9";
		}
		cout<<endl;
		if(l[9][n]==true) {
			cout<<punter[3]<<" Puntos en el juego de la generala: 10";
		}
		cout<<endl<<endl;
	} else {
		if(gene_servida==true&&contador!=2&&n==0&&l[9][n]==true) {
			cout<<"    Parece que sacaste generala servida.\n    Debes esperar a tu rival."<<endl;
			system("pause");
		}
	}
}
void juegofull(int contd[],int tama,bool& full) {
	int i,c;
	for(i=0; i<6; i++) {
		if (contd[i]==3) {
			for(c=0; c<6; c++) {
				if(contd[c]==2) {
					full=true;
				}
			}
		}
	}
}
void juegoescalera(int vec[],int contd[],int tama,bool& escalera) {
	int c=0,i=0;
	while (i<=tama&&c<5) {
		if (contd[i]==1) {
			c++;
		} else {
			c=0;
		}
		i++;
	}
	if (c==5) {
		escalera=true;
	}
}
void mirarnumeros(int vec[],int tam,int contd[],int tama) {
	int i;
	for(i=0; i<tama; i++) {
		contd[i]=0;
	}
	for (int i=0; i<5; i++) {
		contd[vec[i]-1]=contd[vec[i]-1]+1;
	}
}
void vueltas(int vec[],char sq,int& vuelta,int num_ronda,char jugador_1[2][20],int puntuacion[],int cj,int vt[],bool prac, int x) {
	int o=0;
	do {
		srand(time(NULL));
		rlutil::cls();
		marco(jugador_1,num_ronda,puntuacion,cj,vt,x);
		dados(vec,5);
		cout<<"\n\n       Cuales numeros de dado desea modificar?\n       Mandar 0 en caso de no querer modificar."<<endl;
		cin>>o;
		do {
			vec[o-1]=1+rand()%(7-1);
			cin>>o;
		} while (o!=0);
		vuelta++;
		rlutil::cls();
		marco(jugador_1,num_ronda,puntuacion,cj,vt,x);
		dados(vec,5);
		cout<<"Queres seguir tirando dados? s/n  "<<endl;
		cin>>sq;
		if (vuelta==3&&sq=='s') {
			cout<<"Ya gastaste tus tres tiradas en esta ronda"<<endl;
			system ("pause");
		}
	} while(vuelta<3&&sq=='s');
}
void cargardado(int vec[], int tam) {
	srand(time(NULL));
	for (int z = 0; z < tam; z++) {
		vec[z] = 1+rand()%(7-1);
	}
}
void seleccionar(bool l[10][2],int vec[],int contd[], int puntuacion[],int cj,int num_ronda,int punter[]) {
	int elegir;
	cout<<"Ingrese el numero o juego que queres\nsumar puntaje o anular."<<endl;
	cin>>elegir;
	int n=num_ronda%cj;
	///Suma el puntaje y se anula la jugada poniendo falso.
	switch (elegir) {
		case 7:
			puntuacion[n]=puntuacion[n]+punter[0];
			l[6][n]=false;
			break;
		case 8:
			puntuacion[n]=puntuacion[n]+punter[1];
			l[7][n]=false;
			break;
		case 9:
			puntuacion[n]=puntuacion[n]+punter[2];
			l[8][n]=false;
			break;
		case 10:
			puntuacion[n]=puntuacion[n]+punter[3];
			l[9][n]=false;
			break;
		default:
			puntuacion[n]=puntuacion[n]+contd[elegir-1]*elegir;
			l[elegir-1][n]=false;
			break;
	}
}
///Variables de la funcion de maxima puntuación
int puntuacionAlta = 0;
char nombreGanador[20] = "";
//------------
void mayorPuntuacion(int puntuacion[],char jugador_1[2][20],int cj,bool ganaporgene[]) {
	int  u, y;
	if(puntuacion[0]>puntuacion[1]) {
		u=0;
		y=1;
	} else if(puntuacion[0]<puntuacion[1]) {
		u=1;
		y=0;
	}
	if(puntuacion[u]>puntuacionAlta) {
		puntuacionAlta = puntuacion[u];
		strcpy(nombreGanador,jugador_1[u]);
	}
}

///Muestra la puntuación máxima
void mostrarMaximaPuntuacion(){
	cout<<"LA MAYOR PUNTUACION ES DE: "<<puntuacionAlta<<endl;
	cout<<"NOMBRE DEL JUGADOR: "<<nombreGanador<<endl;
}

#endif // FUNCIONES_H_INCLUDED
