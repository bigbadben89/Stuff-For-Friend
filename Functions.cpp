#include "pch.h"

int setFamily(int family, int job) {
    int result = -01;

    if (family == 0) {
        if (job == 5)
            result = 2;
        else if (job == 0 || job == 1)
            result = 3;
    }
    else if (family == 1) {
        if (job == 3)
            result = 3;
        else if (job == 2 || job == 4)
            result = 2;
    }
    else if (family == 2) {
        if (job == 5)
            result = 0;
        else if (job == 2 || job == 4)
            result = 1;
    }
    else if (family == 3) {
        if (job == 3)
            result = 1;
        else if (job == 0 || job == 1)
            result = 0;
    }

    return result;
}


int setType(int type) {
    int result = -01;

    switch (type) {
    case 1:
        result = 3;
        break;
    case 3:
        result = 1;
        break;
    case 2:
        result = 4;
        break;
    case 4:
        result = 2;
        break;
    case 11:
        result = 14;
        break;
    case 14:
        result = 11;
        break;
    case 19:
        result = 34;
        break;
    case 34:
        result = 19;
        break;
    default:
        result = type;
    }

    return result;
}