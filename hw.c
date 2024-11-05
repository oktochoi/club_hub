#include <stdio.h>

int month_days(int y, int m);
int first_day(int y, int m);
void print_calendar(int day, int d1);

int main() {
    int y, m, day, d1;
    
    printf("년과 월을 입력하세요 (예: 2024 10): ");
    scanf("%d%d", &y, &m);

    day = month_days(y, m);
    d1 = first_day(y, m);

    printf("%d년 %d월 달력\n", y, m);
    print_calendar(day, d1);
}

int month_days(int y, int m) {
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    if (m == 2) {
        if (y % 400 == 0) {
            return 29;
        } else if (y % 100 == 0) {
            return 28;
        } else if (y % 4 == 0) {
            return 29;
        } else {
            return 28;
        }
    }
    return 31;  // 1, 3, 5, 7, 8, 10, 12
}

int first_day(int y, int m) {
    if (m == 1 || m == 2) {
        m += 12;
        y -= 1;
    }
    return (1 + (13 * (m + 1) / 5) + (y % 100) + ((y % 100) / 4) + ((y / 100) / 4) - 2 * (y / 100)) % 7 + 7 % 7;
}

void print_calendar(int day, int d1) {
    printf("____________________________________\n");
    printf("| 토 | 일 | 월 | 화 | 수 | 목 | 금 |\n");
    printf("____________________________________\n");

    int i;
    for (i = 0; i < d1; i++) {
        printf("|    ");
    }

    for (int date = 1; date <= day; date++) {
        printf("| %2d ", date);
        if (++i % 7 == 0) {
            printf("|\n");
        }
    }

    if (i % 7 != 0) {
        while (i % 7 != 0) {
            printf("|    ");
            i++;
        }
        printf("|\n");
    }

    printf("_____________________________________\n");
}
