/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:47:54 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/07/27 15:15:37 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;

	max_num = (*info)->len - 1;
	max_bits = 0;
	i = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < (*info)->len)
		{
			if ((((*stack_a)->content >> i) & 1) == 1)
				do_move("ra", stack_a, stack_b, 2);
			else
				do_move("pb", stack_a, stack_b, 2);
			j++;
		}
		i++;
		while (*stack_b)
			do_move("pa", stack_a, stack_b, 2);
	}
}
