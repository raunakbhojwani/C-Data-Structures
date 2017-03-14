README for counters.c
Raunak Bhojwani, April 2016

To compile this program call the following command in the correct directory: make

Makefile contains more information about compilation

Usage:
/*
* counters.c - a simple counters module that creates a counters data structure 
*/

Implements the functions:

/**************** counters_new() ****************/
// creates an empty counter data structure, returns the counter
counters_t *counters_new(void)

/**************** counters_add() ****************/
// adds a key to the counter, increments counter if key already exists
void counters_add(counters_t *ctrs, int key)

/**************** newItem() ****************/
// newItem: create a new item to store in the counters data structure
// returns pointer to new item, if successful,
// else returns NULL.
countersItem_t *newItem(counters_t *ctrs, int key)

/**************** counters_get() ****************/
// counters_get: create a new item to store in the baf
// returns the count of a key if it exists in the counter
// else returns NULL.
int counters_get(counters_t *ctrs, int key)

/**************** counters_delete() ****************/
// deletes the counter and all its contents
void counters_delete(counters_t *ctrs)

Assumptions:

- It is assumed that that the user passes an integer as a key to the counters item

Limitations:

- Due to the use of integers, the usability of this program is limited. It cannot accommodate double or float data types