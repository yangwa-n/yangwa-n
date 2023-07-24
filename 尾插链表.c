#include<stdio.h>
#include<malloc.h>
typedef char type;
int num;

typedef struct list {
	type data[20];
	struct list* node;
}list;

list* creat(num) {
	list* head;
	list* p;
	list* new;
	head = (list*)malloc(sizeof(list));
	if (head == NULL)
		return -1;
	p = head;
	for (int i = 0;i < num;i++) {
		new = (list*)malloc(sizeof(list));
		if (new == NULL)
			return -1;
		scanf("%s", &new->data);
		p->node = new;
		//p = new;
		p = p->node; 
		new->node = NULL;
	}
	return head;
}

void print(list* head) {
	list* next;
	next = head->node;
	while (next!=NULL)
	{
		printf("%s\n", next->data);
		next = next->node;
	}
}
int main() {
	list* head;
	scanf("%d", &num);
	head = creat(num);
	print(head);
}