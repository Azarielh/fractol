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
	static int	winter[3];
	static int	summer[3];
	static int	autumn[3];
	static int	spring[3];
	static int	init;

	if (!init)
		init_color_palettes(winter, summer, autumn, spring, &init);
	if (ft_strcmp(theme, "winter") == 0)
		return (winter);
	else if (ft_strcmp(theme, "summer") == 0)
		return (summer);
	else if (ft_strcmp(theme, "autumn") == 0)
		return (autumn);
	else if (ft_strcmp(theme, "spring") == 0)
		return (spring);
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
		return (0x000000);	
	if (iterations < max_iter * 0.1)
		return (f->background_color);
	f->rm_color = (f->rm_color * 1103515245 + 12345) & 0x7FFFFFFF;
	r = (theme[0] + (f->rm_color & 0x3F)) % 256;
	g = (theme[1] + ((f->rm_color >> 6) & 0x3F)) % 256;
	b = (theme[2] + ((f->rm_color >> 12) & 0x3F)) % 256;

	rgb = ((f->rm_color >> 18) % 256 | r << 16) | (g << 8) | b;
	return (rgb);
}

void cycle_background_color(t_fractol *f)
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
