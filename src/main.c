#include <stdio.h>
#include <stdbool.h> 

bool running = true;
int ip = 0;

//to implement a stack in c
int sp = -1;
int stack[256];


typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;

const int program[] = {
    PSH, 5,//pushes 5 to stack
    PSH, 6,//pushes 6 to stack
    ADD, //pops the two most top values on stack, adds them and pushes them
	//to stack
    POP, //pops value on stack
    HLT  //stops the program`
};

int fetch() {
    return program[ip];
}

void eval(int instr) {
    switch (instr) {
        case HLT: {
            running = false;
            break;
        }
        case PSH: {
            sp++;
            stack[sp] = program[++ip];
            break;
        }
    }
}

int main() {
    while (running) {
        eval(fetch());
        ip++; // increment the ip every iteration
    }
}

