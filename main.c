#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "ft_utils.h"

int	main()
{
	int		i;
	char	**str;

	str = ft_split("bcabcabc42Tokyoabcabcabacabc42Tokyoabcabcabcabc", "abc");
	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}

	printf("%ld\n", ft_strtol("123", NULL, 10));
	return (0);
}
