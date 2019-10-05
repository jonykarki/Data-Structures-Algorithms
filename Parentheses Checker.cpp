/*
Check if the parantheses have been used properly. Implemented using stacks.
Stack is implemented using array of max length 20 (maynot be enough :<)
*/

#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <string.h>

using namespace std;

#define MAX 20

int top = -1;
int stk[MAX];

void push(char);
char pop();
char peek();
bool isEmpty();
bool isFull();

/*
 * 
 */
int main() {
    for (;;) {
        top = -1;
        char exp[MAX], temp;
        int i, flag = 1;
        printf("Enter an expression : ");
        gets(exp);
        for (i = 0; i < strlen(exp); i++) {
            if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
                push(exp[i]);
            if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
                if (top == -1)
                    flag = 0;
                else {
                    temp = pop();
                    if (exp[i] == ')' && (temp == '{' || temp == '['))
                        flag = 0;
                    if (exp[i] == '}' && (temp == '(' || temp == '['))
                        flag = 0;
                    if (exp[i] == ']' && (temp == '(' || temp == '{'))
                        flag = 0;
                }
        }
        if (top >= 0)
            flag = 0;
        if (flag == 1)
            printf("Balanced\n");
        else
            printf("Not Balanced\n");
    }
    return 0;
}

void push(char c) {
    if (top == (MAX - 1)) {
        printf("Stack Overflow\n");
    } else {
        top = top + 1;
        stk[top] = c;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        return (stk[top--]);
    }
}

char peek() {
    if (top == -1) {
        return -1;
    } else {
        return (stk[top]);
    }
}

bool isEmpty() {
    return top < 0;
}

bool isFull() {
    return top == MAX - 1;
}