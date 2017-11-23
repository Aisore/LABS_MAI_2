#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <memory>
#include "BTreeItem.h"

template <class T>
class BTree
{
public:
	BTree();
	virtual ~BTree();

	void insert_BTree(const T &item);
	void delete_node();
	T &Top();
	bool IsEmpty() const;
	uint32_t GetSize() const;

	template <class A> friend std::ostream& operator<<(std::ostream &os, const BTree<A> &btree);
private:
	BTreeItem<T> *head;
	uint32_t count;
};

#endif
