/* 
 * listtest.c - test program for list module
 *
 * Raunak Bhojwani, April 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

int main() 
{
  list_t *list;		                                                   // the list

  list = list_new();                                                  // create a new list. exit if there are any problems.
  if (list == NULL) {
    printf("list_new failed\n");
    exit(1);
  }
  int raunak = 100;
  int george = 0;
  int shaun = 69;
  int raunak2 = 500;
  int karishma = 19;
  int jahnvi = 25;
  int rick = 1;
  // some simple test code
  bool funCall = list_insert(list, "raunak", &raunak);                                // insert several items into the list and print the function call to see if
  printf("%s\n", funCall ? "true" : "false");                                         // true or false is printed correctly
  funCall = list_insert(list, "george", &george);                                     
  printf("%s\n", funCall ? "true" : "false");
  funCall = list_insert(list, "george", NULL);         // should be false                            
  printf("%s\n", funCall ? "true" : "false");
  funCall = list_insert(list, "mahnoor", "rocknroll");
  printf("%s\n", funCall ? "true" : "false");
  funCall = list_insert(list, "shaun", &shaun);
  printf("%s\n", funCall ? "true" : "false");
  funCall = list_insert(list, "raunak", &raunak2);    // should be false
  printf("%s\n", funCall ? "true" : "false");
  funCall = list_insert(list, "karishma", &karishma);
  printf("%s\n", funCall ? "true" : "false");
  funCall = list_insert(list, "jahnvi", &jahnvi);
  printf("%s\n", funCall ? "true" : "false");
  funCall = list_insert(list, "raunak", NULL);         // should be false                            
  printf("%s\n", funCall ? "true" : "false");
  funCall = list_insert(list, "surender", "king");
  printf("%s\n", funCall ? "true" : "false");
  funCall = list_insert(list, "rick", &rick);
  printf("%s\n", funCall ? "true" : "false");
  funCall = list_insert(list, "laxman", "supercook");
  printf("%s\n", funCall ? "true" : "false");
   funCall = list_insert(NULL, "laxman", "supercook");
  funCall = list_insert(list, "raunak", &raunak2);    // should be false
  printf("%s\n", funCall ? "true" : "false");         

  printf("The data for Raunak is %i.\n", (*(char *)list_find(list, "raunak")));                       // should print all the data for the keys associated
  printf("The data for George is %i.\n", (*(char *)list_find(list, "george")));
  printf("The data for Mahnoor is %s.\n", (char *)list_find(list, "mahnoor"));
  printf("The data for Shaun is %i.\n", (*(char *)list_find(list, "shaun")));
  printf("The data for Karishma is %i.\n", (*(char *)list_find(list, "karishma")));
  printf("The data for Karishmaaaaa is %p.\n", list_find(list, "karishmaaaa"));       // key does not exist, should be null
  printf("The data for Jahnvi is %i.\n", (*(char *)list_find(list, "jahnvi")));
  printf("The data for Surender is %s.\n", (char *)list_find(list, "surender"));
  printf("The data for Rick is %i.\n", (*(char *)list_find(list, "rick")));
  printf("The data for Lakshman is %s.\n", (char *)list_find(list, "laxman"));

  list_delete(list);                                                              // delete the list
  printf("%s\n", "The bag has been successfully deleted!");
}