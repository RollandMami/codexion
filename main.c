/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mamiandr <mamiandr@student.42antananarivo.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 09:10:35 by mamiandr         #+#    #+#              */
/*   Updated: 2026/11/23 08:52:21 by mamiandr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int	check_args(char **argv, t_Params *params)
{
	int	error;

	error = 0;
	params->number_of_coders = atoi(argv[1]);
	if (params->number_of_coders <= 0)
	{
		error = 1;
		printf("[ERROR] Number of coders: %d", params->number_of_coders);
	}
	params->time_to_burnout = atoi(argv[2]);
	if (params->time_to_burnout <= 0)
	{
		error = 1;
		printf("[ERROR] Time to burnout: %d", params->time_to_burnout);
	}
	params->time_to_compile = atoi(argv[3]);
	if (params->time_to_compile <= 0)
	{
		error = 1;
		printf("[ERROR] Time to compile: %d", params->time_to_compile);
	}
	params->time_to_debug = atoi(argv[4]);
	if (params->time_to_debug <= 0)
	{
		error = 1;
		printf("[ERROR] time to debug: %d", params->time_to_debug);
	}
	params->time_to_refactor = atoi(argv[5]);
	if (params->time_to_refactor <= 0)
	{
		error = 1;
		printf("[ERROR] Time to refactor: %d", params->time_to_refactor);
	}
	params->number_of_compiles_required = atoi(argv[6]);
	if (params->number_of_compiles_required <= 0)
	{
		error = 1;
		printf("[ERROR] Number of compiles requires: %d",
			params->number_of_compiles_required);
	}
	params->dongle_cooldown = atoi(argv[7]);
	if (params->dongle_cooldown < 0)
	{
		error = 1;
		printf("[ERROR] Dongle cool down: %d", params->dongle_cooldown);
	}
	if (strcmp(argv[8], "edf") != 0 && strcmp(argv[8], "fifo") != 0)
	{
		error = 1;
		printf("[ERROR] Strategy must be edf or fifo: %s\n", argv[8]);
	}
	params->scheduler = strdup(argv[8]);
	return (error);
}

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
