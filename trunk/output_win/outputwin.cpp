
// outputwin.cpp : Implementation file for class OutputWindow
//////////////////


#include <qstring.h>
#include <qtextedit.h>
#include <qprocess.h>

#include "outputwin.h"


COutputWindow::COutputWindow(QWidget *parent, const char *name)
   : QDockWindow(parent, name)
{
  // Create and set the main widget (a QTextEdit)
  output = new QTextEdit(this);
  output->setReadOnly(true);
  setWidget(output);
  compiler = 0;
  connect(output, SIGNAL(textChanged()), output, SLOT(scrollToBottom()));
  
}

void COutputWindow::go()
{
  show(); // show the window
  //execute("nmake clean");
  execute("nmake");
}

void COutputWindow::execute(const QString &command)
{
  compiler = new QProcess(this);
  compiler->addArgument(command);


  connect(compiler, SIGNAL(readyReadStderr()), this, SLOT(updateError()));
  connect(compiler, SIGNAL(readyReadStdout()), this, SLOT(updateText()));
  connect(compiler, SIGNAL(processExited()), this, SLOT(updateExit()));
  compiler->start();
  
}

void COutputWindow::updateError()
{
 QByteArray data = compiler->readStderr();
 QString text = output->text() + QString(data);
 output->setText(text);
}

void COutputWindow::updateText()
{
  QByteArray data = compiler->readStdout();
  QString text = output->text() + QString(data);
  output->setText(text);
}

void COutputWindow::updateExit()
{
  if (compiler->normalExit()) {
    output->append("Completed Successfully");
  }
  else {
    output->append("Error");
  }
}
