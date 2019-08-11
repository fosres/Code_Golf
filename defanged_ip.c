#include <stdio.h>
#include <string.h>

char*defanged(char*s,size_t len)
{
	
	static unsigned char defanged[12];

	memset(defanged,0x0,len);

	unsigned char * d_p = defanged;
	
	while ( *s != 0 )
	{
		if (*s=='.'){*d_p++='[';*d_p++='.';*d_p++=']';s++;}
		else {*d_p++ = *s++;}

	}

	*d_p = 0;

	return defanged;
}

int main(int argc,char**argv)
{
	printf("%s\n",defanged(argv[1],strnlen(argv[1],11)));

	return 0;
}
