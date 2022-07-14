/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:56:48 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/07/14 17:58:41 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

void	ft_error(t_stack **stack);
t_stack	*ft_stack_new(int content);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
int		ft_atoi_check(const char *str, t_stack **stack);
void	do_move(char *c, t_stack **stack_a, t_stack **stack_b, int count);
void	iter_swap(char *c, t_stack **stack_a, t_stack **stack_b);
void	iter_rotate(char *c, t_stack **stack_a, t_stack **stack_b);
void	do_swap(t_stack **stack);
void	do_swap_twice(t_stack **stack_a, t_stack **stack_b);
void	do_push(t_stack **stack_src, t_stack **stack_dst);
void	do_rotate(t_stack **stack);
void	do_rotate_twice(t_stack **stack_a, t_stack **stack_b);
void	do_rev_rotate(t_stack **stack);
void	do_rev_rotate_twice(t_stack **stack_a, t_stack **stack_b);

//borrar!!!!!!!
void	show_actual_state(t_stack *stack, char a);

#endif