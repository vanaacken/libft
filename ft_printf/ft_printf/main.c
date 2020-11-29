#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	main(void)
{
  // ft_printf("%p", NULL);
char c = 66;  
int		tab[7] = {-135, -12, -1, 0, 1, 13, 198};
int i = 0;

while (i < 7)
{
  ft_printf("[index: %i-->|%.c|<--]\n", i, tab[i]);
  i++;
}
i = 0;
FILE *f2 = fopen("printf.txt", "w");
if (f2 == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}
while (i < 7)
{
  fprintf(f2,"[index: %i-->|%.c|<--]\n",i ,tab[i]); 
  i++;
}
fclose(f2);
  //printf("{%d}\n", 42);

  // ft_printf("{%*c}\n", -15, 0);
  // printf("{%*c}\n", -15, 0);

// printf("[%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c]\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
// ft_printf("[%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c]\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
// - [OUTPUT] ft_printf("{%3c}", 0)
//    expected: "{  "
//    actual:   "{  }"

// - [OUTPUT] ft_printf("{%*c}", 0, 0)
//    expected: "{"
//    actual:   "{}"

// - [OUTPUT] ft_printf("{%*c}", -15, 0)
//    expected: "{"
//    actual:   "{}"
//   return (1);
}

//% -> Flags -> min field width -> period -> precision max field width -> argument type