/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:28:29 by amahi             #+#    #+#             */
/*   Updated: 2022/06/15 21:28:18 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_input(t_data *data, int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				error("Error - invalid input");
			j++;
		}
		i++;
	}
	if (ac == 5)
		if (data->num_philo < 1 || data->t_die < 1
			|| data->t_sleep < 1 || data->t_eat < 1)
			error("Error - incorrect input");
	if (ac == 6)
		if (data->num_philo < 1 || data->t_die < 1
			|| data->t_sleep < 1 || data->t_eat < 1 || data->t_must_eat < 1)
			error("Error - incorrect input");
}
