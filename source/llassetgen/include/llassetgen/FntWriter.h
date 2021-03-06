
#pragma once


#include <set>
#include <string>
#include <vector>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <llassetgen/Image.h>
#include <llassetgen/packing/Types.h>


namespace llassetgen
{


struct Info
{
    std::string face;
    int size;
    bool isBold;
    bool isItalic;
    std::string charset;
    bool useUnicode;
};


struct Common
{
    int lineHeight;
    int base;
    int scaleW;
    int scaleH;
    int pages;
    bool isPacked;
    struct padding {
        float left;
        float right;
        float up;
        float down;
    } padding;
    /*
    float stretchH;
    bool useSmoothing;
    int supersamplingLevel;
    struct spacing {
            float horiz;
            float vert;
    } spacing;
    float outlineThickness;
    */
};


struct CharInfo
{
    int id;
    int x;
    int y;
    int width;
    int height;
    float xOffset;
    float yOffset;
    float xAdvance;
    int page;
    uint8_t chnl;
};


struct KerningInfo
{
    int firstId;
    int secondId;
    float kerning;
};


class LLASSETGEN_API FntWriter
{
public:
    FntWriter(FT_Face face, const std::string & faceName, unsigned int fontSize, float scalingFactor, bool scaledGlyph);
    void readFont(std::set<FT_ULong>::iterator charcodesBegin, std::set<FT_ULong>::iterator charcodesEnd);
    void setAtlasProperties(const Vec2<PackingSizeType> & size, int maxHeight, int padding);
    void saveFnt(const std::string & filepath);
    void setCharInfo(FT_UInt charcode, const Rect<PackingSizeType> & charArea, const Vec2<float> & offset);

private:
    void setFontInfo();
    void setKerningInfo(std::set<FT_ULong>::iterator charcodesBegin, std::set<FT_ULong>::iterator charcodesEnd);

private:
    const FT_Face face;
    const std::string faceName;
    Info fontInfo;
    Common fontCommon;
    std::vector<CharInfo> charInfos;
    std::vector<KerningInfo> kerningInfos;
    FT_Pos maxYBearing;
    float scalingFactor;
    bool scaledGlyph;
};


} // namespace llassetgen
