#include "ps.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include <stdio.h>

char	*initio_el_checko(void)
{
	char		buff[100];
	char		*str;
	char		*str_tmp;
	int			fd;
	int			red;

	str = malloc(1);
	str[0] = '\0';
	fd = open("op", O_RDONLY);
	red = 1000000;
	while (red)
		red--;
	while ((red = read(0, buff, 100)) > 0)
	{
		buff[red] = '\0';
		str_tmp = str;
		str = ft_strjoin(str, buff);
		free(str_tmp);
	}
	close(fd);
	return (str);
}

int		main(int ac, char **av)
{
	t_system	*sys;
	t_end_list	*start;
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
	while (start)
	{
		start->op(sys, &str);
		start = start->next;
	}
	//print_sys(sys);
	if (is_sorted(sys))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

/*
int				get_actions(t_push_swap *push)
{
	char		act[4];
	int			cursor;
	int			r_v;

	cursor = 0;
	while ((r_v = read(0, act + cursor, 1)) > 0)
	{
		if (act[cursor] == '\n')
		{
			push->instruction = ft_strnew(cursor);
			ft_memmove(push->instruction, act, cursor);
			return (0);
		}
		else if (cursor > 3)
			return (-1);
		cursor++;
	}
	if (r_v == -1 || (act[2] != '\n' && act[3] != '\n')
	|| (act[2] == '\n' && act[3] == '\n'))
		return (-1);
	push->instruction = ft_strnew(cursor);
	ft_memmove(push->instruction, act, cursor);
	return (0);
}
*/