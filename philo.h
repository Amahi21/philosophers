/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahi <amahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:49:40 by amahi             #+#    #+#             */
/*   Updated: 2022/06/28 14:54:01 by amahi            ###   ########.fr       */
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

struct					s_philo;
typedef struct s_philo	t_philo;

typedef struct s_fork
{
	int				num;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_data
{
	int				num_philo;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	int				t_must_eat;

	int				flag_for_ending;

	t_philo			*philo;
	t_fork			*forks;
	pthread_mutex_t	printf;
	pthread_t		check_die;

	struct timeval	time;

}	t_data;

typedef struct s_philo
{
	pthread_t		id;
	int				num;
	int				amount_eaten;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_data			*data;

	int				t_last_eat;
	pthread_mutex_t	mutex_time;

}	t_philo;

// src.c
int		ft_atoi(const char *str);
void	filling_struct(char **av, t_data *data);
int		time_to_int(struct timeval time);

// utils.c
void	check_input(t_data *data, int ac, char **av);
void	print_by_mutex(t_philo *tmp, char *str);
int		actualtime(struct timeval time);
void	amount_eaten(void	*data);
void	my_usleep(int time);

// init_all.c
void	pthreads(t_data *data);

// actions.c
void	eating(void	*data);
void	*life(void *data);

// main.c
void	error(char *text);

#endif // PHILO_H