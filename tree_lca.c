#include <stdio.h>
#include <stdlib.h>

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

int M_p = 0, N_p = 0;

void endpts(T*r,T*M,T*N)
{
	if (!r)return;
	if (r==M) M_p = 1;
	if (r==N) N_p = 1;
	endpts(r->l,M,N);
	endpts(r->r,M,N);
}

T*lca(T*p,T*r,T*M,T*N)
{
	endpts(r,M,N);
	if(!M_p&&!N_p){M_p=N_p=0;return;}
	else if(M_p&&N_p){M_p=N_p=0;lca(r,r->l,M,N);M_p=N_p=0;lca(r,r->r,M,N);}
	else if(M_p^N_p){return p;}
}

main(int argc,char**argv)
{
	T*r=(T*)calloc(1,sizeof(T));
	r->v=strtol(argv[1],0,10);
	char**argv_p=&argv[1];
	while(*++argv_p){insert_root(&r,strtol(*argv_p,0,10));}
	argv_p=&argv[0];
	T*M=find_num(r,strtol(argv[2],0,10));
	T*N=find_num(r,strtol(argv[3],0,10));
	printf("lca: %p lca_v:%d\n",lca(0,r,M,N),lca(0,r,M,N)->v);	
}
