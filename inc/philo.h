/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:17:07 by engooh            #+#    #+#             */
/*   Updated: 2022/05/14 15:05:38by christellen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
/*	"../src" */
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include "../share/libft/libft.h"

typedef struct s_philosopher
{
	void				*prev_philo;
	pthread_t			thrid;
	pthread_mutex_t		eat;
	int					nbp;
	long int			tte;
	int					is_dead;
	void				*ptr_all;
}	t_philosopher;

typedef struct s_all
{
	int					nbp;
	long int			ttd;
	long int			tte;
	long int			tts;
	long int			ttk;
	long int			genese;
	t_philosopher		*philo;
	pthread_mutex_t		main;
	pthread_mutex_t		sleep;
	pthread_mutex_t		if_dead;
}	t_all;

long int	timestamp(void);
void		*routine(void *argc);
t_all		*init_philo(char **av);
int			wait_philo(t_all *all, int i);
void		*status_dead(void *argc);
void		status_eat(t_all *all, t_philosopher *philo);
void		status_sleep(t_all *all, t_philosopher *philo);
int			destroy_philo(t_all *all, int i, int val_ret);
#endif 
