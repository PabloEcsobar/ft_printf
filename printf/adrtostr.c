/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adrtostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:55:45 by polenyc           #+#    #+#             */
/*   Updated: 2023/12/10 18:22:34 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdlib.h>
#include <stdint.h>

char	*addhexpre(const char *hex, char *str)
{
	return (strjoinfree((char *)hex, str, 1));
}

t_data	*addr_tostr(void *p, const char *spec, const char *base)
{
	const char	*tmp;
	t_data		*num;

	tmp = spec;
	++tmp;
	if (!(uintptr_t)p)
		return (t_datacrt(ft_strdup("(nil)"), 0));
	num = t_datacrt(uint_tostr_base((uintptr_t)p, base), 0);
	if (!num)
		return (NULL);
	num->str = addhexpre(PRE_HEX_S, num->str);
	return (num);
}
