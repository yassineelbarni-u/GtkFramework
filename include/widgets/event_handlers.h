#ifndef EVENT_HANDLERS_H
#define EVENT_HANDLERS_H

#include <gtk/gtk.h>

void on_ok_button_clicked(GtkWidget *widget, gpointer data);
void on_quit_button_clicked(GtkWidget *widget, gpointer data);

// Correction du type pour correspondre à `event_handlers.c`
gboolean show_image_dialog(GtkWidget *parent);

#endif // EVENT_HANDLERS_H
