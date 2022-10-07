/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:56:44 by vnazioze          #+#    #+#             */
/*   Updated: 2022/10/07 10:56:44 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void    add_philosophers_to_list(t_philo *philo, t_data *data, int n)
{
    t_philo    *new_philosophers;
    t_philo    *first;

    first = philo;
    new_philosophers = (t_philo *) malloc (sizeof(t_philo));
    pthread_mutex_init(&new_philosophers->fork_mutex, NULL);
    new_philosophers->id = n + 1;
    new_philosophers->data = data;
    new_philosophers->count_times_each_philosopher_ate = 0;
    while (philo->next != first)
        philo = philo->next;
    philo->next = new_philosophers;
    new_philosophers->next = first;
    new_philosophers->prev = philo;
    first->prev = new_philosophers;
}

void    init_philosophers_list(t_data *data)
{
    int    i;

    //desacoplar em outra função a criação do primeiro filosofo.
    data->philo = (t_philo *) malloc (sizeof(t_philo));
    pthread_mutex_init(&data->philo->fork_mutex, NULL);
    data->philo->data = data;
    data->philo->id = 1;
    data->philo->count_times_each_philosopher_ate = 0;
    data->philo->next = data->philo;
    data->philo->prev = data->philo;
    i = 0;
    while (++i < data->number_of_philosophers)
        add_philosophers_to_list(data->philo, data, i);
}