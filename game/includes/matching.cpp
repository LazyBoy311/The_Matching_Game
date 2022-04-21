#include"matching.h"

bool checkMatching(int R, int C, Point** ptr, Point ps1, Point ps2) {
    if (!(abs(ps1.x - ps2.x) + abs(ps1.y - ps2.y) - 1)) return 1;
    for (int i = 0; i < R; i++) {
        int flag1 = 0, flag2 = 0, flag3 = 0;
        if (i != 0 && i != R - 1)
            for (int j = min(ps1.y, ps2.y); j <= max(ps1.y, ps2.y); j++)
                if (ptr[i][j].value != 0) flag1++;
        for (int j = min(i, ps1.x); j <= max(i, ps1.x); j++)
            if (ptr[j][ps1.y].value != 0)
                flag2++;
        for (int j = min(i, ps2.x); j <= max(i, ps2.x); j++)
            if (ptr[j][ps2.y].value != 0)
                flag3++;
        if (!flag1 && flag2 == 1 && flag3 == 1) return 1;
    }
    for (int j = 0; j < C; j++) {
        int flag1 = 0, flag2 = 0, flag3 = 0;
        if (j != 0 && j != C - 1)
            for (int i = min(ps2.x, ps1.x); i <= max(ps1.x, ps2.x); i++)
                if (ptr[i][j].value != 0) flag1++;
        for (int i = min(j, ps1.y); i <= max(j, ps1.y); i++)
            if (ptr[ps1.x][i].value != 0) flag2++;
        for (int i = min(j, ps2.y); i <= max(j, ps2.y); i++)
            if (ptr[ps2.x][i].value != 0) flag3++;
        if (!flag1 && flag2 == 1 && flag3 == 1) return 1;
    }
    for (int j = min(ps1.y, ps2.y); j <= max(ps1.y, ps2.y); j++) {
        int flag1 = 0, flag2 = 0, flag3 = 0;
        if (j == ps1.y || j == ps2.y) --flag1;
        for (int i = min(ps1.x, ps2.x); i <= max(ps1.x, ps2.x); i++)
            if (ptr[i][j].value == 0) ++flag1;
        for (int i = min(j, ps1.y); i <= max(j, ps1.y); i++)
            if (ptr[ps1.x][i].value != 0) ++flag2;
        for (int i = min(j, ps2.y); i <= max(j, ps2.y); i++)
            if (ptr[ps1.x][i].value != 0) ++flag3;
        if (!flag1 && flag2 == 1 && flag3 == 1) return 1;
    }
    return 0;
}

bool checkAvailable(int R, int C, Point** ptr) {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            if (ptr[i][j].value != 0) {
                for (int k = i; k < R; k++)
                    for (int l = 0; l < C; l++) {
                    	if(i != k || j != l)
	                        if (ptr[i][j].value == ptr[k][l].value)
	                            if (checkMatching(R, C, ptr, ptr[i][j], ptr[k][l]));
	                                return 1;
                    }
            }
        }
    return 0;
}

void resetValue(int R, int C, Point**& ptr) {
    while (true) {
        for (int i = 0; i < (R + C) / 2; i++) { // (R + C) / 2 just random value
            int randomX, randomY, randomK, randomL;
            while (true) {
                randomX = rand() % R;
                randomY = rand() % C;
                if (ptr[randomX][randomY].value != 0) break;
            }
            while (true) {
                randomK = rand() % R;
                randomL = rand() % C;
                if (ptr[randomK][randomL].value != 0) break;
            }
            swap(ptr[randomX][randomY].value, ptr[randomK][randomL].value);
        }
        if (checkAvailable(R, C, ptr)) break;
    }

}
