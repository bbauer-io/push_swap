









#include "libft.h"
#include "ft_printf.h"

int  main(void)
{
	wchar_t *draft = L"Á±≥猫δ요莨ي我是一只猫。米";
	wchar_t *draft2;
	char *utf8_draft;

	draft2 = ft_wstrdup(draft);
	utf8_draft = ft_utf8strencode(draft2);
	ft_putstr(utf8_draft);
	ft_printf("\n%S\n", draft);
	return (0);
}
