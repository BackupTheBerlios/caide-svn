// solution_explorer.cpp : Implementation file for class CSolutionExplorer
////////////////////////


// Includes
#include "solution_explorer.h"
#include "project_browser.h"
#include <qlistview.h>
#include <qtabwidget.h>
#include <qtextedit.h>

CSolutionExplorer::CSolutionExplorer(QWidget *parent, const char* name)
   : QDockWindow(parent, name)
{
  // Create the tab widget twControler
  twControler = new QTabWidget(this);
  setWidget(twControler);

  // Set the window visible by default
  isVisible = true;

  if(!createProjBrowser() && !createClassBrowser() && !createResourceBrowser())
    close();

  twControler->setTabPosition(QTabWidget::Bottom);
  
}


// creatClassBrowser() : function (public slot) to create a class browser
//////////////////////
int CSolutionExplorer::createClassBrowser()
{
  lvClassBrowser = new QListView(this);
  lvClassBrowser->addColumn(tr(" "));
  lvClassBrowser->setResizeMode(QListView::LastColumn);

  twControler->addTab(lvClassBrowser, tr("Class View"));

   return 0;
}


// createProjBrowser() : function (public slot) to create a project browser
//////////////////////
int CSolutionExplorer::createProjBrowser()
{
  ProjectBrowser = new CProjectBrowser(this, tr("Project Browser"));
  ProjectBrowser->setResizeMode(QListView::LastColumn);
  ProjectBrowser->setRootIsDecorated(true);

  // Add to the tab
  twControler->addTab(ProjectBrowser, tr("Projects"));

  return 0;
}

// createResourceBrowser() : function (public slot) to create a resource browser
//////////////////////////
int CSolutionExplorer::createResourceBrowser()
{

  lvResourceBrowser = new QListView(this);
  lvResourceBrowser->addColumn(tr(" "));
  lvResourceBrowser->setResizeMode(QListView::LastColumn);
  lvResourceBrowser->setRootIsDecorated(true);

  twControler->addTab(lvResourceBrowser, tr("Resource View"));

  return 0;
}


// setVisible(bool) : function (public slot) to show or hide the SE Window
///////////////////
void CSolutionExplorer::setVisible(bool showWin)
{
   isVisible = !showWin;

   if(isVisible) 
     this->hide();
   else
     this->show();
}
