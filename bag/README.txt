README for bag.c
Raunak Bhojwani, April 2016

To compile this program call the following command in the correct directory: make

Makefile contains more information about compilation

Usage:
/*
* bag.c - a simple bag module that creates a bag data structure 
*/

Implements the functions:

/* Create an empty bag; 
 * return NULL if error.
 */
bag_t *bag_new(void);

/* insert an item in to the bag */
void bag_insert(bag_t *bag, void *data);

// newItem: create a new item to store in the bag
// returns pointer to new item, if successful,
// else returns NULL.
struct bagItem *newItem(bag_t *bag, void *data);

// bag_extract: remove an item from the bag
// returns data of the extracted item if successful,
// else returns NULL.
void *bag_extract(bag_t *bag);

Assumptions:
- The assumption in this program is that the user knows that the program uses pointers and he or she must cast it accordingly when printing the data returned by bag_extract

Limitations:
- Not a very useful structure since it is implemented using LIFO, similar to a stack