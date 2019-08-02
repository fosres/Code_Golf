#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
	struct tree * left;

	struct tree * right;

	int val;

} tree;


static int * test_p = 0;

void insert(tree * root, const int val)
{
	if ( (root->left == 0x0) && (val < root->val) )
	{
		root->left = (tree *)calloc(1,sizeof(tree));

		root->left->val = val;
	}

	else if ( (root->right == 0x0) && (val >= root->val) )
	{
		root->right = (tree *)calloc(1,sizeof(tree));

		root->right->val = val;
	}
	
	else if ( val < root->val )
	{
		insert(root->left,val);	
	}

	else if ( val >= root->val )
	{
		insert(root->right,val);	
	}
}

void preorder(tree * root,int * test_p)
{
	if ( root == 0x0 ) { return; }

	*test_p++ = root->val;

	preorder(root->left,test_p);

	preorder(root->right,test_p);

}

int main(int argc, char ** argv)
{
	int test_list[argc-1];

	memset(test_list,0,argc*sizeof(int));
	
	test_p = test_list;
	
	tree * root = (tree *)calloc(1,sizeof(tree));

	root->val = strtol(argv[1],0x0,10);

	int i = 1;

	while ( argv[++i] != 0x0 )
	{
		insert(root,strtol(argv[i],0x0,10));
	}

	preorder(root,test_p);

	test_p = test_list;

	i = 1;

	while ( ( i < argc ) )
	{
		if ( *test_p != strtol(argv[i],0x0,10) )
		{
			return 0;
		}

		test_p++;

		i++;
	}

	return 1;	
	
}

