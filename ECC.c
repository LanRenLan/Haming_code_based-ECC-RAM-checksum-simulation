/*
规则：输入最高11位二进制数字，如果有空位则在结尾填零。
该程序会为11位二进制数字生成5位汉明码，共计16位。
然后根据用户要求，模拟电磁信号造成的比特翻转，最多不超过2位，因为在16位数据中同时出现3位比特翻转的概率可以忽略不计
再对被比特翻转后的数据进行ECC校验，如果只有一位错误数据，则可以定位并修正该错误
*/


#include<stdio.h>
#include<string.h>
#include <stdbool.h>
#include <stdlib.h>
#define true 1
#define false 0

//typedef int bool;
//bin为实际数据，bim为错误数据，bincheck0为第一次校验，checkbin0为第二次校验
int main(void) {
    int bin[11];
    char bininput[11];
    int num = 0;

    printf("Enter a 11-bit binary number: ");
    scanf("%11c", bininput);

    for (int i = 0; i < strlen(bininput); i++) {
        if (bininput[i] == '1') 
        {
            num += 1 << (strlen(bininput) - 1 - i);
        }
    }
    if (bininput[0] == '0'){
        bin[0] = 0;
    } else {
        bin[0] = 1;
    }
    if (bininput[1] == '0'){
        bin[1] = 0;
    } else {
        bin[1] = 1;
    }
    if (bininput[2] == '0'){
        bin[2] = 0;
    } else {
        bin[2] = 1;
    }
    if (bininput[3] == '0'){
        bin[3] = 0;
    } else {
        bin[3] = 1;
    }
    if (bininput[4] == '0'){
        bin[4] = 0;
    } else {
        bin[4] = 1;
    }
    if (bininput[5] == '0'){
        bin[5] = 0;
    } else {
        bin[5] = 1;
    }
    if (bininput[6] == '0'){
        bin[6] = 0;
    } else {
        bin[6] = 1;
    }
    if (bininput[7] == '0'){
        bin[7] = 0;
    } else {
        bin[7] = 1;
    }
    if (bininput[8] == '0'){
        bin[8] = 0;
    } else {
        bin[8] = 1;
    }
    if (bininput[9] == '0'){
        bin[9] = 0;
    } else {
        bin[9] = 1;
    }
    if (bininput[10] == '0'){
        bin[10] = 0;
    } else {
        bin[10] = 1;
    }


//传输数据
    int bin15 = bin[10];
    int bin14 = bin[9];
    int bin13 = bin[8];
    int bin12 = bin[7];
    int bin11 = bin[6];
    int bin10 = bin[5];
    int bin9 = bin[4];
    int bin7 = bin[3];
    int bin6 = bin[2];
    int bin5 = bin[1];
    int bin3 = bin[0];
//校验码初始0
    int bin0 = 0;
    int bin1 = 0;
    int bin2 = 0;
    int bin4 = 0;
    int bin8 = 0;
    int bin16 = 0;
//    printf("it is %d\n", bin0);

    int bincheck0, bincheck1, bincheck2, bincheck4, bincheck8; 
//校验码2检测2和4列
    bincheck2 = (bin2 + bin3 + bin6 + bin7 + bin10 + bin11 + bin14 + bin15);
    if (bincheck2 % 2 == 0) {
        bin2 = 0;
    } else {
        bin2 = 1;
    }
//校验码1检测1和3列
    bincheck1 = (bin1 + bin3 + bin5 + bin7 + bin9 + bin11 + bin13 + bin15);
    if (bincheck1 % 2 == 0){
        bin1 = 0;
    } else {
        bin1 = 1;
    }
//5:55
//校验码4检测2和4行
    bincheck4 = (bin4 + bin5 + bin6 + bin7 + bin12 + bin13 + bin14 + bin15);
    if (bincheck4 % 2 == 0){
        bin4 = 0;
    } else {
        bin4 = 1;
    }
//校验码8检测3和4行
    bincheck8 = (bin8 + bin9 + bin10 + bin11 + bin12 + bin13 + bin14 + bin15);
    if (bincheck8 % 2 == 0){
        bin8 = 0;
    } else {
        bin8 = 1;
    }
//校验码0校验整个盘面
    bincheck0 = (bin0 + bin1 + bin2 + bin3 + bin4 + bin5 + bin6 + bin7 + bin8 + bin9 + bin10 + bin11 + bin12 +bin13 + bin14 +bin15);
    if (bincheck0 % 2 == 0){
        bin0 = 0;
    } else {
        bin0 = 1;
    }
    printf("Data with Haming Code is: %d%d%d%d,%d%d%d%d,%d%d%d%d,%d%d%d%d\n", bin0, bin1, bin2, bin3, bin4, bin5, bin6, bin7, bin8, bin9, bin10, bin11, bin12, bin13, bin14, bin15);
//校验码添加完成，发送数据到CPU
//收到完整数据串
    int iii;
    int bim[16];
    for (int iii = 0; iii < 16; iii++)
    bim[iii] = bin[iii];


    int bim15 = bin15;
    int bim14 = bin14;
    int bim13 = bin13;
    int bim12 = bin12;
    int bim11 = bin11;
    int bim10 = bin10;
    int bim9 = bin9;
    int bim8 = bin8;
    int bim7 = bin7;
    int bim6 = bin6;
    int bim5 = bin5;
    int bim4 = bin4;
    int bim3 = bin3;
    int bim2 = bin2;
    int bim1 = bin1;
    int bim0 = bin0;

//    int bitflipcoorpre;
    int datar =("%d%d%d%d,%d%d%d%d,%d%d%d%d,%d%d%d%d", bim0, bim1, bim2, bim3, bim4, bim5, bim6, bim7, bim8, bim9, bim10, bim11, bim12, bim13, bim14, bim15);
//    printf("Data with Haming Code is : %d \n", datar);
//比特反转开始
    int digits, bitflipcoor, bitflipcoor1, bitflipcoor2;
    bitflipcoor = 999;
    bitflipcoor1 = 999;
    bitflipcoor2 = 999;
    printf("How many bit flip(s) do you want, from scale 0 to 2: ");
    scanf("%i", &digits);
    printf("Notice that having more than two bit flips at the same time is unlikely to happen in reality, if so, try reboot or use LDPC\n"); 
    if (digits == 1){
        printf("Which digit do you want bit flip to happen, in a scale 0~15? ");
        scanf("%i", &bitflipcoor);
    } else if (digits == 2){
        printf("Which digit do you want the first bit flip to happen, in a scale 0~15? ");
        scanf("%i", &bitflipcoor1);
        printf("Which digit do you want the second bit flip to happen, in a scale 0~15? ");
        scanf("%i", &bitflipcoor2);
    } else if (digits == 0){
        printf("Sure, no error is going to occur");
    }
    
//    getint();
//    scanf("%i", &bitflipcoorpre);
//    int bitflipcoor = bitflipcoorpre - 1;

//发生比特反转
    if (bitflipcoor <= 15 && bitflipcoor >= 0){
        if (bim0 == 0 && bitflipcoor == 0){
            bim0 = 1;
        } else if (bim0 == 1 && bitflipcoor == 0){
            bim0 = 0;
        } else if (bim1 == 0 && bitflipcoor == 1){
            bim1 = 1;
        } else if (bim1 == 1 && bitflipcoor == 1){
            bim1 = 0;
        } else if (bim2 == 0 && bitflipcoor == 2){
            bim2 = 1;
        } else if (bim2 == 1 && bitflipcoor == 2){
            bim2 = 0;
        } else if (bim3 == 0 && bitflipcoor == 3){
            bim3 = 1;
        } else if (bim3 == 1 && bitflipcoor == 3){
            bim3 = 0;
        } else if (bim4 == 0 && bitflipcoor == 4){
            bim4 = 1;
        } else if (bim4 == 1 && bitflipcoor == 4){
            bim4 = 0;
        } else if (bim5 == 0 && bitflipcoor == 5){
            bim5 = 1;
        } else if (bim5 == 1 && bitflipcoor == 5){
            bim5 = 0;
        } else if (bim6 == 0 && bitflipcoor == 6){
            bim6 = 1;
        } else if (bim6 == 1 && bitflipcoor == 6){
            bim6 = 0;
        } else if (bim7 == 0 && bitflipcoor == 7){
            bim7 = 1;
        } else if (bim7 == 1 && bitflipcoor == 7){
            bim7 = 0;
        } else if (bim8 == 0 && bitflipcoor == 8){
            bim8 = 1;
        } else if (bim8 == 1 && bitflipcoor == 8){
            bim8 = 0;
        } else if (bim9 == 0 && bitflipcoor == 9){
            bim9 = 1;
        } else if (bim9 == 1 && bitflipcoor == 9){
            bim9 = 0;
        } else if (bim10 == 0 && bitflipcoor == 10){
            bim10 = 1;
        } else if (bim10 == 1 && bitflipcoor == 10){
            bim10 = 0;
        } else if (bim11 == 0 && bitflipcoor == 11){
            bim11 = 1;
        } else if (bim11 == 1 && bitflipcoor == 11){
            bim11 = 0;
        } else if (bim12 == 0 && bitflipcoor == 12){
            bim12 = 1;
        } else if (bim12 == 1 && bitflipcoor == 12){
            bim12 = 0;
        } else if (bim13 == 0 && bitflipcoor == 13){
            bim13 = 1;
        } else if (bim13 == 1 && bitflipcoor == 13){
            bim13 = 0;
        } else if (bim14 == 0 && bitflipcoor == 14){
            bim14 = 1;
        } else if (bim14 == 1 && bitflipcoor == 14){
            bim14 = 0;
        } else if (bim15 == 0 && bitflipcoor == 15){
            bim15 = 1;
        } else if (bim15 == 1 && bitflipcoor == 15){
            bim15 = 0;
        } else {
//            printf("error!!!\n");
//            exit(0);
        }
    }

    if (bitflipcoor1 <= 15 && bitflipcoor1 >= 0){
        if (bim0 == 0 && bitflipcoor1 == 0){
            bim0 = 1;
        } else if (bim0 == 1 && bitflipcoor1 == 0){
            bim0 = 0;
        } else if (bim1 == 0 && bitflipcoor1 == 1){
            bim1 = 1;
        } else if (bim1 == 1 && bitflipcoor1 == 1){
            bim1 = 0;
        } else if (bim2 == 0 && bitflipcoor1 == 2){
            bim2 = 1;
        } else if (bim2 == 1 && bitflipcoor1 == 2){
            bim2 = 0;
        } else if (bim3 == 0 && bitflipcoor1 == 3){
            bim3 = 1;
        } else if (bim3 == 1 && bitflipcoor1 == 3){
            bim3 = 0;
        } else if (bim4 == 0 && bitflipcoor1 == 4){
            bim4 = 1;
        } else if (bim4 == 1 && bitflipcoor1 == 4){
            bim4 = 0;
        } else if (bim5 == 0 && bitflipcoor1 == 5){
            bim5 = 1;
        } else if (bim5 == 1 && bitflipcoor1 == 5){
            bim5 = 0;
        } else if (bim6 == 0 && bitflipcoor1 == 6){
            bim6 = 1;
        } else if (bim6 == 1 && bitflipcoor1 == 6){
            bim6 = 0;
        } else if (bim7 == 0 && bitflipcoor1 == 7){
            bim7 = 1;
        } else if (bim7 == 1 && bitflipcoor1 == 7){
            bim7 = 0;
        } else if (bim8 == 0 && bitflipcoor1 == 8){
            bim8 = 1;
        } else if (bim8 == 1 && bitflipcoor1 == 8){
            bim8 = 0;
        } else if (bim9 == 0 && bitflipcoor1 == 9){
            bim9 = 1;
        } else if (bim9 == 1 && bitflipcoor1 == 9){
            bim9 = 0;
        } else if (bim10 == 0 && bitflipcoor1 == 10){
            bim10 = 1;
        } else if (bim10 == 1 && bitflipcoor1 == 10){
            bim10 = 0;
        } else if (bim11 == 0 && bitflipcoor1 == 11){
            bim11 = 1;
        } else if (bim11 == 1 && bitflipcoor1 == 11){
            bim11 = 0;
        } else if (bim12 == 0 && bitflipcoor1 == 12){
            bim12 = 1;
        } else if (bim12 == 1 && bitflipcoor1 == 12){
            bim12 = 0;
        } else if (bim13 == 0 && bitflipcoor1 == 13){
            bim13 = 1;
        } else if (bim13 == 1 && bitflipcoor1 == 13){
            bim13 = 0;
        } else if (bim14 == 0 && bitflipcoor1 == 14){
            bim14 = 1;
        } else if (bim14 == 1 && bitflipcoor1 == 14){
            bim14 = 0;
        } else if (bim15 == 0 && bitflipcoor1 == 15){
            bim15 = 1;
        } else if (bim15 == 1 && bitflipcoor1 == 15){
            bim15 = 0;
        } else {
//            printf("error!!!\n");
//            exit(0);
        }
    }
        if (bitflipcoor2 <= 15 && bitflipcoor2 >= 0){
        if (bim0 == 0 && bitflipcoor2 == 0){
            bim0 = 1;
        } else if (bim0 == 1 && bitflipcoor2 == 0){
            bim0 = 0;
        } else if (bim1 == 0 && bitflipcoor2 == 1){
            bim1 = 1;
        } else if (bim1 == 1 && bitflipcoor2 == 1){
            bim1 = 0;
        } else if (bim2 == 0 && bitflipcoor2 == 2){
            bim2 = 1;
        } else if (bim2 == 1 && bitflipcoor2 == 2){
            bim2 = 0;
        } else if (bim3 == 0 && bitflipcoor2 == 3){
            bim3 = 1;
        } else if (bim3 == 1 && bitflipcoor2 == 3){
            bim3 = 0;
        } else if (bim4 == 0 && bitflipcoor2 == 4){
            bim4 = 1;
        } else if (bim4 == 1 && bitflipcoor2 == 4){
            bim4 = 0;
        } else if (bim5 == 0 && bitflipcoor2 == 5){
            bim5 = 1;
        } else if (bim5 == 1 && bitflipcoor2 == 5){
            bim5 = 0;
        } else if (bim6 == 0 && bitflipcoor2 == 6){
            bim6 = 1;
        } else if (bim6 == 1 && bitflipcoor2 == 6){
            bim6 = 0;
        } else if (bim7 == 0 && bitflipcoor2 == 7){
            bim7 = 1;
        } else if (bim7 == 1 && bitflipcoor2 == 7){
            bim7 = 0;
        } else if (bim8 == 0 && bitflipcoor2 == 8){
            bim8 = 1;
        } else if (bim8 == 1 && bitflipcoor2 == 8){
            bim8 = 0;
        } else if (bim9 == 0 && bitflipcoor2 == 9){
            bim9 = 1;
        } else if (bim9 == 1 && bitflipcoor2 == 9){
            bim9 = 0;
        } else if (bim10 == 0 && bitflipcoor2 == 10){
            bim10 = 1;
        } else if (bim10 == 1 && bitflipcoor2 == 10){
            bim10 = 0;
        } else if (bim11 == 0 && bitflipcoor2 == 11){
            bim11 = 1;
        } else if (bim11 == 1 && bitflipcoor2 == 11){
            bim11 = 0;
        } else if (bim12 == 0 && bitflipcoor2 == 12){
            bim12 = 1;
        } else if (bim12 == 1 && bitflipcoor2 == 12){
            bim12 = 0;
        } else if (bim13 == 0 && bitflipcoor2 == 13){
            bim13 = 1;
        } else if (bim13 == 1 && bitflipcoor2 == 13){
            bim13 = 0;
        } else if (bim14 == 0 && bitflipcoor2 == 14){
            bim14 = 1;
        } else if (bim14 == 1 && bitflipcoor2 == 14){
            bim14 = 0;
        } else if (bim15 == 0 && bitflipcoor2 == 15){
            bim15 = 1;
        } else if (bim15 == 1 && bitflipcoor2 == 15){
            bim15 = 0;
        } else {
//            printf("error!!!\n");
//            exit(0);
        }
    }
    printf("Data after bit flip is: %d%d%d%d,%d%d%d%d,%d%d%d%d,%d%d%d%d\n", bim0, bim1, bim2, bim3, bim4, bim5, bim6, bim7, bim8, bim9, bim10, bim11, bim12, bim13, bim14, bim15);
//    printf("Please handle this to the next program");
//    printf("Yow may now manually switch one or two of the digits of this data, then send it to the next program");

//bim
/*这里本来打算让用户手动输入错误的数据
    int bim[12];
    int num1 = 0;

    printf("Enter a false 11-bit binary number: ");
    scanf("%11s", bim);

    for (int ii = 0; ii < strlen(bim); ii++) {
        if (bim[ii] == 1)
        {
            num1 += 1 << (strlen(bim) - 1 -ii);
        }
    }
*/
//开始进行校验
    int checkbim0, checkbim1, checkbim2, checkbim4, checkbim8;
    bool column24, column34, row24, row34, error0or2, error1;
//校验盘面
    checkbim0 = ((bim1 + bim2 + bim3 + bim4 + bim5 + bim6 + bim7 + bim8 + bim9 + bim10 + bim11 + bim12 +bim13 + bim14 +bim15) % 2);
//    printf("checkbim0 = %i \n", checkbim0);
    if (checkbim0 == bim0){
        error0or2 = true;
        error1 = false;
    } else {
        error0or2 = false;
        error1 = true;
    }
//    printf("checkbim0 = %d, bim0 = %d \n", checkbim0, bim0);
//    printf("error0or2 = %d, error1 = %d \n", error0or2, error1);
//校验3 4列
//第一次校验中，false代表出错
    checkbim2 = ((bim3 + bim6 + bim7 + bim10 + bim11 + bim14 + bim15) % 2);
//    printf("2 = %d, 3 = %d, 4 = %d, 5 = %d, 6 = %d \n", bim2, bim3, bim4, bim5, bim6);
//    printf("checkbim2 = %d \n", checkbim2);
    if (checkbim2 == bim2){
        column34 = 0;
    } else {
        column34 = 1;
    }
//校验2 4列
    checkbim1 = ((bim3 + bim5 + bim7 + bim9 + bim11 + bim13 + bim15) % 2); 
    if (checkbim1 == bim1){
        column24 = 0;
    } else {
        column24 = 1;
    }
//    printf("checkbim1 = %d \n", checkbim1);
//    printf("checkbim1 = %d\n", checkbim1);
//校验2 4行
    checkbim4 = ((bim5 + bim6 + bim7 + bim12 + bim13 + bim14 + bim15) % 2); 
    if (checkbim4 == bim4){
        row24 = 0;
    } else {
        row24 = 1;
    }
//    printf("checkbim4 = %d, row24 = %d \n", checkbim4, row24);
//校验3 4行
    checkbim8 = ((bim9 + bim10 + bim11 + bim12 + bim13 + bim14 + bim15) % 2); 
    if (checkbim8 == bim8){
        row34 = 0;
    } else {
        row34 = 1;
    } 
//    printf("colummn24 = %d, column34 = %d \n", column24, column34);
//开始二次列校验
//第二次校验中，false代表未发现问题
    bool column1, column2, column3, column4, row1, row2, row3, row4;
    if (column24 == 1 && column34 == 1){
        column4 = 1;
    } else if (column24 == 0 && column34 == 1){
        column3 = 1;
    } else if (column24 == 1 && column34 == 0){
        column2 = 1;
    } else if (column24 == 0 && column34 == 0){
        column1 = 1;
    } else {
        printf("error!\n");
    }
//校验是否有多个错误
/*
//    if ((column1 || column2 || column3 || column4  == false) && error0or2 == true){
    if (((column1 + column2 + column3 + column4) % 2  == 0) && error0or2 == false)
        printf("Multiple errors found, transmission forced cancelled, you may re-send your binary messege! \n 多处比特反转，传输强制中止，请重新发送数据! \n");
        exit(0);
    } else if (checkbim0 != bim0){
        printf("Having one bit flip, correcting error now\n");
    } else (
        printf("Having no error, data transfer completed\n");
        exit(0);
    )
*/
    if ((column1 || column2 || column3 || column4  == false) && error0or2 == true){
        printf("Multiple errors found, transmission forced cancelled, you may re-send your binary messege! \nHaming Code is not capable of self-correcting two bit flips\n");
        exit(0);
    } else {
        printf("Having one bit flip, correcting error now\n");
    }
//开始二次行校验
    if (row24 == 1 && row34 == 1){
        row4 = 1;
    } else if (row24 == 0 && row34 == 1){
        row3 = 1;
    } else if (row24 == 1 && row34 == 0){
        row2 = 1;
    } else if (row24 == 0 && row34 == 1){
        row1 = 1;
    }
//    printf("column1 = %d, row1 = %d \n", column1, row1);
//    printf("column3 = %d, row3 = %d \n", column3, row3);
//开始确认坐标点
    int coor;
    if (column1 == 1 && row1 == 1){
        coor = 0;
    } else if (column2 == 1 && row1 == 1){
        coor = 1;
    } else if (column3 == 1 && row1 == 1){
        coor = 2;
    } else if (column4 == 1 && row1 == 1){
        coor = 3;
    } else if (column1 == 1 && row2 == 1){
        coor = 4;
    } else if (column2 == 1 && row2 == 1){
        coor = 5;
    } else if (column3 == 1 && row2 == 1){
        coor = 6;
    } else if (column4 == 1 && row2 == 1){
        coor = 7;
    } else if (column1 == 1 && row3 == 1){
        coor = 8;
    } else if (column2 == 1 && row3 == 1){
        coor = 9;
    } else if (column3 == 1 && row3 == 1){
        coor = 10;
    } else if (column4 == 1 && row3 == 1){
        coor = 11;
    } else if (column1 == 1 && row4 == 1){
        coor = 12;
    } else if (column2 == 1 && row4 == 1){
        coor = 13;
    } else if (column3 == 1 && row4 == 1){
        coor = 14;
    } else if (column4 == 1 && row4 == 1){
        coor = 15;
    } else if (error0or2 == true){
        coor = 999;
    }
//    printf("Now coor = %d\n", coor);
//比特反转还原
    if (coor == 0 && bim0 == 0){
        bim0 = 1;
    } else if (coor == 0 && bim0 == 1){
        bim0 = 0;
    } else if (coor == 1 && bim1 == 0){
        bim1 = 1;
    } else if (coor == 1 && bim1 ==1){
        bim1 = 0;
    } else if (coor == 2 && bim2 == 0){
        bim2 = 1;
    } else if (coor == 2 && bim2 ==1){
        bim2 = 0;
    } else if (coor == 3 && bim3 == 0){
        bim3 = 1;
    } else if (coor == 3 && bim3 ==1){
        bim3 = 0;
    } else if (coor == 4 && bim4 == 0){
        bim4 = 1;
    } else if (coor == 4 && bim4 ==1){
        bim4 = 0;
    } else if (coor == 5 && bim5 == 0){
        bim5 = 1;
    } else if (coor == 5 && bim5 ==1){
        bim5 = 0;
    } else if (coor == 6 && bim6 == 0){
        bim6 = 1;
    } else if (coor == 6 && bim6 ==1){
        bim6 = 0;
    } else if (coor == 7 && bim7 == 0){
        bim7 = 1;
    } else if (coor == 7 && bim7 ==1){
        bim7 = 0;
    } else if (coor == 8 && bim8 == 0){
        bim8 = 1;
    } else if (coor == 8 && bim8 ==1){
        bim8 = 0;
    } else if (coor == 9 && bim9 == 0){
        bim9 = 1;
    } else if (coor == 9 && bim9 ==1){
        bim9 = 0;
    } else if (coor == 10 && bim10 == 0){
        bim10 = 1;
    } else if (coor == 10 && bim10 ==1){
        bim10 = 0;
    } else if (coor == 11 && bim11 == 0){
        bim11 = 1;
    } else if (coor == 11 && bim11 ==1){
        bim11 = 0;
    } else if (coor == 12 && bim12 == 0){
        bim12 = 1;
    } else if (coor == 12 && bim12 ==1){
        bim12 = 0;
    } else if (coor == 13 && bim13 == 0){
        bim13 = 1;
    } else if (coor == 13 && bim13 ==1){
        bim13 = 0;
    } else if (coor == 14 && bim14 == 0){
        bim14 = 1;
    } else if (coor == 14 && bim14 ==1){
        bim14 = 0;
    } else if (coor == 15 && bim15 == 0){
        bim15 = 1;
    } else if (coor == 15 && bim15 ==1){
        bim15 = 0;
    } else if (coor == 999){
        printf("没有错误");
        exit(0);
    }

    
//输出正确的数值
    printf("The corrected value is: %d%d,%d%d%d,%d%d%d,%d%d%d \n", bim3, bim5, bim6, bim7, bim9, bim10, bim11, bim12, bim13, bim14, bim15);
    printf("The false data located at number: %d\n", coor);
    printf("The data transmitted: %d%d%d%d,%d%d%d%d,%d%d%d%d,%d%d%d%d \n", bim0, bim1, bim2, bim3, bim4, bim5, bim6, bim7, bim8, bim9, bim10, bim11, bim12, bim13, bim14, bim15);
    return 0;

}






