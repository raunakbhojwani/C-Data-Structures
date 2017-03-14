/* 
 * hashtabletest.c - test program for hashtable module
 *
 * Raunak Bhojwani, April 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "hashtable.h"


int main() 
{
  hashtable_t *ht;		                                              // the hashtable

  ht = hashtable_new(11);                                           // create new hashtable, exit if you find any errors
  if (ht == NULL) {
    printf("list_new failed\n");
    exit(1);
  }
  int raunak = 51;
  int george = 0;
  int shaun = 69;
  int raunak2 = 500;
  int karishma = 19;
  int jahnvi = 25;
  int rick = 1;
  // some simple test code
  bool funCall = hashtable_insert(ht, "raunak", &raunak);               // insert some string-data pairs into the hashtable, print the function calls to see if 
  printf("%s\n", funCall ? "true" : "false");                           // true and false are being returned effectively
  funCall = hashtable_insert(ht, "george", &george);
  printf("%s\n", funCall ? "true" : "false");
  funCall = hashtable_insert(ht, "mahnoor", "rocknroll");
  printf("%s\n", funCall ? "true" : "false");
  funCall = hashtable_insert(ht, "shaun", &shaun);
  printf("%s\n", funCall ? "true" : "false");
  funCall = hashtable_insert(ht, "george", NULL);       
  printf("%s\n", funCall ? "true" : "false");           // should be false
  funCall = hashtable_insert(ht, "raunak", &raunak2);   
  printf("%s\n", funCall ? "true" : "false");           // should be false
  funCall = hashtable_insert(ht, "karishma", &karishma);
  printf("%s\n", funCall ? "true" : "false");
  funCall = hashtable_insert(ht, "jahnvi", &jahnvi);
  printf("%s\n", funCall ? "true" : "false");
  funCall = hashtable_insert(ht, "surender", "king");
  printf("%s\n", funCall ? "true" : "false");
  funCall = hashtable_insert(ht, "rick", &rick);
  printf("%s\n", funCall ? "true" : "false");
  funCall = hashtable_insert(ht, "raunak", NULL);   
  printf("%s\n", funCall ? "true" : "false");           // should be false
  funCall = hashtable_insert(ht, "laxman", "supercook");
  printf("%s\n", funCall ? "true" : "false");
  funCall = hashtable_insert(NULL, "laxman", "supercook");
  printf("%s\n", funCall ? "true" : "false");         // should be false


  printf("The data for Raunak is %i.\n", (*(char *)hashtable_find(ht, "raunak")));        // find the inserted keys and the data associated with it
  printf("The data for George is %i.\n", (*(char *)hashtable_find(ht, "george")));
  printf("The data for Mahnoor is %s.\n", (char *)hashtable_find(ht, "mahnoor"));
  printf("The data for Shaun is %i.\n", (*(char *)hashtable_find(ht, "shaun")));
  printf("The data for Karishma is %i.\n", (*(char *)hashtable_find(ht, "karishma")));
  printf("The data for Karishmaaaa is %p.\n", hashtable_find(ht, "karishmaaaa"));          // key does not exist, should by null
  printf("The data for Jahnvi is %i.\n", (*(char *)hashtable_find(ht, "jahnvi")));
  printf("The data for Surender is %s.\n", (char *)hashtable_find(ht, "surender"));
  printf("The data for Rick is %i.\n", (*(char *)hashtable_find(ht, "rick")));
  printf("The data for Lakshman is %s.\n", (char *)hashtable_find(ht, "laxman"));

}
