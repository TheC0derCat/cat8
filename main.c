#include<stdio.h>
#include"constants.c"

typedef struct cat8 cat8;
struct cat8{
	byte mem[255];
	byte prog[255];
	byte pc;
};

byte step_cat8(cat8 *m){
	byte A = m->prog[m->pc + 1];
	byte B = m->prog[m->pc + 2];
	switch(m->prog[m->pc]){
		case OP_EXIT: return 1;
		case OP_MOVL: m->mem[A] = B; break;
		case OP_MOV: m->mem[A] = m->mem[B]; break;
		case OP_DEREF: m->mem[A] = m->mem[m->mem[A]]; break;
		case OP_JMP:
		case OP_CJMP: 
		case OP_AND:
		case OP_OR:
		case OP_NOT:
		case OP_ADD:
		case OP_SUB:
		case OP_MUL:
		case OP_DIV:
	}
	return 0;
}

byte run_cat8(cat8 m){
}

int main(void){
	printf("Hello, world!\n");
	return 0;
}