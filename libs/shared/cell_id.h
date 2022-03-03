#pragma once

struct CellID {
    long mcc;
    long mnc;
    long tac;
    long cell;
};

struct NeighborCell {
    int id;
    int EARFCN;
    int rsrp;
    int rsrq;
};
