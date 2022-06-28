/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:47:59 by amahi             #+#    #+#             */
/*   Updated: 2022/06/21 11:34:39 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// возвращает 0, когда "t_last_eat" меньше, чем "t_die"

void	forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
		data->forks[i].num = i;
	i = -1;
	while (++i < data->num_philo)
		data->philo[i].left_fork = &data->forks[i];
	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_init(&data->forks[i].mutex, 0);
		if (i == data->num_philo - 1)
			data->philo[0].right_fork = &data->forks[i];
		else
			data->philo[i + 1].right_fork = &data->forks[i];
		i++;
	}
}

void	*check_die(void *data)
{
	t_data	*tmp;

	tmp = data;
	while (!tmp->flag_for_ending)
	{
		if (tmp->flag_for_ending)
			exit(0);
	}
	return (NULL);
}

void	pthreads(t_data *data)
{
	int	i;

	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philo)
		return ;
	data->forks = (t_fork *)malloc(sizeof(t_fork) * data->num_philo);
	if (!data->forks)
		return ;
	gettimeofday(&data->time, NULL);
	forks(data);
	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].num = i + 1;
		data->philo[i].data = data;
		data->philo[i].amount_eaten = 0;
		pthread_mutex_init(&data->philo[i].mutex_time, 0);
		pthread_create(&data->philo[i].id, NULL, life, &data->philo[i]);
		i++;
	}
	pthread_create(&data->check_die, NULL, check_die, &data);
	i = 0;
	while (i < data->num_philo)
		pthread_join(data->philo[i++].id, NULL);
	pthread_join(data->check_die, NULL);
}
