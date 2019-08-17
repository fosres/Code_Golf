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

int depth=0,max=0;

d(T*r)
{
	if(!r)return;

	depth++;d(r->l);depth--;
	
	if(!r->l&&!r->r)
	{
		if( depth > max)
		{ max = depth; printf("\r%d: %d \0",max,r->v); }

		else
		{
			printf("%d \0",r->v);
		}

	}

	depth++;d(r->r);depth--;
}

main(int argc,char**argv)
{
	T*r=(T*)calloc(1,sizeof(T));
	r->v=strtol(argv[1],0,10);
	char**argv_p=&argv[1];
	while(*++argv_p){insert_root(&r,strtol(*argv_p,0,10));}
	d(r);putchar(0xa);
}

