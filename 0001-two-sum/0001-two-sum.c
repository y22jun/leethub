#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_HASH 1373
#define HASH_KEY(key) key%MAX_HASH
typedef struct Node
{
    int id;
    struct Node *next;
}Node;
Node* hashTable[MAX_HASH];

Node* createNode(int key)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->id=key;
    newNode->next=NULL;
    return newNode;
}

void insert_hashtable(int key,Node* node)
{
    int hash_key=HASH_KEY(key);
    if(hash_key<0) hash_key=-hash_key;
    if(hashTable[hash_key]==NULL) hashTable[hash_key]=node;
    else
    {
        node->next=hashTable[hash_key];
        hashTable[hash_key]=node;
    }
}

int *twoSum(int *nums,int numSize,int target,int *returnSize)
{
    for(int i=0;i<numSize;i++) 
    {
        Node* node=createNode(nums[i]);
        insert_hashtable(nums[i],node);
    }
    for(int i=0;i<numSize-1;i++)
    {
        for(int j=i+1;j<numSize;j++)
        {
            int key=target-nums[i];
            int key_key=HASH_KEY(key);
            if(key_key<0) key_key=-key_key;
            Node* curr=hashTable[key_key];
            while(curr!=NULL)
            {
                if(curr->id==key&&curr->id==nums[j])
                {
                    int *a=(int *)malloc(2*sizeof(int));
                    a[0]=i;
                    a[1]=j;
                    *returnSize=2;
                    return a;
                }
                curr=curr->next;
            }
        }
    }
    *returnSize=0;
    return NULL;    
}