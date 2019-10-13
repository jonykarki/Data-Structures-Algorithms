#include <iostream>
#include <stdio.h>
#include <malloc.h>

using namespace std;

// #a
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *add_new_node(struct node *);
struct node *insert_beg(struct node *);
struct node *delete_end(struct node *);
struct node *display(struct node *);
struct node *reverse_ll(struct node *);

int main()
{
    int option;
    do
    {
        printf("\nMain Menu\n");
        printf("1. Create a list\n");
        printf("2. Add a New Node\n");
        printf("3. Insert node at the begining\n");
        printf("4. Delete the last node\n");
        printf("5. Print the nodes of LL\n");
        printf("6. Reverse the linked list\n");
        printf("7. EXIT\n");
        printf("Enter your option:  ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_ll(start);
            printf("\nDoubly linked list created \n");
            break;
        case 2:
            start = add_new_node(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = delete_end(start);
            break;
        case 5:
            start = display(start);
            break;
        case 6:
            start = reverse_ll(start);
            break;
        }
    } while (option != 7);
    return 0;
}

struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data:  ");
    scanf("%d", &num);
    while (num != -1)
    {
        if (start == NULL)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->prev = NULL;
            new_node->data = num;
            start = new_node;
        }
        else
        {
            ptr = start;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = num;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }
        printf("\n Enter the data:  ");
        scanf("%d", &num);
    }
    return start;
}

// #b
struct node *add_new_node(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data to add to the linked list:  ");
    scanf("%d", &num);
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    new_node = (struct node *)malloc(sizeof(node));
    new_node->data = num;
    new_node->prev = ptr;
    ptr->next = new_node;
    new_node->next = NULL;
    return start;
}

// #c
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n Enter the data to enter to the linked list: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    start->prev = new_node;
    new_node->next = start;
    new_node->prev = NULL;
    start = new_node;
    return start;
}

// #d
struct node *delete_end(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    return start;
}

// #e
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d \t", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

struct node *reverse_ll(struct node *a_node)
{
    if (a_node == NULL){
        return NULL;
    }

    struct node * ptr = a_node -> next;
    a_node -> next = a_node -> prev;
    a_node -> prev = ptr;

    if (a_node->prev == NULL){
        return a_node;
    }

    return reverse_ll(a_node->prev);
}