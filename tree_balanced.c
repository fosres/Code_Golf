#include <stdio.h>
#include <stdlib.h>

typedef struct T
{
	struct T * l;

	struct T * r;

	int v;

} T;

void insert_root(T ** root, int in)
{
  if (!*root)
  {
    *root = (T *)calloc(1,sizeof(T));

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

h(T*r){r=r?1+h(h(r->l)>h(r->r)?r->l:r->r):0;}

b(T*r)
{
	if (r->l&&!b(r->l))return 0;
	if (r->r&&!b(r->r))return 0;
	
	return abs(h(r->l)-h(r->r)) <= 1;
}
int main(int argc,char**argv)
{
	T * r = (T *)calloc(1,sizeof(T));

	r->v = strtol(argv[1],0,10);

	argv = &argv[1];

	while(*++argv){insert_root(&r,strtol(*argv,0,10));}
	
	return b(r);	
}
