#include <stdio.h>
#include <string.h>
#define N 2
#define M 30
void CargarCapitales(char ciudades[][M]);

void CargarKilometros(char ciudades[][M], float distancia[][N]);
void Visualizar_Tabla(char ciudades[][M], float distancia[][N]);
int Validar(char ciudad[], char ciudades[][M]);
float BuscarKilometros(float distancia[][N], int i_origen, int i_destino);


int main(void){
    //Declaración de todas las variables usadas
    float kilometros[N][N];
    char capitales[N][M];
    char ciudad[M], origen[M], destino[M];
    int devuelto, i_ori, i_dest, a;
    float kms;

    //Siguiendo el enunciado, hemos construido y llamado a las siguientes funciones. 
    printf("\n\nPORTAL DE CARGA DE CAPITALES: ");
    CargarCapitales(capitales);
    
    printf("\n\nPORTAL DE CARGA DE KILOMETROS: ");
    CargarKilometros(capitales, kilometros);
    
    printf("\n\nPORTAL DE VISUALIZACION: ");
    Visualizar_Tabla(capitales, kilometros);
    
    printf("\nPORTAL DE VALIDACION");
    printf("\nIntro una ciudad, y se comprobara si existe o no en la memoria: ");
    scanf("%s", ciudad);
    devuelto = Validar(ciudad, capitales);
    if(devuelto == -1){
        printf("\nLa ciudad tecleada no existe. Error %d", devuelto);
    }else{
        printf("La ciudad se situa en la posicion %d de memoria (de la Matriz).", devuelto);
    }

    printf("\nPORTAL DE BUSQUEDA DE KILOMETROS");
    //Mediante un do while, nos aseguraremos de que el usuario teclee la ciudad correcta.
    do{
       printf("\nIntro una capital de origen: ");
       scanf("%s", origen);
       i_ori = Validar(origen, capitales);
        if(i_ori == -1){
            printf("\nLa ciudad tecleada no existe. Error %d", i_ori);
        }else{
            printf("\nLa ciudad se situa en la posicion %d de memoria (de la Matriz).", i_ori);
        }
    }while(i_ori == -1);
    do{
       printf("\nIntro una capital de destino: ");
       scanf("%s", destino);
       i_dest = Validar(destino, capitales);
        if(i_dest == -1){
            printf("\nLa ciudad tecleada no existe. Error %d", i_dest);
        }else{
            printf("\nLa ciudad se situa en la posicion %d de memoria (de la Matriz).", i_dest);
        }
    }while(i_dest == -1);
    kms = BuscarKilometros(kilometros, i_ori, i_dest);
    printf("\nEntre %s y %s hay %.3f kms.", origen, destino, kms);
    printf("\nPulse CUALQUIER TECLA, y a continuación INTRO para salir del programa: ");
    scanf("%d", &a);

    //Señaliza el fin del programa.
    return 0;
}
void CargarCapitales(char ciudades[][M]){
    for(int i = 0; i < N; i++){
        printf("\nIntroduzca capital de provincia: ");
        //Al tratarse de una matriz de cadena, podemos ver que cada fila está compuesta por palabras, por lo que con tal de llamar únicamente a la fila podemos guardar la palabra en la matriz,
        //sin necesidad de hacer uso de las columnas
        scanf("%s", ciudades[i]);
    }
}
void CargarKilometros(char ciudades[][M], float distancia[][N]){
    for(int i = 0; i < N; i++){
        //Al tratarse de una matriz numérica, aquí si es necesario pararse en cada posición de la matriz para guardar cada dato.
        for(int j = 0; j < N; j++){
            printf("\nIntroduzca la distancia entre %s y %s: ", ciudades[i], ciudades[j]);
            scanf("%f", &distancia[i][j]);
        }
    }
    
}
void Visualizar_Tabla(char ciudades[][M], float distancia[][N]){
    //Modelamos la tabla haciendo uso de \t y de \n con el fin de estilizarla.
    printf("\n\nTABLA DE KILOMETROS\n");
    printf("\t");
    for(int i = 0; i < N; i++){
        
        printf("\t\t%s", ciudades[i]);

    }
    printf("\n");
    for(int j = 0; j < N; j++){
        printf("\t%s", ciudades[j]);
        for(int k = 0;  k < N; k++){
            printf("\t\t%.2f", distancia[j][k]);
        }
        printf("\n");
    }

    
}

int Validar(char ciudad[], char ciudades[][M]){
    //Usmos el strcmp para comparar strings, o char[]s. Esta función nos devuelve un 0 en caso de acierto o de igualdad
    int devolver = -1;
    for(int i = 0; i < N; i++){
        if(strcmp(ciudades[i], ciudad) == 0){
            devolver = i;
        }
    }

    return devolver;
}

float BuscarKilometros(float distancia[][N], int i_origen, int i_destino){
    //Un simple recorrido por la matriz de kms nos da la respuesta.
    float kms;
    for(int i = 0; i < N; i++){
        if(i_origen == i){
            for(int j = 0; j < N; j++){
                if(i_destino == j){
                    kms = distancia[i][j];
                }
            }
        }
        
    }
    return kms;
}

