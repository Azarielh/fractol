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

#include "../../includes/fractol.h"

static int julia_iteration(t_julia j, double c_real, double c_imag, t_fractol *f)
{
	double	temp;
	int		i;

	i = -1;
	while (++i < f->max_iter)
	{
		temp = j.z_real * j.z_real - j.z_imag * j.z_imag + c_real;
		j.z_imag = 2 * j.z_real * j.z_imag + c_imag;
		j.z_real = temp;
		if (j.z_real * j.z_real + j.z_imag * j.z_imag > 4.0)
			return (i);
	}
	return (i);
}

void render_julia(t_fractol *f, double c_real, double c_imag)
{
	int		x;
	int		y;
	int		iterations;
	int		color;
	t_julia	j;
	
    y = 0;

    while (y < f->height)
    {
        x = 0;
        while (x < f->width)
        {
			j.z_real = pixel_to_real(f, x);
			j.z_imag = pixel_to_imag(f, y);
			iterations = julia_iteration(j, c_real, c_imag, f);
			color = get_color(iterations, f->max_iter);
			put_px_to_img(f, x, y, color);
			x++;
        }
        y++;
    }
    mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}
