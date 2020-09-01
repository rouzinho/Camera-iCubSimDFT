/*======================================================================================================================

    Copyright 2011, 2012, 2013, 2014, 2015 Institut fuer Neuroinformatik, Ruhr-Universitaet Bochum, Germany

    This file is part of cedar.

    cedar is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    cedar is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
    License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with cedar. If not, see <http://www.gnu.org/licenses/>.

========================================================================================================================

    Institute:   Ruhr-Universitaet Bochum
                 Institut fuer Neuroinformatik

    File:        EarSubscriber.h

    Maintainer:  Tutorial Writer Person
    Email:       cedar@ini.rub.de
    Date:        2011 12 09

    Description:

    Credits:

======================================================================================================================*/

// CEDAR INCLUDES
#include "iCubCam.h"
#include <cedar/processing/ExternalData.h> // getInputSlot() returns ExternalData
#include <cedar/auxiliaries/MatData.h> // this is the class MatData, used internally in this step
#include "cedar/auxiliaries/math/functions.h"
#include <yarp/cv/Cv.h>
#include <cmath>
#include <iostream>

using namespace std;
using namespace yarp::sig;





// SYSTEM INCLUDES

//----------------------------------------------------------------------------------------------------------------------
// constructors and destructor
//----------------------------------------------------------------------------------------------------------------------
iCubCam::iCubCam()
:
cedar::proc::Step(true),
mOutput(new cedar::aux::MatData(cv::Mat::zeros(240, 320, CV_8UC3))),
//mLowerX(new cedar::aux::DoubleParameter(this,"lower x (motor)",-0.5)),
//mUpperX(new cedar::aux::DoubleParameter(this,"upper x (motor)",-0.2)),
//mLowerY(new cedar::aux::DoubleParameter(this,"lower y (motor)",-0.3)),
//mUpperY(new cedar::aux::DoubleParameter(this,"upper y (motor)",0.3)),
//mSizeX(new cedar::aux::IntParameter(this, "Size Field X",50)),
//mSizeY(new cedar::aux::IntParameter(this, "Size Field Y",50)),
mTopic(new cedar::aux::StringParameter(this, "Yarp Destination", "")),
mReconnect(new cedar::aux::DoubleParameter(this,"reconnect",0.0))
{
this->declareOutput("2D",mOutput);

/*mGaussMatrixSizes.clear();
mGaussMatrixCenters.clear();
mGaussMatrixSigmas.clear();
mGaussMatrixSizes.push_back(50);
mGaussMatrixSizes.push_back(50);
mGaussMatrixCenters.push_back(25);
mGaussMatrixCenters.push_back(25);
mGaussMatrixSigmas.push_back(3.0);
mGaussMatrixSigmas.push_back(3.0);
*/

//upper_x = -0.2;
//lower_x = -0.5;
//upper_y = 0.3;
//lower_y = -0.3;

//px = -0.4;
//py = 0;
//old_px = px;
//old_py = py;

//minX = sizeX;
//minY = sizeY;
//maxX = 0;
//maxY = 0;

//this->connect(this->mLowerX.get(), SIGNAL(valueChanged()), this, SLOT(reCompute()));
//this->connect(this->mUpperX.get(), SIGNAL(valueChanged()), this, SLOT(reCompute()));
//this->connect(this->mLowerY.get(), SIGNAL(valueChanged()), this, SLOT(reCompute()));
//this->connect(this->mUpperY.get(), SIGNAL(valueChanged()), this, SLOT(reCompute()));
//this->connect(this->mSizeX.get(), SIGNAL(valueChanged()), this, SLOT(reCompute()));
//this->connect(this->mSizeY.get(), SIGNAL(valueChanged()), this, SLOT(reCompute()));
this->connect(this->mTopic.get(), SIGNAL(valueChanged()), this, SLOT(reName()));
this->connect(this->mReconnect.get(), SIGNAL(valueChanged()), this, SLOT(reConnectYarp()));

}
//----------------------------------------------------------------------------------------------------------------------
// methods
//----------------------------------------------------------------------------------------------------------------------
//
void iCubCam::compute(const cedar::proc::Arguments&)
{
   cv::Mat test = cv::Mat::zeros(240, 320, CV_8UC3);
   yarp::sig::ImageOf<yarp::sig::PixelRgb> *image = inPort.read(false);
   if (image != NULL)
   {
      //int w = image->width();
      //int h = image->height();
      test = yarp::cv::toCvMat(*image);

   }

   //string s = in->get(0).toString();
   //px = stof(s);
   //s = in->get(1).toString();
   //py = stof(s);

  /*if(old_px != px && old_py != py)
  {
     int nx = setFieldPositionX(px);
     int ny = setFieldPositionY(py);
     mGaussMatrixSizes.clear();
     mGaussMatrixCenters.clear();
     mGaussMatrixSigmas.clear();
     mGaussMatrixSizes.push_back(size_y);
     mGaussMatrixSizes.push_back(size_x);
     mGaussMatrixCenters.push_back(ny);
     mGaussMatrixCenters.push_back(nx);
     mGaussMatrixSigmas.push_back(3.0);
     mGaussMatrixSigmas.push_back(3.0);
  }*/




  this->mOutput->setData(test);
  //old_px = px;
  //old_py = py;

}

int iCubCam::setFieldPositionX(float X)
{
   return ax * X + bx;
}

int iCubCam::setFieldPositionY(float Y)
{
   return ay * Y + by;
}

/*float iCubCam::distanceNumber(float x, float y)
{
   float dist = 0;
   if(x < 0 && y < 0)
   {
      dist = std::abs(x) - std::abs(y);
   }
   if(x < 0 && y > 0)
   {
      dist = std::abs(x) + y;
   }
   if(x > 0 && y > 0)
   {
      dist = y - x;
   }
   return dist;
}
*/
void iCubCam::reName()
{
   name_port = this->mTopic->getValue();
}

void iCubCam::reCompute()
{
   //size_x = this->mSizeX->getValue();
   //size_y = this->mSizeY->getValue();
   //lower_x = this->mLowerX->getValue();
   //upper_x = this->mUpperX->getValue();
   //lower_y = this->mLowerY->getValue();
   //upper_y = this->mUpperY->getValue();
   //ax = (static_cast<float>(size_x))/(upper_x-lower_x);
   //bx = 0 - (ax*lower_x);
   //ay = (static_cast<float>(size_y))/(upper_y-lower_y);
   //by = 0 - (ay*lower_y);
}

void iCubCam::reConnectYarp()
{
  inPort.open("/cedar/icubcam");
  //outPort.open(name_port);
  yarp.connect(name_port,inPort.getName());
}

void iCubCam::reset()
{

}
