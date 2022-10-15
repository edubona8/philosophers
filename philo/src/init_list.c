/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 02:28:00 by ebonamic          #+#    #+#             */
/*   Updated: 2022/04/06 02:28:00 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	add_to_circular_list(t_philo *philo, t_data *data, int n)
{
	t_philo	*new_philo;
	t_philo	*aux_head_reference;

	aux_head_reference = philo;
	new_philo = (t_philo *) malloc (sizeof(t_philo));
	pthread_mutex_init(&new_philo->fork, NULL);
	new_philo->data = data;
	new_philo->id = n + 1;
	new_philo->eat_count = 0;
	new_philo->last_eat_time = 0;
	while (philo->next != aux_head_reference)
		philo = philo->next;
	philo->next = new_philo;
	new_philo->next = aux_head_reference;
	new_philo->prev = philo;
	aux_head_reference->prev = new_philo;
}

void	create_circular_list(t_data *data)
{
	data->philo = (t_philo *) malloc (sizeof(t_philo));
	pthread_mutex_init(&data->philo->fork, NULL);
	data->philo->data = data;
	data->philo->id = 1;
	data->philo->eat_count = 0;
	data->philo->next = data->philo;
	data->philo->prev = data->philo;
}

void	init_circular_list_philo(t_data *data)
{
	int	n;

	create_circular_list(data);
	n = 0;
	while (++n < data->philo_num)
		add_to_circular_list(data->philo, data, n);
}
