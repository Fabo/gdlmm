// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GDLMM_DOCKBAR_H
#define _GDLMM_DOCKBAR_H


#include <glibmm.h>

/* Copyright (c) 2009  Fabien Parent <parent.f@gmail.com>
 *
 * This file is part of gdlmm.
 *
 * gdlmm is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 2.1 of the License,
 * or (at your option) any later version.
 *
 * gdlmm is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <gtkmm/box.h>
#include "dock.h"
#include "dockmaster.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GdlDockBar GdlDockBar;
typedef struct _GdlDockBarClass GdlDockBarClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdl
{ class DockBar_Class; } // namespace Gdl
namespace Gdl
{


/** @addtogroup gdlmmEnums Enums and Flags */

/**
 * @ingroup gdlmmEnums
 */
enum DockBarStyle
{
  DOCK_BAR_ICONS,
  DOCK_BAR_TEXT,
  DOCK_BAR_BOTH,
  DOCK_BAR_AUTO
};


class DockBar : public Gtk::Box
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef DockBar CppObjectType;
  typedef DockBar_Class CppClassType;
  typedef GdlDockBar BaseObjectType;
  typedef GdlDockBarClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~DockBar();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class DockBar_Class;
  static CppClassType dockbar_class_;

  // noncopyable
  DockBar(const DockBar&);
  DockBar& operator=(const DockBar&);

protected:
  explicit DockBar(const Glib::ConstructParams& construct_params);
  explicit DockBar(GdlDockBar* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GdlDockBar*       gobj()       { return reinterpret_cast<GdlDockBar*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GdlDockBar* gobj() const { return reinterpret_cast<GdlDockBar*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

protected:
  //GTK+ Virtual Functions (override these to change behaviour):
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

  //Default Signal Handlers::
#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


private:


public:
  DockBar(Dock& dock);
  
  
  Gtk::Orientation get_orientation() const;
  
  
  void set_orientation(Gtk::Orientation orientation);
  
  
  void set_style(DockBarStyle style);
  
  
  DockBarStyle get_style() const;
  
  
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Style de barre d'objet détachable sur laquelle afficher les éléments.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<DockBarStyle> property_dockbar_style() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Style de barre d'objet détachable sur laquelle afficher les éléments.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<DockBarStyle> property_dockbar_style() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Objet GdlDockMaster auquel le composant graphique de barre détachable est lié.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< Glib::RefPtr<DockMaster> > property_master() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Objet GdlDockMaster auquel le composant graphique de barre détachable est lié.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<DockMaster> > property_master() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


};

} // namespace Gdl


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdl::DockBar
   */
  Gdl::DockBar* wrap(GdlDockBar* object, bool take_copy = false);
} //namespace Glib


#endif /* _GDLMM_DOCKBAR_H */

