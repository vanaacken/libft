#include <stdio.h>

int	main(void)
{
	int number = 42;
	printf("abcdef%dghij\n", number);
    printf(" %010d \n", number);
    printf(" %.10x \n", number);  
    printf(" %#x \n", number);

}

//% -> Flags -> min field width -> period -> precision max field width -> argument type