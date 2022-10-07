/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:58:06 by vnazioze          #+#    #+#             */
/*   Updated: 2022/10/05 16:58:06 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <errno.h>

#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RED "\033[0;31m"
#define RE "\033[0m"
#define INVALID_ARGV GREEN "\
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━┓\n\
┃" RED "ERROR:" RE " " GREEN "You must specify at least 4 or 5 arguments┃  Rules ┃\n\
┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃━━━━━━━━┃\n\
┃ - [1] number_of_philosophers                    ┃  >  0  ┃\n\
┃ - [2] time_to_die                               ┃  >= 0  ┃\n\
┃ - [3] time_to_eat                               ┃  >= 0  ┃\n\
┃ - [4] time_to_sleep                             ┃  >= 0  ┃\n\
┃ - [5] number_of_times_each_philosopher_must_eat ┃  >= 0  ┃\n\
┃ - Obs: Argument 5 is optional.                  ┃   --   ┃\n\
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━┛\n" RE

typedef struct s_philo
{
	int 				id;
	long long 			last_time_to_eat;
	int 				count_times_each_philosopher_ate;
	pthread_mutex_t    fork_mutex;
	t_philo 			*next;
	t_philo 			*prev;
	t_data 				*data;
} t_philo;

typedef struct s_data
{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_eat;
	long long start_time;
	int stop;
	int dead_management;
	t_philo *philo;
} t_data;

/**
 * If the character is between 0 and 9, return 1, otherwise return 0
 *
 * @param c The character to be checked.
 *
 * @return 1 or 0
 */
int ft_isdigit(int c);

/**
 * It takes a string, and returns an integer
 *
 * @param string The string to be converted.
 *
 * @return the integer value of the string.
 */
int ft_atoi(const char *nptr);

/**
 * It returns the current time in milliseconds.
 *
 * @return The time in milliseconds.
 */
long long get_time(void);

#endif