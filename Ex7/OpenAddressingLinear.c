#include<stdio.h>
#include<stdlib.h>
int hashTable[10];
int hashFunc(int d)
{
    return d%10;
}
void retrieve(int key)
{
    int flag = 0;
    int hash = hashFunc(key);
    int index = hash;
    while(hashTable[index] != 0 && flag == 0)
    {
        printf("%d\n", hashTable[index]);
        if(hashTable[index] == key) flag = 1;
        index++; index = index % 10;
    }
    if(flag == 0) printf("Not found!\n");
    else printf("Found!\n");
}
void insert(int key)
{
    int index = hashFunc(key);
    while(hashTable[index++] != 0) index = index % 10;
    hashTable[index-1] = key;
}
int main()
{
    int i,key;
    for(i = 0; i < 10; i++)
        hashTable[i] = 0;
    insert(50);
    insert(91);
    insert(71);
    insert(103);
    insert(88);
    insert(48);
    insert(99);
    printf("Enter the key: ");
    scanf("%d", &key);
    retrieve(key);
    printf("\n");
    return 0;
}
