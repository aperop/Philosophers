#include "philo.h"

static void	kill_processes(t_philo **philos, unsigned long i)
{
	while (i != 0)
	{
		i--;
		kill((*philos)[i].pid, 9);
	}
}

void	end_simulation(t_philo **philos, unsigned long i)
{
	t_setup			*setup;
	pid_t			wait_for_satisfied;

	setup = get_setup();
	if (i != setup->num_philos)
	{
		sem_wait(setup->prompt);
		print_message(PROCESS_ERROR);
		kill_processes(philos, i);
		return ;
	}
	wait_for_satisfied = fork();
	if (wait_for_satisfied == 0)
	{
		while (i > 0)
		{
			i--;
			sem_wait(setup->satisfied);
		}
		exit (0);
	}
	waitpid(-1, 0, 0);
	kill_processes(philos, setup->num_philos);
	kill(wait_for_satisfied, 9);
}
