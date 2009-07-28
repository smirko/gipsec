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

static void
start_button_clicked_cb (GtkWidget *button, gpointer user_data)
{
	GIPSec *gipsec = GIPSEC (user_data);
	GtkWidget *widget = NULL;

	if (gipsec->run_mode) {
		// when the in server mode
	} else {
		// when the in client mode
		if (NULL == gipsec->client_window_xml) {
			// This client window isn't initial yet
			gipsec->client_window_xml =
				glade_xml_new (gipsec->glade_file,
						"gipsec_client_window",
						NULL);
		}

		widget = glade_xml_get_widget (gipsec->client_window_xml,
			   	"gipsec_client_window");
		g_return_if_fail (widget != NULL);

		gtk_widget_show_all (widget);
	}
}

static void
stop_button_clicked_cb (GtkWidget *button, gpointer user_data)
{
	GIPSec *gipsec = GIPSEC (user_data);

	if (gipsec->run_mode) {
		// when the in server mode
	} else {
		// when the in client mode
	}
}

static void
config_button_clicked_cb (GtkWidget *button, gpointer user_data)
{
	GIPSec *gipsec = GIPSEC (user_data);

	if (gipsec->run_mode) {
		// when the in server mode
	} else {
		// when the in client mode
	}
}

static void
main_window_quit (GtkWidget *main_window, gpointer user_data)
{
	GMainLoop *loop = NULL;
	
	GIPSec *gipsec = GIPSEC(user_data);

	loop = gipsec->loop;

	if (loop == NULL)
		g_debug("here\n");

	g_main_loop_quit(loop);
	
}

static void
setup_mainwindow (GIPSec *gipsec)
{
	GtkWidget* widget = NULL;

	g_debug ("setup_mainwindow...");

	widget = glade_xml_get_widget (gipsec->main_window_xml, "start_toolbutton");
	g_return_if_fail (widget != NULL);

	g_signal_connect (widget, "clicked",
			G_CALLBACK (start_button_clicked_cb),
			gipsec);

	widget = glade_xml_get_widget (gipsec->main_window_xml, "stop_toolbutton");
	g_return_if_fail (widget != NULL);

	g_signal_connect (widget, "clicked",
			G_CALLBACK (stop_button_clicked_cb),
			gipsec);

	widget = glade_xml_get_widget (gipsec->main_window_xml, "config_toolbutton");
	g_return_if_fail (widget != NULL);

	g_signal_connect (widget, "clicked",
			G_CALLBACK (config_button_clicked_cb),
			gipsec);

	widget = glade_xml_get_widget (gipsec->main_window_xml, "gipsec_main_window");
	g_return_if_fail (widget != NULL);

	g_signal_connect (widget, "delete_event",
			   G_CALLBACK (main_window_quit),
			   gipsec);
}

static GObject *
constructor (GType type,
		guint n_props,
		GObjectConstructParam *construct_props)
{
	GIPSec *gipsec = NULL;

	g_debug ("constructor...");

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

		setup_mainwindow (gipsec);
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
	g_debug ("gipsec_init...");

	g_return_if_fail (gipsec != NULL);

	if (is_server_mode ())
		gipsec->run_mode = 1;
	else
		gipsec->run_mode = 0;
}

static void
gipsec_class_init (GIPSecClass *gipsec_class)
{
	GObjectClass *object_class = G_OBJECT_CLASS (gipsec_class);

	g_debug ("gipsec_class_init...");

	object_class->constructor = constructor;

	/* Virtual methods */
	object_class->finalize = finalize;
}

GIPSec *
gipsec_new ()
{
	return g_object_new (GIPSEC_TYPE, NULL);
}
