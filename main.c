/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 08:46:00 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/14 15:09:25 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils/utill.h"
#include <pthread.h>

void	*routine()
{
	printf("hello thread\n");
}

int     main()
{
	/*pthread_t t1;
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, NULL);*/
	char s[] = "aymen";
	int len = (int)ft_strlen(s);
	printf("len = %d\n", len);
	return(0);
}