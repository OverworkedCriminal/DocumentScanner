#include "../head/imagecv.h"

#include <opencv2/imgproc.hpp>

#include <QImage>
#include <QPainter>

ImageCV::ImageCV(QWidget *parent) : QWidget(parent)
{

}

void ImageCV::show(const cv::Mat &image)
{
    cv::resize(image, _buffer, cv::Size(width(), height()));
    _qimage = QImage(_buffer.data, _buffer.cols, _buffer.rows, _buffer.step, QImage::Format_BGR888);
    repaint();
}

void ImageCV::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(QPoint(0, 0), _qimage);
}
