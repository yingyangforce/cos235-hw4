/* 
/  COS235 - HW4
/
/  Isaiah Grace
*/

#include <stdio.h>

void Push(int **SP, int val);
int Pop(int **SP);
int Instack(int *SP, int val);
int SizeofStack(int *SP);
void Peek(int *SP);
void PrintStack(int *SP);

int Stack[100];
int *SP = Stack;            //Moving stack pointer
const int *InitSP = Stack;  //Pointer to start of stack

//Fns ---

int main() {
    printf("prepush -> %d\n", Stack[0]);
    printf("Stackpointer add -> %p\n", &SP);
    printf("Stackpointer val -> %p\n", SP);
    Push(&SP, 12);
    printf("post push -> %d\n", Stack[0]);
    printf("Stackpointer add -> %p\n", &SP);
    printf("Stackpointer val -> %p\n", SP);
    return 0;
}

void Push(int **SP, int val) {
    **SP = val; //set current top of stack to val
    *SP = *SP + 1; //move pointer to new top of stack
}

