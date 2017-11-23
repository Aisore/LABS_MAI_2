#include "tree.h"
#include "TreeItem.h"

TTree::TTree() {
	head = nullptr;
}

TTree::TTree(const TTree& orig) {
	head = orig.head;
}

void TTree::node_add(TTree* tree, size_t parent, Rhombus &&rhombus) {
	if (parent == 0) {
		TTreeItem *other = new TTreeItem(rhombus);
		other->SetSon(head);
		head = other;
		neednull(head->GetSon());
		neednull(head->GetBrother());
		return;
	}
	if (tree->head) {
		TTreeItem *parent_node = node_find(tree->head, parent);
		if (parent_node) {
			if (parent_node->GetSon() == nullptr) {
				parent_node->SetSon(new TTreeItem(rhombus));
			}
			else {
				TTreeItem *brother = parent_node->GetSon();
				while (brother->GetBrother()) {
					brother = brother->GetBrother();
				}
				brother->SetBrother(new TTreeItem(rhombus));
			}
		}
		else {
			printf("Error: you can't add node\n");
		}
	}
}

TTreeItem* TTree::node_find(TTreeItem* tree, size_t square) {
	TTreeItem *tr = nullptr;
	if (tree->Square() == square) {
		return tree;
	}
	if (tree->GetSon()) {
		tr = node_find(tree->GetSon(), square);
		if (tr != nullptr) {
			return tr;
		}
	}
	if (tree->GetBrother()) {
		tr = node_find(tree->GetBrother(), square);
		if (tr != nullptr) {
			return tr;
		}
	}
	return nullptr;
}

bool TTree::empty() {
	return head == nullptr;
}

void TTree::node_remove(TTreeItem* tree, Item square) {
	if (tree->son) {
		if (tree->son->Square() == square) {
			TTreeItem *tr = tree->son;
			tree->SetSon(tree->son->brother);
			tr->brother = nullptr;
			delete tr;
			return;
		}
		else {
			node_remove(tree->son, square);
		}
	}
	if (tree->brother) {
		if (tree->brother->Square() == square) {
			TTreeItem *tr = tree->brother;
			tree->SetBrother(tree->brother->brother);
			tr->brother = nullptr;
			delete tr;
			return;
		}
		else {
			node_remove(tree->brother, square);
		}
	}
}

void TTree::neednull(TTreeItem* tree) {
	tree = nullptr;
}

void TTree::remove(size_t a)
{
	if (head->Square() == a) {
		delete head;
		head = nullptr;
	} else {
		TTree::node_remove(head, a);
	}
}

void TTree::Draw(TTree* tree, size_t num) {
	TTree::TTree_draw(head,num);
}

void TTree::TTree_draw(TTreeItem* TTree, size_t num) {
	if (TTree) {
		for (int i = 0; i < num; i++) {
			printf("\t");
		}
		TTree->GetRhombus().Print();
		if (TTree->GetSon()) {
			TTree_draw(TTree->GetSon(), num + 1);
		}
		if (TTree->GetBrother()) {
			TTree_draw(TTree->GetBrother(), num);
		}
	}
}

TTree::~TTree() {
	delete head;
}