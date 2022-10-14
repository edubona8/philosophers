/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 02:28:15 by ebonamic          #+#    #+#             */
/*   Updated: 2022/04/06 02:28:15 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	*philo_func(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat_time_mutex);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->data->eat_time_mutex);
	if (philo->id % 2 == 0)
		usleep((philo->data->eat_time - 10) * 1000);
	while (check_stop(philo->data) && (philo->eat_count < philo->data->eat_num \
			|| philo->data->eat_num == -1))
	{
		philo_fork_lock(philo);
		if (check_stop(philo->data) == 0)
			break ;
		philo_eat(philo);
		philo_fork_unlock(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	start_threads(t_data *data)
{
	int		number_of_philo;
	t_philo	*aux_head_reference;

	mutex_init(data);
	number_of_philo = data->philo_num;
	aux_head_reference = data->philo;
	data->start_time = get_time();
	while (number_of_philo > 0)
	{
		pthread_create(&aux_head_reference->thread, NULL, (void *)&philo_func, aux_head_reference);
		aux_head_reference = aux_head_reference->next;
		number_of_philo--;
	}
	death_check(data);
	number_of_philo = data->philo_num;
	while (number_of_philo > 0)
	{
		pthread_join(aux_head_reference->thread, NULL);
		aux_head_reference = aux_head_reference->next;
		number_of_philo--;
	}
}

void mutex_init(t_data *data)
{
	pthread_mutex_init(&data->printer, NULL);
	pthread_mutex_init(&data->stop_mutex, NULL);
	pthread_mutex_init(&data->eat_mutex, NULL);
	pthread_mutex_init(&data->eat_time_mutex, NULL);
}
