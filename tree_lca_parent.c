#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct T
{
	struct T * l;

	struct T * r;

	struct T * p;

	int v;

} T;

void insert_root(T** parent, T ** root, int in)
{
  if (!*root)
  {
    *root = (T *)calloc(1,sizeof(T));

    (*root)->v = in;

    (*root)->p = *parent;

    return;
  }

  else if (in < (*root)->v)
  {
    insert_root(root,&((*root)->l),in);
  }

  else
  {
    insert_root(root,&((*root)->r),in);
  }
}

T*find_num(T*r,int target)
{
	if (!r)return 0;
	if (r->v==target){return r;}
	else if(target<r->v){find_num(r->l,target);}
	else{find_num(r->r,target);}	
}

bool F=0,S=0;

endpts(T*r,T*M,T*N)
{
	if(!r)return;
	endpts(r->l,M,N);endpts(r->r,M,N);
	if(r==M)F=1;
	if(r==N)S=1;
	if(F&&S)return;	
}

T*p(T*M,T*N)
{
	T*m=M,*p=m;
	
	while(!F||!S)
	{
		F=0;S=0;

		endpts(m,M,N);		

		p=m;m=m->p;
	}

	return p;
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
	r->v=strtol(argv[3],0,10);
	char**argv_p=&argv[3];
	while(*++argv_p){insert_root(0,&r,strtol(*argv_p,0,10));}
	in_order(r);putchar(0xa);
	T*M=find_num(r,strtol(argv[1],0,10));
	T*N=find_num(r,strtol(argv[2],0,10));
	printf("M_v:%d N_v:%d\n",M->v,N->v);
	printf("lca: %p lca_v: %d\n",p(M,N),p(M,N)->v);	
}
