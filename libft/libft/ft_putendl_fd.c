/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:56:34 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/01/13 12:38:35 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

desc:	Envia la string al fichero con un salto de linea

*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
