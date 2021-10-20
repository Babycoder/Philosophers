/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:38:46 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/20 15:40:33 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data{
	int			num_of_philo;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	long		entry_time;
	int			num_of_meals;
}				t_data;

typedef struct s_philo{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	mutex;
	long			last_meal;
	int				num_meal;
	t_data			*data;
	struct s_philo	*next;
}				t_philo;

void	ft_threads(t_philo *philo);
void	*ft_philosophers(t_philo *philo);
int		store_data(char **str, t_data *data);
int		all_ate(t_philo *philo);
void	ft_supervisor(t_philo *philo);
void	fill_philo(t_philo **philo, int id, t_data *data);
void	deleteList(t_philo **head);
int		ft_error(int ac);
long	get_time(void);
void	ft_usleep(long int time);
int		ft_onlydigit(char *s);
int		check_data(char **str);
int		ft_atoi(const char *str);

#endif