main(int argc, char ** argv)
{
	static int stack[10];

	while ( *++argv != 0x0 )
	{
		if ( **argv - 0x30 > 0 )
		{
			if ( ++stack[**argv - 0x30] > stack[**argv - 0x30 - 1] )
			{
				return 0;
			}

		}

	}	

	return 1;
}
