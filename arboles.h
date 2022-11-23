#pragma once
#include "arboles/AVL.h"
#include "arboles/BST.h"
#include "arboles/MaxHeap.h"
#include "arboles/MinHeap.h"
#include "arboles/Tree.h"

/***
Tree<T>
    int     height
    int     size
    void    inOrderTraversal
    void    preOrderTraversal
    void    postOrderTraversal
    void    levelTraversal

BST<T>: Tree<T>
    Nodo<T> *Find(T)
    Nodo<T> *Next(Nodo<T> *)
    Nodo<T> *Prev(Nodo<T> *)
    LinkedListTail<Nodo<T> *> RangeSearch(int, int)
    void    Insert(T)
    void    Delete(Nodo<T> *)
    void    RotateLeft
    void    RotateRight

AVL<T>: BST<T>
    void    Insert(T)
    void    Delete(Nodo<T> *)
    void    Rebalance

MaxHeap - MinHeap
    bool    Empty()
    void    HeapSort
    void    Insert(T)
    void    Remove(T)
    void    ChangePriority()
    void    Display()
    T       ExtractMax - ExtractMin
***/
