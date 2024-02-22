//use crate::min_heap::MinHeap;
pub mod linkedlist;
pub mod min_heap;

fn main() {
    let mut heap = min_heap::MinHeap::<i32>::new(12);
    if heap.clone().empty() {
        println!("vacio");
    }
    heap.insert(4);
    heap.display();
    heap.insert(7);
    heap.insert(42);
    heap.insert(38);
    heap.insert(29);
    heap.insert(18);
    heap.insert(35);
    heap.insert(12);
    heap.insert(3);
    heap.display();
    let dato = heap.extract_min();
    heap.remove(3);
    heap.remove(2);
    println!("dato: {}", dato);
    heap.display();
    heap.change_priority(2, 30);
    heap.display();
    println!("LISTA: ");
    let mut list = linkedlist::LinkedList::<i32>::new();
    list.push_front(2);
    list.push_front(7);
    list.display();
    println!("7:{:?}", list.pop_front());
    //    list.display();
    list.push_front(5);
    list.push_back(6);
    list.push_front(3);
    list.display();
    println!("6:{:?}", list.pop_back());
    println!("3:{:?}", list.pop_front());
    list.display();
}
