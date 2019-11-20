#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class SaveImageEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		ofstream stream;
		stream.open("SavedImage.ppm");
		stream << doc.getImageFormat() << endl;
		stream << doc.getWidth() << " " << doc.getHeight() << endl;
		stream << doc.getColorDepth() << endl;

		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				stream << doc[i][j] << " ";
			}
			stream << endl;
		}
	}
};