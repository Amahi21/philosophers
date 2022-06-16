/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:49:40 by amahi             #+#    #+#             */
/*   Updated: 2022/06/15 21:18:27 by amahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int	num_philo;
	int	t_die;
	int	t_sleep;
	int	t_eat;
	int	t_must_eat;
	int	num_forks;
}	t_data;

// src.c
int		ft_atoi(const char *str);
void	filling_struct(char **av, t_data *data);

// utils.c
void	check_input(t_data *data, int ac, char **av);

// main.c
void	error(char *text);

#endif // PHILO_H