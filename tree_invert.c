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

f(T*r,int s){T*t[s];t[0]=r;T**f=&t[0],**e=&t[0];while(f<=e){if(*f){if((*f)->l){*++e=(*f)->l;}if((*f)->r){*++e=(*f)->r;}}free(*f);f++;}}

invert(T**r)
{
	if(!*r){return;}

	T*h=(*r)->l;
	(*r)->l=(*r)->r;
	(*r)->r=h;
	invert(&((*r)->l));
	invert(&((*r)->r));
}

level_order(T*r,int s)
{
	T*t[s+1];T**f=&t[0],**e=&t[0];t[0]=r;

	while(f<=e)
	{
		if((*f)->l){*++e=(*f)->l;}
		
		if((*f)->r){*++e=(*f)->r;}

		printf("%d ",(*f)->v);

		++f;
	}

	putchar(0xa);
}

main(int argc,char*argv[])
{
	T*r=(T*)calloc(1,sizeof(T));
	r->v=strtol(argv[1],0,10);
	char**argv_p=&argv[1];
	while(*++argv_p){insert_root(&r,strtol(*argv_p,0,10));}
	invert(&r);	
	level_order(r,argc-1);
	f(r,argc-1);
}

