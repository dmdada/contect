#ifndef _HEAD_
#define _HEAD_
#define  _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
#include<windows.h>


#define NUM  5
#define NUM1 3


enum
{
	EXIT,
	ADD,
	DEL,
	FIND,
	CHANGE,
	SHOW,
	CLS,
	PAIXU,
	FILEWRITE,
	FILEREAD,
	MOD_FILE,
	LOAD,
};
typedef struct S
{
	char name[10];
	char sex[5];
	int  age;
	char tele[20];
	char addr[20];
} S;

typedef struct 
{
	S *human;
	int capacity;
	int sz;
}contact, *pcon;


void menu();
void test();
void init_contest(pcon contest);
void Add_count(pcon contest);
void Dle_count(pcon contest);
int search(pcon contest);
void Show_count(pcon contest);
void Find_count(pcon contest);
void Change_count(pcon contest);
void Cls_count(pcon contest);
void Paixu_count(pcon contest);
void check_capacity(pcon contest);
void free_mem(pcon contest);
void write_file(pcon contect);
//文件读取
void read_file(pcon contect);
//修改文件
void mod_file(pcon contect, char* name, int flag);
void loadfile(pcon contect);

#endif