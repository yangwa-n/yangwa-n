#include<stdio.h>
#include<malloc.h>
typedef char type;
int num;
typedef struct list {
	type data[20];
	struct list* node;
}list;

list* creadtlist(int num) {
	list* head;
	head = (list*)malloc(sizeof(list));
	if (head == NULL)
		return 0;
	head->node = NULL;
	for (int i = 0;i < num;i++) {
		list* newnode = (list*)malloc(sizeof(list));
		if (newnode == NULL)
			return 0;
		scanf("%s", &newnode->data);
		newnode->node = head->node;
		head->node = newnode;
	}
	return head;
}

void print(list* head) {
	list* p;
	p = head->node;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->node;
	}
}

int main() {
	list* head;
	scanf("%d", &num);
	head=creadtlist(num);
	print(head);
	return 0;
}