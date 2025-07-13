/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:58:56 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/08 15:58:56 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*safe_init()
{
	void	*init;

	init = mlx_init();
	if (init == 0)
	{
		exit_error("mlx_init failed", 1);
		return (init);
	}
	return (init);
}
