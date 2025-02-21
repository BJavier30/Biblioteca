#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

struct Nodo {
    string dato;
    Nodo* siguiente;
};

// Declaración de funciones
void menu_principal();
void pausa();
void agregarLibro(Nodo*& lista);
void insertarEnLista(Nodo*&, string);
void verLibros(Nodo*);
void buscarLibro(Nodo*);
void eliminarLibro(Nodo*&);

Nodo* lista = NULL;

int main() {
    menu_principal();
    return 0;
}

void menu_principal() {
    bool repite = true;
    int opcion;
    do {
        system("cls");
        cout << "\n\t\t\tMENU PRINCIPAL\n";
        cout << "\t1. AGREGAR LIBRO\n";
        cout << "\t2. VER LISTA DE LIBROS\n";
        cout << "\t3. BUSCAR LIBRO\n";
        cout << "\t4. ELIMINAR LIBRO\n";
        cout << "\t0. SALIR\n";

        cout << "\n\tElija una Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                agregarLibro(lista);
                break;
            case 2:
                verLibros(lista);
                break;
            case 3:
                buscarLibro(lista);
                break;
            case 4:
                eliminarLibro(lista);
                break;
            case 0:
                repite = false;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                pausa();
                break;
        }
    } while (repite);
}

void agregarLibro(Nodo*& lista) {
    string dato;
    cout << "Ingrese el nombre del libro: ";
    getline(cin, dato);
    insertarEnLista(lista, dato);
}

void insertarEnLista(Nodo*& lista, string dato) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = lista;
    lista = nuevo_nodo;
    cout << "\n\tEl libro \"" << dato << "\" se agrego correctamente.\n";
    pausa();
}

void verLibros(Nodo* lista) {
    if (lista == NULL) {
        cout << "La lista esta vacia.\n";
    } else {
        Nodo* actual = lista;
        while (actual != NULL) {
            cout << "- " << actual->dato << "\n";
            actual = actual->siguiente;
        }
    }
    pausa();
}

void buscarLibro(Nodo* lista) {
    if (lista == NULL) {
        cout << "La lista esta vacia.\n";
        pausa();
        return;
    }
    string dato;
    cout << "Ingrese el nombre del libro a buscar: ";
    getline(cin, dato);

    Nodo* actual = lista;
    int posicion = 1;
    bool encontrado = false;

    while (actual != NULL) {
        if (actual->dato == dato) {
            cout << "El libro \"" << dato << "\" fue encontrado en la posicion " << posicion << " de la lista.\n";
            encontrado = true;
            break;
        }
        actual = actual->siguiente;
        posicion++;
    }

    if (!encontrado) {
        cout << "El libro \"" << dato << "\" no esta en la lista.\n";
    }
    pausa();
}

void eliminarLibro(Nodo*& lista) {
    if (lista == NULL) {
        cout << "La lista esta vacia. No hay libros para eliminar.\n";
        pausa();
        return;
    }
    string dato;
    cout << "Ingrese el nombre del libro a eliminar: ";
    getline(cin, dato);

    Nodo* actual = lista;
    Nodo* anterior = NULL;
    bool encontrado = false;

    while (actual != NULL) {
        if (actual->dato == dato) {
            if (anterior == NULL) {
                lista = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            cout << "El libro \"" << dato << "\" ha sido eliminado correctamente.\n";
            encontrado = true;
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    }

    if (!encontrado) {
        cout << "El libro \"" << dato << "\" no se encuentra en la lista.\n";
    }
    pausa();
}

void pausa() {
    this_thread::sleep_for(chrono::milliseconds(800));
}
