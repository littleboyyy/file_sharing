#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gmodule.h>

#ifndef LOGIN_CASE_H
#define LOGIN_CASE_H
typedef struct Window {
	GtkApplication *app;
	
	GtkWidget *window;
	GtkWidget *grid;
	
	//nhung cai nay se cho vao database
	GtkWidget *u_name;
	GtkWidget *pass;
	GtkWidget *name;
	GtkWidget *email;
	GtkWidget *phone;
	//
	//user, file, folder
	int nfolder;// so luong folder
	char folname[10]; //ten folder
	char ifolder[10]; //infor folder
	
}Window;

//giao dien Login
void activate (GtkApplication* app, Window *win);
//giao dien Signup
void activate_1(GtkWidget *b,Window *win);

//xu ly Login va Signup
void Login (GtkWidget *button,Window *win);
void Signup (GtkWidget *button,Window *win);

//Home
void HomePage(char *username, Window *win);

//4 nut trong home
void CreateGroup(GtkWidget *button,Window *win);
void JoinGroup(GtkWidget *button,Window *win);
void ViewGroup(GtkWidget *button,Window *win);
void Logout(GtkWidget *button,Window *win);

//add member sau khi create_group
void CreateGroup_addm(GtkWidget *button,Window *win);

//giao dien sau khi an vao 1 group
void Group(GtkWidget *button,Window *win);

//add member trong  nhom
void InGroup_addm(GtkWidget *button,Window *win);

//file folder 
void File(GtkWidget *button,Window *win);
void Folder(GtkWidget *button,Window *win1);
//View Folder
void ViewFolder(GtkWidget *button,Window *win);

void ViewMember(GtkWidget *button,Window *win);
void Delete_mem();

void Upload(GtkWidget *button,Window *win);
void CreateFolder(GtkWidget *button,Window *win);
#endif

