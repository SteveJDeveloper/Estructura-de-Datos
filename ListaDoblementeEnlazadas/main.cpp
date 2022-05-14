//Autor: Steve Jimbo
//Fecha: 08-05-2018
//Materia: Estructura De Datos I

//Declaracion de Librerias
#include <stdlib.h>
#include <iostream>

using namespace std;

//Declaracion de la estructura a usar
struct NODO{
    int dato;
    struct NODO *sig,*ant;
};

//Funcion que permite la visualizacion del menu
void MostrarMenu(){
    cout << "\n\t\tMENU DE OPCIONES" << endl;
    cout << "1. Crear " << endl;
    cout << "2. Borrar por Búsqueda" << endl;
    cout << "3. Imprimir Ascendente" << endl;
    cout << "4. Imprimir Descendente" << endl;
    cout << "5. Salir" << endl;
    cout << "\nDigite su Opcion: ";
}

//Funcion que permite crear la lista doblemente enlazada
void Crear(NODO* &cab, NODO* &ult){
    NODO *nuevo = new NODO;
    cout << "\nIngresar Dato: ";
    cin >> nuevo->dato;
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    if(cab == NULL){
        cab = nuevo;
        ult = cab;
    }else{
        ult->sig = nuevo;
        nuevo->ant = ult;
        ult = nuevo;
    }
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
            cab->ant = NULL;
            free(aux);
            break;
        }
        case 2:{
            aux = ult;
            ult = ult->ant;
            ult->sig = NULL;
            free(aux);
            break;
        }
    }

}

//Funcion que permite imprimir la lista de forma ascendente
void Imprimir_Ascendente(NODO *cab){
    NODO *aux = cab;
    cout << "\nIMPRESION:" << endl;
    if(cab != NULL){
        while(aux != NULL){
            cout << " | " << aux->dato;
            aux = aux->sig;
        }
        cout << " | " << endl;
    }else{
        cout << "\nNO HAY NINGUNA LISTA PARA IMPRIMIR" << endl;
    }
}

//Funcion que permite imprimir la lista de forma descendente
void Imprimir_Descendente(NODO *ult){
    NODO *aux = ult;
    cout << "\nIMPRESION:" << endl;
    if(ult != NULL){
        while(aux != NULL){
            cout << " | " << aux->dato;
            aux = aux->ant;
        }
        cout << " | " << endl;
    }else{
        cout << "\nNO HAY NINGUNA LISTA PARA IMPRIMIR" << endl;
    }

}

int main()
{
    //Declaaracion de variable sy estructuras
    int opcion, con;
    NODO *cab,*ult;
    cab = NULL;
    //Ciclo repetitivo del menu
    do{
        MostrarMenu();
        cin >> opcion;
        //Ejecucion del switch segun el caso
        switch(opcion){
            case 1:{
                do{
                    Crear(cab,ult);
                    cout << "\nDesea ingresar un nuevo dato?" << endl;
                    cout << "1. Si             2. No" << endl;
                    cout << "Digite su opcion: ";
                    cin >> con;
                }while(con != 2);
                break;
            }
            case 2:{
                Eliminar(cab,ult);
                break;
            }
            case 3:{
                Imprimir_Ascendente(cab);
                break;
            }
            case 4:{
                Imprimir_Descendente(ult);
                break;
            }
            case 5:{
                cout << "\n***GRACIAS POR UTILIZAR ESTE PROGRAMA***" << endl;
                cout << "REALIZADO POR: STEVE JIMBO" << endl;
                break;
            }
            default:{
                cout << "\nOpcion Incorrecta" << endl;
                break;
            }
        }

    }while(opcion != 5);
    return 0;
}
