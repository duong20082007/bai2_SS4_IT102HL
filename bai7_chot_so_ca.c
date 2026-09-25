#include <stdio.h>

int main() {
    int N;

    int don_hop_le = 0;
    int don_loi = 0;
    double tong_doanh_thu = 0;
    double don_lon_nhat = 0;

    printf("============================================\n");
    printf(" COFFEE_POS - THONG KE DOANH THU CA\n");
    printf("============================================\n");

    printf("Nhap so luong hoa don trong ca: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("\nCA LAM VIEC KHONG CO HOA DON.\n");
        printf("\n========== BAO CAO CA ==========\n");
        printf("Don hang hop le : 0\n");
        printf("Don hang loi    : 0\n");
        printf("Tong doanh thu  : 0 VNĐ\n");
        printf("Don lon nhat    : 0 VNĐ\n");

        return 0;
    }

    for (int i = 1; i <= N; i++) {

        double gia_co_so;
        char size;
        int so_topping;
        int member;

        printf("\n--------------------------------------------\n");
        printf("HOA DON THU %d\n", i);
        printf("--------------------------------------------\n");

        printf("Nhap gia co so Size S: ");
        scanf("%lf", &gia_co_so);

        if (gia_co_so <= 0) {
            printf("LOI: Gia co so khong hop le!\n");
            printf("Bo qua hoa don %d.\n", i);

            don_loi++;
            continue;
        }

        printf("Nhap Size (S/M/L): ");
        scanf(" %c", &size);

        if (size != 'S' && size != 's' &&
            size != 'M' && size != 'm' &&
            size != 'L' && size != 'l') {

            printf("LOI: Size khong hop le!\n");
            printf("Bo qua hoa don %d.\n", i);

            don_loi++;
            continue;
        }

        printf("Nhap so luong topping: ");
        scanf("%d", &so_topping);

        if (so_topping < 0) {
            printf("\n!!! CANH BAO BAO MAT !!!\n");
            printf("Phat hien so luong topping am.\n");
            printf("HE THONG NGAT CA LAM VIEC!\n");

            break;
        }

        printf("Trang thai hoi vien (1-Gold, 0-Thuong): ");
        scanf("%d", &member);

        double phu_thu_size = 0;

        if (size == 'M' || size == 'm') {
            phu_thu_size = 6000;
        } else if (size == 'L' || size == 'l') {
            phu_thu_size = 10000;
        }

        double phu_thu_topping = so_topping * 8000;

        double tong_truoc_giam =
            gia_co_so + phu_thu_size + phu_thu_topping;

        double tien_giam = 0;

        if (member == 1) {
            tien_giam = tong_truoc_giam * 0.10;
        }

        double thanh_tien = tong_truoc_giam - tien_giam;

        don_hop_le++;
        tong_doanh_thu += thanh_tien;

        if (thanh_tien > don_lon_nhat) {
            don_lon_nhat = thanh_tien;
        }

        printf("\n>>> HOA DON %d <<<\n", i);
        printf("Gia co so       : %.0f VNĐ\n", gia_co_so);
        printf("Phu thu Size    : %.0f VNĐ\n", phu_thu_size);
        printf("Tien topping    : %.0f VNĐ\n", phu_thu_topping);
        printf("Truoc giam      : %.0f VNĐ\n", tong_truoc_giam);
        printf("Giam Gold 10%%   : %.0f VNĐ\n", tien_giam);
        printf("Thanh tien      : %.0f VNĐ\n", thanh_tien);
    }

    printf("\n============================================\n");
    printf("          BAO CAO CHOT SO DOANH THU\n");
    printf("============================================\n");

    printf("Don hang hop le : %d\n", don_hop_le);
    printf("Don hang loi    : %d\n", don_loi);
    printf("Tong doanh thu  : %.0f VNĐ\n", tong_doanh_thu);
    printf("Don lon nhat    : %.0f VNĐ\n", don_lon_nhat);

    printf("============================================\n");

    return 0;
}