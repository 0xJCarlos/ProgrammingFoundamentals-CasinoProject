//PROYECTO FINAL FUNDAMENTOS DE PROGRAMACIÓN    -   JUAN CARLOS SOLÓRZANO CASTANEDO -   CUCEA 2020B
#include<iostream>
#include <cstdlib>
#include<cstdio>
#include<ctime>
#include <bits/stdc++.h>
#define M 4
#define N 3
using namespace std;

int jugadores,ganador,perdedor;
string nombre[4];
int pool=0;
int dinerototal[4],tiros[4][3],dinero[4],tirosfinal[4][3], fapuesta[4];

void juego(int apuesta[], int tam){ //Nombre y dinero disponible para apostar de cada jugador
    for(int i=0; i<tam; i++){
        cout<<"El nombre del jugador "<<i+1<<" es: ";
        cin>>nombre[i];
        cout<<"El jugador "<<nombre[i]<<" pone para apostar: ";
        cin>>dinero[i];
        dinerototal[i]=dinero[i];
    }system("CLS");
}
void setup(){ //Setup del juego, reglas para comenzar,guarda el pool
    int dinero[jugadores];
    cout<<"BIENVENIDO AL CASINO VIRTUAL\n";
    cout<<"¿Cuantas personas jugaran?: ";
    cin>>jugadores;
    int tiros[jugadores];
    system("CLS");

    if(jugadores>4){
        cout<<"El maximo de jugadores es de 4"<<endl;
        system("pause"),system("CLS");
        return(setup());
    }
    else if(jugadores<2){
        cout<<"El minimo de jugadores es de 2 "<<endl;
        system("pause"),system("CLS");
        return(setup());
    }
int total[jugadores];
juego(total,jugadores);
    for(int i=0; i<jugadores; i++){
        cout<<"\nJugador "<<i+1<<" "<<nombre[i]<<endl<<"Cantidad Total: "<<dinerototal[i]<<endl;
    }
    system("pause"),system("CLS");
    for (int i=0;i<jugadores;i++){
        pool+=dinerototal[i];
    }
}
void tirada(){ //Tira 3 dados random por jugador,apuestas de cada jugador y los guarda en arreglo
srand(time(NULL));
int tiros[jugadores][4];

for (int i=0;i<jugadores;i++){
    cout<<"Jugador "<<nombre[i]<<" tira ahora\n\n";
    cout<<"* * * * * * * * *\n*      oo       *\n*       o       *\n*        o      *\n*        o      * \n*               *\n* * * * * * * * *\n";
    for (int j=0;j<3;j++){
        tiros[i][j]=1+rand()%6;
        cout<<tiros[i][j]<<" ";
        tirosfinal[i][j]=tiros[i][j];
    }
    do{
    cout<<endl<<"La cantidad disponible para apostar es: "<<dinerototal[i]<<endl;
    cout<<"¿Cuanto deseas apostar: ";
    cin>>tiros[i][4];
    fapuesta[i]=tiros[i][4];
    cout<<endl;
        if (tiros[i][4]>dinerototal[i]){
            cout<<"Apuesta invalida"<<endl;
        }
    }
    while(tiros[i][4]>dinerototal[i]);
    system("pause");
    system("CLS");
}
}

void resultados(){ //Determina resultados *
int triple=0,doble=0,simple=0;
int mayorI=0,menorI=0;
int empate[4];

for (int i=0;i<jugadores;i++){
    if (tiros[i][0]==tiros[i][1] && tiros[i][1]==tiros[i][2]){
        if (tiros[i][0]>triple){
            triple=tiros[i][0];
            ganador=-1;
            ganador=i+1;
        }
    }

    if (tiros[i][0]==tiros[i][1] || tiros[i][0]==tiros[i][2]){
        if (tiros[i][0]>doble){
            doble=tiros[i][0];
            ganador=-1;
            ganador=i+1;
        }
    }
    if (tiros[i][0]==tiros[i][1] || tiros[i][0]==tiros[i][2]){
        if (tiros[i][0]>doble){
            doble=tiros[i][0];
            ganador=-1;
            ganador=i+1;
            }
        }
    if(tiros[i][1]==tiros[i][2]){
        if (tiros[i][1]>doble){
            doble=tiros[i][1];
            ganador=-1;
            ganador=i+1;
        }
    }

    if (tirosfinal[i][0]!=tirosfinal[i][1] && tirosfinal[i][0]!=tirosfinal[i][2] && tirosfinal[i][1]!=tirosfinal[i][2]){
        for (int j=0;j<3;j++){
            if (mayorI<tirosfinal[i][j]){
                mayorI=tirosfinal[i][j];
                ganador=-1;
                ganador=i+1;
            }
        }
    }
}
menorI=mayorI;
for (int i=0;i<jugadores;i++){
    for(int j=0;j<3;j++){
        if (menorI<doble<triple ){
            if (menorI>tirosfinal[i][j]){
                menorI=tirosfinal[i][j];
            }
        }
    }
}
//Aquí se muestran los resultados
cout<<"El pool es: "<<pool<<endl;
    for (int i=0; i<jugadores;i++){
        cout<<nombre[i]<<": ";
        for (int j=0; j<3;j++){
            cout<<tirosfinal[i][j]<<" ";
        }
        cout<<" "<<fapuesta[i];
        cout<<endl;
    }
cout<<"El ganador es: "<<nombre[ganador]<<endl;
cout<<"El perdedor es: "<<nombre[perdedor]<<endl;

system("pause");
}

main(){
    setup();
    system("CLS");
    tirada();
    resultados();
}
/*
Profe, si está leyendo esto, primero que nada buen día jaja. La verdad este ha sido un reto como ningún otro, puso mi pensamiento y todo mi ser a prueba
Al final en la parte para obtener los resultados quedó masomenos, y si, estoy conciente de que faltaron algunas cositas como mover el dinero dependiendo de los resultados
Y mostrar si hubo algún empate, lamentablemente el tiempo me alcanzó aún con todas las desveladas que me dí intentando terminar este proyecto, la verdad fue una buena experiencia
que ayudó a desarrollar mis habilidades programando, aunque también cabe mencionar que afectó de manera negativa a mi salud fisica y mental, esto de estar 12 horas al día
programando si afecta jaja. Aunque igual aprecio mucho todo lo que aprendí este semestre. Mi experiencia en su clase fue 10/10, se le estima muchisimo profesor, le deseo lo
mejor en estas fechas, felices fiestas!.
*/
