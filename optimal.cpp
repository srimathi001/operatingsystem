#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10

int optimal(int pages[], int num_pages, int num_frames) {
    int frames[MAX_FRAMES] = { -1 };
    int page_faults = 0;

    for (int i = 0; i < num_pages; i++) {
        bool page_found = false;

        // Check if the page is already in a frame
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == pages[i]) {
                page_found = true;
                break;
            }
        }

        // If page not found in any frame, replace the optimal page
        if (!page_found) {
            int replace_index = -1;
            int farthest_index = i + 1;

            for (int j = 0; j < num_frames; j++) {
                int k;
                for (k = i + 1; k < num_pages; k++) {
                    if (frames[j] == pages[k]) {
                        if (k > farthest_index) {
                            farthest_index = k;
                            replace_index = j;
                        }
                        break;
                    }
                }

                // If the page is not referenced anymore, replace it
                if (k == num_pages) {
                    replace_index = j;
                    break;
                }
            }

            // Replace the optimal page with the current page
            frames[replace_index] = pages[i];
            page_faults++;
        }
    }

    return page_faults;
}

int main() {
    int page_frames = 3;
    int page_reference[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int num_pages = sizeof(page_reference) / sizeof(page_reference[0]);

    int page_faults = optimal(page_reference, num_pages, page_frames);

    printf("Page Reference Sequence: ");
    for (int i = 0; i < num_pages; i++) {
        printf("%d ", page_reference[i]);
    }
    printf("\n");

    printf("Number of Page Faults: %d\n", page_faults);

    return 0;
}
