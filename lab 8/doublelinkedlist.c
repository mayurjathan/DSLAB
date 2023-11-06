// Write a menu driven program to perform the following on a doubly linked list
// i.) Insert an element at the rear end of the list
// ii.) Delete an element from the rear end of the list
// iii.) Insert an element at a given position of the list
// iv.) Delete an element from a given position of the list
// v.) Insert an element after another element
// vi.) Insert an element before another element
// vii.) Traverse the list
// viii.) Reverse the list
#include <stdio.h>
#include <string.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}