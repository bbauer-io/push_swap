/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:17:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/04 16:50:12 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <stdio.h>

int		main(void)
{
	int ret;
	setlocale(LC_ALL, "");
/*
	ft_printf("ft_printf:\n");
	ret = ft_printf("%S", L"米");
	ft_printf("\n%d\n", ret);
	ret = ft_printf("%S", L"Á±≥");
	ft_printf("\n%d\n", ret);
	ret = ft_printf("%S", L"我是一只猫。");
	ft_printf("\n%d\n", ret);
	ret = ft_printf("a%Sb%sc%S", L"我", "42", L"猫");
	ft_printf("\n%d\n", ret);
	ret = ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
			L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	ft_printf("\n%d\n", ret);

	printf("PRINTF:\n");
	ret = printf("%S", L"米");
	printf("\n%d\n", ret);
	ret = printf("%S", L"Á±≥");
	printf("\n%d\n", ret);
	ret = printf("%S", L"我是一只猫。");
	printf("\n%d\n", ret);
	ret = printf("a%Sb%sc%S", L"我", "42", L"猫");
	printf("\n%d\n", ret);
	ret = printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
			L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	ft_printf("\n%d\n", ret);
*/
	ft_printf("FT_PRINTF:\n");
	ret = ft_printf("%.4S", L"我是一只猫。");
	ft_printf("\n%d\n", ret);
	ret = ft_printf("%15.4S", L"我是一只猫。");
	ft_printf("\n%d\n", ret);
	ret = ft_printf("%4.15S", L"我是一只猫。");
	ft_printf("\n%d\n", ret);
	ret = ft_printf("{%30S}", L"我是一只猫。");
	ft_printf("\n%d\n", ret);

	printf("PRINTF:\n");
	ret = printf("%.4S", L"我是一只猫。");
	printf("\n%d\n", ret);
	ret = printf("%15.4S", L"我是一只猫。");
	printf("\n%d\n", ret);
	ret = printf("%4.15S", L"我是一只猫。");
	printf("\n%d\n", ret);
	ret = printf("{%30S}", L"我是一只猫。");
	printf("\n%d\n", ret);
	return (0);
}
