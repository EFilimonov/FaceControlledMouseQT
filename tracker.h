#ifndef TRACKER_H
#define TRACKER_H

#include <QThread>
#include <QObject>
#include <QPixmap>
#include "opencv2/opencv.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <opencv2/highgui/highgui_c.h>
#include "Ewma.h"
#include <opencv2/tracking.hpp>
#include <opencv2/tracking/tracking_legacy.hpp>
#include <QScreen>
#include <QApplication>
#include <QMessageBox>
#include <QCursor>
#include <QTimer>


#include <QDebug>


class PointMosse
{
    public:
        cv::Rect2d facialRectangle;
        cv::Ptr<cv::legacy::Tracker> facialTracker;
        //Ewma facialFilterX;
        //Ewma facialFilterY;
        bool needInit = false;
        cv::Point2f pointNew;
        cv::Point2f pointOld;
        cv::Point2f pointDelta;
};


class Tracker : public QThread
{

    Q_OBJECT
public:
    explicit Tracker(QObject *parent = nullptr);

signals:
    void inDisplay(QPixmap pixmap);
//    void outDisplay(QPixmap pixmap);
    void cursorPosition(QPoint qp);
    void cursorDisplacement(float dist);
    void quickClickSignal(bool detect);
    void timerClickSignal(bool detect);
    void newFrame();
    void checkStart();

public slots:
//   void tracking();
    void frameTracking();
    void stopTracking();
    void preTrackingActions();

private:
    bool stopped = false;

public:
    QImage frameQImage;
    QPixmap frameQPixmap;
   // int facetrackerTimeout = 300;
    int trackerTimeout = 80;
    QTimer* faceTrackerTimer;
    int faceFPScounter = 0;
   int faceFPS = 3;
   int cameraIndex = 0;
    //FaceTracker *facetracker;
//    QElapsedTimer *fpsTimer;

private:
  void run() override;


public:
    void initiateTracker();
    void geoSmileCalculation(cv::Mat& im, std::vector<cv::Point2f>& landmarks);
    void calclMousePos(cv::Point2f deltaPoint, int faceH);
    bool Tracking();
    int getAngleABC(cv::Point2d a, cv::Point2d b, cv::Point2d c);
    cv::Point2f rotate2d(const cv::Point2f& inPoint, const double& angRad);
    cv::Point2f rotatePoint(const cv::Point2f& inPoint, const cv::Point2f& center, const double& angRad);
    cv::Rect calculateCrop(cv::Rect _crop, cv::Size _frame);


    void OnSetMousehook();
    void OnUnhookMouse();
    void UnhookMouse();

    void calculateMosseTrackers(cv::Mat _frame, cv::Mat _frame_gray);
    bool initFacialTracker(int i, cv::Mat _frame_gray);

    void addNewPoints();

    void addFacialTracker(cv::Point2f _pt, cv::Rect2d _trackingRectangle);





cv::Point2i cursorPos;
cv::Point2i oldDelta;

    float velocityScale;
    float velocitySlider = 3;
    float velocityK = 0.046;

    bool openFlag = true;
    bool turnOffClick = true;

    bool mouseHookPause = false;
    bool buttonStop = false;
    //float pauseTime = 5.0;

    bool faceInitiatedFlag = false;

    bool loadedFrontalfaceModelFlag = false;
    bool loadedFacemarkModelFlag = false;
    bool loadedSmileModelFlag = false;

    cv::VideoCapture cap;
    cv::CascadeClassifier frontalFaceDetector;
    cv::CascadeClassifier smileDetector;
    CvTermCriteria termcrit;
    int minFaceNeighbors = 5;
    cv::Ptr<cv::face::Facemark> facemark;
    bool facemarkDetectedFlag = false;
    bool faceDetectedFlag = false;

    bool firstFaceCropFlag = true;

    cv::Mat frame, frame_gray, faceROI, equalizerROI;



    // Vector of returned faces
    std::vector<cv::Rect> faces, oldfaces;

    std::vector<std::vector<cv::Point2f> > landmarks;


    bool needToTrackerInit = true;
    bool needToAddPoints = false;

    std::vector<cv::Point2f> pointsT;

    cv::Point2f trackPoint;
    cv::Point2f trackMousePoint;

    cv::Point2f smileAngle;
    float smilingAnCalcCorr;
    float correctedAng;
    Ewma ewmaSmileFilterObj;
    Ewma ewmasmilingAnCalcCorrObj;

    Ewma facialFilterX;
    Ewma facialFilterY;

    cv::String inptext;
    cv::String facetext = "Face not detected";
    cv::String tempinptext;

#define POINTCOLOR cv::Scalar(0, 79, 241)

#define CORRECTIONCOLOR cv::Scalar(50, 255, 50)

#define CORRECTIONALERTCOLOR cv::Scalar(1, 4, 209)

    float dxTrackPointSum = 0;
    float dyTrackPointSum = 0;
    float dxTrackPoint = 0;
    float dyTrackPoint = 0;
    float olDdDMouseX = 0;
    float olDdDMouseY = 0;

    cv::Rect cropToTrack;
    cv::Rect cropEqualizer;

    std::vector<uchar> status;
    std::vector<float> err;

#define QUALITY_LEVEL  0.001
    double minDistRatio = 4.0; // cels num per crop (more -> dencer)
    double minDist = 10;

    int minCornersCount = 7;
    int maxCornersCount = 25;

#define ULTRASMALLMOVECOLOR cv::Scalar(1, 209, 4)
#define SMALLMOVECOLOR cv::Scalar(1, 209, 4)
#define ULTRASMALL_DELTA_LIMIT 8000 //  ultrasmall/small movement, bigger -> more sensitive
    double ultraSmallDelta;


    bool allowMove;

#define PI 3.1415926535

    float captureHorizontal;
    float captureVertical;
    float horSensitivity = 1.6;
    float verSensitivity = 1.8;
    float horScale = 8;
    float verScale = 8;
    int horLimit = 0;
    int vertLimit = 0;
    float deltaXpos = 0;
    float deltaYpos = 0;
    int mouseX = 0;
    int mouseY = 0;

    float mdt = 0.04;
    float mds;
    float mv;

    int correctedDX, correctedDY;

    std::vector<cv::Rect> smiles;
    int noseNoseLenth = 1;
    int eyeEyeLenth = 1;
    float rotationHeadRatio = 1;
    int smilingAngle = 60;
    cv::Point corrAB, corrBC;
    int smilingTriggerAngle = 100;
    cv::Rect smileAIrect;

    int minNeighborsSmileDetector = 60;

    bool detectSmileGeoFlag = false;
    bool detectSmileAIFlag = false;
    bool detectDwellFlag = true;
    bool smileGeoDetectedFlag = false;
    bool smileAIDetectedFlag = false;

    bool isQuickClick = true;
    bool quickSmileUnlocked = true;

//	Timer moveLockTimer;
    bool skipHook = false;

    bool needEqualize = false;

    cv::Point2f dMouse;
    cv::Point2f dMouseOld;

    bool flipCameraFlag = true;
    bool showVideoFlag = true;

    double ewmaAlpha = 0.6;
    double ewmaSmileAlpha = 0.6;
    //0.1 Less smoothing - faster to detect changes, but more prone to noise
    //0.01 More smoothing - less prone to noise, but slower to detect changes
    float boxWidth;
    float boxHeight;
    float boxRatio = 2.0;

    std::vector<PointMosse> pointsMosse;
    int activeTrackers = 0;
    bool skipframe = true;

    cv::Rect2d trackingRectangle;



};

#endif // TRACKER_H
