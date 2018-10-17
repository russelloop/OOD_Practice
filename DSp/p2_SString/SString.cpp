// SString.cpp : 定义字符串操作
//

#include "p2.h"

int next[MAXLEN];

/* 此函数用于初始化主串S和子串T的初值
 * 注意约定T="ABCDE"，而S的初值是通过键盘一个字母一个字母输入的，回车表示输入结束。
 */
void initSStrings(SString &S, SString &T) {
	int i;
	char c;
	S[0]=S[1]=T[6]=0;
	T[0]=5;
	for (i=1;i<=5;i++) T[i]='A'+i-1;
	printf("\n一个个地输入字母A-E或a-e,回车表示输入结束\n");
	i=0;
	do {
		i++;
		do {
            c = toupper(getchar());} 
            while ((!(c>='A'&&c<='E'))&&c!='\n');
		S[i] = c;
	} while (i<255 && S[i]!='\n');
	if (S[i]=='\n') S[i] = 0;
	S[0] = i - 1;
}

/* 此函数用于初始化字符串S
 * 注意S的初值是通过键盘一个字母一个字母输入的，回车表示输入结束。
 */
void initSString(SString &S) {
	int i;
	char c, upc;
	S[0]=S[1];
	printf("初始化字符串：一个个地输入字母A-E或a-e,回车表示输入结束\n");
	i=0;
	do {
		i++;
		do {
			c = getchar();
			upc = toupper(c);
		} while ((!(upc>='A'&&upc<='E'))&&c!='\n');
		S[i] = c;
	} while (i<255 && S[i]!='\n');
	if (S[i]=='\n') S[i] = 0;
	S[0] = i - 1;
}

/* 此函数用于输出显示字符串S
 * 注意tag为真时输出串的长度，否则只输出字符串。
 */
void printSString(SString S, bool tag) {
	int i;
	if (tag) printf("[%d]", S[0]);
    for (i=1; i<=S[0]; i++) printf("%c", S[i]);
	printf("\n");
}

/*TBD2* 串的模式匹配算法，即求子串T在主串S中第pos个字符之后的位置
 *TBD2* 若子串没出现，则返回0
 *TBD2*/
int Index(SString S, SString T, int pos) {
	int i, j;                  //定义i为当前指针位置，j为比对进度（已成功匹配的字符数）
	i = pos;
	j = 1;
	while(i<=S[0] && j<=T[0]){ //比对完成或者比对成功时退出循环
		if(S[i] == T[j]){      //单个字符比对成功,继续下一位置的比对
			i++;
			j++;
		}
		else{                  
			i = i-j+2;         //比对失败,指针回退
			j = 1;             //重置比对进度j
		}
	}

	if(j>T[0])                 //若成功匹配，说明子串存在
		return i - T[0];       //返回子串所在位置
	else return 0;             //否则返回0 
}

/*TBD2* 求模式串T的next函数值并存入数据next[]
 *TBD2*/
void get_next(SString T, int next[]) {
	int i,j;
	i = 1;
	j = 0;
	next[1] = 0;

	while(i<T[0]){
		if(j == 0 || T[i] == T[j]){
            ++i;
			++j;
			next[i] = j;
		}
		else j = next[j];
	}
}

/*TBD2* 求模式串T的next函数修正值并存入数据next[]
 *TBD2*/
void get_nextval(SString T, int next[]) {
	int i,j;
	i = 1;
	j = 0;
	next[1] = 0;

	while(i<T[0]){
		if(j ==0 || T[i] == T[j]){
			++i;
			++j;
			if(T[i] != T[j])           //筛选重复字符
				next[i] = j;
			else
				next[i] = next[j];
		}
		else
			j = next[j];
	}

}

/*TBD2* 串的模式匹配的KMP算法，即求子串T在主串S中第pos个字符之后的位置
 *TBD2* 若子串没出现，则返回0
 *TBD2*/
int Index_KMP(SString S, SString T, int pos) {
	int i,j;
	i = pos;
	j = 1;
	while(i <= S[0] && j <= T[0]){
		if(j == 0 || S[i] == T[j]){
		    ++i;
			++j;
		}
		else j = next[j];
	}

	if(j > T[0])
		return i - T[0];
	else return 0;
}

int mainSString()
{
	SString S, T;
	int r, i, pos;
	//initSStrings(S,T);
	initSString(S);
	initSString(T);
	printf("\n输入从主串的第几个字符开始匹配。要求输入值介于1和%d之间，否则默认为1\n", S[0]);
	scanf("%d", &pos);
	if (pos<1 || pos>S[0]) pos=1;
	printSString(S, 1);
	printSString(T, 1);

	//Index(S, T, pos);

	get_next(T, next);
	get_nextval(T, next);
	r = Index_KMP(S, T, pos);
	if (!r) printf("\n这样的子串在主串第%d个字符之后没有出现\n", pos);
	else {
		printf("\n子串在主串中第%d个字符之后出现，其位置是%d\n", pos, r);
        printf("主串:"); printSString(S, 0);
		printf("子串:"); 
		for (i=1; i<r; i++) printf(" ");
		printSString(T, 0);
	}
	
	return 0;
}

int main(int argc, char* argv[])
{
    mainSString();
    printf("\n键入任意字符程序退出 ......\r\n"); getchar();
    printf("0x%x 0x%x 0x%x", getchar(), '\r', '\n');
    return 0;
}
