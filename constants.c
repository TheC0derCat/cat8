#define OP_EXIT 0 // EXIT immediatly exits the program, ignroing all proceeding bytes including what would be its operands
#define OP_MOVL 1 // "MOVL 2 1 " moves the litteral value "1" into address 2
#define OP_MOV 2 // "MOV 2 1" moves the value from the adress 1 into address 2
#define OP_DEREF 3 // "DEREF 2 1" treats the value at address 1 as a pointer, ands puts the value its pointing to at address 2