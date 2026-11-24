#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

typedef int infotype;
const int MAKS = 5;

struct queue{
    infotype info[MAKS];
    int head;
    int tail;
};

void CreateQueue(queue &Q);
bool isEmptyQueue(queue Q);
bool isFullQueue(queue Q);
void enqueue(queue &Q, infotype x);
void dequeue(queue &Q);
void printInfo(queue Q);

#endif