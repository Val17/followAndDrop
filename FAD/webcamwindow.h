#ifndef WEBCAMWINDOW_H
#define WEBCAMWINDOW_H

#include <QtWidgets>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>


class WebCamWindow : public QWidget
{
    Q_OBJECT
    
public:
    WebCamWindow(QWidget *parent = 0);
    ~WebCamWindow();
    void displayImage();
    void detectHand();
    void trackHand();
    int getFrameWidth() { return frameWidth_;}
    int getFrameHeight() { return frameHeight_;}
    int getTemplateWidth() { return templateWidth_;}
    int getTemplateHeight() { return templateHeight_;}


private slots:
    void aquire();
    void startWebCam();

signals:
    void emitPoint(cv::Point handPoint);

private:
    int frameWidth_;
    int frameHeight_;
    int templateWidth_;
    int templateHeight_;
    QPushButton *webCamButton_;
    QCheckBox *detectCheckBox_;
    QCheckBox *trackCheckBox_;
    QTimer *timer_;
    QLabel *label_;
    cv::Mat imgCam_;
    cv::Mat image_;
    cv::Mat imgRoi_;
    cv::Mat imgOrigin_;
    cv::VideoCapture *webcam_;
    cv::Point matchLoc;
    cv::Mat imageRef;

    };

#endif // WEBCAMWINDOW_H
