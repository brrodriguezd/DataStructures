#include "../nodos.h"

template <class T> class DoublyLinkedList_O {
private:
  NodoPrev<T> *head;

public:
  DoublyLinkedList_O() { this->head = NULL; }

  void Insert(T dato) {
    NodoPrev<T> *nodoprev = new NodoPrev<T>(dato);
    if (!this->head) {
      this->head = nodoprev;
      return;
    }
    if (!(this->head->getData() < dato)) {
      this->head->setPrev(nodoprev);
      nodoprev->setNext(this->head);
      this->head = nodoprev;
      return;
    }
    NodoPrev<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      if (!(recorrer->getNext()->getData() < dato)) {
        break;
      }
      recorrer = recorrer->getNext();
    }
    nodoprev->setNext(recorrer->getNext());
    recorrer->setNext(nodoprev);
    nodoprev->setPrev(recorrer);
    if (nodoprev->getNext()) {
      nodoprev->getNext()->setPrev(nodoprev);
    }
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
    if (this->head) {
      this->head->setPrev(NULL);
    }
  }
  T TopBack() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    NodoPrev<T> *recorrer = this->head;
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
    NodoPrev<T> *recorrer = this->head;
    while (recorrer->getNext()->getNext()) {
      recorrer = recorrer->getNext();
    }
    recorrer->setNext(NULL);
  }
  NodoPrev<T> *Find(T dato) {
    NodoPrev<T> *recorrer = this->head;
    while (recorrer->getData()) {
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
      this->PopFront();
      return;
    }
    NodoPrev<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      if (recorrer->getNext()->getData() == dato) {
        if (recorrer->getNext()->getNext()) {
          recorrer->getNext()->getNext()->setPrev(recorrer);
          recorrer->setNext(recorrer->getNext()->getNext());
          return;
        }
        recorrer->setNext(NULL);
        return;
      }
      recorrer = recorrer->getNext();
    }
    throw std::runtime_error("No se encontro el dato");
  }
  bool Empty() {
    if (!this->head) {
      return true;
    }
    return false;
  }
  void Display() {
    if (this->head) {
      NodoPrev<T> *recorrer = this->head;
      while (recorrer) {
        std::cout << recorrer->getData() << " ";
        recorrer = recorrer->getNext();
      }
    }
    std::cout << '\n';
  }
  void DisplayBackwards() {
    if (this->head) {
      NodoPrev<T> *recorrer = this->head;
      while (recorrer->getNext()) {
        recorrer = recorrer->getNext();
      }
      while (recorrer) {
        std::cout << recorrer->getData() << " ";
        recorrer = recorrer->getPrev();
      }
    }
    std::cout << '\n';
  }
};