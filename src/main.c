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

int check_arguments(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    if (argc < 5 || argc > 6)
	{
		printf(RED "ERROR: " RE "\n%s", INVALID_ARGV);
        exit(1);
	}
    while(argv[++i])
    {
        j = -1;
        while(argv[i][++j])
        {
            if(!ft_isdigit(argv[i][j]))
            {
                printf(RED "ERROR: " RE "\n%s", INVALID_VALUE);
                exit(1);
            }
        }
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_data *data;

    if (check_arguments(argc, argv))
		return (1);
    return (0);
}