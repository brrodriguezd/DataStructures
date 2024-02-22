use num::traits::Bounded;
use std::cmp::PartialOrd;
use std::fmt::Debug;

#[derive(Clone)]
pub struct MinHeap<T>
where
    T: Copy + PartialOrd + Bounded + Debug,
{
    max_size: usize,
    size: usize,
    heap: Vec<T>,
}
impl<T> MinHeap<T>
where
    T: Copy + PartialOrd + Bounded + Debug,
{
    fn parent(index: usize) -> usize {
        index / 2
    }
    fn left_child(index: usize) -> usize {
        index * 2
    }
    fn right_child(index: usize) -> usize {
        index * 2 + 1
    }
    fn sift_up(&mut self, mut index: usize) {
        while index > 1 && self.heap[Self::parent(index) - 1] > self.heap[index - 1] {
            self.heap.swap(index - 1, Self::parent(index) - 1);
            index = Self::parent(index);
        }
    }
    fn sift_down(&mut self, index: usize) {
        let mut max_index = index;
        let left = Self::left_child(index);
        if left <= self.size && self.heap[left - 1] < self.heap[max_index - 1] {
            max_index = left;
        }
        let right = Self::right_child(index);
        if right <= self.size && self.heap[right - 1] < self.heap[max_index - 1] {
            max_index = right;
        }
        if index != max_index {
            self.heap.swap(index - 1, max_index - 1);
            self.sift_down(max_index);
        }
    }
}

impl<T> MinHeap<T>
where
    T: Copy + PartialOrd + Bounded + Debug,
{
    pub fn new(size: usize) -> Self {
        let mut vec: Vec<T> = Vec::new();
        vec.reserve_exact(size);
        MinHeap {
            max_size: size,
            size: 0,
            heap: vec,
        }
    }
    pub fn empty(self) -> bool {
        self.size == 0
    }
    pub fn insert(&mut self, dato: T) {
        if self.size == self.max_size {
            panic!("Está lleno")
        }
        self.heap.push(dato);
        self.size += 1;
        self.sift_up(self.size)
    }
    pub fn extract_min(&mut self) -> T {
        let min = self.heap[0];
        self.heap[0] = self.heap[self.size - 1];
        self.size -= 1;
        self.sift_down(1);
        min
    }
    pub fn remove(&mut self, index: usize) {
        self.heap[index - 1] = T::min_value();
        self.sift_up(index);
        self.extract_min();
    }
    pub fn change_priority(&mut self, index: usize, dato: T) {
        let oldt = self.heap[index - 1];
        self.heap[index - 1] = dato;
        if dato < oldt {
            self.sift_up(index)
        } else {
            self.sift_down(index)
        }
    }
    pub fn display(&self) {
        for idx in 0..self.size {
            print!("{:?} ", self.heap[idx]);
            if idx == 0 || idx == 2 || idx == 6 || idx == 14 {
                println!();
            }
        }
        println!()
    }
}
