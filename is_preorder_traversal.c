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

void insert_root(tree ** root, int in)
{
  if (*root == NULL)
  {
    *root = (tree *)calloc(1,sizeof(tree));

    (*root)->val = in;

    return;
  }

  else if (in < (*root)->val)
  {
    insert_root(&((*root)->left),in);
  }

  else
  {
    insert_root(&((*root)->right),in);
  }
}

void preorder(tree * root)
{
	if ( root == 0x0 ) {  return; }
	
		*test_p++ = root->val;

		preorder(root->left);

		preorder(root->right);

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
		insert_root(&root,strtol(argv[i],0x0,10));
	}
	
	preorder(root);
	
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

