#include "./linkedList/linkedList.cpp"
#include <iostream>
#include <string>

int main() {
    try {
       LinkedList<std::string> list;
       list.create("Hello");
       list.del("!");
      
       std::cout << "Size: " << list.getSize() << std::endl;
       Node<std::string>* curr = list.getHead();
       while (curr) {
           std::cout << curr->getData() << std::endl;
           curr = curr->getNext();
       }
   } catch (const std::runtime_error& e) {
       std::cerr << e.what() << std::endl;
   }
   return 0;
}