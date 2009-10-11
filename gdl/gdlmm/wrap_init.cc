
#include <glib.h>

// Disable the 'const' function attribute of the get_type() functions.
// GCC would optimize them out because we don't use the return value.
#undef  G_GNUC_CONST
#define G_GNUC_CONST /* empty */

#include <gdlmm/wrap_init.h>
#include <glibmm/error.h>
#include <glibmm/object.h>

// #include the widget headers so that we can call the get_type() static methods:

#include "dockobject.h"
#include "dockitem.h"
#include "dockplaceholder.h"
#include "dockmaster.h"
#include "docklayout.h"
#include "dock.h"
#include "dockbar.h"

extern "C"
{

//Declarations of the *_get_type() functions:

GType gdl_dock_get_type(void);
GType gdl_dock_bar_get_type(void);
GType gdl_dock_item_get_type(void);
GType gdl_dock_layout_get_type(void);
GType gdl_dock_master_get_type(void);
GType gdl_dock_object_get_type(void);
GType gdl_dock_placeholder_get_type(void);

//Declarations of the *_error_quark() functions:

} // extern "C"


//Declarations of the *_Class::wrap_new() methods, instead of including all the private headers:

namespace Gdl {  class Dock_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gdl {  class DockBar_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gdl {  class DockItem_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gdl {  class DockLayout_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gdl {  class DockMaster_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gdl {  class DockObject_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gdl {  class DockPlaceholder_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }

namespace Gdl { 

void wrap_init()
{
  // Register Error domains:

// Map gtypes to gtkmm wrapper-creation functions:
  Glib::wrap_register(gdl_dock_get_type(), &Gdl::Dock_Class::wrap_new);
  Glib::wrap_register(gdl_dock_bar_get_type(), &Gdl::DockBar_Class::wrap_new);
  Glib::wrap_register(gdl_dock_item_get_type(), &Gdl::DockItem_Class::wrap_new);
  Glib::wrap_register(gdl_dock_layout_get_type(), &Gdl::DockLayout_Class::wrap_new);
  Glib::wrap_register(gdl_dock_master_get_type(), &Gdl::DockMaster_Class::wrap_new);
  Glib::wrap_register(gdl_dock_object_get_type(), &Gdl::DockObject_Class::wrap_new);
  Glib::wrap_register(gdl_dock_placeholder_get_type(), &Gdl::DockPlaceholder_Class::wrap_new);

  // Register the gtkmm gtypes:
  Gdl::Dock::get_type();
  Gdl::DockBar::get_type();
  Gdl::DockItem::get_type();
  Gdl::DockLayout::get_type();
  Gdl::DockMaster::get_type();
  Gdl::DockObject::get_type();
  Gdl::DockPlaceholder::get_type();

} // wrap_init()

} //Gdl


