/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:16:49 by engooh            #+#    #+#             */
/*   Updated: 2022/05/17 18:02:36 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../inc/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac <= 5)
		return (0);
	data = init_thread(av);
	wait_philo(data, -1);
	destroy_philo(data, -1);
	return (0);
}
