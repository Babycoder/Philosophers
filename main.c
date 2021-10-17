/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 08:46:00 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/18 00:02:24 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_data(t_data data)
{
	printf("num_of_philo = %d\ntime_to_die = %lld\ntime_to_eat = %lld\ntime_to_sleep = %lld\nnum_of_meals = %d\n", data.num_of_philo, data.time_to_die, data.time_to_eat, data.time_to_sleep, data.num_of_meals);
}


int		ft_onlydigit(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return(1);
	}
	return(0);
}

int		check_data(char **str)
{
	int i;
	
	i = 0;
	while(str[i])
		i++;
	if (i == 5 || i == 6)
	{
		i = 1;
		while (str[i])
		{
			if (ft_onlydigit(str[i]) == 1)
				return(1);
			i++;
		}
	}
	else
		return(1);
	return(0);
}

void		store_data(char **str, t_data *data)
{

	data->num_of_philo = ft_atoi(str[1]);
	data->time_to_die = ft_atoi(str[2]) * 1000;
	data->time_to_eat = ft_atoi(str[3]) * 1000;
	data->time_to_sleep = ft_atoi(str[4]) * 1000;
	if (str[5] != NULL)
		data->num_of_meals = ft_atoi(str[5]);
}

int	main(int ac, char *av[])
{
	t_data data;

	if (check_data(av) == 0)
	{
		store_data(av, &data);
		print_data(data);
	}
	else
		printf("Error: Arguments!!\n");
	return(0);
}