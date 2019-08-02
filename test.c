main()
{
	double f = 3.25;

	unsigned long long int a = 0;

	memcpy(&a,&f,8);

	printf("f:%f byte_arr:%f\n",f,a);	
}
