#ifndef PLAYBACKTRAITS_H_INCLUDED
#define PLAYBACKTRAITS_H_INCLUDED

class Replay;
class ReplayList;

class ReplayTraits {
    public:
        typedef Replay
            PlaybackType;

        typedef ReplayList
            ListType;

        static const bool IsReplayType = true;
};

class Savegame;
class SavegameList;

class SavegameTraits {
    public:
        typedef Savegame
            PlaybackType;

        typedef SavegameList
            ListType;

        static const bool IsReplayType = false;
};

#endif // PLAYBACKTRAITS_H_INCLUDED
