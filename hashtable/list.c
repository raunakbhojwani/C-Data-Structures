/* 
 * list.c - simple list module
 *
 * Raunak Bhojwani, April 2016
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

/**************** local types ****************/
typedef struct listItem {
  	char *key;               // the key for this list item
    void *data;		           // pointer to data for this list item
    struct listItem *next;   // pointer to next item in list
} listItem_t;

/**************** global types ****************/
typedef struct list {
	struct listItem *head;     // start item for this list
} list_t;

/**************** global functions ****************/
/* that is, visible outside this file */
/* see list.h for comments about exported functions */

/**************** local functions ****************/
/* not visible outside this file */
static listItem_t *newItem(list_t *list, char *key, void *data);


/**************** list_new() ****************/
// create new empty lists, return the pointer to the list
list_t *
list_new(void)
{
	list_t * list = malloc(sizeof(list_t));              // allocate memory for the list

	// initialize contents of bag structure
	list->head = NULL;
	return list;
}

/**************** list_insert() ****************/
// insert a new item into the list, with key and data
// return true if item inserter
// return fals if key already exists or any other problems
bool list_insert(list_t *list, char *key, void *data)
{
  if (list == NULL) {                                 // return false if list is null
    return false;
  }
  else if (list->head == NULL) {                      // is the list is empty, add item as the head
		listItem_t * item = newItem(list, key, data);
    list->head = item;
    item->next = NULL;
    return true;
  }
  
  else {                                              // if list not empty, check if key exists. if it does, return false
    listItem_t *current = list->head;
    while (current->next != NULL) {
      if (current->key == key) {
        return false;
      }
      current = current->next;
    }
    if (current->key == key) {
      return false;
    }
    listItem_t *item = newItem(list, key, data);      // if key does not exist, add the item and return true
    item->next = current->next;
    current->next = item;
    return true;
  }
}


/**************** newItem() ****************/
// newItem: create a new item to store in the list
// returns pointer to new item, if successful,
// else returns false.

listItem_t *newItem(list_t *list, char *key, void *data)
{
  // allocate memory for the new node
  listItem_t * item = malloc(sizeof(listItem_t));

  if (item == NULL)
    return false;
  else {
    // initialize bag contents

    item->next = NULL;                                  // allocate memory for the new item and store its information and then return item
    item->data = data;
    item->key = malloc(sizeof(key));
    item->key = key;
    if (item->key == NULL) {
      // clean up and return failure
      free(item);
      return false;
    }
    return item;
  }
}

/**************** list_find() ****************/
// finds an item in the list looking for its key
// returns data of said item if successful
// else returns NULL.

void *list_find(list_t *list, char *key)
{
  listItem_t *current = list->head;                         // loop through all items in the list, searching for the key

  if (current != NULL) {
    if (current->key == key) {
      void * data = current->data;                          // if key is found, return the corresponding data
      return data;
    }

    while (current->next != NULL) {
      current = current->next;
      if (current->key == key) {
        void * data = current->data;
        return data;
      }
    }
  }
  return NULL;                                              // else return null
}


/**************** list_delete() ****************/
// delete all contents of the list and the list itself

void list_delete(list_t *list) {
  if (list != NULL) {
    listItem_t * current = list->head;                       // loop through all items in the list, freeing each item and its data and then freeing the list itself
    while (current != NULL) {    
      listItem_t * removed = current;
      current = current->next;
      free(removed);
    }
    free(list);
  }
}



