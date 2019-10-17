#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

//Program for 8-bit counter
int main() {

    printf("Enter number of page_frames: ");
    int page_frames = 0;
    scanf("%d", &page_frames);

    char *inputName = "Lab_09_input.txt";
    FILE *input = fopen(inputName, "r");

    //check for valid input file
    if (input == NULL) {
        printf("Invalid input file!");
        return 0;
    }

    int *frames = (int *) calloc(page_frames, sizeof(int));
    unsigned char *page_age = (unsigned char *) calloc(page_frames, sizeof(unsigned char));

    for (int i = 0; i < page_frames; ++i) {
        frames[i] = 0;
    }

    int hit = 0;
    int miss = 0;
    int page = 0;
    while (fscanf(input, "%d", &page) != EOF) {

        //time tick - move right all bits of age
        for (int i = 0; i < page_frames; ++i) {
            page_age[i] = page_age[i] >> 1;
        }

        //find free space if have
        int index_free = -1;
        for (int j = 0; j < page_frames; ++j) {
            if (frames[j] == 0) {
                index_free = j;
                break;
            }
        }

        //find page in page_frames if exists
        int index_of_page = -1;
        for (int k = 0; k < page_frames; ++k) {
            if (frames[k] == page) {
                index_of_page = k;
                break;
            }
        }

        //we have found page in frames
        if (index_of_page != -1) {
            hit++;

            //add 128 to age[index_of_page] set bit
            page_age[index_of_page] += 128;
        } else {
            if (index_free != -1) {
                //found free place
                frames[index_free] = page;
                page_age[index_free] = 0;
                page_age[index_free] += 128;
            } else{
                //choose min of age in frames
                int min = 256;
                int min_index = -1;
                for (int i = 0; i < page_frames; ++i) {
                    if(page_age[i] < min){
                        min = page_age[i];
                        min_index = i;
                    }
                }

                //insert new page
                frames[min_index] = page;
                page_age[min_index] = 0;
                page_age[min_index] += 128;
            }
            miss++;
        }
    }

    printf("Hit: %d, Miss: %d, Ratio: %lf", hit, miss, (double)hit/miss);
    return 0;
}

//Enter number of page_frames: 10
//Hit: 9, Miss: 991, Ratio: 0.009082

//Enter number of page_frames: 50
//Hit: 51, Miss: 949, Ratio: 0.053741

//Enter number of page_frames: 100
//Hit: 93, Miss: 907, Ratio: 0.102536