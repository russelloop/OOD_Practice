#include <p3tree.h>
#include <ctype.h>

/* ������������������
 */
void biTreTree() {
	BiThrTree root=NULL, Thrt;
	printf("�������������������Ľ��ֵ����ĸ��С�����ʾ��������\n");
	printf("�����������: abc..de.g..f...����P127ͼ6.8(b)��\n");
	printf("�����������: abdh..i..e..cf..g..��6���Ͷ�����C.ppt P10ͼ��\n");
	Create_BiThrTree(root);
    printf("\n���������δ�������Ķ�����: ");
	LDR(root);
	InOrderThreading(Thrt, root);
	printf("\n�������������������: ");
	InOrderTraverse_Thr(Thrt);
	printf("\r\n");
	getchar();
}

/* ��������������
 */
void biTree() {
	BiTree root=NULL;
	printf("�������������������Ľ��ֵ����ĸ��С�����ʾ��������\n");
	printf("�����������: abc..de.g..f...����P127ͼ6.8(b)��\n");
	Create_BiTree(root);
	printf("Ҷ�ӽ��ĸ���: %d\n", countOfLeaves(root));
	hierachyOf(root);
	printf("\r\n");
	//LDR(root);
	//inOrder(root); //�ǵݹ���������
	preOrder(root); //�ǵݹ���������
	level(root);	//��α���
	getchar();
}

void main() {
	//biTree();
	biTreTree();
	getchar();
}