/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 08:46:00 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/17 16:39:31 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int c = 0;
pthread_mutex_t mutex;

void	*routine()
{
	for(int i = 0; i < 10000000; i++)
	{
		pthread_mutex_lock(&mutex);
		c++;
		pthread_mutex_unlock(&mutex);
	}

	return NULL;
	
}

int     main()
{
	pthread_t t1, t2;
	pthread_mutex_init(&mutex, NULL);
	
	pthread_create(&t1, NULL, &routine, NULL);
	
	pthread_create(&t2, NULL, &routine, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("c = %d\n", c);
	pthread_mutex_destroy(&mutex);
	return(0);
}