#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <unordered_set>
#define MAXCHAR 1500

//creating nodes
struct node
{
    float data;
    struct node *next;
};

struct node *start = NULL;

struct node *create_ll(struct node *);    //to create a node list function
struct node *display(struct node *);      // to display a node list function
struct node *insert_beg(struct node *);   // to insert node list function
struct node *insert_end(struct node *);   // to insert node at end list function
struct node *insert_after(struct node *); // to insert node after list function
struct node *delete_beg(struct node *);   // to delete node in the list function
struct node *delete_end(struct node *);   // to Delete a new value at the END of the list
struct node *delete_node(struct node *);  // to Delete a new node BEFORE a particular node
float maximum(struct node *start);        // to get value with decimal points
float minimum(struct node *start);
float mode(struct node *start);
float mean(struct node *start);
float median(struct node *start);
struct node *insertInOrder(struct node *start, float value);
int linked_list_length(struct node *start);
struct node *remove_duplicate(struct node *start);
float find_nth_element(struct node *start, int n);
struct node *sort_list(struct node *);

int main()
{
    start = create_ll(start);
    int option;
    display(start);
    do
    {
        // output display
        printf("\n\n *******  MAIN MENU   *******"); // printf() displays output inside quotation
        printf("\n 1:  Create a list");
        printf("\n 2:  Display the list");
        printf("\n 3:  Add a node at the beginning");
        printf("\n 4:  Add a node at the end");
        printf("\n 5:  Add a node after a given node");
        printf("\n 6:  Delete a node from the beginning");
        printf("\n 7:  To delete a node from the end");
        printf("\n 8:  To delete a given node");
        printf("\n 9:  To sort the list in ascending order");
        printf("\n 10: To find maximum ");
        printf("\n 11: To find minimum value");
        printf("\n 12: To find mean value");
        printf("\n 13: To find median value");
        printf("\n 14: To find mode value");
        printf("\n 15: To find range value");
        printf("\n 16: To remove Duplicate");
        printf("\n 17. Exit \n ");
        printf("Choose the number from 1-16 to perform the function or press 17 to exit: ");
        scanf("%d", &option);

        switch (option) // Using switch to display the message based on user's instructions
        {
        case 1:
            start = create_ll(start);
            printf("\n LINKED LIST CREATED");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;
        case 5:
            start = insert_after(start);
            break;
        case 6:
            start = delete_beg(start);
            break;
        case 7:
            start = delete_end(start);
            break;
        case 8:
            start = delete_node(start);
            break;
        case 9:
            int insert_value;
            printf("Enter the number to insert");
            scanf("%d", &insert_value);
            start = insertInOrder(start, insert_value);
            display(start);
            break;
        case 10:
            printf("Maximum is : %0.2f\n", maximum(start));
            break;
        case 11:
            printf("Minimum is: %0.2f\n", minimum(start));
            break;
        case 12:
            printf("Mean is: %0.2f\n", mean(start));
            break;
        case 13:
            printf("Median is: %0.2f\n", median(start));
            break;
        case 14:
            printf("mode is: %0.2f\n", mode(start));
            break;
        case 15:
            printf("Range is: %0.2f", maximum(start) - minimum(start));
            break;
        case 16:
            start = remove_duplicate(start);
            display(start);
            break;
        }
    }

    while (option != 17);
    //getch();
    return 0;
}

struct node *create_ll(struct node *start)
{

    struct node *new_node, *ptr;

    FILE *fn;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fn = fopen("test.txt", "r");
    if (fn == NULL)
    {
        printf("Couldnot find your file");
    }

    while ((read = getline(&line, &len, fn)) != -1) // to check if the line is empty
    {

        if (atof(line) != 0)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = atof(line);

            if (start == NULL)
            {
                new_node->next = NULL;
                start = new_node;
            }
            else
            {
                ptr = start;

                while (ptr->next != NULL)
                    ptr = ptr->next;
                ptr->next = new_node;
                new_node->next = NULL;
            }
        }
    }

    fclose(fn);
    return start;
}

// display the list to the console.
struct node *display(struct node *start)
{
    struct node *ptr; // to create a new node
    ptr = start;
    while (ptr != NULL)
    {
        printf("%0.2f \n", ptr->data); // print the tab first and then the value

        ptr = ptr->next;
    }
    return start;
}

// INSERTING AT THE BEGINING
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}

// INSERT AT THE END
struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    return start;
}

// INSERT AFTER A NODE CONTAINING A SPECIFIC VALUE
struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num); // to ask user an input
    printf("\n Enter the value after which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

// Function to DELETE THE FIRST NODE
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

// Function to DELETE THE LAST NODE
struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}

