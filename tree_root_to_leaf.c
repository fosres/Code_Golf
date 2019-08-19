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

static char * stack_p=&stack[0]-1;unsigned long long int a=0,b=0;

ri(T*r)
{
if(!r)return;
a|=r->v;
if(!r->l&&!r->r){b+=a;return;}
a<<=1;ri(r->l);a>>=1;a<<=1;ri(r->r);a>>=1;
}

in_order(T*r)
{
if(!r)return;
in_order(r->l);
printf("%d ",r->v);
in_order(r->r);
}

main(int argc,char**argv)
{
	T*r=(T*)calloc(1,sizeof(T));
	r->v=argv[1][0]-0x30;	
	char**argv_p=&argv[1];
	while(*++argv_p){insert_root(&r,**argv_p-0x30);}
	in_order(r);printf("\n");
	ri(r);
	printf("%llu\n",b);
}
