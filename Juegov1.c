#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

//variables globales para cambiar el color dentro del menu
#define CYAN_T      "\x1b[36m"
#define RESET_COLOR "\x1b[0m"
#define ROJO_T      "\x1b[31m"

//Prototipos que se van a utilizar
void menu_nivel();

void bordes();
void mov();
void cora();
int bala();
int balaEnemiga();

void nivel_facil();
void nivel_dificil();
int enemigosMov();
int enemigo();

//estructura para leer el nombre que se le pone al personaje
struct name
    {
        char nombre[20];
    };

struct
    {
        int inicioX, inicioY;
    }enemigos[5];

struct
    {
        int balaX;
        int balaY;
    }balaE[1];

void gotoxy(int x, int y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos; //estructura defininida para las coordenadas
    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon, dwPos);
}

//Funcion para ocultar el cursor
void OcultarCursor()
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 50;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon, &cci);
}


//menu principal del juego
void main()
{
    //variables que se utilizan dentro del menu
    char OP,OP2;
    int n;
    //la estructura se utiliza para leer el nombre que el usuaria le quiera poner al personaje
    struct name name[3];

    //Titulo de juego
    system("CLS");
    printf("\n        ***        **************  *************  *************     **********    ");
    printf("\n      **   **               ****        ***       ***              ***            ");
    printf("\n     **     **            ****          ***       ***             ***             ");
    printf("\n    ***********         ****            ***       *********      ***              ");
    printf("\n    ***     ***       ****              ***       ***             ***             ");
    printf("\n   ***       ***    ****                ***       ***              ***            ");
    printf("\n  ****       ****  **************       ***       *************     **********   \n");
    system("color 03");
    system("PAUSE>arch");

    do{
        system("CLS");
        printf(ROJO_T"\t\t\t""Proyecto AZTEC" RESET_COLOR "\n");
        printf(CYAN_T"\n\n""\t\t""Elige tu peleador" RESET_COLOR "\n");
        printf("\n1)Guerrero");
        printf("\n2)Arquero");
        printf("\n3)Mago");
        printf("\ne)Salir");
        printf("\nSeleccione una opcion: ");
        scanf("%c",&OP);
        switch(OP)
        {
            case '1':
            {
                //do{
                system("CLS");
                printf("\nDonde otros siguen ciegamente la verdad recuerda NADA ES VERDAD");
                printf("\n  Donde otros hombres estan limitados por la moral o la ley ");
                printf("\n   recuerda TODO ESTA PERMITIDO  Actuamos en las sombras ");
                printf("\n                 para servir a la luz ");
                printf("\n                   SOMOS ASESINOS ");

                printf("\n\n"CYAN_T"\t\t""Estadisticas del Guerrero"RESET_COLOR"\n");
                printf("\t\t\tVida = 100\n");
                printf("\t\t\tDa%co = 8\n",164);

                printf("\t(a)aceptar""\t\t\t""(r)regresar al menu\n");
                fflush(stdin);
                scanf("%c",&OP2);
                system("PAUSE>arch");

                switch(OP2)
                {
                    do{
                    case 'a':
                    {
                        /*system("CLS");
                        printf("\n"CYAN_T"\t\t\t""Escoge un nombre para tu guerrero:"RESET_COLOR"\n");
                        fflush(stdin);
                        gets(name[n].nombre);
                        system("PAUSE>arch");*/

                        system("CLS");
                        //printf("\t\t\tEscoge el nivel que quieres\n");
                        //fflush(stdin);
                        menu_nivel();
                        system("PAUSE>arch");

                    }
                    break;
                    case 'r':
                    break;

                    }while(OP2!='r');
                }
                break;
            }
            case '2':
            {
                //do{
                system("CLS");
                printf("\nConcentrate unicamente en tu objetivo, indepndientemente de tu entorno");
                printf("\n     Se el ahora. Preparate y desenfunda. inhala y preparate ");
                printf("\n       para lo que estas apunto de hacer y responsabilizate ");
                printf("\n                del resultado de cada disparo ");

                printf("\n\n"CYAN_T"\t\t""Estadisticas del Arquero"RESET_COLOR"\n");
                printf("\t\t\tVida = 100\n");
                printf("\t\t\tDa%co = 5\n",164);

                printf("\t(a)aceptar""\t\t\t""(r)regresar al menu\n");
                fflush(stdin);
                scanf("%c",&OP2);
                system("PAUSE>arch");
                switch(OP2)
                {
                    do{
                    case 'a':
                    {
                        // system("CLS");
                        // printf("\n"CYAN_T"\t\t\t""Escoge un nombre para tu guerrero:"RESET_COLOR"\n");
                        // fflush(stdin);
                        // gets(name[n].nombre);
                        // system("PAUSE>arch");

                        system("CLS");
                        //printf("\t\t\tEscoge el nivel que quieres\n");
                        //fflush(stdin);
                        menu_nivel();
                        system("PAUSE>arch");

                    }
                    break;
                    case 'r':
                    break;
                    }while(OP2!='r');
                }
                break;
            }
            case '3':
            {
                //do{
                system("CLS");
                printf("\nLa verdadera valentia no es saber cuando quitar una vida");
                printf("\n            si no cuando perdonar una   ");

                printf("\n\n"CYAN_T"\t\t""Estadisticas del Mago"RESET_COLOR"\n");
                printf("\t\t\tVida = 100\n");
                printf("\t\t\tDa%co = 10\n",164);

                printf("\t(a)aceptar""\t\t\t""(r)regresar al menu\n");
                fflush(stdin);
                scanf("%c",&OP2);
                system("PAUSE>arch");

                switch(OP2)
                {
                    do{
                    case 'a':
                    {
                        // system("CLS");
                        // printf("\n"CYAN_T"\t\t\t""Escoge un nombre para tu guerrero:"RESET_COLOR"\n");
                        // fflush(stdin);
                        // gets(name[n].nombre);
                        // system("PAUSE>arch");
                        system("CLS");
                        //printf("\t\t\tEscoge el nivel que quieres\n");
                        //fflush(stdin);
                        menu_nivel();
                        system("PAUSE>arch");
                    }
                    break;
                    case 'r':
                    break;
                    }while(OP2!='r');
                }
                break;
            }
            case 'e':
            {
                system("CLS");
                printf(CYAN_T"\n""\t\t""Vuelve pronto guerrero te estaremos esperando"RESET_COLOR"\n");
                fflush(stdin);
                break;
            }
            default:
            {
                printf("Opcion no valida");
                break;
                system("PAUSE");
            }
        }
    }while(OP!='e');
}


