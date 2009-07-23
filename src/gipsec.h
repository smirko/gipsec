/*
 * gipsec.h
 * This file is part of gipsec, define the gipsec data structure
 * 
 * Copyright (C) 2005 Novell, Inc
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, 
 * Boston, MA 02111-1307, USA.
 *
 * Authors: Bin Li <libin.charles@gmail.com>
 *
 * See ChangeLog to get more details.
 * $Id$
 */
#ifndef GIPSEC_H
#define GIPSEC_H

#include <glade/glade.h>
#include <glib/gtypes.h>
#include <glib-object.h>

#define GIPSEC_TYPE                (gipsec_get_type ())
#define GIPSEC(obj)                (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIPSEC_TYPE, GIPSec))
#define GIPSEC_CLASS(klass)        (G_TYPE_CHECK_CLASS_CAST ((klass), GIPSEC_TYPE, GIPSecClass))
#define IS_GIPSEC(obj)             (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIPSEC_TYPE))
#define IS_GIPSEC_CLASS(klass)     (G_TYPE_CHECK_CLASS_TYPE ((obj), GIPSEC_TYPE))
#define GIPSEC_GET_CLASS(obj)      (G_TYPE_INSTANCE_GET_CLASS ((obj), GIPSEC_TYPE, GIPSecClass))

typedef struct
{
	GObject parent_instance;

	char* glade_file;

	GladeXML* main_window_xml;
	GladeXML* config_window_xml;

} GIPSec;

typedef struct
{
	GObjectClass parent;
} GIPSecClass;

GType gipsec_get_type (void);
GIPSec *gipsec_new ();

#endif /* GIPSEC_H */
