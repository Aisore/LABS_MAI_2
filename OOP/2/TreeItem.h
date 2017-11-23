
#ifndef TTreeITEM_H
#define	TTreeITEM_H

#include "rhombus.h"

class TTree;

class TTreeItem {
public:
	TTreeItem *son;
	TTreeItem *brother;

	TTreeItem(Rhombus& rhombus);
	TTreeItem();
	size_t Square();
	void SetSon(TTreeItem* son);
	void SetBrother(TTreeItem* brother);
	TTreeItem* GetSon();
	TTreeItem* GetBrother();
	Rhombus GetRhombus() const;
	
	virtual ~TTreeItem();
private:
	Rhombus rhombus;
};

#endif	/* TSTACKITEM_H */
