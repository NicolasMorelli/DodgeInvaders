#include <iostream>
using namespace std;
#include "rlutil.h"
#include "funciones.h"
#include "clases.h"
#include <thread>
#include <cstring>


    void nave::pintarNave(){
            rlutil::setColor(10);
            rlutil::locate(posicionX,posicionY);
                cout << nave[0][0] << nave[0][1] << nave[0][2] << nave[0][3] << nave[0][4] << nave[0][5];
            rlutil::locate(posicionX,posicionY+1);
                cout << nave[1][0] << nave[1][1] << nave[1][2] << nave[1][3] << nave[1][4] << nave[1][5];
            rlutil::locate(posicionX,posicionY+2);
                cout << nave[2][0] << nave[2][1] << nave[2][2] << nave[2][3] << nave[2][4] << nave[2][5];
            rlutil::locate(posicionX,posicionY+3);
                cout << nave[3][0] << nave[3][1] << nave[3][2] << nave[3][3] << nave[3][4] << nave[3][5];
            rlutil::locate(posicionX,posicionY+4);
                cout << nave[4][0] << nave[4][1] ;
                rlutil::setColor(12);
                cout << nave[4][2] << nave[4][3];
                rlutil::setColor(10);
                cout << nave[4][4] << nave[4][5];
        }

    void nave::limpiarNave(){
            rlutil::locate(posicionXBackup,posicionYBackup);
                cout << " " << " " << " " << " " << " " << " ";
            rlutil::locate(posicionXBackup,posicionYBackup+1);
                cout << " " << " " << " " << " " << " " << " ";
            rlutil::locate(posicionXBackup,posicionYBackup+2);
                cout << " " << " " << " " << " " << " " << " ";
            rlutil::locate(posicionXBackup,posicionYBackup+3);
                cout << " " << " " << " " << " " << " " << " ";
            rlutil::locate(posicionXBackup,posicionYBackup+4);
                cout << " " << " " << " " << " " << " " << " ";
        }

    void nave::guardarPosicionAnterior(){
            posicionXBackup = posicionX;
            posicionYBackup = posicionY;
        }

    void nave::definirLimites(){
        if(posicionX < 39){posicionX = 40;}
        if(posicionX > 195){posicionX = 194;}
        if(posicionY > 53){posicionY = 53;}
        if(posicionY < 8){posicionY = 8;}
    }

    void nave::pintarVidas(){
        rlutil::setBackgroundColor(7);
        rlutil::setColor(12);

        int y=8;

        for(int i=0;i<vidas;i++){
        rlutil::locate(210,y);
        cout << char(220) << char(220) << char(220) << " " << char(220) << char(220)  <<  char(220);
        rlutil::locate(208,y+1);
        cout << " " <<char(219)<< char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) <<char(219) << " ";
        rlutil::locate(208,y+2);
        cout << " " << char(223)<< char(219) << char(219) << char(219) <<char(219) << char(219) << char(219) << char(219) << char(223) << " ";
        rlutil::locate(210,y+3);
        cout << " " << char(223) <<char(219) <<char(219) << char(219) << char(223) << " ";
        rlutil::locate(213,y+4);
        cout << char(223);
            y+=8;
        }
        rlutil::setBackgroundColor(0);
    }

    void naveEnemiga::comportamiento(){
        if(estado == true){
            posicionY++;
        };
    }

    void naveEnemiga::pintarNave(){
            rlutil::setColor(4);
            rlutil::locate(posicionX,posicionY);
                cout << nave[0][0] << nave[0][1] << nave[0][2] << nave[0][3] << nave[0][4] << nave[0][5];
            rlutil::locate(posicionX,posicionY+1);
                cout << nave[1][0] << nave[1][1] << nave[1][2] << nave[1][3] << nave[1][4] << nave[1][5];
            rlutil::locate(posicionX,posicionY+2);
                cout << nave[2][0] << nave[2][1] << nave[2][2] << nave[2][3] << nave[2][4] << nave[2][5];
            rlutil::locate(posicionX,posicionY+3);
                cout << nave[3][0] << nave[3][1] << nave[3][2] << nave[3][3] << nave[3][4] << nave[3][5];
            rlutil::locate(posicionX,posicionY+4);
                cout << nave[4][0] << nave[4][1] ;
                rlutil::setColor(15);
                cout << nave[4][2] << nave[4][3];
                rlutil::setColor(4);
                cout << nave[4][4] << nave[4][5];
        }

    void naveEnemiga::limpiarNave(){
            rlutil::locate(posicionX,posicionY);
                cout << " " << " " << " " << " " << " " << " ";
            rlutil::locate(posicionX,posicionY+1);
                cout << " " << " " << " " << " " << " " << " ";
            rlutil::locate(posicionX,posicionY+2);
                cout << " " << " " << " " << " " << " " << " ";
            rlutil::locate(posicionX,posicionY+3);
                cout << " " << " " << " " << " " << " " << " ";
            rlutil::locate(posicionX,posicionY+4);
                cout << " " << " " << " " << " " << " " << " ";
        }

    void naveEnemiga::guardarPosicionAnterior(){
            posicionXBackup = posicionX;
            posicionYBackup = posicionY;
        }




  //  bool operator ==(const archivoRanking& reg, const nave& otro) {
  //          return !(strcmp(reg.getNombre(),otro.getNombre()));            // SOBRECARGA DE OPERADOR
  //      }
