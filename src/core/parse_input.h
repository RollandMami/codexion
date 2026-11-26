/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parse_input.h                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mamiandr <mamiandr@student.42antananarivo.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/26 11:23:36 by mamiandr         #+#    #+#              */
/*   Updated: 2026/11/26 11:35:06 by mamiandr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INPUT_H
# define PARSE_INPUT_H

typedef struct s_Params
{
	int		number_of_coders;
	int		time_to_burnout;
	int		time_to_compile;
	int		time_to_debug;
	int		time_to_refactor;
	int		number_of_compiles_required;
	int		dongle_cooldown;
	char	*scheduler;
}	t_Params;

int	check_args(char **argv, t_Params *params);

#endif
