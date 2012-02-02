#include "beatmap.h"

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

static const std::string s_strHitObjects    = "[HitObjects]";
static const std::string s_strMetadata      = "[Metadata]";
static const std::string s_strDifficulty    = "[Difficulty]";
static const std::string s_strGeneral       = "[General]";
static const std::string s_strTimingPoints  = "[TimingPoints]";

enum
{
    SECTION_METADATA        = 1,
    SECTION_HITOBJECTS      = 2,
    SECTION_GENERAL         = 3,
    SECTION_DIFFICULTY      = 4,
    SECTION_TIMINGPOINTS    = 5
};

BeatMap::BeatMap(const std::string &src)
{
    this->parseBeatmap(src);
}

BeatMap::~BeatMap()
{
}

bool BeatMap::isSectionHeader(const std::string &line) const
{
    return line[0] == '[' && line[line.length() - 1] == ']';
}

void BeatMap::parseBeatmap(const std::string &src)
{
    std::istringstream iss(src);
    std::string line;

    int cursection = 0;

    while(std::getline(iss, line))
    {

        if(isSectionHeader(line))
        {

            if(!s_strHitObjects.compare(line))
                cursection = SECTION_HITOBJECTS;
            else if(!s_strMetadata.compare(line))
                cursection = SECTION_METADATA;
            else if(!s_strDifficulty.compare(line))
                cursection = SECTION_DIFFICULTY;
            else if(!s_strGeneral.compare(line))
                cursection = SECTION_GENERAL;
            else if(!s_strTimingPoints.compare(line))
                cursection = SECTION_TIMINGPOINTS;
            else
                cursection = 0;
        }
        else
        {
            if(!cursection || line.length() < 1) continue;
            switch (cursection)
            {
            case SECTION_METADATA:
                this->parseMetadata(line); break;
            case SECTION_HITOBJECTS:
                this->parseHitObject(line); break;
            case SECTION_DIFFICULTY:
                this->parseDifficulty(line); break;
            case SECTION_GENERAL:
                this->parseGeneral(line); break;
            case SECTION_TIMINGPOINTS:
                this->parseTimingPoint(line); break;
            default:
                break;
            }
        }
    }

}

void BeatMap::parseMetadata(const std::string &line)
{
    std::string token;
    std::istringstream iss(line);
    if(std::getline(iss, token, ':'))
    {
        std::string value;
        std::getline(iss, value);
        std::transform(token.begin(), token.end(), token.begin(), ::tolower);
        if(!token.compare("title")) m_metadata.title = trim(value);
        else if(!token.compare("artist")) m_metadata.artist = trim(value);
    }
}

void BeatMap::parseHitObject(const std::string &line)
{
    Beat b;
    std::string token;
    std::istringstream iss(line);
    if(std::getline(iss, token, ',')) iss >> b.x;    // xcoord
    if(std::getline(iss, token, ',')) iss >> b.y;    // ycoord
    if(std::getline(iss, token, ',')) iss >> b.time; // time
    if(std::getline(iss, token, ',')) iss >> b.type; // type
    if(std::getline(iss, token, ',')) iss >> b.sound;// sound

    // further values specify slider information (@TODO: ex. bezier)
    switch(b.type)
    {
    case Beat::BEAT_CIRCLE:
        break;
    case Beat::BEAT_SLIDER:
        break;
    case Beat::BEAT_SPINNER:
        break;
    default: // unknown type?
        return;
    }

    m_beats.push_back(b);
}

void BeatMap::parseGeneral(const std::string &line)
{
    std::string token;
    std::istringstream iss(line);
    if(std::getline(iss, token, ':'))
    {
        std::string value;
        std::getline(iss, value);
        std::istringstream issv(value);
        std::transform(token.begin(), token.end(), token.begin(), ::tolower);
        if(!token.compare("audiofilename"))      m_general.filename = trim(value);
        else if(!token.compare("audioleadin"))   issv >> m_general.leadin;
        else if(!token.compare("previewtime"))   issv >> m_general.previewtime;
        else if(!token.compare("countdown"))     issv >> m_general.countdown;
        else if(!token.compare("previewtime"))   issv >> m_general.previewtime;
        else if(!token.compare("stackleniency")) issv >> m_general.stackleniency;
    }
}

void BeatMap::parseDifficulty(const std::string &line)
{
    std::string token;
    std::istringstream iss(line);
    if(std::getline(iss, token, ':'))
    {
        std::string value;
        std::getline(iss, value);
        std::istringstream issv(value);
        std::transform(token.begin(), token.end(), token.begin(), ::tolower);
        if(!token.compare("hpdrainrate"))           issv >> m_difficulty.drain;
        else if(!token.compare("circlesize"))       issv >> m_difficulty.circlesize;
        else if(!token.compare("approachrate"))     issv >> m_difficulty.approach;
        else if(!token.compare("slidermultiplier")) issv >> m_difficulty.slidermux;
        else if(!token.compare("slidertickrate"))   issv >> m_difficulty.slidertick;
    }
}

void BeatMap::parseTimingPoint(const std::string &line)
{
    TimingPoint tp;

    std::string token;
    std::istringstream iss(line);

    if(std::getline(iss, token, ','))
    {
        std::istringstream issv(token);
        issv >> tp.time;
    }
    if(std::getline(iss, token, ','))
    {
        std::istringstream issv(token);
        issv >> tp.beatlength;
    }

    m_timingPoints.push_back(tp);
}

std::string &BeatMap::trim(std::string &s)
{
     return ltrim(rtrim(s));
}

std::string &BeatMap::ltrim(std::string &s)
{
    s.erase(s.begin(),
            std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

std::string &BeatMap::rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
            s.end());
    return s;
}
