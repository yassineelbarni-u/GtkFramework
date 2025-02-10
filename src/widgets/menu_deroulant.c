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

    // ------------------------------------ Sous-menu horizontal pour "VotreChoix" ------------------------------
    GtkWidget *submenu_votrechoix = gtk_menu_new();
    GtkWidget *submenu_item1 = gtk_menu_item_new_with_label("Sous Choix1");
    GtkWidget *submenu_item2 = gtk_menu_item_new_with_label("Sous Choix2");
    GtkWidget *submenu_item3 = gtk_menu_item_new_with_label("Sous Choix3");
    
    // Ajout des éléments au sous-menu horizontal
    gtk_menu_shell_append(GTK_MENU_SHELL(submenu_votrechoix), submenu_item1);
    gtk_menu_shell_append(GTK_MENU_SHELL(submenu_votrechoix), submenu_item2);
    gtk_menu_shell_append(GTK_MENU_SHELL(submenu_votrechoix), submenu_item3);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item2), submenu_votrechoix);

    // --- Sous-menu horizontal pour "Sous Choix2" ---
    GtkWidget *submenu_horiz = gtk_menu_new();
    GtkWidget *submenu_horiz_item1 = gtk_menu_item_new_with_label("Choix21");
    GtkWidget *submenu_horiz_item2 = gtk_menu_item_new_with_label("Choix22");
    GtkWidget *submenu_horiz_item3 = gtk_menu_item_new_with_label("Choix23");

    int x=0,y=1;
    gtk_menu_attach(GTK_MENU(submenu_horiz), submenu_horiz_item1,x++,y++,0,1);
    gtk_menu_attach(GTK_MENU(submenu_horiz), submenu_horiz_item2,x++,y++,0,1);
    gtk_menu_attach(GTK_MENU(submenu_horiz), submenu_horiz_item3,x++,y++,0,1);

    //--sous menu hrizontal pour le sous  choix 1
    GtkWidget *submenu_horiz1 = gtk_menu_new();
    GtkWidget *submenu_horiz_item11 = gtk_menu_item_new_with_label("Choix11");
    GtkWidget *submenu_horiz_item12 = gtk_menu_item_new_with_label("Choix12");
    GtkWidget *submenu_horiz_item13 = gtk_menu_item_new_with_label("Choix13");

    x=0;y=1;
    gtk_menu_attach(GTK_MENU(submenu_horiz1), submenu_horiz_item11,x++,y++,0,1);
    gtk_menu_attach(GTK_MENU(submenu_horiz1), submenu_horiz_item12,x++,y++,0,1);
    gtk_menu_attach(GTK_MENU(submenu_horiz1), submenu_horiz_item13,x++,y++,0,1);

    //sous menu horizontal pour le sous choix 3
    GtkWidget *submenu_horiz3 = gtk_menu_new();
    GtkWidget *submenu_horiz_item31 = gtk_menu_item_new_with_label("Choix31");
    GtkWidget *submenu_horiz_item32 = gtk_menu_item_new_with_label("Choix32");
    GtkWidget *submenu_horiz_item33 = gtk_menu_item_new_with_label("Choix33");

    x=0;y=1;
    gtk_menu_attach(GTK_MENU(submenu_horiz3), submenu_horiz_item31,x++,y++,0,1);
    gtk_menu_attach(GTK_MENU(submenu_horiz3), submenu_horiz_item32,x++,y++,0,1);
    gtk_menu_attach(GTK_MENU(submenu_horiz3), submenu_horiz_item33,x++,y++,0,1);


/*------------------------------------------------------------------------------------------------------------*/

    //Sous-menu horizontal pour "mon coix"
    GtkWidget *submenu_monchoix = gtk_menu_new();
    GtkWidget *submenu_item11 = gtk_menu_item_new_with_label("Sous Choix1");
    GtkWidget *submenu_item12 = gtk_menu_item_new_with_label("Sous Choix2");
    GtkWidget *submenu_item13 = gtk_menu_item_new_with_label("Sous Choix3");

    // Ajout des éléments au sous-menu horizontal
    gtk_menu_shell_append(GTK_MENU_SHELL(submenu_monchoix), submenu_item11);
    gtk_menu_shell_append(GTK_MENU_SHELL(submenu_monchoix), submenu_item12);
    gtk_menu_shell_append(GTK_MENU_SHELL(submenu_monchoix), submenu_item13);

    // gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item1), submenu_monchoix);

    //sous-menu horizontal pour "leurchiox
    GtkWidget *submenu_leurchoix = gtk_menu_new();
    GtkWidget *submenu_item31 = gtk_menu_item_new_with_label("Sous Choix1");
    GtkWidget *submenu_item32 = gtk_menu_item_new_with_label("Sous Choix2");
    GtkWidget *submenu_item33 = gtk_menu_item_new_with_label("Sous Choix3");

    // Ajout des éléments au sous-menu horizontal
    gtk_menu_shell_append(GTK_MENU_SHELL(submenu_leurchoix), submenu_item31);
    gtk_menu_shell_append(GTK_MENU_SHELL(submenu_leurchoix), submenu_item32);
    gtk_menu_shell_append(GTK_MENU_SHELL(submenu_leurchoix), submenu_item33);
    
    // gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item3), submenu_leurchoix);
    
/**************************************************************************************************************** */



    // Connexion du signal "activate" pour afficher le sous-menu horizontal
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(submenu_item2), submenu_horiz);
    // gtk_menu_item_set_submenu(GTK_MENU_ITEM(submenu_item1), submenu_horiz1);
    // gtk_menu_item_set_submenu(GTK_MENU_ITEM(submenu_item3), submenu_horiz3);




    return menu_bar;
}
