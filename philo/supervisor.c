/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:40:00 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/22 12:33:34 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_ate(t_philo *philo)
{
	t_philo	*tmp;
	int		i;
	int		ate;

	ate = 0;
	i = 0;
	tmp = philo;
	while (i < tmp->data->num_of_philo)
	{
		if (tmp->num_meal == tmp->data->num_of_meals)
			ate++;
		tmp = tmp->next;
		i++;
	}
	if (ate == philo->data->num_of_philo)
		return (1);
	return (0);
}

void	ft_supervisor(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (tmp->next != NULL)
	{
		if ((get_time() - tmp->last_meal >= tmp->data->time_to_die)
			&& tmp->eating == 0)
		{
			pthread_mutex_lock(&g_write);
			printf("\033[0;31m%ld %d died\n",
				((get_time() - philo->data->entry_time) / 1000), tmp->id);
			return ;
		}
		if (philo->data->num_of_meals != 0)
		{
			if (all_ate(philo))
				return ;
		}
		tmp = tmp->next;
	}
}
