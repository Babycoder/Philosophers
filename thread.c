/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:43:09 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/20 15:08:51 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_threads(t_philo *philo)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	tmp = philo;
	while (i < philo->data->num_of_philo)
	{
		tmp->last_meal = get_time();
		pthread_create(&tmp->thread, NULL, (void *)ft_philosophers, tmp);
		usleep(100);
		tmp = tmp->next;
		i++;
	}
}
