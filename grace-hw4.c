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


int main() {
    int input; //for tracking input values

    printf("Stack Tracker v0.1\n\n");
    printf("Please enter an option (or [-1] to quit): ");
    scanf("%d", &input);

    while (input != -1) {
        switch (input) {
            case 0: //push
                printf("What value would you like to push to stack?: ");
                scanf("%d", &input);
                Push(&SP, input);
                printf("%d pushed to stack.\n\n", input);

                break;
            case 1: //pop
                printf("Popped of item: %d\n\n", Pop(&SP));

                break;
            case 2: //instack
                printf("What value would you like to search for?: ");
                scanf("%d", &input);
                if (Instack(SP, input)) {
                    printf("%d is in the stack.\n", input);
                } else {
                    printf("I couldn't find %d in the stack.\n", input);
                }

                break;
            case 3: //sizeofstack
                printf("Size of stack is %d.\n", SizeofStack(SP));
                break;
            case 4: //printstack
                PrintStack(SP);

                break;
            case 5: //peek
                Peek(SP);

                break;
            default:
                printf("I don't understand that command. Please refer to documentation.\n");
        }
        printf("Please enter an option (or [-1] to quit): ");
        scanf("%d", &input);
    }

    printf("Goodbye\n");
    return 0;
}

void Push(int **SP, int val) {
    if (SizeofStack(*SP) >=100) {
        printf("ERROR: Overflow. No room left in the stack.\n");
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

int Instack(int *SP, int val) {
    int **tempSP = &SP;

    while (SizeofStack(*tempSP) > 0) {
        *tempSP = *tempSP - 1;
        
        if (val == **tempSP) return 1;
    }

    return 0;
}

int SizeofStack(int *SP) {
    return SP - InitSP;
}

void Peek(int *SP) { //Pop but moves pointer back
    printf("Last item pushed to stack was %d.\n\n", Pop(&SP));
    *SP = *SP + 1;
}

void PrintStack(int *SP) {
    int **tempSP = &SP;
    
    printf("Your stack:\n\n");

    while (SizeofStack(*tempSP) > 0) {
        *tempSP = *tempSP - 1;
        printf("Stack[%d] is %d\n", SizeofStack(*tempSP), **tempSP);
    }
    printf("\n");
}
