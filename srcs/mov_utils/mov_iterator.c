/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_iterator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:51:30 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/07/14 18:02:36 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	iter_swap(char *c, t_stack **stack_a, t_stack **stack_b)
{
	if (c[1] == 'a')
	{
		do_swap(stack_a);
		write(1, "sa\n", 3);
	}
	if (c[1] == 'b')
	{
		do_swap(stack_b);
		write(1, "sb\n", 3);
	}
	if (c[1] == 's')
	{
		do_swap_twice(stack_a, stack_b);
		write(1, "ss\n", 3);
	}
}

void	iter_push(char *c, t_stack **stack_a, t_stack **stack_b)
{
	if (c[1] == 'a')
	{
		do_push(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
	if (c[1] == 'b')
	{
		do_push(stack_b, stack_a);
		write(1, "pb\n", 3);
	}
}

void	iter_rotate(char *c, t_stack **stack_a, t_stack **stack_b)
{
	if (c[1] == 'a')
	{
		do_rotate(stack_a);
		write(1, "ra\n", 3);
	}
	if (c[1] == 'b')
	{
		do_rotate(stack_a);
		write(1, "rb\n", 3);
	}
	if (c[1] == 'r')
	{
		do_rotate_twice(stack_a, stack_b);
		write(1, "rr\n", 3);
	}
}

void	iter_rev_rotate(char *c, t_stack **stack_a, t_stack **stack_b)
{
	if (c[2] == 'a')
	{
		do_rev_rotate(stack_a);
		write(1, "rra\n", 4);
	}
	if (c[2] == 'b')
	{
		do_rev_rotate(stack_b);
		write(1, "rrb\n", 4);
	}
	if (c[2] == 'r')
	{
		do_rev_rotate_twice(stack_a, stack_b);
		write(1, "rrr\n", 4);
	}
}

void	do_move(char *c, t_stack **stack_a, t_stack **stack_b, int count)
{
	if (count == 2)
	{
		if (c[0] == 's')
			iter_swap(c, stack_a, stack_b);
		if (c[0] == 'p')
			iter_push(c, stack_a, stack_b);
		if (c[0] == 'r')
			iter_rotate(c, stack_a, stack_b);
	}
	if (count == 3)
	{
		iter_rev_rotate(c, stack_a, stack_b);
	}
}
