/*
 * Copyright (C) 2010 Openismus GmbH
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>
#include <glib-object.h>
#include <gmodule.h>

enum {
  SIMPLE_ITEMS = 0,
  FOCUS_ITEMS,
  WRAPPY_ITEMS,
  IMAGE_ITEMS,
  BUTTON_ITEMS
};

#define INITIAL_HALIGN          GTK_ALIGN_FILL
#define INITIAL_VALIGN          GTK_ALIGN_START
#define INITIAL_MINIMUM_LENGTH  3
#define INITIAL_MAXIMUM_LENGTH  6
#define INITIAL_CSPACING        2
#define INITIAL_RSPACING        2
#define N_ITEMS 10

static GtkFlowBox    *the_flowbox       = NULL;
static gint           items_type       = SIMPLE_ITEMS;

static void setup_name_property_for_flowbox(GtkWidget *widget)
{
  GValue* value = g_new0(GValue, 1);
  g_value_init (value, G_TYPE_STRING);
  g_value_set_static_string(value, "flowbox");


  g_object_set_property(widget, "name", value);
}

static void setup_name_property_for_flowbox_child(GtkWidget *widget, long number)
{
  GString* gstring = g_string_new("flowbox-child-");
  g_string_append_printf(gstring, "%ld", number);
  char *property_value = g_string_free(gstring, FALSE);


  GValue* value = g_new0 (GValue, 1);
  g_value_init (value, G_TYPE_STRING);
  g_value_take_string(value, property_value);

  g_object_set_property(widget, "name", value);
}

static void
populate_window (GtkWidget *container)
{

//  g_object = (GObject *) flowbox;
//  setup_name_property_for_flowbox(container);

  GtkWidget *widget, *frame;
  gint i;

  for (i = 0; i < N_ITEMS; i++)
    {
      gchar *text = g_strdup_printf ("Item %02d", i);

      widget = gtk_label_new (text);
//      setup_name_property_for_flowbox_child(widget, i);
      gtk_widget_show (widget);
//      g_object_set_data_full (G_OBJECT (frame), "id", (gpointer)g_strdup (text), g_free);
      gtk_container_add (GTK_CONTAINER (container), widget);
      g_free (text);
    }
}

static GtkWidget *
create_window (void)
{
  GtkWidget *window, *hbox, *vbox, *flowbox_cntl, *items_cntl;
  GtkWidget *widget, *expander, *swindow;

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
//  hbox   = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 6);
//  vbox   = gtk_box_new (GTK_ORIENTATION_VERTICAL, 6);

//  gtk_widget_show (vbox);
//  gtk_widget_show (hbox);
//  gtk_container_add (GTK_CONTAINER (window), hbox);
//  gtk_box_pack_start (GTK_BOX (hbox), vbox);

  swindow = gtk_scrolled_window_new (NULL, NULL);
  gtk_container_add (GTK_CONTAINER (window), swindow);
  gtk_widget_show (swindow);
//  gtk_widget_set_hexpand (swindow, TRUE);
//  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (swindow),
//                                  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

//  gtk_widget_show (swindow);
//  gtk_box_pack_start (GTK_BOX (hbox), swindow);

  GtkWidget* box_container = gtk_box_new (GTK_ORIENTATION_VERTICAL, 6);
  gtk_container_add (GTK_CONTAINER (swindow), box_container);
  populate_window(box_container);

  /* This line was added only for the convenience of reproducing
   * a height-for-width inside GtkScrolledWindow bug (bug 629778).
   *   -Tristan
   */
  gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);
  return window;
}

int
main (int argc, char *argv[])
{
  GtkWidget *window;

  gtk_init ();

  window = create_window ();

  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  gtk_widget_show (window);

  gtk_main ();

  return 0;
}
