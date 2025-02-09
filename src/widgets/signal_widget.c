#include "../../include/widgets/signal_widget.h"

GtkWidget *create_signal() {
    GtkWidget *label = gtk_label_new("Ceci est un signal GTK !");
    return label;
}
