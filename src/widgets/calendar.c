#include "../../include/widgets/calendar.h"
#include <stdlib.h>
#include <stdio.h>

Calander *allouerCalander() {
    Calander *macal;
    macal = (Calander*) malloc(sizeof(Calander));
    if (!macal) {
        printf("Erreur memoire insuffisante");
        exit(-1);
    }
    macal->calendar = NULL;
    return macal;
}

Calander *crer_calendr(Calander *macal) {
    if (!macal) {
        printf("\nErreur liste des calander est null");
        exit(-1);
    }
    macal->calendar = gtk_calendar_new();
    return macal;
}