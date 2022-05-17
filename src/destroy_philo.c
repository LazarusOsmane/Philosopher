/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:00:00 by engooh            #+#    #+#             */
/*   Updated: 2022/05/17 18:02:34 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo.h"

void	destroy_philo(t_data *a, int i)
{
	if (!a)
		return ;
	while (++i < a->nbp_std)
		pthread_mutex_destroy(&a->philo[i].fork);
	pthread_mutex_destroy(&a->lock);
	pthread_mutex_destroy(&a->eat);
	free(a->philo);
	free(a);
}
