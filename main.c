/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 08:46:00 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/18 19:11:08 by ayghazal         ###   ########.fr       */
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

int		ft_error()
{
	printf("Error: Arguments!!\n");
	return(1);
}

void	fill_philo(t_philo **philo, int id)
{
	t_philo *newphilo = (t_philo *)malloc(sizeof(t_philo));
	newphilo->id = id;
    newphilo->next = NULL;

	if (*philo == NULL)
		*philo = newphilo;
	else
	{
		t_philo *lastphilo = *philo;
        
        while(lastphilo->next != NULL)
        {
            lastphilo = lastphilo->next;
        }
        lastphilo->next = newphilo;
	}
}

void	print_philo(t_philo *philo)
{
	t_philo *node;

	node = philo;
	while(node->next != NULL)
	{
		printf("Philosopher [%d] Stored\n", node->id);
		node = node->next;
	}
}


int	main(int ac, char *av[])
{
	t_data data;
	t_philo *philo;
	
	int i = 0;
	philo = NULL;

	
	if (check_data(av) == 1)
		return(ft_error());
	
	store_data(av, &data);
	while(i <= data.num_of_philo)
	{
		fill_philo(&philo, (i + 1));
		i++;
	}
	print_philo(philo);
	return(EXIT_SUCCESS);
}





























  /*pthread_t t1, t2;
	pthread_mutex_init(&mutex, NULL);
	
	pthread_create(&t1, NULL, &routine, NULL);
	
	pthread_create(&t2, NULL, &routine, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("c = %d\n", c);
	pthread_mutex_destroy(&mutex);
	return(0);*/