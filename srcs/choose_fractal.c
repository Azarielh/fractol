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

void	choose_fractal(t_fractol *f)
{
	if (ft_strcmp_2(f->set, "mandelbrot", "m") == 0)
		render_mandelbrot(f);
	else if (ft_strcmp_2(f->set, "butterfly", "b") == 0)
		render_julia(f, -0.75, 0.11);
	else if (ft_strcmp_2(f->set, "vortex", "v") == 0)
		render_julia(f, -0.8, 0.156);
	else if (ft_strcmp_2(f->set, "dragon de douady", "dd") == 0)
		render_julia(f, -0.7, 0.27015);
	else if (ft_strcmp_2(f->set, "lightning", "l") == 0)
		render_julia(f, -0.1, 0.651);
}
