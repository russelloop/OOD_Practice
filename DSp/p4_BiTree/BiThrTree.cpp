#include <p3tree.h>
#include <ctype.h>

BiThrTree pre; //������ʱʹ��

//*TBD4* �������������T��������������Thrtָ��ͷ���
Status InOrderThreading(BiThrTree &Thrt, BiThrTree T) {
    if(!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
        exit(OVERFLOW);
    Thrt->LTag = Link;
    Thrt->RTag = Thread;
    Thrt->rchild = Thrt;
    if(!T){
        Thrt->lchild = Thrt;
    }
    else{
        Thrt->lchild = T;
        pre = Thrt;
        InThreading(T);
        pre->rchild = Thrt;
        pre->RTag = Thread;
        Thrt->rchild = pre;
    }
    return OK;
}

/*TBD5* ���������������������Thrt����ָ��ָ��ͷ���
 *TBD5* ��InOrderThreading(BiThrTree, BiThrTree)ִ�����ʹ�á�
 *TBD5*/
Status InOrderTraverse_Thr(BiThrTree Thrt) {
    BiThrTree p;
    p = Thrt->lchild;
    while(p != Thrt){
        while (p->LTag == Link) {
            p = p->lchild;
        }
        if(!p->data) return ERROR;
        printf("%c", p->data);
        while(p->RTag == Thread && p->rchild != Thrt){
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
    return OK;
}


Status Create_BiThrTree(BiThrTree &rt) {
    char ch;
    scanf("%c", &ch);
    if (ch =='.') {
        rt=NULL;
    }
    else {
        if (!(rt=(BiThrNode *)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
        if (islower(ch)) ch = toupper(ch);
        rt->data = ch;
        rt->LTag = Link;
        rt->RTag = Link;
        Create_BiThrTree(rt->lchild);
        Create_BiThrTree(rt->rchild);
    };
    return OK;
}

/*
 * �������û���������Ķ�������������InOrderThreading(BiThrTree, BiThrTree)
 * ִ�����ʹ�á�
 */
void LDR(BiThrTree rt) {
    if (rt==NULL) return;
    LDR(rt->lchild);
    printf("%c", rt->data);
    //printf("(%d%c%d)", rt->LTag, rt->data, rt->RTag);
    LDR(rt->rchild);
}


// ��������������
void InThreading(BiThrTree p) {
    if (p) {
        InThreading(p->lchild);
        //ǰ������
        if (!p->lchild) {
            p->LTag = Thread;
            p->lchild = pre;
        }
        //�������
        if (!pre->rchild) {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}
