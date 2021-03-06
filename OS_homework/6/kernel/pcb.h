#ifndef _PCB_H
#define _PCB_H

__asm__(".code16gcc");

struct Tss{
	short int SS;
	short int GS;
	short int FS;
	short int ES;
	short int DS;
	short int CS;
	short int DI;
	short int SI;
	short int BP;
	short int SP;
	short int DX;
	short int CX;
	short int BX;
	short int AX;
	int IP;
	short int Flags;
};

struct pcb{
	struct Tss tss;
	int process_status; // 0 is ready , 1 is runing,2 is done
	int process_id;
};

extern void screen_init();
extern void load_user( char, unsigned short int );
extern void saveall_reg();
extern void restore_reg();
extern void saveall_reg_seg();
extern void restore_reg_seg();
extern void init_flag_postion();
extern void print_welcome_msg();
extern void print_message();
extern void print_flag(); //root@wangqin4377@:   position


inline void sti(){
	__asm__("sti");
}

inline void cli(){
	__asm__("cli");
}


#define process_num_MAX  5
#define process_SEG  0

#endif

