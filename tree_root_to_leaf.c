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

static char stack[65];

static char * stack_p=&stack[0]-1;unsigned long long int a=0;

ri(T*r)
{
*++stack_p=r->v+0x30;
if(!r->l&&!r->r){a+=strtol(stack,0,2);return;}
ri(r->l);*stack_p--=0;ri(r->r);*stack_p--=0;
}

main(int argc,char**argv)
{
	T*r=(T*)calloc(1,sizeof(T));
	r->v=strtol(argv[1],0,10);
	char**argv_p=&argv[1];
	while(*++argv_p){insert_root(&r,strtol(*argv_p,0,10));}
	ri(r);
	printf("%llu",a);
}
