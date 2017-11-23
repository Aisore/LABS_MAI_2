#include <iostream>
#include <string>
#include "TNTreeItem.h"

template <class T>
TNTreeItem<T>::TNTreeItem() {
    this->brother = nullptr;
    this->son = nullptr;
    this->id = "";
}

template <class T>
TNTreeItem<T>::TNTreeItem(std::string id, const std::shared_ptr<T> &figure) {
    this->figure = figure;
    this->brother = nullptr;
    this->son = nullptr;
    this->id = id;
}
template <class T>
void TNTreeItem<T>::SetSon(std::shared_ptr<TNTreeItem<T>> son) {
    this->son = son;
}
template <class T>
void TNTreeItem<T>::SetBrother(std::shared_ptr<TNTreeItem<T>> brother) {
    this->brother = brother;
}
template <class T>
std::shared_ptr<T> TNTreeItem<T>::GetFigure() const {
    return this->figure;
}
template <class T>
std::shared_ptr<TNTreeItem<T>> TNTreeItem<T>::GetSon() {
    return this->son;
}
template <class T>
std::shared_ptr<TNTreeItem<T>> TNTreeItem<T>::GetBrother() {
    return this->brother;
}
template <class T>
std::string TNTreeItem<T>::getId() {
    return this->id;
}
template <class T>
std::ostream& operator<<(std::ostream& os, const TNTreeItem<T>& obj) {
    os << obj.figure << std::endl;
    return os;
}

template <class T> Allocator TNTreeItem<T>::allocator{};

template <class T>
void *TNTreeItem<T>::operator new(size_t size) {
	return allocator.Alloc(size);
}
template <class T>
void TNTreeItem<T>::operator delete(void *p) {
	allocator.Free(p);
}

template <class T>
TNTreeItem<T>::~TNTreeItem() {
}

#include "figure.h"
template class TNTreeItem<Figure>;
template std::ostream& operator<<(std::ostream &out, const TNTreeItem<Figure> &obj);