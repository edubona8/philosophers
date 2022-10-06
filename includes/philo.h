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
# define INVALID_ARGV "\
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━┓\n\
┃You must specify at least 4 or 5 arguments:      ┃  Rules ┃\n\
┃ - [1] number_of_philosophers                    ┃  >  0  ┃\n\
┃ - [2] time_to_die                               ┃  >= 0  ┃\n\
┃ - [3] time_to_eat                               ┃  >= 0  ┃\n\
┃ - [4] time_to_sleep                             ┃  >= 0  ┃\n\
┃ - [5] number_of_times_each_philosopher_must_eat ┃  >= 0  ┃\n\
┃ - Obs: Argument 5 is optional.                  ┃   --   ┃\n\
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━┛\n"


int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);

#endif