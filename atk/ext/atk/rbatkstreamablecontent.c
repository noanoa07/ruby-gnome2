/* -*- c-file-style: "ruby"; indent-tabs-mode: nil -*- */
/*
 *  Copyright (C) 2011  Ruby-GNOME2 Project Team
 *  Copyright (C) 2003  Masao Mutoh
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

#include "rbatkprivate.h"

#define RG_TARGET_NAMESPACE mStreamableContent
#define _SELF(s) (ATK_STREAMABLE_CONTENT(RVAL2GOBJ(s)))

static VALUE
rbatkst_get_n_mime_types(VALUE self)
{
    return INT2NUM(atk_streamable_content_get_n_mime_types(_SELF(self)));
}

static VALUE
rbatkst_get_mime_type(VALUE self, VALUE i)
{
    return CSTR2RVAL(atk_streamable_content_get_mime_type(_SELF(self), NUM2INT(i)));
}

static VALUE
rbatkst_get_stream(VALUE self, VALUE mime_type)
{
    GIOChannel* io = atk_streamable_content_get_stream(_SELF(self), RVAL2CSTR(mime_type));
    if (!io)
        rb_raise(rb_eRuntimeError, "Couldn't get the stream.");

    return BOXED2RVAL(io, G_TYPE_IO_CHANNEL);
}


void
Init_atk_streamable_content(void)
{
    VALUE RG_TARGET_NAMESPACE = G_DEF_INTERFACE(ATK_TYPE_STREAMABLE_CONTENT, "StreamableContent", mAtk);

    rb_define_method(RG_TARGET_NAMESPACE, "n_mime_types", rbatkst_get_n_mime_types, 0);
    rb_define_method(RG_TARGET_NAMESPACE, "mime_type", rbatkst_get_mime_type, 1);
    rb_define_method(RG_TARGET_NAMESPACE, "get_stream", rbatkst_get_stream, 1);
}
