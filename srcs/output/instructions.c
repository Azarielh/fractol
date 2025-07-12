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

#include "../../includes/fractol.h"

void	runwhile_instruction(void)
{
	ft_putendl_fd( "┌─────────────┐", 1);
	ft_putendl_fd( "|   FRACTOL   |", 1);
	ft_putendl_fd( "└─────────────┘", 1);
	ft_putendl_fd( "Mouse wheel: Zoom in/out", 1);
	ft_putendl_fd( "Space: Change colors", 1);
	ft_putendl_fd( "ESC: Exit", 1);
}

void	print_instructions(void)
{
	ft_putendl_fd("┌──────────────────────────────────────┐", 1);
	ft_putendl_fd("│                FRACTOL               │", 1);
	ft_putendl_fd("└──────────────────────────────────────┘\n", 1);
	ft_putendl_fd("This program can displays 2 different set of fractals", 1);
	ft_putendl_fd("While launching, you need to choose the one you want to see\n", 1);
	ft_putendl_fd("Note that arguments are case insensitive\n", 1);
	ft_putendl_fd(" For Mandelbrot :\n     ./fractol [m || mandelbrot]\n", 1);
	ft_putendl_fd("───────────────────────────────────────\n", 1);
	ft_putendl_fd(" For Julia :\n     ./fractol [j || julia]\n", 1);
	ft_putendl_fd("\nFor any sets of your choice,", 1);
	ft_putendl_fd("You can choose the color theme you want to start with", 1);
}

