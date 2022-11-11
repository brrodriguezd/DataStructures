#include <iostream>
#include <limits>
#include <vector>

template <class T> class MinHeap {
private:
  int maxSize;
  int size;
  std::vector<T> heap;

public:
  MinHeap(int size) {
    this->maxSize = size;
    this->size = 0;
    this->heap.resize(size);
  }
  int parent(int index) { return index / 2; }
  int leftChild(int index) { return index * 2; }
  int rightChild(int index) { return index * 2 + 1; }
  void SiftUp(int index) {
    while (index > 1 &&
           (this->heap[parent(index) - 1] > this->heap[index - 1])) {
      T temp = this->heap[index - 1];
      this->heap[index - 1] = this->heap[parent(index) - 1];
      this->heap[parent(index)-1] = temp;
      index = parent(index);
    }
  }
  void SiftDown(int index) {
    auto maxIndex = index;
    auto left = leftChild(index);
    if (left <= this->size && this->heap[left-1] < this->heap[maxIndex-1]) {
      maxIndex = left;
    }
    auto right = rightChild(index);
    if (right <= this->size && this->heap[right-1] < this->heap[maxIndex-1]) {
      maxIndex = right;
    }
    if (index != maxIndex) {
      auto temp = this->heap[index-1];
      this->heap[index-1] = this->heap[maxIndex-1];
      this->heap[maxIndex-1] = temp;
      SiftDown(maxIndex);
    }
  }
  void Insert(T dato) {
    if (this->size == this->maxSize) {
      throw std::runtime_error("Lleno");
    }
    this->heap[this->size] = dato;
    this->size += 1;
    SiftUp(this->size);
  }
  T ExtractMin() {
    auto result = this->heap[0];
    this->heap[0] = this->heap[this->size - 1];
    this->size -= 1;
    SiftDown(1);
    return result;
  }
  void Remove(int index) {
    this->heap[index-1] = std::numeric_limits<T>::min();
    SiftUp(index);
    ExtractMin();
  }
  void ChagePriotiry(int index, T dato) {
    auto oldp = this->heap[index-1];
    this->heap[index-1] = dato;
    if (dato < oldp) {
      SiftUp(index);
    } else {
      SiftDown(index);
    }
  }
  void Display() {
    for (int i = 0; i < this->size; i++) {
      std::cout << this->heap[i] << " ";
    }
    std::cout << '\n';
  }
};