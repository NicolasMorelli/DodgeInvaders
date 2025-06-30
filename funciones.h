#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "clases.h"
#include <thread>
#include <cstring>

void menuPrincipal();
void configuracionDePantalla();
void delimitarARENA(int hud,int fondo);
void introducirJugador(nave* miNave);
void iniciarPartida(nave* miNave);
int generarNumeroAleatorio(int numeroAnterior,int numeroAnterior2);
void gameOver();
void mostrarPuntuacion(int puntaje);
void dibujarPuntos(int puntos);
void dibujarDODGEINVADER();
void juego();
void utilidadesDeArchivos(nave* miNave);
void escribir_archivo(archivoRanking* v);
void ordenarLista(int registros);
int contarRegistros();
void mostrarRanking();
bool verificarYSuscribir(nave* MiNave);
void mostrarHistorico();
void escribir_historico(historico* h);



#endif // FUNCIONES_H_INCLUDED
