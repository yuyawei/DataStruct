#include <stdio.h>

struct bi_node{
	int data;
	struct bi_node *parent;
	struct bi_node *lchild;
	struct bi_node *rchild;
};

/*前序遍历*/
void pre_order_traverse(struct bi_node *node)
{
	if(NULL == node)return ;

	printf("%d ", node->data);
	pre_order_traverse(node->lchild);
	pre_order_traverse(node->rchild);
}

/*中序遍历*/
void in_order_traverse(struct bi_node *node)
{
	if(NULL == node)return ;	

	in_order_traverse(node->lchild);
	printf("%d ", node->data);
	in_order_traverse(node->rchild);
}

/*后序遍历*/
void post_order_traverse(struct bi_node *node)
{
	if(NULL == node) return ;
	post_order_traverse(node->lchild);
	post_order_traverse(node->rchild);	
	printf("%d ", node->data);
}

void create_bi_tree(struct bi_node *node)
{

}

int main(void)
{

	return 0;
}
