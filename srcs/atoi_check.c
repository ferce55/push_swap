/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:25:25 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/07/18 12:12:21 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_result(unsigned int res, int s)
{
	if ((res > 2147483647 && s == 1) || (res > 2147483648 && s == -1))
		return (-1);
	return (0);
}

int	ft_atoi_check(const char *str, t_stack **stack, t_info **info)
{
	int				i;
	int				s;
	unsigned int	res;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(stack, *info);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (check_result(res, s) < 0)
		ft_error(stack, *info);
	return (res * s);
}
