/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:02:38 by engooh            #+#    #+#             */
/*   Updated: 2022/05/27 18:27:44 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	parse(int ac, char **av)
{
	int	i;

	if (!(ac == 5 || ac == 6))
		return (printf("Error: invalide number argument\n"));
	av = av + 1;
	while (*av)
	{
		if (ft_atoi(*av) == -1)
			return (printf("Error: invalide argument\n"));
		i = -1;
		while (av[0][++i])
			if (!ft_isdigit(av[0][i]))
				return (printf("Error: invalide argument\n"));
		av++;
	}
	return (0);
}

int	set_data(t_data *data, int ac, char **av)
{
	data->nbp_std = ft_atoi(av[1]);
	data->ttd_std = ft_atoi(av[2]);
	data->tte_std = ft_atoi(av[3]);
	data->tts_std = ft_atoi(av[4]);
	if (av[5])
		data->ect_std = ft_atoi(av[5]);
	if (data->nbp_std < 0)
		return (printf("Error: invalid argument can't be negative"));
	if (data->ttd_std < 0)
		return (printf("Error: invalid argument can't be negative"));
	if (data->tte_std < 0)
		return (printf("Error: invalid argument can't be negative"));
	if (data->tts_std < 0)
		return (printf("Error: invalid argument can't be negative"));
	if (data->tts_std < 0)
		return (printf("Error: invalid argument can't be negative"));
	return (0);
}

int	creat_mutex(t_data *data, int i)
{
	if (pthread_mutex_init(&data->print, NULL) < 0)
		return (0);
	if (pthread_mutex_init(&data->death, NULL) < 0)
		return (0);
	while (++i < data->nbp_std)
	{
		data->philo[i].idx = i;
		data->philo[i].ect = 0;
		data->philo[i].tte = 0;
		data->philo[i].data = data;
		if (pthread_mutex_init(&data->philo[i].fork, NULL) < 0)
			return (0);
	}	
}

int	create_thread_mutex(t_data *data, int is_paire, int i)
{
	while (++i < data->nbp_std)
	{
		if (i % 2 == is_paire)
			if (pthread_create(&data->philo[i].thrid, NULL,
						routine, &data->philo[i]) < 0)
				return (0);
		usleep(100);
	}
	if (i == 1)
		data->philo[i].next = 0;
	return (1);
}

int	init_philo(t_data *data, int ac, char **av)
{
	if (set_data(data, ac, av))
		return (-1);
	if ()
	return (0);
}
