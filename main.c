#include<stdio.h>
#include<stdbool.h>
#include"constants.c"

typedef struct cat8 cat8;
struct cat8{
	byte mem[MAX];
	byte prog[MAX];
	byte pc;
};

cat8 empty_cat8(){
	cat8 m;
	for(int i = 0; i < MAX; i++){
		m.mem[i] = 0;
		m.prog[i] = 0;
	}
	m.pc = 0;
	return m;
}

int step_cat8(cat8 *m){
	byte A = m->prog[m->pc + 1];
	byte B = m->prog[m->pc + 2];
	switch(m->prog[m->pc]){
		case OP_EXIT: return 0;
		case OP_MOVL: m->mem[A] = B; break;
		case OP_MOV: m->mem[A] = m->mem[B]; break;
		case OP_DEREF: m->mem[A] = m->mem[m->mem[A]]; break;
		case OP_JMP: m->pc = A; m->pc--; break;
		case OP_CJMP: if(m->mem[B]) m->pc = A; break;
		case OP_AND: m->mem[A] = m->mem[A] & m->mem[B]; break;
		case OP_OR: m->mem[A] = m->mem[A] | m->mem[B]; break;
		case OP_NOT: m->mem[A] = !(m->mem[A]); m->pc--; break;
		case OP_ADD: m->mem[A] = m->mem[A] + m->mem[B]; break;
		case OP_SUB: m->mem[A] = m->mem[A] - m->mem[B]; break;
		case OP_MUL: m->mem[A] = m->mem[A] * m->mem[B]; break;
		case OP_DIV: m->mem[A] = m->mem[A] / m->mem[B]; break;
	}
	m->pc += 3;
	return 1;
}

byte run_cat8(cat8 *m, bool debug){
	int running = 1;
	while(running) {
		running = step_cat8(m);
		if(debug){
			for(int i = 0; i < 10; i++){
				printf("%d", m->mem[i]);
			}
		}
	}
}

int main(void){
	cat8 m = empty_cat8();
	printf("Hello, world!\n");
	return 0;
}