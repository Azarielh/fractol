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

static int julia_iteration(double z_real, double z_imag, double c_real, double c_imag, int max_iter)
{
	double	temp;
	int		i;

	i = -1;
	while (++i < max_iter)
	{
		temp = z_real * z_real - z_imag * z_imag + c_real;
		z_imag = 2 * z_real * z_imag + c_imag;
		z_real = temp;
		if (z_real * z_real + z_imag * z_imag > 4.0)
			return (i);
	}
	return (i);
}

void render_julia(t_fractol *f, double c_real, double c_imag)
{
    int x, y;
    double real;
	double imag;
    int iterations;
    int color;
	
    y = 0;

    while (y < f->height)
    {
        x = 0;
        while (x < f->width)
        {
            pixel_to_complex(f, x, y, &real, &imag);
            iterations = julia_iteration(real, imag, c_real, c_imag, f->max_iter);
            color = get_color(iterations, f->max_iter, f);
            put_px_to_img(f, x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}
