/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:27:55 by christellen       #+#    #+#             */
/*   Updated: 2022/05/15 10:58:26 by christellen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	value_philo(t_all *all, char **data)
{
	all->nbp = ft_atoi(data[1]);
	all->ttd = ft_atoi(data[2]);
	all->tte = ft_atoi(data[3]);
	all->tts = ft_atoi(data[4]);
	if (data[5])
		all->tts = ft_atoi(data[5]);
}

t_all	*malloc_philo(char **av)
{
	t_all	*new;

	new = malloc(sizeof(t_all));
	value_philo(new, av);
	new->philo = malloc(sizeof(t_philosopher) * (new->nbp + 1));
	if (!new || !new->philo)
	{ 
		destroy_philo(new, -1, 0);
		return (NULL);
	}
	return (new);
}

int		thread_philo(t_all *all, int if_paire, int i)
{
	if (!i)
		if (pthread_create(&all->philo[all->nbp].thrid, NULL, status_dead, &all->philo[all->nbp]) < 0)
			return (destroy_philo(all, -1, 1));
	while (++i < all->nbp)
	{
		if (i % 2 == if_paire)
			if (pthread_create(&all->philo[i].thrid, NULL, routine, &all->philo[i]) < 0)
				return (destroy_philo(all, -1, 1));
		usleep(1);
	}
	return (0);
}

int		mutex_philo(t_all *all, int i)
{
	if (pthread_mutex_init(&all->main, NULL) < 0)
		return (destroy_philo(all, -1, 1));
	if (pthread_mutex_init(&all->sleep, NULL) < 0)
		return (destroy_philo(all, -1, 1));
	if (pthread_mutex_init(&all->if_dead, NULL) < 0)
		return (destroy_philo(all, -1, 1));
	while (++i < all->nbp)
	{
		all->philo[i].nbp = i;
		all->philo[i].is_dead = 1;
		all->philo[i].ptr_all = all;
		if (i)
			all->philo[i].prev_philo = &all->philo[i - 1];
		if (pthread_mutex_init(&all->philo[i].eat, NULL) < 0)
			return (destroy_philo(all, -1, 1));
	}
	all->philo[0].prev_philo = &all->philo[all->nbp - 1];
	return (0);
}

t_all	*init_philo(char **av)
{
	t_all	*all;

	all = malloc_philo(av);
	if (mutex_philo(all, -1))
		return (NULL);
	all->genese = 0;
	all->genese = timestamp();
	printf("start reff %ld\n", all->genese);
	if (thread_philo(all, 1, -1) || thread_philo(all, 0, -1))
		return (NULL);
	return (all);
}