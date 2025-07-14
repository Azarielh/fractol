/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:17:27 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/10 17:17:27 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	runwhile_instruction(void)
{
	ft_putendl_fd("┌─────────────┐", 1);
	ft_putendl_fd("|   FRACTOL   |", 1);
	ft_putendl_fd("└─────────────┘", 1);
	ft_putendl_fd("Mouse wheel: Zoom in/out", 1);
	ft_putendl_fd("SPACE: switch fractal set", 1);
	ft_putendl_fd("ESC: Exit", 1);
}

static void	print_for_julia(void)
{
	ft_putendl_fd(" For Julia's set :\n"
		"./fractol [j || julia]\n", 1);
	ft_putendl_fd("If you run Julia's set, you need option :\n", 1);
	ft_putendl_fd("For its butterfly version set :", 1);
	ft_putendl_fd("                    'butterfly' or 'b'", 1);
	ft_putendl_fd("For its vortex version set :", 1);
	ft_putendl_fd("                    'vortex' or 'v'", 1);
	ft_putendl_fd("For its lightning version set :", 1);
	ft_putendl_fd("                    'lightning' or 'l'", 1);
	ft_putendl_fd("For its dragon de douady version set :", 1);
	ft_putendl_fd("                    'dragon de douady' or 'dd'\n"
		"Due to the inbetween space in the name.\n"
		"The proper way is to use double quote arround 'dragon de douady", 1);
}

void	print_instructions(void)
{
	ft_putendl_fd("┌──────────────────────────────────────┐", 1);
	ft_putendl_fd("│                FRACTOL               │", 1);
	ft_putendl_fd("└──────────────────────────────────────┘\n", 1);
	ft_putendl_fd("This program can displays 2 different"
		"set of fractals", 1);
	ft_putendl_fd("While launching,"
		"you need to choose the one you want to see\n", 1);
	ft_putendl_fd("Note that arguments are case insensitive\n", 1);
	ft_putendl_fd(" For Mandelbrot's set :\n"
		"./fractol [m || mandelbrot]\n", 1);
	ft_putendl_fd("───────────────────────────────────────\n", 1);
	print_for_julia();
}
