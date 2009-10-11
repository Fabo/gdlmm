// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GDLMM_DOCKOBJECT_H
#define _GDLMM_DOCKOBJECT_H

#include <gdlmmconfig.h>


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


#include <gtkmm/container.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GdlDockObject GdlDockObject;
typedef struct _GdlDockObjectClass GdlDockObjectClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdl
{ class DockObject_Class; } // namespace Gdl
namespace Gdl
{


class DockMaster;

//gtkmmproc error: GdlDockParamFlags : unknown _WRAP_ENUM() flag
/** @addtogroup gdlmmEnums Enums and Flags */

/**
 * @ingroup gdlmmEnums
 * @par Bitwise operators:
 * <tt>%DockObjectFlags operator|(DockObjectFlags, DockObjectFlags)</tt><br>
 * <tt>%DockObjectFlags operator&(DockObjectFlags, DockObjectFlags)</tt><br>
 * <tt>%DockObjectFlags operator^(DockObjectFlags, DockObjectFlags)</tt><br>
 * <tt>%DockObjectFlags operator~(DockObjectFlags)</tt><br>
 * <tt>%DockObjectFlags& operator|=(DockObjectFlags&, DockObjectFlags)</tt><br>
 * <tt>%DockObjectFlags& operator&=(DockObjectFlags&, DockObjectFlags)</tt><br>
 * <tt>%DockObjectFlags& operator^=(DockObjectFlags&, DockObjectFlags)</tt><br>
 */
enum DockObjectFlags
{
  DOCK_AUTOMATIC = 1 << 0,
  DOCK_ATTACHED = 1 << 1,
  DOCK_IN_REFLOW = 1 << 2,
  DOCK_IN_DETACH = 1 << 3
};

/** @ingroup gdlmmEnums */
inline DockObjectFlags operator|(DockObjectFlags lhs, DockObjectFlags rhs)
  { return static_cast<DockObjectFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gdlmmEnums */
inline DockObjectFlags operator&(DockObjectFlags lhs, DockObjectFlags rhs)
  { return static_cast<DockObjectFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gdlmmEnums */
inline DockObjectFlags operator^(DockObjectFlags lhs, DockObjectFlags rhs)
  { return static_cast<DockObjectFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gdlmmEnums */
inline DockObjectFlags operator~(DockObjectFlags flags)
  { return static_cast<DockObjectFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup gdlmmEnums */
inline DockObjectFlags& operator|=(DockObjectFlags& lhs, DockObjectFlags rhs)
  { return (lhs = static_cast<DockObjectFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gdlmmEnums */
inline DockObjectFlags& operator&=(DockObjectFlags& lhs, DockObjectFlags rhs)
  { return (lhs = static_cast<DockObjectFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gdlmmEnums */
inline DockObjectFlags& operator^=(DockObjectFlags& lhs, DockObjectFlags rhs)
  { return (lhs = static_cast<DockObjectFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/**
 * @ingroup gdlmmEnums
 */
enum DockPlacement
{
  DOCK_NONE,
  DOCK_TOP,
  DOCK_BOTTOM,
  DOCK_RIGHT,
  DOCK_LEFT,
  DOCK_CENTER,
  DOCK_FLOATING
};


class DockObject : public Gtk::Container
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef DockObject CppObjectType;
  typedef DockObject_Class CppClassType;
  typedef GdlDockObject BaseObjectType;
  typedef GdlDockObjectClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~DockObject();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class DockObject_Class;
  static CppClassType dockobject_class_;

  // noncopyable
  DockObject(const DockObject&);
  DockObject& operator=(const DockObject&);

protected:
  explicit DockObject(const Glib::ConstructParams& construct_params);
  explicit DockObject(GdlDockObject* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GdlDockObject*       gobj()       { return reinterpret_cast<GdlDockObject*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GdlDockObject* gobj() const { return reinterpret_cast<GdlDockObject*>(gobject_); }


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
  virtual void on_detach(bool arg1);
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


private:


protected:
  DockObject();

public:
  
  bool is_compound() const;
  
  
  void detach(bool recursive = true);
  
  
  DockObject* get_parent_object() const;
  
  
  void freeze();
  
  
  void thaw();
  
  
  void reduce();
  
  //_WRAP_METHOD(bool dock_request(int x, int y, const DockRequest& dock_request), gdl_dock_object_dock_request)
  
  template <class OtherType>
  void dock(DockObject& requestor, const OtherType& other_data, DockPlacement position = static_cast<DockPlacement>(DOCK_NONE));
  
  void dock(DockObject& requestor, DockPlacement position = static_cast<DockPlacement>(DOCK_NONE));
  
  
  void bind(const Glib::RefPtr<DockMaster>& master);
  
  
  void unbind();
  
  
  bool is_bound() const;
  
  template <class OtherType>
  bool reorder(DockObject& child, const OtherType& other_data, DockPlacement new_position = static_cast<DockPlacement>(DOCK_NONE));
  
  bool reorder(DockObject& child, DockPlacement new_position = static_cast<DockPlacement>(DOCK_NONE));
  
  
  void present(DockObject& child);
  
  
  bool child_placement(DockObject& child, DockPlacement placement = static_cast<DockPlacement>(DOCK_NONE));
  
  
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Nom facile à lire pour un humain pour l'objet détachable.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Glib::ustring> property_long_name() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Nom facile à lire pour un humain pour l'objet détachable.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_long_name() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Nom unique pour identifier l'objet détachable.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_name() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Dock maître auquel l'objet détachable est connecté.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< Glib::RefPtr<DockMaster> > property_master() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Dock maître auquel l'objet détachable est connecté.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<DockMaster> > property_master() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Icône prédéfinie pour l'objet détachable.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Glib::ustring> property_stock_id() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Icône prédéfinie pour l'objet détachable.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_stock_id() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  
  /**
   * @par Prototype:
   * <tt>void on_my_%detach(bool arg1)</tt>
   */

  Glib::SignalProxy1< void,bool > signal_detach();

  
  //_WRAP_SIGNAL(void dock(DockObject& arg1, DockPlacement arg2, const Glib::ValueBase* arg3), "dock")
  
protected:
  
  void dock(DockObject& requestor, const Glib::ValueBase& other_data, DockPlacement position = static_cast<DockPlacement>(DOCK_NONE));
  
  
  bool reorder(DockObject& child, const Glib::ValueBase& other_data, DockPlacement new_position = static_cast<DockPlacement>(DOCK_NONE));


};

template <class OtherType>
void DockObject::dock(DockObject& requestor, const OtherType& other_data, DockPlacement position)
{
  Glib::Value<OtherType> other_value;
  other_value.init(Glib::Value<OtherType>::value_type());
  
  dock(requestor, other_value, position);
}

template <class OtherType>
bool DockObject::reorder(DockObject& child, const OtherType& other_data, DockPlacement new_position)
{
  Glib::Value<OtherType> other_value;
  other_value.init(Glib::Value<OtherType>::value_type());
  
  return dock(child, other_value, new_position);
}

} // namespace Gdl


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdl::DockObject
   */
  Gdl::DockObject* wrap(GdlDockObject* object, bool take_copy = false);
} //namespace Glib


#endif /* _GDLMM_DOCKOBJECT_H */

