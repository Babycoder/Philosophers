/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:36:38 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/22 11:28:09 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(int ac)
{
	ac++;
	printf("Error: Arguments!!\n");
	return (1);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec + (time.tv_sec * 1000000));
}

void	ft_usleep(long int time)
{
	long long	r;
	long long	mic;

	mic = get_time();
	r = time - 10000;
	usleep(r);
	while ((get_time() - mic) <= (time))
		;
}

int	ft_onlydigit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_data(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i == 5 || i == 6)
	{
		i = 1;
		while (str[i])
		{
			if (ft_onlydigit(str[i]) == 1)
				return (1);
			i++;
		}
	}
	else
		return (1);
	return (0);
}
