// main.cpp : This is the entry point of the application

// Includes

#include "qapplication.h"
#include "mainwin.h"
#include "qplatinumstyle.h"

int main(int argc, char *argv[])
{
   QApplication::setStyle(new QPlatinumStyle);   // first do this
   QApplication app(argc,argv);               // then do this
   app.setStyle(new QPlatinumStyle);

   // Create the main window
   MainWindow *mw = new MainWindow();

   // Set the application caption
   mw->setCaption("Code Anywhere IDE");

   // Set the main widget
   app.setMainWidget(mw);

   // Show the main widget
   mw->show();

   return app.exec();
}

