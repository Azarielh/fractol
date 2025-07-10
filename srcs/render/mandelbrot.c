/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manderlbrot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:14:26 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/08 21:14:26 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	mandelbrot_iteration(double c_real, double c_imag, int max_iter)
{
	double	z_real;
	double	z_imag;
	double	temp;
	int		i;

	z_real = 0.0;
	z_imag = 0.0;
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

void render_mandelbrot(t_fractol *f)
{
    int x, y;
    double real;
	double imag;
    int iterations;
    int color;
	ft_printf("mandel is here\n");
	ft_random_8bits(f, 0);
    y = 0;
    while (y < f->height)
    {
        x = 0;
        while (x < f->width)
        {
            pixel_to_complex(f, x, y, &real, &imag);
            iterations = mandelbrot_iteration(real, imag, f->max_iter);
            color = get_color(iterations, f->max_iter, f);
            put_px_to_img(f, x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}
