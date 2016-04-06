#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->x = ui->labelX;
    ui->widget->y = ui->labelY;
    ui->widget->z = ui->labelZ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSair_triggered()
{
    close();
}

void MainWindow::on_checkBoxEixoX_clicked()
{
    ui->widget->desenharEixos(ui->checkBoxEixoX->checkState(),
                           ui->checkBoxEixoY->checkState(),
                           ui->checkBoxEixoZ->checkState());
}

void MainWindow::on_checkBoxEixoY_clicked()
{
    ui->widget->desenharEixos(ui->checkBoxEixoX->checkState(),
                           ui->checkBoxEixoY->checkState(),
                           ui->checkBoxEixoZ->checkState());
}

void MainWindow::on_checkBoxEixoZ_clicked()
{
    ui->widget->desenharEixos(ui->checkBoxEixoX->checkState(),
                           ui->checkBoxEixoY->checkState(),
                           ui->checkBoxEixoZ->checkState());
}

void MainWindow::on_checkBoxMalhaXY_clicked()
{
    ui->widget->desenharMalha(ui->checkBoxMalhaXY->checkState(),
                              ui->checkBoxMalhaXZ->checkState(),
                              ui->checkBoxMalhaYZ->checkState());
}

void MainWindow::on_checkBoxMalhaXZ_clicked()
{
    ui->widget->desenharMalha(ui->checkBoxMalhaXY->checkState(),
                              ui->checkBoxMalhaXZ->checkState(),
                              ui->checkBoxMalhaYZ->checkState());
}

void MainWindow::on_checkBoxMalhaYZ_clicked()
{
    ui->widget->desenharMalha(ui->checkBoxMalhaXY->checkState(),
                              ui->checkBoxMalhaXZ->checkState(),
                              ui->checkBoxMalhaYZ->checkState());
}

void MainWindow::on_actionAbrirArquivo_triggered()
{
    QString arquivoNome = QFileDialog::getOpenFileName(
                this,
                tr("Abrir arquivo"),
                "C://",
                "All files (*.*)"
                );
    ui->widget->carregarArquivo(arquivoNome);
}
