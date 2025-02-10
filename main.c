/******************************************************************************************************************************
 * 
 * @project: GTK3 project
 * @file main.c
 * @brief the main file of the project
 * 
 * This file contains the main function of the project.
 * 
 * @author Ayyoub el kouri
 * @date 20/01/2025
 * @version 1.0 (last update 27/01/2025)
 * 
 *****************************************************************************************************************************/

#include <gtk/gtk.h>
#include "include/GtkFramework/GtkFramework.h"
// #include "DossierForTesting/test_project_1/project_header.h"
#include "DossierForTesting/test_project_2/project_header_2.h"
#include "XML/xml_style.h"


void on_ok_button_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *new_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(new_window), "Nouvelle Fenêtre");
    gtk_window_set_default_size(GTK_WINDOW(new_window), 400, 300);

    GtkWidget *label = gtk_label_new("Bienvenue dans la nouvelle fenêtre !");
    gtk_container_add(GTK_CONTAINER(new_window), label);

    gtk_widget_show_all(new_window);
}

void on_quit_button_clicked(GtkWidget *widget, gpointer data) {
    GApplication *app = G_APPLICATION(data);  // Convertir le `gpointer` en `GApplication`
    g_application_quit(app);  // 📌 Quitter proprement l'application GtkApplication
}

void show_image_dialog(GtkWidget *parent) {
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(GTK_WINDOW(parent),
                                    GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_QUESTION,
                                    GTK_BUTTONS_YES_NO,
                                    "Voulez-vous afficher une image ?");
    
    // Ajouter un bouton "Annuler"
    gtk_dialog_add_button(GTK_DIALOG(dialog), "Annuler", GTK_RESPONSE_CANCEL);

    // 📌 Déplacer la boîte de dialogue (Position X=300, Y=200)
    gtk_window_move(GTK_WINDOW(dialog), 700, 500);

    // Afficher la boîte de dialogue et récupérer la réponse de l'utilisateur
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    // Gérer la réponse de l'utilisateur
    if (response == GTK_RESPONSE_YES) {
        g_print("L'utilisateur a cliqué sur Oui\n");
        
        // Ouvre une fenêtre avec l'image si nécessaire
        GtkWidget *image_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(image_window), "Image");
        gtk_window_set_default_size(GTK_WINDOW(image_window), 400, 300);

        GtkWidget *image = gtk_image_new_from_file("assets/ma.png");
        gtk_container_add(GTK_CONTAINER(image_window), image);

        // 📌 Déplacer la fenêtre d'image (Position X=400, Y=300)
        gtk_window_move(GTK_WINDOW(image_window), 400, 300);

        gtk_widget_show_all(image_window);
    } else if (response == GTK_RESPONSE_NO) {
        g_print("L'utilisateur a cliqué sur Non\n");
    } else if (response == GTK_RESPONSE_CANCEL) {
        g_print("L'utilisateur a annulé\n");
    }
}


