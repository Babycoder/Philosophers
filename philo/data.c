/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:41:32 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/22 11:50:26 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	store_data(char **str, t_data *data)
{
	data->num_of_philo = ft_atoi(str[1]);
	if (data->num_of_philo <= 0)
		return (1);
	data->time_to_die = ft_atoi(str[2]) * 1000;
	if (data->time_to_die <= 0)
		return (1);
	data->time_to_eat = ft_atoi(str[3]) * 1000;
	if (data->time_to_eat <= 0)
		return (1);
	data->time_to_sleep = ft_atoi(str[4]) * 1000;
	if (data->time_to_sleep <= 0)
		return (1);
	data->num_of_meals = 0;
	if (str[5] != NULL)
	{
		data->num_of_meals = ft_atoi(str[5]);
		if (data->num_of_meals <= 0)
			return (1);
	}
	data->entry_time = get_time();
	return (0);
}
