#pragma once


#include "SimpleCV.h"
#include "smile.h"
#include "rimage.h"


class ofxSmile
{
public:
	static vector< pair<ofVec4f, float> > getSmile(ofImage img)
    {
		img.setImageType(OF_IMAGE_GRAYSCALE);

        ofFloatPixels floatPixels = img.getPixelsRef();

		MPSmile smileFinder;

    
		VisualObject faces;

        RImage<float> rimage(floatPixels.getPixels(),
                             floatPixels.getWidth(),
                             floatPixels.getHeight());

        ofVec4f vec = ofVec4f(0, 0, 0, 0);
        vector< pair<ofVec4f, float> > vecs;

		if (!smileFinder.findSmiles(rimage, faces))
        {
            for(VisualObject* face : faces) {
                vec.x = face->x;
                vec.y = face->y;
                vec.z = face->xSize;
                vec.w = face->ySize;
                vecs.push_back(make_pair(vec, face->activation));
            }
		}
		return vecs;
	}
};
