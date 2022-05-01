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

/* Fns --- */

/*  REFERENCES: 
    adr. of pointer -> &SP
    adr. in stack being kept by SP -> SP

*/

int main() {
    printf("prepush -> %d\n", Stack[0]);
    printf("InitSP add -> %p\n", InitSP);
    printf("Stackpointer stack position -> %p\n", SP);

    Push(&SP, 12);

    printf("post push -> %d\n", Stack[0]);
    printf("InitSP add -> %p\n", InitSP);
    printf("Stackpointer stack position -> %p\n", SP);

    printf("last member should be -> %d\n", Pop(&SP));
    printf("last member should be -> %d\n", Pop(&SP));

    return 0;
}

void Push(int **SP, int val) {
    if (SizeofStack(*SP) >=100) {
        printf("ERROR: Overflow. No room left in the stack");
        return;
    }

    **SP = val; //set current top of stack to val
    *SP = *SP + 1; //move pointer to new top of stack
}

int Pop(int **SP) {
    if (SizeofStack(*SP) <= 0) {
        printf("ERROR: Underflow. Make sure the stack is populated before popping.\n");
        return -1;
    }

    *SP = *SP - 1; //move pointer back one
    return **SP; //return previous top of stack member
}

int SizeofStack(int *SP) {
    return SP - InitSP;
}