#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <opencv2/imgcodecs.hpp>

#include <preprocessing/cannyfactory.h>
#include <preprocessing/dilationfactory.h>
#include <preprocessing/gaussianblurfactory.h>
#include <preprocessing/nonefactory.h>
#include <preprocessing/thresholdfactory.h>

#include <corners_finding/minmaxxyfactory.h>
#include <corners_finding/sumsubxyfactory.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int w{ ui->warpedImage->width() };
    int h{ ui->warpedImage->height() };
    _warpedSize = cv::Size(w, h);

    _preprocessing.resize(4);
    connectSignals();
    _scanner = new ds::DocumentScanner(
                _preprocessing,
                ContoursfindingFactory().create({0.0, 1.0}),
                MinMaxXYFactory().create({}));
    fillProcessingSettings();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete _scanner;
}

void MainWindow::browseFiles(bool)
{
    QString filePath{ QFileDialog::getOpenFileName(this, "Open Image") };
    if (!filePath.isEmpty())
        ui->imagePathInput->setText(filePath);
}

void MainWindow::imageFileChanged(const QString &filePath)
{
    _img = cv::imread(filePath.toStdString());
    if (!_img.empty())
    {
        ui->originalImage->show(_img);
        displayWarpedImage();
    }
}

void MainWindow::connectSignals()
{
    connect(ui->browseButton, &QPushButton::clicked,
            this, &MainWindow::browseFiles);

    connect(ui->imagePathInput, &QLineEdit::textChanged,
            this, &MainWindow::imageFileChanged);

    // preprocessing

    connect(ui->thresholdSettings,
            &PreprocessingStageSettings::valuesChanged,
            this,
            [this](auto stage) { preprocessingChanged(0, stage); });

    connect(ui->blurSettings,
            &PreprocessingStageSettings::valuesChanged,
            this,
            [this](auto stage) { preprocessingChanged(1, stage); });

    connect(ui->edgedetectionSettings,
            &PreprocessingStageSettings::valuesChanged,
            this,
            [this](auto stage) { preprocessingChanged(2, stage); });

    connect(ui->dilationSettings,
            &PreprocessingStageSettings::valuesChanged,
            this,
            [this](auto stage) { preprocessingChanged(3, stage); });

    // contours finding
    connect(ui->contoursfindingSettings,
            &ContoursfindingStageSettings::valuesChanged,
            this,
            &MainWindow::contoursfinderChanged);

    // corners finding
    connect(ui->cornersfindingSettings,
            &CornersfindingStageSettings::valuesChanged,
            this,
            &MainWindow::cornersfinderChanged);
}

void MainWindow::fillProcessingSettings()
{
    auto noneFactory{ std::make_shared<NoneFactory>() };

    auto& threshold{ ui->thresholdSettings };
    threshold->setText("Threshold");
    threshold->add("None", {}, {}, noneFactory);
    threshold->add("Binary", {"t"}, {60.0},
                   std::make_shared<ThresholdFactory>());

    auto& blur{ ui->blurSettings };
    blur->setText("Blur");
    blur->add("None", {}, {}, noneFactory);
    blur->add("Gaussian", {"ksize X", "ksize Y", "sigma X", "sigma Y"},
                          {        3,         3,         0,         0},
                          std::make_shared<GaussianblurFactory>());

    auto& edges{ ui->edgedetectionSettings };
    edges->setText("Edge detection");
    edges->add("Canny", {"t1", "t2"}, {50.0, 220.0},
               std::make_shared<CannyFactory>());

    auto& dilation{ ui->dilationSettings };
    dilation->setText("Dilation");
    dilation->add("None", {}, {}, noneFactory);
    dilation->add("Simple", {"ksize X", "ksize Y"}, {3, 3},
                  std::make_shared<DilationFactory>());

    auto& corners{ ui->cornersfindingSettings };
    corners->add("Min Max XY", {}, {},
                 std::make_shared<MinMaxXYFactory>());
    corners->add("Min Max Sum/Sub XY", {}, {},
                 std::make_shared<SumSubXYFactory>());
}

void MainWindow::displayWarpedImage()
{
    if (_img.empty()) return;

    _scanner->scan(_img, _warped, _warpedSize);
    ui->warpedImage->show(_warped);
}

void MainWindow::preprocessingChanged(
        std::size_t index,
        std::shared_ptr<ds::IPreprocessingStage> stage)
{
    _preprocessing[index] = stage;
    _scanner->setProcessingStages(_preprocessing);
    displayWarpedImage();
}

void MainWindow::contoursfinderChanged(
        std::shared_ptr<ds::ContoursFinder> stage)
{
    _scanner->setContoursFinder(stage);
    displayWarpedImage();
}

void MainWindow::cornersfinderChanged(
        std::shared_ptr<ds::ICornersFinder> stage)
{
    _scanner->setCornersFinder(stage);
    displayWarpedImage();
}

