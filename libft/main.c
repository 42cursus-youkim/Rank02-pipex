#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char *s = "   he ello'dark'ne   ss my 'o l d' friend";
	printf("->%s<-\n", s);
	char **t = ft_qsplit(s, ' ');
	int i = -1;
	while (t[++i])
		printf("=>%s<=\n", t[i]);
	ft_purge2str(t);
	return (0);
}