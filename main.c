/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 08:46:00 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/13 09:01:05 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void	*routine()
{
	printf("hello thread\n");
}

int     main()
{
	pthread_t t1;
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	return(0);
}