#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_HASH 26
#define HASH_KEY(key) (key-'a')%MAX_HASH

typedef struct Node
{
    char* word;
    struct Node* next;
}Node;

Node* hashTable[MAX_HASH];

Node* createNode(char* word)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->word=strdup(word);
    newNode->next=NULL;
    return newNode;
}

void insertHashtable(char* key,Node* node)
{
    int hashKey=HASH_KEY(key[0]);
    if(hashTable[hashKey]==NULL) hashTable[hashKey] = node;
    else
    {
        node->next=hashTable[hashKey];
        hashTable[hashKey]=node;
    }
}

bool wordPattern(char* pattern,char* s)
{
    char* word=strtok(s," ");
    int len=strlen(pattern);
    int cnt=0;
    for(int i=0;i<MAX_HASH;i++) hashTable[i]=NULL;
    int i=0;
    while(word!=NULL)
    {
        if(cnt>=len)return false;
        int hashKey=HASH_KEY(pattern[i]);
        Node* newNode=createNode(word);
        Node* current=hashTable[hashKey];
        if(current!=NULL)
        {
            if(strcmp(current->word, word)!=0) return false;
            current = current->next;
        }
        else
        {
            for (int j=0;j<26;j++) 
                if(hashTable[j]!=NULL&&strcmp(hashTable[j]->word,word)==0) return false;
        }
        insertHashtable(&pattern[i],newNode);
        word=strtok(NULL," ");
        cnt++;
        i++;
    }
    return cnt==len;
}