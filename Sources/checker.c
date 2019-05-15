/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:07 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/15 14:59:28 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

char	*initio_el_checko(void)
{
	char		buff[100];
	char		*str;
	char		*str_tmp;
	int			red;

	str = malloc(1);
	str[0] = '\0';
	while ((red = read(0, buff, 100)) > 0)
	{
		buff[red] = '\0';
		str_tmp = str;
		str = ft_strjoin(str, buff);
		free(str_tmp);
	}
	return (str);
}

int		main(int ac, char **av)
{
	t_s			*sys;
	t_end_list	*start;
	t_end_list	*it;
	char		*str;

	start = NULL;
	if (ac != 2)
		error();
	sys = init(av);
	if (!is_walid(sys))
		return (-1);
	clean_input(sys);
	str = initio_el_checko();
	str_to_list(&start, str);
	free(str);
	str = malloc(1);
	str[0] = '\0';
	it = start;
	while (it)
	{
		it->op(sys, NULL);
		it = it->next;
	}
	if (is_sorted(sys))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	sys_free(sys);
	free(str);
	free_end_list(&start);
}
