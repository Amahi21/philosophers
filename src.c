/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:24:56 by amahi             #+#    #+#             */
/*   Updated: 2022/06/23 20:12:21 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	filling_struct(char **av, t_data *data)
{
	data->num_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->flag_for_ending = 0;
	if (av[5])
		data->t_must_eat = ft_atoi(av[5]);
	else
		data->t_must_eat = -1;
}

int	ft_atoi(const char *str)
{
	long long int	res;
	int				i;
	int				min;

	i = 0;
	min = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		min = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if ((res * min) > INT_MAX)
			return (-1);
		if ((res * min) < INT_MIN)
			return (-1);
	}
	return ((int)res * min);
}

int	time_to_int(struct timeval time)
{
	return ((int)((time.tv_sec * 1000 + time.tv_usec / 1000)));
}
