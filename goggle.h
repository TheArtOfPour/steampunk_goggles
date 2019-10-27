#pragma once

class Goggle {
    public:
        Goggle();
        void initGoggles(int r, int l);
        void open();
        void openLeft();
        void openRight();
        void close();
        void closeLeft();
        void closeRight();
        void blink();
        void adjustLeft(int amount);
        void adjustRight(int amount);
        void adjustBoth(int amount);
        void adjustOpposite(int amount);
};