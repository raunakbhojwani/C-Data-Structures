/* 
 * bag.h - header file for bag module
 * 
 * Raunak Bhojwani, April 2016
 */

#ifndef __BAG_H
#define __BAG_H

/**************** global types ****************/
typedef struct bag bag_t;  // opaque to users of the module

/**************** functions ****************/

/* Create a new (empty) bag; 
 */
bag_t *bag_new(void);

/* Insert item into the given bag;
 * The item is described by some data.
 */
void bag_insert(bag_t *bag, void *data);

/* Remove any item from the bag and return it to the caller;
 * return NULL if bag is empty.
 */
void *bag_extract(bag_t *bag);

void bag_delete(bag_t *bag);


#endif // __BAG_H