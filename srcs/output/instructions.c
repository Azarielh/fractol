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
	t_fractol f;
    int color = 0xFFFFFF;  // Blanc
    f.width = 500;
	f.height = 500;
	f.mlx_ptr = safe_init(&f);
	f.win_ptr = safe_win_opener(&f,"Fractol");
	f.img_ptr = mlx_new_image(f.mlx_ptr, 500, 500);
	f.img_data = mlx_get_data_addr(f.img_ptr, &f.bits, 
										&f.line_len, &f.endian);
	f.img_data = mlx_get_data_addr(f.img_ptr, &f.bits, &f.line_len, &f.endian);
	mlx_string_put(f.mlx_ptr, f.win_ptr, 10, 20, color, "┌─────────────┐");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 10, 20, color, "|   FRACTOL   |");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 10, 20, color, "└─────────────┘");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 10, 40, color, "Mouse wheel: Zoom in/out");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 10, 60, color, "Arrow keys: Move view");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 10, 80, color, "ESC: Exit");
	mlx_string_put(f.mlx_ptr, f.win_ptr, 10, 100, color, "Space: Change colors");

	mlx_key_hook(f.win_ptr, keys_handler, &f);
	mlx_mouse_hook(f.win_ptr, mouse_handler, &f);
	mlx_hook(f.win_ptr, DestroyNotify, 0, close_window, &f);
	// mlx_hook(f.win_ptr, 22, 0, resize_handler, &f);
	mlx_loop(f.mlx_ptr);
}

void	param_instructions(void)
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

