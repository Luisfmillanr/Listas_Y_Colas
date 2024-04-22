#pragma once
#include <queue>
#include <iostream>

class Cola {
private:
    std::queue<int> elementos; // Contenedor interno para almacenar los elementos de la cola.

public:
    // Inicializa la cola para que esté vacía.
    void crear();
    
    // Añade un elemento al final de la cola.
    // Parámetro elemento: El valor a encolar.
    void encolar(int elemento);
    
    // Remueve y retorna el elemento al frente de la cola.
    // Retorna: El valor al frente de la cola o lanza una excepción si la cola está vacía.
    int desencolar();
    
    // Comprueba si la cola está vacía.
    // Retorna: True si la cola no tiene elementos, false de lo contrario.
    bool esta_vacia() const;
    
    // Imprime todos los elementos en la cola sin modificarla.
    void imprimir() const;
};
