/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 06:14:52 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/11 06:14:52 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	init_themes(char *themes[4])
{
	themes[0] = "winter";
	themes[1] = "summer";
	themes[2] = "autumn";
	themes[3] = "spring";
}

void	init_backgound_clr(int clr[8])
{
	clr[0] = 0x0f1419;
	clr[1] = 0x2c2c54;
	clr[2] = 0x3d3d10;
	clr[3] = 0x4a1810;
	clr[4] = 0x3d2818;
	clr[5] = 0x4a3020;
	clr[6] = 0x1f3d1f;
	clr[7] = 0x0d2d1a;
}

void init_color_palettes(int winter[3], int summer[3], int autumn[3], 
									int spring[3], int *init)
{
	winter[0] = 20;
	winter[1] = 20;
	winter[2] = 180;
	summer[0] = 200;
	summer[1] = 120;
	summer[2] = 40;
	autumn[0] = 30;
	autumn[1] = 150;
	autumn[2] = 255;
	spring[0] = 200;
	spring[1] = 50;
	spring[2] = 255;
	*init = 1;
}
