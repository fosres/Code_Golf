#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	struct tree * l;

	struct tree * r;

	int v;

} tree;

void insert_root(tree ** root, int in)
{
  if (!*root)
  {
    *root = (tree *)calloc(1,sizeof(tree));

    (*root)->v = in;

    return;
  }

  else if (in < (*root)->v)
  {
    insert_root(&((*root)->l),in);
  }

  else
  {
    insert_root(&((*root)->r),in);
  }
}

int max(int l,int r)
{
	if ( l > r )return l;
	else return r;
}

int height(tree * r)
{
	if (!r) return 0;

	int lsubheight = 1+height(r->l);

	int rsubheight = 1+height(r->r);

	return max(lsubheight,rsubheight);
}

int main(int argc,char**argv)
{
	tree * r = (tree *)calloc(1,sizeof(tree));

	r->v = strtol(argv[1],0,10);

	argv = &argv[1];

	while(*++argv){insert_root(&r,strtol(*argv,0,10));}
	
	return height(r);	
}
