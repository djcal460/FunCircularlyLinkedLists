/*
 * Author: Derek Calzadillas
 * Purpose: To demonstrate knowledge of circular linked lists
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "func.h"

extern struct Node* head;

void displayMenu(struct Node *p){
//display LL using iter, tail recursion, and head recursion
    int input, ret;
    int f = 0;
    while (!f)
    {
        printf("\nHow do you want the display computed?\n");
        printf("Press [1] iterative display [2] tail recursion display [3] head recursion display (Reverse): ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 3 || input < 1)
        {
            input = reprompt(3); //3 flag for 1,2,3 only
        }
        switch (input)
        {
        case 1:
            printf("You Chose Iterative Display:\n");
            display(p); //ascending display
            break;
        case 2:
            printf("You Chose Tail Recursion Display:\n");
            recursiveTailDisplay(p); //ascending display
            printf("\n");
            break;
        case 3:
            printf("You Chose Head Recursion Display (Reverse):\n");
            recursiveHeadDisplay(&p); //decending display
            printf("\n");
            break;
        default:
            printf("Invalid option.\n");
        }
        f = tryagain();
    }
}

struct Node *insertHeadMenu(struct Node *p)
{
    //Insert at head of LL
    int f = 0;
    int ins, ret;
    while (!f)
    {
        printf("\nInsert an integer to the head of the linked list.\n");
        printf("Enter a valid integer: ");
        fflush(stdout);
        ret = scanf("%d", &ins);
        if (ret != 1 || ins > INT_MAX)
        {
            ins = reprompt(2); //2 flag for valid int
        }
        p = insertAtHead(p, ins);
        printf("You inserted %d in: ", ins);
        printf("\n");
        display(p);
        f = tryagain();
    }
    return p;
}

struct Node *insertPosMenu(struct Node *p)
{
    //Insert at position of ll
    int f = 0;
    int pos, ins, ret;
    while (!f)
    {
        printf("\nInsert an integer a a given pos of the linked list.\n");
        display(p);
        printf("Enter a valid integer to insert: ");
        fflush(stdout);
        ret = scanf("%d", &ins);
        if (ret != 1 || ins > INT_MAX)
        {
            ins = reprompt(2); //2 flag for valid int
        }
        printf("Enter a position: ");
        fflush(stdout);
        ret = scanf("%d", &pos);
        if (ret != 1 || pos > INT_MAX)
        {
            pos = reprompt(2); //2 flag for valid int
        }
        int bounds = insertAtPosition(&p, ins, pos);
        if (bounds)
        {
            printf("You inserted %d at pos %d in: ", ins, pos);
            display(p);
        }
        else
        {
            printf("Your position was out of bounds\n");
        }
        f = tryagain();
    }
    return p;
}



void deleteHeadMenu(struct Node *p)
{
    //delete head of list
    int ret, input, f = 0;
    while (!f)
    {
        printf("\nDelete head node from list: ");
        display(p);
        printf("Delete head node? Enter 1 for yes, 2 for no: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 2 || input < 1)
        {
            input = reprompt(4); //4 valid option 1 or 2
        }
        if (input == 1)
        {
            p = deleteHead(p);
            printf("Updated linked list: ");
            display(head);
        }
        else
        {
            printf("Head Not Deleted.\n");
        }
        f = tryagain();
    }
}

void deleteAtPosMenu(struct Node *p)
{
    //delete node at position
    int pos, ret, f = 0;
    while (!f)
    {
        printf("\nChoose a position to delete the node: ");
        display(p);
        ret = scanf("%d", &pos);
        if (pos < 1 || pos > INT_MAX || ret != 1)
        {
            pos = reprompt(2); //2 flag for int only
        }
        p = deleteAtPos(p, pos);
        printf("Updated linked list: ");
        display(p);
        f = tryagain();
    }

}
