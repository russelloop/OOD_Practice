//------Head files for list in chapter 2 --------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//Ԥ���峣��
#define TRUE 		1
#define FALSE		0
#define OK			1
#define ERROR 		0
#define INFEASIBLE	-1
#define OVERFLOW	-2
#define GUARD	-99
#define MAXLEN 255          //���Ա�(˳���)����󳤶�
#define LIST_MAX_SIZE	50  //�������󳤶�

//�������������
typedef int Status;

typedef int ElemType;

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
} SqList;

typedef struct List {
	int elem[MAXLEN];
	int length;
} List;

typedef unsigned char SString[MAXLEN + 1];

typedef int ElemType;
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;

//---------- p1list.cpp ---------------------------------------------
void InitList(List &L); //* �˺������ڳ�ʼ��һ��������������Ա�L
void InitList0(List &L); //* �˺������ڳ�ʼ��һ�����Ա�L
void printList(List L);
void createTwoLists(List &La, List &Lb);
void MergeList(List La, List Lb, List &Lc); //*TBD1* ��Lb�鲢��La���γ��±�Lc
void Union(List &La, List Lb); //*TBD2* ����La��Lb�ֱ��ʾ�������ϣ����¼���La��La U Lb�� U"��"������
void ReverseList(List &L); //*TBD3* �����Ա�L��ת
void deleteall(List &L, int x, int y); //*TBD4* ��һ������˳���L��ɾ��Ԫ��ֵ��x��y֮�������Ԫ��(x<= y)

//--------- lottery.cpp ----------------------------------------------
void build(LinkList &L, int size); //*TBD1* �Ҹ���-��ʼ��ѭ������L
void display(LinkList L); //*TBD1* �׸���-����Ļ���������L������
void select10(LinkList &L); //*TBD2* �Ҹ���-ʵ��������Ʊ��10ѡ7��
void select36(LinkList &L); //*TBD2* �׸���-ʵ��������Ʊ��36ѡ7��
void freeList(LinkList &L); //*TBD3* �׸���-�ͷų�ʼ������L��ʹ�õ��ڴ�
void mainlottery(); //*TBD3* �Ҹ���-ʵ��������

//--------- LinkedList.cpp --------------------------------------------
Status CreateList_L(LinkList &L, int n); //����β�巨����һ����ͷ���ĳ���Ϊn�ĵ�����L
Status CreateList_L_NoHead(LinkList &L, int n); //����β�巨����һ����ͷ���ĳ���Ϊn�ĵ�����L
void printList_L(LinkList L); //�����ͷ���ĵ�����L
void printList_L_NoHead(LinkList L); //�������ͷ���ĵ�����L
Status GetElem_L(LinkList L, int i, ElemType &e);
Status ListInsert_L(LinkList &L, int i, ElemType e);
Status ListDelete_L(LinkList &L, int i, ElemType &e);
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc);
void deleteallnodes(LinkList &L, ElemType min, ElemType max);
void ChangeLinkList01J(LinkList &L);
Status reorder5(LinkList &L);

//--------- p1list.cpp [��2-2-12] -----------------------------------
void deleteall_1(List *L, int x);
void deleteall_2(List *L, int x);
void deleteall_3(List *L, int x);