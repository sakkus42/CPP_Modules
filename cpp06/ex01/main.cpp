#include "Serializer.hpp"

Data* XOR (Data *a, Data *b) { 
    uintptr_t ptrA = Serializer::serialize(a);
    uintptr_t ptrB = Serializer::serialize(b);
    Data* res = Serializer::deserialize(ptrA ^ ptrB);
    return res;
}

void insert(Data** node, int value) {
    Data* new_node = new Data{
        .value = value, 
        .both = *node
    };

    if (*node != NULL) {
        (*node)->both = XOR(new_node, (*node)->both);
    }

    *node = new_node;
}


void printList (Data *head) 
{ 
    Data *curr = head; 
    Data *prev = NULL; 
    Data *next; 
 
    std::cout << "XOR Linked List written:" << std::endl; 
 
    while (curr != NULL) 
    { 
        std::cout<<curr->value<<" "; 
        next = XOR (prev, curr->both);
        prev = curr; 
        curr = next; 
    } 
    std::cout << std::endl;
}

void printReverseList(Data* head) {
    Data *curr = head; 
    Data *prev = NULL; 
    Data *next; 
 
    std::cout << "XOR Linked List written in reverse order:" << std::endl; 
 
    while (curr != NULL) {
        next = XOR (prev, curr->both);
        prev = curr; 
        curr = next; 
    }
    curr = prev;
    while (curr != NULL){
        std::cout << curr->value << " ";
        prev = XOR (next, curr->both);
        next = curr;
        curr = prev; 
    }
     
}


int main() {
    Data* data = NULL;
    insert(&data, 10);
    insert(&data, 20);
    insert(&data, 30);
    printList(data);
    printReverseList(data);
    return 0;
}
