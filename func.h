/*
 * Author: Derek Calzadillas
 * Purpose: To demonstrate knowledge of circular linked lists
 */

#ifndef __func_h__
#define __func_h__

//create head node 'head' as global, space alloc at runtime
struct Node{
    int data;
    struct Node *next;
};

void createCircular(int[], int );
void display(struct Node *);
int count(struct Node *);
void recursiveTailDisplay(struct Node *);
void recursiveHeadDisplay(struct Node **);
struct Node * insertAtHead(struct Node *,int );
int insertAtPosition(struct Node **, int , int );
struct Node * deleteHead(struct Node *);
struct Node * deleteAtPos(struct Node *, int );
int reprompt(int );
int tryagain();
int menuloop();
void makelist();
void displayMenu(struct Node *);
struct Node *insertHeadMenu(struct Node *);
struct Node *insertPosMenu(struct Node *);
void deleteHeadMenu(struct Node *);
void deleteAtPosMenu(struct Node *);

#endif
