#ifndef TNTREE_H
#define TNTREE_H

#include <string>
#include <memory>
#include "TIterator.h"
#include "TNTreeItem.h"
#include "Hexagon.h"
#include "Rhombus.h"
#include "Pentagon.h"

template <class T>
class TNTree {
public:
    TNTree();
    TNTree(const TNTree<T>& orig);
	template <class A> friend std::ostream& operator<<(std::ostream& os, const TNTree<A>& tree);

	TIterator<TNTreeItem<T>, T> begin();
	TIterator<TNTreeItem<T>, T> end();

    void Insert(std::string parent_id, std::string id, std::shared_ptr<T> &figure);
    void Remove(std::string id);
    void PrintTree();
    void PrintItem(std::string id);
    void SetNull(std::shared_ptr<TNTreeItem<T>> treeItem);
    std::shared_ptr<TNTreeItem<T>> getHead();
    bool IsEmpty() const;
	std::shared_ptr<TNTreeItem<T>> head;
    virtual ~TNTree();
private:

    std::shared_ptr<TNTreeItem<T>> FindNode(std::shared_ptr<TNTreeItem<T>> node, std::string id);
    void print_nodes(std::shared_ptr<TNTreeItem<T>> treeItem, size_t num);
    void node_remove(std::shared_ptr<TNTreeItem<T>> treeItem, std::string id);
};
#endif /* TNTREE_H */
