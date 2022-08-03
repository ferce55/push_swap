/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:08:56 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/08/03 11:42:09 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	iter_pos(t_stack **stack_a, t_stack **stack_b, int len, int pos)
{
	t_stack	*aux;

	aux = *stack_a;
	if (pos < (len / 2))
	{
		while (pos > 0)
		{
			pos--;
			do_move("ra", stack_a, stack_b, 2);
		}
	}
	else
	{
		while (pos <= len - 1)
		{
			pos++;
			do_move("rra", stack_a, stack_b, 3);
		}
	}
}

void	four_nums_case(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	int		pos;
	t_stack	*aux;

	pos = 0;
	aux = *stack_a;
	while (aux->next)
	{
		if (aux->content == (*info)->min)
			break ;
		aux = aux->next;
		pos++;
	}
	iter_pos(stack_a, stack_b, 4, pos);
	if (check_order(stack_a) != 0)
	{
		do_move("pb", stack_a, stack_b, 2);
		three_nums_case(stack_a, stack_b);
		do_move("pa", stack_a, stack_b, 2);
	}
}

void	five_nums_case(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	int		pos;
	t_stack	*aux;

	pos = 0;
	aux = *stack_a;
	while (aux->next)
	{
		if (aux->content == (*info)->max)
			break ;
		aux = aux->next;
		pos++;
	}
	iter_pos(stack_a, stack_b, 5, pos);
	do_move("pb", stack_a, stack_b, 2);
	four_nums_case(stack_a, stack_b, info);
	do_move("pa", stack_a, stack_b, 2);
	do_move("ra", stack_a, stack_b, 2);
}
