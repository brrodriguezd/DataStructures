#include "../nodos.h"

template <class T> class LinkedListTail {
private:
  NodoNext<T> *head;
  NodoNext<T> *tail;

public:
  LinkedListTail() {
    this->head = NULL;
    this->tail = NULL;
  }
  void PushFront(T dato) {
    NodoNext<T> *nodonext = new NodoNext<T>(dato);
    nodonext->setNext(this->head);
    this->head = nodonext;
    if (!this->tail) {
      this->tail = this->head;
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
    if (!this->head) {
      this->tail = NULL;
    }
  }
  void PushBack(T dato) {
    NodoNext<T> *nodonext = new NodoNext<T>(dato);
    if (!this->head) {
      this->head = this->tail = nodonext;
      return;
    }
    this->tail->setNext(nodonext);
    this->tail = nodonext;
  }
  T TopBack() {
    if (!this->tail) {
      throw std::runtime_error("está vacio");
    }
    return this->tail->getData();
  }
  void PopBack() {
    if (!this->head) {
      throw std::runtime_error("está vacio");
    }
    if (this->tail == this->head) {
      this->tail = this->head = NULL;
      return;
    }
    NodoNext<T> *recorrer = this->head;
    while (recorrer->getNext()->getNext()) {
      recorrer = recorrer->getNext();
    }
    recorrer->setNext(NULL);
    this->tail = recorrer;
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
    NodoNext<T> *recorrer = this->head;
    if (this->head->getData() == dato) {
      this->PopFront();
      return;
    }
    while (recorrer->getNext()) {
      if (recorrer->getNext()->getData() == dato) {
        if (recorrer->getNext() == this->tail) {
          recorrer->setNext(NULL);
          this->tail = recorrer;
          return;
        }
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
    if (this->tail == nodonext) {
      this->tail = data;
    }
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
    LinkedListTail<T> listainv;
    NodoNext<T> *recorrer = this->head;
    while (recorrer) {
      listainv.PushFront(recorrer->getData());
      recorrer = recorrer->getNext();
    }
    listainv.Display();
  }
};