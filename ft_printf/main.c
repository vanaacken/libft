#include <stdio.h>

int	main(void)
{
	int number = 42;
	printf("abcdef%dghij\n", number);
    printf(" %-10d \n", number);
    printf("[%-15.10d ]\n", number);  
    printf(" %#x \n", number);

}

//% -> Flags -> min field width -> period -> precision max field width -> argument type