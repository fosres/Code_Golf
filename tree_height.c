typedef struct tree
{
	struct tree * l;

	struct tree * r;

	int v;

} tree;

insert_root(tree ** root, int in)
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

int t = 0, c = 0;

h(tree * r)
{
	if ( r->l == 0 && r->r == 0 )
	{
		if ( c > t ){t=c;}
					
		c--; return;
	}	
	
	if ( h(r->l) ){c++;h(r->l);}
	
	if ( h(r->r) ){c++;h(r->r);}
}
