#include<stdio.h>
#include<stdlib.h>

#define size 11
int count;

int table[size] = {};

int hash1(int item){
    return (item%size);
}
int hash2(int item){
    return 8 - (item % 8);   // 8 - any value
}

void insert(int item){
    int h1 = hash1(item);
    int h2 = hash2(h1);
    int i=1;

    int key = h1;

    if (count == size){
        printf("Can't insert %d. The hashTable is Full :(\n", item);
    }

    while (table[key] != 0 && table[key] != -1){
        key = (h1 + i * h2) % size;
        i++;
    }

    table[key] = item;
    count++;
}

int search(int item){
    int h1 = hash1(item);
    int h2 = hash2(h1);
    int i=1;

    int key = h1;
    
    if (count==0){
        printf("The HashTable is Empty :(...\n");
        exit(EXIT_FAILURE);
    }
    
    while (table[key] != 0){
        if (table[key] == item)
            return key;
       key = (h1 + i * h2) % size;
       i++;
    }
    
    return -1;
}

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
int main(){
    insert(54);
    insert(33);
    //insert(47);
    insert(81);
    insert(38);
    insert(12);
    insert(95);
    insert(74);
    insert(82);
    //insert(46);
    //insert(46);

    printf("hash Table : \n");
    print();

    printf("After Deleting 81:\n");
    delete(81);
    print();

    printf("%d\n", search(54));

    return 0;

}
