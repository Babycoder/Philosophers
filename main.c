/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 08:46:00 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/20 15:19:36 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timestamp(t_philo *philo)
{
	return ((get_time() - philo->data->entry_time) / 1000);
}

void	*ft_philosophers(t_philo *philo)
{
	while (1)
	{
		if (philo->num_meal == philo->data->num_of_meals
			&& philo->data->num_of_meals != 0)
			break ;
		pthread_mutex_lock(&philo->mutex);
		printf("%ld %d has taken a fork\n", timestamp(philo), philo->id);
		pthread_mutex_lock(&philo->next->mutex);
		printf("%ld %d has taken a fork\n", timestamp(philo), philo->id);
		printf("%ld %d is eating\n", timestamp(philo), philo->id);
		philo->last_meal = get_time();
		philo->num_meal += 1;
		ft_usleep(philo->data->time_to_eat);
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&philo->next->mutex);
		printf("%ld %d is sleeping\n", timestamp(philo), philo->id);
		ft_usleep(philo->data->time_to_sleep);
		printf("%ld %d is thinking\n", timestamp(philo), philo->id);
	}
	return (NULL);
}

int	main(int ac, char *av[])
{
	int		i;
	t_data	data;
	t_philo	*philo;

	i = 0;
	philo = NULL;
	if (check_data(av) == 1)
		return (ft_error(ac));
	if (store_data(av, &data) == 1)
		return (EXIT_SUCCESS);
	if (data.num_of_philo <= 0)
		return (EXIT_FAILURE);
	while (i < data.num_of_philo)
	{
		fill_philo(&philo, (i + 1), &data);
		i++;
	}
	ft_threads(philo);
	ft_supervisor(philo);
	deleteList(&philo);
	return (EXIT_SUCCESS);
}
