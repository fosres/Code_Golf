main()
{
	int a[3]; a[0] = 1; a[1] = 2; a[2] = 3;
	
	int b[3];
	memcpy(b,a,3*sizeof(int));
	
	int i = 0;

	while ( i < 3 )
	{
		printf("%d ",b[i]);
		i++;
	}
}
