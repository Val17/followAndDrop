#include <QtWidgets>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include "webcamwindow.h"

using namespace cv;

WebCamWindow::WebCamWindow(QWidget *parent)
    : QWidget(parent)
{
    frameWidth_=320;
    frameHeight_=240;
    templateWidth_=50;
    templateHeight_=50;

    webCamButton_ = new QPushButton(tr("Demarrer aquisition"));
    label_ = new QLabel(tr("Image"));
    detectCheckBox_ = new QCheckBox(tr("Detection initiale"));
    trackCheckBox_= new QCheckBox(tr("Tracking"));

    connect(webCamButton_, SIGNAL(clicked()), this, SLOT(startWebCam()));

    QVBoxLayout *vl1=new QVBoxLayout;
    vl1->addWidget(detectCheckBox_);
    vl1->addWidget(trackCheckBox_);
    QHBoxLayout *hl=new QHBoxLayout;
    hl->addWidget(webCamButton_);
    hl->addLayout(vl1);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label_);
    layout->addLayout(hl);

    setLayout(layout);
    setWindowTitle(tr("Track WebCam"));

    timer_=new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(aquire()));

 }

WebCamWindow::~WebCamWindow()
{
    delete webcam_;
}

void WebCamWindow::displayImage()
{
    if (image_.data!=NULL)
    {
        cv::flip(image_,image_,1); // process the image_
        // change color channel ordering
        cv::cvtColor(image_,image_,COLOR_BGR2RGB);
        // Qt image_
        QImage img= QImage((const unsigned char*)(image_.data),
                           image_.cols,image_.rows,QImage::Format_RGB888);
        // display on label_
        label_->setPixmap(QPixmap::fromImage(img));
        // resize the label_ to fit the image_
        label_->resize(label_->pixmap()->size());
    }
    else QMessageBox(QMessageBox::Critical,tr("Error"),tr("Image is void")).exec();
}


void WebCamWindow::aquire()
{
    if(webcam_->isOpened())
    {
        if (webcam_->read(image_))
        {
//            *webcam_ >> imgCam_;
//            ::resize(imgCam_,image_,Size(),0.5,0.5,CV_INTER_AREA);
            if (detectCheckBox_->isChecked() && !trackCheckBox_->isChecked()) detectHand();
            if (trackCheckBox_->isChecked()) trackHand();
            displayImage();
        }
    }
}

void WebCamWindow::startWebCam()
{
    if (!timer_->isActive())
    {
         webcam_= new cv::VideoCapture(0);
         //webcam_->set(CV_CAP_PROP_FRAME_WIDTH,frameWidth_);
         //webcam_->set(CV_CAP_PROP_FRAME_HEIGHT,frameHeight_);
         //qDebug()<<"width: "<<webcam_->get(CV_CAP_PROP_FRAME_WIDTH);
         //qDebug()<<"height: "<<webcam_->get(CV_CAP_PROP_FRAME_HEIGHT);

        timer_->start(20);
        webCamButton_->setText(tr("Arreter aquisition"));

    }
    else
    {
        timer_->stop();
        delete webcam_;
        webcam_=0;
        webCamButton_->setText(tr("Demarrer aquisition"));
    }
}

void WebCamWindow::detectHand()
{
    cv::Rect rectRoi((frameWidth_-templateWidth_)/2,(frameHeight_-templateHeight_)/2,templateWidth_,templateHeight_);
    rectangle(image_,rectRoi,Scalar( 0, 255, 255),2,8,0);

    Mat roi(image_, rectRoi);
    roi.copyTo(imgRoi_);
    roi.copyTo(imgOrigin_);
    imshow("roi", imgRoi_);
    waitKey(10);


}

void WebCamWindow::trackHand()
{
    Mat result;

    /// Create the result matrix
     int result_cols =  image_.cols - imgRoi_.cols + 1;
     int result_rows = image_.rows - imgRoi_.rows + 1;

     qDebug()<<"WebCamWindow - trackHand(): " << result_cols<<endl;
     qDebug()<<"WebCamWindow - trackHand(): "<< result_rows<<endl;

     result.create( result_rows, result_cols, CV_32FC1 );


     /// Do the Matching and Normalize

      matchTemplate( image_, imgRoi_, result, CV_TM_CCORR_NORMED);
      normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );

      /// Localizing the best match with minMaxLoc
        double minVal; double maxVal; Point minLoc; Point maxLoc;
        Point matchLoc;

        minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );


      /// For SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better

        matchLoc = maxLoc;
        qDebug()<<"WebCamWindow - trackHand(): "<< matchLoc.x <<endl;
        qDebug()<<"WebCamWindow - trackHand(): "<< matchLoc.y <<endl;


       /// Mise à jour de la photo d'origine

        cv::Rect rectRoi(matchLoc.x, matchLoc.y,templateWidth_,templateHeight_);

        Mat roi(image_, rectRoi);
        roi.copyTo(imgRoi_);



      /// Show me what you got
          rectangle( image_, matchLoc, Point( matchLoc.x + imgRoi_.cols , matchLoc.y + imgRoi_.rows ), Scalar(0, 255, 255), 2, 8, 0 );
          rectangle( result, matchLoc, Point( matchLoc.x + imgRoi_.cols , matchLoc.y + imgRoi_.rows ), Scalar(0,255,255), 2, 8, 0 );

        //  imshow( "image_window", imgRoi_ );
         imshow( "result_window", result );






}


