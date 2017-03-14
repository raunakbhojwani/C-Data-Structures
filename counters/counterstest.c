/* 
 * counterstest.c - test program for simple counters module
 *
 * Raunak Bhojwani, April 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include "counters.h"

int main() 
{
  counters_t *counter;		                                                    // the counter

  counter = counters_new();
  if (counter == NULL) {                                                      // make new counter, exit if there are any problems
    printf("counter_new failed\n");
    exit(1);
  }

  // some simple test code
  counters_add(counter, 1);                                                  // add keys to the counter and print the values for the keys 1,2,3 to make sure the count is correct
  printf("The count for George is %i.\n", counters_get(counter, 1));
  printf("The count for Raunak is %i.\n", counters_get(counter, 2));
  printf("The count for HTC is %i.\n", counters_get(counter, 3));
  counters_add(counter, 2);
  printf("The count for George is %i.\n", counters_get(counter, 1));
  printf("The count for Raunak is %i.\n", counters_get(counter, 2));
  printf("The count for HTC is %i.\n", counters_get(counter, 3));
  counters_add(counter, 1);
  printf("The count for George is %i.\n", counters_get(counter, 1));
  printf("The count for Raunak is %i.\n", counters_get(counter, 2));
  printf("The count for HTC is %i.\n", counters_get(counter, 3));
  counters_add(counter, 3);
  printf("The count for George is %i.\n", counters_get(counter, 1));
  printf("The count for Raunak is %i.\n", counters_get(counter, 2));
  printf("The count for HTC is %i.\n", counters_get(counter, 3));
  counters_add(counter, 1);
  printf("The count for George is %i.\n", counters_get(counter, 1));
  printf("The count for Raunak is %i.\n", counters_get(counter, 2));
  printf("The count for HTC is %i.\n", counters_get(counter, 3));
  counters_add(counter, 2);
  printf("The count for George is %i.\n", counters_get(counter, 1));
  printf("The count for Raunak is %i.\n", counters_get(counter, 2));
  printf("The count for HTC is %i.\n", counters_get(counter, 3));
  counters_add(counter, 1);
  counters_add(counter, NULL);
  printf("The count for NULL is %i.\n", counters_get(counter, NULL));
  printf("The count for George is %i.\n", counters_get(counter, 1));
  printf("The count for Raunak is %i.\n", counters_get(counter, 2));
  printf("The count for HTC is %i.\n", counters_get(counter, 3));
  counters_add(counter, 2);
  printf("The count for George is %i.\n", counters_get(counter, 1));
  printf("The count for Raunak is %i.\n", counters_get(counter, 2));
  printf("The count for HTC is %i.\n", counters_get(counter, 3));
  counters_add(counter, 1);
  counters_add(counter, NULL);
  printf("The count for NULL is %i.\n", counters_get(counter, NULL));
  printf("The count for George is %i.\n", counters_get(counter, 1));
  printf("The count for Raunak is %i.\n", counters_get(counter, 2));
  printf("The count for HTC is %i.\n", counters_get(counter, 3));
  counters_add(NULL, 0);                                                                                // should be ignored

  printf("The count for George is %i.\n", counters_get(counter, 1));
  printf("The count for Raunak is %i.\n", counters_get(counter, 2));
  printf("The count for HTC is %i.\n", counters_get(counter, 3));

  counters_add(counter, 4);
  printf("The count for George is %i.\n", counters_get(counter, 1));
  printf("The count for Raunak is %i.\n", counters_get(counter, 2));
  printf("The count for HTC is %i.\n", counters_get(counter, 3));
  printf("The count for Eve is %i.\n", counters_get(counter, 4));
  
  counters_delete(counter);                                                                            // delete counter
  printf("The counters data structure has been deleted. Thank you for testing. Good bye!");
}
