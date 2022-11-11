#include "arboles.h"
#include "listas.h"

int main() {
  MaxHeap<int> heap(8);
  heap.Insert(4);
  heap.Display();
  heap.Insert(7);
  heap.Display();
  return 0;
}
/*
      5
  2       8
1   4   6   10
          7

    2
1       5
      4   8
        6   10
         7
1 2 4 5 6 7 8 10
5 2 1 4 8 6 7 10
1 4 2 7 6 10 8 5
5 2 8 1 4 6 10 7
*/