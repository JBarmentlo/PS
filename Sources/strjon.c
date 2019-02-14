#include <stdlib.h>
#include <string.h>
#include "ps.h"

#include <stdio.h>
void	ft_append(char **str, char *add) //no null handling
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;

	if (str == NULL)
		return ;
	tmp = (char*)malloco(strlen(*str) + strlen(add) + 1);
//	printf("in\n");
	while ((*str)[i])
	{
		tmp[j] = (*str)[i];
		j++;
		i++;
	}
//	printf("in\n");
	i = 0;
	while (add[i])
	{
		tmp[j] = add[i];
		j++;
		i++;
	}
//	printf("in\n");
	tmp[j] = '\0';
//	printf("in\n");
	free(*str);
	*str = tmp;
//	printf("out\n");
}

char	*ft_strappend(char *str, char *add)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = (char*)malloco(strlen(str) + strlen(add) + 1);
	while (str[i])
	{
		tmp[j] = str[i];
		j++;
		i++;
	}
	i = 0;
	while (add[i])
	{
		tmp[j] = add[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	free(str);
	str = tmp;
	return (str);
}
