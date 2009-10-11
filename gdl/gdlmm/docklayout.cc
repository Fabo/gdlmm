// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gdlmm/docklayout.h>
#include <gdlmm/private/docklayout_p.h>

#include <gdl/gdl-dock-layout.h>
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

DockLayout::DockLayout(Dock& dock)
:
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(docklayout_class_.init(), "master", GDL_DOCK_OBJECT_GET_MASTER(dock.gobj()), (char*) 0))
{

}

} // namespace Gdl

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gdl::DockLayout> wrap(GdlDockLayout* object, bool take_copy)
{
  return Glib::RefPtr<Gdl::DockLayout>( dynamic_cast<Gdl::DockLayout*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdl
{


/* The *_Class implementation: */

const Glib::Class& DockLayout_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &DockLayout_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdl_dock_layout_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void DockLayout_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* DockLayout_Class::wrap_new(GObject* object)
{
  return new DockLayout((GdlDockLayout*)object);
}


/* The implementation: */

GdlDockLayout* DockLayout::gobj_copy()
{
  reference();
  return gobj();
}

DockLayout::DockLayout(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

DockLayout::DockLayout(GdlDockLayout* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


DockLayout::~DockLayout()
{}


DockLayout::CppClassType DockLayout::docklayout_class_; // initialize static member

GType DockLayout::get_type()
{
  return docklayout_class_.init().get_type();
}


GType DockLayout::get_base_type()
{
  return gdl_dock_layout_get_type();
}


Glib::RefPtr<DockLayout> DockLayout::create(Dock& dock)
{
  return Glib::RefPtr<DockLayout>( new DockLayout(dock) );
}
void DockLayout::attach(const Glib::RefPtr<DockMaster>& master)
{
gdl_dock_layout_attach(gobj(), Glib::unwrap(master)); 
}

bool DockLayout::load_layout(const Glib::ustring& name)
{
  return gdl_dock_layout_load_layout(gobj(), name.c_str());
}

void DockLayout::save_layout(const Glib::ustring& name)
{
gdl_dock_layout_save_layout(gobj(), name.c_str()); 
}

void DockLayout::delete_layout(const Glib::ustring& name)
{
gdl_dock_layout_delete_layout(gobj(), name.c_str()); 
}

Glib::ListHandle<Glib::ustring> DockLayout::get_layouts(bool include_default)
{
  return Glib::ListHandle<Glib::ustring>(gdl_dock_layout_get_layouts(gobj(), static_cast<int>(include_default)), Glib::OWNERSHIP_SHALLOW);
}

void DockLayout::run_manager()
{
gdl_dock_layout_run_manager(gobj()); 
}

bool DockLayout::load_from_file(const std::string& filename)
{
  return gdl_dock_layout_load_from_file(gobj(), filename.c_str());
}

bool DockLayout::save_to_file(const std::string& filename)
{
  return gdl_dock_layout_save_to_file(gobj(), filename.c_str());
}

bool DockLayout::is_dirty() const
{
  return gdl_dock_layout_is_dirty(const_cast<GdlDockLayout*>(gobj()));
}

Gtk::Widget* DockLayout::get_layouts_ui()
{
  return Glib::wrap(gdl_dock_layout_get_layouts_ui(gobj()));
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> DockLayout::property_dirty() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "dirty");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Glib::RefPtr<DockMaster> > DockLayout::property_master() 
{
  return Glib::PropertyProxy< Glib::RefPtr<DockMaster> >(this, "master");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::RefPtr<DockMaster> > DockLayout::property_master() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<DockMaster> >(this, "master");
}
#endif //GLIBMM_PROPERTIES_ENABLED


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gdl


