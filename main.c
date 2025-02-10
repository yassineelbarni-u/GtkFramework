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
 
 /**
  * @brief Fonction d'activation de l'application GTK
  */
 static void activate(GtkApplication *app, gpointer data)
 {
     (void)data;
 
     /* Création de la fenêtre principale */
     GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "Test des fonctions GTK+", 900, 950, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1, FALSE);
     
     /* Création d'un conteneur fixed */
     GtkWidget *fixed = create_fixed();
 
     /* =================== Menu déroulant =================== */
     GtkWidget *sous_menu = gtk_event_box_new();
     GtkWidget *menu_bar = create_menu_deroulant(window);
     gtk_container_add(GTK_CONTAINER(sous_menu), menu_bar);
     add_to_fixed(fixed, sous_menu, 20, 20); // Position X=20, Y=20
 
     /* =================== HeaderBar =================== */
     GtkWidget *header = create_header_bar("test des fonctions GTK+", "", "assets/home.png", TRUE);
     add_header_bar_to_window(window, header);
 
     /* =================== Scrollable Window =================== */
     GtkWidget *window1 = create_scrolled_window(TRUE, TRUE);
     add_to_scrolled_window(window1, fixed);
     add_to_container(window, window1);
 
     /* =================== Radio Buttons - Connaissance GTK+ =================== */
     GtkWidget *radio1 = create_radio_button("Faible", NULL, NULL, FALSE);
     GtkWidget *radio2 = create_radio_button("Moyen", NULL, radio1, FALSE);
     GtkWidget *radio3 = create_radio_button("Fort", NULL, radio1, FALSE);
     GtkWidget *radio4 = create_radio_button("Très fort", NULL, radio1, TRUE);
 
     GtkWidget *grid = create_grid(0, 10, FALSE, TRUE);
     add_to_grid(grid, radio1, 0, 0, 1, 1);
     add_to_grid(grid, radio2, 0, 1, 1, 1);
     add_to_grid(grid, radio3, 0, 2, 1, 1);
     add_to_grid(grid, radio4, 0, 3, 1, 1);
 
     GtkWidget *frame_button_radio = create_frame("Votre connaissance de GTK+", 0, 1);
     add_to_frame(frame_button_radio, grid, 0, 0, 10, 10);
     
     add_to_fixed(fixed, frame_button_radio, 20, 200);
 
     /* =================== Check Buttons - Commentaires GTK3 =================== */
     GtkWidget *check1 = create_check_button("Convivial", FALSE, FALSE, NULL, NULL);
     GtkWidget *check2 = create_check_button("Intéressant", FALSE, FALSE, NULL, NULL);
     GtkWidget *check3 = create_check_button("Facile à utiliser", FALSE, FALSE, NULL, NULL);
     GtkWidget *check4 = create_check_button("Optimale", FALSE, FALSE, NULL, NULL);
 
     GtkWidget *grid1 = create_grid(0, 10, FALSE, TRUE);
     add_to_grid(grid1, check1, 0, 0, 1, 1);
     add_to_grid(grid1, check2, 0, 1, 1, 1);
     add_to_grid(grid1, check3, 0, 2, 1, 1);
     add_to_grid(grid1, check4, 0, 3, 1, 1);
 
     GtkWidget *frame_button_check = create_frame("Vos commentaires sur GTK3", 0, 1);
     add_to_frame(frame_button_check, grid1, 0, 0, 10, 10);
 
     /* =================== Radio Buttons - État de santé =================== */
     GtkWidget *radio11 = create_radio_button("Malade", NULL, NULL, FALSE);
     GtkWidget *radio21 = create_radio_button("Suspect", NULL, radio11, FALSE);
     GtkWidget *radio31 = create_radio_button("Guéri", NULL, radio11, FALSE);
     GtkWidget *radio41 = create_radio_button("Sain", NULL, radio11, TRUE);
 
     GtkWidget *grid2 = create_grid(0, 10, FALSE, TRUE);
     add_to_grid(grid2, radio11, 0, 0, 1, 1);
     add_to_grid(grid2, radio21, 0, 1, 1, 1);
     add_to_grid(grid2, radio31, 0, 2, 1, 1);
     add_to_grid(grid2, radio41, 0, 3, 1, 1);
 
     GtkWidget *frame_button_radio11 = create_frame("Votre état de santé", 0, 1);
     add_to_frame(frame_button_radio11, grid2, 0, 0, 10, 10);
 
     /* =================== Calendar Widget =================== */
     Calander *macal = allouerCalander();
     macal = crer_calendr(macal);


 
     /* =================== Combo Box Widget =================== */
     Liste_deroul *LDR1 = allouerListe_deroul();
     LDR1->choix = inserer_choix(LDR1->choix, "choix1");
     LDR1->choix = inserer_choix(LDR1->choix, "choix2");
     LDR1->choix = inserer_choix(LDR1->choix, "choix3");
     LDR1->choix = inserer_choix(LDR1->choix, "choix4");
     LDR1->index = 2;
     listeDR(LDR1);
 
     /* =================== Boutons avec images =================== */
      // Create the images for the buttons
    GtkWidget *image_ok = gtk_image_new_from_file("assets/ma.png");
    GtkWidget *image_quitter = gtk_image_new_from_file("assets/home.png");

    // Check if images are loaded correctly
    if (!image_ok) {
        g_printerr("Error loading image 'assets/ma.png'\n");
    }
    if (!image_quitter) {
        g_printerr("Error loading image 'assets/home.png'\n");
    }

    // Create the buttons
    GtkWidget *button = create_button(GTK_RELIEF_NORMAL, "OK", FALSE, NULL, NULL, NULL);
    GtkWidget *button2 = create_button(GTK_RELIEF_NORMAL, "Quitter", FALSE, NULL, NULL, NULL);

    // Set the images to the buttons
    gtk_button_set_image(GTK_BUTTON(button), image_ok);
    gtk_button_set_image(GTK_BUTTON(button2), image_quitter);

    // Ensure the buttons show the images
    gtk_button_set_always_show_image(GTK_BUTTON(button), TRUE);
    gtk_button_set_always_show_image(GTK_BUTTON(button2), TRUE);

    // Connect the buttons to the callback functions
    g_signal_connect(button, "clicked", G_CALLBACK(on_ok_button_clicked), NULL);
    g_signal_connect(button2, "clicked", G_CALLBACK(on_quit_button_clicked), app);
    
    
    add_to_fixed(fixed, button, 400, 850);
    add_to_fixed(fixed, button2, 500, 850);

 
     /* =================== Sélecteur de date =================== */
     GtkWidget *frame_date = gtk_frame_new("Sélectionnez une date");
     create_date_selector(frame_date);
     add_to_fixed(fixed, frame_date, 20, 400);
 
     /* =================== Ajout des widgets au conteneur fixed =================== */
     
     add_to_fixed(fixed, frame_button_check, 20, 300);
     add_to_fixed(fixed, LDR1->combobox, 20, 650);
     add_to_fixed(fixed, frame_button_radio11, 400, 700);
  
 
     /* Affichage de la fenêtre */
     show_widget(window);
     g_idle_add((GSourceFunc)show_image_dialog, window);
 }
 
 /**
  * @brief Fonction principale
  */
 int main(int argc, char **argv)
 {
     GtkApplication *app = gtk_application_new("id.gtk", G_APPLICATION_DEFAULT_FLAGS);
     g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
     int status = g_application_run(G_APPLICATION(app), argc, argv);
     g_object_unref(app);
     return status;
 }
 