#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <gtk/gtk.h>

typedef struct Label {
    char titre[50];
} Label;

typedef struct listechoix {
    Label *text;
    struct listechoix *svt;
} listechoix;

typedef struct {
    GtkWidget *combobox;
    listechoix *choix;
    int index; // choix initiale
} Liste_deroul;

Liste_deroul *allouerListe_deroul();
listechoix *creer_choix(char choix[10]);
listechoix *inserer_choix(listechoix *list, char choix[10]);
void listeDR(Liste_deroul *LD);

#endif // COMBOBOX_H