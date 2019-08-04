#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void row(int s[],int o[],int n)
{	int h = 1;

	while (h <= n)
	{
	
	if(h==2){printf("%d %d\n",1,1);o[0]=1;o[1]=1;}
	
	else if(h==1){printf("%d\n",1);o[0]=1;}

	else
	{
		int j = 0; int *s_p=s,*o_p=o;*o_p++ =1;printf("1 ");

		while(j<(h-2))
		{
			*o_p += *s_p++;
			
			*o_p++ += *s_p;
			
			printf("%d ",*(o_p-1));
			
			j++;
		}
		
		*o_p=1;printf("1 ");puts("");
	}
		memset(s,0,100);memcpy(s,o,100);memset(o,0,100);h++;

	}
	
}

int main(int argc,char ** argv)
{
	const int n = strtol(argv[1],0,10);

	static int s[25], o[25];

	memset(s,0,100); memset(o,0,100);
	
	row(s,o,n);
}


