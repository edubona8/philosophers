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
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <errno.h>

# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define RED "\033[0;31m"
# define RE "\033[0m"

# define INVALID_VALUE	"Invalid parameters! Philosopher must be \
non zero positive number and others must be unsigned positive numbers"
# define INVALID_ARGV	"You must specify at least 4 arguments and maximum 5 including:\n\
- number_of_philosophers,\n\
- time_to_die,\n\
- time_to_eat,\n\
- time_to_sleep,\n\
- number_of_times_each_philosopher_must_eat (optional).\n"


int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);

#endif