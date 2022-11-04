#include "../nodos.h"

template <class T> class DoublyLinkedListTail {
private:
  NodoPrev<T> *head;
  NodoPrev<T> *tail;

public:
  DoublyLinkedListTail() {
    this->head = NULL;
    this->tail = NULL;
  }
  void PushFront(T dato) {
    NodoPrev<T> *nodoprev = new NodoPrev<T>(dato);
    if (!this->head) {
      this->head = this->tail = nodoprev;
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
    if (!this->head) {
      this->tail = NULL;
      return;
    }
    this->head->setPrev(NULL);
  }
  void PushBack(T dato) {
    NodoPrev<T> *nodoprev = new NodoPrev<T>(dato);
    if (!this->tail) {
      this->head = this->tail = nodoprev;
      return;
    }
    this->tail->setNext(nodoprev);
    nodoprev->setPrev(this->tail);
    this->tail = nodoprev;
  }
  T TopBack() {
    if (!this->tail) {
      throw std::runtime_error("está vacia");
    }
    return this->tail->getData();
  }
  void PopBack() {
    if (!this->tail) {
      throw std::runtime_error("está vacia");
    }
    this->tail = this->tail->getPrev();
    if (!this->tail) {
      this->head = NULL;
      return;
    }
    this->tail->setNext(NULL);
  }
  NodoPrev<T> *Find(T dato) {
    NodoPrev<T> *recorrer = this->head;
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
      this->PopFront();
      return;
    }
    NodoPrev<T> *recorrer = this->head;
    while (recorrer->getNext()) {
      if (recorrer->getNext()->getData() == dato) {
        if (recorrer->getNext() == this->tail) {
          recorrer->setNext(NULL);
          this->tail = recorrer;
          return;
        }
        recorrer->getNext()->getNext()->setPrev(recorrer);
        recorrer->setNext(recorrer->getNext()->getNext());
        return;
      }
      recorrer = recorrer->getNext();
    }
    throw std::runtime_error("no se encontro el dato");
  }
  bool Empty() {
    if (!this->head) {
      return true;
    }
    return false;
  }
  void AddBefore(NodoPrev<T> *nodoprev, T dato) {
    NodoPrev<T> *data = new NodoPrev<T>(dato);
    if (nodoprev == this->head) {
      this->head = data;
    } else {
      nodoprev->getPrev()->setNext(data);
    }
    data->setPrev(nodoprev->getPrev());
    nodoprev->setPrev(data);
    data->setNext(nodoprev);
  }
  void AddAfter(NodoPrev<T> *nodoprev, T dato) {
    NodoPrev<T> *data = new NodoPrev<T>(dato);
    if (nodoprev == this->tail) {
      this->tail = data;
    } else {
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
    if (this->tail) {
      NodoPrev<T> *recorrer = this->tail;
      while (recorrer) {
        std::cout << recorrer->getData() << " ";
        recorrer = recorrer->getPrev();
      }
    }
    std::cout << '\n';
  }
};