/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:19:40 by vnazioze          #+#    #+#             */
/*   Updated: 2022/10/06 10:19:40 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * If the character is between 0 and 9, return 1, otherwise return 0
 * 
 * @param c The character to be checked.
 * 
 * @return 1 or 0
 */
int ft_isdigit(int c)
{
    if (c >= 48 && c <= 57)
        return (1);
    return (0);
}

/**
 * It takes a string, and returns an integer
 * 
 * @param string The string to be converted.
 * 
 * @return the integer value of the string.
 */
int	ft_atoi(const char *string)
{
	int	signal;
	int	final_return;

	signal = 1;
	final_return = 0;
	while (*string == ' ' || *string == '\n' || *string == '\t'
		|| *string == '\v' || *string == '\f' || *string == '\r')
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			signal = -1;
		string++;
	}
	while (ft_isdigit(*string))
	{
		final_return = (final_return * 10) + (*string - '0');
		string++;
	}
	return (final_return * signal);
}

/**
 * It returns the current time in milliseconds.
 * 
 * @return The time in milliseconds.
 */
long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}
