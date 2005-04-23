// outputwin.h : Header file for class OutputWindow
////////////////

#ifndef __SFS_OUTPUTWINDOW__H_
#define __SFS_OUTPUTWINDOW__H_

// Includes
#include <qdockwindow.h>

// Forward Declarations
class QProcess;
class QTextEdit;

class COutputWindow : public QDockWindow
{
 Q_OBJECT

 public:
   COutputWindow(QWidget *parent = 0, const char *name = 0);
   void execute(const QString &command);

 public slots:
   void updateText();
   void updateExit();
   void updateError();
   void go();

 private:
   QTextEdit *output;
   QProcess *compiler;

};

#endif
