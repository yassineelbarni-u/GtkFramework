#include "../../include/widgets/combobox.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Liste_deroul *allouerListe_deroul() {
    Liste_deroul *listeDeroul;
    listeDeroul = (Liste_deroul*) malloc(sizeof(Liste_deroul));
    if (!listeDeroul) {
        printf("Erreur memoire insuffisante");
        exit(-1);
    }
    listeDeroul->combobox = NULL;
    listeDeroul->choix = NULL;
    return listeDeroul;
}

listechoix *creer_choix(char choix[10]) {
    listechoix *NE = (listechoix*) malloc(sizeof(listechoix));
    if (!NE) {
        printf("erreur d'allocation memoire!!\n");
        exit(-1);
    }
    NE->text = (Label*) malloc(sizeof(Label));
    strcpy(NE->text->titre, choix);
    NE->svt = NULL;
    return NE;
}

listechoix *inserer_choix(listechoix *list, char choix[10]) {
    listechoix *NE = creer_choix(choix);
    listechoix *pcrt;
    if (!list)
        return NE;
    pcrt = list;
    while (pcrt->svt)
        pcrt = pcrt->svt;
    pcrt->svt = NE;
    return list;
}

void listeDR(Liste_deroul *LD) {
    listechoix *pt;
    if (!LD) {
        printf("\nErreur l'objet de listech est null");
        exit(-1);
    }
    LD->combobox = gtk_combo_box_text_new();
    pt = LD->choix;
    while (pt) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(LD->combobox), pt->text->titre);
        pt = pt->svt;
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(LD->combobox), LD->index);
}