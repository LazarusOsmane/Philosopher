/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 02:52:08 by christellen       #+#    #+#             */
/*   Updated: 2022/05/15 10:47:13 by christellen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int     destroy_philo(t_all *all, int i, int val_ret)
{
    while (all && ++i < all->nbp)
        pthread_mutex_destroy(&all->philo[i].eat);
    pthread_mutex_destroy(&all->main);
    pthread_mutex_destroy(&all->sleep);
    pthread_mutex_destroy(&all->if_dead);
    if (all->philo)
        free(all->philo);
    if (all)
        free(all);
    return (val_ret);
}