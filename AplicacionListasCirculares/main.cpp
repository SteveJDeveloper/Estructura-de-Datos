//Autor: Steve Jimbo
//Fecha: 07-05-2018
//Materia: Estructura De Datos I

//Declaracion de Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

//Declaracion del nodo a utilizar
struct NODO{
    char nombre[40];
    struct NODO *sig;
};

//Esta funcion imprime el menu de opciones que se va
//a utilizar en el programa
void MostrarMenu(){
    cout << "\n\t\tMENU DE OPCIONES" << endl;
    cout << "1. Cargar lista de soldados" << endl;
    cout << "2. Listar soldados en la lista" << endl;
    cout << "3. Salvar Soldado" << endl;
    cout << "4. Salir" << endl;
    cout << "\nDigite su Opcion: ";
}

//Esta funcion nos permite ingresar los elementos a la lista
//de forma circular
NODO *Insertar_Elemento(NODO *cab){
    int sw = 0;
    NODO *nuevo,*ultimo;
    nuevo = new NODO;
    cout << "\nIngresar Nombre: ";
    cin >> nuevo->nombre;
    nuevo->sig = NULL;
    if(cab == NULL){
        cab = nuevo;
        return cab;
    }else{
        ultimo = cab;
        while(ultimo->sig != NULL)
            ultimo = ultimo->sig;
        ultimo->sig = nuevo;
    }

    return cab;
}

//Esta funcion nos permite imprimir los datos de una lista circular
void Imprimir_Lista(NODO *cab){
    int a = 1;
    NODO *aux = cab;
    cout << endl;
    if(cab == NULL){
        cout << "No Hay Lista Para Imprimir" << endl;
        return;
    }
    while(aux->sig != cab){
        cout << a << ". " << aux->nombre << endl;
        aux = aux->sig;
        a++;
    }
    cout << a << ". " << aux->nombre << endl;
}

void Eliminar_Soldado(NODO *cab){
    char busqueda[40];
    int pasos, condicion, contador = 0;
    NODO *aux,*anterior;
    aux = cab;
    cout << endl;
    Imprimir_Lista(cab);
    cout << "\nIngresar Nombre: ";
    cin >> busqueda;
    cout << "\nIngresar Numero De Desplazamiento: ";
    cin >> pasos;

    while(true){
        condicion = strcmp(busqueda,aux->nombre);
        if(condicion == 0){
            break;
        }
        aux = aux->sig;
    }
    while(aux->sig != aux){
        if(contador == pasos){
            aux = aux->sig;
            anterior->sig = aux;
            contador = 0;
        }else{
            anterior = aux;
            aux = aux->sig;
            contador++;
        }
    }
    cout << "\nSe Salva: " << aux->nombre << endl;
}

//Programa Principal
int main()
{
    //Declaracion de Variables y estructuras a utilizar
    int opcion,con;

    NODO *principal = NULL;
    NODO *ultimo;

    do{

        MostrarMenu();
        cin >> opcion;

        //Ejecucion de los modulos
        switch(opcion){
            case 1:{
                do{
                    principal = Insertar_Elemento(principal);
                    cout << "\nDesea ingresar un nuevo nombre?" << endl;
                    cout << "1. Si             2. No" << endl;
                    cout << "Digite su opcion: ";
                    cin >> con;
                }while(con != 2);
                ultimo = principal;
                while(ultimo->sig != NULL)
                    ultimo = ultimo->sig;
                ultimo->sig = principal;
                break;
            }
            case 2:{
                Imprimir_Lista(principal);
                break;
            }
            case 3:{
                Eliminar_Soldado(principal);
                break;
            }
            case 4:{
                break;
            }
        }

    }while(opcion != 4);
    return 0;
}
