#include <stdio.h>

#define num 50

int m[num][num][2],s[num][num];



/*获得将第i条边断开后最后一个运算符在i+s处进行得到的最大值;再循环比较不同的s，取出最大值，最后比较不同的i，取出最大值，便为要求的最大值；m[i][j][0]里存储从顶点i开始，长度为j的链p[i][j]合并的最小值，m[i][j][1]存储链*/
int  getmax(int n,int v[],char op[])
{
    int i1,j1,k1,s1,x;
    int temp_ij_min[num],temp_ij_max[num],temp_max;
    int e[4];
    for(i1=1;i1<=n;i1++)
        m[i1][1][0]=m[i1][1][1]=v[i1];
    for(j1=2;j1<=n;j1++)
        for(i1=1;i1<=n;i1++)
        {
            for(s1=1;s1<=j1-1;s1++)
            {
                x=(i1+s1-1)%n+1;
                if(op[(i1+s1)%n]=='+')
                {
                    temp_ij_min[s1]=m[i1][s1][0]+m[x][j1-s1][0];
                    temp_ij_max[s1]=m[i1][s1][1]+m[x][j1-s1][1];
                }
                else
                {
                    e[0]=(m[i1][s1][0])*(m[x][j1-s1][0]);
                    e[1]=(m[i1][s1][0])*(m[x][j1-s1][1]);
                    e[2]=(m[i1][s1][1])*(m[x][j1-s1][0]);
                    e[3]=(m[i1][s1][1])*(m[x][j1-s1][1]);
                    temp_ij_min[s1]=e[0];
                    temp_ij_max[s1]=e[0];
                    for(k1=1;k1<4;k1++)
                    {
                        if(temp_ij_min[s1]>e[k1])
                            temp_ij_min[s1]=e[k1];
                        if(temp_ij_max[s1]<e[k1])
                            temp_ij_max[s1]=e[k1];
                    }
                }
            }
            m[i1][j1][0]=temp_ij_min[1];m[i1][j1][1]=temp_ij_max[1];
            for(k1=2;k1<=j1-1;k1++)
            {
                if(m[i1][j1][0]>temp_ij_min[k1])
                    m[i1][j1][0]=temp_ij_min[k1];
                if(m[i1][j1][1]<temp_ij_max[k1])
                {
                    m[i1][j1][1]=temp_ij_max[k1];
                    s[i1][j1]=s1;
                }
            }
        }
    temp_max=m[1][n][1];
    for(i1=2;i1<=n;i1++)
    {
        if(temp_max<m[i1][n][1]) temp_max=m[i1][n][1];
    }
    return temp_max;
}


/*主程序*/

int main( )
{
    int n,max;
    int i;
    int v[50];
    char op[50];

    printf("input n:");
    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++)
    {
        scanf("%c %d",&op[i],&v[i]);
        getchar();
    }
    max=getmax(n,v,op);
    printf("the max is:%d",max);
    getchar();


}