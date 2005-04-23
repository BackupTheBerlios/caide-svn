// code_editor.cpp : Implementation file for the class CodeEditor


// Includes
#include <qtextedit.h>
#include "code_editor.h"

// CodeEditor ctor
//////////////////
CodeEditor::CodeEditor(QWidget *parent, const char *name)
  :QTextEdit(parent, name)
{
  std::cout <<"Inside of the code editor ctor\n";
}
