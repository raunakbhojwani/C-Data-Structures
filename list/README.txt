README for list.c
Raunak Bhojwani, April 2016

To compile this program call the following command in the correct directory: make

Makefile contains more information about compilation

Usage:
/*
* list.c - a list module that creates a list data structure by implementing a linked list
*/
Implements the functions:

/**************** list_new() ****************/
// create new empty lists, return the pointer to the list
list_t *list_new(void)

/**************** list_insert() ****************/
// insert a new item into the list, with key and data
// return true if item inserter
// return fals if key already exists or any other problems
bool list_insert(list_t *list, char *key, void *data)
void counters_delete(counters_t *ctrs);

/**************** newItem() ****************/
// newItem: create a new item to store in the list
// returns pointer to new item, if successful,
// else returns false.
listItem_t *newItem(list_t *list, char *key, void *data)


/**************** list_find() ****************/
// finds an item in the list looking for its key
// returns data of said item if successful
// else returns NULL.
void *list_find(list_t *list, char *key)

/**************** list_delete() ****************/
// delete all contents of the list and the list itself
void list_delete(list_t *list) 

Assumptions:

- It is assumed that the user knows that the key associated with list items is in fact a string.

Limitations:

- This implementation of a list, in a linked list manner, can be incredibly inefficient.