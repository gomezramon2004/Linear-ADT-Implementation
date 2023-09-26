#include "./linkedList/linkedList.cpp"
#include <iostream>
#include <string>

int main() {
    LinkedList<std::string> list;
    list.create("Hello");
    list.create("World");
    list.create("!");

    std::cout << list.read("World") << std::endl;
    
    std::cout << "Size: " << list.getSize() << std::endl;
    Node<std::string>* curr = list.getHead();
    while (curr != nullptr) {
        std::cout << curr->getData() << std::endl;
        curr = curr->getNext();
    }

    return 0;
}