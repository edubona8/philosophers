/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 06:44:46 by ebonamic          #+#    #+#             */
/*   Updated: 2022/10/15 06:44:50 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_stop(t_data *data)
{
	pthread_mutex_lock(&data->stop_mutex);
	if (data->stop == 1)
	{
		pthread_mutex_unlock(&data->stop_mutex);
		return (0);
	}
	pthread_mutex_unlock(&data->stop_mutex);
	return (1);
}

int	check_eat_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat_mutex);
	if (philo->eat_count != philo->data->eat_num)
	{
		pthread_mutex_unlock(&philo->data->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->eat_mutex);
	return (0);
}
