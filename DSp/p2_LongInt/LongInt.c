#include <malloc.h>
#include <stdio.h>
#include<conio.h>
#include <mem.h>

typedef struct Number
{
    int data;
    struct Number *next;
    struct Number *prior;
}Number;

void CreateList(Number *L){     //创建长整数
    Number *s,*r;
    char x;
    L=(Number *)malloc(sizeof(Number));
    L->next = L->prior=NULL;
    r = L;
    while((x = getchar())!='\n'){
        if(x >= '0'&& x <= '9'){
            s = (Number *)malloc(sizeof(Number));
            s->data = x - '0';
            r->next = s;
            s->prior = r;
            r = s;
        }
        x = getchar();
    }
    r->next = NULL;
}

void PlusList(Number *L1, Number *L2, char a){   //两个长整数加减运算
    Number *p, *q, *r, *p1, *q1;
    int i = 0, j = 0;
    while(L1->next != NULL){    //将指针指向第一个长整数的尾节点并算出它的长度i
        p = L1->next;
        L1->next = L1->next->next;
        i++;
    }
    while(L2->next != NULL)   //将指针指向第二个长整数的尾节点并算出它的长度j
    {
        q = L2->next;
        L2->next = L2->next->next;
        j++;
    }

    //将两个长整数相加
    if(a=='+'){
        if(i>j){        //当第一个长整数的长度大于第二个
            while(i != 0){
                while(j != 0){
                    if((p->data+q->data)>9){   //当两数相加大于9向前一位进一
                        p->data = p->data+q->data-10;
                        p->prior->data = p->prior->data+1;
                    }
                    else
                        p->data = p->data+q->data;
                    p = p->prior;   //指针前移，准备计算更高一位
                    q = q->prior;
                    j--;
                    i--;
                }

                if(p->data>9 && i>1){   //两数相加大于9向前一位进一，当最高位大于9则不进一
                    p->data=p->data-10;
                    p->prior->data = p->prior->data+1;
                }
                r=p;
                p=p->prior;
                i--;
            }
        }
        else if(i == j){      //当第一个长整数的长度等于第二个
            while(i != 0){
                if((p->data+q->data)>9 && i>1){   //两数相加大于9向前一位进一，当最高位大于9则不进一
                    p->data = p->data+q->data-10;
                    p->prior->data = p->prior->data+1;
                }
                else p->data=p->data+q->data;
                r = p;
                p = p->prior;
                q = q->prior;
                i--;
            }
        }
        else{           //当第一个长整数的长度小于第二个
            while(j != 0){
                while(i != 0){
                    if(p->data+q->data>9){    //当两数相加大于9向前一位进一
                        q->data = q->data+p->data-10;
                        q->prior->data = q->prior->data+1;
                    }
                    else
                        q->data = p->data+q->data;
                    p = p->prior;
                    q = q->prior;
                    j--;
                    i--;
                }
                if(q->data>9 && j>1){     //两数相加大于9向前一位进一，当最高位大于9则不进一
                    q->data = q->data-10;
                    q->prior->data = q->prior->data+1;
                }
                r = q;
                q = q->prior;
                j--;
            }
        }
    }

    //将两个长整数相减
    if(a == '-'){
        if(i>j){          //当第一个长整数的长度大于第二个时，用第一个长整数减第二个
            while(i != 0){
                while(j != 0){
                    if(p->data<q->data){      //当第一个长整数的数小于第二个长整数的数，则向前一位借一
                        p->data = p->data-q->data+10;
                        p->prior->data = p->prior->data-1;
                    }
                    else
                        p->data = p->data-q->data;
                    p = p->prior;
                    q = q->prior;
                    j--;
                    i--;
                }
                if(p->data<0 && i>1){

                    p->data = p->data+10;
                    p->prior->data = p->prior->data-1;
                }
                r = p;
                if(p->data == 0 && i == 1){
                    r = p->next;
                    break;
                }
                p = p->prior;
                i--;
            }
        }
        else if(i == j){           //当第一个长整数的长度等于第二个的长度
            int c = 0, h = i, k = j;
            p1 = p;
            q1 = q;
                while(i != 1){
                    p1 = p1->prior;
                    q1 = q1->prior;
                    i--;
            }
            while(j != 0){    //判断两个长整数的大小
                if(p1->data > q1->data){
                    c = 1;
                    break;
                }
                else if(p1->data<q1->data){
                    c = 0;
                    break;
                }
                else if(p1->data == q1->data && j == 1)
                    c = 1;
                else{
                    p1 = p1->next;
                    q1 = q1->next;
                }
                j--;
            }
            if (c == 1){     //第一个长整数大于第二个长整数，用第一个长整数减去第二个
                while(h != 0){
                    if(p->data < q->data){     //当第一个长整数的数小于第二个长整数的数，则向前一位借一
                        p->data = p->data-q->data+10;
                        p->prior->data = p->prior->data-1;
                    }
                    else
                        p->data = p->data-q->data;
                    r = p;
                    p = p->prior;
                    q = q->prior;
                    h--;
                }
                while(r->data == 0 && k>1){
                    k--;
                    r = r->next;
                }
            }
            if(c == 0){                 //第一个长整数大于第二个长整数
                while(h != 0){
                    if(p->data>q->data && h>1){    //当第二个长整数的数小于第一个长整数的数，则向前一位借一
                        q->data = q->data-p->data + 10;
                        q->prior->data = q->prior->data - 1;
                    }
                    else
                        q->data=q->data-p->data;
                    r = q;
                    p = p->prior;
                    q = q->prior;
                    h--;
                }
                while(r->data == 0){
                    r = r->next;
                }
                r->data = -r->data;
            }
        }
        else {          //当第一个长整数的长度小于第二个
            while(j != 0){
                while(i != 0){
                    if(p->data > q->data){      //当第二个长整数的数小于第一个长整数的数，则向前一位借一
                        q->data = q->data-p->data+10;
                        q->prior->data = q->prior->data-1;
                    }
                    else
                        q->data = q->data-p->data;
                    p = p->prior;
                    q = q->prior;
                    j--;
                    i--;
                }
                if(q->data < 0 && j > 1){
                    q->data = q->data+10;
                    q->prior->data = q->prior->data-1;
                }
                r = q;
                if(r->data == 0 && j == 1){
                    r = r->next;
                    r->data = -r->data;
                    break;
                }
                if(r->data != 0 && j == 1)
                    r->data = -r->data;
                q = q->prior;
                j--;
            }
        }
    }
    while(r!=NULL){
        printf("%d", r->data);
        r = r->next ;
    }
    printf("");
}

void PrintList(Number *L){      //输出长整数

    Number *p = L->next;
    while(p != NULL){
        printf("%d", p->data);
        p = p->next;
    }
    printf("");
}

void DestroyList(Number *L){

    Number *p = L,*q=p->next;
    while(q != NULL){
        free(p);
        p = q;
        q = p->next;
    }
    printf("释放链表");
}

int main(){

    Number number1;
    Number number2;
    Number *p = &number1;
    Number *q = &number2;
    char a;
    printf("Please Enter the First long Integer:");
    CreateList(p);
    for(;;){
        printf("+ or -\n");
        a = getchar();
        if(a == '+' || a == '-')
            break;
        printf("你输入的有误！请重新输入");
    }
    printf("Please Enter the Second long Integer:");
    CreateList(q);
    printf("********************************************************************************");
    PrintList(p);
    printf("+");
    PrintList(q);
    printf("=");
    PlusList(p, q,a);
    printf("********************************************************************************");
    DestroyList(p);
    DestroyList(q);
    getch();
    return 0;
}

