/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:55:14 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/09 20:55:14 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	set_tdraw(t_draw *d, double c_real, double c_imag)
{
	d->c_real = c_real;
	d->c_imag = c_imag;
}

void	choose_fractal(t_fractol *f)
{
	t_draw	d;

	if (ft_strcmp_2(f->set, "mandelbrot", "m") == 0)
		render_mandelbrot(f, &d);
	else if (ft_strcmp_2(f->set, "butterfly", "b") == 0)
	{
		set_tdraw(&d, -0.75, 0.11);
		render_julia(f, &d);
	}
	else if (ft_strcmp_2(f->set, "vortex", "v") == 0)
	{
		set_tdraw(&d, -0.8, 0.156);
		render_julia(f, &d);
	}
	else if (ft_strcmp_2(f->set, "dragon de douady", "dd") == 0)
	{
		set_tdraw(&d, -0.7, 0.27015);
		render_julia(f, &d);
	}
	else if (ft_strcmp_2(f->set, "lightning", "l") == 0)
	{
		set_tdraw(&d, -0.1, 0.651);
		render_julia(f, &d);
	}
}
