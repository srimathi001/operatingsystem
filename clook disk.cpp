#include<stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 100

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int clook(int tracks[], int num_tracks, int start_track) {
    int head_movement = 0;
    int current_track = start_track;
    int i, j;

    
    qsort(tracks, num_tracks, sizeof(int), cmpfunc);


    for (i = 0; i < num_tracks; i++) {
        if (tracks[i] == start_track) {
            break;
        }
    }


    for (j = i; j < num_tracks; j++) {
        head_movement += abs(tracks[j] - current_track);
        current_track = tracks[j];
    }


    for (j = 0; j < i; j++) {
        head_movement += abs(tracks[j] - current_track);
        current_track = tracks[j];
    }

    return head_movement;
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int num_tracks = sizeof(tracks) / sizeof(tracks[0]);
    int start_track = 55;

    int total_head_movement = clook(tracks, num_tracks, start_track);
    float average_head_movement = (float)total_head_movement / num_tracks;

    printf("Track Positions: ");
    for (int i = 0; i < num_tracks; i++) {
        printf("%d ", tracks[i]);
    }
    printf("\n");

    printf("Start Track: %d\n", start_track);
    printf("Total Head Movement: %d\n", total_head_movement);
    printf("Average Head Movement: %.2f\n", average_head_movement);

    return 0;
}
