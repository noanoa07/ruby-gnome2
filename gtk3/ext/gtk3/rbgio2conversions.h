/* -*- c-file-style: "ruby"; indent-tabs-mode: nil -*- */
/*
 *  Copyright (C) 2014  Ruby-GNOME2 Project Team
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *  MA  02110-1301  USA
 */

#ifndef __RBGIO2CONVERSIONS_H__
#define __RBGIO2CONVERSIONS_H__

#define RVAL2GFILE(o)                      (G_FILE(RVAL2GOBJ(o)))
#define RVAL2GICON(o)                      (G_ICON(RVAL2GOBJ(o)))
#define RVAL2GPERMISSION(o)                (G_PERMISSION(RVAL2GOBJ(o)))
#define RVAL2GAPPLICATIONFLAGS(o)          (RVAL2GFLAGS(o, G_TYPE_APPLICATION_FLAGS))

#endif /* __RBGIO2CONVERSIONS_H__ */