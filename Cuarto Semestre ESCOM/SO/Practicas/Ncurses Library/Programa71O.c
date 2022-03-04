#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h> //incluimos la libreria ncurses
#include <unistd.h>

// WINDOW *crearVentana(int alto, int ancho, int y, int x){
//     WINDOW *win;
//     win = subwin(alto,ancho,y,x);

//     return win;
// }

// void eliminarVentana(WINDOW *win){

//     delwin(win);
//     wrefresh(win);

// }
void f6();
void f7();
void f8();
void f9();
void f10();
void f11();
void opcion1(WINDOW *main)
{

    WINDOW *subWin;
    //Obtener tamaño de la ventana
    int yMax, xMax;
    getmaxyx(main, yMax, xMax);
    //Crear una ventana
    subWin = subwin(main, 18, xMax - 28, yMax - 20, 23);
    box(subWin, 0, 0);
    refresh();     //refrescamos la pantalla
    start_color(); //inicializamos los colores

    //se verifica si hay colores
    if (has_colors() && COLOR_PAIRS >= 13)
    {
        int n = 1;
        //especificamos los pares de colores que usaremos
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(6, COLOR_CYAN, COLOR_BLACK);
        init_pair(7, COLOR_BLUE, COLOR_WHITE);
        init_pair(8, COLOR_WHITE, COLOR_RED);
        init_pair(9, COLOR_BLACK, COLOR_GREEN);
        init_pair(10, COLOR_BLUE, COLOR_YELLOW);
        init_pair(11, COLOR_WHITE, COLOR_BLUE);
        init_pair(12, COLOR_WHITE, COLOR_MAGENTA);
        init_pair(13, COLOR_BLACK, COLOR_CYAN);

        refresh(); //volvemos a actualizar la pantalla

        //aqui imprimimos una cadena de texto n veces con colores
        while (n <= 13)
        {
            wcolor_set(subWin, n, NULL);
            mvwaddstr(subWin, 1 + n, 16 + n, "Ncurses");
            n++;
        }
        //aqui imprimimos una cadena de texto n veces con colores
        while (n >= 0)
        {
            wcolor_set(subWin, n, NULL);
            mvwaddstr(subWin, 1 + n, 16 - n, " Ncurses");
            n--;
        }
    }

    refresh(); //actualizamos la pantalla

    mvwprintw(subWin, 10, 38, "Presione cualquier tecla para salir de la opcion");
    wgetch(subWin); //esperamos a que el usuario ingrese una tecla
    wclear(subWin); //se limpia la ventana
    delwin(subWin); //eliminamos la ventana
}
void opcion2(WINDOW *mainwin)
{

    WINDOW *menuwin;
    //Obtener tamaño de la ventana
    int yMax, xMax;
    getmaxyx(mainwin, yMax, xMax);
    //Crear una ventana para ingresar nuestros datos
    menuwin = subwin(mainwin, 18, xMax - 28, yMax - 20, 23);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    //Aplicando la funcionalidad de las teclas de movimiento
    keypad(menuwin, true);
    char *opciones[] = {"Juan Carlos Sarmiento Gutierrez",
                        "Brandon David Meza Vargas", "Alberto Peña Atanasio",
                        "Sergi Alberto Martinez Ramirez"};
    int opcion;
    int seleccion = 0;
    mvwprintw(menuwin, yMax - 25, 7, "MENU BASICO CON NCURSES.H\n");
    while (1)
    {
        for (int i = 0; i < 4; i++)
        {
            //Recorriendo nuestro arreglo de nombres para identificarlos
            if (i == seleccion)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, opciones[i]); //Añadiendolos a la caja
            wattroff(menuwin, A_REVERSE);
        }
        opcion = wgetch(menuwin); //Obtenemos la lista de nombres en base a la seleccion
        switch (opcion)
        {
        //Aumentamos y disminuimos el valor de la seleccion con las teclas de flecha
        case KEY_UP:
            seleccion--;
            if (seleccion == -1)
                seleccion = 0;
            break;
        case KEY_DOWN:
            seleccion++;
            if (seleccion == 4)
                seleccion = 3;
            break;
        default:
            break;
        }
        if (opcion == 10)
            break;
    }
    //Imprimimos el nombre en pantalla
    refresh();
    mvwprintw(menuwin, yMax - 15, 7, "Seleccionaste a %s", opciones[seleccion]);
    mvwprintw(menuwin, yMax - 13, 7, "Presione cualquier tecla para salir de la opcion");
    wgetch(menuwin);

    wclear(menuwin);
    delwin(menuwin);

    refresh();
}
void opcion3(WINDOW *win)
{

    //f6();
    //f7();
    //f8();
    f9();
    //f10();
    //f11();
}

