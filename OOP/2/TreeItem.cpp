#include <iostream>
#include "TreeItem.h"
#include "rhombus.h"

TTreeItem::TTreeItem(Rhombus& rhombus) {
	this->rhombus = rhombus;
	this->brother = nullptr;
	this->son = nullptr;
}

TTreeItem::TTreeItem() {
	this->brother = nullptr;
	this->son = nullptr;
;
}


void TTreeItem::SetSon(TTreeItem *son) {
	this->son = son;
}

void TTreeItem::SetBrother(TTreeItem* brother) {
	this->brother = brother;
}

size_t TTreeItem::Square() {
	return rhombus.Square();
}

Rhombus TTreeItem::GetRhombus() const {
	return this->rhombus;
}

TTreeItem* TTreeItem::GetSon() {
	return this->son;
}

TTreeItem* TTreeItem::GetBrother() {
	return this->brother;
}
TTreeItem::~TTreeItem() {
	delete brother;
	delete son;
}