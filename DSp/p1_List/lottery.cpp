//------Head files for list in chapter 2 --------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//预定义常量
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
#define GUARD   -99
#define MAXLEN 255          //线性表(顺序表)的最大长度
#define LIST_MAX_SIZE   50  //链表的最大长度

//函数结果的类型
typedef int Status;
typedef int ElemType;

typedef int ElemType;
typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

void build(LinkList &L, int size); //*TBD1* 乙负责-初始化循环链表L
void display(LinkList L); //*TBD1* 甲负责-在屏幕上输出链表L的内容
void select10(LinkList &L); //*TBD2* 乙负责-实现体育彩票（10选7）
void select36(LinkList &L); //*TBD2* 甲负责-实现体育彩票（36选7）
void freeList(LinkList &L); //*TBD3* 甲负责-释放初始化链表L所使用的内存
void mainlottery(); //*TBD3* 乙负责-实现主函数

/*TBD1* 乙负责-初始化循环链表L
 *TBD1* 其中size为其大小
 *TBD1*/
void build(LinkList &L, int size){
    LinkList pf, p;
    int i;
    //[1]创建表L的头结点
    L=(LinkList)malloc(sizeof(LNode));
    L->data = size;
    L->next = NULL;
    pf = L;
    for (i = 0; i < size; i++) {
        //[2]创建新结点p，与它的前驱结点pf链接
        p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
        p->next = pf->next;
        pf->next = p;
        pf = p;
    }
    pf->next = L->next;
}

/*TBD1* 甲负责-在屏幕上输出链表L的内容
 *TBD1*/
void display(LinkList L){
    LNode *p=L;
    printf("单链表的内容：\n");
    for(int k = 0; k < 10; k++) {
        printf("[%d]-->", p->data);
        p=p->next;
    }
    printf("\n");
}

/*TBD2* 乙负责-实现体育彩票（10选7）
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
        printf("第\"%d\"个数为%d。\n", j, p->data);
    }
}

/*TBD2* 甲负责-实现体育彩票（36选7）
 *TBD2*/
void select36(LinkList &L) {
    LNode *p=L;
    srand(time(NULL));
    int k;//取值次数循环计数
    int j = 0;//随机取值循环计数
	int i;//检查数组对比循环计数
	bool same = false;//判断是否重复
	int selected[7] = {0,0,0,0,0,0,0};
	do{
		int time = rand();
		for(k = 0; k < time; k++){		//循环数组中随机取值
			p = p->next;
		}

		for(i = 0; i <= j; i++){		//检查是否取过同样的数
			if(p->data == selected[i]){	//若取过，则赋值same为1代表找到，不继续寻找
				same = true;
				break;
			}
		}

		if(!same){					//如果成功通过上面的检查循环
			printf("第\"%d\"个数为%d。\n", j, p->data);
			selected[j] = p->data;		//将取值成功的存入新数组用于下一次检查
			j++;
		}
	//否则说明重复，重新开始循环，重新取值
	}while(j <= 7);//确保取出7个不相同的值后退出循环
}

/*TBD3* 甲负责-释放初始化链表L所使用的内存
 *TBD3*/
void freeList(LinkList &L) {

}

/*TBD3* 乙负责-实现主函数
 *TBD3*/
void mainlottery() {
    LinkList LLa;
	int select = 1;
	printf("欢迎使用彩票抽奖系统\n");
	printf("输入1使用10选7可重复彩票\n");
	printf("输入2使用36选7不重复彩票\n");
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
			printf("无此选项\n");
			break;
	}
    getchar();
}

int main(){
    
    mainlottery();

    return 0;
}