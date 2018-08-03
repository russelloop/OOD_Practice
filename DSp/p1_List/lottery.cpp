//------Head files for list in chapter 2 --------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//Ԥ���峣��
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
#define GUARD   -99
#define MAXLEN 255          //���Ա�(˳���)����󳤶�
#define LIST_MAX_SIZE   50  //�������󳤶�

//�������������
typedef int Status;
typedef int ElemType;

typedef int ElemType;
typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

void build(LinkList &L, int size); //*TBD1* �Ҹ���-��ʼ��ѭ������L
void display(LinkList L); //*TBD1* �׸���-����Ļ���������L������
void select10(LinkList &L); //*TBD2* �Ҹ���-ʵ��������Ʊ��10ѡ7��
void select36(LinkList &L); //*TBD2* �׸���-ʵ��������Ʊ��36ѡ7��
void freeList(LinkList &L); //*TBD3* �׸���-�ͷų�ʼ������L��ʹ�õ��ڴ�
void mainlottery(); //*TBD3* �Ҹ���-ʵ��������

/*TBD1* �Ҹ���-��ʼ��ѭ������L
 *TBD1* ����sizeΪ���С
 *TBD1*/
void build(LinkList &L, int size){
    LinkList pf, p;
    int i;
    //[1]������L��ͷ���
    L=(LinkList)malloc(sizeof(LNode));
    L->data = size;
    L->next = NULL;
    pf = L;
    for (i = 0; i < size; i++) {
        //[2]�����½��p��������ǰ�����pf����
        p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
        p->next = pf->next;
        pf->next = p;
        pf = p;
    }
    pf->next = L->next;
}

/*TBD1* �׸���-����Ļ���������L������
 *TBD1*/
void display(LinkList L){
    LNode *p=L;
    printf("����������ݣ�\n");
    for(int k = 0; k < 10; k++) {
        printf("[%d]-->", p->data);
        p=p->next;
    }
    printf("\n");
}

/*TBD2* �Ҹ���-ʵ��������Ʊ��10ѡ7��
 *TBD2*/
void select10(LinkList &L) {
    LNode *p=L;
    srand(time(NULL));
    int k;
    int j;
    for(j = 1; j < 8; j++){
        int time = rand();
        for(k = 0; k < time; k++){
            p = p->next;
        }
        printf("��\"%d\"����Ϊ%d��\n", j, p->data);
    }
}

/*TBD2* �׸���-ʵ��������Ʊ��36ѡ7��
 *TBD2*/
void select36(LinkList &L) {
    LNode *p=L;
    srand(time(NULL));
    int k;//ȡֵ����ѭ������
    int j = 0;//���ȡֵѭ������
	int i;//�������Ա�ѭ������
	bool same = false;//�ж��Ƿ��ظ�
	int selected[7] = {0,0,0,0,0,0,0};
	do{
		int time = rand();
		for(k = 0; k < time; k++){		//ѭ�����������ȡֵ
			p = p->next;
		}

		for(i = 0; i <= j; i++){		//����Ƿ�ȡ��ͬ������
			if(p->data == selected[i]){	//��ȡ������ֵsameΪ1�����ҵ���������Ѱ��
				same = true;
				break;
			}
		}

		if(!same){					//����ɹ�ͨ������ļ��ѭ��
			printf("��\"%d\"����Ϊ%d��\n", j, p->data);
			selected[j] = p->data;		//��ȡֵ�ɹ��Ĵ���������������һ�μ��
			j++;
		}
	//����˵���ظ������¿�ʼѭ��������ȡֵ
	}while(j <= 7);//ȷ��ȡ��7������ͬ��ֵ���˳�ѭ��
}

/*TBD3* �׸���-�ͷų�ʼ������L��ʹ�õ��ڴ�
 *TBD3*/
void freeList(LinkList &L) {

}

/*TBD3* �Ҹ���-ʵ��������
 *TBD3*/
void mainlottery() {
    LinkList LLa;
	int select = 1;
	printf("��ӭʹ�ò�Ʊ�齱ϵͳ\n");
	printf("����1ʹ��10ѡ7���ظ���Ʊ\n");
	printf("����2ʹ��36ѡ7���ظ���Ʊ\n");
	scanf("%d", &select);
	switch(select){
		case 1:
			build(LLa, 10);
			select10(LLa);
			break;
		case 2:
			build(LLa, 36);
			select36(LLa);
			break;
		default:
			printf("�޴�ѡ��\n");
			break;
	}
    getchar();
}

int main(){
    
    mainlottery();

    return 0;
}