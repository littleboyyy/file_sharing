#include "home.h"
#include "ui_define.h"

int main (int    argc,
      char **argv)
{
  int status;
  
  Window *win = malloc(sizeof(*win));

  win->app = gtk_application_new ("com.gtk.myapp", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (win->app, "activate", G_CALLBACK (activate), win);
  status = g_application_run (G_APPLICATION (win->app), argc, argv);
  g_object_unref (win->app);
  free(win);

  return status;
}
