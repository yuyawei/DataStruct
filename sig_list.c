/* 有头单链表 */
/* 循环有头单链表 */

#include <stdlib.h> 
#include <stdio.h>
#include <stdbool.h>
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

/*单链表是否为空表*/
bool is_empty_sig_list(struct node *head)
{
	return head->next == NULL ? true: false;
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

/*判断链表中一个结点是否为最后一个结点*/
static bool __is_last_sig_list(struct node *node)
{
	return node->next ? true: false;
}

/*删除curNode指向的结点*/
static int __sig_list_del_node(struct node *preNode, struct node *curNode)
{
	if(preNode->next != NULL)
	{
		preNode->next = curNode->next;
		curNode->next = curNode;
		free(curNode);
		return 0;
	}
	/*未完*/
}

/* 单链表删除某个结点 */
int sig_list_del_node(struct node *head, int num)
{
	struct node *prev = NULL;
	struct node *cur = NULL;

	if(is_empty_sig_list(head)) return -1;
	for(prev = head, cur = head->next; cur->next != NULL; prev = cur, cur = cur->next)
	{
		/*删除的结点为链表中间的结点*/
		if(cur->data == num)
		{
			prev->next = cur->next;
			cur->next = cur;
			free(cur);
			return 0;
		}
	}
	/*删除的结点为最后一个结点*/
	if(cur->data == num)
	{
		printf("删除的结点为最后一个结点\n");
		prev->next = NULL;
		cur->next = cur;
		free(cur);
		return 0;
	}

	return 0;
}

/*销毁单链表*/
int sig_list_destroy(struct node *head)
{
	struct node *temp = NULL;
	struct node *cur = NULL;
	struct node *prev = NULL;

	/*单链表为空，释放头结点*/
	if(is_empty_sig_list(head))
	{
		head->next = head;
		free(head);
		return 0;
	}


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
	printf("单链表是否为空:%d \n", is_empty_sig_list(head));

	sig_list_add(head, 1);
	sig_list_add(head, 2);
	sig_list_add(head, 3);
	sig_list_tail(head, 100);
	sig_list_for_each_opr(head, print_node);
	printf("true or false:%d\n", sig_list_check_loop(head));
	printf("单链表是否为空:%d \n", is_empty_sig_list(head));
	sig_list_del_node(head, 30);
	sig_list_for_each_opr(head, print_node);
	sig_list_del_node(head, 100);
	sig_list_for_each_opr(head, print_node);
	

	return 0;
}
