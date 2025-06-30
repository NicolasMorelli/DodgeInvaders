#include <iostream>
using namespace std;
#include "rlutil.h"
#include "funciones.h"
#include "clases.h"



    void menuPrincipal(){
        rlutil::cls();

  int op = 1, y = 0;
  rlutil::hidecursor();
  do {
    dibujarDODGEINVADER();
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(113, 20);
    cout << "JUGAR";
    rlutil::locate(110, 25);
    cout << "VER RANKING";
    rlutil::locate(105, 30);
    cout << "HISTORICO DE JUGADORES";
    rlutil::locate(113, 35);
    cout << "SALIR\n";



    rlutil::locate(130, 20 + y);
    cout << char(60)<< char(60)<< (char)254 << (char)254 << endl;
    rlutil::locate(95, 20 + y);
    cout << (char)254 << (char)254 << (char)62 << (char)62 << endl;

    int key = rlutil::getkey();
    switch (key) {
    case 14: // UP
      rlutil::locate(95, 20 + y);
      cout << "    " << endl;
      rlutil::locate(130, 20 + y);
      cout << "    " << endl;
      y-=5;
      if (y < 0) {
        y = 0;
      }
      break;
    case 15: // DOWN
      rlutil::locate(95, 20 + y);
      cout << "    " << endl;
      rlutil::locate(130, 20 + y);
      cout << "    " << endl;
      y+=5;
      if (y > 14) {
        y = 15;
      }
      break;
    case 1: // ACEPTAR
      switch (y) {
      case 0:
        op = 1;
        juego();
        rlutil::cls();
        break;
      case 5:
        op = 1;
        mostrarRanking();
        rlutil::cls();
        break;
      case 10:
        op=1;
        mostrarHistorico();
        rlutil::cls();
        break;
      case 15:
        rlutil::cls();
        rlutil::setColor(rlutil::WHITE);
        cout << "¡Hasta la proxima!"<< endl;
        op = 0;
        break;
      }
    }

  } while (op != 0);
  return;

}

    void configuracionDePantalla(){
        const int H = 237;
        const int V = 63;

        for(int i=0;i<74;i++){
            rlutil::locate(23+i,13);
            cout << char (219);
            rlutil::locate(23+i,21);
            cout << char (219);
            rlutil::locate(23+i,23);
            cout << char (219);
        }

        for(int i=0;i<10;i++){
            rlutil::locate(96,13+i);
            cout << char (219);
            rlutil::locate(23,13+i);
            cout << char (219);
        }

        rlutil::locate(25,15);
        cout << "CONFIGURA EL TAMANIO DE LA PESTANIA HASTA OBTENER LOS VALORES DESEADOS";
        rlutil::locate(25,17);
        cout << "RESULTADOS ESPERADOS";
        rlutil::locate(50,17);
        cout << "X: " << H;
        rlutil::locate(60,17);
        cout << "Y: " << V;

        while (true) {
        rlutil::hidecursor();
        int a = rlutil::tcols();
        int b = rlutil::trows();
        rlutil::locate(53, 19);
        cout << a;
        rlutil::locate(63, 19);
        cout << b;
        rlutil::msleep(100);

            rlutil::locate(24,22);
        if(a == H && b == V) {
            rlutil::msleep(1000);
            for(int a=0;a<4;a++){
                rlutil::setColor(1);
                for(int c=0;c<18;c++){
                    cout << char(219);
                    rlutil::msleep(25);
                    }
                rlutil::setColor(7);
                }
                int a = rlutil::tcols();
                int b = rlutil::trows();

                if(a == H && b == V){
                        rlutil::msleep(300);
                        break;}

                if(a != H || b != V){
                    rlutil::locate(24,22);
                    for(int i=0;i<72;i++){cout << " ";}
                  }
            }
        }
    }

    void introducirJugador(nave* miNave){
        bool terminar = false;
        miNave->setPosicionX(116);
        miNave->setPosicionY(50);

  while(terminar == false) {
  rlutil::hidecursor();
    int key = rlutil::getkey();
    if(miNave->getMoviendose() == false){
            switch (key) {
        case 14: // UP
            miNave->guardarPosicionAnterior();
            miNave->setPosicionY(miNave->getPosicionY()-3);
          break;
        case 15: // DOWN
            miNave->guardarPosicionAnterior();
            miNave->setPosicionY(miNave->getPosicionY()+3);
          break;
        case 16: // LEFT
            miNave->guardarPosicionAnterior();
            miNave->setPosicionX(miNave->getPosicionX()-6);
          break;
        case 17: // RIGHT
            miNave->guardarPosicionAnterior();
            miNave->setPosicionX(miNave->getPosicionX()+6);
          break;
          }

        miNave->setMoviendose(true);
        if(miNave->getVidas()<1){
            terminar = true;
        }
    }

 }

}

    void delimitarARENA(int hud, int fondo){
        rlutil::setBackgroundColor(hud);
        rlutil::cls();
        rlutil::setColor(fondo);


        for(int i=0;i<5;i++){
            rlutil::locate(0,i);
            for(int i=0;i<237;i++){
                cout << char (219);
            }
        }

        for(int i=0;i<7;i++){
            rlutil::locate(1,58+i);
            for(int i=0;i<237;i++){
                cout << char (219);
            }
        }



        for(int i=0;i<57;i++){
            rlutil::locate(1,1+i);
            for(int i=0;i<35;i++){
                cout << char(219);
            }
            rlutil::locate(202,1+i);
            for(int i=0;i<35;i++){
                cout << char(219);
            }
        }
    rlutil::locate(40,57);
    }

    int generarNumeroAleatorio(int numeroAnterior,int numeroAnterior2){

        int numeroAleatorio = (rand() % 28) + 1;

        if(numeroAnterior == numeroAleatorio){
            return generarNumeroAleatorio(numeroAnterior,numeroAnterior2);
        }

        if(abs(numeroAnterior-numeroAleatorio) == 1 || abs(numeroAnterior2-numeroAleatorio) == 1){
            return generarNumeroAleatorio(numeroAnterior,numeroAnterior2);
        }


        numeroAnterior2 = numeroAnterior;
        numeroAnterior = numeroAleatorio;

        return numeroAleatorio;
    }

    void gameOver(){
        for(int i=0;i<5;i++){
        rlutil::cls();
            rlutil::msleep(30);
        rlutil::locate(80,25);
            cout << "   _____          __  __ ______    ______      ________ _____  ";
        rlutil::msleep(40);
        rlutil::locate(80,26);
            cout << "  / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\/ ";
        rlutil::msleep(50);
        rlutil::locate(80,27);
            cout << " | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |";
        rlutil::msleep(60);
        rlutil::locate(80,28);
            cout << " | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  / ";
        rlutil::msleep(70);
        rlutil::locate(80,29);
            cout << " | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\ ";
        rlutil::msleep(80);
        rlutil::locate(80,30);
            cout << "  \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\";
        rlutil::msleep(90);
        }
    }

    void mostrarPuntuacion(int puntaje){
        rlutil::locate(105,35);
        cout << "PUNTUACION : " << puntaje;
    }

    void dibujarPuntos(int puntos){
        rlutil::locate(115,7);
        cout << "PUNTOS: " << puntos;
    }

    void dibujarDODGEINVADER(){
    rlutil::setColor(4);
    rlutil::locate(55,5);
    cout << "$$$$$$$\\   $$$$$$\\  $$$$$$$\\   $$$$$$\\  $$$$$$$$\\       $$$$$$\\ $$\\   $$\\ $$\\    $$\\  $$$$$$\\  $$$$$$$\\  $$$$$$$$\\ $$$$$$$\\   $$$$$$\\  ";
    rlutil::locate(55,6);
    cout << "$$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ $$  _____|      \\_$$  _|$$$\\  $$ |$$ |   $$ |$$  __$$\\ $$  __$$\\ $$  _____|$$  __$$\\ $$  __$$\\ ";
    rlutil::locate(55,7);
    cout << "$$ |  $$ |$$ /  $$ |$$ |  $$ |$$ /  \\__|$$ |              $$ |  $$$$\\$$  |$$ |   $$ |$$ /  $$ |$$ |  $$ |$$ |      $$ |  $$ |$$ /  \\__|";
    rlutil::locate(55,8);
    cout << "$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |$$$$\\ $$$$$\\            $$ |  $$ $$\\$$ |\\$$\\  $$  |$$$$$$$$ |$$ |  $$ |$$$$$\\    $$$$$$$  |\\$$$$$$\\ ";
    rlutil::locate(55,9);
    cout << "$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |\\_$$ |$$  __|           $$ |  $$ \\$$$$ | \\$$\\$$  / $$  __$$ |$$ |  $$ |$$  __|   $$  __$$<  \\____$$\\";
    rlutil::locate(55,10);
    cout << "$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |              $$ |  $$ |\\$$$ |  \\$$$  /  $$ |  $$ |$$ |  $$ |$$ |      $$ |  $$ |$$\\   $$ |";
    rlutil::locate(55,11);
    cout << "$$$$$$$  | $$$$$$  |$$$$$$$  |\\$$$$$$  |$$$$$$$$\\       $$$$$$\\ $$ | \\$$ |   \\$  /   $$ |  $$ |$$$$$$$  |$$$$$$$$\\ $$ |  $$ |\\$$$$$$  |";
    rlutil::locate(55,12);
    cout << "\\_______/  \\______/ \\_______/  \\______/ \\________|      \\______|\\__|  \\__|    \\_/    \\__|  \\__|\\_______/ \\________|\\__|  \\__| \\______/ ";
    }

    void juego(){
    nave *jugador = new nave;
        rlutil::cls();
        char nombre[20];
        rlutil::locate(110,45);
        cout << "INGRESA UN NOMBRE: ";
        cin >> nombre;
        jugador->setNombre(nombre);
        rlutil::cls();

    delimitarARENA(0,7);

    rlutil::msleep(3000);
    thread hilo1(introducirJugador, jugador);
    thread hilo2(iniciarPartida, jugador);

    hilo1.join();
    hilo2.join();
    delete(jugador);
    }

    void utilidadesDeArchivos(nave *miNave){      // aca se maneja a partir de los datos que contiene mi nave, se registra  y ordena en el ranking
       archivoRanking *arch = new archivoRanking;
        arch->setNombre(miNave->getNombre());
        arch->setPuntaje(miNave->getPuntuacion());

        historico *historico1= new historico;
        historico1->setNombre(miNave->getNombre());

        bool suscribio = verificarYSuscribir(miNave);
        if(!(suscribio)){
            escribir_archivo(arch);
            escribir_historico(historico1);
        }


        int totalPersonas = contarRegistros(); // -> cuenta de ranking
        ordenarLista(totalPersonas);
    }

    void escribir_archivo(archivoRanking * v){
        FILE *part;
        part=fopen("ranking.dat","ab");
            if(part==NULL){
                cout<<"Error de archivo";
                exit(1);
            }
        fwrite(v, sizeof(archivoRanking),1,part);
        fclose(part);
    }

    void ordenarLista(int registros) {
        FILE *ranking;
        ranking=fopen("ranking.dat","rb");

        archivoRanking *lista = new archivoRanking[registros];               // Leer todas las personas del archivo a un arreglo
        fread(lista, sizeof(archivoRanking),registros, ranking);


        for (int i = 0; i < registros ; i++) {
            for (int j = 0; j < registros - i - 1; j++) {
                if (lista[j].getPuntaje() < lista[j + 1].getPuntaje()) {

                    archivoRanking temporal = lista[j];
                    lista[j] = lista[j + 1];
                    lista[j + 1] = temporal;
                }
            }
        }

        fclose(ranking);
        ranking=fopen("ranking.dat","wb");
        fwrite(lista, sizeof(archivoRanking), registros < 5 ? registros : 5 , ranking);           // Escribir la lista ordenada de nuevo al archivo
        fclose(ranking);
}

    int contarRegistros(){
        FILE *contar = fopen("ranking.dat","rb");

        int contador = 0;
        archivoRanking arch;

        while (fread(&arch, sizeof(archivoRanking), 1, contar) == 1) {
            contador++;
        }

        fclose(contar);
        return contador;
    }

    void mostrarRanking(){
        rlutil::cls();
        FILE* archRanking;
        archRanking=fopen("ranking.dat","rb");
        archivoRanking reg;
        int i=0;
        while(fread(&reg, sizeof (archivoRanking), 1, archRanking)==1){
            rlutil::locate(95,15+i);
            rlutil::msleep(200);

            reg.mostrar();
            i+=2;
        }

        rlutil::locate(1,1);
        system("pause");
    }


    void escribir_historico(historico * h){
        FILE *hist;
        hist=fopen("historico.dat","ab");
            if(hist==NULL){
                cout<<"Error de archivo";
                exit(1);
            }
        fwrite(h, sizeof(historico),1,hist);
        fclose(hist);
    }

    void mostrarHistorico(){
        rlutil::cls();
        FILE* archHistorico;
        archHistorico=fopen("historico.dat","rb");
        historico reg;
        int i=0;
        while(fread(&reg, sizeof (historico), 1, archHistorico)==1){
            rlutil::locate(95,15+i);
            rlutil::msleep(200);

            reg.mostrar();
            i+=2;
        }

        rlutil::locate(1,1);
        system("pause");
    }



    bool verificarYSuscribir(nave* MiNave){
        // se verifica si esta el nombre en el archivo
        FILE* archRanking;
        archRanking=fopen("ranking.dat","rb+");
        archivoRanking reg;
        bool escribio = false;


            while(fread(&reg,sizeof(archivoRanking),1,archRanking)==1){
                if(*MiNave == reg){
                    if(MiNave->getPuntuacion() > reg.getPuntaje()){
                        reg.setPuntaje(MiNave->getPuntuacion());
                        fseek(archRanking,ftell(archRanking)-sizeof (reg),0);
                        escribio = fwrite(&reg,sizeof (reg),1,archRanking);
                        fclose(archRanking);
                        break;
                    }else{
                        escribio = true;
                    }
                }
            }

        // se modifica si esta en el archivo
        return escribio;
    }






