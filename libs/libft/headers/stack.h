/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:08:18 by mrouves           #+#    #+#             */
/*   Updated: 2025/02/20 23:08:27 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <collection.h>

# define STACK_INIT 64

typedef t_collection	t_stack;

void	stack_push(t_stack *stack, void *data);
void	stack_pops(t_stack *stack, uint32_t nb);
void	*stack_pop(t_stack *stack);
void	*stack_top(t_stack *stack);

#endif
