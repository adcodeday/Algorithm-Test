/*��һ�������У�������ţȺ��ţȺA��ţȺB���ֱ���mͷ��nͷţ��ÿͷţ����һ�����ص����أ�������һ��������ʾ��

ţȺA��ţȺB��ţ���������ش�С���������������������ҳ�������ţȺ������ţ�����ص���λ����

�������һ���㷨��ʹ���㷨��ʱ�临�Ӷ�ΪO(log (m+n))��

���룺
[100, 300],[200]
����ֵ��
200.00000
˵����
�ϲ����� = [100,200,300] ����λ�� 200
*/

double findMedianSortedArrays(int* weightsA, int weightsALen, int* weightsB,
    int weightsBLen) {
    // write code here
    if (weightsALen > weightsBLen) {
        //����ָ��
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
        //����ֵ
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
    //����ݹ�
    if (num1 > num2) {
        return findMedianSortedArrays(weightsA, (weightsALen + 1) / 2,
            weightsB + (weightsALen / 2), weightsBLen - (weightsALen / 2));
    }
    else {
        return findMedianSortedArrays(weightsA + weightsALen / 2, (weightsALen + 1) / 2,
            weightsB, weightsBLen - (weightsALen / 2));
    }

}