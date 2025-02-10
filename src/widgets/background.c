#include "../../include/widgets/background.h"

void set_background(GtkWidget *window, const gchar *image_path)
{
    /* Créer un GtkOverlay */
    GtkWidget *overlay = gtk_overlay_new();

    /* Créer l'image de fond */
    GtkWidget *background = gtk_image_new_from_file(image_path);

    /* S'assurer que l'image remplit la fenêtre */
    gtk_widget_set_halign(background, GTK_ALIGN_FILL);
    gtk_widget_set_valign(background, GTK_ALIGN_FILL);
    gtk_widget_set_hexpand(background, TRUE);
    gtk_widget_set_vexpand(background, TRUE);

    /* Ajouter l'image de fond à l'overlay */
    gtk_overlay_add_overlay(GTK_OVERLAY(overlay), background);

    /* Ajouter l'overlay à la fenêtre */
    gtk_container_add(GTK_CONTAINER(window), overlay);

    /* Appliquer l'overlay comme arrière-plan */
    gtk_widget_show_all(window);
}