//desarrollo del prototipo de menu
void menu_nivel()
{
    char op;
    bool repetir = true;

    do{
        system("CLS");
        printf(CYAN_T"\n\n""\t\t""Elige el nivel que quieres" RESET_COLOR "\n");

        printf("\t\t\t1)Nivel Facil\n");
        printf("\t\t\t2)Nivel Difici\n");
        printf("\t\t\t3)Salir\n");
        scanf("%c",&op);
        system("PAUSE>arch");

        switch(op)
        {
            case '1':
            {
                system("CLS");
                printf(CYAN_T"\n""\t\t""Elegiste el Nivel Facil"RESET_COLOR"\n");
                fflush(stdin);
                system("PAUSE>arch");
                nivel_facil();
                system("CLS");
                break;
            }
            case '2':
            {
                system("CLS");
                printf(CYAN_T"\n""\t\t""Elegiste el Nivel Dificil"RESET_COLOR"\n");
                fflush(stdin);
                system("PAUSE>arch");
                nivel_dificil();
                system("CLS");
                break;
            }
            case '3':
            {
                system("CLS");
                printf(CYAN_T"\n""\t\t""Salio del juego y regresara al menu principal"RESET_COLOR"\n");
                repetir = false;
                break;
            }
            default:
            {
                printf("Opcion no valida\n");
                system("PAUSE");
                break;
            }
        }
    }while(repetir);
}


