/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:18:51 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/08 18:18:51 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_window(t_fractol *f)
{
	clean_exit(f);
	return (0);
}

int	resize_handler(t_fractol *f)
{
	static int	init;

	init = 0;
	if (init == 0)
	{
		init = 1;
		return (0);
	}
	if (f->img_ptr)
		mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	f->width = 1024;
	f->height = 768;
	f->img_ptr = mlx_new_image(f->mlx_ptr, f->width, f->height);
	f->img_data = mlx_get_data_addr(f->img_ptr, &f->bits, &f->line_len, &f->endian);
	choose_fractal(f);
	return (0);
}