/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonamic <ebonamic@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 02:27:58 by ebonamic          #+#    #+#             */
/*   Updated: 2022/04/06 02:27:58 by ebonamic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
	{
		printf ("\033[0;31m ERROR: \033[0mIncorrect number of arguments\n");
		return (1);
	}
	
	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf ("\033[0;31m ERROR: \033[0mArguments are formatted incorrectly\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}


void init_data(t_data *data, char **argv)
{
	data->philo_num = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->stop = 0;
	if (argv[5] != NULL)
		data->eat_num = ft_atoi(argv[5]);
	else
		data->eat_num = -1;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_args(argc, argv))
		return (1);
	data = (t_data *) malloc (sizeof(t_data));
	init_data(data, argv);
	init_circular_list_philo(data);
	init_threads(data);
	free_all(data);
}