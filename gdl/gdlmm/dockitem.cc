// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gdlmm/dockitem.h>
#include <gdlmm/private/dockitem_p.h>

#include <gdl/gdl-dock-item.h>
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

namespace Gdl
{

void DockItem::dock_floating(int docking_param)
{
  gdl_dock_item_dock_to(gobj(), 0, GDL_DOCK_FLOATING, docking_param);
}

} // namespace Gdl

namespace
{


static const Glib::SignalProxyInfo DockItem_signal_dock_drag_begin_info =
{
  "dock-drag-begin",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


static void DockItem_signal_dock_drag_end_callback(GdlDockItem* self, gboolean p0,void* data)
{
  using namespace Gdl;
  typedef sigc::slot< void,bool > SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
);
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
    #endif //GLIBMM_EXCEPTIONS_ENABLED
  }
}

static const Glib::SignalProxyInfo DockItem_signal_dock_drag_end_info =
{
  "dock-drag-end",
  (GCallback) &DockItem_signal_dock_drag_end_callback,
  (GCallback) &DockItem_signal_dock_drag_end_callback
};


static void DockItem_signal_dock_drag_motion_callback(GdlDockItem* self, gint p0,gint p1,void* data)
{
  using namespace Gdl;
  typedef sigc::slot< void,int,int > SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
, p1
);
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
    #endif //GLIBMM_EXCEPTIONS_ENABLED
  }
}

static const Glib::SignalProxyInfo DockItem_signal_dock_drag_motion_info =
{
  "dock-drag-motion",
  (GCallback) &DockItem_signal_dock_drag_motion_callback,
  (GCallback) &DockItem_signal_dock_drag_motion_callback
};


} // anonymous namespace


namespace Glib
{

Gdl::DockItem* wrap(GdlDockItem* object, bool take_copy)
{
  return dynamic_cast<Gdl::DockItem *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gdl
{


/* The *_Class implementation: */

const Glib::Class& DockItem_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &DockItem_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdl_dock_item_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void DockItem_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  klass->dock_drag_begin = &dock_drag_begin_callback;
  klass->dock_drag_end = &dock_drag_end_callback;
  klass->dock_drag_motion = &dock_drag_motion_callback;
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void DockItem_Class::dock_drag_begin_callback(GdlDockItem* self)
{
  Glib::ObjectBase *const obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    CppObjectType *const obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        // Call the virtual member method, which derived classes might override.
        obj->on_dock_drag_begin();
        return;
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }
  
  BaseClassType *const base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->dock_drag_begin)
    (*base->dock_drag_begin)(self);
}
void DockItem_Class::dock_drag_end_callback(GdlDockItem* self, gboolean p0)
{
  Glib::ObjectBase *const obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    CppObjectType *const obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        // Call the virtual member method, which derived classes might override.
        obj->on_dock_drag_end(p0
);
        return;
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }
  
  BaseClassType *const base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->dock_drag_end)
    (*base->dock_drag_end)(self, p0);
}
void DockItem_Class::dock_drag_motion_callback(GdlDockItem* self, gint p0, gint p1)
{
  Glib::ObjectBase *const obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    CppObjectType *const obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        // Call the virtual member method, which derived classes might override.
        obj->on_dock_drag_motion(p0
, p1
);
        return;
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }
  
  BaseClassType *const base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->dock_drag_motion)
    (*base->dock_drag_motion)(self, p0, p1);
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* DockItem_Class::wrap_new(GObject* o)
{
  return manage(new DockItem((GdlDockItem*)(o)));

}


/* The implementation: */

DockItem::DockItem(const Glib::ConstructParams& construct_params)
:
  DockObject(construct_params)
{
  }

DockItem::DockItem(GdlDockItem* castitem)
:
  DockObject((GdlDockObject*)(castitem))
{
  }

DockItem::~DockItem()
{
  destroy_();
}

DockItem::CppClassType DockItem::dockitem_class_; // initialize static member

GType DockItem::get_type()
{
  return dockitem_class_.init().get_type();
}


GType DockItem::get_base_type()
{
  return gdl_dock_item_get_type();
}


DockItem::DockItem(const Glib::ustring& name, const Glib::ustring& long_name, DockItemBehavior behavior)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  DockObject(Glib::ConstructParams(dockitem_class_.init(), "name", name.c_str(), "long_name", long_name.c_str(), "behavior", ((GdlDockItemBehavior)(behavior)), static_cast<char*>(0)))
{
  

}