void f6()
{
    initscr();
    start_color();

    char *a = "Esto va primero";

    init_color(COLOR_BLACK, 100, 698, 333);

    insstr(a); //Esta llamada

    insdelln(10); //Esta llamada recorre el numero de lineas indicado en su argumento, sobre la linea actual
    refresh();
    getch();
    endwin();
}

void f7()
{
    initscr();
    start_color();

    char *a = "Esto va primero";

    init_color(COLOR_BLACK, 100, 698, 333);

    insstr(a);

    //insertln();	//Esta llamada recorre una linea debajo de la linea actual
    refresh();
    getch();
    endwin();
}

void f8()
{
    initscr();
    start_color();

    char *a = "Esto va primero";
    char *aux;

    init_color(COLOR_BLACK, 100, 698, 333);

    //longname lo que hace es devolver una cadena que describe a la terminal
    printw("Descripcion de la terminal: %s", longname());

    refresh();
    getch();
    endwin();
}

void f9()
{
    initscr();
    start_color();
    init_color(COLOR_BLACK, 100, 698, 333);
    int aux;

    printw("Ingrese su caracter: ");
    //mvgecth funciona como getch, solo que esta recibe el caracter dada la posicion en sus argumentos, el primer parametro indica filas y el segundo columnas
    aux = mvgetch(8, 3);
    printw("\n El caracter fue: %c\n", aux);
    refresh();
    getch();
    endwin();
}

void f10()
{

    initscr();
    start_color();
    char *aux = "Soy una cadena impresa con mvwaddstr";
    init_color(COLOR_BLACK, 100, 698, 333);

    //namps duerme la terminal un tiempo determinado, indicado en milisegundos y en su argumento, antes de que cualquier accion se realice
    napms(5000);
    printw("Me dormi 5 segundos...\n");

    //Esta funcion lo que hace es imprimir una fila de caracteres en una posicion indicada. El primer y segundo argumento indican la posicion donde se imprimira, el tercer argumento representa el caracter a imprimir y el ultimo parametro indica el maximo de esos caracteres que se mostraran en pantalla
    mvvline(3, 6, '#', 10);

    //Esta funcion lo que hace es imprimir una cadena en una posicion indicada.El primer argumento indica el recurso a utilizar, en este caso la pantalla. El segundo y tercer argumento indican la posicion donde se imprimira, el cuarto es la cadena a mostrar en dicha posicion
    mvwaddstr(stdscr, 15, 20, aux);

    refresh();
    getch();
    endwin();
}

void f11()
{
    initscr();
    char *aux = "Soy una cadena";
    printw("\n Soy una cadena \n");
    //scr_dum sobrescribe en el archivo a.txt
    scr_dump("a.txt");
}

int main()
{

    WINDOW *mainwin, *subwin; //variables para las ventanas

    int res; //variable para elegir opción del menu

    //inicializamos ncurses
    if ((mainwin = initscr()) == NULL)
    {
        fprintf(stderr, "Error\n"); //si hay un error al inicializar, se imprime
        exit(-1);                   //salimos del programa
    }
    raw();    //para ignorar caracteres especiales
    noecho(); //prevenimos la repeticion de caracteres escritos por el usuario

    keypad(mainwin, true); //iniciamos el control de teclas
    printw("Opciones del programa\n");
    printw("Presiona F1 para opcion 1\n");
    printw("Presiona F2 para opcion 2\n");
    printw("Presiona F3 para opcion 3\n");
    printw("Presiona F5 para salir\n");

    refresh(); //actualizamos la pantalla

    //leemos una tecla del teclado y mientras sea diferente a F5 no salimos
    while ((res = getch()) != KEY_F(5))
    {

        switch (res)
        {
        case KEY_F(1):

            opcion1(mainwin); //si presionamos F1 se ejcuta la opcion 1
            break;

        case KEY_F(2):

            opcion2(mainwin); //si presionamos F2 se ejcuta la opcion 2

            break;

        case KEY_F(3):
            opcion3(mainwin); //si presionamos F3 se ejcuta la opcion 3
            break;

        case KEY_F(5):
            break;
        }
    }

    delwin(mainwin); //eliminamos la ventana principal
    refresh();       //actualizamos la pantalla
    endwin();        //finalizamos la ejecucion de la ventana

    return 0;
}
