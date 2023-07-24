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
	printf("业主姓名");
	scanf("%s", &g->name);
	printf("车位号");
	scanf("%s", &g->number);
	printf("车牌号");
	scanf("%s", &g->num);
}

void Input(sqlist* G) {
	int num;
	int i;
	printf("==========车辆信息输入==========\n");
	printf("请输入录入的业主人数\n");
	scanf("%d", &num);
	for (i = 0;i < num;i++) {
		printf("====第%d个业主====\n", i+1 );
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
	printf("==========车辆信息插入==========\n");
	printf("请输入你想要插入的位置\n");
	scanf("%d", &num);
	printf("请输入业主信息：\n");
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
	printf("==========业主信息删除==========\n");
	int num=0;
	printf("请输入想要删除的位置：\n");
	scanf("%d", &num);
	if (Del(G, num))
		printf("del success");
	else
		printf("erro");
}

void Print(sqlist* G, int i) {
	printf("==========第%d位业主信息==========\n", i + 1);
	printf("姓名：%s\n车位号：%s\n车牌号：%s\n", G->elem[i].name, G->elem[i].number, G->elem[i].num);
}

void print(sqlist* G) {
	int i;
	for (i = 0;i < G->length;i++) {
		Print(G, i);
	}
}

int check(sqlist* G) {
	printf("==========车辆信息查找==========\n");
	printf("请输入需要查找的业主车牌号");
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
	printf("==========车辆信息操作系统==========\n");
	printf("操作对应序号：\n1.新业主录入\n2.查找\n3.删除\n4.插入\n5.输出当前所有业主信息\n");
	if (initelem(&G))
		printf("====初始化成功====\n");
	while (1) {
		printf("请输入序号，0退出\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:Input(&G);break;
		case 2:	ch=check(&G);
			if (ch) {
				printf("该车牌号业主位于%d号位置\n", ch + 1);
				break;
			}
			else{
				printf("车牌号不存在\n");
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