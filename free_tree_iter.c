typedef struct T
{
	struct T * left;

	struct T * right;

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
    insert_root(&((*root)->left),in);
  }

  else
  {
    insert_root(&((*root)->right),in);
  }
}

f(T*r,int s)
{
	T*t[s];t[0]=r;T**f=&t[0],**e=&t[0];
	
	while(f<=e)
	{
		if(*f)
		{
			if((*f)->left)
			{
				*++e=(*f)->left;
			}

			if((*f)->right)
			{
				*++e=(*f)->right;
			}
		}

		printf("%p:%d ",*f,(*f)->v);free(*f);f++;
	}
	putchar(0xa);
}

#if 0 
//Normal Verson:
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
#endif

#if 0
//Competitive version
f(T*r,int s){T*t[s];t[0]=r;T**f=&t[0],**e=&t[0];while(f<=e){if(*f){if((*f)->left){*++e=(*f)->left;}if((*f)->right){*++e=(*f)->right;}}free(*f);f++;}}
#endif

main(int argc,char**argv)
{
	T*r=(T*)calloc(1,sizeof(T));
	r->v=strtol(argv[1],0,10);
	char**argv_p=&argv[1];
	while(*++argv_p){insert_root(&r,strtol(*argv_p,0,10));}
	f(r,argc-1);
}

