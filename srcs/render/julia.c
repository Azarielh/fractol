/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:20:18 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/09 12:20:18 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int julia_iteration(t_draw d, double c_real, double c_imag, t_fractol *f)
{
	double	temp;
	int		i;

	i = -1;
	while (++i < f->max_iter)
	{
		temp = d.z_real * d.z_real - d.z_imag * d.z_imag + c_real;
		d.z_imag = 2 * d.z_real * d.z_imag + c_imag;
		d.z_real = temp;
		if (d.z_real * d.z_real + d.z_imag * d.z_imag > 4.0)
			return (i);
	}
	return (get_color(i, f->max_iter));
}

void render_julia(t_fractol *f, double c_real, double c_imag)
{
	int		x;
	int		y;
	int		color;
	t_draw	d;
	
    y = 0;

    while (y < f->height)
    {
        x = 0;
        while (x < f->width)
        {
			d.z_real = pixel_to_real(f, x);
			d.z_imag = pixel_to_imag(f, y);
			color = julia_iteration(d, c_real, c_imag, f);
			put_px_to_img(f, x, y, color);
			x++;
        }
        y++;
    }
    mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}
