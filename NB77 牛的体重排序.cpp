/*在一个牧场中，有两个牛群，牛群A和牛群B，分别有m头和n头牛。每头牛都有一个独特的体重，体重由一个整数表示。

牛群A和牛群B的牛都按照体重从小到大进行排序。你的任务是找出这两个牛群的所有牛的体重的中位数。

请你设计一个算法，使得算法的时间复杂度为O(log (m+n))。

输入：
[100, 300],[200]
返回值：
200.00000
说明：
合并体重 = [100,200,300] ，中位数 200
*/

double findMedianSortedArrays(int* weightsA, int weightsALen, int* weightsB,
    int weightsBLen) {
    // write code here
    if (weightsALen > weightsBLen) {
        //交换指针
        int* weightsSave = weightsB;
        weightsB = weightsA;
        weightsA = weightsSave;
        int weightlensave = weightsBLen;
        weightsBLen = weightsALen;
        weightsALen = weightlensave;
    }
    double num1 = weightsA[weightsALen / 2];
    double num2 = weightsB[weightsBLen / 2];
    if ((weightsALen & 1) == 0) {
        num1 = (weightsA[weightsALen / 2] + weightsA[weightsALen / 2 - 1]) / 2.0;
    }
    if ((weightsBLen & 1) == 0) {
        num2 = (weightsB[weightsBLen / 2] + weightsB[weightsBLen / 2 - 1]) / 2.0;
    }
    if (weightsALen == 1) {
        //返回值
        if (weightsBLen == 1)
            return (weightsA[0] + weightsB[0]) / 2.0;
        if ((weightsBLen & 1) == 0) {
            if (weightsA[0] > weightsB[weightsBLen / 2])
                return weightsB[weightsBLen / 2];
            if (weightsA[0] < weightsB[weightsBLen / 2 - 1])
                return weightsB[weightsBLen / 2 - 1];
            return weightsA[0];
        }
        if ((weightsBLen & 1) == 1) {
            if (weightsA[0] >= weightsB[weightsBLen / 2 + 1])
                return (weightsB[weightsBLen / 2 + 1] + weightsB[weightsBLen / 2]) / 2.0;
            if (weightsA[0] <= weightsB[weightsBLen / 2 - 1])
                return (weightsB[weightsBLen / 2 - 1] + weightsB[weightsBLen / 2]) / 2.0;
            return (weightsB[weightsBLen / 2] + weightsA[0]) / 2.0;
        }
    }
    //进入递归
    if (num1 > num2) {
        return findMedianSortedArrays(weightsA, (weightsALen + 1) / 2,
            weightsB + (weightsALen / 2), weightsBLen - (weightsALen / 2));
    }
    else {
        return findMedianSortedArrays(weightsA + weightsALen / 2, (weightsALen + 1) / 2,
            weightsB, weightsBLen - (weightsALen / 2));
    }

}