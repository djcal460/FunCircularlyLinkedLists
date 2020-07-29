/*
 * Author: Derek Calzadillas
 * Purpose: To demonstrate knowledge of circular linked lists
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "func.h"

extern struct Node *head;

int main()
{

    //welcome to this prog
    int input, ret;
    printf("\nWelcome to Fun Circular Linked Lists. Demonstrating Knowledge of Linked Lists.\n");
    printf("To start, let's create a circular linked list.\n");

    //create a global list called head
    makelist();

    //display the lists to the user
    printf("This is your circular linked list: ");
    display(head);

    //prompt user for what they would like to do with the linked list
    do
    {
        printf("\nWhat Do You Want to Do with Circular Linked List?\n");
        printf("1.  Display\n");
        printf("2.  Insert at Head\n");
        printf("3.  Insert at Position\n");
        printf("4.  Delete at Head\n");
        printf("5.  Delete at Position\n");
        printf("6.  Exit Program.\n");
        printf("\nEnter your choice: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 6 || input < 1)
        {
            input = reprompt(5); //flag#5 for 1-18 choices
        }
        switch (input)
        {
        case 1:
            printf("Display");
            displayMenu(head);
            break;
        case 2:
            printf("Insert Head");
            insertHeadMenu(head);
            break;
        case 3:
            printf("Insert at Pos");
            insertPosMenu(head);
            break;
        case 4:
            printf("Delete Head");
            deleteHeadMenu(head);
            break;
        case 5:
            printf("Delete at Pos");
            deleteAtPosMenu(head);
            break;
        case 6:
            printf("Exiting Program...\n");
            exit(0);
            break;
        default:
            printf("Invalid option.\n");
        }
    } while (input != 6);
    exit(0);
}
