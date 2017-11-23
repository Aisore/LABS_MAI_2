#include <iostream>
#include <memory>
#include "BTreeItem.h"

template <class T>
BTreeItem<T>::BTreeItem(const T &val, BTreeItem<T> *item) {
	figure = new T(val);
	left = item;
	right = nullptr;
}

template <class T>
void BTreeItem<T>::Push(const T &val) {
	*figure = val;
}

template <class T>
T &BTreeItem<T>::Pop() const
{
	return *figure;
}

template <class T>
void BTreeItem<T>::SetNext(BTreeItem<T> *item)
{
	left = item;
}

template <class T>
BTreeItem<T> &BTreeItem<T>::GetNext() const
{
	return *left;
}


template <class T>
BTreeItem<T>::~BTreeItem() {
	delete figure;
}

typedef unsigned char Byte;

template class
BTreeItem<void *>;