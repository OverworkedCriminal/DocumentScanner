#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <opencv2/imgcodecs.hpp>

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
        ui->imagePathInput->setText(filePath);
}

void MainWindow::imageFileChanged(const QString &filePath)
{
    cv::Mat img{ cv::imread(filePath.toStdString()) };
    if (!img.empty())
        ui->originalImage->show(img);
}

void MainWindow::connectSignals()
{
    connect(ui->browseButton, &QPushButton::clicked,
            this, &MainWindow::browseFiles);

    connect(ui->imagePathInput, &QLineEdit::textChanged,
            this, &MainWindow::imageFileChanged);
}

