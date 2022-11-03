#include "../Nodo.h"

template <class T = int> class LinkedList_O {
private:
  Nodo<T> *head;

public:
  LinkedList_O() { this->head = NULL; }

  void Insert(T dato) {
    Nodo<T> *nodo = new Nodo<T>(dato);
    if (!this->head) {
      this->head = nodo;
      return;
    }
    if (!(this->head->getData() < dato)) {
      nodo->setNext(this->head);
      this->head = nodo;
      return;
    }
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      if (!(recorrer->getNext()->getData() < dato)) {
        break;
      }
      recorrer = recorrer->getNext();
    }
    nodo->setNext(recorrer->getNext());
    recorrer->setNext(nodo);
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
  T TopBack() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    Nodo<T> *recorrer = this->head;
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
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()->getNext()) {
      recorrer = recorrer->getNext();
    }
    recorrer->setNext(NULL);
  }
  Nodo<T> *Find(T dato) {
    Nodo<T> *recorrer = this->head;
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
    Nodo<T> *recorrer = this->head;
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
  void Display() {
    if (this->head) {
      Nodo<T> *recorrer = this->head;
      while (recorrer) {
        std::cout << recorrer->getData() << " ";
        recorrer = recorrer->getNext();
      }
    }
    std::cout << '\n';
  }
  /*void DisplayBackwards() {
    LinkedList_O<T> listainv;
    Nodo<T> *recorrer = this->head;
    while (recorrer) {
      listainv.PushFront(recorrer->getData());
      recorrer = recorrer->getNext();
    }
    listainv.Display();
  }*/
};