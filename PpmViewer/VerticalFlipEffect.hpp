#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class VerticalFlipEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		int count = 0;
		int new_x = 0;
		int new_y = 0;
		vector<vector<Pixel>> copy{};
		copy.resize(doc.getHeight());

		for (int i = 0; i < doc.getHeight(); i++)
		{
			copy[i].resize(doc.getWidth());
		}

		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				copy[i][j] = doc[i][j];
			}
		}
		for (int i = doc.getHeight() - 1; i >= 0; i--)
		{
			for (int j = 0; j < doc[i].size(); j++)
			{
				doc[count][j] = copy[i][j];
				new_x++;
			}
			count++;
			new_y++;
			new_x = 0;
		}
	}
};