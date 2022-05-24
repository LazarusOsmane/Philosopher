/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:38:06 by engooh            #+#    #+#             */
/*   Updated: 2022/05/24 09:48:19 by engooh           ###   ########.fr       */
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
	pthread_mutex_destroy(&a->death);
	pthread_mutex_destroy(&a->eat);
	free(a->philo);
	free(a);
}
