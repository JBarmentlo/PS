#include "ps.h"
#include <stdio.h>
#include <stdlib.h>

int		*gen_list(int	size)
{
	int	*out;
	int	i;

	out = (int*)malloco(size * 4);
	i = 0;
	while (i < size)
	{
		out[i] = -1;
		i++;
	}
	return (out);
}

int		test_lst(int *lst, int size)
{
	int	i;
	int	j;

	i = 0;
//	printf("TESTin\n");
	while (i + 1 < size && lst[i] != -1)
	{
		j = i + 1;
		while (j < size && lst[j] != -1)
		{
			if (lst[i] == lst[j])
			{
//				printf("TESTout\n");
				return (0);
			}
			j++;
		}
		i++;
	}
//	printf("TESTout\n");
	return (1);
}

int		baktrak(int *lst, int pos, int size)
{
	if (pos == size)
		return (1);
	if (pos == -1)
		return (0);
	while (lst[pos] < size)
	{
		if (test_lst(lst, pos + 1) && lst[pos] != -1)
			if (baktrak(lst, pos + 1, size))
				return (1);
		lst[pos] = lst[pos] + 1;
	}
	lst[pos] = -1;
	return (0);
}

void	printer(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	intotab(int	*ints, char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab[i][0] = ints[i] / 10 + '0';
		tab[i][1] = ints[i] % 10 + '4';
		tab[i][3] = '\0';
		i++;
	}
}

void		daman(void)
{
	char	**tab;
	int		*ints;
	int		i;
	t_system	*sys;
	char		*str;
	FILE 		*fd;
	char		*filename;

	filename = strdup("trees/000000");
	str = malloco(1);
	str[0] = '\0';
	tab = malloco(sizeof(char*) * 15);
	i = 4;
	while (i < 10)
	{
		tab[i] = (char*)malloco(3);
		tab[i][1] = '\0';
		tab[i][2] = '\0';
		i++;
	}
	ints = gen_list(6);
	tab[0] = strdup("3");
	tab[1] = strdup("0");
	tab[2] = strdup("1");
	tab[3] = strdup("2");

	tab[10] = strdup("10");
	tab[11] = strdup("11");
	tab[12] = strdup("12");
	tab[13] = strdup("13");
	while (baktrak(ints, 0, 6))
	{
		intotab(ints, tab + 4, 6);
		printer(tab + 1, 12);

		sys = init(13, tab);
		clean_input(sys);
		pa(sys, NULL);
		pa(sys, NULL);
		pa(sys, NULL);
		print_sys(sys);
		rec_start(sys, &str);
		print_sys(sys);
		filename[6] = '0' + ints[0];
		filename[7] = '0' + ints[1];
		filename[8] = '0' + ints[2];
		filename[9] = '0' + ints[3];
		filename[10] = '0' + ints[4];
		filename[11] = '0' + ints[5];
		fd = fopen(filename, "a");
		printf("filename :%s \nstr %s\n",filename, str);
		fputs(str, fd);
		fclose(fd);
		free(str);
		str = malloco(1);
		str[0] = '\0';
		sys_free(sys);

		ints[5] = ints[5] + 1;
		printf("\n\n");
		i++;
	}




}

