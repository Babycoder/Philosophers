/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:50:33 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/14 15:08:45 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utill.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*temp;
	int		i;

	i = 0;
	if (!s || s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	str = (char *)s;
	temp = (char *)malloc(len + 1);
	if (temp == NULL)
		return (NULL);
	while (str[start] != '\0' && len > 0)
	{
		temp[i] = str[start];
		i++;
		start++;
		len--;
	}
	temp[i] = '\0';
	return (temp);
}
