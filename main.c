/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:45:39 by candrese          #+#    #+#             */
/*   Updated: 2024/05/13 07:53:30 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//declare pointers to data structs, stack a and b

//handle input count and errors. argument count must be 2 or more, and the second input must not be empty

//handle inputs as variable number of command line arguments or as a string (split)

//initialize stack a by appending each input number as a node to stack a
//	handle integer overflow, dublicates and syntax errors (only digits, + -)
//	check input if long integer
//		if the input is a string, convert to long integer
//	append the nodes to stack a

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	// init stack
	else
		a = args(argv);

	sa(&a);
//for testing and debugging
	//stack a
	while (a->prev != NULL)
		a=a->prev;
	while (a->next != NULL)
	{
		printf("%d ", a->value);
		a = a->next;
	}
	printf("%d ", a->value);
	//stack b
	// while (b->prev != NULL)
	// 	b=b->prev;
	// while (b->next != NULL)
	// {
	// 	printf("%d ", b->value);
	// 	b = b->next;
	// }
	// printf("%d ", b->value);
// TO DO free_stack(&a);
	return (0);
}
