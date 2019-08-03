//
// Created by robin on 02.08.2019.
//

#include "Tileset.h"

tson::Tileset::Tileset(const nlohmann::json &json)
{
    parse(json);
}

bool tson::Tileset::parse(const nlohmann::json &json)
{
    bool allFound = true;

    if(json.count("columns") > 0) m_columns = json["columns"].get<int>(); else allFound = false;
    if(json.count("firstgid") > 0) m_firstgid = json["firstgid"].get<int>(); else allFound = false;
    if(json.count("image") > 0) m_image = fs::path(json["image"].get<std::string>()); else allFound = false;
    if(json.count("margin") > 0) m_margin = json["margin"].get<int>(); else allFound = false;
    if(json.count("name") > 0) m_name = json["name"].get<std::string>(); else allFound = false;
    if(json.count("spacing") > 0) m_spacing = json["spacing"].get<int>(); else allFound = false;
    if(json.count("tilecount") > 0) m_tileCount = json["tilecount"].get<int>(); else allFound = false;
    if(json.count("transparentcolor") > 0) m_transparentColor = tson::Color(json["transparentcolor"].get<std::string>()); //Optional
    if(json.count("type") > 0) m_type = json["type"].get<std::string>(); //Optional

    if(json.count("imagewidth") > 0 && json.count("imageheight") > 0)
        m_imageSize = {json["imagewidth"].get<int>(), json["imageheight"].get<int>()}; else allFound = false;
    if(json.count("tilewidth") > 0 && json.count("tileheight") > 0)
        m_tileSize = {json["tilewidth"].get<int>(), json["tileheight"].get<int>()}; else allFound = false;

    return allFound;
}

int tson::Tileset::getColumns() const
{
    return m_columns;
}

int tson::Tileset::getFirstgid() const
{
    return m_firstgid;
}

const fs::path &tson::Tileset::getImagePath() const
{
    return m_image;
}

const tson::Vector2i &tson::Tileset::getImageSize() const
{
    return m_imageSize;
}

int tson::Tileset::getMargin() const
{
    return m_margin;
}

const std::string &tson::Tileset::getName() const
{
    return m_name;
}

int tson::Tileset::getSpacing() const
{
    return m_spacing;
}

int tson::Tileset::getTileCount() const
{
    return m_tileCount;
}

const tson::Vector2i &tson::Tileset::getTileSize() const
{
    return m_tileSize;
}

const tson::Color &tson::Tileset::getTransparentColor() const
{
    return m_transparentColor;
}

const std::string &tson::Tileset::getType() const
{
    return m_type;
}