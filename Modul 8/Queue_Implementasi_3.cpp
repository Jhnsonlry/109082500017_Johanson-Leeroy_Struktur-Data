#include "Queue.h"

void CreateQueue(queue &Q)
{
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(queue Q)
{
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

bool isFullQueue(queue Q)
{
    if((Q.tail + 1) % MAKS == Q.head){
        return true;
    } else {
        return false;
    }
}  

void enqueue(queue &Q, infotype x)
{
    if(isFullQueue(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmptyQueue(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKS;
        }
        Q.info[Q.tail] = x;
    }
}
void dequeue(queue &Q)
{
    if(isEmptyQueue(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(Q.head == Q.tail){
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKS;
        }
    }
}
void printInfo(queue Q)
{
    cout << Q.head << " - " << Q.tail << "\t | ";

    if(isEmptyQueue(Q) == true){
        cout << "empty queue";
    } else {
        int i = Q.head;

        while(true){
            cout << Q.info[i] << " ";

            if(i == Q.tail){
                break;
            }

            i = (i + 1) % MAKS;
        }
    }

    cout << endl;
}