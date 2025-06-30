-------------------------------------



<em> <h1 align="center">¿QUE ES ESTO? </h1> </em>
![image](https://github.com/user-attachments/assets/44b06bb2-ed60-4164-813a-75ddf0151837)



Dodge Invaders es un juego desarrollado como trabajo final para la materia Laboratorio de Computación II en la facultad.
El objetivo principal del proyecto fue aplicar conocimientos de programación en C++, manejo de clases, estructuras de control, y lógica de videojuegos.

En el juego, el jugador controla una nave que debe esquivar una lluvia constante de enemigos y obstáculos que caen desde la parte superior de la pantalla.
A medida que pasa el tiempo, la dificultad incrementa, aumentando la velocidad y frecuencia de los enemigos. El juego pone a prueba la agilidad del jugador y su capacidad de reacción.

Además, se implementaron funciones adicionales como puntajes, colisiones, y generación aleatoria de enemigos, utilizando la librería rlutil para la manipulación de la consola.
Todo el código fue escrito íntegramente en C++ y ejecutado en entorno local como una aplicación de consola.



-------------------------------------






<em> <h1 align="center"> 🔧 DEPLOYMENT SENSILLO DEL JUEGO 🔧  </h1> </em>

Para ejecutar el juego Dodge Invaders , simplemente se necesita tener instalado un compilador de C++ como g++.

<h3>✅ Requisitos</h3>
Sistema operativo con consola bash (Linux, macOS o Windows con Git Bash / WSL)

Compilador g++
Comandos: g++, c++, dbg (este ultimo opcional para depuración)

<h3>🧪 Verificación del entorno:</h3>
Desde la terminal, podés verificar si tenés todo lo necesario ejecutando los siguientes comandos:

		g++ --version
		c++ --version
		dbg --version
Si estos comandos devuelven una versión válida, significa que los programas están correctamente instalados y el deploy esta listo para hacerse.

<h3>📁 Navegar al proyecto</h3>
Movete a la carpeta del proyecto utilizando cd. Por ejemplo, si tenés la carpeta descomprimida en el escritorio:

		cd ~/Escritorio/DodgeInvaders

<h3>🛠️ Compilación del juego</h3>
Una vez dentro de la carpeta que contiene los archivos .cpp, ejecutá el siguiente comando para compilar:

	g++ -g -o juego.exe *.cpp

Si ocurre algun problema, y no genera el ejecutable, recomiendo que se utilice otra version del compilador estandar C++ 14.

	 g++ -std=c++14 -g -o juego.exe *.cpp

Esto generaria un ejecutable el cual ya al ingresar te generara automaticamente los archivos .dat para la persistencia de datos.






-------------------------------------



<em> <h1 align="center"> DESCRIPCION DEL FUNCIONAMIENTO: </h1> </em>



-------------------------------------

1 Inicialización del juego

•Se crea un arreglo de punteros a enemigos (enemigos) con capacidad para 26 naves enemigas.

•Se inicializan variables para controlar la generación de enemigos, puntaje y la lógica del juego.

-------------------------------------


2 Bucle principal del juego (while (terminar == false))

El juego corre continuamente hasta que se activa la condición de terminar (terminar = true).

-------------------------------------

3 Generación de enemigos

•Cada cierto número de iteraciones (cuando acumulador == 150), se crea una nueva nave enemiga.

•La posición horizontal de la nave enemiga se calcula aleatoriamente con cierta lógica (función generarNumeroAleatorio), y aparece en una posición fija vertical (y=6).

•La nave enemiga vieja en esa posición se elimina limpiando su dibujo de pantalla.

•Se agregan enemigos al arreglo de forma cíclica, reemplazando a los que ya se eliminaron.

-------------------------------------

4 Movimiento y comportamiento de enemigos

•Para cada enemigo existente:

   •Se limpia la nave del frame anterior (borra dibujo previo).
  
   •Se ejecuta su comportamiento (probablemente bajar o moverse).
  
   •Se vuelve a dibujar en su nueva posición.
  
   •Si un enemigo llega a la posición vertical límite (>= 53), se elimina (sale de pantalla).
  
   •Se detecta colisión con la nave del jugador, Si la distancia entre enemigo y jugador es menor a cierto rango, el jugador pierde una vida, y la nave enemiga se elimina.
  

-------------------------------------



5 Manejo de la nave del jugador :

•Se definen límites para que la nave no salga de la pantalla.

•Se limpia el dibujo anterior y se vuelve a pintar la nave y sus vidas en pantalla.

•Se resetea el estado de movimiento para esperar nueva entrada del jugador.

-------------------------------------

6 Fin del juego:


•Si las vidas del jugador son menores a 1:

•Se limpian todas las naves enemigas restantes con una pequeña pausa para efecto visual.

•Se limpia la nave del jugador.

•Se muestra la pantalla de gameOver().

•Se guarda y muestra la puntuación del jugador.

•Se ejecutan funciones para guardar datos en archivos.

•Se espera 3 segundos y termina el bucle.

![image](https://github.com/user-attachments/assets/72726efa-8472-40c7-81af-c023ca4386b3)


-------------------------------------


7 Puntaje:

• En cada iteración del juego, el puntaje incrementa en 2 * PI puntos, es decir, un puntaje proporcional al tiempo de juego.