static void activate(GtkApplication *app, gpointer data)
{
    (void)data;
    // let only the project you want to run
    // comment the others

    // after choosing the project all you want to do is to run the program
       
      

        // Création de la fenêtre principale
        GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "Test des fonctions GTK+", 900, 950, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE);
        
        // Création d'un conteneur de type fixed
        GtkWidget *fixed = create_fixed();

      
    // Solution : Utiliser `GtkEventBox` pour encapsuler `GtkMenuBar`
    GtkWidget *menu_eventbox = gtk_event_box_new();
    GtkWidget *menu_bar = create_menu_deroulant(window);
    gtk_container_add(GTK_CONTAINER(menu_eventbox), menu_bar);


        // Création d'un HeaderBar pour centrer le titre
        GtkWidget *header = create_header_bar("test des fonctions GTK+", "", "assets/home.png", TRUE);
        add_header_bar_to_window(window, header);
    
        GtkWidget *window1 = create_scrolled_window(TRUE, TRUE);
        add_to_scrolled_window(window1, fixed);
        add_to_container(window, window1);
    



    //creation de la widgets de radio button
    GtkWidget *radio1 = create_radio_button("Faible", NULL, NULL, FALSE);
    GtkWidget *radio2 = create_radio_button("Moyen", NULL, radio1, FALSE);
    GtkWidget *radio3 = create_radio_button("Fort", NULL, radio1, FALSE);
    GtkWidget *radio4 = create_radio_button("Très fort", NULL, radio1, TRUE);

    GtkWidget *grid = create_grid(0, 10, FALSE, TRUE);

    add_to_grid(grid, radio1, 0, 0, 1, 1);
    add_to_grid(grid, radio2, 0, 1, 1, 1);
    add_to_grid(grid, radio3, 0, 2, 1, 1);
    add_to_grid(grid, radio4, 0, 3, 1, 1);

    GtkWidget *frame_button_radio = create_frame("Votre connaissance de gtk+", 0, 1);
    add_to_frame(frame_button_radio, grid, 0, 0, 10, 10);

      //creation de la widgets de check button
      GtkWidget *check1 = create_check_button("convaivial", FALSE, FALSE, NULL, NULL);
      GtkWidget *check2 = create_check_button("interessant", FALSE, FALSE, NULL, NULL);
      GtkWidget *check3 = create_check_button("facile a utiliser", FALSE, FALSE, NULL, NULL);
      GtkWidget *check4 = create_check_button("optimale", FALSE, FALSE, NULL, NULL);
      
      GtkWidget *grid1 = create_grid(0, 10, FALSE, TRUE);

      add_to_grid(grid1, check1, 0, 0, 1, 1);
      add_to_grid(grid1, check2, 0, 1, 1, 1);
      add_to_grid(grid1, check3, 0, 2, 1, 1);
      add_to_grid(grid1, check4, 0, 3, 1, 1);

      GtkWidget *frame_button_check = create_frame("Vos commentaires Sur GTK3", 0, 1);
      add_to_frame(frame_button_check, grid1, 0, 0, 10, 10);



    //creation de la widgets de radio button
    GtkWidget *radio11 = create_radio_button("Malade", NULL, NULL, FALSE);
    GtkWidget *radio21 = create_radio_button("Suspect", NULL, radio11, FALSE);
    GtkWidget *radio31 = create_radio_button("Gueri", NULL, radio11, FALSE);
    GtkWidget *radio41 = create_radio_button("sain", NULL, radio11, TRUE);

    GtkWidget *grid2 = create_grid(0, 10, FALSE, TRUE);

    add_to_grid(grid2, radio11, 0, 0, 1, 1);
    add_to_grid(grid2, radio21, 0, 1, 1, 1);
    add_to_grid(grid2, radio31, 0, 2, 1, 1);
    add_to_grid(grid2, radio41, 0, 3, 1, 1);

    GtkWidget *frame_button_radio11 = create_frame("Votre etat de sante", 0, 1);
    add_to_frame(frame_button_radio11, grid2, 0, 0, 10, 10);

    
       // Create and add the calendar widget
       Calander *macal = allouerCalander();
       macal = crer_calendr(macal);

  // Create and add the combo box widget
  Liste_deroul *LDR1 = allouerListe_deroul();
  LDR1->choix = inserer_choix(LDR1->choix, "choix1");
  LDR1->choix = inserer_choix(LDR1->choix, "choix2");
  LDR1->choix = inserer_choix(LDR1->choix, "choix3");
  LDR1->choix = inserer_choix(LDR1->choix, "choix4");
  LDR1->index = 2;
  listeDR(LDR1);
   
    //creation de la widgets de switch button
    // GtkWidget *switch_button = create_switch_button(TRUE, NULL, NULL);

    // add_to_fixed(fixed, switch_button, 200, 300); // Position X=20, Y=20

    //creation spin button

    // GtkWidget *spin_button = create_spin_button(0, 100, 1, 50, 0, FALSE, FALSE);
    // add_to_fixed(fixed, spin_button, 600, 300); // Position X=20, Y=20
    

/*-------widgets des image dans une button et chaque button lorsque est clicke doit affichier une event-----------*/
    // creation des images pour les boutons
    GtkWidget *image_ok = gtk_image_new_from_file("assets/ma.png");
    GtkWidget *image_quitter = gtk_image_new_from_file("assets/home.png");

    //verifier si les images sont bien chargees
    if (!image_ok) {
        g_printerr("Error loading image 'assets/ma.png'\n");
    }
    if (!image_quitter) {
        g_printerr("Error loading image 'assets/home.png'\n");
    }

    // creation des buttons
    GtkWidget *button = create_button(GTK_RELIEF_NORMAL, "OK", FALSE, NULL,NULL, NULL);
    GtkWidget *button2 = create_button(GTK_RELIEF_NORMAL, "quitter", FALSE, NULL, NULL, NULL);

    // mettre les images dans les buttons
    gtk_button_set_image(GTK_BUTTON(button), image_ok);
    gtk_button_set_image(GTK_BUTTON(button2), image_quitter);

    // afficher les images meme si les buttons sont desactives
    gtk_button_set_always_show_image(GTK_BUTTON(button), TRUE);
    gtk_button_set_always_show_image(GTK_BUTTON(button2), TRUE);

    GtkWidget *singal = create_signal();
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(on_ok_button_clicked), NULL);
    g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(on_quit_button_clicked), app);
    



    // Add the buttons to the fixed container
    add_to_fixed(fixed, button, 400, 850); // Position X=400, Y=850
    add_to_fixed(fixed, button2, 500, 850); // Position X=500, Y=850
/*----------------------------------------------------------------------------------------------------------------*/
    // ajouter les widgets au conteneur fixed
    add_to_fixed(fixed, menu_eventbox, 20, 20); // Position X=20, Y=20
    add_to_fixed(fixed, frame_button_radio, 20, 200);
    add_to_fixed(fixed, frame_button_check, 20, 300);
    add_to_fixed(fixed, macal->calendar, 20, 400);
    add_to_fixed(fixed, LDR1->combobox, 20, 650);
    add_to_fixed(fixed, frame_button_radio11, 400, 700);
    

    show_widget(window);
    
    g_idle_add((GSourceFunc)show_image_dialog, window);
}


int main(int argc, char **argv)
{
    GtkApplication *app = gtk_application_new("id.gtk", G_APPLICATION_DEFAULT_FLAGS);
    int status = 0;
    // arg myarg;
    // myarg.argc = argc;
    // myarg.argv = argv;
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}