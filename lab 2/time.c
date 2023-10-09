/*Define a structure time with data members hour, min, sec. Write the user defined
functions to (i) Add (ii) To find difference between two objects of class time.
Functions take two-time objects as argument and return time object. Also write the
display and read function.*/
#include <stdio.h>
struct Time {
    int hour;
    int min;
    int sec;
};

struct Time add(struct Time t1, struct Time t2) {
    struct Time result;
    result.sec = t1.sec + t2.sec;
    result.min = t1.min + t2.min + result.sec / 60;
    result.sec %= 60;
    result.hour = t1.hour + t2.hour + result.min / 60;
    result.min %= 60;
    result.hour %= 24;
    return result;
}

struct Time diff(struct Time t1, struct Time t2) {
    struct Time result;
    int totalSecs1 = t1.sec + t1.min * 60 + t1.hour * 3600;
    int totalSecs2 = t2.sec + t2.min * 60 + t2.hour * 3600;
    int diffSecs = totalSecs1 - totalSecs2;
    
    if (diffSecs < 0)
        diffSecs += 24 * 3600;

    result.hour = diffSecs / 3600;
    diffSecs %= 3600;
    result.min = diffSecs / 60;
    result.sec = diffSecs % 60;
    
    return result;
}

struct Time read() {
    struct Time t;
    printf("Enter hours: ");
    scanf("%d", &t.hour);
    printf("Enter minutes: ");
    scanf("%d", &t.min);
    printf("Enter seconds: ");
    scanf("%d", &t.sec);
    return t;
}

void display(struct Time t) {
    printf("%d hours, %d minutes, %d seconds", t.hour, t.min, t.sec);
}

int main() {
    struct Time time1, time2, result;

    printf("Enter the first time:\n");
    time1 = read();

    printf("Enter the second time:\n");
    time2 = read();

    result = add(time1, time2);
    printf("Sum of times: ");
    display(result);
    
    result = diff(time1, time2);
    printf("\nDifference between times: ");
    display(result);

    return 0;
}
