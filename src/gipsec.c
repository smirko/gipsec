/*
 * gipsec.c
 * This file is part of gipsec, implement gipsec instance.
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
#include <glib/gi18n.h>
#include "gipsec.h"
#include "gipsec-options.h"

G_DEFINE_TYPE(GIPSec, gipsec, G_TYPE_OBJECT)

static GObject *
constructor (GType type,
		guint n_props,
		GObjectConstructParam *construct_props)
{
	GIPSec *gipsec = NULL;

	gipsec = GIPSEC (G_OBJECT_CLASS (gipsec_parent_class)->constructor (type, n_props, construct_props));

	g_set_application_name (_("GIPSec monitor window"));

	gipsec->glade_file = g_build_filename (GLADEDIR, "gipsec.glade", NULL);
	if (!gipsec->glade_file ||
		   	!g_file_test (gipsec->glade_file, G_FILE_TEST_IS_REGULAR)) {
		g_warning (_("The GIPSec could not find the glade file."));
		goto error;
	}

	if (is_dialog_window()) {
		gipsec->config_window_xml =
			glade_xml_new (gipsec->glade_file, "gipsec_config_window", NULL);
	} else {
		gipsec->main_window_xml =
			glade_xml_new (gipsec->glade_file, "gipsec_main_window", NULL);
	}

	return G_OBJECT (gipsec);

error:
	g_object_unref (gipsec);

	return NULL;
}

static void
finalize (GObject *object)
{
	GIPSec *gipsec = GIPSEC (object);

	g_free (gipsec->glade_file);

	if (gipsec->main_window_xml)
		g_object_unref (gipsec->main_window_xml);

	G_OBJECT_CLASS (gipsec_parent_class)->finalize (object);
}

static void
gipsec_init (GIPSec *gipsec)
{
}

static void
gipsec_class_init (GIPSecClass *gipsec_class)
{
	GObjectClass *object_class = G_OBJECT_CLASS (gipsec_class);

	object_class->constructor = constructor;

	/* Virtual methods */
	object_class->finalize = finalize;
}

GIPSec *
gipsec_new ()
{
	return g_object_new (GIPSEC_TYPE, NULL);
}
