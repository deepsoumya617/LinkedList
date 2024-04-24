// singlylinkedlist.h

#include <iostream>
#include <vector>
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode (int data1) {
        data = data1;
        this->next = NULL;
    }
};

class SLL {
public:
    ListNode* head;
    ListNode* tail;
    int length;

    SLL () {
        head = tail = NULL;
        length = 0;
    }

    void convertArr2LL (int arr[], int size) {
        length = size;
        int n = size;
        head = new ListNode(arr[0]);
        tail = new ListNode(arr[n - 1]);
        ListNode* mover = head;
        for(int i = 1; i < n; ++i) {
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = temp;
        }
    }

    void convertVector2LL (std::vector<int>& v) {
        length = v.size();
        head = new ListNode(v[0]);
        tail = new ListNode(v[v.size() - 1]);
        ListNode* mover = head;
        for(int i = 1; i < v.size(); ++i) {
            ListNode* temp = new ListNode(v[i]);
            mover->next = temp;
            mover = temp;
        }
    }

    int findElement (int val) {
        ListNode* temp = head;
        int cnt = 0;
        int flag = 0;
        while (temp) {
            cnt++;
            if(temp->data == val) {
                flag = 1;
                std::cout << "Element found at index " << cnt;
                break;
            }
            temp = temp->next;
        }
        if(!flag) {
            std::cout << "Element not found in the List";
        }
    }

    void insertBeforeHead (int val) {
        ListNode* temp = new ListNode(val);
        if(length == 0) head = tail = temp;
        else {
            temp->next = head;
            head = temp;
        }
        length++;
    }

    void insertAfterHead (int val) {
        ListNode* temp = new ListNode(val);
        if(length == 0) head = tail = temp;
        else {
            temp->next = head->next;
            head->next = temp;
        }
        length++;
    }

    void displayLL () {
        ListNode* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void insertAfterTail (int val) {
        ListNode* temp = new ListNode(val);
        if(length == 0) head = tail = temp;
        else {
            tail->next = temp;
            temp->next = NULL;
            tail = temp;
        }
        length++;
    }

    void insertBeforeTail (int val) {
        ListNode* temp = new ListNode(val);
        if(length == 0) head = tail = temp;
        else {
            ListNode* mover = head;
            while (mover->next->next != NULL) {
                mover = mover->next;
            }
            temp->next = mover->next;
            mover->next = temp;
            tail = temp->next;
        }
        length++;
    }

    void insertAtIdx (int idx, int val) {
        if(idx < 1 or idx > length) {
            std::cout << "Invalid Index";
            return;
        }
        else if(idx == 1) insertBeforeHead(val);
        else if(idx == length) insertBeforeTail(val);
        else {
            ListNode* curr = new ListNode(val);
            ListNode* temp = head;
            for(int i = 1; i < idx - 1; ++i) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
            length++;
        }
    }

    int getAtIdx (int idx) {
        if(idx < 1 or idx > length) {
            std::cout << "Invaild Index ";
            return idx;
        }
        else if (idx == 1) return head->data;
        else if (idx == length) return tail->data;
        else {
            ListNode* temp = head;
            for (int i = 2; i <= idx; ++i)
                temp = temp->next;
            return temp->data;
        }
    }

    void deleteHead () {
        if(length == 0) {
            std::cout << "List is empty";
            return;
        } else {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            length--;
        }
    }

    void deleteTail () {
        if(length == 0) {
            std::cout << "List is empty";
            return;
        } else {
            ListNode* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            temp->next = NULL;
            tail = temp;
            length--;
        }
    }

    void deleteAtIdx (int idx) {
        if(idx < 1 || idx > length) {
            std::cout << "Invalid Index";
            return;
        }
        else if(idx == 1) deleteHead();
        else if(idx == length) deleteTail();
        else {
            ListNode* temp = head;
            for(int i = 2; i < idx; ++i) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            length--;
        }
    }

    void reverse () {
        ListNode* temp = head;
        ListNode* a = head;
        ListNode* tempHead = head;
        ListNode* nextNode = head->next;
        while (nextNode != NULL) {
            a = nextNode;
            nextNode = a->next;
            a->next = temp;
            temp = a;
        }
        tempHead->next = NULL;
        head = temp;
    }
};

#endif