#include"suggestmove.h"
#include"matching.h"

suggestmove SuggestMove(int R, int C, Point** ptr) {
    suggestmove a;
    a.x1 = 0;   a.x2 = 0; a.y1 = 0; a.y2 = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            if (ptr[i][j].value != 0) {
                for (int k = i; k < R; k++)
                    for (int l = 0; l < C; l++) {
                    	if(i != k || j != l)
	                        if (ptr[i][j].value == ptr[k][l].value)
	                            if (checkMatching(R, C, ptr, ptr[i][j], ptr[k][l])) {
	                            	ptr[i][j].SelectedBox();
	                            	ptr[k][l].SelectedBox();
	                                a.x1 = i;   a.y1 = j; a.x2 = k; a.y2 = l;
	                                return a;
	                            }
                    }
            }
        }
    return a;
}
