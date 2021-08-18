#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char *h = "he'l'''''l'o w'or'ld'";
	printf("-<%s>-\n-<%s>-\n", h, ft_strtrd(h, "hl '"));
	char *s = "   he ello'dark'ne  ss my 'o l d' friend ";
	for (int i = 0; i < ft_strlen(s); i++)
		printf("%c", "1234567890"[i % 10]);
	printf("\n%s\n", s);
	char **t = ft_qsplit(s, ' ');
	int i = -1;
	while (t[++i])
		printf("=>%s<=\n", t[i]);
	ft_purge2str(t);
	return (0);
}
