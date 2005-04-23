// mainwin.h : header file for the main window
//

// Change Log
/////////////
// Date | Author | Action
//
// 20040625 | Stephen Bunn | Created intial header file

#ifndef __SFS_MAINWIN_H__
#define __SFS_MAINWIN_H__


// Includes
#include <qmainwindow.h>
#include <qimage.h>

// Forward Declarations
class CodeEditor;
class CSolutionExplorer;
class COutputWindow;
class QTabWidget;
class QToolBar;
class QAction;
class QLabel;
class QTabWidget;
class QTextBrowser;


class MainWindow : public QMainWindow
{
   Q_OBJECT

   public:
    MainWindow(QWidget *parent = 0, const char *name = 0);

   private:     // Variables
     CodeEditor         *codeEditor;               // Code Editor Widget
     QTabWidget         *twManager;                // The window manager
     COutputWindow      *OutputWindow;             // The output window
     QTextBrowser       *testb;
     QImage imgFeatures;
     CSolutionExplorer  *SolutionExplorer;         // Project Explorer Widget 
     QToolBar           *tbFile;                   // "File" Toolbar
     QPopupMenu         *fileMenu;                 // "File" Menu
     QPopupMenu         *viewMenu;                 // "View" Menu
     QPopupMenu         *debugMenu;                // Debug Menu for dev
     QAction            *actExit;                  // "File->Exit" Action
     QAction            *actShowSE;                //  Proj. Expl. Toggle
     QAction            *actCreatePB;              // Create a new Project Browser
     QAction            *actCreateCB;              // Create Solution Browser
     QAction            *actCreateRB;              // Create Resource Browser
     QAction            *actCompile;               // Compile Action
     QLabel             *labelTemp;                // Temp Message Label


   private:  // Methods
      bool CreateActions();
      bool CreateToolbars();
      bool CreateMenus();
      bool CreateStatusbar();
     
   private slots:
};

#endif
