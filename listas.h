#pragma once
#include "listas/DoublyLinkedList.h"
#include "listas/DoublyLinkedListTail.h"
#include "listas/DoublyLinkedListTail_O.h"
#include "listas/DoublyLinkedList_O.h"
#include "listas/LinkedList.h"
#include "listas/LinkedListTail.h"
#include "listas/LinkedListTail_O.h"
#include "listas/LinkedList_O.h"
/***
NO-ORDENADAS:

LinkedListTail<T>
LinkedList<T>
DoublyLinkedListTail<T>
DoublyLinkedList<T>

void    PushFront(T)
T       TopFront()
void    PopFront()
void    PushBack(T)
T       TopBack()
void    PopBack()
Node*   Find(T)
void    Erase(T)
bool    Empty()
void    AddBefore(Node*, T)
void    AddAfter(Node*, T)
void    Display()
void    DisplayBackwards()

ORDENADAS:

LinkedListTail_O<T>
LinkedList_O<T>
DoublyLinkedListTail_O<T>
DoublyLinkedList_O<T>

void    Insert(T)
void    PopFront()
void    PopBack()
void    Delete(T)
T       TopFront()
T       TopBack()
Node*   Find(T)
bool    Empty()
void    Display()
void    DisplayBackwards() ## Solo en las dobles

***/