#include "Pila.h"
#include <stdexcept> // Para std::runtime_error

void Pila::crear() {
    elementos.clear();
}

void Pila::apilar(int elemento) {
    elementos.push_back(elemento);
}

int Pila::desapilar() {
    if (esta_vacia()) {
        throw std::runtime_error("Desapilar llamado en pila vacía.");
    }
    int tope = elementos.back();
    elementos.pop_back();
    return tope;
}

bool Pila::esta_vacia() const {
    return elementos.empty();
}

void Pila::imprimir() const {
    std::cout << "Pila: ";
    for (int i = elementos.size() - 1; i >= 0; --i) {
        std::cout << elementos[i] << " ";
    }
    std::cout << std::endl;
}
