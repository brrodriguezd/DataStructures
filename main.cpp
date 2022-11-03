#include "listasordenadas.h"

int main() {
  
  DoublyLinkedListTail_O<> lista = DoublyLinkedListTail_O<>();
  lista.Insert(3);
  lista.Insert(2);
  lista.Insert(1);
  lista.Insert(4);
  lista.Insert(6);
  lista.Insert(7);
  lista.Display();
  lista.DisplayBackwards();
  std::cout<<lista.TopBack()<<'\n';
  lista.PopBack();
  lista.Display();
  lista.DisplayBackwards();
  lista.PopFront();
  lista.Insert(5);
  lista.Display();
  lista.DisplayBackwards();
  std::cout<<lista.TopBack()<<'\n';
  lista.PopBack();
  return 0;
}