#ifndef TNTREEITEM_H
#define TNTREEITEM_H

#include <string>
#include <memory>

#include "Hexagon.h"
#include "Rhombus.h"
#include "Pentagon.h"

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
    
    virtual ~TNTreeItem();
private:
    std::string id;
    std::shared_ptr<T> figure;

    std::shared_ptr<TNTreeItem<T>> son;
    std::shared_ptr<TNTreeItem<T>> brother;
};

#endif  /* TNTREEITEM_H */
