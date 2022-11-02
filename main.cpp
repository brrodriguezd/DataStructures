#include "listasnoordenadas.h"

int main() {
  DoublyLinkedList<int> lista;
  Nodo<int> *nodo;
  lista.PushFront(3);
  lista.PushFront(2);
  lista.PushFront(1);
  lista.PushBack(4);
  lista.PushBack(6);
  lista.PushBack(7);
  lista.DisplayBackwards();
  lista.Display();
  lista.PopBack();
  lista.PopFront();
  std::cout << lista.TopFront() << " ";
  std::cout << lista.TopBack() << '\n';
  nodo = lista.Find(6);
  lista.AddBefore(nodo, 5);
  lista.AddAfter(nodo, 7);
  std::cout << lista.TopBack() << '\n';
  nodo = lista.Find(lista.TopFront());
  lista.AddAfter(nodo, 1);
  lista.AddBefore(nodo, 0);
  lista.DisplayBackwards();
  lista.Display();
  std::cout << lista.TopFront() << " ";
  std::cout << lista.TopBack() << '\n';
  lista.Erase(3);
  lista.DisplayBackwards();
  lista.Display();
  lista.Erase(7);
  lista.DisplayBackwards();
  lista.Display();
  lista.Erase(0);
  lista.DisplayBackwards();
  lista.Display();
  std::cout << lista.TopFront() << " ";
  std::cout << lista.TopBack() << '\n';
  lista.PopBack();
  lista.PopBack();
  lista.PopBack();
  lista.PopBack();
  lista.PopFront();
  return 0;
}
/***
DoublyLinkedListNoTail<T> lista;
DoublyLinkedList<T> lista;
LinkedList<T> lista;
LinkedListNoTail<T>lista;
PushFront(T)
T TopFront()
PopFront()
PushBack(T)
T TopBack()
PopBack()
Node* Find(T)
Erase(T)
bool Empty()//
AddBefore(Node*, T)
AddAfter(Node*, T)
Display()
DisplayBackwards()
        ***/