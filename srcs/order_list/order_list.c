/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:47:59 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/08/17 12:05:14 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	parse_array(t_stack **stack_a, t_info **info, int *array)
{
	int		i;
	t_stack	*aux;

	i = 0;
	aux = *stack_a;
	while (i < (*info)->len - 1)
	{
		array[i] = aux->content;
		aux = aux->next;
		i++;
	}
	array[i] = aux->content;
}

static void	order_array(t_info **info, int *array)
{
	int	i;
	int	j;
	int	swapped;
	int	aux;

	i = 0;
	while (i < (*info)->len - 1)
	{
		swapped = 0;
		j = 0;
		while (j < (*info)->len - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
	}
}

static int	get_pos(t_stack *aux, int min, int max, int *array)
{
	int	pos;

	pos = -1;
	while (pos == -1)
	{
		if (aux->content == array[(min + max) / 2])
			pos = (min + max) / 2;
		else if (aux->content > array[(min + max) / 2])
			min = (min + max) / 2;
		else
			max = (min + max) / 2;
	}
	return (pos);
}

static void	get_list_pos(t_stack **stack_a, t_info **info, int *array)
{
	int		min;
	int		max;
	int		pos;
	t_stack	*aux;

	aux = *stack_a;
	while (aux)
	{	
		pos = -1;
		min = 0;
		max = (*info)->len - 1;
		if (aux->content == array[min])
			pos = 0;
		else if (aux->content == array[max])
			pos = (*info)->len - 1;
		else
			pos = get_pos(aux, min, max, array);
		aux->content = pos;
		aux = aux->next;
	}
}

void	order_list(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	int	*array;

	array = malloc(sizeof(int) * (*info)->len);
	parse_array(stack_a, info, array);
	order_array(info, array);
	get_list_pos(stack_a, info, array);
	radix_sort(stack_a, stack_b, info);
	free(array);
}
