#include "ui_define.h"

#define USERNAME "1"
#define PASSWORD "1"

void
activate (GtkApplication* app,
			Window *win)
{
  GtkWidget *button,*button_1;
  GtkWidget *label_user;
  GtkWidget *label_pass;
  Window *win1;
  win1 = win;
  
  //create window
  win1->window = gtk_application_window_new (win1->app);
  gtk_window_set_title (GTK_WINDOW (win1->window), "Log In");
  gtk_window_set_default_size (GTK_WINDOW (win1->window), 320, 200);

  //create grid
  win1->grid = gtk_grid_new ();
  gtk_window_set_child (GTK_WINDOW (win1->window), win1->grid);
  
  //label
  label_user = gtk_label_new("Username  ");
  gtk_grid_attach(GTK_GRID(win1->grid), label_user, 0, 1, 1, 1);
  label_pass = gtk_label_new("Password  ");
  gtk_grid_attach(GTK_GRID(win1->grid), label_pass, 0, 2, 1, 1);
  
  //insert field
  win1->u_name = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(win1->u_name), "Username");
  gtk_grid_attach(GTK_GRID(win1->grid), win1->u_name, 1, 1, 1, 1);

  win1->pass = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(win1->pass), "Password");
  gtk_entry_set_visibility(GTK_ENTRY(win1->pass), 0);//hide password
  gtk_grid_attach(GTK_GRID(win1->grid), win1->pass, 1, 2, 1, 1);
  
  //button login
  button = gtk_button_new_with_label ("\nLog In\n");
  gtk_grid_attach(GTK_GRID(win1->grid), button, 1, 3, 1, 1);
  g_signal_connect (button, "clicked", G_CALLBACK (Login), win1);//G_CALLBACK (Login) goi ham login
  
  //button signup
  button_1 = gtk_button_new_with_label ("Sign Up");
  gtk_grid_attach(GTK_GRID(win1->grid), button_1, 1, 6, 1, 1);
  g_signal_connect_swapped(button_1, "clicked", G_CALLBACK(gtk_window_destroy), win1->window);
  g_signal_connect (button_1, "clicked", G_CALLBACK (activate_1), win1);
  
  gtk_widget_show (win1->window);
}

void activate_1 (GtkWidget *b, Window *win)
{
  GtkWidget *button,*button_1;
  GtkWidget *label_1,*label_2,*label_3,*label_4,*label_5,*label_6,*re_pass;
  Window *win1;
  win1 = win;
  
  //create window
  win1->window = gtk_application_window_new (win1->app);
  gtk_window_set_title (GTK_WINDOW (win1->window), "Sign Up");
  gtk_window_set_default_size (GTK_WINDOW (win1->window), 640, 400);

  //create grid
  win1->grid = gtk_grid_new ();
  gtk_window_set_child (GTK_WINDOW (win1->window), win1->grid);
  
  //label
  label_1 = gtk_label_new("Username:\n");
  gtk_grid_attach(GTK_GRID(win1->grid), label_1, 0, 1, 1, 1);
  label_2 = gtk_label_new("Password:\n");
  gtk_grid_attach(GTK_GRID(win1->grid), label_2, 0, 2, 1, 1);
  label_3 = gtk_label_new("Re-Password:\n");
  gtk_grid_attach(GTK_GRID(win1->grid), label_3, 0, 3, 1, 1);
  label_4 = gtk_label_new("Name:\n");
  gtk_grid_attach(GTK_GRID(win1->grid), label_4, 0, 4, 1, 1);
  label_5 = gtk_label_new("Email:\n");
  gtk_grid_attach(GTK_GRID(win1->grid), label_5, 0, 5, 1, 1);
  label_6 = gtk_label_new("Phone:\n");
  gtk_grid_attach(GTK_GRID(win1->grid), label_6, 0, 6, 1, 1);
  
  //insert field
  win1->u_name = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(win1->u_name), "Username");
  gtk_grid_attach(GTK_GRID(win1->grid), win1->u_name, 1, 1, 1, 1);

  win1->pass = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(win1->pass), "Password");
  gtk_entry_set_visibility(GTK_ENTRY(win1->pass), 0);//hide password
  gtk_grid_attach(GTK_GRID(win1->grid), win1->pass, 1, 2, 1, 1);
  
  re_pass = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(re_pass), "Re-Password");
  gtk_entry_set_visibility(GTK_ENTRY(re_pass), 0);//hide password
  gtk_grid_attach(GTK_GRID(win1->grid), re_pass, 1, 3, 1, 1);
  
  win1->name = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(win1->name), "Name");
  gtk_grid_attach(GTK_GRID(win1->grid), win1->name, 1, 4, 1, 1);
  
  win1->email = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(win1->email), "Email");
  gtk_grid_attach(GTK_GRID(win1->grid), win1->email, 1, 5, 1, 1);
  
  win1->phone = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(win1->phone), "Phone");
  gtk_grid_attach(GTK_GRID(win1->grid), win1->phone, 1, 6, 1, 1);
  
  //button signup
  button = gtk_button_new_with_label ("\nSign Up\n");
  gtk_grid_attach(GTK_GRID(win1->grid), button, 1, 7, 1, 1);
  g_signal_connect (button, "clicked", G_CALLBACK (Signup), win1);
  
  //button login
  button_1 = gtk_button_new_with_label ("Log In");
  gtk_grid_attach(GTK_GRID(win1->grid), button_1, 1, 8, 1, 1);
  g_signal_connect_swapped(button_1, "clicked", G_CALLBACK(gtk_window_destroy), win1->window);
  g_signal_connect (button_1, "clicked", G_CALLBACK (activate), win1);
  
  gtk_widget_show (win1->window);
}

