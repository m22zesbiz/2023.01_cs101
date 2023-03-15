#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {

    srand((unsigned) time(NULL));
    int n = 2; 
    int endless = 0; 

    FILE* fp;
    fp = fopen("lotto.txt", "w+");
    // fwrite(arr_read, sizeof(arr_read), 1, fp);
    // fseek(fp, 0, SEEK_SET);
    // fread(arr_read, sizeof(arr_read), 1, fp);

    char header[] = "======== lotto649 ========";
    fprintf(fp, "%s\n", header);

    for (int i = 0; i < n; i++) {
        int result[6]; 
        int numGen; 
        int counter = 0; 
        fprintf(fp, "[%d]: ", i + 1);

        // first 6 number
        while (endless < 1) {
            numGen = floor(rand() % 69) + 1; 
            for (int j = 0; j < counter + 1; j++) {
                if (numGen == result[j]) {
                    j = counter + 1; 
                } else if (numGen != result[j] && j == counter) {
                    result[counter] = numGen; 
                    counter++; 
                    j = counter + 1; 
                }
            }
            if (counter == 6) {
                break; 
            }
        }

        // sorting numbers
        for (int j = 0; j < 6; j++) {
            for (int k = j + 1; k < 7; k++) {
                if (result[j] > result[k]) {
                    int temp = result[j];
                    result[j] = result[k];
                    result[k] = temp;
                }
            }
        }

        // special number
        endless = 0; 
        counter = 0; 
        while (endless < 1) {
            numGen = floor(rand() % 10) + 1; 
            for (int j = 0; j < 7; j++) {
                if (numGen == result[j]) {
                    j = 6; 
                } else if (numGen != result[j] && j == 6) {
                    result[6] = numGen; 
                    counter = 6; 
                    j = 6; 
                }
            }
            if (counter == 6) {
                break; 
            }
        }

        // printing result
        for (int j = 0; j < 7; j++) {
            if (result[j] < 10) {
                fprintf(fp, "0%d ", result[j]); 
            } else {
                fprintf(fp, "%d ", result[j]); 
            }
        }

        fprintf(fp, "\n");
    }

    // printing empty set
    for (int i = 0; i < 5 - n; i++) {
        fprintf(fp, "[%d]: ", i + n + 1);
        for (int j = 0; j < 7; j++) {
            fprintf(fp, "-- "); 
        }
        fprintf(fp, "\n");
    }

    char footer[] = "======== csie@CGU ========";
    fprintf(fp, "%s\n", footer);

    fclose(fp);
}
