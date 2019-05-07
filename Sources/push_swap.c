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
	int			fd;

	if (ac != 2)
		error();
	start = NULL;
	str = NULL;
	str = malloco(1);
	str[0] = '\0';
	sys = init(av);
	if (!is_walid(sys))
		return (-1);
	clean_input(sys);
	m_ab(sys, sys->size, &str);
	ft_printf("%s", str);
	fd = open("op", O_RDWR | O_TRUNC , S_IRWXU | S_IRWXG | S_IRWXO);
	ft_fprintf(fd, "%s", str);
	close(fd);
	//printf("sorted:%d\n", is_sorted(sys));
//	print_sys(sys);
	//str_to_list(&start, str);
	//print_list(&start);

}
