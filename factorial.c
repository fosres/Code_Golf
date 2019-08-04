long double f(n){return!n?1:n*f(n-1);}
//long double f(n){return(n<2)?1:n*f(n-1);}

main(int argc,char**argv)
{printf("%.209Lf\n",f(strtol(argv[1],0,10)));}
