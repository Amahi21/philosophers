/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:30:02 by amahi             #+#    #+#             */
/*   Updated: 2022/06/28 15:55:29 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(void	*data)
{
	t_philo	*tmp;

	tmp = data;
	pthread_mutex_lock(&tmp->left_fork->mutex);
	print_by_mutex(tmp, "has taken a fork");
	pthread_mutex_lock(&tmp->right_fork->mutex);
	print_by_mutex(tmp, "has taken a fork");
	print_by_mutex(tmp, "is eating");
	my_usleep(tmp->data->t_eat);
	amount_eaten(data);
	pthread_mutex_lock(&tmp->mutex_time);
	tmp->t_last_eat = actualtime(tmp->data->time);
	if (actualtime(tmp->data->time) - tmp->t_last_eat > tmp->data->t_die)
	{
		print_by_mutex(tmp, "died");
		exit(0);
	}
	// printf("t_last_eat -	%d\ntime -		%d\n", tmp->t_last_eat, actualtime(tmp->data->time));
	pthread_mutex_unlock(&tmp->mutex_time);
	pthread_mutex_unlock(&tmp->right_fork->mutex);
	pthread_mutex_unlock(&tmp->left_fork->mutex);
	print_by_mutex(tmp, "is sleeping");
	my_usleep(tmp->data->t_sleep);
	print_by_mutex(tmp, "is thinking");
}

void	*life(void *data)
{
	t_philo	*tmp;

	tmp = data;
	if (tmp->num % 2 == 0)
		my_usleep(200);
	while (tmp->data->flag_for_ending < tmp->data->num_philo)
		eating(data);
	return (0);
}
