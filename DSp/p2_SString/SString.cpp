// SString.cpp : �����ַ�������
//

#include "p2.h"

int next[MAXLEN];

/* �˺������ڳ�ʼ������S���Ӵ�T�ĳ�ֵ
 * ע��Լ��T="ABCDE"����S�ĳ�ֵ��ͨ������һ����ĸһ����ĸ����ģ��س���ʾ���������
 */
void initSStrings(SString &S, SString &T) {
	int i;
	char c;
	S[0]=S[1]=T[6]=0;
	T[0]=5;
	for (i=1;i<=5;i++) T[i]='A'+i-1;
	printf("\nһ������������ĸA-E��a-e,�س���ʾ�������\n");
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

/* �˺������ڳ�ʼ���ַ���S
 * ע��S�ĳ�ֵ��ͨ������һ����ĸһ����ĸ����ģ��س���ʾ���������
 */
void initSString(SString &S) {
	int i;
	char c, upc;
	S[0]=S[1];
	printf("��ʼ���ַ�����һ������������ĸA-E��a-e,�س���ʾ�������\n");
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

/* �˺������������ʾ�ַ���S
 * ע��tagΪ��ʱ������ĳ��ȣ�����ֻ����ַ�����
 */
void printSString(SString S, bool tag) {
	int i;
	if (tag) printf("[%d]", S[0]);
    for (i=1; i<=S[0]; i++) printf("%c", S[i]);
	printf("\n");
}

/*TBD2* ����ģʽƥ���㷨�������Ӵ�T������S�е�pos���ַ�֮���λ��
 *TBD2* ���Ӵ�û���֣��򷵻�0
 *TBD2*/
int Index(SString S, SString T, int pos) {
	int i, j;                  //����iΪ��ǰָ��λ�ã�jΪ�ȶԽ��ȣ��ѳɹ�ƥ����ַ�����
	i = pos;
	j = 1;
	while(i<=S[0] && j<=T[0]){ //�ȶ���ɻ��߱ȶԳɹ�ʱ�˳�ѭ��
		if(S[i] == T[j]){      //�����ַ��ȶԳɹ�,������һλ�õıȶ�
			i++;
			j++;
		}
		else{                  
			i = i-j+2;         //�ȶ�ʧ��,ָ�����
			j = 1;             //���ñȶԽ���j
		}
	}

	if(j>T[0])                 //���ɹ�ƥ�䣬˵���Ӵ�����
		return i - T[0];       //�����Ӵ�����λ��
	else return 0;             //���򷵻�0 
}

/*TBD2* ��ģʽ��T��next����ֵ����������next[]
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

/*TBD2* ��ģʽ��T��next��������ֵ����������next[]
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
			if(T[i] != T[j])           //ɸѡ�ظ��ַ�
				next[i] = j;
			else
				next[i] = next[j];
		}
		else
			j = next[j];
	}

}

/*TBD2* ����ģʽƥ���KMP�㷨�������Ӵ�T������S�е�pos���ַ�֮���λ��
 *TBD2* ���Ӵ�û���֣��򷵻�0
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
	printf("\n����������ĵڼ����ַ���ʼƥ�䡣Ҫ������ֵ����1��%d֮�䣬����Ĭ��Ϊ1\n", S[0]);
	scanf("%d", &pos);
	if (pos<1 || pos>S[0]) pos=1;
	printSString(S, 1);
	printSString(T, 1);

	//Index(S, T, pos);

	get_next(T, next);
	get_nextval(T, next);
	r = Index_KMP(S, T, pos);
	if (!r) printf("\n�������Ӵ���������%d���ַ�֮��û�г���\n", pos);
	else {
		printf("\n�Ӵ��������е�%d���ַ�֮����֣���λ����%d\n", pos, r);
        printf("����:"); printSString(S, 0);
		printf("�Ӵ�:"); 
		for (i=1; i<r; i++) printf(" ");
		printSString(T, 0);
	}
	
	return 0;
}

int main(int argc, char* argv[])
{
    mainSString();
    printf("\n���������ַ������˳� ......\r\n"); getchar();
    printf("0x%x 0x%x 0x%x", getchar(), '\r', '\n');
    return 0;
}
