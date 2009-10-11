dnl Copyright (c) 2009  Fabien Parent <parent.f@gmail.com>
dnl This file is part of gdlmm.

_CONVERSION(`GdlDockObject*', `DockObject*', Glib::wrap($3))
_CONVERSION(`DockObject&', `GdlDockObject*', $3.gobj())
_CONVERSION(`DockItem&', `GdlDockItem*', $3.gobj())
_CONVERSION(`Gtk::Requisition*', `GtkRequisition*', $3)
_CONVERSION(`const DockObject&', `GdlDockObject*', $3.gobj())
_CONVERSION(`GdlDockObject*', `DockObject&', `*Glib::wrap($3)')

_CONVERSION(`GList*',`Glib::ListHandle<Glib::ustring>',__FL2H_SHALLOW)
_CONVERSION(`GList*',`Glib::ListHandle<DockItem*>',__FL2H_SHALLOW)

_CONVERSION(`const Glib::RefPtr<DockMaster>&',`GdlDockMaster*',__CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<DockMaster>&',`GObject*', G_OBJECT($3->gobj()))

dnl _CONVERSION(`GValue*', `const Glib::ValueBase*', Glib::wrap($3))
dnl _CONVERSION(`const Glib::ValueBase*', `GValue*', const_cast<GValue*>($3->gobj()))

_CONVERSION(`const Glib::ustring', `const gchar*', $3.c_str())

_CONVERSION(`GdlDockItem*', `DockItem*', Glib::wrap($3))
_CONVERSION(`GdlDockPlaceholder*', `DockPlaceholder*', Glib::wrap($3))
_CONVERSION(`GdlDock*', `Dock*', Glib::wrap($3))

_CONVERSION(`Dock&', `GdlDock*', $3.gobj())
_CONVERSION(`DockPlacement', `GdlDockPlacement*', (GdlDockPlacement*) &$3)

_CONV_ENUM(Gdl, DockPlacement)
_CONV_ENUM(Gdl, DockObjectFlags)
_CONV_ENUM(Gdl, DockParamFlags)

_CONV_ENUM(Gdl, DockItemBehavior)
_CONV_ENUM(Gdl, DockItemFlags)

_CONV_ENUM(Gdl, SwitcherStyle)

_CONV_ENUM(Gdl, DockBarStyle)
