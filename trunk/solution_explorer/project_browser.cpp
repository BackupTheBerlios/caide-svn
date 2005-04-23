// project_browser.cpp : Implmentation file for class CProjectBrowser
////////////////////////

#include "project_browser.h"
#include <qheader.h>
#include <qfile.h>

CProjectBrowser::CProjectBrowser(QWidget *parent, const char *name)
  :QListView(parent, name)
{
  // Construct the Project Browser list view

  // Hide the list view's header. We don't need it
  lvHeader = header();
  lvHeader->hide();

}

