#include <p3tree.h>
#include <ctype.h>
#include <string.h>

BTWithLevel queue[MAX_TREE_SIZE];
int front=0, rear=0;
BiTree stack[MAX_TREE_SIZE];
int top=0;

/*TBD1* ���ݰ������������������Ľ��ֵ����ĸ��С�����ʾ������������������rt
 *TBD1* �����������: abc..de.g..f..., �����Ķ���������P127ͼ6.8(b)��ʾ
 *TBD1*/
Status Create_BiTree(BiTree &rt) {
    char ch;
    scanf("%c", &ch);
    if(ch == '')
        T = NULL;
    else{
        if(!(T = (BiTNode *)malloc(sizeof(BiTNode))))exit(OVERFLOW);
        T->data = ch;
        Create_BiTree(T->lchild);
        Create_BiTree(T->rchild);
    }
    return OK;
}

//*TBD2* �ǵݹ���������(�⼯P42 6.37)
void preOrder(BiTree rt) {
    BiTree p;
    printf("���������");
    p = rt;
    while(p || !StackEmpty()){//p�ǿջ�ջ�ǿ�
        if(p){
            //���ʸýڵ�
            printf("%c", p->data);
            //���ʺ���ջ
            Push(p);
            //һ·����
            p = p->lchild;
        }
        else{
            Pop(p);
            p = p->rchild;
        }
    }
    printf("\r\n");
}


	//*TBD3* ��α���(�⼯P42 6.47)
// ע��hierachyOf(BiTree)��hierachyOf1(BiTree)�ı���˼·�������ͬ
void level(BiTree rt){
    BTWithLevel q,p;
    printf("��α�����");
    q = (BTWithLevel)malloc(sizeof(struct BTNodeWithLevel));
    p = (BTWithLevel)malloc(sizeof(struct BTNodeWithLevel));
    q->node = rt;
    EnQueue(q);
    while(!QueueEmpty()){
        DeQueue(q);
        printf("%c", q->node->data);
        if(q->node->lchild){
            p = (BTWithLevel)malloc(sizeof(struct BTNodeWithLevel));
            p->node = q->node->lchild;
            EnQueue(p);
        }
        if(q->node->rchild){
            p = (BTWithLevel)malloc(sizeof(struct BTNodeWithLevel));
            p->node = q->node->rchild;
            EnQueue(p);
        }
    }
}



// �ݹ����Ҷ�ӽ����Ŀ(�⼯P42 6.42)
int countOfLeaves(BiTree rt) {
	if (rt==NULL) return 0;
	if ((rt->lchild==NULL)&&(rt->rchild==NULL)) return 1;
	   else return (countOfLeaves(rt->lchild) + countOfLeaves(rt->rchild));
}

// �ݹ���������
void LDR(BiTree rt) {
	if (rt==NULL) return;
	LDR(rt->lchild);
	printf("%c", rt->data);
	LDR(rt->rchild);
}

// �ǵݹ���������
void inOrder(BiTree rt) {
	BiTree p;
	printf("�������: ");
	p = rt;
	while (p||!StackEmpty()) {//p�ǿջ�ջ�ǿ�
		//1.�����֧���£����������ڲ������ջ��ֱ��������Ϊ�յĽ��
		if (p) {
			Push(p);
			p = p->lchild;
		}
		else {
			//2.���ʸý��(p==NULL)
			Pop(p);
			printf("%c", p->data);
			//3.���ʸý���������ĸ����ظ���1
			p = p->rchild; 
		}
	}
	printf("\r\n");
}


