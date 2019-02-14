#include <string.h>

int		str_rm_part(char *str, int begin, int size)
{
	while (str[begin + size])
	{
		str[begin ] = str[begin + size];
		begin++;
	}
	str[begin] = '\0';
	return (1);
}

int		clean_str(char *str)
{
	int	i;
	int	done;

	i = 0;
	done = 1;
	while (str[i + 4])
	{
		if (str[i] == 'p' && str[i + 1] == 'a')
			if (str[i + 3] == 'p' && str[i + 4] == 'b')
			{
				done = 0;
				str_rm_part(str, i, 6);
			}
		if (str[i] == 'p' && str[i + 1] == 'b')
			if (str[i + 3] == 'p' && str[i + 4] == 'a')
			{
				done = 0;
				str_rm_part(str, i, 6);
			}
		i++;
	}
	return (done);
}
