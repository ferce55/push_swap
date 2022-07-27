/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:21:31 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/07/20 12:37:37 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	three_nums_case(t_stack **stack_a, t_stack **stack_b)
{
	int	pos1;
	int	pos2;
	int	pos3;

	pos1 = (*stack_a)->content;
	pos2 = (*stack_a)->next->content;
	pos3 = (*stack_a)->next->next->content;
	if ((pos1 > pos2) && (pos2 < pos3) && (pos3 > pos1))
		do_move("sa", stack_a, stack_b, 2);
	else if ((pos1 > pos2) && (pos2 > pos3) && (pos3 < pos1))
	{
		do_move("sa", stack_a, stack_b, 2);
		do_move("rra", stack_a, stack_b, 3);
	}
	else if ((pos1 > pos2) && (pos2 < pos3) && (pos3 < pos1))
		do_move("ra", stack_a, stack_b, 2);
	else if ((pos1 < pos2) && (pos2 > pos3) && (pos3 > pos1))
	{
		do_move("sa", stack_a, stack_b, 2);
		do_move("ra", stack_a, stack_b, 2);
	}
	else
		do_move("rra", stack_a, stack_b, 3);
}
