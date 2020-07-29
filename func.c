/*
 * Author: Derek Calzadillas
 * Purpose: To demonstrate knowledge of circular linked lists
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "func.h"

struct Node *head = NULL;
int flag = 1;

void createCircular(int a[], int n)
{
    int i;

    //t is temp helper to create new node
    struct Node *t, *last;

    //header ptr pts to newly created node in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = a[0]; //head accesses and assigns value to node

    last = head; //both ptrs pt to new node

    //build list by moving last ptr to new node through each iter
    for (i = 1; i < n; i++)
    {

        //create new node for the list, temp ptr pts to it
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i]; //t accesses and assigns value to node
        t->next = head; //t->next always inserted last, so t->next will link to the head
        last->next = t; //prev ptr next addr is assigned to new node's addr
        last = t;       //last pts to this newly appended node
    }

} //end create

void display(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);

    printf("\n");
}

int count(struct Node *p)
{
    int c = 0;
    //if not null start counting
    if (p)
    {
        do
        {
            c = c + 1;
            p = p->next;

        } while (p != head);
    }
    return c;
}

void recursiveTailDisplay(struct Node *p)
{

    static int flag = 0;

    if (head != p || flag == 0)
    {
        flag = 1;
        printf("%d ", p->data); //tail recursion
        recursiveTailDisplay(p->next);
    }

    if (p == head && flag == 1)
        printf("\n");
    flag = 0;
}

void recursiveHeadDisplay(struct Node **h)
{

    static int flag = 0;

    if (head != *h || flag == 0)
    {
        flag = 1;
        recursiveHeadDisplay(&(*h)->next); //head recursion
        printf("%d ", (*h)->data);
    }
    if (*h == head && flag == 0)
        printf("\n");
    flag = 0;
}

struct Node *insertAtHead(struct Node *h, int x)
{
    //copy head node
    struct Node *p = h;

    //create new node, link its next to head
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = head;

    //iterate to last node (last node should link to head, but we want to change that)
    while (p->next != h)
    {
        p = p->next;
    }
    p->next = t; //last node now links to t which is the new head

    //optional
    head = t;
    return head;
}

int insertAtPosition(struct Node **h, int x, int pos)
{
    struct Node *p = *h;
    if (pos > count(p))
    { //check if inbounds
        return 0;
    }

    struct Node *t;

    //if insert at pos 0, then first node (special case)
    if (pos == 0)
    {

        //create new node
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;

        //if head is null, then list was empty
        if (head == NULL)
        {
            head = t;          //t is head
            head->next = head; //head pts to itself for circular
        }
        else
        { //list wasn't empty so need to iter to the end
            p = head;
            while (p->next != head) //continue until we loop around to beginning
                p = p->next;
            p->next = t;    //last node next point to new node
            t->next = head; //new node next pts to old head
            head = t;       //head pts to new node
        }
    }
    else
    { //insert at a different pos than 0
        p = head;
        //p from head to desired pos
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        //create new node
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next; //new node next pt to node after p
        p->next = t;       //node after p is now new node
    }
    return 1;
}

struct Node *deleteHead(struct Node *p)
{
    //move node to end of circle
    while (p->next != head)
        p = p->next;
    p->next = head->next; //end node pts to node after head
    free(head);           //del head
    head = p->next;       //head jumps one node forward
    return head;
}

struct Node *deleteAtPos(struct Node *p, int pos)
{

    if (pos > count(p))
    {
        printf("Not a valid position.\n");
        return p;
    }

    struct Node *q; //to be one ahead of p

    if (pos == 1)
    {
        //iter p to end of circle
        while (p->next != head)
        {
            p = p->next;
        }
        //if there's only one node, free it
        if (p == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next; //end node pts to node after head
            free(head);           //del head
            head = p->next;       //head jumps one node forward
        }
    }
    else
    { //pos not the first node
        p = head;
        for (int i = 0; i < pos - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        free(q);
    }
    printf("Node at pos %d deleted.\n", pos);
    return head;
}

int reprompt(int flag)
{
    int fixin, input, ret = 0;
    if (flag == 1)
    { //check valid size
        while (ret != 1 || input > INT_MAX || input < 1)
        {
            printf("Enter a valid size: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    else if (flag == 2)
    { // check valid int
        while (ret != 1 || input > INT_MAX)
        {
            printf("Enter a valid integer: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    else if (flag == 3)
    { // check valid option 1-3
        while (ret != 1 || input > 3 || input < 1)
        {
            printf("\nEnter a valid option 1,2,3: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    else if (flag == 4)
    { // check valid option 1-2
        while (ret != 1 || input > 2 || input < 1)
        {
            printf("Enter a valid option 1,2: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    else if (flag == 5)
    { // check valid option 1-18
        while (ret != 1 || input > 6 || input < 1)
        {
            printf("Enter a valid option 1-6: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    return input;
}

int tryagain()
{
    int prompt, ret;
    printf("Press [Any Key][Enter] to Repeat or [1] to Return to Menu: ");
    ret = scanf("%d", &prompt);
    if (prompt != 1 || ret != 1)
        return 0;
    return 1; //if 1, continue loop
}

int menuloop()
{
    int prompt, ret;
    printf("Press [Any Key][Enter] for New Menu Item or [1] to Exit Program: ");
    ret = scanf("%d", &prompt);
    if (prompt != 1 || ret != 1)
        return 0;
    return 1; //if 1, continue loop
}

void makelist()
{
    //prompt user
    int input, size, ret;
    printf("\nEnter the size of desired global linked list: ");
    ret = scanf("%d", &size);
    if (size < 1 || size > INT_MAX || ret != 1)
    {
        size = reprompt(1); //1 flag for size
    }
    int arr[size];
    printf("Enter an integer for each element of the linked list.\n");
    for (int i = 0; i < size; i++)
    {
        printf("Please enter an integer: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > INT_MAX)
        {
            input = reprompt(2); //2 flag for int only
        }
        arr[i] = input;
    }
    createCircular(arr, size);
}
