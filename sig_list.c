/* 有头单链表 */
/* 循环有头单链表 */

#include <stdlib.h> 
#include <stdio.h>
struct node {
	int data;
	struct node *next;
};

/*单链表初始化*/
void sig_list_init(struct node *head)
{
	head->data = 0;
	head->next = NULL;
}

/*单链表头部加入结点*/
int sig_list_add(struct node *head, int num)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	if(!new_node)
	{
		printf("new_node malloc error.\n");
		return -1;
	}
	new_node->data = num;

	/*加入新结点*/
	/*如果链表为空*/
	if(head->next == NULL)
	{
		printf("当前链表为空\n");
		head->next = new_node;
		new_node->next = NULL;
	}
	/* 如果链表不为空 */
	else 
	{
		printf("当前链表不为空\n");
		new_node->next = head->next;
		head->next = new_node;
	}

	return 0;
}

void print_node(struct node *node)
{
	printf("%d ", node->data);	
}


/* 遍历链表并操作 */
void sig_list_for_each_opr(struct node *head, void (*func)(struct node *head))
{
	struct node *cur = head;

	for(cur = head; cur->next != NULL; cur = cur->next)
	{
		func(cur);
	}	
	func(cur);
}

/* 遍历链表 */
struct node * __sig_list_for_each(struct node *head)
{
	struct node *tail;
	for(tail = head; tail->next != NULL; tail = tail->next)
		;
	
	return tail;
}

/*单链表尾部加入结点*/
int sig_list_tail(struct node *head, int num)
{
	struct node *tail;
	tail = __sig_list_for_each(head);

	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	if(!new_node)
	{
		printf("new_node malloc error\n");
		return -1;
	}
	new_node->data = num;
	tail->next = new_node;
	new_node->next = NULL;

	return 0;
}

/* 单链表删除某个结点 */
int sig_list_del_node(struct node *head, int num)
{
	struct node *back = NULL;
	struct node *cur = NULL;


	/* 如果node是最后的结点 */
	/* 如果只有head和node两个结点 */

	return 0;
}

/* 判断单链表有环还是无环 */
/* 无环：0    有环：1 */
int sig_list_check_loop(struct node *head)
{
	if(head == NULL)
		return 0;
	struct node *slow = head;
	struct node *fast = head;
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			return 1;
	}
	return 0;    

}

int main(void)
{
	struct node *head = (struct node *)malloc(sizeof(struct node));
	if(!head)
	{
		printf("head malloc error.\n");
		return -1;
	}
	sig_list_init(head);

	sig_list_add(head, 1);
	sig_list_add(head, 2);
	sig_list_add(head, 3);
	sig_list_tail(head, 100);
	sig_list_for_each_opr(head, print_node);
	printf("true or false:%d\n", sig_list_check_loop(head));

	return 0;
}
