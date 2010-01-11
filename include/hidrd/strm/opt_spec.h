/** @file
 * @brief HID report descriptor - option specification
 *
 * Copyright (C) 2010 Nikolai Kondrashov
 *
 * This file is part of hidrd.
 *
 * Hidrd is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Hidrd is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with hidrd; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * @author Nikolai Kondrashov <spbnick@gmail.com>
 *
 * @(#) $Id$
 */

#ifndef __HIDRD_STRM_OPT_SPEC_H__
#define __HIDRD_STRM_OPT_SPEC_H__

#include "hidrd/strm/opt.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Option specification */
typedef struct hidrd_strm_opt_spec {
    const char             *name;   /**< Name */
    hidrd_strm_opt_type     type;   /**< Value type */
    bool                    req;    /**< "Required" flag */
    hidrd_strm_opt_value    dflt;   /**< Default value */
    const char             *desc;   /**< Human-readable description */
} hidrd_strm_opt_spec;

/**
 * Check if an option specification is valid.
 *
 * @param spec  Option specification to check.
 *
 * @return True if the option specification is valid, false otherwise.
 */
extern bool hidrd_strm_opt_spec_valid(const hidrd_strm_opt_spec *spec);

/**
 * Parse a string option as an option specification, modifying the option
 * value and referencing strings from it.
 *
 * @param spec  Location for output option specification.
 * @param opt   Option to be parsed, modified and referenced in the
 *              resulting option specification.
 *
 * @return True if parsed successfully, false otherwise.
 *
 * @note Option value format is the following:
 *       TYPE ['?' DEFAULT_VALUE] ['\'' DESCRIPTION]
 *       TYPE is a hidrd_strm_opt_type value. DEFAULT_VALUE is a string
 *       representation of the value. If there is no DEFAULT_VALUE part, the
 *       option is considered mandatory.
 */
extern bool hidrd_strm_opt_spec_parse_opt(hidrd_strm_opt_spec  *spec,
                                          const hidrd_strm_opt *opt);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __HIDRD_STRM_OPT_SPEC_H__ */


