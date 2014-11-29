#ifndef HASHTABLE
#define HASHTABLE

#define WORD_LENGTH  45
#define TABLE_LENGTH 26

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//struct used to hold each word
typedef struct node 
{
    char word[WORD_LENGTH + 1];
    struct node *next;
	
} node;

// table 
typedef struct table_node 
{
    char letter;
    struct node *next;
	
} table_node;

#endif

//What needs to go in dictionary and what stays in hash-table
//includes defines