/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:34:11 by qdang             #+#    #+#             */
/*   Updated: 2019/12/31 16:02:24 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dtoi(double nb)
{
	if (nb > 0)
		if (nb - (int)nb >= 0.5)
			return ((int)nb + 1);
	if (nb < 0)
		if ((int)nb - nb >= 0.5)
			return ((int)nb - 1);
	return ((int)nb);
}
