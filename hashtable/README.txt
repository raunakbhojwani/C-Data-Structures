README for hashtable.c
Raunak Bhojwani, April 2016

To compile this program call the following command in the correct directory: make

Makefile contains more information about compilation

Usage:
/*
* hashtable.c - a hashtable module that creates a hash table data structure using the list module already defined and used
*/


Implements the functions:

/**************** hashtable_new() ****************/
// create new hashtable, return pointer to the new hashtable
hashtable_t *hashtable_new(const int num_slots)

/**************** hashtable_insert() ****************/
// insert a key-data pair to the hashtable, return true if successful, false otherwise
bool hashtable_insert(hashtable_t *ht, char *key, void *data)

/**************** hashtable_find() ****************/
// find the item associate with the k=given key, return data associated with item if successful
// return null otherwise
void *hashtable_find(hashtable_t *ht, char *key)

/**************** hashtable_delete() ****************/
// delete the hashtable and all of its contents
void hashtable_delete(hashtable_t *ht) 

Assumptions:

- It is assumed that the hash function maps a key to only one slot and also that the hash function used is an effective one.
- It is assumed that the user passes an integer as an argument to represent num_slots.

Limitations:

- Limitations of this program include memory allocation - a maximum amount of memory is established when the hash table is created. The user or program does not explicitly define a maximum number of slots.
