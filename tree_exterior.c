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

i(T*r)
{
	if(!r){return;}
	i(r->l);
	if(!r->l&&!r->r){printf("%d ",r->v);}
	i(r->r);
}
l(T*r){if(!r){return;}if(r->l||r->r)printf("%d ",r->v);l(r->l);}
ri(T*r){if(!r)return;ri(r->r);if(r->l||r->r){printf("%d ",r->v);}}
e(T*r){l(r);i(r);ri(r->r);}
main(int argc,char**argv)
{
	T*r=(T*)calloc(1,sizeof(T));
	r->v=strtol(argv[1],0,10);
	char**argv_p=&argv[1];
	while(*++argv_p){insert_root(&r,strtol(*argv_p,0,10));}
	e(r);
}

