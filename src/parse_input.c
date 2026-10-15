// parse_input.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include "parse_input.h"

static int	parse_positive_int(const char *str, int *out, const char *name)
{
	char	*end;
	long	val;

	errno = 0;
	val = strtol(str, &end, 10);
	if (errno != 0 || end == str || *end != '\0'
		|| val <= 0 || val > INT_MAX)
	{
		fprintf(stderr, "Erreur: %s invalide ('%s')\n", name, str);
		return (0);
	}
	*out = (int)val;
	return (1);
}

int	parse_args(int argc, char **argv, t_config *cfg)
{
	if (argc != 9)
	{
		fprintf(stderr, "Usage: %s coders burnout compile debug "
			"refactor nb_compiles dongle_cooldown scheduler\n", argv[0]);
		return (0);
	}
	if (!parse_positive_int(argv[1], &cfg->number_of_coders, "number_of_coders")
		|| !parse_positive_int(argv[2], &cfg->time_to_burnout, "time_to_burnout")
		|| !parse_positive_int(argv[3], &cfg->time_to_compile, "time_to_compile")
		|| !parse_positive_int(argv[4], &cfg->time_to_debug, "time_to_debug")
		|| !parse_positive_int(argv[5], &cfg->time_to_refactor, "time_to_refactor")
		|| !parse_positive_int(argv[6], &cfg->number_of_compiles_required,
			"number_of_compiles_required")
		|| !parse_positive_int(argv[7], &cfg->dongle_cooldown, "dongle_cooldown"))
		return (0);
	if (strcmp(argv[8], "fifo") != 0 && strcmp(argv[8], "edf") != 0)
	{
		fprintf(stderr, "Erreur: scheduler doit être 'fifo' ou 'edf'\n");
		return (0);
	}
	cfg->scheduler = argv[8];
	return (1);
}