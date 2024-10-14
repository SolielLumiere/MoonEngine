#pragma once

enum CardClass : int
{
    CH_CLUB,
    CH_SPADE,
    CH_HEART,
    CH_DIAMOND,
    CH_TOTAL
};

enum CardColor : int
{
    RED,
    BLACK,
    C_TOTAL,
};

enum CardValue : int
{
    AS = 1,
    TWO,
    TREE,
    FOUR,
    FICE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEEN,
    JACK, 
    QUEEN, 
    KING,
    CV_TOTAL
};

enum Tags{
    T_CARD
};