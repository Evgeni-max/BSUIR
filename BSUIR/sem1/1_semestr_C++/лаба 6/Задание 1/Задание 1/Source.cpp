#include <iostream>

int main()
{
    char ch;
    const int sizeofchararray = 100;
    char nums[sizeofchararray];

    int count = 0;
    while ((ch = getchar()) != '\n') {
        nums[count] = ch;
        count++;
    }
    nums[count] = '\0';

    char today = nums[0];
    int todaycount = 1, mincount = count;
    for (int i = 1; i < count; i++) {

        if (nums[i] == today) {
            todaycount++;
        }
        else {
            today = nums[i];
            if (todaycount < mincount) mincount = todaycount;
            todaycount = 1;
        }
    }
    if (todaycount < mincount) mincount = todaycount;


    std::cout << "Min groop: " << mincount;
}
