long double f(n)
{if ( n == 1 || n == 0 ){return 1;}return n * f(n-1);}
main(int argc,char**argv)
{printf("%.209Lf\n",f(strtol(argv[1],0,10)));}
