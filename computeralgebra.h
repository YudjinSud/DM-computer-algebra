#ifndef COMPUTERALGEBRA_H
#define COMPUTERALGEBRA_H

#include <QMainWindow>

#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class ComputerAlgebra; }
QT_END_NAMESPACE

class ComputerAlgebra : public QMainWindow
{
    Q_OBJECT

public:
    ComputerAlgebra(QWidget *parent = nullptr);
    ~ComputerAlgebra();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionPrint_triggered();

private:
    Ui::ComputerAlgebra *ui;
    QString currentFile = "";
};
#endif // COMPUTERALGEBRA_H
