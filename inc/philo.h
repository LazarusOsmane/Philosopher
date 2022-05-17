/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:17:07 by engooh            #+#    #+#             */
/*   Updated: 2022/05/17 18:02:39 by engooh           ###   ########.fr       */
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
	int					dead;
	struct s_data		*data;
	pthread_mutex_t		fork;	
	pthread_t			thrid;
}	t_philo;

typedef struct s_data
{
	long int			genese;
	int					nbp_std;
	long int			ttd_std;
	long int			tte_std;
	long int			tts_std;
	long int			ect_std;
	t_philo				*philo;
	pthread_mutex_t		eat;
	pthread_mutex_t		lock;
}	t_data;

long int	timestamp(void);
void		*routine(void *philo);
t_data		*init_thread(char **av);
void		ft_usleep(ssize_t time);
void		wait_philo(t_data *a, int i);
void		destroy_philo(t_data *a, int i);
void		print_philo(t_philo *p, const char *str);
void		status_philo(t_philo *p, char *str, int status);
#endif 
