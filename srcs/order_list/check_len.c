/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:16:58 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/07/20 10:42:50 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_order(t_stack **stack_a)
{
	t_stack	*aux;

	aux = *stack_a;
	while (aux->next)
	{
		if (aux->content > aux->next->content)
			return (1);
		aux = aux->next;
	}
	return (0);
}

void	check_len(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	if ((*info)->len == 2)
		do_move("sa", stack_a, stack_b, 2);
	if ((*info)->len == 3)
		three_nums_case(stack_a, stack_b);
	else if ((*info)->len <= 5)
		five_nums_case(stack_a, stack_b, info);
	/*else 
		//order_list(stack_a, stack_b, info);*/
	show_actual_state(*stack_a, 'a');
	show_actual_state(*stack_b, 'b');
}
