#include <stdio.h>

/* ฟังก์ชันคำนวณโอกาสชนะ (Odds)
   ใช้สูตร Odds = Outs x 4
   ส่งกลับค่าเป็นเปอร์เซ็นต์ (float)
*/
float calculate_win_odds(int outs);

int main() {
    int card_outs;               // จำนวน Outs
    float win_probability;       // โอกาสชนะ (%)

    // กำหนดค่า Outs ตามโจทย์ (ได้ Pair จาก 9 หรือ K)
    card_outs = 9;

    // เรียกใช้ฟังก์ชันเพื่อคำนวณโอกาสชนะ
    win_probability = calculate_win_odds(card_outs);

    // แสดงรายงานผลลัพธ์
    printf("\n--- POKER PROBABILITY REPORT (2 Cards Remaining) ---\n");
    printf("Calculated Outs: %d\n", card_outs);
    printf("Win Probability (Odds x 4): %.2f%%\n", win_probability);

    // ประเมินระดับโอกาสชนะ
    printf("Assessment: ");
    if (win_probability >= 30.0) {
        printf("HIGH Win Probability\n");
    } else {
        printf("LOW Win Probability\n");
    }

    return 0;
}

/* ฟังก์ชันคำนวณโอกาสชนะ
   ใช้ Type Casting เพื่อให้ได้ค่าทศนิยม
*/
float calculate_win_odds(int outs) {
    return (float)outs * 4;
}