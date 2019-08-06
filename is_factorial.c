f(int n){if(!n)return n;int p=1;for(int i=1;p<n;i++,p*=i);return p==n?1:0;}

main(int argc,char**argv)
{
	int n = strtol(argv[1],0,10);

	return f(n);
}
