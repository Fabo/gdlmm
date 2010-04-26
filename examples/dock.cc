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
#include <gdlmm.h>
#include <gdl/gdl.h>


static Gtk::Widget* create_text_item(void)
{
	Gtk::VBox* vbox = new Gtk::VBox(false);
	Gtk::TextView* text = new Gtk::TextView();
	Gtk::ScrolledWindow* scrolledwindow = new Gtk::ScrolledWindow();
	scrolledwindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	scrolledwindow->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
	scrolledwindow->add(*Gtk::manage(text));
	vbox->pack_start(*Gtk::manage(scrolledwindow));
	vbox->show_all();
	
	return Gtk::manage(vbox);
}

static Gtk::Button* create_item(const Glib::ustring& button_title)
{
	Gtk::Button* button = new Gtk::Button(button_title);
	button->show();
	
	return Gtk::manage(button);
}

static void on_style_button_toggled(Gtk::RadioButton* button, Gdl::Dock& dock, Gdl::SwitcherStyle style)
{
	Glib::RefPtr<Gdl::DockMaster> master = dock.property_master();
	if (button->get_active())
	{
		master->property_switcher_style() = style;
	}
}

static Gtk::RadioButton* create_style_button(Gdl::Dock& dock, Gtk::VBox* box, Gtk::RadioButtonGroup* group, Gdl::SwitcherStyle style, const Glib::ustring& style_text)
{
	Gdl::SwitcherStyle current_style;
	Gtk::RadioButton* button;
	if (group)
		button = new Gtk::RadioButton(*group, style_text);
	else
		button = new Gtk::RadioButton(style_text);
	
	Glib::RefPtr<Gdl::DockMaster> master = dock.property_master();
	current_style = master->property_switcher_style();
	
	if (current_style == style)
	{
		button->set_active(true);
	}
	
	button->signal_toggled().connect(sigc::bind<Gtk::RadioButton*, Gdl::Dock&, Gdl::SwitcherStyle>(sigc::ptr_fun(&on_style_button_toggled), button, dock, style));
	box->pack_start(*Gtk::manage(button), false, false);
	return button;
}

static Gtk::Widget* create_styles_item(Gdl::Dock& dock)
{
	Gtk::VBox* vbox = new Gtk::VBox(false);
	Gtk::RadioButtonGroup* group;
	
	group = &(create_style_button(dock, vbox, 0, Gdl::SWITCHER_STYLE_ICON, "Only icon")->get_group());
	create_style_button(dock, vbox, group, Gdl::SWITCHER_STYLE_TEXT, "Only text");
	create_style_button(dock, vbox, group, Gdl::SWITCHER_STYLE_BOTH, "Both icons and texts");
	create_style_button(dock, vbox, group, Gdl::SWITCHER_STYLE_TOOLBAR, "Desktop toolbar style");
	create_style_button(dock, vbox, group, Gdl::SWITCHER_STYLE_TABS, "Notebook tabs");
	create_style_button(dock, vbox, group, Gdl::SWITCHER_STYLE_NONE, "None of the above");
	
	vbox->show_all();
	
	return Gtk::manage(vbox);
}

static void button_dump_cb(Glib::RefPtr<Gdl::DockLayout> layout)
{
	layout->save_to_file("layout.xml");
}

static void run_layout_manager_cb (Glib::RefPtr<Gdl::DockLayout> layout)
{
	layout->run_manager();
}

static void save_layout_cb(Glib::RefPtr<Gdl::DockLayout> layout)
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

static void on_change_name(Gdl::DockItem& item)
{
	static int index = 10;
	item.property_long_name() = Glib::ustring::compose("Item %1", index++);
}

int main(int argc, char** argv)
{
	Gtk::Main kit(argc, argv);
	Gdl::init();
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
	item2.add(*create_styles_item(dock));
	items[0]->add(*create_text_item());
	
	Gtk::Button& name_button = *create_item("Button 3");
	name_button.signal_clicked().connect(sigc::bind<Gdl::DockItem&>(sigc::ptr_fun(&on_change_name), item3));
	item3.add(name_button);
	
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

	Gdl::DockPlaceholder("ph1", dock, Gdl::DOCK_TOP, false);
	Gdl::DockPlaceholder("ph2", dock, Gdl::DOCK_BOTTOM, false);
	Gdl::DockPlaceholder("ph3", dock, Gdl::DOCK_LEFT, false);
	Gdl::DockPlaceholder("ph4", dock, Gdl::DOCK_RIGHT, false);
	
	
	window.show_all_children();
	Gtk::Main::run(window);
	
	return 0;
}
