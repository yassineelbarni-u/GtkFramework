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



static void activate(GtkApplication *app, gpointer data)
{
    // let only the project you want to run
    // comment the others

    // after choosing the project all you want to do is to run the program


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

  GtkWidget *fixed = create_fixed();
 
    


    add_to_fixed(fixed, frame_button_radio, 20, 200);
    add_to_fixed(fixed, frame_button_check, 20, 300);
    add_to_fixed(fixed, macal->calendar, 20, 400);
    add_to_fixed(fixed, frame_button_radio11, 400, 700);
    add_to_fixed(fixed, LDR1->combobox, 20, 650);


    

    GtkWidget *window = create_window(app, GTK_WINDOW_TOPLEVEL, "Password", 800, 600, TRUE, GTK_WIN_POS_CENTER, TRUE, NULL, 1.0, FALSE);

    add_to_container(window, fixed);

    show_widget(window);
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