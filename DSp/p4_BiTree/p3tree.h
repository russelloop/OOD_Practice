#include <stdio.h>
#include <stdlib.h>

//Ԥ���峣��
#define TRUE 		1
#define FALSE		0
#define OK			1
#define ERROR 		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

//�������������
typedef int Status;

//------------- ch6 --------------------------------
#define MAX_TREE_SIZE 	100
#define MAX_TREE_LEVEL	5
#define PADDING			3 // ��ʾ���ʱ���������ַ�����������Ϊ2-5�����Ȼ��
typedef char TElemType;
//-------------�������Ķ���洢��ʾ-----------------
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
typedef struct BTNodeWithLevel{
	BiTree node;
	int level;
	char parentTag; // ' '��Ϊ��, '\\'������, '/'������
}*BTWithLevel;
bool QueueEmpty();
void EnQueue(BTWithLevel n);
void DeQueue(BTWithLevel &n);
bool StackEmpty();
void Push(BiTree n);
void Pop(BiTree &n);
Status Create_BiTree(BiTree &rt); //*TBD1* ����������������д���������rt
void LDR(BiTree rt);		// �ݹ���������
void inOrder(BiTree rt);	// �ǵݹ���������
void DLR(BiTree rt);
void preOrder(BiTree rt);	//*TBD2* �ǵݹ���������(�⼯P42 6.37)
void LRD(BiTree rt);
int countOfLeaves(BiTree rt); // �ݹ����Ҷ�ӽ����Ŀ(�⼯P42 6.42)
void level(BiTree rt);		//*TBD3* ��α���(�⼯P42 6.47)
void hierachyOf(BiTree rt);
//-------------�������Ķ��������洢��ʾ-------------
typedef enum PointerTag { Link, Thread }; 
typedef struct BiThrNode{
   TElemType data;
   struct BiThrNode *lchild, *rchild;
   PointerTag LTag, RTag;
}BiThrNode, *BiThrTree;
Status Create_BiThrTree(BiThrTree &rt);
BiThrNode *New_BiThrTree();
void LDR(BiThrTree rt);  //�������û���������Ķ�����
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T); //*TBD4* �������������T��������������Thrtָ��ͷ���
Status InOrderTraverse_Thr(BiThrTree Thrt); //*TBD5* ���������������������Thrt����ָ��ָ��ͷ���
void InThreading(BiThrTree p);

