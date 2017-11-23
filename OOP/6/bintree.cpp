#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"

template <class T>
BTree<T>::BTree() {
	head = nullptr;
	count = 0;
}

template <class T>
void BTree<T>::insert_BTree(const T &item)
{
    BTreeItem<T> *tmp = new BTreeItem<T>(item,head);
	head = tmp;
	++count;
}

template <class T>
void BTree<T>::delete_node()
{
	if (head) {
		BTreeItem<T> *tmp = &head->GetNext();
		delete head;
		head = tmp;
		count--;
	}
}

template <class T>
bool BTree<T>::IsEmpty() const
{
	return !count;
}

template <class T>
uint32_t BTree<T>::GetSize() const
{
	return count;
}

template <class T>
T &BTree<T>::Top()
{
	return head->Pop();
}


template <class T>
BTree<T>::~BTree()
{
	for (BTreeItem<T> *tmp = head, *tmp2; tmp; tmp = tmp2) {
		tmp2 = &tmp->GetNext();
		delete tmp;
	}
}

typedef unsigned char Byte;

template class
BTree<void *>;