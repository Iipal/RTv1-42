/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bits_macroses.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:36:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/06 08:38:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BITS_MACROSES_H
# define LIBFT_BITS_MACROSES_H

# define TO_N_BIT(n) (1 << (n))

# define SET_BIT(mask, bit) ((mask) |= (bit))
# define TOGGLE_BIT(mask, bit) ((mask) ^= (bit))
# define UNSET_BIT(mask, bit) ((mask) &= ~(bit))

# define IS_BIT(mask, bit) (((mask) & (bit)) == (bit))

#endif
