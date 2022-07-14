/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:44:16 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/07/14 17:44:26 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	do_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*sec;
	t_stack	*frst;

	frst = *stack;
	last = ft_stacklast(*stack);
	sec = frst->next;
	*stack = sec;
	last->next = frst;
	frst->next = 0;
}

void	do_rotate_twice(t_stack **stack_a, t_stack **stack_b)
{
	do_rotate(stack_a);
	do_rotate(stack_b);
}

void	do_rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*b_last;
	t_stack	*frst;

	frst = *stack;
	last = ft_stacklast(*stack);
	b_last = *stack;
	while ((b_last->next)->next)
		b_last = b_last->next;
	last->next = frst;
	*stack = last;
	b_last->next = 0;
}

void	do_rev_rotate_twice(t_stack **stack_a, t_stack **stack_b)
{
	do_rev_rotate(stack_a);
	do_rev_rotate(stack_b);
}
