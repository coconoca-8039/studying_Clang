#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4  // �z��̃T�C�Y
#define MAX_VALUE 3 // �z��ɓ����ԑ傫����

int main() {
    int array[SIZE] = {0};  // �z���0�ŏ�����
    int counter = 0;  // �������ޒl�̃J�E���^
    int count[MAX_VALUE] = {0};  // �e�����̏o���񐔂��L�^����z��
    bool all_same;

    while (1) {  // �������[�v
        // �z����E�ɃX���C�h������  �Ō������X�V���Ȃ��ƃf�[�^���㏑������Ă��܂�
        for (int i = SIZE - 1; i > 0; i--) {
            array[i] = array[i - 1];
        }

        // 0�`9�̃����_���Ȓl�����[�ɑ}��
        int random_value = rand() % MAX_VALUE;
        array[0] = random_value;
        printf("�����_���l: %d ��}��\n", random_value);

        printf("���݂̔z��: ");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");

        // �e�����̌��𐔂��鏈��
        for (int i = 0; i < MAX_VALUE; i++) {
            count[i] = 0;
        }
        for (int i = 0; i < SIZE; i++) {
            count[array[i]]++;  // �Y�����鐔���̃J�E���g�𑝂₷
        }
        for (int i = 0; i < MAX_VALUE; i++) {
            if (count[i] > 0) {  // �z����ɑ��݂��鐔�������\��
                printf("%d: %d��\n", i, count[i]);
            }
        }

        // �z��2�ڈȍ~���S��2�̎�
        all_same = true;  // �t���O�� true�i�^�j�ŏ�����
        for (int i = 1; i < SIZE; i++) {  // i = 1�ɂ��Ă���̂��|�C���g
            if (array[i] != 2) {
                all_same = false;
                break;
            }
        }
        if (all_same == true) {
            printf("\n");
            printf("222222222222222222222222222\n");
            printf("\n");
        }

        // �z���0�ڂ�1�ڂ�1�̎�
        if(array[0] == 1 && array[1] == 1){
            printf("\n");
            printf("111111111111111111111111111\n");
            printf("\n");
        }

        printf("Press Enter...\n");
        getchar();
        
    }

    /*
    �����_���l: 2 ��}��
    ���݂̔z��: 2 2 1 0 
    0: 1��
    1: 1��
    2: 2��
    Press Enter...
    */

    return 0;
}