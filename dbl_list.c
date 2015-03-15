#include <stdio.h>
#include <stdlib.h>

struct dnode {
	struct dnode *prev;
	struct dnode *next;
	char ch;
};

/*初始化双链表头*/
void dbl_list_init(struct dnode *head)
{
	head->prev = NULL;
	head->next = NULL;
	head->ch = 'A';
}

/*双链表头部加入结点*/  
int dbl_list_add(struct dnode *head, char ch)
{
	struct dnode *new_dnode = (struct dnode *)malloc(sizeof(struct dnode));
	if(!new_dnode)
	{
		printf("new_dnode malloc erro\n");
		return -1;
	}
	new_dnode->ch = ch;
	/*如果双链表为空，只有头结点*/
	if(NULL == head->prev && NULL == head->next)
	{
		new_dnode->next = head;
		new_dnode->prev = head;
		head->next = new_dnode;
		head->prev = new_dnode;
	}
	/*如果双链表不为空*/
	else
	{
		new_dnode->next = head->next;
		new_dnode->prev = head;
		head->next->prev = new_dnode;
		head->next = new_dnode;
	}
	
	return 0;
}

/*遍历双链表，打印结点*/
void dbl_list_for_each_opr(struct dnode *head)
{
	struct dnode *cur = head;
	for(cur = head; cur->next != head; cur = cur->next)
	{
		printf("%c ", cur->ch);
	}
	printf("%c\n", cur->ch);
}

struct dnode * __dbl_list_for_each(struct dnode *head)
{
	struct dnode *tail;

	/*不需要*/

	return tail;
}

int dbl_list_tail(struct dnode *head, char ch)
{
	struct dnode *new_dnode = (struct dnode *)malloc(sizeof(struct dnode));
	if(!new_dnode)
	{
		printf("new_dnode malloc erro\n");
		return -1;
	}
	new_dnode->ch = ch;
	/*如果双链表为空，只有头结点*/
	if(NULL == head->prev && NULL == head->next)
	{
		new_dnode->next = head;
		new_dnode->prev = head;
		head->next = new_dnode;
		head->prev = new_dnode;
	}
	/*如果双链表不为空*/
	else
	{
		new_dnode->next = head;
		new_dnode->prev = head->prev;
		head->prev->next = new_dnode;
		head->prev = new_dnode;
	}
	return 0;
}

int dbl_list_del(struct dnode *head, char ch)
{
	struct dnode *cur;
	struct dnode *back;
	cur = head;
	while(cur->next != head)
	{
		struct dnode *temp = cur;
		if(temp->ch == ch)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			temp->prev = NULL;
			temp->next = NULL;
			free(temp);
			break;				/*删除单个后，重复的不再删除*/
		}
		cur = cur->next;
	}
	return 0;
}

/*判断双链表是否为空*/
/*为空：1*/
/*不为空：0*/
int is_empty_dbl_list(struct dnode *head)
{
	return (NULL == head->next && NULL == head->prev);
}

/*销毁双链表*/
int dbl_list_destroy(struct dnode *head)
{

	return 0;
}

int main(void)
{
	struct dnode *head = (struct dnode *)malloc(sizeof(struct dnode));
	if(!head)
	{
		printf("dnode malloc error\n");
		return -1;
	}
	dbl_list_init(head);
	printf("链表是否为空:%d\n", is_empty_dbl_list(head));

	dbl_list_tail(head, 'B');
	dbl_list_tail(head, 'B');
	dbl_list_tail(head, 'C');
	dbl_list_add(head, 'D');

	printf("链表是否为空:%d\n", is_empty_dbl_list(head));
	
	dbl_list_for_each_opr(head);

	dbl_list_del(head, 'B');
	dbl_list_for_each_opr(head);

	return 0;
}
