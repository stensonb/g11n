/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */
/* $XConsortium: XlcGeneric.h,v 1.5 94/03/29 22:51:13 rws Exp $ */
/*
 * Copyright (C) 1994 X Consortium
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNEC-
 * TION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of the X Consortium shall not
 * be used in advertising or otherwise to promote the sale, use or other deal-
 * ings in this Software without prior written authorization from the X Consor-
 * tium.
 *
 * X Window System is a trademark of X Consortium, Inc.
 */
/*
 * Copyright 1992, 1993 by TOSHIBA Corp.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of TOSHIBA not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission. TOSHIBA make no representations about the
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * TOSHIBA DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
 * ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
 * TOSHIBA BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
 * ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 *
 * Author: Katsuhisa Yano	TOSHIBA Corp.
 *			   	mopi@osa.ilab.toshiba.co.jp
 */

#ifndef _XLCGENERIC_H_
#define _XLCGENERIC_H_

#include "XlcPubI.h"

extern Bool _XInitGenericOM(
#if NeedFunctionPrototypes
    XLCd		/* lcd */
#endif
);

extern Bool _XInitGenericIM(
#if NeedFunctionPrototypes
    XLCd		/* lcd */
#endif
);

typedef struct _ParseInfoRec *ParseInfo;

typedef struct _CodeSetRec {
    XlcCharSet *charset_list;
    int num_charsets;
    int cs_num;
    XlcSide side;
    int length;
    ParseInfo parse_info;
    unsigned long wc_encoding;
} CodeSetRec, *CodeSet;

typedef enum {
    E_GL,			/* GL encoding */
    E_GR,			/* GR encoding */
    E_SS,			/* single shift */
    E_LSL,			/* locking shift left */
    E_LSR,			/* locking shift right */
    E_LAST
} EncodingType;

typedef struct _ParseInfoRec {
    EncodingType type;
    char *encoding;
    CodeSet codeset;
} ParseInfoRec;

/*
 * XLCd private data
 */

#define XLC_GENERIC(lcd, x)	(((XLCdGeneric) lcd->core)->gen.x)
#define XLC_GENERIC_PART(lcd)	(&(((XLCdGeneric) lcd->core)->gen))

typedef struct _XLCdGenericPart {
    int codeset_num;
    CodeSet *codeset_list;
    unsigned char *mb_parse_table;
    int mb_parse_list_num;
    ParseInfo *mb_parse_list;
    unsigned long wc_encode_mask;
    unsigned long wc_shift_bits;
    CodeSet initial_state_GL;
    CodeSet initial_state_GR;
#ifndef X_NOT_STDC_ENV
    Bool use_stdc_env;
    Bool force_convert_to_mb;
#endif
} XLCdGenericPart;

typedef struct _XLCdGenericRec {
    XLCdCoreRec core;	
    XLCdPublicPart pub;
    XLCdGenericPart gen;	
} XLCdGenericRec, *XLCdGeneric;

extern XLCdMethods _XlcGenericMethods;

#endif  /* _XLCGENERIC_H_ */