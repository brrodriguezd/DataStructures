#include <iostream>
#include <limits>
#include <vector>

template <class T> class MaxHeap {
private:
  int maxSize;
  int size;
  std::vector<T> heap;

public:
  MaxHeap(int size) {
    this->maxSize = size;
    this->size = 0;
    this->heap.resize(size);
  }
  MaxHeap(std::vector<T> arr) {
    this->size = this->maxSize = arr.size();
    this->heap = arr;
    for (int i = (this->size + 1) / 2; i > 0; i--) {
      SiftDown(i);
    }
  }
  void HeapSort() {
    auto save = this->size;
    while(this->size > 1) {
      T temp = this->heap[0];
      this->heap[0] = this->heap[this->size - 1];
      this->heap[this->size - 1] = temp;
      this->size -= 1;
      SiftDown(1);
    }
    this->size=save;
  }
  int parent(int index) { return index / 2; }
  int leftChild(int index) { return index * 2; }
  int rightChild(int index) { return index * 2 + 1; }
  void SiftUp(int index) {
    while (index > 1 &&
           (this->heap[parent(index) - 1] < this->heap[index - 1])) {
      T temp = this->heap[index - 1];
      this->heap[index - 1] = this->heap[parent(index) - 1];
      this->heap[parent(index) - 1] = temp;
      index = parent(index);
    }
  }
  void SiftDown(int index) {
    auto maxIndex = index;
    auto left = leftChild(index);
    if (left <= this->size && this->heap[left - 1] > this->heap[maxIndex - 1]) {
      maxIndex = left;
    }
    auto right = rightChild(index);
    if (right <= this->size &&
        this->heap[right - 1] > this->heap[maxIndex - 1]) {
      maxIndex = right;
    }
    if (index != maxIndex) {
      auto temp = this->heap[index - 1];
      this->heap[index - 1] = this->heap[maxIndex - 1];
      this->heap[maxIndex - 1] = temp;
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
  T ExtractMax() {
    auto result = this->heap[0];
    this->heap[0] = this->heap[this->size - 1];
    this->size -= 1;
    SiftDown(1);
    return result;
  }
  void Remove(int index) {
    this->heap[index - 1] = std::numeric_limits<T>::max();
    SiftUp(index);
    ExtractMax();
  }
  void ChagePriotiry(int index, T dato) {
    auto oldp = this->heap[index - 1];
    this->heap[index - 1] = dato;
    if (dato > oldp) {
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
  void BuildHeap(std::vector<T> arr) {
    for (int i = 0; i < arr.size(); i++) {
      this->Insert(arr[i]);
    }
  }
};