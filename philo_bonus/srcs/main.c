#include "philo.h"

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	parse_args(argc, argv);
	set_base_timestamp();
	launch_simulation();
	unlink_all_sems();
	exit (0);
}
