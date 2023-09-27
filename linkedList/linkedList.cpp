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
    if (!head) {
        head = newNode;
    } else {
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
        if (curr->getData() == data) {
            return curr->getData();
        }
        curr = curr->getNext();
    }
    return nullptr;
}

template <class T>
bool LinkedList<T>::update(T update, T data){
    Node<T>* curr = head;
    while (curr) {
        if (curr->getData() == data) {
            curr->setData(update);
            return true;
        }
        curr = curr->getNext();
    }
    return false;
}

template <class T>
bool LinkedList<T>::del(T data) {
    if (!head) {
        return false;
    }

    if (head->getData() == data) {
        Node<T>* temp = head;
        head = head->getNext();
        delete temp;
        --size;
        return true;
    }

    Node<T>* prev = head;
    Node<T>* curr = head->getNext();

    while (curr) {
        if (curr->getData() == data) {
            prev->setNext(curr->getNext());
            delete curr;
            --size;
            return true;
        }
        prev = curr;
        curr = curr->getNext();
    }

    return false;
}

template <class T>
LinkedList<T>::~LinkedList() {
    while (head) {
        Node<T>* temp = head;
        head = head->getNext();
        delete temp;
    }
}