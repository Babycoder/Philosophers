/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:38:21 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/22 12:29:34 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	push_last(t_philo **philo, t_philo *newphilo, int id, t_data *data)
{
	t_philo	*head;
	t_philo	*lastphilo;

	lastphilo = *philo;
	head = *philo;
	while (lastphilo->next != NULL)
	{
		lastphilo = lastphilo->next;
	}
	lastphilo->next = newphilo;
	if (id == data->num_of_philo)
		lastphilo->next->next = head;
}

void	fill_philo(t_philo **philo, int id, t_data *data)
{
	t_philo	*newphilo;

	newphilo = (t_philo *)malloc(sizeof(t_philo));
	newphilo->id = id;
	newphilo->num_meal = 0;
	newphilo->eating = 0;
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
		push_last(philo, newphilo, id, data);
}

void	deleteList(t_philo **head)
{
	t_philo	*current;
	t_philo	*next;
	int		i;
	int		n;

	usleep(100);
	i = 0;
	current = *head;
	n = current->data->num_of_philo;
	pthread_mutex_destroy(&g_write);
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
