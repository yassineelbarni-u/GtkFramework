#include "../../include/widgets/menu_deroulant.h"

// Callback pour afficher le sous-menu vertical
void on_menu_item_selected(GtkWidget *widget, gpointer data) {
    GtkWidget *menu = GTK_WIDGET(data);
    gtk_widget_show_all(menu);
}

// Callback pour afficher le sous-menu horizontal
void on_submenu_item_selected(GtkWidget *widget, gpointer data) {
    GtkWidget *submenu = GTK_WIDGET(data);
    gtk_widget_show_all(submenu);
}

// Fonction pour créer le menu déroulant
GtkWidget *create_menu_deroulant(GtkWidget *parent) {
    // Création du menu principal
    GtkWidget *menu_bar = gtk_menu_bar_new();

    // Création des éléments du menu principal
    GtkWidget *menu_item1 = gtk_menu_item_new_with_label("MonChoix");
    GtkWidget *menu_item2 = gtk_menu_item_new_with_label("VotreChoix");
    GtkWidget *menu_item3 = gtk_menu_item_new_with_label("LeurChoix");

    // Ajout des éléments au menu principal
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item1);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item2);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item3);

    // --- Sous-menu vertical pour "VotreChoix" ---
    GtkWidget *submenu_votrechoix = gtk_menu_new();
    GtkWidget *submenu_item1 = gtk_menu_item_new_with_label("Sous Choix1");
    GtkWidget *submenu_item2 = gtk_menu_item_new_with_label("Sous Choix2");
    GtkWidget *submenu_item3 = gtk_menu_item_new_with_label("Sous Choix3");

    gtk_menu_shell_append(GTK_MENU_SHELL(submenu_votrechoix), submenu_item1);
    gtk_menu_shell_append(GTK_MENU_SHELL(submenu_votrechoix), submenu_item2);
    gtk_menu_shell_append(GTK_MENU_SHELL(submenu_votrechoix), submenu_item3);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item2), submenu_votrechoix);

    // --- Sous-menu horizontal pour "Sous Choix2" ---
    GtkWidget *submenu_horiz = gtk_menu_new();
    GtkWidget *submenu_horiz_item1 = gtk_menu_item_new_with_label("Choix221");
    GtkWidget *submenu_horiz_item2 = gtk_menu_item_new_with_label("Choix222");
    GtkWidget *submenu_horiz_item3 = gtk_menu_item_new_with_label("Choix223");

    gtk_menu_shell_append(GTK_MENU_SHELL(submenu_horiz), submenu_horiz_item1);
    gtk_menu_shell_append(GTK_MENU_SHELL(submenu_horiz), submenu_horiz_item2);
    gtk_menu_shell_append(GTK_MENU_SHELL(submenu_horiz), submenu_horiz_item3);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(submenu_item2), submenu_horiz);

    return menu_bar;
}
