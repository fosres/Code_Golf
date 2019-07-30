
main(int argc, char * argv[])
{
	const int i = strtol(argv[3],0x0,10);

	char temp = argv[1][i];

	argv[1][i] = argv[2][i];

	argv[2][i] = temp;

	while ( *++argv != argv[3] )
	{
		while ( **argv != 0x0 )
		{
			putchar(**argv); putchar(0xa); (*argv)++;
		}

		putchar(0xa);
	}
	
	return 0;
}
