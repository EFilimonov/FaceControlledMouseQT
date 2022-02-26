#include "facetracker.h"

FaceTracker::FaceTracker(QObject *parent) : QObject(parent)
{

}


void FaceTracker::faceTracking()
{
    while(!stopped)
    {
        frameFaceTracking();
        QThread::msleep(facetrackerTimeout);
    }
}



void FaceTracker::frameFaceTracking()
{

    if(!ptrTracker->frame.empty())
    {
        trackFace();
        ptrTracker->preTrackingActions();
    }

}


void FaceTracker::trackFace()
{
    frontalFaceDetector.detectMultiScale(ptrTracker->frame_gray, ptrTracker->faces, 1.1, ptrTracker->minFaceNeighbors, cv::CASCADE_FIND_BIGGEST_OBJECT | cv::CASCADE_DO_CANNY_PRUNING, cv::Size(65, 65));
}


void FaceTracker::stopFaceTracking()
{
    stopped = true;
}
