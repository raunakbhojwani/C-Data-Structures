/* 
 * bagtest.c - test program for simple bag module
 *
 * Raunak Bhojwani, April 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include "bag.h"

int main() 
{
  bag_t *bag;		                                             // the bag

  bag = bag_new();
  if (bag == NULL) {
    printf("bag_new failed\n");                             // check if bag was made successfully
    exit(1);
  }

  int test1 = 3;
  int test2 = 7;

  // some simple test code
  bag_insert(bag, "george");                                // insert several items into the bag
  bag_insert(bag, "raunak");
  bag_insert(bag, &test1);
  bag_insert(bag, "htc");
  bag_insert(bag, "clara");
  bag_insert(bag, NULL);                                    // including the item NULL, which will add nothing
  bag_insert(bag, &test2);
  bag_insert(bag, "VR");
  bag_insert(bag, "robot");
  bag_insert(bag, "zombie");
  bag_insert(NULL, 0);                                     // case where item inserted to null, should be ignored
  bag_insert(bag, NULL);

  printf("%s\n", (char *)bag_extract(bag));                // print the data of the item extracted, should be a LIFO structure
  printf("%s\n", (char *)bag_extract(bag));

  bag_insert(bag, "eve");
  
  printf("%s\n", (char *)bag_extract(bag));
  printf("%s\n", (char *)bag_extract(bag));

  printf("%d\n", *((char*)bag_extract(bag)));
  printf("%s\n", (char *)bag_extract(bag));
  printf("%s\n", (char *)bag_extract(bag));
  printf("%d\n", *((char*)bag_extract(bag)));
  printf("%s\n", (char *)bag_extract(bag));
  printf("%s\n", (char *)bag_extract(bag));
  printf("%p\n", bag_extract(bag));                         // bag is empty, should print nil from this call onwards
  printf("%p\n", bag_extract(bag));
  printf("%p\n", bag_extract(bag));
  printf("%p\n", bag_extract(bag));
  printf("%p\n", bag_extract(bag));

  bag_delete(bag);                                          // delete the bag
  printf("%s\n", "The bag has been successfully deleted!");
  
}