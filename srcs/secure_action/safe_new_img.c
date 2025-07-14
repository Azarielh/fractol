/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_new_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:38:43 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/14 14:51:06 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*safe_new_img(t_fractol *f)
{
	void	*new_img_ptr;

	new_img_ptr = mlx_new_image(f->mlx_ptr, f->width, f->height);
	if (new_img_ptr == 0)
		exit_n_free("Failed to build a new image", f, 3);
	return (new_img_ptr);
}
