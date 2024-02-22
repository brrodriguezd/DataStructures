use std::{fmt::Debug, ptr::NonNull};

struct Node<T>
where
    T: Copy + Clone + Debug,
{
    data: T,
    next: Option<NonNull<Node<T>>>,
}
#[derive(Clone, Copy)]
pub(crate) struct LinkedList<T>
where
    T: Copy + Clone + Debug,
{
    head: Option<NonNull<Node<T>>>,
    tail: Option<NonNull<Node<T>>>,
}

impl<T> Node<T>
where
    T: Copy + Clone + Debug,
{
    fn new(data: T, next: Option<NonNull<Node<T>>>) -> Self {
        Node { data, next }
    }
}
impl<T> LinkedList<T>
where
    T: Copy + Clone + Debug,
{
    pub fn new() -> Self {
        LinkedList {
            head: None,
            tail: None,
        }
    }
    pub fn push_front(&mut self, data: T) {
        //lifetime
        let new_node = Box::new(Node::new(data, self.head.clone()));
        let new_node_ptr = Some(NonNull::from(Box::leak(new_node)));
        self.head = new_node_ptr;
        if self.tail.is_none() {
            self.tail = self.head
        }
    }
    pub fn push_back(&mut self, data: T) {
        //lifetime
        let new_node = Box::new(Node::new(data, self.head.clone()));
        let new_node_ptr = Some(NonNull::from(Box::leak(new_node)));
        if self.tail.is_none() {
            self.head = new_node_ptr;
            self.tail = new_node_ptr;
        }
        unsafe { self.tail.unwrap().as_mut().next = new_node_ptr };
        self.tail = new_node_ptr;
    }
    pub fn pop_front(&mut self) -> T {
        let node = self.head.expect("la lista está vacia").as_ptr();
        if self.tail == self.head {
            self.tail = None;
        }
        unsafe {
            self.head = (*node).next;
            (*node).data
        }
    }
    pub fn pop_back(&mut self) -> T {
        let mut node = self.head.expect("la lista está vacia").as_ptr();
        let data: T;
        if self.head == self.tail {
            self.head = None;
            self.tail = None;
            unsafe {
                return (*node).data;
            }
        }
        unsafe {
            'iter: loop {
                if (*node).next == self.tail {
                    data = (*(*node).next.unwrap().as_ptr()).data;
                    (*node).next = None;
                    self.tail = Some(NonNull::from(&(*node)));
                    break 'iter;
                }
                node = (*node).next.unwrap().as_ptr();
            }
        }
        data
    }
    pub fn display(&self) {
        let mut node = self.head.expect("la lista está vacia").as_ptr();
        unsafe {
            'iter: loop {
                print!("{:?}", (*node).data);
                if node == self.tail.unwrap().as_ptr() {
                    break 'iter;
                }
                node = (*node).next.unwrap().as_ptr();
            }
        }
        println!();
    }
}
