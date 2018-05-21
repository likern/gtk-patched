/*
 * Copyright (C) 2010 Openismus GmbH
 * Copyright (C) 2013 Red Hat, Inc.
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

 *
 * Authors:
 *      Tristan Van Berkom <tristanvb@openismus.com>
 *      Matthias Clasen <mclasen@redhat.com>
 *      William Jon McCann <jmccann@redhat.com>
 */

#ifndef __BREAFFY_FLOW_BOX_H__
#define __BREAFFY_FLOW_BOX_H__

#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gtk/gtkbin.h>

G_BEGIN_DECLS


#define BREAFFY_TYPE_FLOW_BOX                  (breaffy_flow_box_get_type ())
#define BREAFFY_FLOW_BOX(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), BREAFFY_TYPE_FLOW_BOX, BreaffyFlowBox))
#define BREAFFY_FLOW_BOX_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), BREAFFY_TYPE_FLOW_BOX, BreaffyFlowBoxClass))
#define BREAFFY_IS_FLOW_BOX(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BREAFFY_TYPE_FLOW_BOX))
#define BREAFFY_IS_FLOW_BOX_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), BREAFFY_TYPE_FLOW_BOX))
#define BREAFFY_FLOW_BOX_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), BREAFFY_TYPE_FLOW_BOX, BreaffyFlowBoxClass))

typedef struct _BreaffyFlowBox            BreaffyFlowBox;
typedef struct _BreaffyFlowBoxClass       BreaffyFlowBoxClass;

typedef struct _BreaffyFlowBoxChild       BreaffyFlowBoxChild;
typedef struct _BreaffyFlowBoxChildClass  BreaffyFlowBoxChildClass;

struct _BreaffyFlowBox
{
  GtkContainer container;
};

struct _BreaffyFlowBoxClass
{
  GtkContainerClass parent_class;

  void (*child_activated)            (BreaffyFlowBox        *box,
                                      BreaffyFlowBoxChild   *child);
  void (*selected_children_changed)  (BreaffyFlowBox        *box);
  void (*activate_cursor_child)      (BreaffyFlowBox        *box);
  void (*toggle_cursor_child)        (BreaffyFlowBox        *box);
  gboolean (*move_cursor)            (BreaffyFlowBox        *box,
                                      GtkMovementStep    step,
                                      gint               count);
  void (*select_all)                 (BreaffyFlowBox        *box);
  void (*unselect_all)               (BreaffyFlowBox        *box);

  /* Padding for future expansion */
  void (*_gtk_reserved1) (void);
  void (*_gtk_reserved2) (void);
  void (*_gtk_reserved3) (void);
  void (*_gtk_reserved4) (void);
  void (*_gtk_reserved5) (void);
  void (*_gtk_reserved6) (void);
};

#define BREAFFY_TYPE_FLOW_BOX_CHILD            (breaffy_flow_box_child_get_type ())
#define BREAFFY_FLOW_BOX_CHILD(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), BREAFFY_TYPE_FLOW_BOX_CHILD, BreaffyFlowBoxChild))
#define BREAFFY_FLOW_BOX_CHILD_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), BREAFFY_TYPE_FLOW_BOX_CHILD, BreaffyFlowBoxChildClass))
#define BREAFFY_IS_FLOW_BOX_CHILD(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BREAFFY_TYPE_FLOW_BOX_CHILD))
#define BREAFFY_IS_FLOW_BOX_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BREAFFY_TYPE_FLOW_BOX_CHILD))
#define BREAFFY_FLOW_BOX_CHILD_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), EG_TYPE_FLOW_BOX_CHILD, BreaffyFlowBoxChildClass))

struct _BreaffyFlowBoxChild
{
  GtkBin parent_instance;
};

struct _BreaffyFlowBoxChildClass
{
  GtkBinClass parent_class;

  void (* activate) (BreaffyFlowBoxChild *child);

  /* Padding for future expansion */
  void (*_gtk_reserved1) (void);
  void (*_gtk_reserved2) (void);
};

/**
 * BreaffyFlowBoxCreateWidgetFunc:
 * @item: (type GObject): the item from the model for which to create a widget for
 * @user_data: (closure): user data from breaffy_flow_box_bind_model()
 *
 * Called for flow boxes that are bound to a #GListModel with
 * breaffy_flow_box_bind_model() for each item that gets added to the model.
 *
 * Returns: (transfer full): a #GtkWidget that represents @item
 */
typedef GtkWidget * (*BreaffyFlowBoxCreateWidgetFunc) (gpointer item,
                                                   gpointer  user_data);

GDK_AVAILABLE_IN_ALL
GType                 breaffy_flow_box_child_get_type            (void) G_GNUC_CONST;
GDK_AVAILABLE_IN_ALL
GtkWidget*            breaffy_flow_box_child_new                 (void);
GDK_AVAILABLE_IN_ALL
gint                  breaffy_flow_box_child_get_index           (BreaffyFlowBoxChild *child);
GDK_AVAILABLE_IN_ALL
gboolean              breaffy_flow_box_child_is_selected         (BreaffyFlowBoxChild *child);
GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_child_changed             (BreaffyFlowBoxChild *child);


