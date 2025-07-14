/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:19:18 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/14 22:51:39 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	store_previous_minmax(t_fractol *f, t_zoom_data *previous)
{
	previous->x_min = f->x_min;
	previous->x_max = f->x_max;
	previous->y_min = f->y_min;
	previous->y_max = f->y_max;
}

void	zoom_at_point(int scroll, int x, int y, t_fractol *f)
{
	double		real;
	double		imag;
	t_zoom_data	previous;

	real = pixel_to_real(f, x);
	imag = pixel_to_imag(f, y);
	previous.x_max = 0.0;
	store_previous_minmax(f, &previous);
	if (scroll == SCROLL_UP)
	{
		f->max_iter += 8;
		f->x_min = real - ((previous.x_max - previous.x_min) / 1.48) * 0.5;
		f->x_max = real + ((previous.x_max - previous.x_min) / 1.48) * 0.5;
		f->y_min = imag - ((previous.y_max - previous.y_min) / 1.48) * 0.5;
		f->y_max = imag + ((previous.y_max - previous.y_min) / 1.48) * 0.5;
	}
	if (scroll == SCROLL_DOWN)
	{
		f->max_iter -= 8;
		f->x_min = real - ((previous.x_max - previous.x_min) * 1.5) * 0.5;
		f->x_max = real + ((previous.x_max - previous.x_min) * 1.5) * 0.5;
		f->y_min = imag - ((previous.y_max - previous.y_min) * 1.5) * 0.5;
		f->y_max = imag + ((previous.y_max - previous.y_min) * 1.5) * 0.5;
	}
	choose_fractal(f);
}

int	mouse_handler(int button, int x, int y, void *param)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		zoom_at_point(button, x, y, (t_fractol *)param);
	return (0);
}
