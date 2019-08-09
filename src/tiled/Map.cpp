//
// Created by robin on 31.07.2019.
//

#include "Map.h"
#include "../objects/Color.hpp"
#include "../objects/Vector2.hpp"

tson::Map::Map(const nlohmann::json &json)
{
    parse(json);
}

/*!
 * Parses a json of a Tiled map.
 * @param json A json object with the format of Map
 * @return true if all mandatory fields was found. false otherwise.
 */
bool tson::Map::parse(const nlohmann::json &json)
{
    bool allFound = true;
    if(json.count("backgroundcolor") > 0) m_backgroundColor = Colori(json["backgroundcolor"].get<std::string>()); //Optional
    if(json.count("width") > 0 && json.count("height") > 0 )
        m_size = {json["width"].get<int>(), json["height"].get<int>()}; else allFound = false;
    if(json.count("hexsidelength") > 0) m_hexsideLength = json["hexsidelength"].get<int>();         //Optional
    if(json.count("infinite") > 0) m_isInfinite = json["infinite"].get<bool>();                     //Optional
    if(json.count("nextlayerid") > 0) m_nextLayerId = json["nextlayerid"].get<int>();               //Optional
    if(json.count("nextobjectid") > 0) m_nextObjectId = json["nextobjectid"].get<int>(); else allFound = false;
    if(json.count("orientation") > 0) m_orientation = json["orientation"].get<std::string>(); else allFound = false;
    if(json.count("renderorder") > 0) m_renderOrder = json["renderorder"].get<std::string>();       //Optional
    if(json.count("staggeraxis") > 0) m_staggerAxis = json["staggeraxis"].get<std::string>();       //Optional
    if(json.count("staggerindex") > 0) m_staggerIndex = json["staggerindex"].get<std::string>();    //Optional
    if(json.count("tiledversion") > 0) m_tiledVersion = json["tiledversion"].get<std::string>(); else allFound = false;
    if(json.count("tilewidth") > 0 && json.count("tileheight") > 0 )
        m_tileSize = {json["tilewidth"].get<int>(), json["tileheight"].get<int>()}; else allFound = false;
    if(json.count("type") > 0) m_type = json["type"].get<std::string>();                            //Optional
    if(json.count("version") > 0) m_version = json["version"].get<int>(); else allFound = false;

    //More advanced data
    if(json.count("layers") > 0 && json["layers"].is_array())
        std::for_each(json["layers"].begin(), json["layers"].end(), [&](const nlohmann::json &item) { m_layers.emplace_back(item); });
    if(json.count("tilesets") > 0 && json["tilesets"].is_array())
        std::for_each(json["tilesets"].begin(), json["tilesets"].end(), [&](const nlohmann::json &item) { m_tilesets.emplace_back(item); });
    if(json.count("properties") > 0 && json["properties"].is_array())
        std::for_each(json["properties"].begin(), json["properties"].end(), [&](const nlohmann::json &item) { m_properties.add(item); });

    return allFound;
}

const tson::Colori &tson::Map::getBackgroundColor() const
{
    return m_backgroundColor;
}

const tson::Vector2<int> &tson::Map::getSize() const
{
    return m_size;
}

int tson::Map::getHexsideLength() const
{
    return m_hexsideLength;
}

bool tson::Map::isInfinite() const
{
    return m_isInfinite;
}

int tson::Map::getNextLayerId() const
{
    return m_nextLayerId;
}

int tson::Map::getNextObjectId() const
{
    return m_nextObjectId;
}

const std::string &tson::Map::getOrientation() const
{
    return m_orientation;
}

const std::string &tson::Map::getRenderOrder() const
{
    return m_renderOrder;
}

const std::string &tson::Map::getStaggerAxis() const
{
    return m_staggerAxis;
}

const std::string &tson::Map::getStaggerIndex() const
{
    return m_staggerIndex;
}

const std::string &tson::Map::getTiledVersion() const
{
    return m_tiledVersion;
}

const tson::Vector2<int> &tson::Map::getTileSize() const
{
    return m_tileSize;
}

const std::string &tson::Map::getType() const
{
    return m_type;
}

int tson::Map::getVersion() const
{
    return m_version;
}

const std::vector<tson::Layer> &tson::Map::getLayers() const
{
    return m_layers;
}

tson::PropertyCollection &tson::Map::getProperties()
{
    return m_properties;
}

const std::vector<tson::Tileset> &tson::Map::getTilesets() const
{
    return m_tilesets;
}

