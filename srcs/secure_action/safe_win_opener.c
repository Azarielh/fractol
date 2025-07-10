/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_win_opener.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:19:37 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/08 17:19:37 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	*safe_win_opener(void *mlx_ptr, int size_x, int size_y, char *title)
{
	void	*win_ptr;

	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, title);
	if (win_ptr == 0)
	{
		exit_error("Failed to open a new window", 2);
		return (win_ptr);
	}
	return (win_ptr);
}