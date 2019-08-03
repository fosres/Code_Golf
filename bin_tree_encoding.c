#include <stdio.h>

typedef struct node
{
	struct node * left, * right;

	int data;
}node;

size_t len = 0;

length(node * root)
{
	if ( root == 0x0 )
	{ return; }

	if ( root->left != 0 )
	{
		length(root->left);
	}

	len++;

	if ( root->right != 0 )
	{
		length(root->right);
	}
}

int * encode( node * root)
{
	length(root);	

	int en[len]; int * en_p;
	
	memset(en,0,len*4); len = 0;

	
}
