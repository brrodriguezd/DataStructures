#include "../arboles.h"
#include <vector>

template <class T> class Sort {
public:
  void MinHeapSort(std::vector<T> arr) {
    auto heap = new MinHeap<T>(arr.size());
    for (int i = 0; i < arr.size(); i++) {
      heap.Insert(arr[i]);
    }
    for (int i = 0; i < arr.max_size(); i++) {
      arr[i] = heap.ExtractMin();
    }
  }
  void MaxHeapSort(std::vector<T> arr) {
    auto heap = new MaxHeap<T>(arr.size());
    for (int i = 0; i < arr.size(); i++) {
      heap.Insert(arr[i]);
    }
    for (int i = 0; i < arr.max_size(); i++) {
      arr[i] = heap.ExtractMax();
    }
  }
  void MinParcialSorting(std::vector<T> arr, int k) {
    auto heap = new MinHeap<T>(arr);
    for (int i = 0; i < k; i++) {
      heap.ExtractMin();
    }
  }
  void MaxParcialSorting(std::vector<T> arr, int k) {
    auto heap = new MaxHeap<T>(arr);
    for (int i = 0; i < k; i++) {
      heap.ExtractMax();
    }
  }
};