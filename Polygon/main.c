#include <stdio.h>
#include <stdlib.h>

#define MAX_POINT 20
int chain_value[MAX_POINT][MAX_POINT][2];  //chain[i][j][0]表示从v[i]节点开始，边长为j的链的最大值
//chain[i][j][1]表示从v[i]节点开始，边长为j的链的最小值
int n,*v;
char *op;

int get_max_sum();
void chain_max(int start, int len, int k);
void get_max_min(int a, int b, int c, int d, int start, int index, int len);

int main()
{
    int i;
    char ch;

    scanf("%d",&n);
    v = (int *)malloc(n*sizeof(int));
    op = (char *)malloc(n*sizeof(char));

    ch = getchar();                    //数据输入
    for (i = 0; i < n; i++)
    {
        scanf("%c",&op[i]);
        ch = getchar();
        scanf("%d",&v[i]);
        ch = getchar();
    }

    printf("MAX:%d\n",get_max_sum());

    return 0;
}//main


int get_max_sum()
{
    int i,k,start,max,tmp,len;

    for (i = 0; i < n; i++)
    {
        chain_value[i][0][0] = v[i];        //链长为0，即单个点的值
        chain_value[i][0][1] = v[i];
    }

    for (len = 1; len < n; len++)  //控制链的长度，
    {
        for (start = 0; start < n ; start++)        //起点start配合链长，就可以得出除去某条边的效果
        {
            chain_value[start][len][0] = -9999;
            chain_value[start][len][1] = 9999;
            for (k = 0; k < len; k++)
            {
                chain_max(start,len,k);
            }
        }
    }

    max = chain_value[0][n-1][0];            //最终的最大值
    for (start = 1; start < n; start++)
    {
        tmp =  chain_value[start][n-1][0];
        max = max > tmp ? max : tmp;
    }
    return max;
}

void chain_max( int start, int len, int k)
{
    int index,a,b,c,d;  //a<= m1 <= b  c<= m2 <=d

    index = (start+k+1)%n;  //表示符号(op)或者符号后面的操作数的下标

    a = chain_value[start][k][1];
    b = chain_value[start][k][0];
    c = chain_value[index][len-k-1][1];
    d = chain_value[index][len-k-1][0];

    get_max_min(a,b,c,d,start,index,len);

}

void get_max_min(int a, int b, int c, int d, int start, int index, int len)
{
    int max_max,min_min,max_min,min_max;
    int max,min;

    max = chain_value[start][len][0];
    min = chain_value[start][len][1];

    if ('+' == op[index])
    {
        max = max > (b + d) ? max : (b + d);
        min = min < (a + c) ? min : (a + c);
    }
    else if ('x' == op[index])
    {
        max_max = b * d;
        min_min = a * c;
        max_min = b * c;
        min_max = a * d;

        max = max > max_max ? max :max_max;
        max = max > min_min ? max : min_min;
        max = max > max_min ? max : max_min;
        max = max > min_max ? max : min_max;

        min = min < max_max ? min :max_max;
        min = min < min_min ? min : min_min;
        min = min < max_min ? min : max_min;
        min = min < min_max ? min : min_max;
    }

    chain_value[start][len][0] = max;
    chain_value[start][len][1] = min;
}

//2013/9/14 10:13