/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parse_input.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mamiandr <mamiandr@student.42antananarivo.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/26 11:17:48 by mamiandr         #+#    #+#              */
/*   Updated: 2026/11/26 11:59:39 by mamiandr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parse_input.h"

static int	check_value(int value, char *name, int allow_zero)
{
	if (value < 0 || (value == 0 && !allow_zero))
	{
		printf("[ERROR] Invalid %s: %d\n", name, value);
		return (1);
	}
	return (0);
}

static int	check_positive_integer(t_Params *params)
{
	int	err;

	err = 0;
	err += check_value(params->number_of_coders, "coders", 0);
	err += check_value(params->time_to_burnout, "burnout", 0);
	err += check_value(params->time_to_compile, "compile", 0);
	err += check_value(params->time_to_debug, "debug", 0);
	err += check_value(params->time_to_refactor, "refactor", 0);
	err += check_value(params->number_of_compiles_required, "compiles", 0);
	err += check_value(params->dongle_cooldown, "cooldown", 1);
	return (err > 0);
}

int	check_args(char **argv, t_Params *params)
{
	params->number_of_coders = atoi(argv[1]);
	params->time_to_burnout = atoi(argv[2]);
	params->time_to_compile = atoi(argv[3]);
	params->time_to_debug = atoi(argv[4]);
	params->time_to_refactor = atoi(argv[5]);
	params->number_of_compiles_required = atoi(argv[6]);
	params->dongle_cooldown = atoi(argv[7]);
	if (strcmp(argv[8], "edf") != 0 && strcmp(argv[8], "fifo") != 0)
	{
		printf("[ERROR] Strategy must be edf or fifo: %s\n", argv[8]);
		return (1);
	}
	params->scheduler = strdup(argv[8]);
	return (check_positive_integer(params));
}
