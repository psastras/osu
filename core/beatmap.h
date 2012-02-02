#ifndef BEATMAP_H
#define BEATMAP_H

#include <string>
#include <vector>

struct Beat
{
    int x, y;
    int time, type, sound;

    enum {
        BEAT_CIRCLE = 5,
        BEAT_SLIDER = 6,
        BEAT_SPINNER = 12
    };
};

struct Metadata
{
	std::wstring title, artist;
};

struct General
{
	std::wstring filename;
    int leadin, previewtime, countdown;
    float stackleniency;
};

struct Difficulty
{
    int drain, circlesize, approach;
    float slidermux, slidertick;
};

struct TimingPoint
{
    int time;
    float beatlength;
};

class BeatMap
{
public:
	BeatMap(const std::wstring &src);
    ~BeatMap();

    std::vector<Beat> const& beats() const { return m_beats; }
    std::vector<TimingPoint> const& timingpoints() const { return m_timingPoints; }
    Metadata const& metadata() const { return m_metadata; }
    General const& general() const { return m_general; }
    Difficulty const& difficulty() const { return m_difficulty; }

	void draw(int time);

protected:
	bool isSectionHeader(const std::wstring &line) const;
	void parseBeatmap(const std::wstring &src);
	void parseMetadata(const std::wstring &line);
	void parseHitObject(const std::wstring &line);
	void parseGeneral(const std::wstring &line);
	void parseDifficulty(const std::wstring &line);
	void parseTimingPoint(const std::wstring &line);

    std::vector<Beat> m_beats;
    std::vector<TimingPoint> m_timingPoints;

    Metadata m_metadata;
    General m_general;
    Difficulty m_difficulty;


private:

	std::wstring &trim(std::wstring &s) const;
	std::wstring &ltrim(std::wstring &s) const;
	std::wstring &rtrim(std::wstring &s) const;
};

#endif // BEATMAP_H