// ����Ļ����ʾ������root�Ľṹʾ��ͼ
void hierachyOf(BiTree root){
	int tab, max_leaves, max_width;
	BTWithLevel rt, last;
	BiTree bnode;
	char *padding0, *padding1;
	if (root==NULL) return;
	
	// ��������
	rt = (BTNodeWithLevel *) malloc(sizeof(BTNodeWithLevel));
	last = rt;
	rt->node = root;
	rt->level = 1;
	rt->parentTag = ' ';
    EnQueue(rt);
	printf("\n�������Ľṹʾ��ͼ:\n");

	// ������������������������ʾ��С
	max_leaves = 16;//2^(MAX_TREE_LEVEL - 1); // ��������������Ҷ�ӽ����
    max_width = (max_leaves+1) * PADDING;	// ��ʾ��������Ҷ�ӽ��ʱ������ַ����
	tab = max_width/2;		// ��ʾ�����ʱ������ַ����	

	// ��ʼ�����ڴ�Ų����ַ�������ߵ��ַ���
	padding0 = (char *)malloc(max_width);
	memset(padding0, 0, max_width);
	padding1 = (char *)malloc(max_width);
	memset(padding1, 0, max_width);
	
	while (!QueueEmpty()) { //������ʶ������Ľ��
		DeQueue(rt);
		bnode = rt->node;
		
		if ((last == rt) || (rt->level > last->level)) {
			if (strlen(padding1)) {
				printf("\n%s", padding0);
				printf("\n%s", padding1);
				tab = strlen(padding1) - 2*PADDING;
			}
			memset(padding0, 0, max_width);
			memset(padding0,' ', tab);
			memset(padding1, 0, max_width);
			memset(padding1,' ', tab);
			last = rt;
		};

		// ��ǰ����������Ϊ�գ�����
		/*if ((bnode==NULL)&&(last->parentTag=='/')) {
			memset(&padding0[strlen(padding0)], ' ', PADDING);
			memset(&padding1[strlen(padding1)], ' ', PADDING);
		}*/

		if ((bnode!=NULL)&&(rt->level == last->level)) {
			padding0[strlen(padding0)] =  rt->parentTag;
			memset(&padding0[strlen(padding0)], ' ', PADDING);
			padding1[strlen(padding1)] =  bnode->data;
			memset(&padding1[strlen(padding1)], ' ', PADDING);

			rt = (BTNodeWithLevel *) malloc(sizeof(BTNodeWithLevel));
			rt->node = bnode->lchild;
			rt->level = last->level + 1;
			rt->parentTag = '/';
			EnQueue(rt);
			rt = (BTNodeWithLevel *) malloc(sizeof(BTNodeWithLevel));
			rt->node = bnode->rchild;
			rt->level = last->level + 1;
			rt->parentTag = '\\';
			EnQueue(rt);
		}
	}
}

void hierachyOf1(BiTree root){
	int size=0, tab;
	BTWithLevel rt, last;
	BiTree bnode;
	char *padding;
	if (root==NULL) return;
	rt = (BTNodeWithLevel *) malloc(sizeof(BTNodeWithLevel));
	last = rt;
	rt->node = root;
	rt->level = 1;
    EnQueue(rt);
	printf("\n");
	size=countOfLeaves(root)*5*sizeof(char)+4*MAX_TREE_LEVEL;
	padding = (char *)malloc(size);
	memset(padding, 0, size);
	tab = (size/2-(rt->level)*3)>0 ? size/2-(rt->level)*3 : 0;
	while (!QueueEmpty()) {
		DeQueue(rt);
		bnode = rt->node;
		if ((last == rt) || (rt->level > last->level)) {
			if (strlen(padding)) {
				printf("\n%s\n", padding);
				tab = strlen(padding) - 8;
			}
			memset(padding, 0, size);
			memset(padding,' ', tab);
			last = rt;
		};

		if ((bnode!=NULL)&&(rt->level == last->level)) {			
			padding[strlen(padding)] =  (bnode!=NULL) ? bnode->data : ' ';
			memset(&padding[strlen(padding)], ' ', 4);
			rt = (BTNodeWithLevel *) malloc(sizeof(BTNodeWithLevel));
			rt->node = bnode->lchild;
			rt->level = last->level + 1;
			EnQueue(rt);
			rt = (BTNodeWithLevel *) malloc(sizeof(BTNodeWithLevel));
			rt->node = bnode->rchild;
			rt->level = last->level + 1;
			EnQueue(rt);
		}
	}
}

/*
 * ���е�˳��洢ʵ��
 */
bool QueueEmpty() {
	return (front==rear);
}

void EnQueue(BTWithLevel n) {
	queue[rear]= n;
	rear = (rear+1)%MAX_TREE_SIZE;
}

void DeQueue(BTWithLevel &n) {
	n = queue[front];
	front = (front+1)%MAX_TREE_SIZE;
}

/*
 * ��ջ��˳��洢ʵ��
 */
bool StackEmpty() {
	return (top==0);
}

void Push(BiTree n) {
	stack[top]= n;
	if (top++ > MAX_TREE_SIZE) {
		printf("\nStack overflow! exceed MAX_TREE_SIZE.\n");
		exit(OVERFLOW);
	}
}

void Pop(BiTree &n) {
	if (StackEmpty()) printf("\nStack is empty!\n");
	else {
		top--;
		n = stack[top];
	}
}

