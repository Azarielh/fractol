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

void	pixel_to_complex(t_fractol *f, int x, int y, double *real, double *imag)
{
	*real = f->x_min + (double)x * (f->x_max - f->x_min) / f->width;
    *imag = f->y_min + (double)y * (f->y_max - f->y_min) / f->height;
}

void put_px_to_img(t_fractol *f, int x, int y, int color)
{
	char *dst;
	
	dst = f->img_data + (y * f->line_len + x * (f->bits / 8));
	*(unsigned int*)dst = color;
}

static void init_color_palettes(int winter[3], int summer[3], int sea[3], 
									int purple[3], int *init)
{
	winter[0] = 64;
	winter[1] = 50;
	winter[2] = 255;
	summer[0] = 255;
	summer[1] = 100;
	summer[2] = 30;
	sea[0] = 30;
	sea[1] = 150;
	sea[2] = 255;
	purple[0] = 200;
	purple[1] = 50;
	purple[2] = 255;
	*init = 1;
}

int *get_theme(char *theme)
{
	static int	winter[3];
	static int	summer[3];
	static int	sea[3];
	static int	purple[3];
	static int	init;

	if (!init)
		init_color_palettes(winter, summer, sea, purple, &init);

	if (ft_strcmp(theme, "winter") == 0)
		return (winter);
	else if (ft_strcmp(theme, "summer") == 0)
		return (summer);
	else if (ft_strcmp(theme, "sea") == 0)
		return (sea);
	else if (ft_strcmp(theme, "purple") == 0)
		return (purple);
	return (summer);
}

int get_color(int iterations, int max_iter, t_fractol *f)
{
	int	*theme;
	int rgb;
	int r;
	int g;
	int b;

	theme = get_theme(f->theme);
	if (iterations == max_iter)
	{
		r = ft_random_8bits(f, theme[0]);
		g = ft_random_8bits(f, theme[1]);
		b = ft_random_8bits(f, theme[2]);
		rgb = (r << 16) | (g << 8) | b;
		return (rgb);
	}
	// Dégradé coloré basé sur iterations
	r = theme[0];
	g = theme[1];
	b = theme[2];

	rgb = (r << 16) | (g << 8) | b;
	return (rgb);
}

unsigned int ft_random_8bits(t_fractol * f, int max)
{
	unsigned int rm_value;

	if (max == 255)
		rm_value = (f->rm_color * 1103515245 + 12345) & 0xFF;
	else if (max == 127)
		rm_value = (f->rm_color * 1103515245 + 12345) & 0x7F;
	else if (max == 63)
		rm_value = (f->rm_color * 1103515245 + 12345) & 0x3F;
	else if (max == 31)
		rm_value = (f->rm_color * 1103515245 + 12345) & 0x1F;
	else if (max == 0)
		f->rm_color = (f->rm_color * 1103515245 + 12345) & 0x7fffffff;
	else
	 {
		f->rm_color = (f->rm_color * 1103515245 + 12345) & 0x7fffffff;
		return (f->rm_color % (max + 1));
    }
	return (rm_value);
}
