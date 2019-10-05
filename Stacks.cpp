/*
 * Decimal Number Connversion to Other number systems with base N.
 * Implemented using Stacks.
 */

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <malloc.h>
#include <string>

using namespace std;

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top = NULL;
struct stack *push(struct stack *, int);
struct stack *pop(struct stack *);
int peek(struct stack *);
struct stack *display(struct stack *);

void conversion(int, int);

int main()
{
    int decimal_num, conversion_base;
    cout << "Please enter a Decimal Number: ";
    cin >> decimal_num;
    cout << "Please enter the conversion base: ";
    cin >> conversion_base;
    conversion(decimal_num, conversion_base);
    cout << "Your base " << conversion_base << " of the number " << decimal_num << " is : ";
    display(top);
    return 0;
}

struct stack *push(struct stack *top, int val)
{
    struct stack *ptr;
    ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = val;
    if (top == NULL)
    {
        ptr->next = NULL;
        top = ptr;
    }
    else
    {
        ptr->next = top;
        top = ptr;
    }
    return top;
}

struct stack *pop(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if (top == NULL)
        printf("\n STACK UNDERFLOW");
    else
    {
        top = top->next;
        free(ptr);
    }
    return top;
}

int peek(struct stack *top)
{
    if (top == NULL)
    {
        return -1;
    }
    else
    {
        return top->data;
    }
}

struct stack *display(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if (top == NULL)
        printf("\n STACK IS EMPTY");
    else
    {
        while (ptr != NULL)
        {
            int dat = ptr->data;
            if (dat > 9)
            {
                cout << (char)(dat+55);
            } else {
                cout << dat;
            }
            ptr = ptr->next;
        }
    }
    return top;
}

void conversion(int decimal_num, int conversion_base)
{
    int remainder, quotient;
    quotient = 1;
    while (quotient != 0)
    {
        quotient = decimal_num / conversion_base;
        remainder = decimal_num % conversion_base;
        top = push(top, remainder);
        decimal_num = quotient;
    }
}