void
Login (GtkWidget *button, Window *win)
{
	Window *win1;
  	win1 = win;
  	
  	GtkWidget *label;
  	GtkWidget *grid;
  	GtkWidget *subwindow;
  
  	char username[30];
  	strncpy(username, gtk_editable_get_text(GTK_EDITABLE(win1->u_name)), sizeof(username)-1);
    //gtk_editable_get_text co kieu du lieu (* char)
  	username[sizeof(username)-1] = '\0';
  
  	char password[30];
  	strncpy(password, gtk_editable_get_text(GTK_EDITABLE(win1->pass)), sizeof(password)-1);
  	password[sizeof(password)-1] = '\0';
  
  	if (strcmp(username,USERNAME)==0 && strcmp(password,PASSWORD)==0)
	{
    	gtk_window_destroy(GTK_WINDOW(win1->window));
    	HomePage(username, win1);
	}

   	else if (strcmp(username,USERNAME)!=0 || strcmp(password,PASSWORD)!=0)
	{
	//new window
		gtk_widget_hide(win1->window);
		gtk_init ();
    	subwindow = gtk_window_new();
    	gtk_window_set_title (GTK_WINDOW (subwindow), "Login Error");
    //
    	grid = gtk_grid_new ();
   		gtk_window_set_child (GTK_WINDOW (subwindow), grid);
    
    	label = gtk_label_new("Username and Password is incorrect.");
    	gtk_grid_attach(GTK_GRID(grid), label, 0, 2, 1, 1);
    
    	button = gtk_button_new_with_label ("Retry");
    	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
    	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_show), win1->window);
    	gtk_grid_attach(GTK_GRID(grid), button, 1, 3, 1, 1);
    
    	gtk_widget_show (subwindow);
	}
return;
}

void Signup (GtkWidget *button,Window *win)
{
	char username[30];
  	strncpy(username, gtk_editable_get_text(GTK_EDITABLE(win->u_name)), sizeof(username)-1);
	HomePage(username, win);
}

void HomePage(char *username, Window *win)
{
	Window *win1;
  	win1 = win;
  	
	//1_Tao nhom 2_Tham gia nhom 3_Nhom da tham gia 4_Nhom cua ban
  	GtkWidget *button_1, *button_2, *button_3, *button_4, *label;
  
	win1->window = gtk_application_window_new (win1->app);
  	gtk_window_set_title (GTK_WINDOW (win1->window), "Home");
  	gtk_window_set_default_size (GTK_WINDOW (win1->window), 640, 400);
  	
  	win1->grid = gtk_grid_new ();
  	gtk_window_set_child (GTK_WINDOW (win1->window), win1->grid);
  
  	//label
  	label = gtk_label_new("  Hello!\n\t\t\t\t\t\t\t");
  	gtk_grid_attach(GTK_GRID(win1->grid), label, 1, 0, 1, 1);
  	
  	//button
  	button_1 = gtk_button_new_with_label("\t\t\t\nCreate Group\n\n");
  	gtk_grid_attach(GTK_GRID(win1->grid), button_1, 4, 1, 1, 1);
  	g_signal_connect(button_1, "clicked", G_CALLBACK(CreateGroup), win1);
  	
  	button_2 = gtk_button_new_with_label("\t\t\t\nJoin a Group\n\n");
  	gtk_grid_attach(GTK_GRID(win1->grid), button_2, 4, 2, 1, 1);
  	g_signal_connect(button_2, "clicked", G_CALLBACK(JoinGroup), win1);
  	
  	button_3 = gtk_button_new_with_label("\t\t\t\nView All Group\n\n");
  	gtk_grid_attach(GTK_GRID(win1->grid), button_3, 4, 3, 1, 1);
  	g_signal_connect(button_3, "clicked", G_CALLBACK(ViewGroup), win1);
  	
  	button_4 = gtk_button_new_with_label("\t\t\t\nLog Out\n\n");
  	gtk_grid_attach(GTK_GRID(win1->grid), button_4, 4, 4, 1, 1);
  	g_signal_connect(button_4, "clicked", G_CALLBACK(Logout), win1);
  	
  	gtk_widget_show (win1->window);
}

