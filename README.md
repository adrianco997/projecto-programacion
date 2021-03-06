Objetivos de la Segunda Iteración del Proyecto (I2)

4. [R4] Modificar, en caso de necesidad, los demás módulos existentes para que
utilicen los nuevos manteniendo la funcionalidad previa.
Por ejemplo, en la estructura de datos de Game,
sustituir el puntero a Object existente para
guardar el único objeto que se permitía en la I1, por un array de punteros a
objeto para almacenar todos los que se utilicen en el juego, como se hace con
los espacios, y además, añadir un puntero a Die para disponer de un dado. En
todos los casos, se utilizarán las funciones adecuadas de los nuevos módulos
para la manipulación necesaria de datos desde las primitivas de los demás.

5. [R5] Crear un fichero de carga de los objetos que se utilizarán en el juego
(objects.dat), siguiendo el modelo del empleado para cargar los espacios.
El fichero debe incluir cuatro objetos.

6. [R6] Crear una función en GameReader para cargar los objetos en el juego,
siguiendo el modelo de la función utilizada para cargar los espacios.
Modificar los módulos necesarios para que los objetos se carguen desde fichero,
como se hace con los espacios.

7. [R7] Añadir un nuevo comando para tirar el dado.


9. [R9] Modificar el comando (grasp o g) que permite al jugador coger un
objeto de un espacio, de modo que pueda indicarse el objeto que se pretende
coger de entre los que haya disponibles en el espacio concreto.
En particular, este comando deberá incluir el identificador o nombre
establecidos para el objeto (ficha en el tablero) que se quiere coger,
por ejemplo: "grasp O4" (ver Figura 2).
~~~
+-----------+ +-----------+ +-----------+
|         16| | >8D     17| |         22|
|    ___    | |           | |    ___    |
|   / _ \   | |  <O)__/   | |   (O O)   |
|  / / \ \  | |   \_-/    | |    \m/    |
| O4        | |           | |           |
+-----------+ +-----------+ +-----------+
~~~
Figura 2. Ejemplos de descripciones gráficas (ASCII) de espacios: izquierda, casilla de puente con ficha "O4"; centro, casilla de oca con el jugador ">8D"; y, derecha, casilla de la muerte.

10. [R10] Modificar una vez más el módulo Space para incluir una descripción gráfica (ASCII) del espacio de 3x7 caracteres (ver Figura 2). Para ello podría incluirse un campo gdesc que fuera un array de tres strings, cada uno con espacio para siete caracteres. De este modo, por ejemplo, la descripción gráfica de la casilla 17 de la Figura 2 estaría formada por los strings:
~~~
"       ", "<O)__/", "  \_-/ "
~~~
Y la línea del fichero de datos correspondiente a dicha casilla podría ser:
"#s:17|Casilla 17 (Oca)|16|-1|18|21| |<O)__ / | \_-/ |"
También en este caso deberán prepararse las primitivas para manejar el nuevo campo en las funciones existentes (create, destroy y print) y crear las nuevas funciones de manipulación necesarias (set y get).
11. [R11] Crear un nuevo fichero de carga de espacios para implementar un tablero para el Juego de la Oca con 25 casillas todas enlazadas secuencialmente (norte/sur). Además, las casillas correspondientes a ocas (5, 9, 13, 17, 21 y 25) unidas mediante un enlace adicional (este/oeste), cada oca con la siguiente oca. También, las casillas correspondientes a puentes (8 y 16) enlazadas mutuamente (también este/oeste). Y por último, la correspondiente a la muerte (22) unida (de nuevo este/oeste) con la casilla de salida (1). Adicionalmente, se incluirán en el fichero las descripciones gráficas para las casillas de oca, puente y muerte (ver Figura 2).
12. [R12] Modificar la función de carga de espacios para adaptarse a los cambios introducidos en el formato.
13. [R13] Modificar la función de visualización del estado del juego para mostrar: (1) la descripción gráfica (ASCII) de cada espacio; (2) el espacio donde está cada objeto; (3) varios objetos en los espacios visualizados; (4) los objetos que porta el jugador; (5) el último valor del dado; y (6) el último comando ejecutado seguido del resultado de su ejecución (OK o ERROR) (ver Figura 3). Tenga en cuenta que puede que deba redimensionar alguna ventana de la interfaz de usuario.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~ +-----------+                                          ~ Object location:    ~
~ | >8D     16|>                                         ~ O1:16, O2:16, O3:18 ~
~ |   ___     |                                          ~                     ~
~ |  / _ \    |                                          ~ Players objects: O4 ~
~ | / / \ \   |                                          ~                     ~
~ | O1,O2     |                                          ~ Last die value: 5   ~
~ +-----------+                                          ~                     ~
~       v                                                ~                     ~
~ +-----------+                                          ~                     ~
~ | 17        |>                                         ~                     ~
~ |           |                                          ~                     ~
~ | <O)__/    |                                          ~                     ~
~ |   \_-/    |                                          ~                     ~
~ |           |                                          ~                     ~
~ +-----------+                                          ~                     ~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~ The game of the Goose ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~ The commands you can use are:                                                ~
~ following(f), previous(p), grasp(g), drop(d), roll(r), exit(e)               ~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ~
~ Following: OK                                                                ~
~ Following: OK                                                                ~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Figura 3. Ejemplo de visualización de estado de juego: arriba a la izquierda,
casilla 16 de puente con fichas "O1" y "O2" además del jugador ">8D"; debajo,
casilla de oca 17; en la parte derecha, localización de objetos, objeto portado
por jugador y último valor dado; en la parte inferior, últimos comandos
ejecutados y su estado.
14. [R14] Modificar el programa principal del juego (game_loop.c) para que,
además de seguir funcionando como lo hacía antes, permita generar un fichero
de registro (LOG) con trazas de la ejecución. En particular, el fichero LOG
registrará una línea por cada comando ejecutado, en la que se indicará el
comando y el resultado de su ejecución (OK o ERROR). De este modo, si el
comando fuera "grasp" y no se consiguiera coger el objeto pretendido, en
el fichero de LOG se escribiría la línea "grasp: ERROR", mientras que si
el objeto se hubiera cogido sin problema en el fichero se escribiría "grasp: OK".
Para indicar al programa que se desea generar un fichero de LOG, al invocarlo se
pasara como últimos argumentos "-l" seguido del nombre deseado para el fichero
de LOG, después de los otros argumentos requeridos. De esta manera, si para
invocar al programa sin LOG la línea de comandos fuera "game_loop fchdatos",
donde "fchdatos" es la raíz de los ficheros de datos a cargar, entonces, para
invocar al programa especificando que se genere el LOG la línea de comandos
podría ser "game_loop fchdatos –l fchlog.log", donde "fchlog.log" es el nombre
del fichero de LOG. Para implementar esta nueva funcionalidad el programa
debería: (a) procesar convenientemente los argumentos de entrada, y en caso
de ser necesario, (b) antes de iniciar el bucle del juego, abrir para escritura
un fichero de LOG con el nombre indicado, (c) obtener en cada iteración el
resultado de la ejecución del comando y escribir este y su resultado en el
fichero de LOG como se ha dicho anteriormente, y finalmente (d) cerrar el
fichero de LOG (si se está usando) antes de terminar el programa al salir del
bucle de juego.
15. Modificar el Makefile del proyecto para automatizar la compilación y el
enlazado del conjunto.
16. Depurar el código hasta conseguir su correcto funcionamiento.
