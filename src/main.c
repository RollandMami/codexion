/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mamiandr <mamiandr@student.42antananarivo.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 09:10:35 by mamiandr         #+#    #+#              */
/*   Updated: 2026/11/26 11:18:21 by mamiandr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int	main(int argc, char **argv)
{
	t_Params	params;

	if (argc != 9)
	{
		printf("[ERROR] Number of parameters");
		return (1);
	}
	params.scheduler = NULL;
	if (check_args(argv, &params) == 1)
		return (1);
	printf("hello world %s\n", params.scheduler);
	return (0);
}
