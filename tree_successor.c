
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

T*find_num(T*r,int target)
{
	if (!r)return 0;
	if (r->v==target){return r;}
	else if(target<r->v){find_num(r->l,target);}
	else{find_num(r->r,target);}	
}

_Bool I=0;
s(T*r,T*i)
{if(!r)return;s(r->l,i);if(I){printf("%p %d\n",r,r->v);I=0;return;}if(r==i){I=1;}s(r->r,i);}

main(int argc,char**argv)
{
	T*r=(T*)calloc(1,sizeof(T));
	r->v=strtol(argv[3],0,10);
	char**argv_p=&argv[3];
	while(*++argv_p){insert_root(&r,strtol(*argv_p,0,10));}
	T*M=find_num(r,strtol(argv[1],0,10));
	s(r,M);
}

