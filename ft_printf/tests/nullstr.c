
#include "ft_printf.h"

int		main(void)
{
	char	*nullstr;

	nullstr = NULL;
	ft_printf("\nnull string: %s\n", nullstr);
	ft_printf("{%s}", 0);

return (0);
}
