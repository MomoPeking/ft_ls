/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:59:46 by qdang             #+#    #+#             */
/*   Updated: 2020/03/10 15:24:56 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(long long nbr)
{
	int		nbrlen;

	nbrlen = 0;
	if ((unsigned long long)nbr == -9223372036854775808U)
		return (19);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		nbrlen++;
		nbr /= 10;
	}
	return (nbrlen);
}
