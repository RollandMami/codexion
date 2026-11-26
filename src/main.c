/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mamiandr <mamiandr@student.42antananarivo.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 09:10:35 by mamiandr         #+#    #+#              */
/*   Updated: 2026/11/26 12:30:27 by mamiandr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "main.h"

int	main(int argc, char **argv)
{
	t_Params	params;
	int			err;
	t_workSpace	workspace;

	if (argc != 9)
	{
		printf("[ERROR] Number of parameters\n");
		return (1);
	}
	err = check_args(argv, &params);
	if (err == 1)
		return (1);
	printf("hello world %s\n", params.scheduler);
	workspace.params = params;
	workspace.coders = malloc(sizeof(t_Coder)*params.number_of_coders);
	if (workspace.coders == NULL)
	{
		printf("[ERROR] Memory allocation failed for coders\n");
		return (1);
	}
	workspace.dongles = malloc(sizeof(t_Dongle)*params.number_of_dongles);
	if (workspace.dongles == NULL)
	{
		printf("[ERROR] Memory allocation failed for dongles\n");
		return (1);
	}
	return (0);
}
