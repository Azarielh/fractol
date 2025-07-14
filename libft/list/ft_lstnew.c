/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:55:38 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/12/04 22:04:04 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ls	*ft_lstnew(void *content)
{
	t_ls	*new_item;

	new_item = (t_ls *)malloc(sizeof(t_ls));
	if (!new_item)
		return (NULL);
	new_item->content = content;
	new_item->next = NULL;
	return (new_item);
}
