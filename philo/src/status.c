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

int check_death(t_data *data, int r)
{
    pthread_mutex_lock(&data->death);
    if (!data->dead)
        r = 0;
    pthread_mutex_unlock(&data->death);
    return (r);
}

int status_death(t_data *data, int i)
{
    while (++i < data->nbp_std)
    {
        if (data->philo[i].genese && ((timestamp() - data->philo[i].tte >= data->ttd_std) || (data->ect_if && data->philo[i].ect == data->ect_std)))
        {
            pthread_mutex_lock(&data->death);
            data->dead = 0;
            pthread_mutex_unlock(&data->death);
            print_philo(data, &data->philo[i], "died\n", 5);
            return (0);
        }
    }
    return (1);
}

void status_eat(t_data *data, t_philo *philo)
{
    pthread_mutex_lock(&philo->fork);
    philo->acess = 0;
    print_philo(data, philo, "has taken a fork\n", 17);
    //if (philo->next && philo->next->acess)
    //{
    pthread_mutex_lock(&philo->next->fork);
    print_philo(data, philo, "has taken a fork\n", 17);
    philo->tte = timestamp();
    ft_usleep(data->tte_std, data);
    print_philo(data, philo, "is eating\n", 10);
    philo->ect++;
    pthread_mutex_unlock(&philo->fork);
    pthread_mutex_unlock(&philo->next->fork);
    //}
    //else
      //  pthread_mutex_unlock(&philo->fork);
    philo->acess = 1;
}

void    status_sleep_think(t_data *data, t_philo *philo)
{
    print_philo(data, philo, "is sleeping\n", 12);
    ft_usleep(data->tts_std, data);
    print_philo(data, philo, "is thinking\n", 12);
}
