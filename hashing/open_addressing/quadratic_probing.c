#include<stdio.h>
#include<stdlib.h>

#define size 10
int count;

int table[size] = {};

int hash(int item){
    return (item % size);
}

// Inserting an element in hashtable
void insert(int item){
    int key = hash(item);
    int i=1;
    
    if (count == size){
        printf("Hash Overflow. Can't insert %d :(.. \n", item);
    }

    while (table[key] != 0 && table[key] != -1){
 // Here, 0 shows empty slot and -1 shows deleted element slot
        key = (key + i*i) % size;
        i++;
    }

    table[key] = item;
    count++;
}

// searching element in hashtable
int search(int item){
    int key = hash(item);
    int i=1;
    if (count == 0){
        exit(EXIT_FAILURE);
    }

    while (table[key] != 0){
        
        if (table[key] == item)
            return key;
        
        key = (key + i*i) % size;
        i++;
    }   

    return -1;
}

// deleting element form hash table
void delete(int item){
    if (count == 0){
        printf("The hashtable is Empty ..!\n");
        exit(EXIT_FAILURE);
    }

   int  position = search(item);

    if (position != -1){
        table[position] = -1;
        count--;
    }
}

void print(){
    for (int i=0; i<size; i++){
        printf("%d ", table[i]);
    }
    printf("\n");
}

// Driver code
int main(){
    insert(54);
    insert(33);
    insert(47);
    insert(81);
    insert(38);
    insert(12);
    insert(95);
    insert(74);
    insert(82);
    insert(46);
    insert(46);

    printf("hash Table : \n");
    print();

    printf("After Deleting 81 and 74:\n");
    delete(81);
    delete(74);
    print();
    printf("location of 46 : %d\n", search(46));

    return 0;
}

/*
 * Results : 

Hash Overflow. Can't insert 46 :(..
hash Table :
46 81 12 33 54 95 82 47 38 74
After Deleting 81 and 74:
46 -1 12 33 54 95 82 47 38 -1
location of 46 : 0

*/
