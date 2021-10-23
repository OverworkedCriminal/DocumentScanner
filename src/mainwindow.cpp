#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectSignals();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::browseFiles(bool)
{
    QString filePath{ QFileDialog::getOpenFileName(this, "Open Image") };
    if (!filePath.isEmpty())
    {
        ui->imagePathInput->setText(filePath);
    }
}

void MainWindow::connectSignals()
{
    connect(ui->browseButton, &QPushButton::clicked,
            this, &MainWindow::browseFiles);
}

