/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.h                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mamiandr <mamiandr@student.42antananarivo.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/23 05:36:30 by mamiandr         #+#    #+#              */
/*   Updated: 2026/11/26 12:26:55 by mamiandr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "core/core.h"

typedef struct s_Coder
{
	int			id;
	int			in_action;
	int			compiles_done;
	int			is_burnt_out;
	int			last_compile_time;
	int			last_debug_time;
	int			last_refactor_time;
	t_Params	*params;
}	t_Coder;

typedef struct s_Dongle
{
	int	id;
	int	last_used_time;
	int	is_available;
}	t_Dongle;

typedef struct s_workSpace
{
	t_Params	params;
	t_Coder		*coders;
	t_Dongle	*dongles;
}	t_workSpace;
#endif
