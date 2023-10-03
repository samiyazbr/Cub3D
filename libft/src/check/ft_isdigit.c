/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:31:48 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/19 11:32:48 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* int main()
{
	printf("%d", ft_isdigit(9));
} */