void nivel_facil()
{
    bordes();
}


void nivel_dificil()
{
    bordes();
}



void bordes()
{
    int i;
    //lados
    system("CLS");
    for(i=2; i<78; i++)
    {
        gotoxy(i,3); printf("%c",205);
        gotoxy(i,33); printf("%c",205);
    }
    //arriba y abajo
    for(i=4; i<33; i++)
    {
        gotoxy(2,i); printf("%c",186);
        gotoxy(77,i); printf("%c",186);
    }
    //esquinas
    gotoxy(2,3); printf("%c",201);
    gotoxy(2,33); printf("%c",200);
    gotoxy(77,3); printf("%c",187);
    gotoxy(77,33); printf("%c",188);


    for(int i=0;i < 1; i++){
        enemigos[i].inicioX = 3;
        enemigos[i].inicioY = 4;
    }

    OcultarCursor();
    mov();

    system("PAUSE>arch");
}


void mov()
{

    int x = 39 , y = 30, salud = 3;
    int balaX=x, balaY=y, balaActive=0, golpes = 0,direccion = 0,auxGolpes=0;
    //int x1 = 39 , y1 = 6;

    gotoxy(x,y); printf("%c%c%c%c",40,94,94,41);
    gotoxy(x,y+1); printf("%c%c%c%c%c",47,124,124,92,47);
    gotoxy(x,y+2); printf("%c%c%c%c",40,47,92,41);

    do
    {
        // AGREGAMOS UN INTERVALO O UNA PAUSA PARA QUE EL BUCLE NO CORRA RAPIDO
        Sleep(100);
        direccion = enemigosMov(direccion);
        cora(salud);
        salud = balaEnemiga(x,y,salud);

        // HACEMOS UN BARRIDO DEL PERSONA ANTERIOR
        gotoxy(x,y);   printf("     ");
        gotoxy(x,y+1); printf("     ");
        gotoxy(x,y+2); printf("     ");

        // IZQUIERDA
        if (GetAsyncKeyState(0x25) && x>3)
        {
            x--;
        }
         // DERECHA
        if (GetAsyncKeyState(0x27) && x+6 < 78)
        {
            x++;
        }
        // ABAJO
        if (GetAsyncKeyState(0x28) && y+3 < 33)
        {
            y++;
        }
        // ARRIBA
        if (GetAsyncKeyState(0x26) && y>4)
        {
            y--;
        }

        /// IMPRIMIMOS A NUESTRO PERSONAJE
        gotoxy(x,y);   printf("%c%c%c%c",40,94,94,41);
        gotoxy(x,y+1); printf("%c%c%c%c%c",47,124,124,92,47);
        gotoxy(x,y+2); printf("%c%c%c%c",40,47,92,41);

        if (GetAsyncKeyState(0x20) && y>4)
        {
            if(balaActive==0){
                balaActive=1;
                balaX=balaX+1;
            }
        }

        if(balaY<=4){
            balaActive=0;
            gotoxy(balaX,balaY); printf(" ");
        }

        if(balaActive == 1){
            balaY = bala(balaX, balaY);
            auxGolpes=golpes;
            golpes = enemigo(balaX,balaY,golpes);
            if(auxGolpes != golpes){
                gotoxy(balaX,balaY); printf(" ");
                balaY=4;
                balaX=3;
            }
        }else if(balaActive==0){
            balaX=x;
            balaY=y;
        }

        if(GetAsyncKeyState(0x1B))
        {
            system("CLS");
            exit(EXIT_SUCCESS);
        }


    }while(1);
    getch();
}

