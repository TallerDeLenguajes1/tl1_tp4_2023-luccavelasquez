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



int main()
{
    int cant;
    Tarea **tareasPendientes, **tareasRealizadas;
    char *Buffer;

    printf("Ingrese la cantidad de tareas que decea cargar: ");
    scanf("%d",&cant);

    tareasPendientes = malloc(sizeof(Tarea)*cant);
    tareasRealizadas = malloc(sizeof(Tarea)*cant);

    for (int i = 0; i < cant; i++)
    {
        //preguntar porque es una buena practica hacer esto
        tareasPendientes[i] = NULL;
        tareasRealizadas[i] = NULL;
    }
    
    for (int i = 0; i < cant; i++)
    {
        Buffer = malloc(sizeof(char)*100);
        tareasPendientes[i] = malloc(sizeof(Tarea)*1);
        
        tareasPendientes[i][0].TareaID = i + 1;
        printf("Ingrese la descripcion de la tarea: ");
        fflush(stdin);
        gets(Buffer);
        tareasPendientes[i][0].Descripcion = malloc((strlen(Buffer)+1) * sizeof(char));
        strcpy(tareasPendientes[i][0].Descripcion,Buffer);
        tareasPendientes[i][0].Duracion = 10 + rand() % 90; 
        free(Buffer);
    }
    

    for (int i = 0; i < cant; i++)
    {  
        int resp;
        printf("Tarea: %d\n", 1+i);
        puts(tareasPendientes[i]->Descripcion);

        printf("Realizo la tarea? Marque 1 si la realizo de lo contrario marque 0: %d",&resp);
        if (resp == 1)
        {
            tareasRealizadas[i] = tareasPendientes[i];
            tareasPendientes[i] = NULL;
        }
        


    }
    




    return 0;
}