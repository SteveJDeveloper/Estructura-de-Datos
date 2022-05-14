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
    cout << "1. Crear" << endl;
    cout << "2. Insertar al Inicio" << endl;
    cout << "3. Insertar al Final" << endl;
    cout << "4. Insertar por Posicion" << endl;
    cout << "5. Eliminar al Inicio" << endl;
    cout << "6. Eliminar al Final" << endl;
    cout << "7. Eliminar por Posicion" << endl;
    cout << "8. Imprimir" << endl;
    cout << "9. Destruir" << endl;
    cout << "10.Salir" << endl;
    cout << "\nDigite su Opcion: ";
}

NODO *Insertar_cabeza(NODO *cab){
    NODO *nuevo;
    nuevo = new NODO;
    cout << "\nIngrese el dato: ";
    cin >> nuevo->dato;
    nuevo->sig = NULL;
    if(cab == NULL)
        cab = nuevo;
    else{
        nuevo->sig = cab;
        cab = nuevo;
    }
    return cab;
}

void Insertar_final(NODO *cab){
    NODO *nuevo,*ultimo;
    ultimo = cab;
    while(ultimo->sig != NULL)
        ultimo = ultimo->sig;
    nuevo = new NODO;
    cout << "\nIngrese el dato: ";
    cin >> nuevo->dato;
    nuevo->sig = NULL;
    ultimo->sig = nuevo;
}

void Insertar_posicion(NODO *cab){
    NODO *nuevo,*ultimo;
    ultimo = cab;

}

NODO *Eliminar_inicio(NODO *cab){
    NODO *aux;
    aux = cab;
    cab = cab->sig;
    free(aux);
    return cab;
}

void Eliminar_final(NODO *cab){
    if(cab->sig == NULL){
        cout << "Lo siento - No se puede elimnar de esta forma" << endl;
        cout << "Utilice la Opcion 5" << endl;
    }else{
        NODO *ultimo,*anterior;
        ultimo = cab;
        anterior = cab;
        while(ultimo->sig != NULL){
            anterior  = ultimo;
            ultimo = ultimo->sig;
        }
        anterior->sig = NULL;
        free(ultimo);
    }

}

void Imprimir(NODO *cab){
    NODO *aux;
    aux = cab;
    cout << endl;
    while(aux != NULL){
        cout << "| " << aux->dato << " ";
        aux = aux->sig;
    }
}



int main()
{
    int opcion;

    NODO *principal = NULL;

    do{

        MostrarMenu();
        cin >> opcion;

        switch(opcion){
            case 1:{

                break;
            }
            case 2:{
                principal = Insertar_cabeza(principal);
                break;
            }
            case 3:{
                Insertar_final(principal);
                break;
            }
            case 4:{

                break;
            }
            case 5:{
                Eliminar_inicio(principal);
                break;
            }
            case 6:{
                Eliminar_final(principal);
                break;
            }
            case 7:{

                break;
            }
            case 8:{
                Imprimir(principal);
                break;
            }
            case 9:{

                break;
            }
            case 10:{
                cout << "\n***GRACIAS POR UTILIZAR ESTE PROGRAMA***" << endl;
                cout << "REALIZADO POR: STEVE JIMBO" << endl;
                break;
            }
            default:{
                cout << "\nOpcion Incorrecta" << endl;
                break;
            }
        }
    }while(opcion != 10);

    return 0;
}
