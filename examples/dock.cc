/** 
 * Copyright (C) 2009  Fabien Parent <parent.f@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <gtkmm.h>
#include <gtk/gtk.h>

#include <gdlmm.h>
#include <gdl/gdl.h>

Gtk::Widget* create_text_item(void)
{
	GtkWidget *vbox1;
	GtkWidget *scrolledwindow1;
	GtkWidget *text;

	vbox1 = gtk_vbox_new (FALSE, 0);
	gtk_widget_show (vbox1);

	scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
	gtk_widget_show (scrolledwindow1);
	gtk_box_pack_start (GTK_BOX (vbox1), scrolledwindow1, TRUE, TRUE, 0);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1),
					GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
        gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow1),
                                             GTK_SHADOW_ETCHED_IN);
	text = gtk_text_view_new ();
        g_object_set (text, "wrap-mode", GTK_WRAP_WORD, NULL);
	gtk_widget_show (text);
	gtk_container_add (GTK_CONTAINER (scrolledwindow1), text);

	return Glib::wrap(vbox1);
}

Gtk::Widget* create_item(const gchar *button_title)
{
	GtkWidget *vbox1;
	GtkWidget *button1;

	vbox1 = gtk_vbox_new (FALSE, 0);
	gtk_widget_show (vbox1);

	button1 = gtk_button_new_with_label (button_title);
	gtk_widget_show (button1);
	gtk_box_pack_start (GTK_BOX (vbox1), button1, TRUE, TRUE, 0);

	return Glib::wrap(vbox1);
}

void on_style_button_toggled(GtkRadioButton *button, GdlDock *dock)
{
	gboolean active;
	GdlDockMaster *master = GDL_DOCK_OBJECT_GET_MASTER (dock);
	GdlSwitcherStyle style =
		static_cast<GdlSwitcherStyle>(GPOINTER_TO_INT (g_object_get_data (G_OBJECT (button),
						    "__style_id")));
	active = gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (button));
	if (active) {
	    g_object_set (master, "switcher-style", style, NULL);
	}
}

GtkWidget* create_style_button (GtkWidget *dock, GtkWidget *box, GtkWidget *group,
		     GdlSwitcherStyle style, const gchar *style_text)
{
	GdlSwitcherStyle current_style;
	GtkWidget *button1;
	GdlDockMaster *master = GDL_DOCK_OBJECT_GET_MASTER (dock);
	
	g_object_get (master, "switcher-style", &current_style, NULL);
	button1 = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (group),
						   style_text);
	gtk_widget_show (button1);
	g_object_set_data (G_OBJECT (button1), "__style_id",
			   GINT_TO_POINTER (style));
	if (current_style == style) {
	    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button1), TRUE);
	}
	g_signal_connect (button1, "toggled",
			  G_CALLBACK (on_style_button_toggled),
			  dock);
	gtk_box_pack_start (GTK_BOX (box), button1, FALSE, FALSE, 0);
	return button1;
}

Gtk::Widget* create_styles_item(GtkWidget *dock)
{
	GtkWidget *vbox1;
	GtkWidget *group;
	
	vbox1 = gtk_vbox_new (FALSE, 0);
	gtk_widget_show (vbox1);

	group = create_style_button (dock, vbox1, NULL,
				     GDL_SWITCHER_STYLE_ICON, "Only icon");
	group = create_style_button (dock, vbox1, group,
				     GDL_SWITCHER_STYLE_TEXT, "Only text");
	group = create_style_button (dock, vbox1, group,
				     GDL_SWITCHER_STYLE_BOTH,
				     "Both icons and texts");
	group = create_style_button (dock, vbox1, group,
				     GDL_SWITCHER_STYLE_TOOLBAR,
				     "Desktop toolbar style");
	group = create_style_button (dock, vbox1, group,
				     GDL_SWITCHER_STYLE_TABS,
				     "Notebook tabs");
	group = create_style_button (dock, vbox1, group,
				     GDL_SWITCHER_STYLE_NONE,
                                     "None of the above");
	return Glib::wrap(vbox1);
}

void button_dump_cb(Glib::RefPtr<Gdl::DockLayout> layout)
{
	layout->save_to_file("layout.xml");
}

void run_layout_manager_cb (Glib::RefPtr<Gdl::DockLayout> layout)
{
	layout->run_manager();
}

void save_layout_cb(Glib::RefPtr<Gdl::DockLayout> layout)
{
	Gtk::Dialog dialog("New Layout");
	Gtk::HBox hbox;
	hbox.set_border_width(8);
	dialog.get_vbox()->pack_start(hbox, false, false);
	dialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);

	Gtk::Label label("Name:");
	hbox.pack_start(label, false, false);
	
	Gtk::Entry entry;
	hbox.pack_start(entry);
	
	hbox.show_all();

	if (dialog.run() == Gtk::RESPONSE_OK)
	{
		layout->save_layout(entry.get_text());
	}
}

int main(int argc, char** argv)
{
	Gtk::Main kit(argc, argv);
	Gtk::Window window;
	
	window.set_title("Docking widget test");
	window.set_default_size(400, 400);
	
	Gtk::VBox table;
	table.set_border_width(10);
	
	Gtk::HBox box, button_box(true);
	
	Gtk::Button save_button(Gtk::Stock::SAVE), layout_manager_button("Layout Manager"), dump_button("Dump XML");
	
	Gdl::DockItem item1("item1", "Item #1", Gdl::DOCK_ITEM_BEH_LOCKED);
	Gdl::DockItem item2("item2", "Item #2: Select the switcher style for notebooks", Gtk::Stock::EXECUTE);
	Gdl::DockItem item3("item3", "Item #3 has accented characters (áéíóúñ)", Gtk::Stock::CONVERT, Gdl::DOCK_ITEM_BEH_NORMAL | Gdl::DOCK_ITEM_BEH_CANT_CLOSE);
	Gdl::DockItem* items[4];
	items[0] = new Gdl::DockItem("Item #4", "Item #4", Gtk::Stock::JUSTIFY_FILL, Gdl::DOCK_ITEM_BEH_NORMAL | Gdl::DOCK_ITEM_BEH_CANT_ICONIFY);
	
	Gdl::Dock dock;
	dock.add_item(item1, Gdl::DOCK_TOP);
	dock.add_item(item2, Gdl::DOCK_RIGHT);
	dock.add_item(item3, Gdl::DOCK_BOTTOM);
	dock.add_item(*(items[0]), Gdl::DOCK_BOTTOM);
	
	item1.add(*create_text_item());
	item2.add(*create_styles_item((GtkWidget*) dock.gobj()));
	item3.add(*create_item("Button 3"));
	items[0]->add(*create_text_item());
	
	item2.property_resize() = false;
	
	for (int i = 1; i < 3; i++)
	{
		Glib::ustring name = Glib::ustring::compose("Item #%1", i + 4);
		items[i] = new Gdl::DockItem(name, name, Gtk::Stock::NEW);
		items[i]->add(*create_text_item());
		items[0]->dock(*((Gdl::DockObject*) items[i]), Gdl::DOCK_CENTER);
	}
	
	item3.dock_to(item1, Gdl::DOCK_TOP);
	item2.dock_to(item3, Gdl::DOCK_RIGHT);
	item2.dock_to(item3, Gdl::DOCK_LEFT);
	item2.dock_floating();
	
	Gdl::DockBar dock_bar(dock);
	dock_bar.set_style(Gdl::DOCK_BAR_TEXT);
	
	table.pack_start(box);
	box.pack_start(dock_bar, false, false);
	box.pack_end(dock);
	
	window.add(table);
	table.pack_end(button_box, false, false);
	
	Glib::RefPtr<Gdl::DockLayout> layout_manager = Gdl::DockLayout::create(dock);
	
	button_box.pack_end(save_button, false, true);
	button_box.pack_end(layout_manager_button, false, true);
	button_box.pack_end(dump_button, false, true);
	
	save_button.signal_clicked().connect(sigc::bind<Glib::RefPtr<Gdl::DockLayout> >(sigc::ptr_fun(&save_layout_cb), layout_manager));
	layout_manager_button.signal_clicked().connect(sigc::bind<Glib::RefPtr<Gdl::DockLayout> >(sigc::ptr_fun(&run_layout_manager_cb), layout_manager));
	dump_button.signal_clicked().connect(sigc::bind<Glib::RefPtr<Gdl::DockLayout> >(sigc::ptr_fun(&button_dump_cb), layout_manager));
	
	gdl_dock_placeholder_new("ph1", GDL_DOCK_OBJECT(dock.gobj()), GDL_DOCK_TOP, FALSE);
	gdl_dock_placeholder_new("ph2", GDL_DOCK_OBJECT(dock.gobj()), GDL_DOCK_BOTTOM, FALSE);
	gdl_dock_placeholder_new("ph3", GDL_DOCK_OBJECT(dock.gobj()), GDL_DOCK_LEFT, FALSE);
	gdl_dock_placeholder_new("ph4", GDL_DOCK_OBJECT(dock.gobj()), GDL_DOCK_RIGHT, FALSE);
	
	/* see https://bugzilla.gnome.org/show_bug.cgi?id=597996
	Gdl::DockPlaceholder("ph1", dock, Gdl::DOCK_TOP, false);
	Gdl::DockPlaceholder("ph2", dock, Gdl::DOCK_BOTTOM, false);
	Gdl::DockPlaceholder("ph3", dock, Gdl::DOCK_LEFT, false);
	Gdl::DockPlaceholder("ph4", dock, Gdl::DOCK_RIGHT, false);
	*/
	
	window.show_all_children();
	Gtk::Main::run(window);
	
	return 0;
}
