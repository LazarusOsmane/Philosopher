/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 08:21:53 by engooh            #+#    #+#             */
/*   Updated: 2022/05/17 18:02:32 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	set_data_philo(t_data *data, char **av)
{
	data->nbp_std = ft_atoi(av[1]);
	data->ttd_std = ft_atoi(av[2]);
	data->tte_std = ft_atoi(av[3]);
	data->tts_std = ft_atoi(av[4]);
	if (av[5])
		data->ect_std = ft_atoi(av[5]);
}

t_data	*set_philo(char **av)
{
	t_data	*a;

	a = malloc(sizeof(t_data));
	if (!a)
		return (NULL);
	set_data_philo(a, av);
	printf("%d philo \n", a->nbp_std);
	a->philo = malloc(sizeof(t_philo) * (a->nbp_std + 1));
	if (!a->philo)
		return (NULL);
	return (a);
}

int	create_mutex(t_data *a, int i)
{
	pthread_mutex_init(&a->eat, NULL);
	pthread_mutex_init(&a->lock, NULL);
	while (++i < a->nbp_std)
	{
		a->philo[i].idx = i;
		a->philo[i].ect = 0;
		a->philo[i].data = a;
		if (i == a->nbp_std - 1)
			a->philo[i].next = 0;
		else
			a->philo[i].next = i + 1;
		if (pthread_mutex_init(&a->philo[i].fork, NULL) < 0)
			return (0);
	}
	return (1);
}

int	create_thread(t_data *a, int is_paire, int i)
{
	while (++i < a->nbp_std)
	{
		if (i % 2 == is_paire)
			if (pthread_create(&a->philo[i].thrid, NULL,
					routine, &a->philo[i]) < 0)
				return (0);
		usleep(1);
	}
	return (1);
}

t_data	*init_thread(char **av)
{
	t_data		*a;

	a = set_philo(av);
	if (!a)
		return (NULL);
	if (!create_mutex(a, -1))
		return (NULL);
	a->genese = timestamp();
	if (!create_thread(a, 0, -1) || !create_thread(a, 1, -1))
		return (NULL);
	return (a);
}
