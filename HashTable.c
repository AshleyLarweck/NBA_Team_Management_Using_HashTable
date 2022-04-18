#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include "HashTable.h"

//Malloc a new HashTableImp, malloc the hashTable to be an array of HashTableEntrys of size n, 
//initialize each iChainIndex to be -2 (indicating that the spot is empty), 
//and return a pointer to the HashTableImp.
HashTable newHashTable(int n)
{
   HashTableImp *x = (HashTableImp*)malloc(sizeof(HashTableImp));
   x->n = n;
   int i =0;
   x->hashTable = (HashTableEntry*)malloc(n*sizeof(HashTableEntry));
   for(i = 0; i < n; i++)
   {
       x->hashTable[i].chainIndex = -2;
   }
   return x;
}

//Free the HashTable h.
void freeHashTable(HashTable h)
{
  if(h!=NULL)
    {
        if(h->hashTable != NULL)free(h->hashTable);
        free(h);
    }
}

//Given a string, convert it into an integer to be used in either
//the division method or the midsquare method.
int stringToInt(char *stringToConvert)
{
   int x;
   sscanf(stringToConvert, "%d", &x);
   return x;
}

//Given a key value, use the division method to find a 
//valid index for hashTable.
int divisionMethod(int key, int n)
{
return (key%n);
}

int numberOfDigits(int a)
{
   int i = 0;
   while(a > 0)
   {
       i++;
       a /= 10;
   }
   return i;
}

int po(int a, int b)
{
   while(b > 0)
   {
       a = a*10;
       b--;
   }
   return a;
}

//Given a key value, use the midsquare method to find a 
//valid index for hashTable.
/*int midsquareMethod(int key, int n)
{
   int temp = key*key;
   int x = numberOfDigits(temp);
   int y = numberOfDigits(n);
   if(x < y)
   {
       return x;
   }
   int p, p1;
   p = po(10, (x - ceil((x-y)/2)));
   p1 = po(10, (x-y)/2);
   temp = temp%p;
   temp = temp/p1;
   return temp;
}*/

//Insert e into our HashTable h by using stringToInt to convert the team name
//into an integer and then passing that integer to one of the division or 
//midsquare method functions.  If this entry is not occupied, insert it there
//and change the corresponding iChainIndex to be -1.  If there is a collision,
//use open chaining to find an open location for e, and update the iChainIndex
//values accordingly.
void put(HashTable h, Element e)
{
   int key = stringToInt(e.teamName);
   long hashIndex = divisionMethod(key, h->n);
   int i = 0;

   while(h->hashTable[hashIndex].chainIndex != -2)
   {
     hashIndex+=2;
     hashIndex = hashIndex%h->n;
     i++;
     if(i==h)
     {
       return;
     }

   }

   h->hashTable[hashIndex].key = e;
   h->hashTable[hashIndex].chainIndex = -1;
}

//Return a pointer to the key stuct containing the data that matches teamName
//if it exists.  If it does not exist, return NULL.
Element* get(HashTable h, char *teamName)
{
   int key = stringToInt(teamName);
   Element *addressValue;
   int hashIndex = divisionMethod(key, h->n);
   while(strcmp(h->hashTable[hashIndex].key.teamName, teamName) != 0)
   {  
      hashIndex += 2;
      hashIndex = hashIndex % h->n;
      //printf("%d\n", h->hashTable[hashIndex].key);
      addressValue = &(h->hashTable[hashIndex].key);
      //printf("%d\n", addressValue);
   }
   return addressValue;
}