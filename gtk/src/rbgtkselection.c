/* -*- c-file-style: "ruby"; indent-tabs-mode: nil -*- */
/************************************************

  rbgtkselection.c -

  $Author: mutoh $
  $Date: 2003/05/24 11:32:12 $

  Copyright (C) 2002,2003 Masao Mutoh

  This file is devided from rbgtkwidget.c.
  rbgtkwidget.c -
  Copyright (C) 1998-2000 Yukihiro Matsumoto,
                          Daisuke Kanda,
                          Hiroshi Igarashi
************************************************/
#include "global.h"

#define RVAL2WIDGET(w) (GTK_WIDGET(RVAL2GOBJ(w)))

static VALUE
gtkdrag_selection_owner_set(self, widget, selection, time)
    VALUE self, widget, selection, time;
{
    int ret = gtk_selection_owner_set(RVAL2WIDGET(widget), 
                                      RVAL2ATOM(selection), NUM2INT(time));
    return ret ? Qtrue : Qfalse;
}

static VALUE
gtkdrag_selection_add_target(self, widget, selection, target, info)
    VALUE self, widget, selection, target, info;
{
    gtk_selection_add_target(RVAL2WIDGET(widget), RVAL2ATOM(selection),
                             RVAL2ATOM(target), NUM2INT(info));
    return self;
}

static VALUE
gtkdrag_selection_add_targets(self, widget, selection, targets)
    VALUE self, widget, selection, targets;
{
    gtk_selection_add_targets(RVAL2WIDGET(widget), 
                              RVAL2ATOM(selection),
                              rbgtk_get_target_entry(targets), RARRAY(targets)->len);
    return self;
}

static VALUE
gtkdrag_selection_clear_targets(self, widget, selection)
    VALUE self, widget, selection;
{
    gtk_selection_clear_targets(RVAL2WIDGET(widget), RVAL2ATOM(selection));
    return self;
}

static VALUE
gtkdrag_selection_convert(self, widget, selection, target, time)
    VALUE self, widget, selection, target, time;
{
    gboolean ret = gtk_selection_convert(RVAL2WIDGET(widget), 
                                         RVAL2ATOM(selection), RVAL2ATOM(target),
                                         NUM2INT(time));
    return ret ? Qtrue : Qfalse;
}

static VALUE
gtkdrag_selection_remove_all(self, widget)
    VALUE self, widget;
{
    gtk_selection_remove_all(RVAL2WIDGET(widget));
    return self;
}

void
Init_gtk_selection()
{
    VALUE mSelection =  rb_define_module_under(mGtk, "Selection");

    rb_define_module_function(mSelection, "owner_set", gtkdrag_selection_owner_set, 3);
    rb_define_module_function (mSelection, "add_target", gtkdrag_selection_add_target, 4);
    rb_define_module_function(mSelection, "add_targets", gtkdrag_selection_add_targets, 3);
    rb_define_module_function(mSelection, "clear_targets", gtkdrag_selection_clear_targets, 2);
    rb_define_module_function(mSelection, "convert", gtkdrag_selection_convert, 4);
    rb_define_module_function(mSelection, "remove_all", gtkdrag_selection_remove_all, 1);
}
