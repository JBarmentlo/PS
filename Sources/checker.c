#include "ps.h"
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include <stdio.h>

char	*initio_el_checko(void)
{

	char		buff[551];
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
	while ((red = read(fd, buff, 550)) > 0)
	{
		buff[red] = '\0';
		str_tmp = str;
		str = ft_strjoin(str, buff);
		free(str_tmp);
	}
	close(fd);
	return(str);
}

int		main(int ac, char **av)
{
	t_system	*sys;
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
	//printf("%s", str);
	str_to_list(&start, str);
	free(str);
	str = malloc(1);
	str[0] = '\0';
	it = start;
	while (it)
	{
		it->op(sys, &str);
		it = it->next;
	}
	//print_sys(sys);
	//print_list(&start);
	if (is_sorted(sys))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}