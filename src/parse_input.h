// parse_input.h
#ifndef PARSE_INPUT_H
# define PARSE_INPUT_H

typedef struct s_config
{
	int		number_of_coders;
	int		time_to_burnout;
	int		time_to_compile;
	int		time_to_debug;
	int		time_to_refactor;
	int		number_of_compiles_required;
	int		dongle_cooldown;
	char	*scheduler;
}	t_config;

int	parse_args(int argc, char **argv, t_config *cfg);

#endif