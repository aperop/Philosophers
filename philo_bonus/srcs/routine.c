#include "philo.h"

void	grab_forks(t_philo *philo)
{
	unsigned long	timestamp;
	t_setup			*setup;

	setup = get_setup();
	sem_wait(setup->forks);
	philo->state = grabbing_forks;
	timestamp = get_timestamp_in_ms();
	sem_wait(setup->prompt);
	write_prompt(grabbing_forks, philo->index + 1, timestamp);
	sem_post(setup->prompt);
	if (setup->num_philos == 1)
	{
		better_usleep(setup->time_to_die * 1000 + 500);
		return ;
	}
	sem_wait(setup->forks);
	timestamp = get_timestamp_in_ms();
	sem_wait(setup->prompt);
	write_prompt(grabbing_forks, philo->index + 1, timestamp);
	sem_post(setup->prompt);
	return ;
}

void	eat(t_philo *philo)
{
	unsigned long	timestamp;
	t_setup			*setup;

	setup = get_setup();
	timestamp = get_timestamp_in_ms();
	sem_wait(setup->prompt);
	philo->state = eating;
	philo->last_fed = timestamp;
	philo->meals++;
	write_prompt(eating, philo->index + 1, timestamp);
	if (philo->meals == setup->max_meals)
		sem_post(setup->satisfied);
	sem_post(setup->prompt);
	better_usleep(setup->time_to_eat * 1000);
	sem_post(setup->forks);
	if (setup->num_philos == 1)
		return ;
	sem_post(setup->forks);
	return ;
}

void	nap(t_philo *philo)
{
	unsigned long	timestamp;
	t_setup			*setup;

	setup = get_setup();
	sem_wait(setup->prompt);
	timestamp = get_timestamp_in_ms();
	philo->state = sleeping;
	write_prompt(sleeping, philo->index + 1, timestamp);
	sem_post(setup->prompt);
	better_usleep(setup->time_to_sleep * 1000);
	return ;
}

void	think(t_philo *philo)
{
	unsigned long	timestamp;
	t_setup			*setup;

	setup = get_setup();
	sem_wait(setup->prompt);
	timestamp = get_timestamp_in_ms();
	philo->state = thinking;
	write_prompt(thinking, philo->index + 1, timestamp);
	sem_post(setup->prompt);
	return ;
}
