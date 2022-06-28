/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 06:36:01 by amahi             #+#    #+#             */
/*   Updated: 2022/06/28 14:59:13 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(char *text)
{
	int	i;

	i = 0;
	while (text[i])
		write(1, &text[i++], 1);
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	printf("\n");
	if (ac == 5 || ac == 6)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			error("Error - malloc");
		filling_struct(av, data);
		check_input(data, ac, av);
		pthread_mutex_init(&data->printf, NULL);
		pthreads(data);
		// printf("num - %d\ndie - %d\neat - %d\nsleep - %d\nmust eat - %d\n", data->num_philo, data->t_die, data->t_eat, data->t_sleep, data->t_must_eat);
	}
	else
		my_usleep(2000);
	return (0);
		// error("Error - wrong input\nCorrect - ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]");
}