void CreateGroup(GtkWidget *button,Window *win)
{
	Window *win1;
    win1 = win;
    
	gtk_widget_hide(win1->window);
	GtkWidget *subgrid;
	GtkWidget *subwindow;
	GtkWidget *label, *label_1,*label_2,*gr_name,*desc,*button_1;
	
	//
	//Cua so nhap ten nhom, mo ta nhom
	//
    subwindow = gtk_application_window_new (win1->app);
    gtk_window_set_title (GTK_WINDOW (subwindow), "Create Group");
    gtk_window_set_default_size (GTK_WINDOW (subwindow), 640, 400);
    
	subgrid = gtk_grid_new ();
  	gtk_window_set_child (GTK_WINDOW (subwindow), subgrid);
  	
  	//label
  	label = gtk_label_new("Create Group!");
  	gtk_grid_attach(GTK_GRID(subgrid), label, 0, 0, 1, 1);
    label_1 = gtk_label_new("\nGroup Name:    ");
  	gtk_grid_attach(GTK_GRID(subgrid), label_1, 0, 2, 1, 1);
  	label_2 = gtk_label_new("\nDescription:    ");
  	gtk_grid_attach(GTK_GRID(subgrid), label_2, 0, 4, 1, 1);
  
 	//insert field
  	gr_name = gtk_entry_new();
  	gtk_entry_set_placeholder_text(GTK_ENTRY(gr_name), "Group Name\n");
  	gtk_grid_attach(GTK_GRID(subgrid), gr_name, 1, 3, 1, 1);

  	desc = gtk_entry_new();
  	gtk_entry_set_placeholder_text(GTK_ENTRY(desc), "Description...\n\n\n");
 	gtk_grid_attach(GTK_GRID(subgrid), desc, 1, 5, 1, 1);
 	
 	//button
	button = gtk_button_new_with_label ("Cancel");
	gtk_grid_attach(GTK_GRID(subgrid), button, 0, 8, 1, 1);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_show), win1->window);
    
    button_1 = gtk_button_new_with_label ("Next");
 	gtk_grid_attach(GTK_GRID(subgrid), button_1, 1, 8, 1, 1);
 	g_signal_connect_swapped(button_1, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
 	g_signal_connect(button_1, "clicked", G_CALLBACK(CreateGroup_addm), win1);
    
    gtk_widget_show (subwindow);
}

void JoinGroup(GtkWidget *button,Window *win)
{
	Window *win1;
    win1 = win;
    
	gtk_widget_hide(win1->window);
	GtkWidget *subgrid,*subgrid_1;
	GtkWidget *subwindow,*subwindow_1;
	GtkWidget *label, *label_1, *gr_name, *button_1,*button_2;
	
    subwindow = gtk_application_window_new (win1->app);
    gtk_window_set_title (GTK_WINDOW (subwindow), "Join a Group");
    gtk_window_set_default_size (GTK_WINDOW (subwindow), 640, 400);
    
	subgrid = gtk_grid_new ();
  	gtk_window_set_child (GTK_WINDOW (subwindow), subgrid);
  	
  	//label
  	label = gtk_label_new("Join a Group!");
  	gtk_grid_attach(GTK_GRID(subgrid), label, 0, 0, 1, 1);
    label_1 = gtk_label_new("\nEnter Group Code:    ");
  	gtk_grid_attach(GTK_GRID(subgrid), label_1, 0, 2, 1, 1);
  
 	//insert field
  	gr_name = gtk_entry_new();
  	gtk_entry_set_placeholder_text(GTK_ENTRY(gr_name), "Code...\n");
  	gtk_grid_attach(GTK_GRID(subgrid), gr_name, 1, 3, 1, 1);
 	
 	//button
	button = gtk_button_new_with_label ("Cancel");
	gtk_grid_attach(GTK_GRID(subgrid), button, 0, 8, 1, 1);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_show), win1->window);
    
    button_1 = gtk_button_new_with_label ("OK");
 	gtk_grid_attach(GTK_GRID(subgrid), button_1, 1, 8, 1, 1);
 	
 	/*
	int i; //thong bao thanh cong
	scanf("%d",i); 
 	if(i=1)//thanh cong
	 {
 		gtk_widget_hide(subwindow);
		gtk_init ();
    	subwindow_1 = gtk_window_new();
    	gtk_window_set_title (GTK_WINDOW (subwindow_1), "Succeed");
    	//
    	subgrid_1 = gtk_grid_new ();
    	gtk_window_set_child (GTK_WINDOW (subwindow_1), subgrid_1);
    
    	label_1 = gtk_label_new("Join group succeed!");
    	gtk_grid_attach(GTK_GRID(subgrid_1), label_1, 0, 2, 1, 1);
    
    	button_2 = gtk_button_new_with_label ("OK");
    	g_signal_connect_swapped(button_2, "clicked", G_CALLBACK(gtk_window_destroy), subwindow_1);
    	g_signal_connect_swapped(button_2, "clicked", G_CALLBACK(gtk_widget_show), subwindow);
    	gtk_grid_attach(GTK_GRID(subgrid_1), button_2, 1, 3, 1, 1);
    
    gtk_widget_show (subwindow_1);
	 } else{// that bai
	 	gtk_widget_hide(subwindow);
		gtk_init ();
    	subwindow_1 = gtk_window_new();
    	gtk_window_set_title (GTK_WINDOW (subwindow_1), "Join Group Error");
    	//
    	subgrid_1 = gtk_grid_new ();
    	gtk_window_set_child (GTK_WINDOW (subwindow_1), subgrid_1);
    
    	label_1 = gtk_label_new("Incorrect Group Code!");
    	gtk_grid_attach(GTK_GRID(subgrid_1), label_1, 0, 2, 1, 1);
    
    	button_2 = gtk_button_new_with_label ("Retry");
    	g_signal_connect_swapped(button_2, "clicked", G_CALLBACK(gtk_window_destroy), subwindow_1);
    	g_signal_connect_swapped(button_2, "clicked", G_CALLBACK(gtk_widget_show), subwindow);
    	gtk_grid_attach(GTK_GRID(subgrid_1), button_2, 1, 3, 1, 1);
    
    	gtk_widget_show (subwindow_1);
	 }
    */
    gtk_widget_show (subwindow);
}

