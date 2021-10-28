#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <DocumentScanner/DocumentScanner.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ds::DocumentScanner* _scanner;
    std::vector<std::shared_ptr<ds::IPreprocessingStage>> _preprocessing;

    cv::Mat _img;
    cv::Mat _warped;
    cv::Size _warpedSize;

private slots:

    /**
     * @brief Slot is called whenever browseButton is pressed.
     * It shows QFileDialog and saves selected file path
     * in QLineEdit.
     */
    void browseFiles(bool);

    /**
     * @brief Slot is called whenever text in QLineEdit changes.
     * It reads new image and displays it on originalImage widget.
     * @param filePath path to the new image
     */
    void imageFileChanged(const QString& filePath);

    /**
     * @brief Slot is called whenever contours finder
     * arguments change
     * @param stage new object which should replace old one
     */
    void contoursfinderChanged(
            std::shared_ptr<ds::ContoursFinder> stage);

    /**
     * @brief Slot is called whenever selected corners finding
     * stage implementation changes (combobox value)
     * or value in QLineEdit changes
     * @param stage new cornersfinding object that
     * should replace old one
     */
    void cornersfinderChanged(
            std::shared_ptr<ds::ICornersFinder> stage);

private:

    /**
     * @brief Helper method. Connects each singal to slot
     */
    void connectSignals();

    /**
     * @brief Helper method. Sets text on each ProcessingSettings
     * and fill their comboboxes
     */
    void fillProcessingSettings();

    /**
     * @brief Helper method. Scans image (if it is not null)
     * and displays it onto widget
     */
    void displayWarpedImage();

    /**
     * @brief Method is called whenever selected preprocessing
     * stage implementation changes (combobox value)
     * or value in QLineEdit changes
     * @param index index of stage
     * @param stage new stage that should replace old one
     */
    void preprocessingChanged(
            std::size_t index,
            std::shared_ptr<ds::IPreprocessingStage> stage);


};
#endif // MAINWINDOW_H
