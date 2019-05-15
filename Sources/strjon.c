/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:09 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/08 17:41:45 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ps.h"

void	ft_append(char **str, char *add)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL)
		return ;
	tmp = (char*)malloco(strlen(*str) + strlen(add) + 1);
	while ((*str)[i])
	{
		tmp[j] = (*str)[i];
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
	free(*str);
	*str = tmp;
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