// Function to DELETE THE NODE
struct node *delete_node(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value of the node which has to be deleted : ");
    scanf("%d", &val);
    ptr = start;
    if (ptr->data == val)
    {
        start = delete_beg(start);
    }
    else
    {
        while (ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
    }
    return start;
}

// function to find the maximum from the  given list
float maximum(struct node *start)
{
    float max = 0;
    struct node *ptr1;
    ptr1 = start;
    while (ptr1->next != NULL)
    {
        if (ptr1->data > max)
        {
            max = ptr1->data;
        }
        ptr1 = ptr1->next;
    }
    if (ptr1->next == NULL)
    {
        if (ptr1->data > max)
        {
            max = ptr1->data;
        }
    }
    return max;
}

// function to find minimum value from a given list
float minimum(struct node *start)
{
    float min = 100000;
    struct node *ptr1;
    ptr1 = start;
    while (ptr1->next != NULL)
    {
        if (ptr1->data < min)
        {
            min = ptr1->data;
        }
        ptr1 = ptr1->next;
    }
    if (ptr1->next == NULL)
    {
        if (ptr1->data < min)
        {
            min = ptr1->data;
        }
    }
    return min;
}

//function to find mean value
float mean(struct node *start)
{
    float mean = 0;
    float sum = 0;

    struct node *ptr1;
    ptr1 = start;
    while (ptr1->next != NULL)
    {
        sum = sum + ptr1->data;
        ptr1 = ptr1->next;
    }
    if (ptr1->next == NULL)
    {
        sum = sum + ptr1->data;
    }
    mean = sum / linked_list_length(start);
    return mean;
}

// function to find median
float median(struct node *start)
{
    //sort the list
    int med_n = (linked_list_length(start) + 1) / 2;
    struct node *list = start;
    list = sort_list(list);
    float med = find_nth_element(list, med_n);
    return med;
}

// function to find mode
float mode(struct node *head)
{
    struct node *ptr = head;
    int count = 0;
    int max_count = 0;
    float roj = -1;
    while (ptr != NULL)
    {
        int count = 1;
        struct node *next1 = ptr->next;
        while (next1 != NULL)
        {
            if (ptr->data == next1->data)
                count++;
            next1 = next1->next;
        }
        if (count > max_count)
        {
            max_count = count;
            roj = ptr->data;
        }
        ptr = ptr->next;
        count++;
    }
    if (max_count >= count / 2)
    {
        return roj;
        return -1;
    }
}

int linked_list_length(struct node *start)
{
    int x = 0;
    struct node *ptr1;
    ptr1 = start;
    while (ptr1->next != NULL)
    {
        x = x + 1;
        ptr1 = ptr1->next;
    }
    if (ptr1->next == NULL)
    {
        x = x + 1;
    }
    return x;
}

//function to remove duplicate
struct node *remove_duplicate(struct node *start)
{
    struct node *previousNode = NULL;
    struct node *currentNode = start;

    std::unordered_set<float> elementsSet;

    while (currentNode != NULL)
    {
        if (elementsSet.find(currentNode->data) != elementsSet.end())
        {
            previousNode->next = currentNode->next;
            delete currentNode;
        }
        else
        {
            elementsSet.insert(currentNode->data);
            previousNode = currentNode;
        }
        currentNode = previousNode->next;
    }
    return start;
}

float find_nth_element(struct node *start, int n)
{
    int i = 1;
    struct node *ptr1;
    ptr1 = start;
    while (ptr1->next != NULL)
    {
        if (i == n)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        i = i + 1;
    }
    if (ptr1->next == NULL)
    {
        return ptr1->data;
    }
}

struct node *sort_list(struct node *)
{
    struct node *ptr1, *ptr2;
	int temp;
	ptr1 = start;
	while (ptr1->next != NULL)
	{
		ptr2 = ptr1->next;
		while (ptr2 != NULL)
		{
			if (ptr1->data > ptr2->data)
			{
				temp = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = temp;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return start;
}

// Function to insert to the linkedlist
struct node *insertInOrder(struct node *start, float value)
{
    
    struct node *ptr = start;
    //sort the list
    start = sort_list(start);

    struct node *value_to_add = (struct node *)malloc(sizeof(struct node));
    value_to_add->data = value;

    if (value < ptr->data)
    {
        value_to_add->next = start;
        start = value_to_add;
    }

    while (ptr != NULL)
    {
        if (value < ptr->next->data)
        {
            struct node *tmp = ptr->next;
            ptr->next = value_to_add;
            value_to_add->next = tmp;
        }
        ptr = ptr->next;
    }
    return start;
}
