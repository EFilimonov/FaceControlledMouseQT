#ifndef FACETRACKER_H
#define FACETRACKER_H

#include <QObject>
#include <QThread>
//#include <QTimer>
#include <QDebug>
#include "tracker.h"


class FaceTracker : public QObject
{
        Q_OBJECT

public:
    explicit FaceTracker(QObject *parent = nullptr);

public:
    void trackFace();
    void frameFaceTracking();

public slots:
    void stopFaceTracking();
    void faceTracking();

private:
    bool stopped;


public:
    int facetrackerTimeout = 300;
    bool needReadFlag = true;
    bool loadedFrontalfaceModelFlag = false;
    Tracker* ptrTracker;
    cv::CascadeClassifier frontalFaceDetector;
};

#endif // FACETRACKER_H

