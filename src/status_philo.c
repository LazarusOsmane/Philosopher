/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:16:35 by christellen       #+#    #+#             */
/*   Updated: 2022/05/17 12:15:30 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_philo(t_philo *p, const char *str)
{
	pthread_mutex_lock(&p->data->lock);
	printf("[%ld] [%d] %s", timestamp() - p->data->genese, p->idx, str);
	pthread_mutex_lock(&p->data->lock);
}
