/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:53:54 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:32:44 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/* int main()
{
	printf("%d", ft_isascii('\n'));
} */