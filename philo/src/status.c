/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:15:26 by christellen       #+#    #+#             */
/*   Updated: 2022/05/28 19:38:30by christellen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void status_eat(t_data *data, t_philo *philo)
{
    pthread_mutex_lock(&philo->fork);
    philo->acess = 0;
    print_philo(data, philo, "has taken a fork\n", 17);
    if (philo->next->acess)
    {
        pthread_mutex_lock(&philo->next->fork);
        print_philo(data, philo, "has taken a fork\n", 17);
        philo->ect++;
        philo->tte = timestamp() - philo->genese;
        print_philo(data, philo, "is eating\n", 10);
        ft_usleep(data->tte_std, philo);
        pthread_mutex_unlock(&philo->fork);
        pthread_mutex_unlock(&philo->next->fork);
    }
    else
    {
        //print_philo(data, philo, "free a fork\n");
        pthread_mutex_unlock(&philo->fork);
    }
    philo->acess = 1;
}

void    status_sleep_think(t_data *data, t_philo *philo)
{
    print_philo(data, philo, "is sleeping\n", 12);
    ft_usleep(data->tts_std, philo);
    print_philo(data, philo, "is thinking\n", 12);
}