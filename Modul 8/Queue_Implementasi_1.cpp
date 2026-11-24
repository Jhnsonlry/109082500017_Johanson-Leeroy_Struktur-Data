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
    if(Q.tail == MAKS - 1){
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
        if(isEmptyQueue(Q) == true)
        {
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}
void dequeue(queue &Q)
{
    if(isEmptyQueue(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = 0; i < Q.tail; i++){
            Q.info[i] =  Q.info[i+1];
        }
        Q.tail--;
        if(Q.tail < 0)
        {
            Q.head = -1;
            Q.tail = -1;
        }
    }
}
void printInfo(queue Q)
{
    cout << Q.head << " - " << Q.tail << "\t | ";

    if(isEmptyQueue(Q) == true){
        cout << "empty queue";
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}