/* 
 * bag.c - simple bag module
 *
 * Raunak Bhojwani, April 2016
 */

/***include relevant libraries ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bag.h"

/**************** local type struct ****************/
typedef struct bagItem {
  	void *data;		           // pointer to data for this bag item
  	struct bagItem * next;   // pointer to the next item in the back
} bagItem_t;

/**************** global type struct ****************/
typedef struct bag {
	struct bagItem *head;      // start item in bag
} bag_t;

/**************** global functions ****************/
/* that is, visible outside this file */
/* see bag.h for comments about exported functions */

/**************** local functions ****************/
/* not visible outside this file */
static struct bagItem *newItem(bag_t *bag, void *data);

/**************** bag_new() ****************/
bag_t *
bag_new(void)
{
	bag_t * bag = malloc(sizeof(bag_t));   // allocate memory for the bag
	bag->head = NULL;                      // initialize contents of bag module, namely setting its head to null

	return bag;
}

/**************** bag_insert() ****************/
void 
bag_insert(bag_t *bag, void *data)
{
  if ((!(bag == NULL)) && bag->head == NULL) {        // check if bag exits and if it is empty. if so, insert the item and intialize it as the head
    bagItem_t * item = newItem(bag, data);
    if (item == NULL) {
      return;
    }
    bag->head = item;
    item->next = NULL;
  }
  else if ((!(bag == NULL)) && bag->head != NULL) {   // check if bag exits and if it is not empty. if so, insert the item into the bag and 
    bagItem_t *current = bag->head;                   // organize it as part of the LIFO structure
    while (current->next != NULL) {
      current = current->next;
    }
    bagItem_t *item = newItem(bag, data);
    if (item == NULL) {
      return;
    }
    item->next = current->next;
    current->next = item;
  }
}


/**************** newItem() ****************/
// newItem: create a new item to store in the bag
// returns pointer to new item, if successful,
// else returns NULL.

struct bagItem *newItem(bag_t *bag, void *data) 
{
  bagItem_t * item = malloc(sizeof(bagItem_t));       // allocate memory for the new item in the bag

  if (item == NULL)                                   // check if memory was allocated well, if not return NULL
    return NULL;
  else {
    item->next = NULL;                                // allocate memory for the bag's data and store the data before returning the item.
    // item->data = malloc(sizeof(data));                // if there are problems, return NULL
    item->data = data;
    if (item->data == NULL) {
      // clean up and return failure
      free(item);
      return NULL;
    }
    return item;
  }
}

/**************** bag_extract() ****************/
// bag_extract: remove an item from the bag
// returns data of the extracted item if successful,
// else returns NULL.

void *bag_extract(bag_t *bag)
{
	if (bag->head == NULL) {                           // check if bag is empty, if it is then return NULL
		return NULL;
	}

	bagItem_t * current = bag->head;

  if (current == bag->head && current->next == NULL) {    // if only one item in the bag, remove that item
    void * data = current->data;
    free(current);
    bag->head = NULL;
    return data;
  }

	while (current->next->next!= NULL) {                    // loop through all items in bag in order to remove the last one and delete it appropriately
   		current = current->next;
	}
 
	bagItem_t * removed = current->next;
  void * data = removed->data;
  current->next = NULL;
	free(removed);
	return data;
}

/**************** bag_delete() ****************/
// bag_delete: delete the bag and all ts contents
void bag_delete(bag_t *bag) 
{
  if (bag != NULL) {
    bagItem_t *current = bag->head;                       // if bag is not NULL, loop through items and remove each one before removing the bag itself
    while (current != NULL) {    
      bagItem_t *removed = current;
      current = current->next;
      free(removed);
    }
    free(bag);
  }
}

