# FunCircularlyLinkedLists

### Interactive terminal app demonstrating singly linked list computations

FunCircularlyLinkedLists was developed in c language to demonstrate how a globally or locally created singly linked list can be manipulated using pointers in many many ways.
  - Enter your own elements to create a magically-numbered circularly linked list
  - 5 fun fun menu options to manipulate the list
  - Menu options let you decide to use iteration, tail recurstion or head recursion
  - Repeat menu the same options to continually change the list

# Features!
Menu options include display, insert at head, insert at position, delete head, and delete at position! Still not enough for you? Well, in addition to each feature, you will have additional choices to decide how you want the feature computed. For example, you may display the linked list by computing via iteration, tail recursion, or head recursion. 

### Tech
Tech uses the very very very advanced terminal shell and gcc compiler.

### Installation
The program comes with a swanky Makefile for you to automagically compile the .c extensions into .o binaries. Exciting? Make the file and run the file in bash.
```sh
$ make
$ ./funfuncircularlinkedlists
```

Don't have all that time to type in "make"? Well, I have another solution for you...

```sh
$ gcc -I./ -o funfuncircularlinkedlists funfuncircularlinkedlists.c menufunc.c func.c
```
