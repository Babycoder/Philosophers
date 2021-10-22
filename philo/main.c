/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 08:46:00 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/22 12:40:36 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	int		i;
	t_data	data;
	t_philo	*philo;

	i = 0;
	philo = NULL;
	if (check_data(av) == 1)
		return (ft_error(ac));
	if (store_data(av, &data) == 1)
		return (EXIT_FAILURE);
	pthread_mutex_init(&g_write, NULL);
	while (i < data.num_of_philo)
	{
		fill_philo(&philo, (i + 1), &data);
		i++;
	}
	ft_threads(philo);
	ft_supervisor(philo);
	deleteList(&philo);
	return (EXIT_SUCCESS);
}
