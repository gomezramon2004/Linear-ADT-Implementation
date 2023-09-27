#include "linkedList.hpp"

template <class T>
Node<T>::Node(T data): data(data), next(nullptr) {}

template <class T>
T Node<T>::getData() {
    return data;
}

template <class T>
Node<T>* Node<T>::getNext() {
    return next;
}

template <class T>
void Node<T>::setData(T data) {
    this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}

template <class T>
LinkedList<T>::LinkedList(): size(0), head(nullptr) {}

template <class T>
int LinkedList<T>::getSize() {
    return size;
}

template <class T>
Node<T>* LinkedList<T>::getHead() {
    return head;
}

template <class T>
void LinkedList<T>::create(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (!head) {                                // If list is empty
        head = newNode;     
    } else {                                    // If list is not empty
        Node<T>* curr = head;
        while (curr->getNext()) {
            curr = curr->getNext();
        }
        curr->setNext(newNode);
    }
    size++;
}

template <class T>
T LinkedList<T>::read(T data) {
    Node<T>* curr = head;
    while (curr) {
        if (curr->getData() == data) {          // If the node to be read is found
            return curr->getData();
        }
        curr = curr->getNext();
    }
    throw std::runtime_error("ERROR: Node not found");
}

template <class T>
bool LinkedList<T>::update(T update, T data){   
    Node<T>* curr = head;
    while (curr) {                              
        if (curr->getData() == data) {          // If the node to be updated is found
            curr->setData(update);
            return true;
        }
        curr = curr->getNext();
    }
    throw std::runtime_error("ERROR: Node not found");
}

template <class T>
bool LinkedList<T>::del(T data) {
    if (!head) {
        throw std::runtime_error("ERROR: Node not found");                           // If list is empty
    }

    if (head->getData() == data) {              // If the node to be deleted is the head
        Node<T>* temp = head;
        head = head->getNext();
        delete temp;
        --size;
        return true;
    }

    Node<T>* prev = head;
    Node<T>* curr = head->getNext();

    while (curr) {
        if (curr->getData() == data) {          // If the node to be deleted is not the head
            prev->setNext(curr->getNext());
            delete curr;
            --size;
            return true;
        }
        prev = curr;
        curr = curr->getNext();
    }

    throw std::runtime_error("ERROR: Node not found");
}

template <class T>
LinkedList<T>::~LinkedList() {
    while (head) {
        Node<T>* temp = head;
        head = head->getNext();
        delete temp;
    }
}