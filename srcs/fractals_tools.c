/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:03:08 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/09 12:03:08 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	pixel_to_real(t_fractol *f, int x)
{
	return (f->x_min + (double)x * (f->x_max - f->x_min) / f->width);
}

double	pixel_to_imag(t_fractol *f, int y)
{
	return (f->y_min + (double)y * (f->y_max - f->y_min) / f->height);
}

void put_px_to_img(t_fractol *f, int x, int y, int color)
{
	int offset;

	offset =  (y * f->line_len + x * (f->bits / 8));
	f->img_data[offset] = color;
}

