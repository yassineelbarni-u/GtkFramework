#include "../../include/widgets/date_selector.h"

void create_date_selector(GtkWidget *container) {
    GtkWidget *combo_day = gtk_combo_box_text_new();
    GtkWidget *combo_month = gtk_combo_box_text_new();
    GtkWidget *combo_year = gtk_combo_box_text_new();

    // Remplissage des jours (1-31)
    for (int i = 1; i <= 31; i++) {
        char str[3];
        sprintf(str, "%02d", i);
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_day), str);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo_day), 0);

    // Remplissage des mois (1-12)
    for (int i = 1; i <= 12; i++) {
        char str[3];
        sprintf(str, "%02d", i);
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_month), str);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo_month), 0);

    // Remplissage des années (2000 - 2030)
    for (int i = 2000; i <= 2030; i++) {
        char str[5];
        sprintf(str, "%d", i);
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_year), str);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo_year), 10);

    // Conteneur horizontal
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(hbox), gtk_label_new("Jour :"), FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox), combo_day, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox), gtk_label_new("Mois :"), FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox), combo_month, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox), gtk_label_new("Année :"), FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hbox), combo_year, FALSE, FALSE, 5);

    gtk_container_add(GTK_CONTAINER(container), hbox);
}
