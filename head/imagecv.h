#ifndef IMAGECV_H
#define IMAGECV_H

#include <QWidget>
#include <opencv2/core/mat.hpp>

/**
 * @brief Class is responsible for drawing
 * opencv BGR888 images on QWidget
 */
class ImageCV : public QWidget
{
    Q_OBJECT

private:
    cv::Mat _buffer;
    QImage _qimage;

public:
    explicit ImageCV(QWidget *parent = nullptr);

public slots:

    /**
     * @brief Method rescales image to match widget size
     * and repaint widget.
     * @param image BGR888 image to draw
     */
    void show(const cv::Mat& image);

private:
    void paintEvent(QPaintEvent*);

};

#endif // IMAGECV_H
