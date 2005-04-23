// solution_explorer.h : Header file for class SolutionExplorer
////////////////////////////////////////////

#ifndef __SFS_SOLUTIONEXPLORER_H__
#define __SFS_SOLUTIONEXPLORER_H__


// Includes
#include <qdockwindow.h>
#include <qlistview.h>

// Forward Declarations
class QListView;
class QTabWidget;
class CProjectBrowser;

class CSolutionExplorer : public QDockWindow
{
  Q_OBJECT

  public:  // Methods
    CSolutionExplorer(QWidget *parent = 0, const char *name = 0);

    bool winVisible() const
     {return isVisible;}

  private: // Variables
    QTabWidget          *twControler;
    CProjectBrowser     *ProjectBrowser;
    QListView           *lvClassBrowser;
    QListView           *lvResourceBrowser;
    QListViewItem       *lvi;
    QListViewItem       *lvi2;
    bool                isVisible;

  public slots:  // Public slots
    void setVisible(bool b);
    int createProjBrowser();
    int createClassBrowser();
    int createResourceBrowser();
    
};

#endif

