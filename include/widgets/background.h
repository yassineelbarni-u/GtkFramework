/*****************************************************************************************************************************
 * 
 * @file background.h
 * @brief Header file for managing the background image in a GTK window.
 * 
 * This file contains the macro and function declarations to set a background image
 * for the main window.
 * 
 * @author Ayyoub el Kouri
 * @date 24/01/2025
 * @version 1.0
 * 
 ****************************************************************************************************************************/

 #ifndef BACKGROUND_H
 #define BACKGROUND_H
 
 #include <gtk/gtk.h>
 
 #ifdef __cplusplus
 extern "C" {
 #endif
 
 /* Macro to set the background image */
 #define SET_BACKGROUND(window, image_path) set_background(window, image_path)
 
 /**
  * @brief Sets a background image for a GTK window using GtkOverlay.
  * 
  * @param window The GTK main window.
  * @param image_path The file path of the background image.
  */
 void set_background(GtkWidget *window, const gchar *image_path);
 
 #ifdef __cplusplus
 }
 #endif
 
 #endif // BACKGROUND_H
 