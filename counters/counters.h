/* 
 * list.h - header file for list module
 *
 * Raunak Bhojwani, April 2016
 */

#ifndef __COUNTERS_H
#define __COUNTERS_H

/**************** global types ****************/
typedef struct counters counters_t;  // opaque to users of the module

/**************** functions ****************/

/* Create a new (empty) counters data structure; 
 */
counters_t *counters_new(void);

/* If key exists, increment counter;
 * If key does not exist, add key and set counter to 1
 */
void counters_add(counters_t *ctrs, int key);

/* Return the current value associated with the given key;
 * return 0 if key is not found.
 */
int counters_get(counters_t *ctrs, int key);

/* Delete the whole data structure
 */
void counters_delete(counters_t *ctrs);

#endif // __COUNTERS_H