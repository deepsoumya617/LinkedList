// In this CPP file I have explained about all of the 
// Operations and commands included in the "SinglyLinkedList.h" file
#include <iostream>
#include <vector>
#include "SinglyLinkedList.h"
using namespace std;

// Main Function
int main () {
    // Declaration of the Linked Lists
    SLL list1;
    SLL list2;

    // Convert an Array to a Singly Linked List
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    list1.convertArr2LL(arr, n);

    // Convert an Vector to a Singly Linked List
    vector<int> v = {7, 8, 9, 10, 11};
    list2.convertVector2LL(v);
    
    // Find an element in the list
    list1.findElement(5);
    cout << "\n";

    // Insert an Element Before the Head of the Linked List
    list1.insertBeforeHead(8);

    // Insert an Element After the Head of the Linked List
    list1.insertAfterHead(9);

    // Insert an Element Before the Tail of the Linked List
    list1.insertBeforeTail(11);

    // Insert an Element After the Tail of the Linked List
    list1.insertAfterTail(15);
        
    // Insert an Element At a given Index of the Linked List
    list1.insertAtIdx(4, 7);

    // Get an Element from a given Index of the Linked List
    cout << list1.getAtIdx(5) << "\n";

    // Delete the Head of the Linked List
    list1.deleteHead();

    // Delete the Tail of the Linked List
    list1.deleteTail();

    // Delete Node from a given Index of the Linked List
    list1.deleteAtIdx(5);
    
    // Reverse the Linked List
    list1.reverse();
    list1.displayLL();

    // Get the Length of the Linked List
    cout << "\n";
    cout << list1.length;

    return 0;
}