DockItem::DockItem(const Glib::ustring& name, const Glib::ustring& long_name, const Gtk::StockID& stock_id, DockItemBehavior behavior)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  DockObject(Glib::ConstructParams(dockitem_class_.init(), "name", name.c_str(), "long_name", long_name.c_str(), "stock_id", (stock_id).get_c_str(), "behavior", ((GdlDockItemBehavior)(behavior)), static_cast<char*>(0)))
{
  

}

void DockItem::dock_to(DockItem& target, DockPlacement position, int docking_param)
{
gdl_dock_item_dock_to(gobj(), target.gobj(), ((GdlDockPlacement)(position)), docking_param); 
}

void DockItem::set_orientation(Gtk::Orientation orientation)
{
gdl_dock_item_set_orientation(gobj(), ((GtkOrientation)(orientation))); 
}

Gtk::Widget* DockItem::get_tablabel() const
{
  return Glib::wrap(gdl_dock_item_get_tablabel(const_cast<GdlDockItem*>(gobj())));
}

void DockItem::set_tablabel(Gtk::Widget& tablabel)
{
gdl_dock_item_set_tablabel(gobj(), (tablabel).gobj()); 
}

void DockItem::hide_grip()
{
gdl_dock_item_hide_grip(gobj()); 
}

void DockItem::show_grip()
{
gdl_dock_item_show_grip(gobj()); 
}

void DockItem::bind(Gtk::Widget& dock)
{
gdl_dock_item_bind(gobj(), (dock).gobj()); 
}

void DockItem::unbind()
{
gdl_dock_item_unbind(gobj()); 
}

void DockItem::hide_item()
{
gdl_dock_item_hide_item(gobj()); 
}

void DockItem::iconify_item()
{
gdl_dock_item_iconify_item(gobj()); 
}

void DockItem::show_item()
{
gdl_dock_item_show_item(gobj()); 
}

void DockItem::lock()
{
gdl_dock_item_lock(gobj()); 
}

void DockItem::unlock()
{
gdl_dock_item_unlock(gobj()); 
}

void DockItem::set_default_position(DockObject& reference)
{
gdl_dock_item_set_default_position(gobj(), reference.gobj()); 
}

void DockItem::preferred_size(Gtk::Requisition* req)
{
gdl_dock_item_preferred_size(gobj(), req); 
}


Glib::SignalProxy0< void > DockItem::signal_dock_drag_begin()
{
  return Glib::SignalProxy0< void >(this, &DockItem_signal_dock_drag_begin_info);
}


Glib::SignalProxy1< void,bool > DockItem::signal_dock_drag_end()
{
  return Glib::SignalProxy1< void,bool >(this, &DockItem_signal_dock_drag_end_info);
}


Glib::SignalProxy2< void,int,int > DockItem::signal_dock_drag_motion()
{
  return Glib::SignalProxy2< void,int,int >(this, &DockItem_signal_dock_drag_motion_info);
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<DockItemBehavior> DockItem::property_behavior() 
{
  return Glib::PropertyProxy<DockItemBehavior>(this, "behavior");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<DockItemBehavior> DockItem::property_behavior() const
{
  return Glib::PropertyProxy_ReadOnly<DockItemBehavior>(this, "behavior");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> DockItem::property_locked() 
{
  return Glib::PropertyProxy<bool>(this, "locked");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> DockItem::property_locked() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "locked");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<Gtk::Orientation> DockItem::property_orientation() 
{
  return Glib::PropertyProxy<Gtk::Orientation>(this, "orientation");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<Gtk::Orientation> DockItem::property_orientation() const
{
  return Glib::PropertyProxy_ReadOnly<Gtk::Orientation>(this, "orientation");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<int> DockItem::property_preferred_height() 
{
  return Glib::PropertyProxy<int>(this, "preferred-height");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<int> DockItem::property_preferred_height() const
{
  return Glib::PropertyProxy_ReadOnly<int>(this, "preferred-height");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<int> DockItem::property_preferred_width() 
{
  return Glib::PropertyProxy<int>(this, "preferred-width");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<int> DockItem::property_preferred_width() const
{
  return Glib::PropertyProxy_ReadOnly<int>(this, "preferred-width");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> DockItem::property_resize() 
{
  return Glib::PropertyProxy<bool>(this, "resize");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> DockItem::property_resize() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "resize");
}
#endif //GLIBMM_PROPERTIES_ENABLED


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void Gdl::DockItem::on_dock_drag_begin()
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->dock_drag_begin)
    (*base->dock_drag_begin)(gobj());
}
void Gdl::DockItem::on_dock_drag_end(bool cancel)
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->dock_drag_end)
    (*base->dock_drag_end)(gobj(),static_cast<int>(cancel));
}
void Gdl::DockItem::on_dock_drag_motion(int x, int y)
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->dock_drag_motion)
    (*base->dock_drag_motion)(gobj(),x,y);
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gdl


