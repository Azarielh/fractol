/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:19:18 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/08 18:19:18 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_at_point(int scroll, int x, int y, t_fractol *f)
{
	double	real;
	double	imag;

	real = pixel_to_real(f, x);
	imag = pixel_to_imag(f, y);
	if (scroll == SCROLL_UP)
	{
		f->x_min = real - ((f->x_max - f->x_min) / 1.48) / 2.0;
		f->x_max = real + ((f->x_max - f->x_min) / 1.48) / 2.0;
    	f->y_min = imag - ((f->y_max - f->y_min) / 1.48) / 2.0;
    	f->y_max = imag + ((f->y_max - f->y_min) / 1.48) / 2.0;
	}
	if (scroll == SCROLL_DOWN)
	{
		f->x_min = real - ((f->x_max - f->x_min) / 0.68) / 2.0;
		f->x_max = real + ((f->x_max - f->x_min) / 0.68) / 2.0;
    	f->y_min = imag - ((f->y_max - f->y_min) / 0.68) / 2.0;
    	f->y_max = imag + ((f->y_max - f->y_min) / 0.68) / 2.0;
	}
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	f->img_ptr = mlx_new_image(f->mlx_ptr, f->width, f->height);
	f->img_data = mlx_get_data_addr(f->img_ptr, &f->bits, &f->line_len, &f->endian);

	choose_fractal(f);
}

int	mouse_handler(int button, int x, int y, void *param)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		zoom_at_point(button, x, y, (t_fractol *)param);
	return (0);
}