/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:08:56 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/07/20 11:51:44 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	do_pos_two(t_stack **stack_a, t_stack **stack_b)
{
	do_move("rra", stack_a, stack_b, 3);
	do_move("rra", stack_a, stack_b, 3);
	do_move("pa", stack_a, stack_b, 2);
	do_move("ra", stack_a, stack_b, 2);
	do_move("ra", stack_a, stack_b, 2);
	do_move("ra", stack_a, stack_b, 2);
}

void	pos_last_num(t_stack **stack_a, t_stack **stack_b, int len, int pos)
{
	if (pos == 1)
	{
		do_move("ra", stack_a, stack_b, 2);
		do_move("pa", stack_a, stack_b, 2);
		do_move("rra", stack_a, stack_b, 3);
	}
	else if ((pos == 2 && len == 4) || pos == 3)
	{
		do_move("rra", stack_a, stack_b, 3);
		do_move("pa", stack_a, stack_b, 2);
		do_move("ra", stack_a, stack_b, 2);
		do_move("ra", stack_a, stack_b, 2);
	}
	else if (pos == 2 && len == 5)
		do_pos_two(stack_a, stack_b);
	else
	{
		do_move("ra", stack_a, stack_b, 2);
		do_move("pa", stack_a, stack_b, 2);
	}
}

static void	four_nums_case(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	int	pos;

	pos = 0;
	do_move("pb", stack_a, stack_b, 2);
	three_nums_case(stack_a, stack_b);
	if ((*stack_b)->content < (*stack_a)->content)
		do_move("pa", stack_a, stack_b, 2);
	if ((*stack_b)->content > (*stack_a)->content)
		pos = 1;
	if ((*stack_b)->content > (*stack_a)->next->content)
		pos = 2;
	if ((*stack_b)->content > (*stack_a)->next->next->content)
	{
		do_move("ra", stack_a, stack_b, 2);
		do_move("pa", stack_a, stack_b, 2);
		pos = 0;
	}
	pos_last_num(stack_a, stack_b, 4, pos);
}

void	five_nums_case(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	int	pos;

	pos = 0;
	if ((*info)->len == 5)
	{
		do_move("pb", stack_a, stack_b, 2);
	}
	four_nums_case(stack_a, stack_b, info);
	if ((*info)->len == 4)
		return ;
	if ((*stack_b)->content < (*stack_a)->content)
	{
		do_move("pa", stack_a, stack_b, 2);
		return ;
	}
	if ((*stack_b)->content > (*stack_a)->content)
		pos = 1;
	if ((*stack_b)->content > (*stack_a)->next->content)
		pos = 2;
	if ((*stack_b)->content > (*stack_a)->next->next->content)
		pos = 3;
	if ((*stack_b)->content > (*stack_a)->next->next->next->content)
		pos = 4;
	pos_last_num(stack_a, stack_b, 5, pos);
}
