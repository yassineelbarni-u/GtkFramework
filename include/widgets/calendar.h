#ifndef CALENDAR_H
#define CALENDAR_H

#include <gtk/gtk.h>

typedef struct {
    GtkWidget *calendar;
} Calander;

Calander *allouerCalander();
Calander *crer_calendr(Calander *macal);

#endif // CALENDAR_H