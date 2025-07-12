/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 06:17:07 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/11 06:17:07 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int *get_theme(char *theme)
{
	static int	theme1[3];
	static int	theme2[3];
	static int	theme3[3];
	static int	theme4[3];
	static int	init;

	if (!init)
		init_color_palettes(theme1, theme2, theme3, theme4, &init);
	if (ft_strcmp(theme, "theme1") == 0)
		return (theme1);
	else if (ft_strcmp(theme, "theme2") == 0)
		return (theme2);
	else if (ft_strcmp(theme, "theme3") == 0)
		return (theme3);
	else if (ft_strcmp(theme, "theme4") == 0)
		return (theme4);
	return (theme1);
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
		return (f->background_color);
	if (iterations < max_iter * 0.1)
		return (f->background_color);
	f->rm_color = (f->rm_color * 1103515245 + 12345) & 0x7FFFFFFF;
	r = (theme[0] + (f->rm_color & 0x3F)) % 256;
	g = (theme[1] + ((f->rm_color >> 6) & 0x3F)) % 256;
	b = (theme[2] + ((f->rm_color >> 12) & 0x3F)) % 256;

	rgb = (r << 16) | (g << 8) | b;
	return (rgb);
}

void switch_color(t_fractol *f)
{
	static int	color_index;
	static int	clr[8];
	static char	*themes[4];
	static int	th_index;
	int			clr_len;

	init_themes(themes);
	init_background(clr);
	clr_len = sizeof(clr) / sizeof(clr[0]);
	color_index = (color_index + 1) % clr_len;
	if (color_index % 2 == 0)
	{
		th_index = (th_index + 1) % (sizeof(themes) / sizeof(themes[0]));
		free(f->theme);
		f->theme = ft_strdup(themes[th_index]);
	}
	f->background_color = clr[color_index];
	choose_fractal(f);
}
