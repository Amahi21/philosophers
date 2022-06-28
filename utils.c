/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:28:29 by amahi             #+#    #+#             */
/*   Updated: 2022/06/28 14:57:27 by amahi            ###   ########.fr       */
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

int	actualtime(struct timeval time)
{
	struct timeval	time_now;

	gettimeofday(&time_now, NULL);
	return ((int)((time_now.tv_sec * 1000 + time_now.tv_usec / 1000)
		- (time.tv_sec * 1000 + time.tv_usec / 1000)));
}

void	print_by_mutex(t_philo *tmp, char *str)
{
	pthread_mutex_lock(&tmp->data->printf);
	printf("%d %d %s\n", actualtime(tmp->data->time), tmp->num, str);
	pthread_mutex_unlock(&tmp->data->printf);
}

void	amount_eaten(void	*data)
{
	t_philo	*tmp;

	tmp = data;
	tmp->amount_eaten += 1;
	if (tmp->data->t_must_eat == tmp->amount_eaten)
		tmp->data->flag_for_ending++;
	if (tmp->data->flag_for_ending == tmp->data->num_philo)
		exit(0);
}

void	my_usleep(int time)
{
	struct timeval	t2;
	struct timeval	t1;
	int				start;
	int				after;

	gettimeofday(&t1, NULL);
	gettimeofday(&t2, NULL);
	start = time_to_int(t1);
	after = time_to_int(t2);
	while (after - start < time)
	{
		gettimeofday(&t2, NULL);
		after = time_to_int(t2);
	}
}
