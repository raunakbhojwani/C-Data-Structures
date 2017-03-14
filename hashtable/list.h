/* 
 * list.h - header file for list module
 *
 * Raunak Bhojwani, April 2016
 */

#ifndef __LIST_H
#define __LIST_H

/**************** global types ****************/
typedef struct list list_t;  // opaque to users of the module

/**************** functions ****************/

/* Create a new (empty) list; 
 */
list_t *list_new(void);

/* Insert item into the given list;
 * return false if key already exists, and true if new item was inserted.
 * If list is NULL, or you encounter other error, return false.
 * Copy the key string
 */
bool list_insert(list_t *list, char *key, void *data);

/* Return the data associated with the given key;
 * return NULL if key is not found.
 */
void *list_find(list_t *list, char *key);

void list_delete(list_t *list);

#endif // __LIST_H