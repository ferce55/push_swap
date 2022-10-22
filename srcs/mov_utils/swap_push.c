/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:00:32 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/10/01 16:18:46 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	do_push(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*aux;

	aux = (*stack_src)->next;
	ft_stackadd_front(stack_dst, *stack_src);
	*stack_src = aux;
} 

void	do_swap(t_stack **stack)
{
	t_stack	*aux;

	aux = *stack;
	*stack = (*stack)->next;
	aux->next = (*stack)->next;
	(*stack)->next = aux;
}

void	do_swap_twice(t_stack **stack_a, t_stack **stack_b)
{
	do_swap(stack_a);
	do_swap(stack_b);
}
