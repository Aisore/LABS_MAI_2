#ifndef BTREEITEM_H
#define BTREEITEM_H

#include <string>
#include <iostream>
#include <memory>

template <class T>
class BTreeItem {
public:
	BTreeItem(const T &val, BTreeItem<T> *item);
	void Push(const T &val);
	T &Pop() const;
	void SetNext(BTreeItem<T> *item);
	BTreeItem<T> &GetNext() const;
	virtual ~BTreeItem();
private:
	T *figure;
	BTreeItem<T> *left;
	BTreeItem<T> *right;
};

#endif  /* BTREEITEM_H */