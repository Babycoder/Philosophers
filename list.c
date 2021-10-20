/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:38:21 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/20 15:04:09 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_philo(t_philo **philo, int id, t_data *data)
{
	t_philo *newphilo = (t_philo *)malloc(sizeof(t_philo));
	newphilo->id = id;
	newphilo->num_meal = 0;
	newphilo->data = data;
	pthread_mutex_init(&newphilo->mutex, NULL);
	newphilo->next = NULL;

	if (data->num_of_philo == 1)
	{
		*philo = newphilo;
		(*philo)->next = newphilo;
		return ;
	}
	if (*philo == NULL)
		*philo = newphilo;
	else
	{
		t_philo	*head = *philo;
		t_philo *lastphilo = *philo;

		while(lastphilo->next != NULL)
		{
			lastphilo = lastphilo->next;
		}
		lastphilo->next = newphilo;
		if (id == data->num_of_philo)
			lastphilo->next->next = head;
	}
}

void	deleteList(t_philo **head)
{
	t_philo	*current;
	t_philo	*next;
	int		i;
	int		n;

	i = 0;
	current = *head;
	n = current->data->num_of_philo;
	while (i < n)
	{
		next = current->next;
		pthread_mutex_destroy(&current->mutex);
		free(current);
		current = next;
		i++;
	}
	*head = NULL;
}
