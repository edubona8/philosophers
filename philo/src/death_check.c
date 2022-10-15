/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 06:44:13 by ebonamic          #+#    #+#             */
/*   Updated: 2022/10/15 06:44:13 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eat_count_check(t_data *data)
{
	t_philo	*philo;

	philo = data->philo;
	if (check_eat_mutex(philo))
		return (0);
	philo = philo->next;
	while (philo != data->philo)
	{
		if (check_eat_mutex(philo))
			return (0);
		philo = philo->next;
	}
	pthread_mutex_lock(&data->stop_mutex);
	data->stop = 1;
	pthread_mutex_unlock(&data->stop_mutex);
	return (1);
}

void	death_check(t_data *data)
{
	t_philo	*philo;

	philo = data->philo;
	while (check_stop(data))
	{
		usleep(10);
		pthread_mutex_lock(&philo->data->eat_time_mutex);
		if (get_time() - philo->last_eat_time > data->die_time)
		{
			pthread_mutex_unlock(&philo->data->eat_time_mutex);
			pthread_mutex_lock(&data->stop_mutex);
			data->stop = 1;
			pthread_mutex_unlock(&data->stop_mutex);
			pthread_mutex_lock(&data->printer);
			printf ("%lli %i died\n", get_time() - data->start_time, philo->id);
			pthread_mutex_unlock(&data->printer);
			break ;
		}
		else
			pthread_mutex_unlock(&philo->data->eat_time_mutex);
		philo = philo->next;
	}
}
