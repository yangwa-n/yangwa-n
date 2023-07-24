#include <stdio.h>
#include <malloc.h>
#include<string.h>
typedef char elemtype;
typedef int elem;
#define maxsize 1000

typedef struct  {
	char name[20];
	char number[5];
	char num[10];
}host;

typedef struct vehicle {
	host* elem;
	elem length;
	elem elemsize;
}sqlist;

int initelem(sqlist* G) {
	G->elem = (host*)malloc(sizeof(host) * maxsize);
	G->length = 0;
	G->elemsize = maxsize;
	if(G->elem)
		return 1;
}

void input(host* g) {
	printf("ҵ������");
	scanf("%s", &g->name);
	printf("��λ��");
	scanf("%s", &g->number);
	printf("���ƺ�");
	scanf("%s", &g->num);
}

void Input(sqlist* G) {
	int num;
	int i;
	printf("==========������Ϣ����==========\n");
	printf("������¼���ҵ������\n");
	scanf("%d", &num);
	for (i = 0;i < num;i++) {
		printf("====��%d��ҵ��====\n", i+1 );
		input(&G->elem[i]);
	}
	G->length = i;
}

void Insert(sqlist* G, int num, host temp) {
	if (num<1 || num>G->length + 1)
		printf("erro");
	if (G->length >= maxsize)
		printf("erro");
	for (int y = G->length-1;y >= num-1 ;y--) {
		G->elem[y + 1] = G->elem[y];
	}
	G->elem[num-1] = temp;
	G->length++;
}

void insert(sqlist* G) {
	int num;
	printf("==========������Ϣ����==========\n");
	printf("����������Ҫ�����λ��\n");
	scanf("%d", &num);
	printf("������ҵ����Ϣ��\n");
	host temp;
	input(&temp);
	Insert(G, num, temp);
}

int Del(sqlist* G, int num) {
	if (num<1 || num>G->length) {
		printf("erro");
		return 0;
	}
	for (int j = num;j < G->length;j++)
		G->elem[j - 1] = G->elem[j];
	G->length--;
	return 1;
}

void del(sqlist* G) {
	printf("==========ҵ����Ϣɾ��==========\n");
	int num=0;
	printf("��������Ҫɾ����λ�ã�\n");
	scanf("%d", &num);
	if (Del(G, num))
		printf("del success");
	else
		printf("erro");
}

void Print(sqlist* G, int i) {
	printf("==========��%dλҵ����Ϣ==========\n", i + 1);
	printf("������%s\n��λ�ţ�%s\n���ƺţ�%s\n", G->elem[i].name, G->elem[i].number, G->elem[i].num);
}

void print(sqlist* G) {
	int i;
	for (i = 0;i < G->length;i++) {
		Print(G, i);
	}
}

int check(sqlist* G) {
	printf("==========������Ϣ����==========\n");
	printf("��������Ҫ���ҵ�ҵ�����ƺ�");
	char carnum[20];
	scanf("%s", carnum);
	for (int i = 0;i < G->length;i++) {
		if (strcmp(G->elem[i].num, carnum) == 0)
			return i;
	}

}
int main()
{
	sqlist G;
	int a, ch=0;
	printf("==========������Ϣ����ϵͳ==========\n");
	printf("������Ӧ��ţ�\n1.��ҵ��¼��\n2.����\n3.ɾ��\n4.����\n5.�����ǰ����ҵ����Ϣ\n");
	if (initelem(&G))
		printf("====��ʼ���ɹ�====\n");
	while (1) {
		printf("��������ţ�0�˳�\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:Input(&G);break;
		case 2:	ch=check(&G);
			if (ch) {
				printf("�ó��ƺ�ҵ��λ��%d��λ��\n", ch + 1);
				break;
			}
			else{
				printf("���ƺŲ�����\n");
				break;
			}
		case 3:	del(&G);break;
		case 4:	insert(&G);break;
		case 5:print(&G);break;
		case 0: return 0;
		}
	}
	free(G.elem);
	G.elem = NULL;
	return 0;
}