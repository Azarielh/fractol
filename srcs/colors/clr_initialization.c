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
	themes[0] = "theme1";
	themes[1] = "theme2";
	themes[2] = "theme3";
	themes[3] = "theme4";
}

void	init_background(int clr[8])
{
	clr[0] = 0x1a0033;
	clr[1] = 0x330066;
	clr[2] = 0x003d1a;
	clr[3] = 0x004d33;
	clr[4] = 0x4d0033;
	clr[5] = 0x660019;
	clr[6] = 0x1a3300;
	clr[7] = 0x330d00;
}

void init_color_palettes(int theme1[3], int theme2[3], int theme3[3], 
									int theme4[3], int *init)
{
	theme1[0] = 20;
	theme1[1] = 20;
	theme1[2] = 180;
	theme2[0] = 255;
	theme2[1] = 80;
	theme2[2] = 0;
	theme3[0] = 200;
	theme3[1] = 100;
	theme3[2] = 20;
	theme4[0] = 50;
	theme4[1] = 200;
	theme4[2] = 80;
	*init = 1;
}
