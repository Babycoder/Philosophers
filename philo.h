/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:38:46 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/19 02:44:05 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO__H
#define PHILO__H

#include <stdio.h>
#include "utils/utill.h"
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data{
    
    int num_of_philo;
    long long time_to_die;
    long  long time_to_eat;
    long long time_to_sleep;
    long entry_time;
    int num_of_meals;
    
} t_data;

typedef struct  s_philo{
    
    int id;
    pthread_t thread;
    
    pthread_mutex_t mutex;
    
    long last_meal; 
    
    t_data  *data;
    
    struct s_philo *next;
    
}               t_philo;

#endif