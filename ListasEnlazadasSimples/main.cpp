#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct NODO{
    int dato;
    NODO *sig;
};

void MostrarMenu(){
    cout << "\n\t\tMENU DE OPCIONES" << endl;
    cout << "1. Insertar Elemento (Por ordenamiento)" << endl;
    cout << "2. Eliminar Elemento Buscado" << endl;
    cout << "3. Imprimir - Iterativo" << endl;
    cout << "4. Imprimir - Recursivo" << endl;
    cout << "5. Destruir la Lista" << endl;
    cout << "6. Salir" << endl;
    cout << "\nDigite su Opcion: ";
}

NODO *Insertar_Elemento(NODO *cab){
    int caso = 0, sw = 0;
    NODO *nuevo = new NODO;
    NODO *ultimo = cab;
    cout << "\nIngresar Dato: ";
    cin >> nuevo->dato;
    nuevo->sig = NULL;
    if(cab->sig == NULL)
        caso = 2;
    if(cab->dato == 0)
        caso = 1;
    if(cab->dato > nuevo->dato)
        caso = 3;
    if(caso == 0){
        while(ultimo->sig != NULL)
            ultimo = ultimo->sig;
        if(ultimo->dato < nuevo->dato)
            caso = 4;
    }
    switch(caso){
        case 0:{
            NODO *aux = cab;
            NODO *anterior = cab;
            do{
                if(aux->dato < nuevo->dato){
                    anterior = aux;
                    aux = aux->sig;
                }else
                    sw = 1;
            }while(sw != 1);
            nuevo->sig = aux;
            anterior->sig = nuevo;
            break;
        }
        case 1:{
            cab = nuevo;
            break;
        }
        case 2:{
            cab->sig = nuevo;
            break;
        }
        case 3:{
            nuevo->sig = cab;
            cab = nuevo;
            break;
        }
        case 4:{
            ultimo->sig = nuevo;
            break;
        }
    }
    return cab;
}

NODO *Eliminar_Elemento(NODO *cab){
    NODO *aux = cab;
    NODO *ultimo = cab;
    NODO *anterior = cab;

    int busqueda, sw = 0, caso = 0;

    cout << "\nIngresar el Dato a eliminar: ";
    cin >> busqueda;

    while(ultimo->sig != NULL)
            ultimo = ultimo->sig;
    if(cab->dato == busqueda)
        caso = 1;
    if(ultimo->dato == busqueda)
        caso = 2;

    switch(caso){
        case 0:{
            while(aux->sig != NULL){
                if(aux->dato == busqueda){
                    ultimo =  aux->sig;
                    anterior->sig = ultimo;
                    free(aux);
                    sw = 1;
                    break;
                }
                anterior  = aux;
                aux = aux->sig;
            }
            break;
        }
        case 1:{
            cab = cab->sig;
            free(aux);
            sw = 1;
            break;
        }
        case 2:{
            ultimo = cab;
            while(ultimo->sig != NULL){
                anterior  = ultimo;
                ultimo = ultimo->sig;
            }
            anterior->sig = NULL;
            free(ultimo);
            sw = 1;
            break;
        }
    }
    if(sw == 0){
        cout << "\nEl Dato No Fue Encontrado\n" << endl;
    }else{
        cout << "\nEl Dato Ha Sido Borrado\n" << endl;
    }
    return cab;
}

void Imprimir_Iterativo(NODO *cab){
    NODO *aux = cab;
    cout << endl;
    if(cab != NULL){
        while(aux != NULL){
            cout << "| " << aux->dato << " ";
            aux = aux->sig;
        }
    }else{
        cout << "No Hay Lista Para Imprimir" << endl;
    }
}

void Imprimir_Recursivo(NODO *cab){
    NODO *aux = cab;
    if(aux != NULL){
        cout << "| " << aux->dato << " ";
        aux = aux->sig;
        Imprimir_Recursivo(aux);
    }
}

NODO *Destruir(NODO *cab){
    NODO *aux =  cab;
    while(aux->sig != NULL){
        cab = aux;
        aux = aux->sig;
        free(cab);
    }
    cab = aux;
    free(cab);
    cab = NULL;
    cout << "\nLa Lista Ha Sido Destruida" << endl;
    return cab;
}

int main()
{
    int opcion, con;

    NODO *principal = new NODO;

    do{

        MostrarMenu();
        cin >> opcion;

        switch(opcion){
            case 1:{
                do{
                    principal = Insertar_Elemento(principal);
                    cout << "\nDesea ingresar un nuevo numero?" << endl;
                    cout << "1. Si" << endl;
                    cout << "2. No" << endl;
                    cout << "Digite su opcion: ";
                    cin >> con;
                }while(con != 2);
                break;
            }
            case 2:{
                principal = Eliminar_Elemento(principal);
                break;
            }
            case 3:{
                Imprimir_Iterativo(principal);
                break;
            }
            case 4:{
                cout << endl;
                Imprimir_Recursivo(principal);
                break;
            }
            case 5:{
                principal = Destruir(principal);
                break;
            }
            case 6:{
                cout << "\n***GRACIAS POR UTILIZAR ESTE PROGRAMA***" << endl;
                cout << "REALIZADO POR: STEVE JIMBO" << endl;
                break;
            }
            default:{
                cout << "\nOpcion Incorrecta" << endl;
                break;
            }
        }

    }while(opcion != 6);

    return 0;
}
