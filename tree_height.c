typedef struct tree
{
	struct tree * l;

	struct tree * r;

	int v;

} tree;

i(tree ** r, int in)
{
  if (*r == 0)
  {
    *r = (tree *)calloc(1,sizeof(tree));

    (*r)->v = in;

    return;
  }

  else if (in < (*r)->v)
  {
    i(&((*r)->l),in);
  }

  else
  {
    i(&((*r)->r),in);
  }
}



int t = 0, c = 0;

height(tree * r)
{
	if (!r){if(c>t){t=c;}return;}

	if ( r->l){ c++;height(r->l);}
	
	c--;

	if ( r->r){c++;height(r->r);}
	
	c--;

}

main(int argc,char**argv)
{
	tree * r = (tree *)calloc(1,sizeof(tree));

	while(*++argv != 0){i(&r,strtol(*argv,0,10));}
	
	height(r);

	return t;
	

}
