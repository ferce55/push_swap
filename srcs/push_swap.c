/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:29:50 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/10/03 19:18:04 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	if (argc >= 2)
	{
		write (1, "aqui", 4);//parsear parametros
	}
	if (argc == 1)
	{
		ft_error();
	}
	argv = 0;
	write (1, "hola", 4);
}
