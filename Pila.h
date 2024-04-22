#pragma once
#include <vector>
#include <iostream>

// Clase que implementa una estructura de datos de tipo pila.
// Permite operaciones estándar de pila como apilar, desapilar e imprimir.
class Pila {
private:
    std::vector<int> elementos; // Almacena los elementos de la pila.

public:
    // Reinicializa la pila para que esté vacía.
    void crear();

    // Agrega un elemento en la parte superior de la pila.
    // @param elemento: El valor entero a apilar.
    void apilar(int elemento);

    // Remueve y retorna el elemento superior de la pila.
    // @return: El valor en la parte superior de la pila.
    // @throws std::runtime_error si la pila está vacía.
    int desapilar();

    // Comprueba si la pila está vacía.
    // @return: Verdadero si la pila no tiene elementos, falso de lo contrario.
    bool esta_vacia() const;

    // Imprime todos los elementos de la pila desde el más reciente al más antiguo.
    void imprimir() const;
};
