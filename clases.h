#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
#include <chrono>
#include <ctime>
#include <cstring>




    class Fecha {
    private:
        int anio;
        int mes;
        int dia;
        int hora;
        int minuto;
        int segundo;
    public:
    Fecha() {
        time_t currentTime = time(nullptr);
        tm* localTime = localtime(&currentTime);
        dia = localTime->tm_mday;
        mes = localTime->tm_mon + 1;
        anio = localTime->tm_year + 1900;
    }

    void mostrarFecha(){
        cout << dia << "/" << mes << "/" << anio;
    }

    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
};

    class archivoRanking{
    private:
        char nombre[20];
        int puntaje;
        Fecha fecha;
    public:
        void setPuntaje(int PUNTAJE){puntaje = PUNTAJE;}
        void setNombre(const char* nuevoNombre){strcpy(nombre, nuevoNombre);}
        int getPuntaje(){return puntaje;}
        const char* getNombre() const {return nombre;}

        void mostrar(){
            cout << nombre << " | Puntos: " << puntaje << " | ";
            fecha.mostrarFecha();
        }



    };


    class nave{
    private:
        int posicionX=50;
        int posicionY=25;
        int posicionXBackup;
        int posicionYBackup;
        int vidas = 3;
        int estado;
        int puntuacion = 0;
        bool moviendose=false;
        char nombre[20];

        char nave[5][6] = {
        {char(219),  ' '    , char(219) , char(219) ,     ' '      ,char(219)},
        {char(219),  ' '    , char(219) , char(219) ,     ' '      ,char(219)},
        {char(219),char(219),    ' '    ,    ' '    ,  char(219)   ,char(219)},
        {   ' '   ,char(219), char(219) , char(219) ,  char(219)   ,   ' '   },
        {   ' '   ,char(219), char(219) , char(219) ,  char(219)   ,   ' '   }

    };



    public:

        bool operator ==(const archivoRanking& reg) {
            return !(strcmp(reg.getNombre(),nombre));            // SOBRECARGA DE OPERADOR IZQ ARCH DERECH NAVE
        }


        void setPosicionX(int POSICIONX){posicionX = POSICIONX;}
        void setPosicionY(int POSICIONY){posicionY = POSICIONY;}
        void setPosicionXBackup(int POSICIONXBACKUP){posicionXBackup = POSICIONXBACKUP;}
        void setPosicionYBackup(int POSICIONYBACKUP){posicionYBackup = POSICIONYBACKUP;}
        void setVidas(int VIDAS){vidas = VIDAS;}
        void setEstado(int ESTADO){estado = ESTADO;}
        void setMoviendose(bool MOVIENDOSE){moviendose = MOVIENDOSE;}
        void setPuntuacion(int PUNTUACION){puntuacion = PUNTUACION;}
        void setNombre(const char* nuevoNombre){strcpy(nombre, nuevoNombre);}


        int getPosicionX(){return posicionX;}
        int getPosicionY(){return posicionY;}
        int getPosicionXBackup(){return posicionXBackup;}
        int getPosicionYBackup(){return posicionYBackup;}
        int getVidas(){return vidas;}
        int getEstado(){return estado;}
        bool getMoviendose(){return moviendose;}
        int getPuntuacion(){return puntuacion;}
        const char* getNombre() const {return nombre;}


        void pintarNave();
        void limpiarNave();
        void guardarPosicionAnterior();
        void definirLimites();
        void pintarVidas();


    };

    class naveEnemiga{
    private:
        int posicionX = 5;
        int posicionY = 5;
        int posicionXBackup;
        int posicionYBackup;
        bool estado = true;

        char nave[5][6] = {
        {char(190),  ' '    , char(220) , char(220) ,     ' '      ,char(190)},
        {char(186),  ' '    , char(219) , char(219) ,     ' '      ,char(186)},
        {char(223),char(219),    ' '    ,    ' '    ,  char(219)   ,char(223)},
        {   ' '   ,char(220), char(223) , char(223) ,  char(220)   ,   ' '   },
        {   ' '   ,char(223), char(158) , char(158) ,  char(223)   ,   ' '   }
    };

    public:
        void setPosicionX(int POSICIONX){posicionX = POSICIONX;}
        void setPosicionY(int POSICIONY){posicionY = POSICIONY;}
        void setPosicionXBackup(int POSICIONXBACKUP){posicionXBackup = POSICIONXBACKUP;}
        void setPosicionYBackup(int POSICIONYBACKUP){posicionYBackup = POSICIONYBACKUP;}
        void setEstado(int ESTADO){estado = ESTADO;}

        int getPosicionX(){return posicionX;}
        int getPosicionY(){return posicionY;}
        int getPosicionXBackup(){return posicionXBackup;}
        int getPosicionYBackup(){return posicionYBackup;}
        bool getEstado(){return estado;}

        void comportamiento();
        void guardarPosicionAnterior();
        void pintarNave();
        void limpiarNave();
    };



    class historico{
    private:
        char nombre[20];
    public:
        void setNombre(const char* nuevoNombre){strcpy(nombre, nuevoNombre);}
        const char* getNombre() const {return nombre;}

        void mostrar(){
            cout << nombre;
        }
    };


      //  bool operator ==(const nave& otro, const archivoRanking& reg);   // DECLARACION DE SOBRECARGA
      //  bool operator ==(const archivoRanking& reg, const nave& otro);


#endif // CLASES_H_INCLUDED