int balaEnemiga(int x,int y,int salud){
    int enemigoX = 0;
    int enemigoY = 0;


    for(int i=0;i<2;i++){
        // variables mas simple s
        enemigoX = enemigos[i].inicioX;
        enemigoY = enemigos[i].inicioY;

        // si el enemigo vio al jugar dispara
        if((x+2 == enemigos[i].inicioX+2) && balaE[0].balaY==3){
            balaE[0].balaX = enemigoX+1;
            balaE[0].balaY = enemigoY+2;
        }

        // si la bala fue disparada continua su trayectoria
        if(balaE[0].balaY != 3){
            // si la bala alcanza el limite se desaparece
            if(balaE[0].balaY >= 33){
                balaE[0].balaY=3;
                break;
            }

            // si la bala alcanza al jugador se desaparece y marca daño al jugador
            if((balaE[0].balaX >= x && balaE[0].balaX <= x+5) && (balaE[0].balaY >= y && balaE[0].balaY <= y+5)){
                salud--;
                balaE[0].balaY = 3;
                break;
            }

            // borra la bala
            gotoxy(balaE[0].balaX,balaE[0].balaY); printf(" ");
            //incrementa su trayectoria
            balaE[0].balaY++;
            //se vuelve a pintar
            gotoxy(balaE[0].balaX,balaE[0].balaY); printf("8");
        }
    }
    // retorna los cambios a la salud
    return salud;
}


void cora(salud)
{
    int corazones = salud;

    gotoxy(68,2); printf("Vidas");
    gotoxy(74,2); printf("     ");

    for(int i=0; i<corazones; i++)
    {
        gotoxy(74+i,2); printf(ROJO_T"%c"RESET_COLOR ,3);
    }
}

 int bala(int x, int y)
{
        // se borra
        gotoxy(x,y); printf(" ");
        //se incrementa la posicon
        y--;
        // se vuelve a pintar
        gotoxy(x,y); printf("8");


    return y;
}

int enemigo(int x, int y,int golpes){

    int enemigoX = 0;
    int enemigoY = 0;


    for(int i=0;i<2;i++){
        // ponemos las posiciones en variables mas simples
        enemigoX = enemigos[i].inicioX;
        enemigoY = enemigos[i].inicioY;

        if(((x >= enemigos[i].inicioX && x <= enemigos[i].inicioX+5) && (y >= enemigos[i].inicioY && y <=enemigos[i].inicioY+4)) && golpes >= 5)
        {
            // se borra al enemigo si murio.
            gotoxy(enemigoX,enemigoY);   printf("     ");
            gotoxy(enemigoX,enemigoY+1); printf("     ");
            gotoxy(enemigoX,enemigoY+2); printf("     ");

            // volver a poner al enemigo incio
            enemigos[i].inicioX = 3;
            enemigos[i].inicioY = 4;
            // reiniciamos su contador de golpes
            golpes = 0;
        }
        if((x >= enemigos[i].inicioX && x <= enemigos[i].inicioX+5) && (y >= enemigos[i].inicioY && y <=enemigos[i].inicioY+4)){
            // en caso de recibir golpe se incrementa,
            golpes++;
        }
    }

    return golpes;
}

int enemigosMov(int direccion){
    int x=10, y=10;

    for(int i=0; i < 1; i++){
        // Extraemos los valores
        x = enemigos[i].inicioX;
        y = enemigos[i].inicioY;

        // borramos el enemigo
        gotoxy(x,y);   printf("     ");
        gotoxy(x,y+1); printf("     ");
        gotoxy(x,y+2); printf("     ");

        // se establecen limites de interaccion del enemigo
        if(x>=72){
            direccion = 1;
        }
        if(x<=3){
            direccion = 0;
        }

        // se elije la direccion del enemigo
        if(direccion == 0){
            x++;
        }
        if(direccion == 1){
            x--;
        }

        //despues se pinta el personaje por encima
        gotoxy(x,y); printf("%c%c%c%c",40,118,118,41);
        gotoxy(x,y+1); printf("%c%c%c%c%c",47,124,124,92,47);
        gotoxy(x,y+2); printf("%c%c%c%c",40,47,92,41);

        // Volvemos a introducir los valores ahora con cambios
        enemigos[i].inicioX = x;
        enemigos[i].inicioY = y;
    }

    // retornamos la direccion actuak oara la siguiente vez que entre a este ciclo
    return direccion;
}
