#include<stdio.h>
#include<stdlib.h>

#define size 10
int count; // count of element present in the hashtable
int table[size] = {};  // Initialize all table values 0

// Hash Function
int hash(int item){
    return item % size;
}

// Inserting element into Hash Table
void insert(int item){
    int key = hash(item);

    if (count == size){
        printf("HashTable Overflow, Couldn't insert %d :(....\n",item);
        return;
    }

    while(table[key] != 0 && table[key] != -1){ 
        // Here, 0 shows empty slot and -1 shows deleted element slot
        key = (key + 1) % size;
    }
    table[key] = item;
    count++;
}

// searching for the element
int search(int item){
     if (count==0){
        printf("The Hashtable is Empty :(..\n");
        
        exit(EXIT_FAILURE);
    }

    int key = hash(item);
    
    while (table[key] != 0){
        if (table[key] == item)
            return key;
        
        key = (key+1)%size;
    }
   
    printf("Element not found :(...\n");
    return -1;

}

// Deleting elemet
void delete(int item){

    if (count==0){
        printf("The Hashtable is Empty :(..\n");
        
        exit(EXIT_FAILURE);
    }
    
    int location = search(item);
    
    if (location != -1){
        table[location] = -1;
        count--;
    }

}

void print_list(){
    for (int i=0; i<size; i++){
        printf("%d ", table[i]);
    }
    printf("\n");
}

// Driver Code
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

    printf("The Hash Table is : \n");
    print_list();

    delete(95);
    delete(46);
    printf("After deleting 95 and 46\n");
    print_list();
    printf("Finding the index of 12 in Hash Table : %d\n", search(12));
 }

/*

 * Results: 
HashTable Overflow, Couldn't insert 46 :(....
The Hash Table is :
46 81 12 33 54 95 74 47 38 82
After deleting 95 and 46
-1 81 12 33 54 -1 74 47 38 82
Finding the index of 12 in Hash Table : 2

*/
