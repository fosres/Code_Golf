typedef struct T
{
	struct T * l;

	struct T * r;

	int v;

} T;

typedef struct L
{
	struct L * n;

	int v;
} L;

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

L*i(L**n,int i)
{
	while(*n){n=&((*n)->n);}
	*n=(L*)calloc(1,sizeof(L));
	(*n)->v=i;
	return *n;
}


b(T*r,L*l)
{
	if(!r)return;
	b(r->l,l);
	if(!r->l&&!r->r){l=i(&l,r->v);}
	b(r->r,l);
}

print_list(L*n)
{
	while(n)
	{
		printf("%d ",n->v);n=n->n;
	}
	
	putchar(0xa);
}

main(int argc,char**argv)
{
	T*r=(T*)calloc(1,sizeof(T));
	r->v=strtol(argv[1],0,10);
	char**argv_p=&argv[1];
	while(*++argv_p){insert_root(&r,strtol(*argv_p,0,10));}
	L*l=(L*)calloc(1,sizeof(L));
	b(r,l);
	l=l->n;
	print_list(l);
}


