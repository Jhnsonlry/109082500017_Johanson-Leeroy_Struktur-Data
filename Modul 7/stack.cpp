#include "stack.h"

void CreateStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top == 19) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";

        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }

        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        int i = 0;
        int j = S.top;

        while (i < j) {
            infotype temp = S.info[i];
            S.info[i] = S.info[j];
            S.info[j] = temp;

            i++;
            j--;
        }
    }
}

void pushAscending(Stack &S, int x) {
    if (S.top == 19) {
        cout << "Stack penuh!" << endl;
    } else {
        int i = S.top;

        while (i >= 0 && S.info[i] > x) {
            S.info[i + 1] = S.info[i];
            i--;
        }

        S.info[i + 1] = x;
        S.top++;
    }
}



void getInputStream(Stack &S) {
    char input;
    while (true) {
        input = cin.get();

        if (input == '\n') {
            break;
        }

        if (input >= '0' && input <= '9') {
            if (S.top == 19) {
                cout << "Stack penuh!" << endl;
                break;
            }

            push(S, input - '0');
        }
    }
}