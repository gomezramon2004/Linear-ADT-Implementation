#include "./linkedList/linkedList.cpp"
#include <iostream>
#include <string>

int main() {
    LinkedList<std::string> list;
    list.insertAtEnd("Hello");
    list.insertAtEnd("World");
    list.insertAtEnd("!");
    std::cout << "Size: " << list.getSize() << std::endl;
    Node<std::string>* curr = list.getHead();
    while (curr != nullptr) {
        std::cout << curr->getData() << std::endl;
        curr = curr->getNext();
    }

    return 0;
}