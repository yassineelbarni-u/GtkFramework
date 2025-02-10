#include "../../include/widgets/level_bar.h"

GtkWidget *create_level_bar(gdouble min_value, gdouble max_value, gdouble default_value, GtkLevelBarMode mode, gboolean inverted)
{
    levelBarInfos *levelBarInformation = (levelBarInfos *)malloc(sizeof(levelBarInfos));
    if (!levelBarInformation) return NULL;

    levelBarInformation->min_value = min_value;
    levelBarInformation->max_value = max_value;
    levelBarInformation->default_value = default_value;
    levelBarInformation->mode = mode;
    levelBarInformation->inverted = inverted;

    GtkWidget *levelBar = set_properties_level_bar(levelBarInformation);
    free(levelBarInformation);

    return levelBar;
}

GtkWidget *set_properties_level_bar(levelBarInfos *levelBarInformation)
{
    // create the level bar with the min and max values
    GtkWidget *levelBar = gtk_level_bar_new_for_interval(levelBarInformation->min_value, levelBarInformation->max_value);

    // set the default value
    gtk_level_bar_set_value(GTK_LEVEL_BAR(levelBar), levelBarInformation->default_value);

    // set the mode of the level bar
    gtk_level_bar_set_mode(GTK_LEVEL_BAR(levelBar), levelBarInformation->mode);

    // set the inverted of the level bar
    if (levelBarInformation->inverted)
        gtk_level_bar_set_inverted(GTK_LEVEL_BAR(levelBar), TRUE);

    return levelBar;
}