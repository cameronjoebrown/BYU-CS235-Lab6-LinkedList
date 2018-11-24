//
//  LinkedList.h
//  Lab6
//
//  Created by Cam on 11/12/18.
//  Copyright © 2018 Cameron Brown. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <iostream>
#include "LinkedListInterface.h"

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface <T> {
public:
    struct Node {
        T value;
        Node* next;
    };
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        listSize = 0;
    }
    ~LinkedList() {
        clear();
    }
    void insertHead(T value) {
        if(checkForDuplicate(value)) {
            
        }
        else if(head == nullptr){
            Node* newHead = new Node();
            newHead->value = value;
            head = newHead;
            listSize++;
            
        }
        else {
            Node* newHead = new Node();
            newHead->value = value;
            newHead->next = head;
            head = newHead;
            listSize++;
        }
    }
    void insertTail(T value) {
        if(head == nullptr){
            insertHead(value);
        }
        else if(checkForDuplicate(value)) {
            
        }
        else {
            currentIndex = head;
            while (currentIndex->next != NULL) {
                currentIndex = currentIndex->next;
            }
            Node* newTail = new Node();
            newTail->value = value;
            newTail->next = nullptr;
            currentIndex->next = newTail;
            tail = newTail;
            listSize++;
        }
    }
    void insertAfter(T value, T insertionNode) {
        if(checkForDuplicate(value)) {
            
        }
        else {
            currentIndex = head;
            while (currentIndex != NULL) {
                if (currentIndex->value == insertionNode) {
                    Node* newNode = new Node();
                    newNode->value = value;
                    newNode->next = currentIndex->next;
                    currentIndex->next = newNode;
                    break;
                }
                currentIndex = currentIndex->next;
            }
        }

    }
    void remove(T value) {
        
    }
    void clear() {
        
    }
    T at(int index) {
        T value;
        return value;
    }
    int size() {
        return listSize;
    }
    string toString() {
        
        return "";
    }
    bool checkForDuplicate(T value) {
            currentIndex = head;
            while (currentIndex != NULL) {
                if (currentIndex->value == value) {
                    return true;
                }
                currentIndex = currentIndex->next;
            }
            return false;
    }
protected:
    
    
private:
    Node* head;
    Node* tail;
    Node* currentIndex;
    int listSize;
};

#endif /* LinkedList_h */
