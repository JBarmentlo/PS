/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:08 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/15 15:16:47 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_s			*sys;
	t_end_list	*start;

	if (ac != 2)
		error();
	start = NULL;
	sys = init(av);
	if (!is_walid(sys))
		return (-1);
	clean_input(sys);
	m_ab(sys, sys->size, &start);
	simplify(&start);
	print_list(&start);
	sys_free(sys);
	free_end_list(&start);
	return (1);
}
