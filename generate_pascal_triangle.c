row(int s[],int o[],int i)
{
	if(i==2){printf("%d %d\n",i,i);o[0]=1;o[1]=1;}
	else if(i==1){printf("%d\n",i);o[0]=1;}
	else
	{
		int j = 0; int *s_p=s,*o_p=o;*o_p++ =1;printf("1 ");
		while(j<i){*o_p+=*s_p++;*o_p++ += *s_p;printf("%d ",*(o_p-1));j++;}
		*o_p=1;printf("1 ");puts("");
	}
}

main(int argc,char ** argv)
{
	int n = strtol(argv[1],0,10);

	static int s[25], o[25];

	memset(s,0,100); memset(o,0,100);

	int i = 1;

	while (i <= n){row(s,o,i);memset(s,0,100);memcpy(s,o,100);memset(o,0,100);i++;}

}


