/*
Generates random numbers and adds to the Circular Priority Queue. (Incomplete)
*/

#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

#define QMAX 10

int add_count = 0;

struct Queue {
    int front = -1, rear = -1;
    int queue_data[QMAX];
    string qname;
};

struct Queue *circular_q_one, *circular_q_two, *circular_q_three;

int generate_random_num(int min, int max) {
    return min + rand() % ((max + 1) - min);
}

int is_q_empty(struct Queue *q) {
    if (q->front == -1) return 1;
    return 0;
}

int is_q_full(struct Queue *q) {
    if ((q->front == q->rear + 1) || (q->front == 0 && q->rear == QMAX - 1)) return 1;
    return 0;
}

void add_to_q(struct Queue *q, int value) {
    if (is_q_full(q)) printf("\n Queue is full!! \n");
    else {
        if (q->front == -1) q->front = 0;
        q->rear = (q->rear + 1) % QMAX;
        q->queue_data[q->rear] = value;
        //cout << "Inserted " << value << " in " << q->qname << "\n";
    }
}

int remove_from_q(struct Queue *q) {
    int value;
    if (is_q_empty(q)) {
        cout << "Empty Queue\n"; 
        return (-1);
    } else {
        value = q->queue_data[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % 10;
        }
        cout << "Deleted element "  << value << "\n";
        return (value);
    }
}

void display_data(struct Queue *q) {
    cout << "Elements in " << q->qname << " ";
    cout << q->queue_data << "\n";
}

void display_status() {
    cout << "Status after " << add_count << " elements\n";
    if (is_q_empty(circular_q_one)) {
        cout << "Circular Queue One is empty \n";
    } else {
        display_data(circular_q_one);
    }
    
    if (is_q_empty(circular_q_two)) {
        cout << "Circular Queue two is empty\n";
    } else {
        display_data(circular_q_two);
    }
    
    if (is_q_empty(circular_q_three)) {
        cout << "Circular Queue three is empty\n";
    } else {
        display_data(circular_q_three);
    }
}

void add_to_q_helper(struct Queue *q, int value_to_add) {
    int dq_count = generate_random_num(1, 2) * 2;
    if (add_count < 6) {
        add_to_q(q, value_to_add);
        display_status();
    } 
    if (add_count == 6) {
        for (int j = 0; j < dq_count; j++) {
            //int value = remove_from_q(q);
        }
        add_to_q(q, value_to_add);
        display_status();
    } 
    if (add_count > 6) {
        if (add_count % 3 == 0) {
            for (int k = 0; k < dq_count; k++) {
                //remove_from_q(q);
            }
            add_to_q(q, value_to_add);
            display_status();
        } else {
            add_to_q(q, value_to_add);
        }
    }
    add_count = add_count + 1;
}

int main() {
    srand(static_cast<unsigned int> (time(0)));

    circular_q_one = (struct Queue *) malloc(sizeof (struct Queue));
    circular_q_one->qname = "Circular Queue 1";
    circular_q_two = (struct Queue *) malloc(sizeof (struct Queue));
    circular_q_two->qname = "Circular Queue 2";
    circular_q_three = (struct Queue *) malloc(sizeof (struct Queue));
    circular_q_three->qname = "Circular Queue 3";

    while (1) {
        int priority = generate_random_num(1, 3);
        int value_to_add = generate_random_num(100, 999);

        if (priority == 1) {
            add_to_q_helper(circular_q_one, value_to_add);
        } else if (priority == 2) {
            add_to_q_helper(circular_q_two, value_to_add);
        } else if (priority == 3) {
            add_to_q_helper(circular_q_three, value_to_add);
        }
    }

    return 0;
}

