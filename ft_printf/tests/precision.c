
#include "ft_printf.h"

int		main(void)
{

	ft_printf("\nMine:\n");
	ft_printf("%% 4.5i |% 4.5i|", 42);

	ft_printf("\n\nOriginal:\n");
	printf("%% 4.5i |% 4.5i|\n", 42);

	return (0);
}
