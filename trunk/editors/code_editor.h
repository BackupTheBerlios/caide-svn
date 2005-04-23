// code_editor.h : Header file for the CodeEditor class
//

// Change Log
/////////////
// Date | Author | Action
// 20040625 | Stephen Bunn | Intial creation of the header file


// Description: The CodeEditor class is derived for QTextEdit
//              the CodeEditor implements basic editor functions
//              language specefic comes from the define QSyntaxHighlighter

#ifndef __SFS_CODEEDITOR_H__
#define __SFS_CODEEDITOR_H__


// Includes
#include <iostream>
#include <qtextedit.h>

// Forward Declarations

class CodeEditor : public QTextEdit
{
   public:
    CodeEditor(QWidget *parent = 0, const char *name = 0);

};

#endif