void ViewGroup(GtkWidget *button,Window *win)
{
	Window *win1;
    win1 = win;
    
	gtk_widget_hide(win1->window);
	GtkWidget *subgrid;
	GtkWidget *subwindow;
	GtkWidget *button_1, *button_2, *button_3, *button_4, *label;
	
    subwindow = gtk_application_window_new (win1->app);
    gtk_window_set_title (GTK_WINDOW (subwindow), "View All Group");
    gtk_window_set_default_size (GTK_WINDOW (subwindow), 640, 400);
    
	subgrid = gtk_grid_new ();
  	gtk_window_set_child (GTK_WINDOW (subwindow), subgrid);
  	
  	//label
  	label = gtk_label_new("All Group");
  	gtk_grid_attach(GTK_GRID(subgrid), label, 0, 0, 1, 1);
  	
  	//button
  	button_1 = gtk_button_new_with_label("\t\t\t\nGroup 1\n\n");
  	gtk_grid_attach(GTK_GRID(subgrid), button_1, 1, 2, 1, 1);
  	g_signal_connect_swapped(button_1, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
  	g_signal_connect(button_1, "clicked", G_CALLBACK(Group), win1);
  	
  	button_2 = gtk_button_new_with_label("\t\t\t\nGroup 2\n\n");
  	gtk_grid_attach(GTK_GRID(subgrid), button_2, 3, 2, 1, 1);
  	//g_signal_connect_swapped(button_1, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
  	//g_signal_connect(button_1, "clicked", G_CALLBACK(Group), win1);
  	
  	button_3 = gtk_button_new_with_label("\t\t\t\nGroup 3\n\n");
  	gtk_grid_attach(GTK_GRID(subgrid), button_3, 5, 2, 1, 1);
  	//g_signal_connect_swapped(button_1, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
  	//g_signal_connect(button_1, "clicked", G_CALLBACK(Group), win1);
  	
  	button_4 = gtk_button_new_with_label("\t\t\t\nGroup 4\n\n");
  	gtk_grid_attach(GTK_GRID(subgrid), button_4, 7, 2, 1, 1);
  	//g_signal_connect_swapped(button_1, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
  	//g_signal_connect(button_1, "clicked", G_CALLBACK(Group), win1);
  	
	button = gtk_button_new_with_label ("Back");
	gtk_grid_attach(GTK_GRID(subgrid), button, 0, 1, 1, 1);
	
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_show), win1->window);
    
    gtk_widget_show (subwindow);
}

void Logout(GtkWidget *button,Window *win)
{
	gtk_window_destroy(GTK_WINDOW(win->window));
	activate(win->app,win);
}

