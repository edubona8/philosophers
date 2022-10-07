/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:28:41 by vnazioze          #+#    #+#             */
/*   Updated: 2022/10/05 16:28:41 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * It checks if the arguments are valid
 * 
 * @param argv The array of arguments passed to the program.
 * 
 * @return the value of the expression.
 */
int	check_arguments(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i] != NULL)
	{
		j = -1;
		while (argv[i][++j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
		}
	}
	return (1);
}

/**
 * It checks the arguments passed to the program.
 * 
 * @param argc the number of arguments passed to the program
 * @param argv the arguments passed to the program
 */
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6 || check_arguments(argv) == 0)
	{
		printf("%s", INVALID_ARGV);
		exit (1);
	}
	data = (t_data *) malloc(sizeof(t_data));
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		data->number_eat = ft_atoi(argv[5]);
	else
		data->number_eat = -1;
}