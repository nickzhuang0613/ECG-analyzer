#pragma once
#include <vector>

class STAnalysis;

class ECGST
{
public:
  class Interval;
  class Episode;
  
  ECGST (void);
  ~ECGST (void);
  const std::vector< Interval > & getIntervals() const;
  const std::vector< Episode >& getEpisodes() const;
  const Interval& getIntervalAt(int i) const;
  const Episode& getEpisodeAt(int i) const;
  std::pair<int,int> getIntervalBeginAndEnd(int) const;
  std::pair<int,int> getEpisodeBeginAndEnd(int) const;
  
  class Interval {
  public:
    Interval(int r = 0, int iso = 0, int j = 0, int st = 0, double sl = 0.0, double of = 0.0);
    int rpoint;
    int isopoint;
    int jpoint;
    int stpoint;
    double slope;
    double offset;
    static double thresh;
    bool lower(const double& thresh = ECGST::Interval::thresh) const;
    bool higher(const double& thresh = ECGST::Interval::thresh) const;
    bool normal(const double& thresh = ECGST::Interval::thresh) const;
    std::pair<int, int> span() const;
  };
  
  class Episode {
  public:
    Episode (int s = 0, int e = 0);
    int start, end;
    std::pair<int, int> span() const;
  };
  
private:
  void addInterval(const ECGST::Interval &);
  void addEpisode(const ECGST::Episode &);
  
  std::vector<Interval> intervals;
  std::vector<Episode> episodes;
  
  friend class STAnalysis;
};

