#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
