#include <iostream>
using namespace std;
#include "rlutil.h"
#include "funciones.h"
#include "clases.h"
#include <cstring>

void iniciarPartida(nave* miNave){
        srand(time(0));
        int numeroAnterior = 0;
        int numeroAnterior2 = 0;
        int acumulador = 0;
        int acu=0;
        bool terminar = false;
        int puntos =0;
        const float PI = 3.14;
        naveEnemiga* enemigos[26] = {nullptr};

        while(terminar == false){
                dibujarPuntos(puntos);
                acumulador = acumulador + 50;

            if(acumulador == 150){
                naveEnemiga* enemigo = new naveEnemiga();
                enemigo->setPosicionX(26+(generarNumeroAleatorio(numeroAnterior,numeroAnterior2) * 6));
                enemigo->setPosicionY(6);

                if (enemigos[acu] != nullptr) {
                    enemigos[acu]->limpiarNave();       //->> limpia sin se excede de el limite de naves
                }

                enemigos[acu] = enemigo;
                acumulador = 0;
                acu++;
                if(acu == 26){acu = 0;}
            }

                for(int i=0;i<25;i++){
                    if (enemigos[i] != nullptr) {
                            enemigos[i]->limpiarNave();
                            enemigos[i]->comportamiento();     // comportamiento de los enemigos
                            enemigos[i]->pintarNave();

                            if(enemigos[i]->getPosicionY() >= 53){
                                enemigos[i]->limpiarNave();                   // limpia si llega al limite
                                enemigos[i] = nullptr;
                                break;
                           }

                           if (abs(enemigos[i]->getPosicionX() - miNave->getPosicionX()) < 6 && abs(enemigos[i]->getPosicionY() - miNave->getPosicionY()) < 5) {
                                    miNave->setVidas(miNave->getVidas()-1);     //   colision con enemigo
                                    enemigos[i]->limpiarNave();                 //
                                    enemigos[i] = nullptr;

                                        rlutil::setBackgroundColor(7);          //
                                    for(int i=0;i<40;i++){                      //
                                        rlutil::locate(209,8+i);                // LIMPIEZA DE CORAZONES
                                        cout << "         ";                    //
                                    }
                                        rlutil::setBackgroundColor(0);          //
                                }
                    }
                }



            miNave->definirLimites();
            miNave->limpiarNave();             // ---> manejo del jugador mediante la referencia
            miNave->pintarNave();
            miNave->pintarVidas();
            miNave->setMoviendose(false);


            if(miNave->getVidas() < 1){                                 // endeo del juego
                for(int i=0;i<24;i++){
                    if (enemigos[i] != nullptr) {
                        enemigos[i]->limpiarNave();
                        rlutil::msleep(150);
                    }
                }

                miNave->limpiarNave();
                gameOver();
                miNave->setPuntuacion(puntos);
                mostrarPuntuacion(miNave->getPuntuacion());
                utilidadesDeArchivos(miNave);                                // archivos
                rlutil::msleep(3000);

                terminar = true;                                        // endeo del juego
            }
            puntos+=2*PI;     // -> puntos por vuelta
        }


    }


