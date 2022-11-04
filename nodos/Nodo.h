#pragma once
#include <iostream>

template <class T> class Nodo {
protected:
  T dato;

public:
  Nodo(T dato) { this->dato = dato; }
  void setDato(T dato) { this->dato = dato; }
  T getData() { return this->dato; }
};