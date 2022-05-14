//Autor: Steve Jimbo
//Fecha: 15-05-2018
//Materia: Estructura De Datos I

//Declaracion de Librerias
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

//Declaracion de la estructura
struct NODO{
    int dato;
    struct NODO *ant,*sig;
};

//Funcion que permite la visualizacion del menu
void MostrarMenu(){
    cout << "\n\t\tMENU DE OPCIONES" << endl;
    cout << "1. Crear " << endl;
    cout << "2. Borrar por Busqueda" << endl;
    cout << "3. Imprimir Ascendente" << endl;
    cout << "4. Imprimir Descendente" << endl;
    cout << "5. Salir" << endl;
    cout << "\nDigite su Opcion: ";
}

//Funcion que permite borrar un elemento por busqueda
void Eliminar(NODO* &cab, NODO* &ult){
    NODO *aux;
    int numero, caso = 0;
    cout << "\nIngresar Dato A Eliminar: ";
    cin >> numero;
    if(numero == cab->dato)
        caso = 1;
    if(numero == ult->dato)
        caso = 2;
    if(caso == 0){
        aux = cab;
        while(aux->dato != numero)
            aux = aux->sig;
    }
    switch(caso){
        case 0:{
            aux->ant->sig = aux->sig;
            aux->sig->ant = aux->ant;
            free(aux);
            break;
        }
        case 1:{
            aux = cab;
            cab = cab->sig;
            cab->ant = ult;
            ult->sig = cab;
            aux = NULL;
            free(aux);
            break;
        }
        case 2:{
            aux = ult;
            ult = ult->ant;
            ult->sig = cab;
            cab->ant = ult;
            aux = NULL;
            free(aux);
            break;
        }
    }
}

//Funcion que permite cargar la lista de elementos desde un archivo plano
void CargarElementos(NODO* &cab, NODO* &ult){
    int numero, caso = 0, sw = 0;
    NODO *aux,*nuevo,*anterior;
    FILE*flujo=fopen("Original.txt","r");
    while(!feof(flujo)){
        fscanf(flujo,"%d",&numero);
        if(!feof(flujo)){
            caso = 0;
            sw = 0;
            nuevo = new NODO;
            nuevo->sig = NULL;
            nuevo->ant = NULL;
            nuevo->dato = numero;
            if(cab == NULL)
                caso = 1;
            if(caso == 0){
                if(cab->dato > nuevo->dato)
                    caso = 2;
                if(ult->dato < nuevo->dato)
                    caso = 3;
            }
            switch(caso){
                case 0:{
                    aux = cab;
                    do{
                        if(aux->dato < nuevo->dato){
                            anterior = aux;
                            aux = aux->sig;
                        }else{
                            sw = 1;
                        }
                    }while(sw != 1);
                    nuevo->sig = aux;
                    nuevo->ant = anterior;
                    anterior->sig = nuevo;
                    aux->ant = nuevo;
                    break;
                }
                case 1:{
                    cab = nuevo;
                    ult = cab;
                    break;
                }
                case 2:{
                    aux = cab;
                    cab = nuevo;
                    cab->sig = aux;
                    aux->ant = cab;
                    break;
                }
                case 3:{
                    ult->sig = nuevo;
                    nuevo->ant = ult;
                    ult = nuevo;
                    break;
                }
            }
        }
    }
    fclose(flujo);
    cab->ant = ult;
    ult->sig = cab;
}

//Funcion que permite imprimir la lista de forma ascendente
void Imprimir_Ascendente(NODO *cab){
    NODO *aux = cab;
    cout << "\nIMPRESION ASCENDENTE: " << endl;
    if(cab != NULL){
        while(aux->sig != cab){
            cout << " | " << aux->dato;
            aux = aux->sig;
        }
        cout << " | " << aux->dato;
        cout << " | " << endl;
    }else{
        cout << "\nNO HAY NINGUNA LISTA PARA IMPRIMIR" << endl;
    }
}

//Funcion que permite imprimir la lista de forma descendente
void Imprimir_Descendente(NODO *ult){
    NODO *aux = ult;
    cout << "\nIMPRESION DESCENDENTE: " << endl;
    if(ult != NULL){
        while(aux->ant != ult){
            cout << " | " << aux->dato;
            aux = aux->ant;
        }
        cout << " | " << aux->dato;
        cout << " | " << endl;
    }else{
        cout << "\nNO HAY NINGUNA LISTA PARA IMPRIMIR" << endl;
    }
}

int main()
{
    //Declaracion de variables y estructuras a utilizar
    NODO *cab,*ult;
    cab = NULL;
    ult = NULL;
    int opcion;

    do{
        MostrarMenu();
        cin >> opcion;
        switch(opcion){
            case 1:{
                CargarElementos(cab,ult);
                cout << "\nLista Creada Correctamente" << endl;
                break;
            }

            case :{
                Imprimir_Ascendente(cab);
                break;
            }
            case :{
                Imprimir_Descendente(ult);
                break;
            }
            case :{
                Eliminar(cab,ult);
                break;
            }

            default:{
                cout << "\nOpcion Incorrecta" << endl;
                break;
            }
        }
    }while(opcion != );

    return 0;
}
