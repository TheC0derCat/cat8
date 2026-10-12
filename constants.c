typedef unsigned char byte;

#define MAX 255

#define OP_EXIT 0 // EXIT exits the program, returning its first operand
#define OP_MOVL 1 // "MOVL 2 1 " moves the litteral value "1" into address 2
#define OP_MOV 2 // "MOV 2 1" moves the value from the adress 1 into address 2
#define OP_DEREF 3 // "DEREF 2 1" treats the value at address 1 as a pointer, ands puts the value its pointing to at address 2
#define OP_JMP 4 // "JMP 2" sets program counter to the value at address 2
#define OP_CJMP 5 // "CJMP 2 1" sets program counter to the value at address 2 if the value at address 1 is not zero
#define OP_AND 6 // "AND A B" A = A & B
#define OP_OR 7 // "OR A B" A = A | B
#define OP_NOT 8 // "NOT A" A = !A
#define OP_ADD 9 // "ADD A B" A = A + B
#define OP_SUB 10 // "SUB A B" A = A - B
#define OP_MUL 11 // "MUL A B" A = A * B
#define OP_DIV 12 // "DIV A B" A = A / B