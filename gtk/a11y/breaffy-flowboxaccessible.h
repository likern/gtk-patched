/*
 * Copyright (C) 2013 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __BREAFFY_FLOW_BOX_ACCESSIBLE_H__
#define __BREAFFY_FLOW_BOX_ACCESSIBLE_H__

#if !defined (__GTK_A11Y_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk-a11y.h> can be included directly."
#endif

#include <gtk/a11y/gtkcontaineraccessible.h>

G_BEGIN_DECLS

#define BREAFFY_TYPE_FLOW_BOX_ACCESSIBLE                   (breaffy_flow_box_accessible_get_type ())
#define BREAFFY_FLOW_BOX_ACCESSIBLE(obj)                   (G_TYPE_CHECK_INSTANCE_CAST ((obj), BREAFFY_TYPE_FLOW_BOX_ACCESSIBLE, BreaffyFlowBoxAccessible))
#define BREAFFY_FLOW_BOX_ACCESSIBLE_CLASS(klass)           (G_TYPE_CHECK_CLASS_CAST ((klass), BREAFFY_TYPE_FLOW_BOX_ACCESSIBLE, BreaffyFlowBoxAccessibleClass))
#define BREAFFY_IS_FLOW_BOX_ACCESSIBLE(obj)                (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BREAFFY_TYPE_FLOW_BOX_ACCESSIBLE))
#define BREAFFY_IS_FLOW_BOX_ACCESSIBLE_CLASS(klass)        (G_TYPE_CHECK_CLASS_TYPE ((klass), BREAFFY_TYPE_FLOW_BOX_ACCESSIBLE))
#define BREAFFY_FLOW_BOX_ACCESSIBLE_GET_CLASS(obj)         (G_TYPE_INSTANCE_GET_CLASS ((obj), BREAFFY_TYPE_FLOW_BOX_ACCESSIBLE, BreaffyFlowBoxAccessibleClass))

typedef struct _BreaffyFlowBoxAccessible        BreaffyFlowBoxAccessible;
typedef struct _BreaffyFlowBoxAccessibleClass   BreaffyFlowBoxAccessibleClass;
typedef struct _BreaffyFlowBoxAccessiblePrivate BreaffyFlowBoxAccessiblePrivate;

struct _BreaffyFlowBoxAccessible
{
  GtkContainerAccessible parent;

  BreaffyFlowBoxAccessiblePrivate *priv;
};

struct _BreaffyFlowBoxAccessibleClass
{
  GtkContainerAccessibleClass parent_class;
};

GDK_AVAILABLE_IN_ALL
GType breaffy_flow_box_accessible_get_type (void);

G_END_DECLS

#endif /* __BREAFFY_FLOW_BOX_ACCESSIBLE_H__ */
