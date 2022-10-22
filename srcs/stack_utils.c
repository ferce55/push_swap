/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:31:57 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/10/01 17:26:06 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	new->next = *stack;
	*stack = new;
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*aux;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	aux = ft_stacklast(*stack);
	aux->next = new;
}
