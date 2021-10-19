/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 08:46:00 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/19 18:20:01 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long    get_time(void)
{
    struct timeval    time;

    gettimeofday(&time, NULL);
    return (time.tv_usec + (time.tv_sec * 1000000));
}

void    ft_usleep(long int time)
{
    long long    r;
    long long    mic;

    mic = get_time();
    r = time - 1000;
    usleep(r);
    while ((get_time() - mic) <= (time))
        ;
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
	data->entry_time = get_time();
}

int		ft_error(int ac)
{
	ac++;
	printf("Error: Arguments!!\n");
	return(1);
}

void	fill_philo(t_philo **philo, int id, t_data *data)
{
	t_philo *newphilo = (t_philo *)malloc(sizeof(t_philo));
	newphilo->id = id;
	newphilo->num_meal = 0;
	newphilo->data = data;
	pthread_mutex_init(&newphilo->mutex, NULL);
    newphilo->next = NULL;

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

void	print_philo(t_philo *philo)
{
	t_philo *tmp;

	tmp = philo;
	while(1)
	{
		printf("Philosopher [%d] Stored\n", tmp->id);
		tmp = tmp->next;
	}
}

void	*ft_philosophers(t_philo *philo)
{
	while(1)
	{
		pthread_mutex_lock(&philo->mutex);
		pthread_mutex_lock(&philo->next->mutex);	
		printf("%ld %d has taken a fork\n", ((get_time() - philo->data->entry_time)/1000), philo->id);
		printf("%ld %d has taken a fork\n", ((get_time() - philo->data->entry_time)/1000), philo->id);
		printf("%ld %d is eating\n", ((get_time() - philo->data->entry_time)/1000), philo->id);
		philo->last_meal = get_time();
		philo->num_meal += 1;
		ft_usleep(philo->data->time_to_eat);
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&philo->next->mutex);
		printf("%ld %d is sleeping\n", ((get_time() - philo->data->entry_time)/1000), philo->id);
		ft_usleep(philo->data->time_to_sleep);
		printf("%ld %d is thinking\n", ((get_time() - philo->data->entry_time)/1000), philo->id);
	}
	return NULL;
}

int 	all_ate(t_philo *philo)
{
	t_philo *tmp;
	int i;
	int  ate;

	ate = 0;
	i = 0;
	tmp = philo;
	while(i < tmp->data->num_of_philo)
	{
		if (tmp->num_meal == tmp->data->num_of_meals)
			ate++;
		tmp = tmp->next;
		i++;
	}
	if (ate == philo->data->num_of_philo)
		return(1);
	return(0);
}

void	ft_supervisor(t_philo *philo)
{
	t_philo *tmp;
	
	tmp = philo;
	while(tmp->next != NULL)
	{
		if (get_time() - tmp->last_meal >= tmp->data->time_to_die)
		{
			printf("%ld %d died\n", ((get_time() - philo->data->entry_time)/1000), philo->id);
			return ;
		}
		if (all_ate(philo))
			return ;
		tmp = tmp->next;
	}
}

void deleteList(t_philo **head)
{
	t_philo	*current;
	t_philo	*next;
	int i;
	int n;
	
	i = 0;
	current = *head;
	n = current->data->num_of_philo; 
	while(i < n)
	{
		next = current->next;
		pthread_mutex_destroy(&current->mutex);
		free(current);
		current = next;
		i++;
	}
	*head = NULL;
}


int	main(int ac, char *av[])
{
	t_data data;
	t_philo *philo = NULL;
	t_philo *tmp;
	
	int i = 0;
	philo = NULL;

	//======= FILL_DATA ============
	
	if (check_data(av) == 1)
		return(ft_error(ac));
	
	store_data(av, &data);
	while(i < data.num_of_philo)
	{
		fill_philo(&philo, (i + 1), &data);
		i++;
	}
	
	//======= THREAD CREATE ===========
	
	i = 0;
	tmp = philo;
	while(i < data.num_of_philo)
	{
		tmp->last_meal = get_time();
		pthread_create(&tmp->thread, NULL, (void *)ft_philosophers, tmp);
		usleep(50);
		tmp =  tmp->next;
		i++;
	}
	ft_supervisor(philo);
	deleteList(&philo);

	return(EXIT_SUCCESS);
}