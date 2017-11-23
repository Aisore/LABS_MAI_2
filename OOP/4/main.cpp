#include <iostream>
#include <cstring>
#include <memory>
#include <cstdlib>
#include "TNTree.h"
//#include "Trapezium.h"

int main(int argc, char** argv)
{
    TNTree<Figure> *tree = new TNTree<Figure>();
    std::string action;

    std::cout << "Type 'h' or 'help' to get help." << std::endl;
    while (1) {
        std::cin.clear();
        std::cin.sync();
        std::cout << "> ";
        std::cin >> action;
       
        if (action == "q" || action == "quit") {
            break;
        } else if (action == "ih" || action == "insert hexagon") {
            std::shared_ptr<Figure> fig;
            std::string parent_id, id;

            std::cout << "Enter parent id: ";
            std::cin >> parent_id;
            std::cout << "Enter node id: ";
            std::cin >> id;
            
            fig = std::make_shared<Hexagon>(std::cin);
            tree->Insert(parent_id, id, fig);
        } else if (action == "ir" || action == "insert rhombus") {
            std::shared_ptr<Figure> fig;
            std::string parent_id, id;

            std::cout << "Enter parent id: ";
            std::cin >> parent_id;
            std::cout << "Enter node id: ";
            std::cin >> id;
            
            fig = std::make_shared<Rhombus>(std::cin);
            tree->Insert(parent_id, id, fig);
        } else if (action == "ip" || action == "insert pentagon") {
            std::shared_ptr<Figure> fig;
            std::string parent_id, id;

            std::cout << "Enter parent id: ";
            std::cin >> parent_id;
            std::cout << "Enter node id: ";
            std::cin >> id;
            
            fig = std::make_shared<Pentagon>(std::cin);
            tree->Insert(parent_id, id, fig);
        } else if (action == "r" || action == "Remove") {
            std::string id;
            if (!(std::cin >> id)) {
                std::cout << "Incorrect value." << std::endl;
                continue;
            }
			if (tree->head->getId() == id) {
				delete tree;
				tree = new TNTree<Figure>();
			} else {
				tree->Remove(id);
			}
		} else if (action == "d" || action == "destroy") {
            delete tree;
            tree = new TNTree<Figure>();
            std::cout << "The tree was deleted." << std::endl;
        } else if (action == "p" || action == "print") {
            if (!tree->IsEmpty()) {
            tree->PrintTree();
            }
            else {
                std::cout << "The tree is empty." << std::endl;
            }
        } else if (action == "pi" || action == "printitem") {
            std::string id;
            std::cout << "Enter item id: ";
            std::cin >> id;

            tree->PrintItem(id);
        } else if (action == "help" || action == "h") {
            std::cout << "'h'  or 'help'      - display the help." << std::endl;
            std::cout << "'r'  or 'Remove'    - Remove the figure with area s." << std::endl;
            std::cout << "'d'  or 'destroy'   - delete the tree." << std::endl;
            std::cout << "'p'  or 'print'     - output the tree." << std::endl;
            std::cout << "'ih'                - insert a hexagon into the tree." << std::endl;
            std::cout << "'ir'                - insert a rhombus into the tree." << std::endl;
            std::cout << "'ip'                - insert a pentagon into the tree." << std::endl;
            std::cout << "'pi' or 'printitem' - print item by id." << std::endl;
            std::cout << "'q'  or 'quit'      - exit the program." << std::endl;
        }
    }
    
    return 0;
}

