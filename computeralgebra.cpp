#include "computeralgebra.h"
#include "ui_computeralgebra.h"

ComputerAlgebra::ComputerAlgebra(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ComputerAlgebra)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

ComputerAlgebra::~ComputerAlgebra()
{
    delete ui;
}


void ComputerAlgebra::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void ComputerAlgebra::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file!" + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = file.readAll();
    ui->textEdit->setText(text);
    file.close();

}

void ComputerAlgebra::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file!" + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void ComputerAlgebra::on_actionExit_triggered()
{
    QApplication::quit();
}

void ComputerAlgebra::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void ComputerAlgebra::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void ComputerAlgebra::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void ComputerAlgebra::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer name");
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec() == QDialog::Rejected) {
        QMessageBox::warning(this, "Warning", "Cannot access printer!");
    }
    ui->textEdit->print(&printer);
}
