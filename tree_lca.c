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

int F = 0, S = 0;

T*endpts(T*r,T*M,T*N)
{
	if(!r)return;
	if (r==M)F=1;
	if (r==N)S=1;
	if(F&&S)return;	
	endpts(r->l,M,N);
	if(F&&S)return;
	endpts(r->r,M,N);
	if(F&&S)return;
}

T*lca(T*p,T*r,T*M,T*N)
{
	if(!r){return 0;}
	
	F=S=0;

	endpts(r,M,N);
	
	if(F==0 && S==0){return 0;}
	
	else if(F==1^S==1){return p;}
	
	if (lca(r,r->l,M,N)) return lca(r,r->l,M,N);

	if (lca(r,r->r,M,N)) return lca(r,r->r,M,N);
		
	return 0;	
		
}

main(int argc,char**argv)
{
	T*r=(T*)calloc(1,sizeof(T));
	r->v=strtol(argv[3],0,10);
	char**argv_p=&argv[3];
	while(*++argv_p){insert_root(&r,strtol(*argv_p,0,10));}
	T*M=find_num(r,strtol(argv[1],0,10));
	T*N=find_num(r,strtol(argv[2],0,10));
	endpts(r,M,N);
	printf("F:%d S:%d\n",F,S);
	printf("lca: %p lca_v: %d\n",lca(0,r,M,N),lca(0,r,M,N)->v);	
}
