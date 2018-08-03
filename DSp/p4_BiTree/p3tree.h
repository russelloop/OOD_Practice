#include <stdio.h>
#include <stdlib.h>

//预定义常量
#define TRUE 		1
#define FALSE		0
#define OK			1
#define ERROR 		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

//函数结果的类型
typedef int Status;

//------------- ch6 --------------------------------
#define MAX_TREE_SIZE 	100
#define MAX_TREE_LEVEL	5
#define PADDING			3 // 显示结点时所需间隔的字符数，建议设为2-5间的自然数
typedef char TElemType;
//-------------二叉树的二叉存储表示-----------------
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
typedef struct BTNodeWithLevel{
	BiTree node;
	int level;
	char parentTag; // ' '父为空, '\\'右子树, '/'左子树
}*BTWithLevel;
bool QueueEmpty();
void EnQueue(BTWithLevel n);
void DeQueue(BTWithLevel &n);
bool StackEmpty();
void Push(BiTree n);
void Pop(BiTree &n);
Status Create_BiTree(BiTree &rt); //*TBD1* 根据输入的先序序列创建二叉树rt
void LDR(BiTree rt);		// 递归地中序遍历
void inOrder(BiTree rt);	// 非递归地中序遍历
void DLR(BiTree rt);
void preOrder(BiTree rt);	//*TBD2* 非递归的先序遍历(题集P42 6.37)
void LRD(BiTree rt);
int countOfLeaves(BiTree rt); // 递归计算叶子结点数目(题集P42 6.42)
void level(BiTree rt);		//*TBD3* 层次遍历(题集P42 6.47)
void hierachyOf(BiTree rt);
//-------------二叉树的二叉线索存储表示-------------
typedef enum PointerTag { Link, Thread }; 
typedef struct BiThrNode{
   TElemType data;
   struct BiThrNode *lchild, *rchild;
   PointerTag LTag, RTag;
}BiThrNode, *BiThrTree;
Status Create_BiThrTree(BiThrTree &rt);
BiThrNode *New_BiThrTree();
void LDR(BiThrTree rt);  //中序遍历没有线索化的二叉树
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T); //*TBD4* 中序遍历二叉树T，将其线索化，Thrt指向头结点
Status InOrderTraverse_Thr(BiThrTree Thrt); //*TBD5* 中序遍历线索化二叉树，Thrt的左指针指向头结点
void InThreading(BiThrTree p);

