#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
};
#endif // MAINWINDOW_H
