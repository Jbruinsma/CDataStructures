//
// Created by justi on 4/20/2025.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListNode.h"
#include <string>
#include <sstream>



template<typename T>
class LinkedList {
private:
    ListNode<T>* head;
    ListNode<T>* tail;
    int size;

    ListNode<T>* getNodeAt(int index) {
        if (checkIndex(index) && !isEmpty()){
            int count = 0;
            ListNode<T>* curr = head;
            while (count < index) {
                count += 1;
                curr = curr->getNext();
            }
            return curr;
        }
        return nullptr;
    }

    bool checkIndex(int index) const {
        if (index < 0 || index >= size) {
            return false;
        } else {
            return true;
        }
    }

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LinkedList() {
        ListNode<T>* curr = head;
        while (curr) {
            ListNode<T>* next = curr->getNext();
            delete curr;
            curr = next;
        }
    }

    std::string toString() const {
        std::ostringstream out;
        ListNode<T>* curr = head;
        while (curr) {
            out << curr->getVal();
            if (curr->getNext()) {
                out << " <-> ";
            }
            curr = curr->getNext();
        }
        return out.str();
    }

    int getSize() const{
        return size;
    }

    void prepend(T value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        if (this->isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            head->setPrev(newNode);
            newNode->setNext(head);
            head = newNode;
        }
        size += 1;
    }

    void append(T value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        if (this->isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->setNext(newNode);
            newNode->setPrev(tail);
            tail = newNode;
        }
        size += 1;
    }

    void remove(T value) {
    if (isEmpty()) return;

    ListNode<T>* curr = head;

    while (curr != nullptr) {
        if (curr->getVal() == value) {
            ListNode<T>* nextNode = curr->getNext();
            ListNode<T>* prevNode = curr->getPrev();

            if (curr == head && curr == tail) {
                head = nullptr;
                tail = nullptr;
            } else if (curr == head) {
                head = nextNode;
                if (head) head->setPrev(nullptr);
            } else if (curr == tail) {
                tail = prevNode;
                if (tail) tail->setNext(nullptr);
            } else {
                if (prevNode) prevNode->setNext(nextNode);
                if (nextNode) nextNode->setPrev(prevNode);
            }

            delete curr;
            size--;
            return;
        }

        curr = curr->getNext();
    }
}

    void removeAt(const int index) {
        if (!isEmpty() && checkIndex(index)) {
            ListNode<T>* node = getNodeAt(index);
            ListNode<T>* prevNode = node->getPrev();
            ListNode<T>* nextNode = node->getNext();

            if (node == head && node == tail) {
                head = nullptr;
                tail = nullptr;
            } else if (node == head) {
                head = nextNode;
                if (head) head->setPrev(nullptr);
            } else if (node == tail) {
                tail = prevNode;
                if (tail) tail->setNext(nullptr);
            } else {
                if (prevNode) prevNode->setNext(nextNode);
                if (nextNode) nextNode->setPrev(prevNode);
            }

            delete node;
            size--;
        }
    }

    bool contains(T value ) const {
        if (isEmpty()) return false;
        ListNode<T>* curr = head;
        while (curr != nullptr) {
            if (curr->getVal() == value) {
                return true;
            }
            curr = curr->getNext();
        }
        return false;
    }

    ListNode<T>* find(T value) const {
        if (isEmpty()) return nullptr;
        ListNode<T>* curr = head;
        while (curr != nullptr) {
            if (curr->getVal() == value) {
                return curr;
            }
            curr = curr->getNext();
        }
        return nullptr;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

};



#endif //LINKEDLIST_H
