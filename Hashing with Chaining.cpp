#include <iostream>

using namespace std;

#define HASH_TABLE_SIZE 9

struct node
{
    int data;
    node *next;
};

int keys[8] = {7, 24, 18, 52, 36, 54, 11, 23};
struct node *HashTable[HASH_TABLE_SIZE] = {nullptr};

int hash_function(int value)
{
    return value % HASH_TABLE_SIZE;
}

void add_to_table(int value)
{
    int loc = hash_function(value);
    // check if there is already a linked list at that position
    if (HashTable[loc] == nullptr)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = NULL;
        HashTable[loc] = new_node;
    }
    else
    {
        struct node *current_node = HashTable[loc];
        while (current_node->next != NULL)
        {
            current_node = current_node->next;
        }
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = NULL;
        current_node->next = new_node;
    }
}

int main()
{
    int count = sizeof(keys) / sizeof(keys[0]);
    // add all the keys to the hash table
    for (int i = 0; i < count; i++)
    {
        add_to_table(keys[i]);
    }
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        cout << i << ": ";
        if (HashTable[i] != nullptr)
        {
            struct node *current_loc = HashTable[i];
            cout << current_loc->data;
            while (current_loc->next != NULL){
                cout << " -> ";
                current_loc = current_loc->next;
                cout << current_loc->data;
            }
        }
        cout << endl;
    }
}