/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:29:50 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/07/14 17:58:47 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	at_exit(void)
{
	system("leaks -q push_swap");
}

int	check_num(char *nums, t_stack **stack)
{
	int	i;
	int	num;

	i = -1;
	while (nums[++i])
	{
		if (nums[i] != ' ' && nums[i] != '-' && nums[i] != '+'
			&& (nums[i] < '0' || nums[i] > '9'))
			ft_error(stack);
	}
	num = ft_atoi_check(nums, stack);
	return (num);
}

void	ft_parse_string(char **argv, t_stack	**stack)
{
	char	**nums_splitted;
	int		i;
	int		num;

	nums_splitted = ft_split(argv[1], ' ');
	i = -1;
	while (nums_splitted[++i])
	{
		num = check_num(nums_splitted[i], stack);
		printf("%d\n", num);
		ft_stackadd_back(stack, ft_stack_new(num));
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	//at_exit();
	if (argc < 2)
	{
		return (0);
	}
	ft_parse_string(argv, &stack_a);
	do_move("sa", &stack_a, &stack_b, 2);
	return (0);
}
