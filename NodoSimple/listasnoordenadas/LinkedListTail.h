#include "../Nodo.h"

template <class T> class LinkedListTail {
private:
  Nodo<T> *head;
  Nodo<T> *tail;

public:
  LinkedListTail() {
    this->head = NULL;
    this->tail = NULL;
  }
  void PushFront(T dato) {
    Nodo<T> *nodo = new Nodo<T>(dato);
    nodo->setNext(this->head);
    this->head = nodo;
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
    Nodo<T> *nodo = new Nodo<T>(dato);
    if (!this->head) {
      this->head = this->tail = nodo;
      return;
    }
    this->tail->setNext(nodo);
    this->tail = nodo;
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
    Nodo<T> *recorrer = this->head;
    while (recorrer->getNext()->getNext()) {
      recorrer = recorrer->getNext();
    }
    recorrer->setNext(NULL);
    this->tail = recorrer;
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
    Nodo<T> *recorrer = this->head;
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
    if (this->tail == nodo) {
      this->tail = data;
    }
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
  void DisplayBackwards() {
    LinkedListTail<T> listainv;
    Nodo<T> *recorrer = this->head;
    while (recorrer) {
      listainv.PushFront(recorrer->getData());
      recorrer = recorrer->getNext();
    }
    listainv.Display();
  }
};