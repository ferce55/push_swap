/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 12:15:43 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/10/01 17:08:49 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	free(stack);
}

void	ft_free(t_stack *stack, t_info *info)
{
	free(info);
	ft_free_stack(stack);
}

void	ft_error(t_stack *stack, t_info *info)
{
	ft_putstr_fd("Error\n", 2);
	ft_free(stack, info);
	exit (1);
}
