//------Head files for string and list --------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Ԥ���峣��
#define TRUE 		1
#define FALSE		0
#define OK			1
#define ERROR 		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

//�������������
typedef int Status;

#define GUARD	-99
#define MAXLEN 255          //���Ա�(˳���)����󳤶�

typedef unsigned char SString[MAXLEN + 1]; //SString[0]Ϊ���ĳ���

void initSStrings(SString &S, SString &T);
void initSString(SString &S);
void printSString(SString S, bool tag);
int Index(SString S, SString T, int pos);
void get_next(SString T, int next[]);
void get_nextval(SString T, int nextval[]);
int Index_KMP(SString S, SString T, int pos);
int mainSString();