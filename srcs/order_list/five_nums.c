/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:08:56 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/07/18 15:55:17 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	four_nums_case(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	
}

void	five_nums_case(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	four_nums_case;
	{
		do_move("pb", stack_a, stack_b, 2);
		do_move("pb", stack_a, stack_b, 2);
		three_nums_case(stack_a, stack_b);
	}
	show_actual_state(*stack_a, 'a');
	show_actual_state(*stack_b, 'b');
}