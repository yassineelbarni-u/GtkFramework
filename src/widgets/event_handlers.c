#include "../../include/widgets/event_handlers.h"

gboolean show_image_dialog(GtkWidget *parent) {
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(parent),
                                               GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                               GTK_MESSAGE_QUESTION,
                                               GTK_BUTTONS_YES_NO,
                                               "Voulez-vous afficher une image ?");
    
    gtk_dialog_add_button(GTK_DIALOG(dialog), "Annuler", GTK_RESPONSE_CANCEL);
    gtk_window_move(GTK_WINDOW(dialog), 700, 500);

    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    if (response == GTK_RESPONSE_YES) {
        GtkWidget *image_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(image_window), "Image");
        gtk_window_set_default_size(GTK_WINDOW(image_window), 400, 300);

        GtkWidget *image = gtk_image_new_from_file("assets/ma.png");
        gtk_container_add(GTK_CONTAINER(image_window), image);

        gtk_window_move(GTK_WINDOW(image_window), 400, 300);
        gtk_widget_show_all(image_window);
    } else if (response == GTK_RESPONSE_NO) {
        g_print("L'utilisateur a cliqué sur Non\n");
    } else if (response == GTK_RESPONSE_CANCEL) {
        g_print("L'utilisateur a annulé\n");
    }

    return FALSE;  // Correction pour éviter l'erreur de type
}

// ✅ Correction des avertissements
void on_ok_button_clicked(GtkWidget *widget, gpointer data) {
    (void)widget; // Éviter l'avertissement
    (void)data;   // Éviter l'avertissement

    GtkWidget *new_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(new_window), "Nouvelle Fenêtre");
    gtk_window_set_default_size(GTK_WINDOW(new_window), 400, 300);

    GtkWidget *label = gtk_label_new("Bienvenue dans la nouvelle fenêtre !");
    gtk_container_add(GTK_CONTAINER(new_window), label);

    gtk_widget_show_all(new_window);
}

void on_quit_button_clicked(GtkWidget *widget, gpointer data) {
    (void)widget; // Éviter l'avertissement

    GApplication *app = G_APPLICATION(data);
    g_application_quit(app);
}
