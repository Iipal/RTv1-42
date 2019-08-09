/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_isr_flags.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:03:38 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/08 23:12:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_ISR_FLAGS_H
# define RTV1_ISR_FLAGS_H

# include <stdint.h>

extern uint32_t g_isr_flags;

# define ISR_UP               (1U << 0U)
# define ISR_DOWN             (1U << 1U)
# define ISR_LEFT             (1U << 2U)
# define ISR_RIGHT            (1U << 3U)
# define ISR_ZINC             (1U << 4U)
# define ISR_ZDEC             (1U << 5U)
# define ISR_ROT_X            (1U << 6U)
# define ISR_ROT_Y            (1U << 7U)
# define ISR_ROT_Z            (1U << 8U)
# define ISR_DEC_ROT_X        (1U << 9U)
# define ISR_DEC_ROT_Y        (1U << 10U)
# define ISR_DEC_ROT_Z        (1U << 11U)
# define ISR_RENDER_FPS       (1U << 12U)
# define ISR_SPEEDUP          (1U << 13U)
# define ISR_SPEEDDOWN        (1U << 14U)
# define ISR_LIGHT_DEBUG      (1U << 15U)
# define ISR_OBJS_DEBUG       (1U << 16U)
# define ISR_DBG_Z_OR_INTENSE (1U << 17U)
# define ISR_INC_AL           (1U << 18U)
# define ISR_DEC_AL           (1U << 19U)

#endif
