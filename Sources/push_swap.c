/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:08 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/08 17:03:39 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_system	*sys;
	char		*str;
	t_end_list	*start;

	if (ac != 2)
		error();
	start = NULL;
	str = malloco(1);
	str[0] = '\0';
	sys = init(av);
	if (!is_walid(sys))
		return (-1);
	clean_input(sys);
	m_ab(sys, sys->size, &str);
	str_to_list(&start, str);
	simplify(&start);
	print_list(&start);
}
