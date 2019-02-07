#include "ps.h"

int main(int ac, char **av)
{
	t_system *sys;

	sys = init(ac, av);
	pa(sys);
	print_sys(sys);
	ra(sys);
	pb(sys);
		print_sys(sys);
}
