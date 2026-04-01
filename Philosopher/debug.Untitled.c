void	wait_simulation(t_sim *sim)
{
	unsigned int	i;

	i = 0;
	while (i < sim->nb_philos)
	{
		pthread_join(sim->philos[i]->thread, NULL);
		i++;
	}
	if (sim->nb_philos > 1)
		pthread_join(sim->steward, NULL);
}

backup//


static void	eat_sleep_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->simu->fork_lock[philo->left_fork]);
	print_status(philo, 1, HAS_LEFT_FORK);
	pthread_mutex_lock(&philo->simu->fork_lock[philo->right_fork]);
	print_status(philo, 1, HAS_RIGHT_FORK);
	print_status(philo, 1, IS_EATING);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(&philo->meal_time_lock);
	sleep_routine(philo->simu, philo->simu->time_to_eat);
	if (check_stop_flag(philo->simu) == 1)
	{
		pthread_mutex_lock(&philo->meal_time_lock);
		philo->meal_eaten += 1;
		pthread_mutex_unlock(&philo->meal_time_lock);
	}
	print_status(philo, 1, IS_SLEEPING);
	pthread_mutex_unlock(&philo->simu->fork_lock[philo->right_fork]);
	pthread_mutex_unlock(&philo->simu->fork_lock[philo->left_fork]);
	sleep_routine(philo->simu, philo->simu->time_to_sleep);	
}

modified backup

static void	eat_sleep_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->simu->fork_lock[philo->left_fork]);
	print_status(philo, 1, HAS_LEFT_FORK);
	pthread_mutex_lock(&philo->simu->fork_lock[philo->right_fork]);
	print_status(philo, 1, HAS_RIGHT_FORK);
	print_status(philo, 1, IS_EATING);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = get_time_ms();
	sleep_routine(philo->simu, philo->simu->time_to_eat);
	if (check_stop_flag(philo->simu) == 1)
		philo->meal_eaten += 1;
	pthread_mutex_unlock(&philo->meal_time_lock);
	print_status(philo, 1, IS_SLEEPING);
	pthread_mutex_unlock(&philo->simu->fork_lock[philo->right_fork]);
	pthread_mutex_unlock(&philo->simu->fork_lock[philo->left_fork]);
	sleep_routine(philo->simu, philo->simu->time_to_sleep);	
}
