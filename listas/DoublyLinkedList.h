#include "../nodos.h"

template <class T> class DoublyLinkedList {
private:
  NodoPrev<T> *head;

public:
  DoublyLinkedList() { this->head = NULL; }
  void PushFront(T dato) {
    NodoPrev<T> *nodoprev = new NodoPrev<T>(dato);
    if (!this->head) {
      this->head = nodoprev;
      return;
    }
    this->head->setPrev(nodoprev);
    nodoprev->setNext(this->head);
    this->head = nodoprev;
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
  void PushBack(T dato) {
    NodoPrev<T> *nodoprev = new NodoPrev<T>(dato);
    if (!this->head) {
      this->head = nodoprev;
      return;
    }
    NodoPrev<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      recorrer = recorrer->getNext();
    }
    recorrer->setNext(nodoprev);
    nodoprev->setPrev(recorrer);
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
  void AddBefore(NodoPrev<T> *nodoprev, T dato) {
    NodoPrev<T> *data = new NodoPrev<T>(dato);
    if (nodoprev->getPrev()) {
      nodoprev->getPrev()->setNext(data);
    } else {
      this->head = data;
    }
    data->setPrev(nodoprev->getPrev());
    nodoprev->setPrev(data);
    data->setNext(nodoprev);
  }
  void AddAfter(NodoPrev<T> *nodoprev, T dato) {
    NodoPrev<T> *data = new NodoPrev<T>(dato);
    if (nodoprev->getNext()) {
      nodoprev->getNext()->setPrev(data);
    }
    data->setNext(nodoprev->getNext());
    nodoprev->setNext(data);
    data->setPrev(nodoprev);
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