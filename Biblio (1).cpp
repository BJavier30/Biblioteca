#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

struct Nodo
{
    string dato;
    Nodo* siguiente;
};
void menu_principal();
void pausa();
void agg(Nodo*& lista);
void Lista(Nodo*&, string);
void ver(Nodo*);
void buscar(Nodo*);

Nodo* lista = NULL;

int main()
{
    menu_principal();
    pausa();
    return 0;
}
void menu_principal()
{
    bool repite = true;
    int opcion;
    do {
        system("cls");
        cout << "\n\t\t\tMENU PRINCIPAL\n"; // Menu que sera visible
        cout << "\t1. AGREGAR LIBRO\n";
        cout << "\t2. VER LISTA DE LIBROS\n";
        cout << "\t3. BUSCAR LIBRO\n";
        cout << "\t0. SALIR\n";

        cout << "\n\tElija una Opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            agg(lista);
            break;

        case 2:
            ver(lista);
            break;

        case 3:
            buscar(lista);
            break;

        case 0:
            repite = false;
            break;

        default:
            cout << "Opcion no valida.\n";
            system("pause");
            break;
        }

    } while (repite);

}

void agg(Nodo*& lista) {
    string dato;  
    cout << "Ingrese el nombre del libro: ";
    cin.ignore();  
    getline(cin, dato);
    Lista(lista, dato);  
}

void Lista(Nodo*& lista, string dato) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = lista;  // Apunta al nodo anterior
    lista = nuevo_nodo;  // Actualiza la lista para que apunte al nuevo nodo
    cout << "\n\tEl libro \"" << dato << "\" se agrego correctamente.\n";
    pausa();
}
void pausa()
{    
    std::this_thread::sleep_for(std::chrono::milliseconds(800));  // Pausa por 8 milisegundos
}

void ver(Nodo* lista) {
    if (lista == NULL) {
        cout << "La lista esta vacia.\n";
        return;
    }
    Nodo* actual = lista;
    while (actual != NULL) {
        cout << "- " << actual->dato << "\n";
        actual = actual->siguiente;
    }
    system("pause");
}
void buscar(Nodo* lista) {
    if (lista == NULL) {
        cout << "La lista esta vacia.\n";
        return;
    }
    string dato;
    cout << "Ingrese el nombre del libro a buscar: ";
    cin.ignore();
    getline(cin, dato);

    Nodo* actual = lista;
    bool encontrado = false;

    while (actual != NULL) {
        if (actual->dato == dato) {
            cout << "El libro \"" << dato << "\" fue encontrado en la lista.\n";
            encontrado = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (!encontrado) {
        cout << "El libro \"" << dato << "\" no esta en la lista.\n";
    }
    system("pause");
}
