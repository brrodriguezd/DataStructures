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
NO ORDENADAS:

LinkedListTail<T>
LinkedList<T>
DoublyLinkedListTail<T>
DoublyLinkedList<T>

PushFront(T)
T TopFront()
PopFront()
PushBack(T)
T TopBack()
PopBack()
Node* Find(T)
Erase(T)
bool Empty()
AddBefore(Node*, T)
AddAfter(Node*, T)
Display()
DisplayBackwards()

ORDENADAS:

LinkedListTail_O<T>
LinkedList_O<T>
DoublyLinkedListTail_O<T>
DoublyLinkedList_O<T>

Insert(T)
PopFront()
PopBack()
Delete(T)
T TopFront()
T TopBack()
Node* Find(T)
bool Empty()
Display()
DisplayBackwards() ## Solo en las dobles
        ***/