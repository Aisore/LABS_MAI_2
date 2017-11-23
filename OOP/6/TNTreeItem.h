#ifndef TNTREEITEM_H
#define TNTREEITEM_H

#include <string>
#include <memory>

#include "allocator.h"


template <class T>
class TNTreeItem {
public:
    TNTreeItem();
    TNTreeItem(std::string id, const std::shared_ptr<T> &figure);
	template <class A> friend std::ostream& operator<<(std::ostream& os, const TNTreeItem<A>& obj);
    
    void SetSon(std::shared_ptr<TNTreeItem<T>> son);
    void SetBrother(std::shared_ptr<TNTreeItem<T>> brother);
    std::shared_ptr<TNTreeItem<T>> GetSon();
    std::shared_ptr<TNTreeItem<T>> GetBrother();
    std::shared_ptr<T> GetFigure() const;
    std::string getId();
    
	void *operator new(size_t size);
	void operator delete(void *ptr);

    virtual ~TNTreeItem();
private:
    std::string id;
    std::shared_ptr<T> figure;

    std::shared_ptr<TNTreeItem<T>> son;
    std::shared_ptr<TNTreeItem<T>> brother;

	static Allocator allocator;
};

#endif  /* TNTREEITEM_H */
