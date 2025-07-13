/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:15:52 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/13 19:37:32 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pars_args(char **args, t_fractol *f)// second param for julia must be : (b || butterfly) (v || vortex)
{
	f->set = ft_tolower_str(args[1]);
	if (args[2] && (ft_strcmp(f->set, "j") == 0 ||
			ft_strcmp(f->set, "julia") == 0))
	{
		if (!args[2])
			exit_error("The set of Julia recquire an extra argument.\
							Pleasse, read the instruction >> \n", 1);
		else if (ft_strcmp_2(args[2], "butterfly", "b") == 0)
			  f->set = ft_tolower_str(args[2]);
		else if (ft_strcmp_2(args[2], "vortex", "v") == 0)
			f->set = ft_tolower_str(args[2]);
		else if (ft_strcmp_2(args[2], "dragon de douady", "dd") == 0)
			f->set = ft_tolower_str(args[2]);
		else if (ft_strcmp_2(args[2], "lightning", "l") == 0)
			f->set = ft_tolower_str(args[2]);
		else
			exit_error("There is an arror with your arguments. Please, check\
							avalaible argumentss for set of Julia. >> \n", 1);
	}
	else if (ft_strcmp_2(f->set, "mandelbrot", "m") != 0)
		exit_error("Please, read the following instructions >> \n", 1);
}