void CreateGroup_addm(GtkWidget *button,Window *win)//sau khi create group thi hien de add member
{
	Window *win1;
    win1 = win;
    
	gtk_widget_hide(win1->window);
	GtkWidget *subgrid,*subgrid_1;
	GtkWidget *subwindow, *subwindow_1;
	GtkWidget *label, *label_1,*label_2, *gr_name, *button_1, *button_2;
	
    subwindow = gtk_application_window_new (win1->app);
    gtk_window_set_title (GTK_WINDOW (subwindow), "Add Member");
    gtk_window_set_default_size (GTK_WINDOW (subwindow), 640, 400);
    
	subgrid = gtk_grid_new ();
  	gtk_window_set_child (GTK_WINDOW (subwindow), subgrid);
  	
  	//label
    label = gtk_label_new("\nInput Username:    ");
  	gtk_grid_attach(GTK_GRID(subgrid), label, 0, 2, 1, 1);
  
 	//insert field
  	gr_name = gtk_entry_new();
  	gtk_entry_set_placeholder_text(GTK_ENTRY(gr_name), "Username\n");
  	gtk_grid_attach(GTK_GRID(subgrid), gr_name, 1, 3, 1, 1);
 	
 	//button
	button = gtk_button_new_with_label ("Back");
	gtk_grid_attach(GTK_GRID(subgrid), button, 0, 8, 1, 1);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
    g_signal_connect(button, "clicked", G_CALLBACK(CreateGroup), win1);
    
    button_1 = gtk_button_new_with_label ("OK");
 	gtk_grid_attach(GTK_GRID(subgrid), button_1, 1, 8, 1, 1);
 	
 	/*
	int i; //thong bao thanh cong
 	scanf("%d",i);
 	if(i=1)//thanh cong
	 {
 		gtk_widget_hide(subwindow);
		gtk_init ();
    	subwindow_1 = gtk_window_new();
    	gtk_window_set_title (GTK_WINDOW (subwindow_1), "Succeed");
    	//
    	subgrid_1 = gtk_grid_new ();
    	gtk_window_set_child (GTK_WINDOW (subwindow_1), subgrid_1);
    
    	label_1 = gtk_label_new("Add member succeed!");
    	gtk_grid_attach(GTK_GRID(subgrid_1), label_1, 0, 2, 1, 1);
    
    	button_2 = gtk_button_new_with_label ("OK");
    	g_signal_connect_swapped(button_2, "clicked", G_CALLBACK(gtk_window_destroy), subwindow_1);
    	g_signal_connect_swapped(button_2, "clicked", G_CALLBACK(gtk_widget_show), subwindow);
    	gtk_grid_attach(GTK_GRID(subgrid_1), button_2, 1, 3, 1, 1);
    
    gtk_widget_show (subwindow_1);
	 } else{// that bai
	 	gtk_widget_hide(subwindow);
		gtk_init ();
    	subwindow_1 = gtk_window_new();
    	gtk_window_set_title (GTK_WINDOW (subwindow_1), "Add member Error");
    	//
    	subgrid_1 = gtk_grid_new ();
    	gtk_window_set_child (GTK_WINDOW (subwindow_1), subgrid_1);
    
    	label_1 = gtk_label_new("Incorrect Input Username");
    	gtk_grid_attach(GTK_GRID(subgrid_1), label_1, 0, 2, 1, 1);
    
    	button_2 = gtk_button_new_with_label ("Retry");
    	g_signal_connect_swapped(button_2, "clicked", G_CALLBACK(gtk_window_destroy), subwindow_1);
    	g_signal_connect_swapped(button_2, "clicked", G_CALLBACK(gtk_widget_show), subwindow);
    	gtk_grid_attach(GTK_GRID(subgrid_1), button_2, 1, 3, 1, 1);
    
    	gtk_widget_show (subwindow_1);
	 }*/
	 
	gtk_widget_show (subwindow);
}

