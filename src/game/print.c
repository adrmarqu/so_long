/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:37:23 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/15 14:27:16 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(const char *s)
{
	ft_printf(RED "Error\n" YELLOW "%s" WHITE "\n", s);
	exit(1);
}

void	print_move(const int nb, const char *s)
{
	ft_printf(CYAN "Moves: %d\n" MAGENTA "ACTION: %s\n\n", nb, s);
}
