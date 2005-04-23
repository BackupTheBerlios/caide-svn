// project_browser.h : Header file for the class CProjectBrowser
///////////////////////////////////////////////////////////////////

#ifndef __SFS_PROJECTBROWSER_H__
#define __SFS_PROJECTBROWSER_H__

// Includes
#include <qlistview.h>
#include <qstring.h>


// Forward Declarations


class CProjectBrowser : public QListView
{
  Q_OBJECT

  public:
   CProjectBrowser(QWidget *parent = 0, const char *name = 0);

  private:
   QHeader *lvHeader;  // Header for the list view
};

#endif