void Group(GtkWidget *button,Window *win)
{
	Window *win1;
    win1 = win;
    
    gtk_widget_hide(win1->window);
	GtkWidget *box,*box_1;
	GtkWidget *subgrid;
	GtkWidget *subwindow;
	GtkWidget *label, *label_1;
	GtkWidget *button_1,*button_2,*button_3;//1_View member 2_Upload 3_Create Folder
	GtkWidget *button1,*button2,*button3;//1File 2Folder
	
	subwindow = gtk_application_window_new (win1->app);
    gtk_window_set_title (GTK_WINDOW (subwindow), "Group");
    gtk_window_set_default_size (GTK_WINDOW (subwindow), 640, 400);
    
    subgrid = gtk_grid_new ();
  	gtk_window_set_child (GTK_WINDOW (subwindow), subgrid);
    
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL,20);
	gtk_grid_attach(GTK_GRID(subgrid), box, 0, 2, 1, 1);
	label = gtk_label_new("\n\n");
  	gtk_grid_attach(GTK_GRID(subgrid), label, 0, 1, 1, 1); 
	
	button_1 = gtk_button_new_with_label ("View member");
	gtk_box_append (GTK_BOX(box), button_1);
	g_signal_connect_swapped(button_1, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
	g_signal_connect(button_1, "clicked", G_CALLBACK(ViewMember), win1);
	
	button_2 = gtk_button_new_with_label ("Upload file");
	gtk_box_append (GTK_BOX(box), button_2);
	g_signal_connect_swapped(button_2, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
	g_signal_connect(button_2, "clicked", G_CALLBACK(Upload), win1);
	
	button_3 = gtk_button_new_with_label ("Create folder");
	gtk_box_append (GTK_BOX(box), button_3);
	g_signal_connect_swapped(button_3, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
	g_signal_connect(button_3, "clicked", G_CALLBACK(CreateFolder), win1);
	
	button = gtk_button_new_with_label ("Back");
	gtk_box_append (GTK_BOX(box), button);
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
	g_signal_connect(button, "clicked", G_CALLBACK(ViewGroup), win1); //back ViewGroup
	
	//
	box_1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);
	gtk_grid_attach(GTK_GRID(subgrid), box_1, 2, 1, 1, 1);
	label_1 = gtk_label_new("|\t\t\t\n|\t\t\t\n|\t\t\t\n|\t\t\t\n|\t\t\t\n|\t\t\t\n|\t\t\t\n|\t\t\t\n|\t\t\t\n|\t\t\t\n|\t\t\t\n|\t\t\t\n|\t\t\t\n|\t\t\t\n|\t\t\t\n|\t\t\t\n|\t\t\t\n|\t\t\t");
  	gtk_grid_attach(GTK_GRID(subgrid), label_1, 1, 2, 1, 1);
	
	button1 = gtk_button_new_with_label ("File");
	gtk_box_append (GTK_BOX(box_1), button1);
	g_signal_connect(button1, "clicked", G_CALLBACK(File), win1);
	
	button2 = gtk_button_new_with_label ("Folder");
	gtk_box_append (GTK_BOX(box_1), button2);
	g_signal_connect(button2, "clicked", G_CALLBACK(Folder), win1);
	
	button3 = gtk_button_new_with_label ("Folder2");
	gtk_box_append (GTK_BOX(box_1), button3);
	
  	gtk_widget_show (subwindow);
}

void ViewMember(GtkWidget *button,Window *win)
{
	Window *win1;
    win1 = win;
    
	gtk_widget_hide(win1->window);
	GtkWidget *subgrid;
	GtkWidget *subwindow;
	GtkWidget *button_a, *button_1, *button_2, *button_3, *delete_1, *delete_2, *delete_3;
	
	//tao window
    subwindow = gtk_application_window_new (win1->app);
    gtk_window_set_title (GTK_WINDOW (subwindow), "View Member");
    gtk_window_set_default_size (GTK_WINDOW (subwindow), 640, 400);
    
	subgrid = gtk_grid_new ();
  	gtk_window_set_child (GTK_WINDOW (subwindow), subgrid);
  	
  	//button
  	button_1 = gtk_button_new_with_label("\t\t\tMember 1");
  	gtk_grid_attach(GTK_GRID(subgrid), button_1, 0, 1, 1, 1);
  	delete_1 = gtk_button_new_with_label("\t\t\tDelete");
  	gtk_grid_attach(GTK_GRID(subgrid), delete_1, 1, 1, 1, 1);
  	
  	
  	button_2 = gtk_button_new_with_label("\t\t\tMember 2");
  	gtk_grid_attach(GTK_GRID(subgrid), button_2, 0, 2, 1, 1);
  	delete_2 = gtk_button_new_with_label("\t\t\tDelete");
  	gtk_grid_attach(GTK_GRID(subgrid), delete_2, 1, 2, 1, 1);
  	
  	
  	button_3 = gtk_button_new_with_label("\t\t\tMember 3");
  	gtk_grid_attach(GTK_GRID(subgrid), button_3, 0, 3, 1, 1);
  	delete_3 = gtk_button_new_with_label("\t\t\tDelete");
  	gtk_grid_attach(GTK_GRID(subgrid), delete_3, 1, 3, 1, 1);
  	
  	
  	button_a = gtk_button_new_with_label("\t\t\tAdd Member");
  	gtk_grid_attach(GTK_GRID(subgrid), button_a, 4, 0, 1, 1);
  	g_signal_connect_swapped(button_a, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
  	g_signal_connect(button_a, "clicked", G_CALLBACK(InGroup_addm), win1);
  	
  	
	button = gtk_button_new_with_label ("Back");
	gtk_grid_attach(GTK_GRID(subgrid), button, 4, 4, 1, 1);
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
    g_signal_connect(button, "clicked", G_CALLBACK(Group), win1); //back Group
    
    gtk_widget_show (subwindow);
}

void Delete_mem()
{
	    GtkWidget *subwindow_1,*subgrid_1,*label,*button;
		gtk_init ();
    	subwindow_1 = gtk_window_new();
    	gtk_window_set_title (GTK_WINDOW (subwindow_1), "Delete Member");
    	//
    	subgrid_1 = gtk_grid_new ();
    	gtk_window_set_child (GTK_WINDOW (subwindow_1), subgrid_1);
    
    	label = gtk_label_new("Delete member succeed!");
    	gtk_grid_attach(GTK_GRID(subgrid_1), label, 0, 2, 1, 1);
    
    	button = gtk_button_new_with_label ("OK");
    	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), subwindow_1);
    	gtk_grid_attach(GTK_GRID(subgrid_1), button, 1, 3, 1, 1);
    
        gtk_widget_show (subwindow_1);
}

