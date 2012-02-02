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
    std::string title, artist;
};

struct General
{
    std::string filename;
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
    BeatMap(const std::string &src);
    ~BeatMap();

    std::vector<Beat> const& beats() const { return m_beats; }
    std::vector<TimingPoint> const& timingpoints() const { return m_timingPoints; }
    Metadata const& metadata() const { return m_metadata; }
    General const& general() const { return m_general; }
    Difficulty const& difficulty() const { return m_difficulty; }

protected:
    bool isSectionHeader(const std::string &line) const;
    void parseBeatmap(const std::string &src);
    void parseMetadata(const std::string &line);
    void parseHitObject(const std::string &line);
    void parseGeneral(const std::string &line);
    void parseDifficulty(const std::string &line);
    void parseTimingPoint(const std::string &line);

    std::vector<Beat> m_beats;
    std::vector<TimingPoint> m_timingPoints;

    Metadata m_metadata;
    General m_general;
    Difficulty m_difficulty;


private:

    std::string &trim(std::string &s);
    std::string &ltrim(std::string &s);
    std::string &rtrim(std::string &s);
};

#endif // BEATMAP_H
