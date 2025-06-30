#include <iostream>
#include <thread>
using namespace std;
#include "funciones.h"
#include "rlutil.h"
#include "clases.h"
#include <cstring>



int main()
{
    /*
    archivoRanking reg;
    nave Nave;
    Nave.setNombre("hola");
    reg.setNombre("hola");                // sobrecarga de operador
    cout << (Nave == reg) << endl;
    */

    configuracionDePantalla();
    rlutil::msleep(1500);
    menuPrincipal();

    return 0;
}
