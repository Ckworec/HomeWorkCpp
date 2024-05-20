#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#define eps 1.0e-15

struct Color{
    float r, g, b;

    Color();
    Color(float r, float g, float b);
    ~Color();
};

class Image{
    public:
        Image(int width, int height);
        ~Image();

        Color GetColor(int x, int y) const;
        void SetColor(const Color& color, int x, int y);

        void Read(const char* filename);
        void Export(const char* filename);

        void Brightness(Image& im, const char* name);
    private:
        int m_width;
        int m_height;
        std :: vector<Color> m_colors;
};