GDK_AVAILABLE_IN_ALL
GType                 breaffy_flow_box_get_type                  (void) G_GNUC_CONST;

GDK_AVAILABLE_IN_ALL
GtkWidget            *breaffy_flow_box_new                       (void);

GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_bind_model                (BreaffyFlowBox                 *box,
                                                              GListModel                 *model,
                                                              BreaffyFlowBoxCreateWidgetFunc  create_widget_func,
                                                              gpointer                    user_data,
                                                              GDestroyNotify              user_data_free_func);

GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_set_homogeneous           (BreaffyFlowBox           *box,
                                                              gboolean              homogeneous);
GDK_AVAILABLE_IN_ALL
gboolean              breaffy_flow_box_get_homogeneous           (BreaffyFlowBox           *box);
GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_set_row_spacing           (BreaffyFlowBox           *box,
                                                              guint                 spacing);
GDK_AVAILABLE_IN_ALL
guint                 breaffy_flow_box_get_row_spacing           (BreaffyFlowBox           *box);

GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_set_column_spacing        (BreaffyFlowBox           *box,
                                                              guint                 spacing);
GDK_AVAILABLE_IN_ALL
guint                 breaffy_flow_box_get_column_spacing        (BreaffyFlowBox           *box);

GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_set_min_children_per_line (BreaffyFlowBox           *box,
                                                              guint                 n_children);
GDK_AVAILABLE_IN_ALL
guint                 breaffy_flow_box_get_min_children_per_line (BreaffyFlowBox           *box);

GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_set_max_children_per_line (BreaffyFlowBox           *box,
                                                              guint                 n_children);
GDK_AVAILABLE_IN_ALL
guint                 breaffy_flow_box_get_max_children_per_line (BreaffyFlowBox           *box);
GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_set_activate_on_single_click (BreaffyFlowBox        *box,
                                                                 gboolean           single);
GDK_AVAILABLE_IN_ALL
gboolean              breaffy_flow_box_get_activate_on_single_click (BreaffyFlowBox        *box);

GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_insert                       (BreaffyFlowBox        *box,
                                                                 GtkWidget         *widget,
                                                                 gint               position);
GDK_AVAILABLE_IN_ALL
BreaffyFlowBoxChild      *breaffy_flow_box_get_child_at_index           (BreaffyFlowBox        *box,
                                                                 gint               idx);

GDK_AVAILABLE_IN_ALL
BreaffyFlowBoxChild      *breaffy_flow_box_get_child_at_pos             (BreaffyFlowBox        *box,
                                                                 gint               x,
                                                                 gint               y);

typedef void (* BreaffyFlowBoxForeachFunc) (BreaffyFlowBox      *box,
                                        BreaffyFlowBoxChild *child,
                                        gpointer         user_data);

GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_selected_foreach             (BreaffyFlowBox        *box,
                                                                 BreaffyFlowBoxForeachFunc func,
                                                                 gpointer           data);
GDK_AVAILABLE_IN_ALL
GList                *breaffy_flow_box_get_selected_children        (BreaffyFlowBox        *box);
GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_select_child                 (BreaffyFlowBox        *box,
                                                                 BreaffyFlowBoxChild   *child);
GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_unselect_child               (BreaffyFlowBox        *box,
                                                                 BreaffyFlowBoxChild   *child);
GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_select_all                   (BreaffyFlowBox        *box);
GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_unselect_all                 (BreaffyFlowBox        *box);
GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_set_selection_mode           (BreaffyFlowBox        *box,
                                                                 GtkSelectionMode   mode);
GDK_AVAILABLE_IN_ALL
GtkSelectionMode      breaffy_flow_box_get_selection_mode           (BreaffyFlowBox        *box);
GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_set_hadjustment              (BreaffyFlowBox        *box,
                                                                 GtkAdjustment     *adjustment);
GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_set_vadjustment              (BreaffyFlowBox        *box,
                                                                 GtkAdjustment     *adjustment);

typedef gboolean (*BreaffyFlowBoxFilterFunc) (BreaffyFlowBoxChild *child,
                                          gpointer         user_data);

GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_set_filter_func              (BreaffyFlowBox        *box,
                                                                 BreaffyFlowBoxFilterFunc filter_func,
                                                                 gpointer             user_data,
                                                                 GDestroyNotify       destroy);
GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_invalidate_filter            (BreaffyFlowBox        *box);

typedef gint (*BreaffyFlowBoxSortFunc) (BreaffyFlowBoxChild *child1,
                                    BreaffyFlowBoxChild *child2,
                                    gpointer         user_data);

GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_set_sort_func                (BreaffyFlowBox        *box,
                                                                 BreaffyFlowBoxSortFunc  sort_func,
                                                                 gpointer            user_data,
                                                                 GDestroyNotify      destroy);
GDK_AVAILABLE_IN_ALL
void                  breaffy_flow_box_invalidate_sort              (BreaffyFlowBox         *box);

G_END_DECLS


#endif /* __BREAFFY_FLOW_BOX_H__ */