void Upload(GtkWidget *button,Window *win)
{
	Window *win1;
    win1 = win;
    
	GtkWidget *subgrid;
	GtkWidget *subwindow;
	GtkWidget *label, *label_1, *gr_name, *button_1;
	
    subwindow = gtk_application_window_new (win1->app);
    gtk_window_set_title (GTK_WINDOW (subwindow), "Upload File");
    gtk_window_set_default_size (GTK_WINDOW (subwindow), 640, 400);
    
	subgrid = gtk_grid_new ();
  	gtk_window_set_child (GTK_WINDOW (subwindow), subgrid);
  	
  	//label
  	label = gtk_label_new("Upload File!");
  	gtk_grid_attach(GTK_GRID(subgrid), label, 0, 0, 1, 1);
    label_1 = gtk_label_new("\nEnter File Path:    ");
  	gtk_grid_attach(GTK_GRID(subgrid), label_1, 0, 2, 1, 1);
  
 	//insert field
  	gr_name = gtk_entry_new();
  	gtk_grid_attach(GTK_GRID(subgrid), gr_name, 1, 3, 1, 1);
 	
 	//button
	button = gtk_button_new_with_label ("Cancel");
	gtk_grid_attach(GTK_GRID(subgrid), button, 0, 8, 1, 1);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
    g_signal_connect(button, "clicked", G_CALLBACK(Group), win1); //back Group
    
    button_1 = gtk_button_new_with_label ("Upload");
 	gtk_grid_attach(GTK_GRID(subgrid), button_1, 1, 8, 1, 1);
    
    gtk_widget_show (subwindow);
}

void CreateFolder(GtkWidget *button,Window *win)
{
	Window *win1;
    win1 = win;
    
	GtkWidget *subgrid,*subgrid_1;
	GtkWidget *subwindow,*subwindow_1;
	GtkWidget *label, *label_1,*label_2, *gr_name, *button_1,*button_2;
	
    subwindow = gtk_application_window_new (win1->app);
    gtk_window_set_title (GTK_WINDOW (subwindow), "Create Folder");
    gtk_window_set_default_size (GTK_WINDOW (subwindow), 640, 400);
    
	subgrid = gtk_grid_new ();
  	gtk_window_set_child (GTK_WINDOW (subwindow), subgrid);
  	
  	//label
  	label = gtk_label_new("Create Folder!");
  	gtk_grid_attach(GTK_GRID(subgrid), label, 0, 0, 1, 1);
    label_1 = gtk_label_new("\nEnter Folder Name:    ");
  	gtk_grid_attach(GTK_GRID(subgrid), label_1, 0, 2, 1, 1);
  
 	//insert field
  	gr_name = gtk_entry_new();
  	gtk_grid_attach(GTK_GRID(subgrid), gr_name, 1, 3, 1, 1);
 	
 	//button
	button = gtk_button_new_with_label ("Cancel");
	gtk_grid_attach(GTK_GRID(subgrid), button, 0, 8, 1, 1);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
    g_signal_connect(button, "clicked", G_CALLBACK(Group), win1); //back Group
    
    button_1 = gtk_button_new_with_label ("Create");
 	gtk_grid_attach(GTK_GRID(subgrid), button_1, 1, 8, 1, 1);
 	
 	
 	int i; //thong bao thanh cong
 	scanf("%d",&i);
 	if(i=1)//thanh cong
	 {
 		gtk_widget_hide(subwindow);
		gtk_init ();
    	subwindow_1 = gtk_window_new();
    	gtk_window_set_title (GTK_WINDOW (subwindow_1), "Succeed");
    	//
    	subgrid_1 = gtk_grid_new ();
    	gtk_window_set_child (GTK_WINDOW (subwindow_1), subgrid_1);
    
    	label_2 = gtk_label_new("Add member succeed!");
    	gtk_grid_attach(GTK_GRID(subgrid_1), label_2, 0, 2, 1, 1);
    
    	button_2 = gtk_button_new_with_label ("OK");
    	g_signal_connect_swapped(button_2, "clicked", G_CALLBACK(gtk_window_destroy), subwindow_1);
    	g_signal_connect_swapped(button_2, "clicked", G_CALLBACK(gtk_widget_show), subwindow);
    	gtk_grid_attach(GTK_GRID(subgrid_1), button_2, 1, 3, 1, 1);
    
    gtk_widget_show (subwindow_1);
	 } else{// that bai
	 	gtk_widget_hide(subwindow);
		gtk_init ();
    	subwindow_1 = gtk_window_new();
    	gtk_window_set_title (GTK_WINDOW (subwindow_1), "Add member Error");
    	//
    	subgrid_1 = gtk_grid_new ();
    	gtk_window_set_child (GTK_WINDOW (subwindow_1), subgrid_1);
    
    	label_2 = gtk_label_new("Incorrect Input Username");
    	gtk_grid_attach(GTK_GRID(subgrid_1), label_2, 0, 2, 1, 1);
    
    	button_2 = gtk_button_new_with_label ("Retry");
    	g_signal_connect_swapped(button_2, "clicked", G_CALLBACK(gtk_window_destroy), subwindow_1);
    	g_signal_connect_swapped(button_2, "clicked", G_CALLBACK(gtk_widget_show), subwindow);
    	gtk_grid_attach(GTK_GRID(subgrid_1), button_2, 1, 3, 1, 1);
    
    	gtk_widget_show (subwindow_1);
	 }
	 
    
    gtk_widget_show (subwindow);
}

