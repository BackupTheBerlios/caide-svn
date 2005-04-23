// mainwin.cpp : implementation of the MainWindow class
//

// Includes
#include <qtabwidget.h>
#include <qimage.h>
#include <qtoolbar.h>
#include <qpopupmenu.h>
#include <qaction.h>
#include <qmenubar.h>
#include <qstatusbar.h>
#include <qtextbrowser.h>
#include <qlabel.h>

#include "mainwin.h"
#include "editors/code_editor.h"
#include "solution_explorer/solution_explorer.h"
#include "output_win/outputwin.h"

// MainWindow ctor
//////////////////
MainWindow::MainWindow(QWidget *parent, const char *name)
   : QMainWindow(parent, name)
{

   // Set the applications icon
   setIcon(QPixmap::fromMimeSource("applogo.png"));

   // Here we create and set the main widget
   twManager = new QTabWidget(this, "Window Manager");
   setCentralWidget(twManager);

   testb = new QTextBrowser(this, "Test");
   testb->mimeSourceFactory()->setFilePath(".");
   testb->mimeSourceFactory()->setImage("startpage-title", QImage::fromMimeSource("startpage-title.png"));
   testb->setSource("test.htm");
   twManager->addTab(testb, testb->documentTitle());

   // Create the Solution Explorer Dock Window
   SolutionExplorer = new CSolutionExplorer(this);
   SolutionExplorer->setCaption("Solution Explorer");
   SolutionExplorer->setHorizontallyStretchable(true);
   SolutionExplorer->setResizeEnabled(true);
   SolutionExplorer->setCloseMode(QDockWindow::Always);
   moveDockWindow(SolutionExplorer, Left);

   // Create the output dock wndow
   OutputWindow = new COutputWindow(this);
   OutputWindow->setCaption("Output");
   OutputWindow->setVerticallyStretchable(true);
   OutputWindow->setResizeEnabled(true);
   OutputWindow->setCloseMode(QDockWindow::Always);
   moveDockWindow(OutputWindow, Bottom);
   OutputWindow->hide(); // Hide the window by default

   // Create all actions
   if(!CreateActions())
     close();

   // Create the status bar
   if(!CreateStatusbar())
     close();

   // Now we create all MainWindow toolbars
   if(!CreateToolbars())
     close();

   // Now we create all MainWindow Menus
   if(!CreateMenus())
     close();

   // Resize the window
   resize(600,400);


}

bool MainWindow::CreateStatusbar()
{
  labelTemp = new QLabel(tr("See the power of Open Source"), this);
  labelTemp->setAlignment(AlignHCenter);
  labelTemp->setMinimumSize(labelTemp->sizeHint());

  statusBar()->addWidget(labelTemp);
  
  return true;
}

bool MainWindow::CreateToolbars()
{
  tbFile = new QToolBar(tr("File"), this);
  actExit->addTo(tbFile);
  actShowSE->addTo(tbFile);
  return true;
}

bool MainWindow::CreateActions()
{

   // File Close Action
   actExit = new QAction(tr("E&xit"), tr("CTRL-X"), this);
   actExit->setIconSet(QPixmap::fromMimeSource("close.png"));
   actExit->setStatusTip(tr("Close the IDE"));

   // Show / Hide Project Window
   actShowSE = new QAction(tr("Show/Hide Solution Browser"),tr("CTRL-S"), this);
   actShowSE->setToggleAction(true);
   actShowSE->setOn(SolutionExplorer->winVisible());
   actShowSE->setIconSet(QPixmap::fromMimeSource("features.png"));
   actShowSE->setStatusTip(tr("Show/Hide the Solution Explorer"));

   // Create the Compile Action
   actCompile = new QAction(tr("Compile Application"), tr("CTRL-C"), this);
   actCompile->setIconSet(QPixmap::fromMimeSource("applogo.png"));
   actCompile->setStatusTip(tr("Compile the application"));

   // Create Project Browser
   actCreatePB = new QAction(tr("Create Project Browser"),tr("CTRL-P") ,this);

   // Create Class Browser
   actCreateCB = new QAction(tr("Create Class Browser"),tr("CTRL-C"),  this);

   // Create Resource Browser
   actCreateRB = new QAction(tr("Create Resource Browser"),tr("CTRL-R"),  this);



   // Now we setup the connections.  If any fail. We bail
   if(!connect(actExit, SIGNAL(activated()), this, SLOT(close()))) 
     return false;

   connect(actShowSE, SIGNAL(toggled(bool)),
         SolutionExplorer, SLOT(setVisible(bool)));

   connect(actCreatePB, SIGNAL(activated()),
         SolutionExplorer, SLOT(createProjBrowser()));

   connect(actCreateCB, SIGNAL(activated()),
         SolutionExplorer, SLOT(createClassBrowser()));

   connect(actCreateRB, SIGNAL(activated()),
         SolutionExplorer, SLOT(createResourceBrowser()));

   connect(actCompile, SIGNAL(activated()),
         OutputWindow, SLOT(go()));
   

   return true; // If nothing fails then we assume success

}

bool MainWindow::CreateMenus()
{

   // Create the top level menu
   fileMenu = new QPopupMenu(this);
   actExit->addTo(fileMenu);

   viewMenu = new QPopupMenu(this);
   actShowSE->addTo(viewMenu);

   debugMenu = new QPopupMenu(this);
   actCreatePB->addTo(debugMenu);
   actCreateCB->addTo(debugMenu);
   actCreateRB->addTo(debugMenu);
   actCompile->addTo(debugMenu);

   if(!menuBar()->insertItem(tr("&File"), fileMenu))
     close();

   if(!menuBar()->insertItem(tr("&View"), viewMenu))
     close();

   if(!menuBar()->insertItem(tr("&Debug"), debugMenu))
     close();

   return true;  // If nothing fails then we assume success

}
