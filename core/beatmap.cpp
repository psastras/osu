#include "beatmap.h"

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

static const std::wstring s_strHitObjects    = L"[HitObjects]";
static const std::wstring s_strMetadata      = L"[Metadata]";
static const std::wstring s_strDifficulty    = L"[Difficulty]";
static const std::wstring s_strGeneral       = L"[General]";
static const std::wstring s_strTimingPoints  = L"[TimingPoints]";

enum
{
    SECTION_METADATA        = 1,
    SECTION_HITOBJECTS      = 2,
    SECTION_GENERAL         = 3,
    SECTION_DIFFICULTY      = 4,
    SECTION_TIMINGPOINTS    = 5
};

BeatMap::BeatMap(const std::wstring &src)
{
    this->parseBeatmap(src);
}

BeatMap::~BeatMap()
{
}


bool BeatMap::isSectionHeader(const std::wstring &line) const
{

	std::wstring copy = line;
	copy = trim(copy);
	return line[0] == '[' && line[line.length() - 1] == ']';
}

void BeatMap::parseBeatmap(const std::wstring &src)
{
	std::wistringstream iss(src);
	std::wstring line;

    int cursection = 0;

	while(std::getline(iss, line)) //this should trim newlines...?
	{
		if (line[line.length() - 1] == '\r' || line[line.length() - 1] == '\n')
			line = line.substr(0, line.length() - 1);

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

void BeatMap::parseMetadata(const std::wstring &line)
{
	std::wstring token;
	std::wistringstream iss(line);
	if(std::getline(iss, token, L':'))
    {
		std::wstring value;
        std::getline(iss, value);
        std::transform(token.begin(), token.end(), token.begin(), ::tolower);
		if(!token.compare(L"title")) m_metadata.title = trim(value);
		else if(!token.compare(L"artist")) m_metadata.artist = trim(value);
    }
}

void BeatMap::parseHitObject(const std::wstring &line)
{
    Beat b;
	std::wstring token;
	std::wistringstream iss(line);
	if(std::getline(iss, token, L',')) iss >> b.x;    // xcoord
	if(std::getline(iss, token, L',')) iss >> b.y;    // ycoord
	if(std::getline(iss, token, L',')) iss >> b.time; // time
	if(std::getline(iss, token, L',')) iss >> b.type; // type
	if(std::getline(iss, token, L',')) iss >> b.sound;// sound

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

void BeatMap::parseGeneral(const std::wstring &line)
{

	std::wstring token;
	std::wistringstream iss(line);
	if(std::getline(iss, token, L':'))
    {
		std::wstring value;
        std::getline(iss, value);
		std::wistringstream issv(value);
        std::transform(token.begin(), token.end(), token.begin(), ::tolower);
		if(!token.compare(L"audiofilename"))      m_general.filename = trim(value);
		else if(!token.compare(L"audioleadin"))   issv >> m_general.leadin;
		else if(!token.compare(L"previewtime"))   issv >> m_general.previewtime;
		else if(!token.compare(L"countdown"))     issv >> m_general.countdown;
		else if(!token.compare(L"previewtime"))   issv >> m_general.previewtime;
		else if(!token.compare(L"stackleniency")) issv >> m_general.stackleniency;
    }
}

void BeatMap::parseDifficulty(const std::wstring &line)
{
	std::wstring token;
	std::wistringstream iss(line);
	if(std::getline(iss, token, L':'))
    {
		std::wstring value;
        std::getline(iss, value);
		std::wistringstream issv(value);
        std::transform(token.begin(), token.end(), token.begin(), ::tolower);
		if(!token.compare(L"hpdrainrate"))           issv >> m_difficulty.drain;
		else if(!token.compare(L"circlesize"))       issv >> m_difficulty.circlesize;
		else if(!token.compare(L"approachrate"))     issv >> m_difficulty.approach;
		else if(!token.compare(L"slidermultiplier")) issv >> m_difficulty.slidermux;
		else if(!token.compare(L"slidertickrate"))   issv >> m_difficulty.slidertick;
    }
}

void BeatMap::parseTimingPoint(const std::wstring &line)
{
    TimingPoint tp;

	std::wstring token;
	std::wistringstream iss(line);

	if(std::getline(iss, token, L','))
    {
		std::wistringstream issv(token);
        issv >> tp.time;
    }
	if(std::getline(iss, token, L','))
    {
		std::wistringstream issv(token);
        issv >> tp.beatlength;
    }

    m_timingPoints.push_back(tp);
}

std::wstring &BeatMap::trim(std::wstring &s) const
{
     return ltrim(rtrim(s));
}

std::wstring &BeatMap::ltrim(std::wstring &s) const
{
    s.erase(s.begin(),
            std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

std::wstring &BeatMap::rtrim(std::wstring &s) const
{
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
            s.end());
    return s;
}
