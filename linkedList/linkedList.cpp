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
void LinkedList<T>::insertAtFront(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->setNext(head);
    head = newNode;
    size++;
}

template <class T>
void LinkedList<T>::insertAtEnd(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T>* curr = head;
        while (curr->getNext() != nullptr) {
            curr = curr->getNext();
        }
        curr->setNext(newNode);
    }
    size++;
}

template <class T>
LinkedList<T>::~LinkedList() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->getNext();
        delete temp;
    }
}