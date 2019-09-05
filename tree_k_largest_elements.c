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

int IN_RANGE=0;
int k=0;
kl(T*r)
{
	if((!r)&&!IN_RANGE)
	{
		IN_RANGE=1;

		return;
	}

	if(!r){return;}

	kl(r->r);

	if(IN_RANGE&&(k>0)){printf("%d ",r->v);k--;}

	kl(r->l);
}

main(int argc,char**argv)
{
	T*r=(T*)calloc(1,sizeof(T));
	r->v=strtol(argv[1],0,10);
	char**argv_p=&argv[1];
	while(*++argv_p){insert_root(&r,strtol(*argv_p,0,10));}
	k=7;	
	kl(r);
}

