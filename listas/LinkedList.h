#include "../Nodo.h"

template <class T> class LinkedList {
private:
  Nodo<T> *head;

public:
  LinkedList() { this->head = nullptr; }
  void PushFront(T dato) {
    Nodo<T> *nodo = new Nodo<T>(dato);
    nodo->setNext(this->head);
    this->head = nodo;
  }
  T TopFront() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    return this->head->getDato();
  }
  void PopFront() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    this->head = this->head->getNext();
  }
  void PushBack(T dato) {
    if (!this->head) {
      this->PushFront(dato);
    } else {
      Nodo<T> *nodo = new Nodo<T>(dato);
      Nodo<T> *recorrer = this->head;
      while (recorrer->getNext()) {
        recorrer = recorrer->getNext();
      }
      recorrer->setNext(nodo);
    }
  }
  T TopBack() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      recorrer = recorrer->getNext();
    }
    return recorrer->getDato();
  }
  void PopBack() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    if (!this->head->getNext()) {
      this->head = nullptr;
      return;
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()->getNext()) {
      recorrer = recorrer->getNext();
    }
    recorrer->setNext(nullptr);
  }
  Nodo<T> *Find(T dato) {
    Nodo<T> *recorrer = this->head;
    while (recorrer) {
      if (recorrer->getDato() == dato) {
        return recorrer;
      }
      recorrer = recorrer->getNext();
    }
    throw std::runtime_error("no está en la lista");
  }
  void Erase(T dato) {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    if (this->head->getDato() == dato) {
      this->head = this->head->getNext();
      return;
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      if (recorrer->getNext()->getDato() == dato) {
        recorrer->setNext(recorrer->getNext()->getNext());
        return;
      }
      recorrer = recorrer->getNext();
    }
    throw std::runtime_error("No existe el dato");
  }
  bool Empty() {
    if (!this->head) {
      return true;
    }
    return false;
  }
  void AddBefore(Nodo<T> *nodo, T dato) {
    Nodo<T> *data = new Nodo<T>(dato);
    data->setNext(nodo);
    if (nodo == this->head) {
      this->head = data;
      return;
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer) {
      if (recorrer->getNext() == nodo) {
        recorrer->setNext(data);
        return;
      }
      recorrer = recorrer->getNext();
    }
    throw std::runtime_error("No existe el dato");
  }
  void AddAfter(Nodo<T> *nodo, T dato) {
    Nodo<T> *data = new Nodo<T>(dato);
    data->setNext(nodo->getNext());
    nodo->setNext(data);
  }
  void Display() {
    if (this->head) {
      Nodo<T> *recorrer = this->head;
      while (recorrer) {
        std::cout << recorrer->getDato() << " ";
        recorrer = recorrer->getNext();
      }
    }
    std::cout << '\n';
  }
  void DisplayBackwards() {
    LinkedList<T> listainv;
    Nodo<T> *recorrer = this->head;
    while (recorrer) {
      listainv.PushFront(recorrer->getDato());
      recorrer = recorrer->getNext();
    }
    listainv.Display();
  }
};