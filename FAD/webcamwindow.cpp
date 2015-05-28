///fichier webcamwindow.cpp
/// Createur: Arnaud DENIZET
/// Binome: DAVY/DENIZET

#include "webcamwindow.h"

using namespace cv;

WebCamWindow::WebCamWindow(QWidget *parent)
    : QWidget(parent)
{
    frameWidth_=640;
    frameHeight_=480;
    templateWidth_=50;
    templateHeight_=50;

    label_ = new QLabel(tr("Image"));
    detectCheckBox_ = new QCheckBox(tr("Detection initiale"));
    trackCheckBox_= new QCheckBox(tr("Démarrer le tracking"));

    Mat imageRef;
    Mat imageAcquisition;

    QHBoxLayout *hl=new QHBoxLayout;
    hl->addWidget(detectCheckBox_);
    hl->addWidget(trackCheckBox_);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label_);
    layout->addLayout(hl);

    setLayout(layout);

    timer_=new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(aquire()));



    startWebCam();

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
            //  *webcam_ >> imgCam_;
            // ::resize(imgCam_,image_,Size(),0.8,0.8,CV_INTER_AREA);
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

    imageRef = Mat(image_, rectRoi);
    imageRef.copyTo(imgRoi_);
    roi.copyTo(imgOrigin_);
    //imshow("roi", imgRoi_);
    waitKey(10);


}

void WebCamWindow::trackHand()
{
    Mat result;

    /// Create the result matrix
     int result_cols =  image_.cols - imgRoi_.cols + 1;
     int result_rows = image_.rows - imgRoi_.rows + 1;

     //qDebug()<<"WebCamWindow - trackHand(): " << result_cols<<endl;
     //qDebug()<<"WebCamWindow - trackHand(): "<< result_rows<<endl;

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
        //qDebug()<<"WebCamWindow - trackHand(): "<< matchLoc.x <<endl;
        //qDebug()<<"WebCamWindow - trackHand(): "<< matchLoc.y <<endl;


       /// Mise à jour de la photo d'origine

        cv::Rect rectRoi(matchLoc.x, matchLoc.y,templateWidth_,templateHeight_);

        Mat roi(image_, rectRoi);
        roi.copyTo(imgRoi_);

        emit emitPoint(matchLoc);

      /// Show me what you got
          rectangle( image_, matchLoc, Point( matchLoc.x + imgRoi_.cols , matchLoc.y + imgRoi_.rows ), Scalar(0, 255, 255), 2, 8, 0 );
          rectangle( result, matchLoc, Point( matchLoc.x + imgRoi_.cols , matchLoc.y + imgRoi_.rows ), Scalar(0,255,255), 2, 8, 0 );

        //  imshow( "image_window", imgRoi_ );
         //imshow( "result_window", result );






}


