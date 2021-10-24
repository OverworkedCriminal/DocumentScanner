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
    fillProcessingSettings();
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

void MainWindow::fillProcessingSettings()
{
    auto& threshold{ ui->thresholdSettings };
    threshold->setText("Threshold");
    threshold->add("None", {}, {});
    threshold->add("Binary", {"t"}, {60.0});

    auto& blur{ ui->blurSettings };
    blur->setText("Blur");
    blur->add("None", {}, {});
    blur->add("Gaussian", {"ksize X", "ksize Y", "sigma X", "sigma Y"},
                          {        3,         3,         0,         0});

    auto& edges{ ui->edgedetectionSettings };
    edges->setText("Edge detection");
    edges->add("Canny", {"t1", "t2"}, {50.0, 220.0});

    auto& dilation{ ui->dilationSettings };
    dilation->setText("Dilation");
    dilation->add("None", {}, {});
    dilation->add("Simple", {"ksize X", "ksize Y"}, {3, 3});

    auto& corners{ ui->cornersfindingSettings };
    corners->setText("Corners finding");
    corners->add("Min Max XY", {}, {});
    corners->add("Min Max Sum/Sub XY", {}, {});
}

