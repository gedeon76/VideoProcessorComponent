/* \brief

This is a class for access local video from a USB camera
This is though for testing purposes or as a tool
for local teleoperation testbeds.
*/

/*
PROJECT:	3DPOINTER
COMPONENT:	VIDEO PROCESSOR
DATE:		27.05.15
AUTHOR:		HENRY PORTILLA
SPECIAL
THANKS:		GOD
*/

#pragma once

#include "commonVideoProcessorComponent.h"
#include <thread>

// include circular buffer to be used like a reconfigurable fixed size image buffer
#include <boost\circular_buffer.hpp>
#include <boost\circular_buffer\space_optimized.hpp>

const int DEFAULT_BUFFER_SIZE = 10;

class LocalVideo
{
public:
	LocalVideo();
	~LocalVideo();

	/// set the camera name
	/// @param[in,out] cameraName name given to this camera
	void setCameraName(std::string &cameraName);

	/// get the camera name
	/// @param[in,out] cameraName name given to this camera
	void getCameraName(std::string &cameraName);

	/// connect to the camera and start a thread for recovery images
	/// @param[in,out] cameraID is the ID for this camera
	/// @param[in] width image width for this camera
	/// @param[in] height image height for this camera
	void startCamera(int &cameraID, int width, int height);

	/// get the last image from the camera image buffer
	/// @param[in,out] cameraImage save the last available image	
	void getImage(cv::Mat &cameraImage);

	/// set the desired frame rate for the camera
	/// @param[in,out] fps seth the frame per second for this camera, here there will be camera real capacities
	void setFrameRate(int &fps);

	/// stop the camera
	void stopCamera();


private:

	int cameraID;				///< camera identification
	int fps;					///< set the current frame per seconds for this camera
	int width, height;			///< width and heigh of the camera image
	std::string cameraModel;	///< save the camera model
	boost::circular_buffer_space_optimized<cv::Mat> imageBuffer;
								///< image buffer

};
