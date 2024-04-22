#include "Pila.h"
#include "Cola.h"
#include <iostream>
#include <limits>

using namespace std;

void modificar_estructura(Pila &pila, int X) {
    Pila pila_temporal; // Una pila temporal para guardar los elementos hasta encontrar X
    bool encontrado = false;

    // Desapilamos elementos hasta que encontremos X o la pila esté vacía
    while (!pila.esta_vacia() && !encontrado) {
        int elemento = pila.desapilar();
        if (elemento == X) {
            encontrado = true;
            pila_temporal.apilar(elemento); // Apilamos X de nuevo en la pila temporal
        }
    }

    // Devolvemos todos los elementos desde la pila temporal a la pila original
    while (!pila_temporal.esta_vacia()) {
        pila.apilar(pila_temporal.desapilar());
    }

    // Informamos al usuario si no se encontró el elemento X
    if (!encontrado) {
        cout << "El valor " << X << " no se encontró en la pila." << endl;
    }
}

void modificar_estructura(Cola &cola, int X) {
    Cola cola_temporal; // Una cola temporal para guardar elementos
    bool encontrado = false;

    // Desencolamos elementos hasta encontrar X o hasta que la cola esté vacía
    while (!cola.esta_vacia() && !encontrado) {
        int elemento = cola.desencolar();
        if (elemento == X) {
            encontrado = true;
            cola_temporal.encolar(elemento); // Reencolamos X en la cola temporal
        }
    }

    // Transferimos de vuelta a la cola original los elementos en cola temporal (solo X si se encontró)
    while (!cola_temporal.esta_vacia()) {
        cola.encolar(cola_temporal.desencolar());
    }

    // Informamos al usuario si X no fue encontrado en la cola
    if (!encontrado) {
        cout << "El valor " << X << " no se encontró en la cola." << endl;
    }
}

// Función para obtener entrada válida del usuario
int obtenerValor() {
    int valor;
    while (!(cin >> valor)) {
        cin.clear(); // Limpia el estado de error de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada hasta el siguiente salto de línea
        cout << "Entrada inválida. Por favor, ingrese un número entero: ";
    }
    return valor;
}

int main() {
    Pila miPila;
    Cola miCola;
    int opcion, valor, X;

    do {
        cout << "\nMenú de Operaciones:\n";
        cout << "1. Apilar elemento en Pila\n";
        cout << "2. Desapilar elemento de Pila\n";
        cout << "3. Encolar elemento en Cola\n";
        cout << "4. Desencolar elemento de Cola\n";
        cout << "5. Modificar estructura Pila\n";
        cout << "6. Modificar estructura Cola\n";
        cout << "7. Imprimir Pila\n";
        cout << "8. Imprimir Cola\n";
        cout << "9. Salir\n";
        cout << "Seleccione una opción: ";
        opcion = obtenerValor();

        switch (opcion) {
            case 1:
                cout << "Ingrese un valor para apilar: ";
                valor = obtenerValor();
                miPila.apilar(valor);
                cout << "Valor apilado correctamente." << endl;
                break;
            case 2:
                if (!miPila.esta_vacia()) {
                    cout << "Elemento desapilado: " << miPila.desapilar() << endl;
                } else {
                    cout << "La pila está vacía." << endl;
                }
                break;
            case 3:
                cout << "Ingrese un valor para encolar: ";
                valor = obtenerValor();
                miCola.encolar(valor);
                cout << "Valor encolado correctamente." << endl;
                break;
            case 4:
                if (!miCola.esta_vacia()) {
                    cout << "Elemento desencolado: " << miCola.desencolar() << endl;
                } else {
                    cout << "La cola está vacía." << endl;
                }
                break;
            case 5:
                cout << "Ingrese el valor X para modificar la Pila: ";
                X = obtenerValor();
                modificar_estructura(miPila, X);
                miPila.imprimir();
                break;
            case 6:
                cout << "Ingrese el valor X para modificar la Cola: ";
                X = obtenerValor();
                modificar_estructura(miCola, X);
                miCola.imprimir();
                break;
            case 7:
                miPila.imprimir();
                break;
            case 8:
                miCola.imprimir();
                break;
            case 9:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida, por favor intente de nuevo." << endl;
        }
    } while (opcion != 9);

    return 0;
}
