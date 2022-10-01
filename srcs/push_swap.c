/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:29:50 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/10/01 15:59:52 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	at_exit(void)
{
	system("leaks -q push_swap");
}

int	check_num(char *nums, t_stack **stack, t_info **info)
{
	int	i;
	int	num;

	i = -1;
	while (nums[++i])
	{
		if (nums[i] != ' ' && nums[i] != '-' && nums[i] != '+'
			&& (nums[i] < '0' || nums[i] > '9'))
			ft_error(stack, *info);
	}
	num = ft_atoi_check(nums, stack, info);
	return (num);
}

int	check_list(t_stack **stack, t_info **info)
{
	t_stack	*aux;
	t_stack	*aux1;
	int		len;

	len = 0;
	if (!*stack)
		return (0);
	aux = *stack;
	while (aux->next)
	{
		len ++;
		aux1 = aux->next;
		while (aux1)
		{
			if (aux->content == aux1->content)
				ft_error(stack, *info);
			aux1 = aux1->next;
		}
		aux = aux->next;
	}
	(*info)->len = len + 1;
	return (1);
}

void	parse_string(char **argv, t_stack	**stack, t_info **info)
{
	char	**nums_splitted;
	int		i;
	int		j;
	int		num;

	j = 1;
	while (argv[j])
	{
		nums_splitted = ft_split(argv[j], ' ');
		i = 0;
		while (nums_splitted[i])
		{
			num = check_num(nums_splitted[i], stack, info);
			ft_stackadd_back(stack, ft_stack_new(num));
			free(nums_splitted[i]);
			i++;
		}
		free(nums_splitted);
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	*info;

	if (argc < 2)
		return (0);
	info = ft_calloc(1, sizeof(t_info));
	if (!info)
		ft_error(&stack_a, info);
	parse_string(argv, &stack_a, &info);
	if (check_list(&stack_a, &info) == 0)
	{
		ft_free(&stack_a, info);
		return (0);
	}
	if (check_order(&stack_a) == 0)
	{
		ft_free(&stack_a, info);
		return (0);
	}
	check_len(&stack_a, &stack_b, &info);
	ft_free(&stack_a, info);
	return (0);
}
