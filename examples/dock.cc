/** 
 * Copyright (C) 2009-2011  Fabien Parent <parent.f@gmail.com>
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

class GdlExampleWindow : public Gtk::Window
{
public:
    GdlExampleWindow() :
        m_layout_manager(Gdl::DockLayout::create(m_dock)),
        m_ph1("ph1", m_dock, Gdl::DOCK_TOP, false),
        m_ph2("ph2", m_dock, Gdl::DOCK_BOTTOM, false),
        m_ph3("ph3", m_dock, Gdl::DOCK_LEFT, false),
        m_ph4("ph4", m_dock, Gdl::DOCK_RIGHT, false)
    {
        Gtk::Button* save_button = new Gtk::Button(Gtk::Stock::SAVE);
        Gtk::Button* layout_manager_button = new Gtk::Button("Layout Manager");
        Gtk::Button* dump_button = new Gtk::Button("Dump XML");

        Gdl::DockBar* dockbar = new Gdl::DockBar(m_dock);
        dockbar->set_style(Gdl::DOCK_BAR_TEXT);

        Gtk::Box* box = new Gtk::HBox(false, 5);
        Gtk::Box* button_box = new Gtk::HBox(true, 5);

        Gtk::Box* table = new Gtk::VBox(false, 5);
        table->set_border_width(10);
        table->pack_start(*Gtk::manage(box));
        table->pack_end(*Gtk::manage(button_box), false, false);

        box->pack_start(*Gtk::manage(dockbar), false, false);
        box->pack_end(m_dock);

        button_box->pack_end(*Gtk::manage(save_button), false, true);
        button_box->pack_end(*Gtk::manage(layout_manager_button), false, true);
        button_box->pack_end(*Gtk::manage(dump_button), false, true);

        save_button->signal_clicked().connect(sigc::mem_fun
            (*this, &GdlExampleWindow::save_layout));
        layout_manager_button->signal_clicked().connect(sigc::mem_fun
            (*this, &GdlExampleWindow::run_layout_manager));
        dump_button->signal_clicked().connect(sigc::mem_fun
            (*this, &GdlExampleWindow::dump_xml));

        create_items();

        set_title("Docking widget test");
        set_default_size(400, 400);
        add(*Gtk::manage(table));
        show_all_children();
    }

    void create_items()
    {
        Gdl::DockItem* items[4];
        Gdl::DockItem* item1 = new Gdl::DockItem
                ("item1", "Item #1", Gdl::DOCK_ITEM_BEH_LOCKED);
        Gdl::DockItem* item2 = new Gdl::DockItem(
                "item2",
                "Item #2: Select the switcher style for notebooks",
                Gtk::Stock::EXECUTE);
        Gdl::DockItem* item3 = new Gdl::DockItem(
                "item3",
                "Item #3 has accented characters (áéíóúñ)",
                Gtk::Stock::CONVERT,
                Gdl::DOCK_ITEM_BEH_NORMAL | Gdl::DOCK_ITEM_BEH_CANT_CLOSE);
        items[0] = new Gdl::DockItem(
                "Item #4",
                "Item #4",
                Gtk::Stock::JUSTIFY_FILL,
                Gdl::DOCK_ITEM_BEH_NORMAL | Gdl::DOCK_ITEM_BEH_CANT_ICONIFY);

        m_dock.add_item(*Gtk::manage(item1), Gdl::DOCK_TOP);
        m_dock.add_item(*Gtk::manage(item2), Gdl::DOCK_RIGHT);
        m_dock.add_item(*Gtk::manage(item3), Gdl::DOCK_BOTTOM);
        m_dock.add_item(*Gtk::manage(items[0]), Gdl::DOCK_BOTTOM);

        for (int i = 1; i < 3; i++)
        {
            Glib::ustring name = Glib::ustring::compose("Item #%1", i + 4);
            items[i] = Gtk::manage
                (new Gdl::DockItem(name, name, Gtk::Stock::NEW));
            items[i]->add(*create_text_item());
            items[0]->dock(*((Gdl::DockObject*) items[i]), Gdl::DOCK_CENTER);
        }

        Gtk::Button* name_button = new Gtk::Button("Button 3");
        name_button->signal_clicked().connect(sigc::bind<Gdl::DockItem&>
            (sigc::mem_fun(*this, &GdlExampleWindow::on_change_name), *item3));

        item2->property_resize() = false;

        item1->add(*create_text_item());
        item2->add(*create_styles_item());
        item3->add(*Gtk::manage(name_button));
        items[0]->add(*create_text_item());

        item3->dock_to(*item1, Gdl::DOCK_TOP);
        item2->dock_to(*item3, Gdl::DOCK_RIGHT);
        item2->dock_to(*item3, Gdl::DOCK_LEFT);
        item2->dock_floating();
    }

protected:
    void on_change_name(Gdl::DockItem& item)
    {
        static int index = 10;
        item.property_long_name() = Glib::ustring::compose("Item %1", index++);
    }

    void on_style_button_toggled(Gtk::RadioButton* button,
                                 Gdl::SwitcherStyle style)
    {
        Glib::RefPtr<Gdl::DockMaster> master = m_dock.property_master();
        if (button->get_active())
            master->property_switcher_style() = style;
    }

    void dump_xml()
    {
        m_layout_manager->save_to_file("layout.xml");
    }

    void run_layout_manager ()
    {
        m_layout_manager->run_manager();
    }

    void save_layout()
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
            m_layout_manager->save_layout(entry.get_text());
    }

    /**
     * Helpers
     */
    Gtk::Widget* create_text_item()
    {
        Gtk::Box* box = new Gtk::VBox(false);
        Gtk::TextView* text = new Gtk::TextView();
        Gtk::ScrolledWindow* scrolledwindow = new Gtk::ScrolledWindow();
        scrolledwindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
        scrolledwindow->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
        scrolledwindow->add(*Gtk::manage(text));
        box->pack_start(*Gtk::manage(scrolledwindow));
        box->show_all();

        return Gtk::manage(box);
    }

    Gtk::RadioButton* create_style_button(Gtk::Box* box,
                                          Gtk::RadioButtonGroup* group,
                                          Gdl::SwitcherStyle style,
                                          const Glib::ustring& style_text)
    {
        Gdl::SwitcherStyle current_style;
        Gtk::RadioButton* button;
        if (group)
            button = new Gtk::RadioButton(*group, style_text);
        else
            button = new Gtk::RadioButton(style_text);

        Glib::RefPtr<Gdl::DockMaster> master = m_dock.property_master();
        current_style = master->property_switcher_style();

        if (current_style == style)
            button->set_active(true);

        button->signal_toggled().connect
            (sigc::bind<Gtk::RadioButton*, Gdl::SwitcherStyle>(sigc::mem_fun
                (*this, &GdlExampleWindow::on_style_button_toggled),
             button, style));
        box->pack_start(*Gtk::manage(button), false, false);
        return Gtk::manage(button);
    }

    Gtk::Widget* create_styles_item()
    {
        Gtk::Box* box = new Gtk::VBox(false);
        Gtk::RadioButtonGroup group;

        group = create_style_button
            (box,0, Gdl::SWITCHER_STYLE_ICON, "Only icon")->get_group();
        create_style_button(box, &group, Gdl::SWITCHER_STYLE_TEXT, "Only text");
        create_style_button
            (box, &group, Gdl::SWITCHER_STYLE_BOTH, "Both icons and texts");
        create_style_button
            (box, &group, Gdl::SWITCHER_STYLE_TOOLBAR, "Desktop toolbar style");
        create_style_button
            (box, &group, Gdl::SWITCHER_STYLE_TABS, "Notebook tabs");
        create_style_button
            (box, &group, Gdl::SWITCHER_STYLE_NONE, "None of the above");
        box->show_all();
        return Gtk::manage(box);
    }

private:
    Gdl::Dock m_dock;
    Glib::RefPtr<Gdl::DockLayout> m_layout_manager;

    Gdl::DockPlaceholder m_ph1;
    Gdl::DockPlaceholder m_ph2;
    Gdl::DockPlaceholder m_ph3;
    Gdl::DockPlaceholder m_ph4;
};

int main(int argc, char** argv)
{
    Gtk::Main kit(argc, argv);
    Gdl::init();

    GdlExampleWindow window;
    Gtk::Main::run(window);

    return 0;
}
