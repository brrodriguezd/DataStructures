#include "../nodos.h"

template <class T> class LinkedList {
private:
  NodoNext<T> *head;

public:
  LinkedList() { this->head = NULL; }
  void PushFront(T dato) {
    NodoNext<T> *nodonext = new NodoNext<T>(dato);
    nodonext->setNext(this->head);
    this->head = nodonext;
  }
  T TopFront() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    return this->head->getData();
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
      NodoNext<T> *nodonext = new NodoNext<T>(dato);
      NodoNext<T> *recorrer = this->head;
      while (recorrer->getNext()) {
        recorrer = recorrer->getNext();
      }
      recorrer->setNext(nodonext);
    }
  }
  T TopBack() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    NodoNext<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      recorrer = recorrer->getNext();
    }
    return recorrer->getData();
  }
  void PopBack() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    if (!this->head->getNext()) {
      this->head = NULL;
      return;
    }
    NodoNext<T> *recorrer = this->head;
    while (recorrer->getNext()->getNext()) {
      recorrer = recorrer->getNext();
    }
    recorrer->setNext(NULL);
  }
  NodoNext<T> *Find(T dato) {
    NodoNext<T> *recorrer = this->head;
    while (recorrer) {
      if (recorrer->getData() == dato) {
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
    if (this->head->getData() == dato) {
      this->head = this->head->getNext();
      return;
    }
    NodoNext<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      if (recorrer->getNext()->getData() == dato) {
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
  void AddBefore(NodoNext<T> *nodonext, T dato) {
    NodoNext<T> *data = new NodoNext<T>(dato);
    data->setNext(nodonext);
    if (nodonext == this->head) {
      this->head = data;
      return;
    }
    NodoNext<T> *recorrer = this->head;
    while (recorrer) {
      if (recorrer->getNext() == nodonext) {
        recorrer->setNext(data);
        return;
      }
      recorrer = recorrer->getNext();
    }
    throw std::runtime_error("No existe el dato");
  }
  void AddAfter(NodoNext<T> *nodonext, T dato) {
    NodoNext<T> *data = new NodoNext<T>(dato);
    data->setNext(nodonext->getNext());
    nodonext->setNext(data);
  }
  void Display() {
    if (this->head) {
      NodoNext<T> *recorrer = this->head;
      while (recorrer) {
        std::cout << recorrer->getData() << " ";
        recorrer = recorrer->getNext();
      }
    }
    std::cout << '\n';
  }
  void DisplayBackwards() {
    LinkedList<T> listainv;
    NodoNext<T> *recorrer = this->head;
    while (recorrer) {
      listainv.PushFront(recorrer->getData());
      recorrer = recorrer->getNext();
    }
    listainv.Display();
  }
};