/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 09:55:48 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/14 15:03:54 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utill.h"

int	ft_isalpha(int x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
	{
		return (1);
	}
	return (0);
}