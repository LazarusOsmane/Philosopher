/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:16:49 by engooh            #+#    #+#             */
/*   Updated: 2022/05/15 10:27:30 by christellen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../inc/philo.h"

int	main(int ac, char **av)
{
	t_all	*all;

	if (ac < 5)
		return (1);
	all = init_philo(av);
	if (wait_philo(all, -1))
		return (destroy_philo(all, -1, 1));
	return (destroy_philo(all, -1, 0));
}
