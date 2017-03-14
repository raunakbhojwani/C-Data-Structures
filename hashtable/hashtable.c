/* 
 * hashtable.c - simple hashtable module
 *
 * Raunak Bhojwani, April 2016
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
#include "jhash.h"
#include "hashtable.h"


/**************** local types ****************/
typedef struct hashtable {
  	int num_slots;     // number of slots in the hastable
    list_t **slots;     // double pointer to list of list modules
} hashtable_t;

/**************** hashtable_new() ****************/
// create new hashtable, return pointer to the new hashtable
hashtable_t *hashtable_new(const int num_slots)
{
  if (num_slots <= 0) {         // catch error if num slots is too small
    printf("%s\n", "Error: please enter a num_slots that is greater than 0");
    exit(1);
  }
  hashtable_t *hashtable = malloc(sizeof(hashtable_t));         // allocate memory for the hashtable and all its slots
  hashtable->slots = malloc(sizeof(list_t*));

  for (int i = 0; i < num_slots; i++) {               // create new empty lists in each slot
    hashtable->slots[i] = list_new();
  }

  hashtable->num_slots = num_slots;

	return hashtable;
}

/**************** hashtable_insert() ****************/
// insert a key-data pair to the hashtable, return true if successful, false otherwise
bool hashtable_insert(hashtable_t *ht, char *key, void *data)
{
  if (ht == NULL) {
    return false;
  }

  int slot = JenkinsHash(key, ht->num_slots);             // use hash function to get slot number, and insert item there
  if (list_insert(ht->slots[slot], key, data)) {
    return true;
  }
  return false;
}

/**************** hashtable_find() ****************/
// find the item associate with the k=given key, return data associated with item if successful
// return null otherwise

void *hashtable_find(hashtable_t *ht, char *key)
{
  int slot = JenkinsHash(key, ht->num_slots);           // use the hash function and list_find to find the key, returning data, data will be null if key not found
  void * data = list_find(ht->slots[slot], key);
  return data;
}

/**************** hashtable_delete() ****************/
// delete the hashtable and all of its contents

void hashtable_delete(hashtable_t *ht) 
{
  if (ht != NULL) {
    list_t *current;
    for (int i = 0; i < ht->num_slots; i++) {           // loop through all the slots and free each slot
      current = ht->slots[i];
      list_delete(current);
    }
    free(ht->slots);                                    // free the pointer to slots and then the hashtable itself
    free(ht);
  }
}



