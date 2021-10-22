/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:16:51 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/22 12:32:01 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timestamp(t_philo *philo)
{
	return ((get_time() - philo->data->entry_time) / 1000);
}

void	print_state(t_philo *philo, int n)
{
	pthread_mutex_lock(&g_write);
	if (n == 1)
		printf("%ld %d has taken a fork\n", timestamp(philo), philo->id);
	if (n == 2)
		printf("%ld %d is eating\n", timestamp(philo), philo->id);
	if (n == 3)
		printf("%ld %d is sleeping\n", timestamp(philo), philo->id);
	if (n == 4)
		printf("%ld %d is thinking\n", timestamp(philo), philo->id);
	pthread_mutex_unlock(&g_write);
}

void	*ft_philosophers(t_philo *philo)
{
	while (1)
	{
		if (philo->num_meal == philo->data->num_of_meals
			&& philo->data->num_of_meals != 0)
			break ;
		pthread_mutex_lock(&philo->mutex);
		print_state(philo, 1);
		pthread_mutex_lock(&philo->next->mutex);
		print_state(philo, 1);
		print_state(philo, 2);
		philo->eating = 1;
		philo->last_meal = get_time();
		ft_usleep(philo->data->time_to_eat);
		philo->num_meal += 1;
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&philo->next->mutex);
		philo->eating = 0;
		print_state(philo, 3);
		ft_usleep(philo->data->time_to_sleep);
		print_state(philo, 4);
	}
	return (NULL);
}
