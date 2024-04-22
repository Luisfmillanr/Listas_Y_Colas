#include "Cola.h"
#include <stdexcept> // Para std::runtime_error

void Cola::crear() {
    std::queue<int> empty;
    swap(elementos, empty);
}

void Cola::encolar(int elemento) {
    elementos.push(elemento);
}

int Cola::desencolar() {
    if (esta_vacia()) {
        throw std::runtime_error("Desencolar llamado en cola vacía.");
    }
    int frente = elementos.front();
    elementos.pop();
    return frente;
}

bool Cola::esta_vacia() const {
    return elementos.empty();
}

void Cola::imprimir() const {
    std::cout << "Cola: ";
    std::queue<int> copia = elementos; // Esto sigue siendo necesario debido a la naturaleza de std::queue que no provee un iterador
    while (!copia.empty()) {
        std::cout << copia.front() << " ";
        copia.pop();
    }
    std::cout << std::endl;
}
