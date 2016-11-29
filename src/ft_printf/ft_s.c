/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:08:23 by vdarmaya          #+#    #+#             */
/*   Updated: 2016/11/29 18:22:41 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		is_normal(char *str, t_printf *elem)
{
	int count;
	int size;

	count = 0;
	if (elem->flag_minus)
		ft_putstrwp(str, elem->precision);
	if ((elem->precision != -1) && (size_t)elem->precision < ft_strlen(str))
		size = elem->precision;
	else
		size = ft_strlen(str);
	count += size;
	while (elem->width-- > size)
	{
		ft_putchar(' ');
		count++;
	}
	if (!elem->flag_minus)
		ft_putstrwp(str, elem->precision);
	return (count);
}

int		is_null(t_printf *elem)
{
	int	size;

	size = 0;
	if (elem->flag_minus)
		ft_putstrwp("(null)", elem->precision);
	if (elem->width > 6 || (elem->width > elem->precision && elem->precision != -1))
	{
		size += elem->width;
		if ((elem->precision != -1) && elem->precision < 6)
			size += 6 - elem->precision;
		while (size-- > 6)
			ft_putchar(' ');
	}
	if (!elem->flag_minus)
		ft_putstrwp("(null)", elem->precision);
	if (elem->width > 6 || (elem->width > elem->precision && elem->precision != -1))
		return (elem->width);
	if ((elem->precision != -1) && (elem->precision < 6))
		return (elem->precision);
	return (6);
}

int		ft_s(char *str, t_printf *elem)
{
	int		count;

	count = 0;
	if (!str)
		return (is_null(elem));
	else if ((size_t)elem->width > ft_strlen(str) ||
			(elem->width > elem->precision))
		count = is_normal(str, elem);
	else
	{
		ft_putstrwp(str, elem->precision);
		if ((elem->precision != -1) && (size_t)elem->precision < ft_strlen(str))
			count += elem->precision;
		else
			count += ft_strlen(str);
	}
	return (count);
}
