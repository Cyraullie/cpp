/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:16:39 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/23 15:27:24 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// a.x * (b.y-c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)

Fixed area_calc(Point const a, Point const b, Point const c)
{
	Fixed res;

	res = a.getX() * (b.getY()-c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY());
	if (res < 0)
		res = res * -1;
	res = res / 2;
	std::cout << "area : " << res << std::endl;
	return (res);
	
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed area_abc(area_calc(a, b, c));
	
	Fixed area_pab(area_calc(point, a, b));
	Fixed area_pbc(area_calc(point, b, c));
	Fixed area_pac(area_calc(point, a, c));
	if ((area_pab + area_pbc + area_pac) == area_abc)
		return (true);
	return (false);
}