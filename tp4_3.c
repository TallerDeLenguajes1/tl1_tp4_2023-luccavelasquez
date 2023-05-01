#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Tarea
{
    int TareaID;
    char *Descripcion;
    int Duracion;

} Tarea;

typedef struct TNodo //ver como poner un nombre al TNodo
{
    Tarea tarea;
    struct TNodo *sig;

} TNodo;


TNodo * CrearListaVacia();//preguntar porque va el asterisco, retorna un puntero de tipo nodo?
TNodo * CrearNodo(Tarea tarea);

void InsertarNodo(TNodo ** Start, TNodo *NuevoNodo);

int main()
{
    int resp;
    char *Buffer;
    Tarea tarea;

    //Nodo *Start; la lista es de tipo nodo
    TNodo *TareasPendientes; //= a start, es mi lista..
    TNodo *TareasRealizadas;

    TareasPendientes = CrearListaVacia(); // apunta a null
    TareasRealizadas = CrearListaVacia();

    TNodo *NNodo; //lo utilizo dentro del for!!


    //cargar tareas
    do
    {
        int i=0;
        

        Buffer = malloc(sizeof(char)*100);
        
        tarea.TareaID = i + 1;
        printf("Ingrese la descripcion de la tarea: ");
        fflush(stdin);
        gets(Buffer);
        tarea.Descripcion = malloc((strlen(Buffer)+1) * sizeof(char));
        strcpy(tarea.Descripcion,Buffer);

        tarea.Duracion = 10 + rand() % 90; 
        free(Buffer);//ver si estaria bien poner un free tarea.Descripcion
        i++;
        //deberia crear el nodo???

        NNodo = CrearNodo(tarea);

        InsertarNodo(&TareasPendientes,NNodo);

        printf("Si decea ingresar una nueva tarea ingrese 1, de lo contrario ingrese 0: ");
        scanf("%d",&resp);

    } while (resp == 1);
    

    //Mostrar tareas realizadas y luego las pendieentes



    return 0;
}

TNodo * CrearListaVacia() //preguntar porque va el asterisco
{
    return NULL;
}

TNodo * CrearNodo(Tarea tarea) //ver si esta bien hecho...
{
    TNodo * NNodo = malloc(sizeof(TNodo));

    NNodo->tarea.TareaID = tarea.TareaID;
    NNodo->tarea.Duracion = tarea.Duracion;
    NNodo->tarea.Descripcion = tarea.Descripcion;
    
    NNodo->sig = NULL;

    return NNodo;
}

void InsertarNodo(TNodo ** Start, TNodo *NuevoNodo) //ver como funciona la logica de esto.. 
{
    NuevoNodo->sig = *Start; //es null?
    *Start = NuevoNodo;
}
