#ifndef TTree_H
#define TTree_H

#include <iostream>

#include "rhombus.h"
#include "TreeItem.h"

typedef double Item;

class TTree {
public:
	TTree();
	TTree(const TTree& orig);

	void node_add(TTree* tree, size_t parent, Rhombus &&rhombus);
	bool empty();
	TTreeItem* node_find(TTreeItem* node, size_t square);
	void TTree_draw(TTreeItem* TTree, size_t num);
	void remove(size_t square);
	void neednull(TTreeItem* tree);
	void Draw(TTree* tree, size_t num);
	void node_remove(TTreeItem* TTree, Item square);
	virtual ~TTree();
private:
	TTreeItem *head;

};
#endif /* TTree_H */