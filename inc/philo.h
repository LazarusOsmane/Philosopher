/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:17:07 by engooh            #+#    #+#             */
/*   Updated: 2022/05/23 18:12:12 by engooh           ###   ########.fr       */
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

struct	s_data;

typedef struct s_philo
{
	int					idx;
	int					next;
	int					ect;
	long int			tte;
	long int			s_tte;
	long int			s_ttd;
	long int			s_tts;
	struct s_data		*data;
	pthread_mutex_t		fork;	
	pthread_t			thrid;
}	t_philo;

typedef struct s_data
{
	int					dead;
	long int			genese;
	int					nbp_std;
	long int			ttd_std;
	long int			tte_std;
	long int			tts_std;
	long int			ect_std;
	t_philo				*philo;
	pthread_mutex_t		eat;
	pthread_mutex_t		all;
	pthread_mutex_t		lock;
	pthread_mutex_t		death;
	int					tu_peut_lock;
}	t_data;

long int	timestamp(void);
int			check_death(t_philo *p);
void		*routine(void *philo);
t_data		*init_thread(char **av);
void		ft_usleep(long int time, t_philo *p);
void		wait_philo(t_data *a, int i);
void		superviseur(t_data *a);
void		destroy_philo(t_data *a, int i);
void		print_philo(t_philo *p, const char *str);
int			status_death(t_data *a, int i);
void		status_fork(t_philo *p);
void		status_eat(t_philo *p);
void		status_philo(t_philo *p);
void		status_sleep(t_philo *p);
void		status_think(t_philo *p);
#endif 
