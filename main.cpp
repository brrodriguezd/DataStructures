#include "arboles.h"
#include "listas.h"

int main() {
  MaxHeap<int> heap(12);
  heap.Insert(4);
  heap.Display();
  heap.Insert(7);
  heap.Insert(42);
  heap.Insert(38);
  heap.Insert(29);
  heap.Insert(18);
  heap.Insert(35);
  heap.Insert(12);
  heap.Insert(3);
  heap.Display();
  auto dato = heap.ExtractMax();
  heap.Remove(3);
  heap.Remove(2);
  std::cout<<dato<<'\n';
  heap.Display();
  heap.HeapSort();
  heap.Display();
  return 0;
}
/*
      7
    7   7
  7  7  7  7
4

*/