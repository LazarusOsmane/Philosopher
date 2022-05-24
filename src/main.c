/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:37:15 by engooh            #+#    #+#             */
/*   Updated: 2022/05/23 14:01:33 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../inc/philo.h"

int	check_death(t_philo *p)
{
	pthread_mutex_lock(&p->data->death);
	if (!p->data->dead)
	{
		pthread_mutex_unlock(&p->data->death);
		return (0);
	}
	pthread_mutex_unlock(&p->data->death);
	return (1);
}

void	superviseur(t_data *a)
{
	while (42)
		if (!status_death(a, -1))
			return ;
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac < 4)
		return (0);
	data = init_thread(av);
	superviseur(data);
	wait_philo(data, -1);
	destroy_philo(data, -1);
	return (0);
}
