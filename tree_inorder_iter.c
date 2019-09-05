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


inorder(T**r,int s)
{
	T*t[s+1];memset(t,0,sizeof(T)*(s+1));t[0]=*r;T**f=&t[0],*h=0;

	while(f>=&t[0])
	{
		while(*f)
		{
			if((*f)->l){*(f+1)=(*f)->l;++f;}
		}
		
		while( (f>=&t[0]) && !((*f)->r) )
		{
			printf("%d ",(*f)->v);

			*f--=0;
		}

		if( (f>=&t[0]) && (*f)->r ){h=(*f)->r;printf("%d ",(*f)->v);*f=h;}
	}

	putchar(0xa);

}

f(T*r,int s)
{
	T*t[s];t[0]=r;T**f=&t[0],**e=&t[0];
	
	while(f<=e)
	{
		if(*f)
		{
			if((*f)->l)
			{
				*++e=(*f)->l;
			}

			if((*f)->r)
			{
				*++e=(*f)->r;
			}
		}

		printf("%p:%d ",*f,(*f)->v);free(*f);f++;
	}
	putchar(0xa);
}

level_order(T*r,int s)
{
	T*t[s+1];T**f=&t[0],**e=&t[0];t[0]=r;

	while(f<=e)
	{
		if((*f)->l){*++e=(*f)->l;}
		
		if((*f)->r){*++e=(*f)->r;}

		printf("%p: %d ",(*f),(*f)->v);

		++f;
	}

	putchar(0xa);
}


i(T*r){if(!r){return;}i(r->l);printf("%d ",r->v);i(r->r);}

main(int argc,char*argv[])
{
	T*r=(T*)calloc(1,sizeof(T));
	r->v=strtol(argv[1],0,10);
	char**argv_p=&argv[1];
	while(*++argv_p){insert_root(&r,strtol(*argv_p,0,10));}
	inorder(r,argc-1);
	printf("Level order: ");
	level_order(r,argc-1);
	printf("Free order: ");
	f(r,argc-1);
}

