/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:22:07 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/08 14:22:07 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void init_fractol(t_fractol *f, char **args)
{
	pars_args(args, f);
	f->width = 800;
	f->height = 800;
	f->x_min = -2.5;
	f->x_max = 1.0;
	f->y_min = -1.25;
	f->y_max = 1.25;
	f->max_iter = 100;
	f->background_color = 0x000000;
	f->mlx_ptr = safe_init();
	f->win_ptr = safe_win_opener(f, "Fractol");
	f->img_ptr = mlx_new_image(f->mlx_ptr, f->width, f->height);
	f->img_data = mlx_get_data_addr(f->img_ptr, &f->bits, 
										&f->line_len, &f->endian);
}

int main(int argc, char **args)
{
    t_fractol f;
	
	if(argc < 2)
		exit_error("Please, read the following instructions >>\n", 1);
	runwhile_instruction();
	init_fractol(&f, args);
	choose_fractal(&f);
	mlx_key_hook(f.win_ptr, keys_handler, &f);
	mlx_mouse_hook(f.win_ptr, mouse_handler, &f);
	mlx_hook(f.win_ptr, DestroyNotify, 0, close_window, &f);
	mlx_hook(f.win_ptr, ConfigureNotify, 0, resize_handler, &f);

	mlx_loop(f.mlx_ptr);
	return (0);
}
