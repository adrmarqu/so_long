/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:19:41 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/03 13:36:13 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_lay	lay;

	lay = ft_newlay();
	check_arguments(argc, argv[1], &lay);
	init_game(&lay);
	return (0);
}
