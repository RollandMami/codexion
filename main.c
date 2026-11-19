/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mamiandr <mamiandr@student.42antananarivo.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 09:10:35 by mamiandr         #+#    #+#              */
/*   Updated: 2026/11/19 09:57:10 by mamiandr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		number_of_coders;
	int		time_to_burnout;
	int		time_to_compile;
	int		time_to_debug;
	int		time_to_refactor;
	int		number_of_compiles_required;
	int		dongle_cooldown;
	char	*scheduler;
	int		error;

	if (argc != 9)
	{
		printf("[ERROR] Number of parameters");
		return (1);
	}
	number_of_coders = atoi(argv[1]);
	if (number_of_coders <= 0)
	{
		error = 1;
		printf("[ERROR] Number of coders: %d", number_of_coders);
	}
	time_to_burnout = atoi(argv[2]);
	if (time_to_burnout <= 0)
	{
		error = 1;
		printf("[ERROR] Time to burnout: %d", time_to_burnout);
	}
	time_to_compile = atoi(argv[3]);
	if (time_to_compile <= 0)
	{
		error = 1;
		printf("[ERROR] Time to compile: %d", time_to_compile);
	}
	time_to_debug = atoi(argv[4]);
	if (time_to_debug <= 0)
	{
		error = 1;
		printf("[ERROR] time to debug: %d", time_to_debug);
	}
	time_to_refactor = atoi(argv[5]);
	if (time_to_refactor <= 0)
	{
		error = 1;
		printf("[ERROR] Tune to refactor: %d", time_to_refactor);
	}
	number_of_compiles_required = atoi(argv[6]);
	if (number_of_compiles_required <= 0)
	{
		error = 1;
		printf("[ERROR] Number of compiles requires: %d", number_of_compiles_required);
	}
	dongle_cooldown = atoi(argv[7]);
	if (dongle_cooldown < 0)
	{
		error = 1;
		printf("[ERROR] Dongle cool down: %d", dongle_cooldown);
	}
	if (strcmp(argv[8]) != "edf" && strcmp(argv[8]) != "fifo")
	{
		error = 1;
		printf("[ERROR] Strategy error %s", argv[8]);
	}
	if (error == 1)
		return (1);
	scheduler = malloc(strlen(argv[8]) + 1);
	strcpy(scheduler, argv[8]);
	printf("hello world %s\n", scheduler);
	free(scheduler);
	return (0);
}
