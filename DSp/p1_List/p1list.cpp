// ʵ��һ�����һ������ʵ�����Ա��ϲ�������
// e1list.cpp : �������̨Ӧ�ó������ڵ㡣
// 

#include "p1list.h"

/* �˺������ڳ�ʼ��һ��������������Ա�L
 * L�ĳ�ֵ��ͨ�����̰��յ����Ĵ���һ����Ȼ��һ����Ȼ������ġ�
 */
void InitList(List &L) {
    int i=0,d;
    L.elem[0]=GUARD;
    printf("����ĳ���Ա����Ԫ�ص�ֵ(��Ȼ��)��%d��ʾ���������\n", GUARD);
    do {
        scanf("%d", &d);
        if (d!=GUARD) {
            if (i!=0 && d < L.elem[i-1]) 
                printf("\n����Ҫ��ʼ��һ��������������Ա�������һ����С�ڵ�%d��Ȼ��",L.elem[i]);
            else L.elem[i++]=d;
        }
        if (i==MAXLEN) printf("\n�����Ա��ȴﵽ���ֵ\n");
    }while ((d!=GUARD)&&(i<MAXLEN));
    L.length=i;
}

/* �˺������ڳ�ʼ��һ�����Ա�L
 * L�ĳ�ֵ��ͨ������һ����Ȼ��һ����Ȼ������ġ�
 */
void InitList0(List &L) {
    int i=0,d;
    L.elem[0]=GUARD;
    printf("����ĳ���Ա����Ԫ�ص�ֵ(��Ȼ��)��%d��ʾ���������\n", GUARD);
    do {
        scanf("%d", &d);
        if (d!=GUARD) L.elem[i++]=d;
        if (i==MAXLEN) printf("\n�����Ա��ȴﵽ���ֵ\n");
    }while ((d!=GUARD)&&(i<MAXLEN));
    L.length=i;
}

void printList(List L){
    int i;
    printf("���Ա�[%d]: \n", L.length);
    for (i=0;i<L.length;i++) printf("%d ", L.elem[i]);
    printf("\n");
}

void createTwoLists(List &La, List &Lb) {
    printf("\n�����������Ա�--ע�������������ܳ��Ȳ�Ҫ����%d\n",MAXLEN);
    InitList(La);
    printf("\n��ʼ�����Ա�Lb���䳤�Ȳ�����%d���������ֱ��ضϣ�\n", MAXLEN-La.length);
    InitList(Lb);
    if (La.length + Lb.length > MAXLEN) Lb.length=MAXLEN-La.length;
}


/*TBD1* ��Lb�鲢��La���γ��±�Lc
 *TBD1* Ҫ��Lc����������������ظ�Ԫ��
 *TBD1*/
void MergeList(List La, List Lb, List &Lc) {
    int i, j, k;
    i = j = k = 0;

    while(i < La.length && j < Lb.length){
        if(La.elem[i] < Lb.elem[j]){
            Lc.elem[k++] = La.elem[i++];
        }
        else{
            Lc.elem[k++] = Lb.elem[j++];
        }
    }

    while(i < La.length){
        Lc.elem[k++] = La.elem[i++];
    }
    while(j < Lb.length){
        Lc.elem[k++] = Lb.elem[j++];
    }

    Lc.length = k;
}

/*TBD2* ����La��Lb�ֱ��ʾ�������ϣ����¼���La��La U Lb�� U"��"������
 *TBD2* ע�⼯���ﲻ��������ظ�Ԫ��
 *TBD2*/
void Union(List &La, List Lb) {
    int i = La.length;
    int j = 0;
    while(j <= Lb.length){
        La.elem[i++] = Lb.elem[j++];
    }
    La.length += Lb.length; 
}

/*TBD3* �����Ա�L��ת
 *TBD3* Ҫ��ʹ�����ٵĸ��ӿռ䣬�ռ临�Ӷ�ΪO(1)��
 *TBD3*/
void ReverseList(List &L) {
    int temp;
    int i, j;
    int n = L.length - 1;
    for(i = 0; i <= n; i++){
            temp = L.elem[n];
        for(j = n - 1; j>= i; j--){
            L.elem[j + 1] = L.elem[j];
        }
            L.elem[i] = temp;
    }
}

/*TBD4* ��һ������˳���L��ɾ��Ԫ��ֵ��x��y֮�������Ԫ��(x<= y)
 *TBD4* Ҫ���Խϸߵ�Ч��ʵ�֣��ռ临�Ӷ�ΪO(1)��
 *TBD4*/
void deleteall(List &L, int x, int y) {
    int n = L.length - 1;
    int i = 0;
    int j;
    while(i <= n) {
        if (L.elem[i] >= x && L.elem[i] <= y){
            for(j = i; j <= n; j++) {
                L.elem[j] = L.elem[j + 1];
            }
            L.length -= 1;
        }
        else
            i++;
    }
}


int main(int argc, char* argv[])
{
    mainlottery();
    //List La;
    //InitList(La);
    //printList(La);
    //InitList(Lb);
    //printList(Lb);
    //MergeList(La, Lb, Lc);
    //Union(La, Lb);
    //ReverseList(La);
    //deleteall(La, 3, 5);
    //printList(La);

    printf("\n���������ַ������˳� ......"); getchar();
    return 0;
}