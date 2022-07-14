/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 12:15:43 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/07/14 16:58:07 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	show_actual_state(t_stack *stack, char a)
{
	if (!stack)
		return ;
	printf("%d\n", stack->content);
	while (stack->next)
	{
		stack = stack->next;
		printf("%d\n", stack->content);
	}
	printf("stack %c-----\n", a);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(*stack);
	}
	*stack = NULL;
}

void	ft_free(t_stack **stack)
{
	ft_free_stack(stack);
}

void	ft_error(t_stack **stack)
{
	ft_putstr_fd("Error\n", 2);
	ft_free(stack);
	exit (1);
}
