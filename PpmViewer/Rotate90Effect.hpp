#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class Rotate90Effect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		int copy_width = doc.getHeight();
		int copy_height = doc.getWidth();
		vector<vector<Pixel>> newv{};
		newv.resize(copy_height);
		for (int i = 0; i < newv.size(); i++)
		{
			newv[i].resize(copy_width);
		}

		for (int i = 0; i < doc.getWidth(); i++)
		{
			vector<Pixel> temp_vect;
			for (int j = doc.getHeight() - 1; j >= 0; j--)
			{
				temp_vect.push_back(doc[j][i]);
			}
			newv[i] = temp_vect;
		}

		doc.setHeight(copy_height);
		doc.setWidth(copy_width);
		doc.resizeRGBY(copy_height);
		doc.resizeRGBX(copy_width);

		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				doc[i][j] = newv[i][j];
			}
		}
		
	}
};