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
#include <sstream>
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
            
        }
        else {
            Node* newHead = new Node();
            newHead->value = value;
            newHead->next = head;
            head = newHead;
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
        if(checkForDuplicate(value)){
            currentIndex = head;
            Node* temp;
            while (currentIndex->value != value) {
                temp = currentIndex;
                currentIndex = currentIndex->next;
            }
            if(currentIndex == head) {
                head = currentIndex->next;
                delete currentIndex;
                if(size()==0) {
                    head = NULL;
                    tail = NULL;
                }
                return;
            }
            else if(currentIndex == tail) {
                tail = temp;
                temp->next=NULL;
                delete currentIndex;
                if(size() == 0) {
                    head = NULL;
                    tail = NULL;
                }
                return;
            }
            else {
                temp->next = currentIndex->next;
                delete currentIndex;
                if(size()==0){
                    head = NULL;
                    tail = NULL;
                }
                return;
            }
            
        }
        else {
            return;
        }
        
    }
    void clear() {
        while(size() > 0){
            Node* n = head;
            head = head->next;
            delete n;
        }
        head = NULL;
        tail = NULL;
    }
    T at(int index) {
        if (index < 0) {
            throw out_of_range("under");
        }
        else{
            currentIndex = head;
            for (int i = 0; i <= index; i++) {
                if (currentIndex == NULL) {
                    throw out_of_range("OVER");
                }
                else if (i == index) {
                    break;
                }
                currentIndex = currentIndex->next;
            }
            return currentIndex->value;
        }
        
    }
    int size() {
        int listSize = 0;
        currentIndex = head;
        while(currentIndex != nullptr) {
            ++listSize;
            currentIndex = currentIndex->next;
        }
        return listSize;
    }
    string toString() {
        string list;
        ostringstream output;
        
        currentIndex = head;
        if (currentIndex == NULL) {
            return list;
        }
        else {
            while (currentIndex != NULL) {
                output << currentIndex->value;
                currentIndex = currentIndex->next;
                if(currentIndex == NULL){
                    
                }
                else {
                    output << " ";
                }
            }
            
            list = output.str();
            return list;
        }
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
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* currentIndex = nullptr;
};

#endif /* LinkedList_h */