void File(GtkWidget *button,Window *win)
{
	GtkWidget *window,*grid,*button_1;
		gtk_init ();
    	window = gtk_window_new();
    	gtk_window_set_title (GTK_WINDOW (window), "File");
    	//
    	grid = gtk_grid_new ();
    	gtk_window_set_child (GTK_WINDOW (window), grid);
    
    	button_1 = gtk_button_new_with_label ("File");
    	gtk_grid_attach(GTK_GRID(grid), button_1, 1, 0, 1, 1);
    
    	button = gtk_button_new_with_label ("Back");
    	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), window);
    	gtk_grid_attach(GTK_GRID(grid), button, 1, 1, 1, 1);
    
        gtk_widget_show (window);
}

void Folder(GtkWidget *button,Window *win1)
{
	Window *win;
    win = win1;
	GtkWidget *window,*grid,*button_1;
		gtk_init ();
    	window = gtk_window_new();
    	gtk_window_set_title (GTK_WINDOW (window), "Folder");
    	//
    	grid = gtk_grid_new ();
    	gtk_window_set_child (GTK_WINDOW (window), grid);
    
    	button_1 = gtk_button_new_with_label ("View Folder");
    	gtk_grid_attach(GTK_GRID(grid), button_1, 1, 0, 1, 1);
    	g_signal_connect_swapped(button_1, "clicked", G_CALLBACK(gtk_window_destroy), window);
    	g_signal_connect(button_1, "clicked", G_CALLBACK(ViewFolder), win);
    	
    
    	button = gtk_button_new_with_label ("Back");
    	g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), window);
    	gtk_grid_attach(GTK_GRID(grid), button, 1, 1, 1, 1);
    
        gtk_widget_show (window);	
}

void ViewFolder(GtkWidget *button,Window *win)
{
	Window *win1;
    win1 = win;
    
    GtkWidget *subgrid;
	GtkWidget *subwindow;
	GtkWidget *label, *button_1;
	
    subwindow = gtk_application_window_new (win1->app);
    gtk_window_set_title (GTK_WINDOW (subwindow), "View Folder");
    gtk_window_set_default_size (GTK_WINDOW (subwindow), 640, 400);

  	subgrid = gtk_grid_new ();
  	gtk_window_set_child (GTK_WINDOW (subwindow), subgrid);
  	
  	win1->nfolder=5;
  	strcpy(win1->ifolder,"Infor");
  	strcpy(win1->folname,"Folder");

  	for (int i = 0; i < win1->nfolder; i++)
    {
      button_1 = gtk_button_new ();
      gtk_button_set_label (GTK_BUTTON (button_1), win1->folname);
      //g_object_set (button_1, "xalign", 0.0, NULL);
      gtk_grid_attach (GTK_GRID (subgrid), button_1, 0, i, 1, 1);

      label = gtk_label_new (NULL);
      g_object_set (label, "xalign", 0.5, NULL);//
      gtk_label_set_text (GTK_LABEL (label), win1->ifolder);//set thong tin cho folder
      gtk_grid_attach (GTK_GRID (subgrid), label, 1, i, 1, 1);
    }
    
    button = gtk_button_new_with_label ("Back");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
    g_signal_connect(button, "clicked", G_CALLBACK(Folder), win1);
    gtk_grid_attach(GTK_GRID(subgrid), button, 0, win1->nfolder, 1, 1);

  	gtk_widget_show (subwindow);
}

void InGroup_addm(GtkWidget *button,Window *win)
{
	Window *win1;
    win1 = win;
    
	GtkWidget *subgrid,*subgrid_1;
	GtkWidget *subwindow;
	GtkWidget *label, *gr_name, *button_1, *button_2;
	
    subwindow = gtk_application_window_new (win1->app);
    gtk_window_set_title (GTK_WINDOW (subwindow), "Add Member");
    gtk_window_set_default_size (GTK_WINDOW (subwindow), 640, 400);
    
	subgrid = gtk_grid_new ();
  	gtk_window_set_child (GTK_WINDOW (subwindow), subgrid);
  	
  	//label
    label = gtk_label_new("\nInput Username:    ");
  	gtk_grid_attach(GTK_GRID(subgrid), label, 0, 2, 1, 1);
  
 	//insert field
  	gr_name = gtk_entry_new();
  	gtk_entry_set_placeholder_text(GTK_ENTRY(gr_name), "Username\n");
  	gtk_grid_attach(GTK_GRID(subgrid), gr_name, 1, 3, 1, 1);
 	
 	//button
	button = gtk_button_new_with_label ("Back");
	gtk_grid_attach(GTK_GRID(subgrid), button, 0, 8, 1, 1);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
    g_signal_connect(button, "clicked", G_CALLBACK(ViewMember), win1);
    
    button_1 = gtk_button_new_with_label ("OK");
 	gtk_grid_attach(GTK_GRID(subgrid), button_1, 1, 8, 1, 1);
 	//g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), subwindow);
 	
    gtk_widget_show (subwindow);
}
